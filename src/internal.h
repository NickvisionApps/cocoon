/**
 * @file internal.h
 * @internal Private helpers shared by the Objective-C++ implementation files (conversion, native casts, signal binding, helper constructors). Not part of the public API.
 */
#pragma once

#import <AppKit/AppKit.h>
#include <cstdarg>
#include <cstring>
#include <dlfcn.h>
#include <functional>
#include <string>
#include <utility>
#include <vector>
#include "generated/generated.h"
#include "generated/struct_conversions.h"
#include "standard_action.h"
#include "types.h"
#include "var_arg.h"

namespace cocoon::internal
{
    using Handler = std::function<void(id, id)>;

    void* retain(id object);

    template <class T>
    inline T* ns(const cocoon::Object* object)
    {
        return (__bridge T*)object->handle();
    }

    inline id obj(const cocoon::Object* object)
    {
        return (__bridge id)object->handle();
    }

    template <class T>
    inline T* native(const cocoon::Object& object)
    {
        return (__bridge T*)object.handle();
    }

    template <class T>
    inline T wrap(id object)
    {
        return T(cocoon::Adopt{object ? retain(object) : nullptr});
    }

    inline id native_id(const cocoon::Object& object)
    {
        return (__bridge id)object.handle();
    }

    template <class T>
    inline T wrap_cf(const void* reference)
    {
        return T(cocoon::Adopt{reference ? const_cast<void*>(CFRetain(reference)) : nullptr});
    }

    template <class C, class F>
    inline NSArray* to_array(const C& values, F&& convert)
    {
        NSMutableArray* result = [NSMutableArray arrayWithCapacity:values.size()];
        for (const auto& value : values)
        {
            id item = convert(value);
            [result addObject:item ?: (id)[NSNull null]];
        }
        return result;
    }

    template <class T, class F>
    inline std::vector<T> from_array(NSArray* array, F&& convert)
    {
        std::vector<T> result;
        for (id item in array)
        {
            result.push_back(convert(item));
        }
        return result;
    }

    template <class C, class FK, class FV>
    inline NSDictionary* to_dictionary(const C& values, FK&& convert_key, FV&& convert_value)
    {
        NSMutableDictionary* result = [NSMutableDictionary dictionaryWithCapacity:values.size()];
        for (const auto& pair : values)
        {
            id key = convert_key(pair.first);
            id value = convert_value(pair.second);
            if (key && value)
            {
                result[key] = value;
            }
        }
        return result;
    }

    template <class C, class FK, class FV>
    inline C from_dictionary(NSDictionary* dictionary, FK&& convert_key, FV&& convert_value)
    {
        C result;
        for (id key in dictionary)
        {
            if constexpr (requires { result.emplace(convert_key(key), convert_value(dictionary[key])); })
            {
                result.emplace(convert_key(key), convert_value(dictionary[key]));
            }
            else
            {
                result.emplace_back(convert_key(key), convert_value(dictionary[key]));
            }
        }
        return result;
    }

    NSData* to_data(const std::vector<std::uint8_t>& value);

    NSMutableData* to_mutable_data(const std::vector<std::uint8_t>& value);
    std::vector<std::uint8_t> from_data(NSData* value);

    std::vector<std::uint64_t> pack_var_args(const std::vector<cocoon::VarArg>& args);

    inline va_list make_va_list(std::vector<std::uint64_t>& slots)
    {
        static_assert(sizeof(va_list) == sizeof(void*), "va_list must be a plain pointer (arm64)");
        va_list list;
        void* pointer = slots.data();
        std::memcpy(&list, &pointer, sizeof(list));
        return list;
    }

    template <class T>
    inline T load_symbol(const char* name, T fallback)
    {
        void* address = dlsym(RTLD_DEFAULT, name);
        return address ? *static_cast<T*>(address) : fallback;
    }

    void bind_action(id target, id host, Handler handler);
    void observe(id host, id object, NSNotificationName name, Handler handler);
    void keep_delegate(id host, id delegate, void (^refresh)(void));

    NSString* to(const std::string& value);
    std::string from(NSString* value);
    std::string from(const char* value);
    NSArray<NSString*>* to(const std::vector<std::string>& value);
    std::vector<std::string> from(NSArray<NSString*>* value);
    std::vector<std::string> from_urls(NSArray<NSURL*>* value);
    CGSize to(const cocoon::Size& value);
    cocoon::Size from(CGSize value);
    CGPoint to(const cocoon::Point& value);
    cocoon::Point from(CGPoint value);
    CGRect to(const cocoon::Rect& value);
    cocoon::Rect from(CGRect value);
    NSEdgeInsets to(const cocoon::Insets& value);
    cocoon::Insets from(NSEdgeInsets value);

    NSApplication* make_application();
    NSWindow* make_window(const std::string& title, cocoon::Size size, cocoon::WindowStyle style);
    void show_window(NSWindow* window);
    NSViewController* make_view_controller(const cocoon::View& view);
    NSSplitViewController* make_split_view_controller();
    NSMenuItem* make_menu_item(const std::string& title, const std::string& shortcut);
    NSMenuItem* make_standard_menu_item(cocoon::StandardAction action);
    void apply_shortcut(NSMenuItem* item, const std::string& shortcut);
    NSToolbar* make_toolbar(const std::string& identifier);
    NSToolbarItem* make_toolbar_item(const std::string& identifier, const std::string& label, const std::string& symbol);
    void toolbar_add(NSToolbar* toolbar, NSString* identifier, NSToolbarItem* item, bool isDefault, bool required);
    void install_toolbar_provider(void* native);
    NSAlert* make_alert(const std::string& message, const std::string& informativeText, cocoon::AlertStyle style);
    NSImageView* make_image_view(const cocoon::Image& image);
    NSBox* make_separator();
    NSStackView* make_stack(NSUserInterfaceLayoutOrientation orientation);
}
