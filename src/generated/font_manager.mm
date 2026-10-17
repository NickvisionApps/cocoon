#include "generated/font_manager.h"
#include "internal.h"

namespace cocoon
{
    FontManager::FontManager() : FontManager(Adopt{cocoon::internal::retain([[::NSFontManager alloc] init])})
    {
    }

    FontManager::FontManager(std::nullptr_t) : Object(nullptr)
    {
    }

    FontManager::FontManager(Adopt adopt) : Object(adopt)
    {
    }

    void FontManager::add_font_trait(const Object& sender) const
    {
        [cocoon::internal::ns<::NSFontManager>(this) addFontTrait:cocoon::internal::native_id(sender)];
    }

    std::vector<std::string> FontManager::available_font_names_with_traits(FontTraitMask some_traits) const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSFontManager>(this) availableFontNamesWithTraits:static_cast<::NSFontTraitMask>(some_traits)], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::vector<Object>> FontManager::available_members_of_font_family(const std::string& fam) const
    {
        return cocoon::internal::from_array<std::vector<Object>>([cocoon::internal::ns<::NSFontManager>(this) availableMembersOfFontFamily:cocoon::internal::to(fam)], [](id e) -> std::vector<Object>
                                                   {
                                                       return cocoon::internal::from_array<Object>((NSArray*)e, [](id e) -> Object
                                                                                     {
                                                                                         return cocoon::internal::wrap<Object>(e);
                                                                                     });
                                                   });
    }

    std::map<std::string, Object> FontManager::convert_attributes(const std::map<std::string, Object>& attributes) const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSFontManager>(this) convertAttributes:cocoon::internal::to_dictionary(attributes, [](const std::string& k) -> id
                                                                                                                                     {
                                                                                                                                         return cocoon::internal::to(k);
                                                                                                                                     },
                                                                                                                                     [](const Object& v) -> id
                                                                                                                                     {
                                                                                                                                         return cocoon::internal::native_id(v);
                                                                                                                                     })],
                                                                  [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    Font FontManager::convert_font(const Font& font_obj) const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSFontManager>(this) convertFont:cocoon::internal::native<::NSFont>(font_obj)]);
    }

    Font FontManager::convert_font(const Font& font_obj, const std::string& typeface) const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSFontManager>(this) convertFont:cocoon::internal::native<::NSFont>(font_obj) toFace:cocoon::internal::to(typeface)]);
    }

    Font FontManager::convert_font(const Font& font_obj, FontTraitMask trait) const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSFontManager>(this) convertFont:cocoon::internal::native<::NSFont>(font_obj) toHaveTrait:static_cast<::NSFontTraitMask>(trait)]);
    }

    Font FontManager::convert_font(const Font& font_obj, double size) const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSFontManager>(this) convertFont:cocoon::internal::native<::NSFont>(font_obj) toSize:static_cast<::CGFloat>(size)]);
    }

    FontTraitMask FontManager::convert_font_traits(FontTraitMask traits) const
    {
        return static_cast<FontTraitMask>([cocoon::internal::ns<::NSFontManager>(this) convertFontTraits:static_cast<::NSFontTraitMask>(traits)]);
    }

    Font FontManager::convert_weight(bool up_flag, const Font& font_obj) const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSFontManager>(this) convertWeight:static_cast<::BOOL>(up_flag) ofFont:cocoon::internal::native<::NSFont>(font_obj)]);
    }

    Menu FontManager::font_menu(bool create) const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSFontManager>(this) fontMenu:static_cast<::BOOL>(create)]);
    }

    bool FontManager::font_named(const std::string& f_name, FontTraitMask some_traits) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFontManager>(this) fontNamed:cocoon::internal::to(f_name) hasTraits:static_cast<::NSFontTraitMask>(some_traits)]);
    }

    FontPanel FontManager::font_panel(bool create) const
    {
        return cocoon::internal::wrap<FontPanel>([cocoon::internal::ns<::NSFontManager>(this) fontPanel:static_cast<::BOOL>(create)]);
    }

    Font FontManager::font_with_family(const std::string& family, FontTraitMask traits, std::int64_t weight, double size) const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSFontManager>(this) fontWithFamily:cocoon::internal::to(family) traits:static_cast<::NSFontTraitMask>(traits) weight:static_cast<::NSInteger>(weight) size:static_cast<::CGFloat>(size)]);
    }

    std::string FontManager::localized_name_for_family(const std::string& family, const std::string& face_key) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFontManager>(this) localizedNameForFamily:cocoon::internal::to(family) face:cocoon::internal::to(face_key)]);
    }

    void FontManager::modify_font(const Object& sender) const
    {
        [cocoon::internal::ns<::NSFontManager>(this) modifyFont:cocoon::internal::native_id(sender)];
    }

    void FontManager::modify_font_via_panel(const Object& sender) const
    {
        [cocoon::internal::ns<::NSFontManager>(this) modifyFontViaPanel:cocoon::internal::native_id(sender)];
    }

    void FontManager::order_front_font_panel(const Object& sender) const
    {
        [cocoon::internal::ns<::NSFontManager>(this) orderFrontFontPanel:cocoon::internal::native_id(sender)];
    }

    void FontManager::order_front_styles_panel(const Object& sender) const
    {
        [cocoon::internal::ns<::NSFontManager>(this) orderFrontStylesPanel:cocoon::internal::native_id(sender)];
    }

    void FontManager::remove_font_trait(const Object& sender) const
    {
        [cocoon::internal::ns<::NSFontManager>(this) removeFontTrait:cocoon::internal::native_id(sender)];
    }

    bool FontManager::send_action() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFontManager>(this) sendAction]);
    }

    void FontManager::set_font_manager_factory(const std::string& factory_id)
    {
        [::NSFontManager setFontManagerFactory:NSClassFromString(cocoon::internal::to(factory_id))];
    }

    void FontManager::set_font_menu(const Menu& new_menu) const
    {
        [cocoon::internal::ns<::NSFontManager>(this) setFontMenu:cocoon::internal::native<::NSMenu>(new_menu)];
    }

    void FontManager::set_font_panel_factory(const std::string& factory_id)
    {
        [::NSFontManager setFontPanelFactory:NSClassFromString(cocoon::internal::to(factory_id))];
    }

    void FontManager::set_selected_attributes(const std::map<std::string, Object>& attributes, bool flag) const
    {
        [cocoon::internal::ns<::NSFontManager>(this) setSelectedAttributes:cocoon::internal::to_dictionary(attributes, [](const std::string& k) -> id
                                                                               {
                                                                                   return cocoon::internal::to(k);
                                                                               },
                                                                               [](const Object& v) -> id
                                                                               {
                                                                                   return cocoon::internal::native_id(v);
                                                                               })
                                                  isMultiple:static_cast<::BOOL>(flag)];
    }

    void FontManager::set_selected_font(const Font& font_obj, bool flag) const
    {
        [cocoon::internal::ns<::NSFontManager>(this) setSelectedFont:cocoon::internal::native<::NSFont>(font_obj) isMultiple:static_cast<::BOOL>(flag)];
    }

    FontTraitMask FontManager::traits_of_font(const Font& font_obj) const
    {
        return static_cast<FontTraitMask>([cocoon::internal::ns<::NSFontManager>(this) traitsOfFont:cocoon::internal::native<::NSFont>(font_obj)]);
    }

    std::int64_t FontManager::weight_of_font(const Font& font_obj) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSFontManager>(this) weightOfFont:cocoon::internal::native<::NSFont>(font_obj)]);
    }

    std::string FontManager::action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSFontManager>(this) action]));
    }

    void FontManager::set_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSFontManager>(this) setAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    std::vector<std::string> FontManager::available_font_families() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSFontManager>(this) availableFontFamilies], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> FontManager::available_fonts() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSFontManager>(this) availableFonts], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    FontAction FontManager::current_font_action() const
    {
        return static_cast<FontAction>([cocoon::internal::ns<::NSFontManager>(this) currentFontAction]);
    }

    bool FontManager::is_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFontManager>(this) isEnabled]);
    }

    void FontManager::set_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSFontManager>(this) setEnabled:static_cast<::BOOL>(value)];
    }

    bool FontManager::is_multiple() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFontManager>(this) isMultiple]);
    }

    Font FontManager::selected_font() const
    {
        return cocoon::internal::wrap<Font>([cocoon::internal::ns<::NSFontManager>(this) selectedFont]);
    }

    FontManager FontManager::shared_font_manager()
    {
        return cocoon::internal::wrap<FontManager>([::NSFontManager sharedFontManager]);
    }

    Object FontManager::target() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSFontManager>(this) target]);
    }

    void FontManager::set_target(const Object& value) const
    {
        [cocoon::internal::ns<::NSFontManager>(this) setTarget:cocoon::internal::native_id(value)];
    }
}
