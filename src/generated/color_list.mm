#include "generated/color_list.h"
#include "internal.h"

namespace cocoon
{
    ColorList::ColorList(const std::string& name) : ColorList(Adopt{cocoon::internal::retain([[::NSColorList alloc] initWithName:cocoon::internal::to(name)])})
    {
    }

    ColorList::ColorList(const std::string& name, const std::string& path) : ColorList(Adopt{cocoon::internal::retain([[::NSColorList alloc] initWithName:cocoon::internal::to(name) fromFile:cocoon::internal::to(path)])})
    {
    }

    ColorList::ColorList() : ColorList(Adopt{cocoon::internal::retain([[::NSColorList alloc] init])})
    {
    }

    ColorList::ColorList(std::nullptr_t) : Object(nullptr)
    {
    }

    ColorList::ColorList(Adopt adopt) : Object(adopt)
    {
    }

    ColorList ColorList::color_list_named(const std::string& name)
    {
        return cocoon::internal::wrap<ColorList>([::NSColorList colorListNamed:cocoon::internal::to(name)]);
    }

    Color ColorList::color_with_key(const std::string& key) const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSColorList>(this) colorWithKey:cocoon::internal::to(key)]);
    }

    void ColorList::insert_color(const Color& color, const std::string& key, std::uint64_t loc) const
    {
        [cocoon::internal::ns<::NSColorList>(this) insertColor:cocoon::internal::native<::NSColor>(color) key:cocoon::internal::to(key) atIndex:static_cast<::NSUInteger>(loc)];
    }

    void ColorList::remove_color_with_key(const std::string& key) const
    {
        [cocoon::internal::ns<::NSColorList>(this) removeColorWithKey:cocoon::internal::to(key)];
    }

    void ColorList::remove_file() const
    {
        [cocoon::internal::ns<::NSColorList>(this) removeFile];
    }

    void ColorList::set_color(const Color& color, const std::string& key) const
    {
        [cocoon::internal::ns<::NSColorList>(this) setColor:cocoon::internal::native<::NSColor>(color) forKey:cocoon::internal::to(key)];
    }

    bool ColorList::write_to_url(const URL& url) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSColorList>(this) writeToURL:cocoon::internal::native<::NSURL>(url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    std::vector<std::string> ColorList::all_keys() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSColorList>(this) allKeys], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    std::vector<ColorList> ColorList::available_color_lists()
    {
        return cocoon::internal::from_array<ColorList>([::NSColorList availableColorLists], [](id e) -> ColorList
                                                       {
                                                           return cocoon::internal::wrap<ColorList>((::NSColorList*)e);
                                                       });
    }

    bool ColorList::is_editable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSColorList>(this) isEditable]);
    }

    std::string ColorList::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSColorList>(this) name]);
    }
}
