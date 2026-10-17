#include "generated/metadata_query.h"
#include "internal.h"

@interface AKMetadataQueryDelegate : NSObject <NSMetadataQueryDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKMetadataQueryDelegate

- (id)metadataQuery:(NSMetadataQuery*)query replacementObjectForResultObject:(NSMetadataItem*)result
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::MetadataQuery, cocoon::Object(cocoon::MetadataItem)>::emit((__bridge void*)strongHost, "replacement_object_for_result_object", cocoon::internal::wrap<cocoon::MetadataItem>(result));
    return cocoon::internal::native_id(__r);
}

- (id)metadataQuery:(NSMetadataQuery*)query replacementValueForAttribute:(NSString*)attrName value:(id)attrValue
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::MetadataQuery, cocoon::Object(std::string, cocoon::Object)>::emit((__bridge void*)strongHost, "replacement_value_for_attribute_value", cocoon::internal::from(attrName), cocoon::internal::wrap<cocoon::Object>(attrValue));
    return cocoon::internal::native_id(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(metadataQuery:replacementObjectForResultObject:))
    {
        return strongHost && cocoon::Signal<cocoon::MetadataQuery, cocoon::Object(cocoon::MetadataItem)>::connected((__bridge void*)strongHost, "replacement_object_for_result_object");
    }
    if (selector == @selector(metadataQuery:replacementValueForAttribute:value:))
    {
        return strongHost && cocoon::Signal<cocoon::MetadataQuery, cocoon::Object(std::string, cocoon::Object)>::connected((__bridge void*)strongHost, "replacement_value_for_attribute_value");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    MetadataQuery::MetadataQuery() : MetadataQuery(Adopt{cocoon::internal::retain([[::NSMetadataQuery alloc] init])})
    {
        MetadataQuery::install_delegate_delegate_(handle());
    }

    MetadataQuery::MetadataQuery(std::nullptr_t) : Object(nullptr)
    {
    }

    MetadataQuery::MetadataQuery(Adopt adopt) : Object(adopt)
    {
    }

    void MetadataQuery::disable_updates() const
    {
        [cocoon::internal::ns<::NSMetadataQuery>(this) disableUpdates];
    }

    void MetadataQuery::enable_updates() const
    {
        [cocoon::internal::ns<::NSMetadataQuery>(this) enableUpdates];
    }

    void MetadataQuery::enumerate_results_using_block(std::function<void(Object, std::uint64_t, bool&)> block) const
    {
        [cocoon::internal::ns<::NSMetadataQuery>(this) enumerateResultsUsingBlock:(block ? (void (^)(id, ::NSUInteger, BOOL*)) ^ void(id a192_0, ::NSUInteger a192_1, ::BOOL * a192_2) { bool __o192_2 = a192_2 ? static_cast<bool>(*a192_2) : bool(); block(cocoon::internal::wrap<Object>(a192_0), static_cast<std::uint64_t>(a192_1), __o192_2); if (a192_2) { *a192_2 = static_cast<::BOOL>(__o192_2); } } : (void (^)(id, ::NSUInteger, BOOL*))nil)];
    }

    void MetadataQuery::enumerate_results_with_options(EnumerationOptions opts, std::function<void(Object, std::uint64_t, bool&)> block) const
    {
        [cocoon::internal::ns<::NSMetadataQuery>(this) enumerateResultsWithOptions:static_cast<::NSEnumerationOptions>(opts) usingBlock:(block ? (void (^)(id, ::NSUInteger, BOOL*)) ^ void(id a193_0, ::NSUInteger a193_1, ::BOOL * a193_2) { bool __o193_2 = a193_2 ? static_cast<bool>(*a193_2) : bool(); block(cocoon::internal::wrap<Object>(a193_0), static_cast<std::uint64_t>(a193_1), __o193_2); if (a193_2) { *a193_2 = static_cast<::BOOL>(__o193_2); } } : (void (^)(id, ::NSUInteger, BOOL*))nil)];
    }

    std::uint64_t MetadataQuery::index_of_result(const Object& result) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSMetadataQuery>(this) indexOfResult:cocoon::internal::native_id(result)]);
    }

    Object MetadataQuery::result_at_index(std::uint64_t idx) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSMetadataQuery>(this) resultAtIndex:static_cast<::NSUInteger>(idx)]);
    }

    bool MetadataQuery::start_query() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMetadataQuery>(this) startQuery]);
    }

    void MetadataQuery::stop_query() const
    {
        [cocoon::internal::ns<::NSMetadataQuery>(this) stopQuery];
    }

    Object MetadataQuery::value_of_attribute(const std::string& attr_name, std::uint64_t idx) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSMetadataQuery>(this) valueOfAttribute:cocoon::internal::to(attr_name) forResultAtIndex:static_cast<::NSUInteger>(idx)]);
    }

    bool MetadataQuery::is_gathering() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMetadataQuery>(this) isGathering]);
    }

    std::vector<MetadataQueryResultGroup> MetadataQuery::grouped_results() const
    {
        return cocoon::internal::from_array<MetadataQueryResultGroup>([cocoon::internal::ns<::NSMetadataQuery>(this) groupedResults], [](id e) -> MetadataQueryResultGroup
                                                                      {
                                                                          return cocoon::internal::wrap<MetadataQueryResultGroup>((::NSMetadataQueryResultGroup*)e);
                                                                      });
    }

    std::vector<std::string> MetadataQuery::grouping_attributes() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSMetadataQuery>(this) groupingAttributes], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void MetadataQuery::set_grouping_attributes(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSMetadataQuery>(this) setGroupingAttributes:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                        {
                                                                                                            return cocoon::internal::to(e);
                                                                                                        })];
    }

    double MetadataQuery::notification_batching_interval() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMetadataQuery>(this) notificationBatchingInterval]);
    }

    void MetadataQuery::set_notification_batching_interval(double value) const
    {
        [cocoon::internal::ns<::NSMetadataQuery>(this) setNotificationBatchingInterval:static_cast<::NSTimeInterval>(value)];
    }

    OperationQueue MetadataQuery::operation_queue() const
    {
        return cocoon::internal::wrap<OperationQueue>([cocoon::internal::ns<::NSMetadataQuery>(this) operationQueue]);
    }

    void MetadataQuery::set_operation_queue(const OperationQueue& value) const
    {
        [cocoon::internal::ns<::NSMetadataQuery>(this) setOperationQueue:cocoon::internal::native<::NSOperationQueue>(value)];
    }

    Predicate MetadataQuery::predicate() const
    {
        return cocoon::internal::wrap<Predicate>([cocoon::internal::ns<::NSMetadataQuery>(this) predicate]);
    }

    void MetadataQuery::set_predicate(const Predicate& value) const
    {
        [cocoon::internal::ns<::NSMetadataQuery>(this) setPredicate:cocoon::internal::native<::NSPredicate>(value)];
    }

    std::uint64_t MetadataQuery::result_count() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSMetadataQuery>(this) resultCount]);
    }

    std::vector<Object> MetadataQuery::results() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSMetadataQuery>(this) results], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    std::vector<Object> MetadataQuery::search_items() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSMetadataQuery>(this) searchItems], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    void MetadataQuery::set_search_items(const std::vector<Object>& value) const
    {
        [cocoon::internal::ns<::NSMetadataQuery>(this) setSearchItems:cocoon::internal::to_array(value, [](const Object& e) -> id
                                                                                                 {
                                                                                                     return cocoon::internal::native_id(e);
                                                                                                 })];
    }

    std::vector<Object> MetadataQuery::search_scopes() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSMetadataQuery>(this) searchScopes], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    void MetadataQuery::set_search_scopes(const std::vector<Object>& value) const
    {
        [cocoon::internal::ns<::NSMetadataQuery>(this) setSearchScopes:cocoon::internal::to_array(value, [](const Object& e) -> id
                                                                                                  {
                                                                                                      return cocoon::internal::native_id(e);
                                                                                                  })];
    }

    std::vector<SortDescriptor> MetadataQuery::sort_descriptors() const
    {
        return cocoon::internal::from_array<SortDescriptor>([cocoon::internal::ns<::NSMetadataQuery>(this) sortDescriptors], [](id e) -> SortDescriptor
                                                            {
                                                                return cocoon::internal::wrap<SortDescriptor>((::NSSortDescriptor*)e);
                                                            });
    }

    void MetadataQuery::set_sort_descriptors(const std::vector<SortDescriptor>& value) const
    {
        [cocoon::internal::ns<::NSMetadataQuery>(this) setSortDescriptors:cocoon::internal::to_array(value, [](const SortDescriptor& e) -> id
                                                                                                     {
                                                                                                         return cocoon::internal::native<::NSSortDescriptor>(e);
                                                                                                     })];
    }

    bool MetadataQuery::is_started() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMetadataQuery>(this) isStarted]);
    }

    bool MetadataQuery::is_stopped() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMetadataQuery>(this) isStopped]);
    }

    std::vector<std::string> MetadataQuery::value_list_attributes() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSMetadataQuery>(this) valueListAttributes], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void MetadataQuery::set_value_list_attributes(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSMetadataQuery>(this) setValueListAttributes:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                         {
                                                                                                             return cocoon::internal::to(e);
                                                                                                         })];
    }

    std::map<std::string, std::vector<MetadataQueryAttributeValueTuple>> MetadataQuery::value_lists() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, std::vector<MetadataQueryAttributeValueTuple>>>([cocoon::internal::ns<::NSMetadataQuery>(this) valueLists], [](id k) -> std::string
                                                                                                                       {
                                                                                                                           return cocoon::internal::from((NSString*)k);
                                                                                                                       },
                                                                                                                       [](id v) -> std::vector<MetadataQueryAttributeValueTuple>
                                                                                                                       {
                                                                                                                           return cocoon::internal::from_array<MetadataQueryAttributeValueTuple>((NSArray*)v, [](id e) -> MetadataQueryAttributeValueTuple
                                                                                                                                                                                                 {
                                                                                                                                                                                                     return cocoon::internal::wrap<MetadataQueryAttributeValueTuple>((::NSMetadataQueryAttributeValueTuple*)e);
                                                                                                                                                                                                 });
                                                                                                                       });
    }

    void MetadataQuery::install_delegate_delegate_(void* native)
    {
        ::NSMetadataQuery* host = (__bridge ::NSMetadataQuery*)native;
        AKMetadataQueryDelegate* delegate = [[AKMetadataQueryDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSMetadataQuery* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSMetadataQuery* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
