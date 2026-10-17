#include "generated/bundle.h"
#include "internal.h"

namespace cocoon
{
    Bundle::Bundle(const std::string& path) : Bundle(Adopt{cocoon::internal::retain([[::NSBundle alloc] initWithPath:cocoon::internal::to(path)])})
    {
    }

    Bundle::Bundle(const URL& url) : Bundle(Adopt{cocoon::internal::retain([[::NSBundle alloc] initWithURL:cocoon::internal::native<::NSURL>(url)])})
    {
    }

    Bundle::Bundle() : Bundle(Adopt{cocoon::internal::retain([[::NSBundle alloc] init])})
    {
    }

    Bundle::Bundle(std::nullptr_t) : Object(nullptr)
    {
    }

    Bundle::Bundle(Adopt adopt) : Object(adopt)
    {
    }

    URL Bundle::url_for_auxiliary_executable(const std::string& executable_name) const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSBundle>(this) URLForAuxiliaryExecutable:cocoon::internal::to(executable_name)]);
    }

    URL Bundle::url_for_image_resource(const std::string& name) const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSBundle>(this) URLForImageResource:cocoon::internal::to(name)]);
    }

    URL Bundle::url_for_resource(const std::string& name, const std::string& ext) const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSBundle>(this) URLForResource:cocoon::internal::to(name) withExtension:cocoon::internal::to(ext)]);
    }

    URL Bundle::url_for_resource(const std::string& name, const std::string& ext, const std::string& subpath) const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSBundle>(this) URLForResource:cocoon::internal::to(name) withExtension:cocoon::internal::to(ext) subdirectory:cocoon::internal::to(subpath)]);
    }

    URL Bundle::url_for_resource(const std::string& name, const std::string& ext, const std::string& subpath, const URL& bundle_url)
    {
        return cocoon::internal::wrap<URL>([::NSBundle URLForResource:cocoon::internal::to(name) withExtension:cocoon::internal::to(ext) subdirectory:cocoon::internal::to(subpath) inBundleWithURL:cocoon::internal::native<::NSURL>(bundle_url)]);
    }

    URL Bundle::url_for_resource(const std::string& name, const std::string& ext, const std::string& subpath, const std::string& localization_name) const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSBundle>(this) URLForResource:cocoon::internal::to(name) withExtension:cocoon::internal::to(ext) subdirectory:cocoon::internal::to(subpath) localization:cocoon::internal::to(localization_name)]);
    }

    std::vector<URL> Bundle::ur_ls_for_resources_with_extension(const std::string& ext, const std::string& subpath) const
    {
        return cocoon::internal::from_array<URL>([cocoon::internal::ns<::NSBundle>(this) URLsForResourcesWithExtension:cocoon::internal::to(ext) subdirectory:cocoon::internal::to(subpath)], [](id e) -> URL
                                   {
                                       return cocoon::internal::wrap<URL>((::NSURL*)e);
                                   });
    }

    std::vector<URL> Bundle::ur_ls_for_resources_with_extension(const std::string& ext, const std::string& subpath, const URL& bundle_url)
    {
        return cocoon::internal::from_array<URL>([::NSBundle URLsForResourcesWithExtension:cocoon::internal::to(ext) subdirectory:cocoon::internal::to(subpath) inBundleWithURL:cocoon::internal::native<::NSURL>(bundle_url)], [](id e) -> URL
                                   {
                                       return cocoon::internal::wrap<URL>((::NSURL*)e);
                                   });
    }

    std::vector<URL> Bundle::ur_ls_for_resources_with_extension(const std::string& ext, const std::string& subpath, const std::string& localization_name) const
    {
        return cocoon::internal::from_array<URL>([cocoon::internal::ns<::NSBundle>(this) URLsForResourcesWithExtension:cocoon::internal::to(ext) subdirectory:cocoon::internal::to(subpath) localization:cocoon::internal::to(localization_name)], [](id e) -> URL
                                   {
                                       return cocoon::internal::wrap<URL>((::NSURL*)e);
                                   });
    }

    Bundle Bundle::bundle_for_class(const std::string& a_class)
    {
        return cocoon::internal::wrap<Bundle>([::NSBundle bundleForClass:NSClassFromString(cocoon::internal::to(a_class))]);
    }

    Bundle Bundle::bundle_with_identifier(const std::string& identifier)
    {
        return cocoon::internal::wrap<Bundle>([::NSBundle bundleWithIdentifier:cocoon::internal::to(identifier)]);
    }

    Bundle Bundle::bundle_with_path(const std::string& path)
    {
        return cocoon::internal::wrap<Bundle>([::NSBundle bundleWithPath:cocoon::internal::to(path)]);
    }

    Bundle Bundle::bundle_with_url(const URL& url)
    {
        return cocoon::internal::wrap<Bundle>([::NSBundle bundleWithURL:cocoon::internal::native<::NSURL>(url)]);
    }

    std::string Bundle::class_named(const std::string& class_name) const
    {
        return cocoon::internal::from(NSStringFromClass([cocoon::internal::ns<::NSBundle>(this) classNamed:cocoon::internal::to(class_name)]));
    }

    AttributedString Bundle::context_help_for_key(const std::string& key) const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSBundle>(this) contextHelpForKey:cocoon::internal::to(key)]);
    }

    Image Bundle::image_for_resource(const std::string& name) const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSBundle>(this) imageForResource:cocoon::internal::to(name)]);
    }

    bool Bundle::load_and_return_error() const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSBundle>(this) loadAndReturnError:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool Bundle::load_nib_named(const std::string& nib_name, const Object& owner, std::vector<Object>& top_level_objects) const
    {
        NSArray* __v_top_level_objects = nil;
        auto __r = [cocoon::internal::ns<::NSBundle>(this) loadNibNamed:cocoon::internal::to(nib_name) owner:cocoon::internal::native_id(owner) topLevelObjects:&__v_top_level_objects];
        top_level_objects = cocoon::internal::from_array<Object>(__v_top_level_objects, [](id e) -> Object
                                                   {
                                                       return cocoon::internal::wrap<Object>(e);
                                                   });
        return static_cast<bool>(__r);
    }

    AttributedString Bundle::localized_attributed_string_for_key(const std::string& key, const std::string& value, const std::string& table_name) const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSBundle>(this) localizedAttributedStringForKey:cocoon::internal::to(key) value:cocoon::internal::to(value) table:cocoon::internal::to(table_name)]);
    }

    std::string Bundle::localized_string_for_key(const std::string& key, const std::string& value, const std::string& table_name) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBundle>(this) localizedStringForKey:cocoon::internal::to(key) value:cocoon::internal::to(value) table:cocoon::internal::to(table_name)]);
    }

    std::string Bundle::localized_string_for_key(const std::string& key, const std::string& value, const std::string& table_name, const std::vector<std::string>& localizations) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBundle>(this) localizedStringForKey:cocoon::internal::to(key)
                                                                  value:cocoon::internal::to(value)
                                                                  table:cocoon::internal::to(table_name)
                                                          localizations:cocoon::internal::to_array(localizations, [](const std::string& e) -> id
                                                                                     {
                                                                                         return cocoon::internal::to(e);
                                                                                     })]);
    }

    Object Bundle::object_for_info_dictionary_key(const std::string& key) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSBundle>(this) objectForInfoDictionaryKey:cocoon::internal::to(key)]);
    }

    std::string Bundle::path_for_auxiliary_executable(const std::string& executable_name) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBundle>(this) pathForAuxiliaryExecutable:cocoon::internal::to(executable_name)]);
    }

    std::string Bundle::path_for_image_resource(const std::string& name) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBundle>(this) pathForImageResource:cocoon::internal::to(name)]);
    }

    std::string Bundle::path_for_resource(const std::string& name, const std::string& ext) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBundle>(this) pathForResource:cocoon::internal::to(name) ofType:cocoon::internal::to(ext)]);
    }

    std::string Bundle::path_for_resource(const std::string& name, const std::string& ext, const std::string& subpath) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBundle>(this) pathForResource:cocoon::internal::to(name) ofType:cocoon::internal::to(ext) inDirectory:cocoon::internal::to(subpath)]);
    }

    std::string Bundle::path_for_resource(const std::string& name, const std::string& ext, const std::string& subpath, const std::string& localization_name) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBundle>(this) pathForResource:cocoon::internal::to(name) ofType:cocoon::internal::to(ext) inDirectory:cocoon::internal::to(subpath) forLocalization:cocoon::internal::to(localization_name)]);
    }

    std::string Bundle::path_for_sound_resource(const std::string& name) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBundle>(this) pathForSoundResource:cocoon::internal::to(name)]);
    }

    std::vector<std::string> Bundle::paths_for_resources_of_type(const std::string& ext, const std::string& subpath) const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSBundle>(this) pathsForResourcesOfType:cocoon::internal::to(ext) inDirectory:cocoon::internal::to(subpath)], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Bundle::paths_for_resources_of_type(const std::string& ext, const std::string& subpath, const std::string& localization_name) const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSBundle>(this) pathsForResourcesOfType:cocoon::internal::to(ext) inDirectory:cocoon::internal::to(subpath) forLocalization:cocoon::internal::to(localization_name)], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Bundle::preferred_localizations_from_array(const std::vector<std::string>& localizations_array)
    {
        return cocoon::internal::from_array<std::string>([::NSBundle preferredLocalizationsFromArray:cocoon::internal::to_array(localizations_array, [](const std::string& e) -> id
                                                                                                    {
                                                                                                        return cocoon::internal::to(e);
                                                                                                    })],
                                           [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Bundle::preferred_localizations_from_array(const std::vector<std::string>& localizations_array, const std::vector<std::string>& preferences_array)
    {
        return cocoon::internal::from_array<std::string>([::NSBundle preferredLocalizationsFromArray:cocoon::internal::to_array(localizations_array, [](const std::string& e) -> id
                                                                                                    {
                                                                                                        return cocoon::internal::to(e);
                                                                                                    })
                                                                        forPreferences:cocoon::internal::to_array(preferences_array, [](const std::string& e) -> id
                                                                                                    {
                                                                                                        return cocoon::internal::to(e);
                                                                                                    })],
                                           [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    bool Bundle::preflight_and_return_error() const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSBundle>(this) preflightAndReturnError:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool Bundle::unload() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBundle>(this) unload]);
    }

    std::vector<Bundle> Bundle::all_bundles()
    {
        return cocoon::internal::from_array<Bundle>([::NSBundle allBundles], [](id e) -> Bundle
                                      {
                                          return cocoon::internal::wrap<Bundle>((::NSBundle*)e);
                                      });
    }

    std::vector<Bundle> Bundle::all_frameworks()
    {
        return cocoon::internal::from_array<Bundle>([::NSBundle allFrameworks], [](id e) -> Bundle
                                      {
                                          return cocoon::internal::wrap<Bundle>((::NSBundle*)e);
                                      });
    }

    URL Bundle::app_store_receipt_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSBundle>(this) appStoreReceiptURL]);
    }

    std::string Bundle::built_in_plug_ins_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBundle>(this) builtInPlugInsPath]);
    }

    URL Bundle::built_in_plug_ins_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSBundle>(this) builtInPlugInsURL]);
    }

    std::string Bundle::bundle_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBundle>(this) bundleIdentifier]);
    }

    std::string Bundle::bundle_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBundle>(this) bundlePath]);
    }

    URL Bundle::bundle_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSBundle>(this) bundleURL]);
    }

    std::string Bundle::development_localization() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBundle>(this) developmentLocalization]);
    }

    std::vector<Number> Bundle::executable_architectures() const
    {
        return cocoon::internal::from_array<Number>([cocoon::internal::ns<::NSBundle>(this) executableArchitectures], [](id e) -> Number
                                      {
                                          return cocoon::internal::wrap<Number>((::NSNumber*)e);
                                      });
    }

    std::string Bundle::executable_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBundle>(this) executablePath]);
    }

    URL Bundle::executable_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSBundle>(this) executableURL]);
    }

    std::map<std::string, Object> Bundle::info_dictionary() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSBundle>(this) infoDictionary], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    bool Bundle::is_loaded() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBundle>(this) isLoaded]);
    }

    std::vector<std::string> Bundle::localizations() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSBundle>(this) localizations], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::map<std::string, Object> Bundle::localized_info_dictionary() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSBundle>(this) localizedInfoDictionary], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    Bundle Bundle::main_bundle()
    {
        return cocoon::internal::wrap<Bundle>([::NSBundle mainBundle]);
    }

    std::vector<std::string> Bundle::preferred_localizations() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSBundle>(this) preferredLocalizations], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::string Bundle::principal_class() const
    {
        return cocoon::internal::from(NSStringFromClass([cocoon::internal::ns<::NSBundle>(this) principalClass]));
    }

    std::string Bundle::private_frameworks_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBundle>(this) privateFrameworksPath]);
    }

    URL Bundle::private_frameworks_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSBundle>(this) privateFrameworksURL]);
    }

    std::string Bundle::resource_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBundle>(this) resourcePath]);
    }

    URL Bundle::resource_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSBundle>(this) resourceURL]);
    }

    std::string Bundle::shared_frameworks_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBundle>(this) sharedFrameworksPath]);
    }

    URL Bundle::shared_frameworks_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSBundle>(this) sharedFrameworksURL]);
    }

    std::string Bundle::shared_support_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBundle>(this) sharedSupportPath]);
    }

    URL Bundle::shared_support_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSBundle>(this) sharedSupportURL]);
    }
}
