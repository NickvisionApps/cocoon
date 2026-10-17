#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class MetadataItem;
    class MetadataQueryAttributeValueTuple;
    class MetadataQueryResultGroup;
    class OperationQueue;
    class Predicate;
    class SortDescriptor;

    /**
     * @brief C++ handle for the Objective-C class `NSMetadataQuery` (Foundation).
     * @details A query that you perform against Spotlight metadata. The ''NSMetadataQuery'' class encapsulates the functionality provided by the \<doc://com.apple.documentation/documentation/coreservices/file_metadata/mdquery> opaque type for querying the Spotlight metadata. ''NSMetadataQuery'' objects provide metadata query results in several ways: - As individual attribute values for requested attributes. - As value lists that contain the distinct values for given attributes in the query results. - As a result array proxy, containing all the query results. This is suitable for use with Cocoa bindings. - As a hierarchical collection of results, grouping together items with the same values for specified grouping attributes. This is also suitable for use with Cocoa bindings. Queries have two phases: the initial gathering phase that collects all currently matching results and a second live-update phase. By default, the receiver has no limitation on its search scope. Use the ''searchScopes'' property to customize. By default, notification of updated results occurs at 1.0 seconds. Use the ''notificationBatchingInterval'' property to customize. You must set a predicate with the ''predicate'' property before starting a query.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MetadataQuery metadata_query;
     * metadata_query.set_grouping_attributes({"a", "b"});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MetadataQuery metadata_query{};
     * metadata_query.set_grouping_attributes({"a", "b"});
     * auto grouping_attributes = metadata_query.grouping_attributes();
     * metadata_query.set_notification_batching_interval(1);
     * auto notification_batching_interval = metadata_query.notification_batching_interval();
     * metadata_query.set_operation_queue(cocoon::OperationQueue());
     * auto operation_queue = metadata_query.operation_queue();
     * metadata_query.disable_updates();
     * metadata_query.enable_updates();
     * metadata_query.result_at_index(1);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmetadataquery
     */
    class MetadataQuery : public Object
    {
    public:
        /// @brief Creates a new `NSMetadataQuery` instance and returns a handle to it.
        explicit MetadataQuery();
        /// @brief Creates a null handle that refers to no native object.
        MetadataQuery(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MetadataQuery(Adopt adopt);
        /**
     * @brief Calls `-[NSMetadataQuery disableUpdates]`.
     * @details Disables updates to the query results. These nest.
     */
        void disable_updates() const;
        /**
     * @brief Calls `-[NSMetadataQuery enableUpdates]`.
     * @details Enables updates to the query results.
     */
        void enable_updates() const;
        /**
     * @brief Calls `-[NSMetadataQuery enumerateResultsUsingBlock:]`.
     * @details Enumerates the current set of results using the given block. This method disables the query at the start of the iteration and reenables it upon completion.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void enumerate_results_using_block(std::function<void(Object, std::uint64_t, bool&)> block) const;
        /**
     * @brief Calls `-[NSMetadataQuery enumerateResultsWithOptions:usingBlock:]`.
     * @details Enumerates the current set of results using the given block and enumeration options.
     * @param opts Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void enumerate_results_with_options(EnumerationOptions opts, std::function<void(Object, std::uint64_t, bool&)> block) const;
        /**
     * @brief Calls `-[NSMetadataQuery indexOfResult:]`.
     * @details Returns the index of the specified result.
     * @param result Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t index_of_result(const Object& result) const;
        /**
     * @brief Calls `-[NSMetadataQuery resultAtIndex:]`.
     * @details Returns the query result at a specific index. For performance reasons, use this method when retrieving a specific result, rather than the array returned by the results property.
     * @param idx Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object result_at_index(std::uint64_t idx) const;
        /**
     * @brief Calls `-[NSMetadataQuery startQuery]`.
     * @details Attempts to start the query. Returns YES when successful; otherwise, NO. A query may fail to start if it does not specify a predicate, or if the query has already been started. This method must be called from the receiver's operationQueue or on the main thread.
     * @return The converted Objective-C result.
     */
        bool start_query() const;
        /**
     * @brief Calls `-[NSMetadataQuery stopQuery]`.
     * @details Stops the query from generating any further results.
     */
        void stop_query() const;
        /**
     * @brief Calls `-[NSMetadataQuery valueOfAttribute:forResultAtIndex:]`.
     * @details Returns the value for the attribute name attrName at the index in the results specified by idx. The attribute must be specified in valueListAttributes, as a sorting key in a specified sort descriptor, or as one of the grouping attributes specified for the query.
     * @param attr_name Argument converted to the Objective-C parameter of the same role.
     * @param idx Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object value_of_attribute(const std::string& attr_name, std::uint64_t idx) const;
        /**
     * @brief Returns the `gathering` property of `NSMetadataQuery`.
     * @details A Boolean value that indicates whether the query is in its initial gathering phase.
     * @return The converted Objective-C result.
     */
        bool is_gathering() const;
        /**
     * @brief Returns the `groupedResults` property of `NSMetadataQuery`.
     * @details An array of NSMetadataQueryResultGroups, for the first grouping attribute.
     * @return The converted Objective-C result.
     */
        std::vector<MetadataQueryResultGroup> grouped_results() const;
        /**
     * @brief Returns the `groupingAttributes` property of `NSMetadataQuery`.
     * @details An array of attributes used to group query results.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> grouping_attributes() const;
        /**
     * @brief Sets the `groupingAttributes` property of `NSMetadataQuery`.
     * @details An array of attributes used to group query results.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_grouping_attributes(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `notificationBatchingInterval` property of `NSMetadataQuery`.
     * @details The interval at which notification of updated results occurs.
     * @return The converted Objective-C result.
     */
        double notification_batching_interval() const;
        /**
     * @brief Sets the `notificationBatchingInterval` property of `NSMetadataQuery`.
     * @details The interval at which notification of updated results occurs.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_notification_batching_interval(double value) const;
        /**
     * @brief Returns the `operationQueue` property of `NSMetadataQuery`.
     * @details An optional operation queue for notifications and delegate method calls.
     * @return The converted Objective-C result.
     */
        OperationQueue operation_queue() const;
        /**
     * @brief Sets the `operationQueue` property of `NSMetadataQuery`.
     * @details An optional operation queue for notifications and delegate method calls.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_operation_queue(const OperationQueue& value) const;
        /**
     * @brief Returns the `predicate` property of `NSMetadataQuery`.
     * @details The predicate used to filter query results. Setting this property while a query is running stops the query and discards the current results. The receiver immediately starts a new query.
     * @return The converted Objective-C result.
     */
        Predicate predicate() const;
        /**
     * @brief Sets the `predicate` property of `NSMetadataQuery`.
     * @details The predicate used to filter query results. Setting this property while a query is running stops the query and discards the current results. The receiver immediately starts a new query.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_predicate(const Predicate& value) const;
        /**
     * @brief Returns the `resultCount` property of `NSMetadataQuery`.
     * @details The number of results returned by the query.
     * @return The converted Objective-C result.
     */
        std::uint64_t result_count() const;
        /**
     * @brief Returns the `results` property of `NSMetadataQuery`.
     * @details An array containing the query's results. This is for key-value bindings, and causes side-effects on the query.
     * @return The converted Objective-C result.
     */
        std::vector<Object> results() const;
        /**
     * @brief Returns the `searchItems` property of `NSMetadataQuery`.
     * @details An array of objects that the query will search. Items can be a mixture of NSMetadataItem, NSURL objects (file URLs only) and/or string paths; the getter returns the same mixture as was set.
     * @return The converted Objective-C result.
     */
        std::vector<Object> search_items() const;
        /**
     * @brief Sets the `searchItems` property of `NSMetadataQuery`.
     * @details An array of objects that the query will search. Items can be a mixture of NSMetadataItem, NSURL objects (file URLs only) and/or string paths; the getter returns the same mixture as was set.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_search_items(const std::vector<Object>& value) const;
        /**
     * @brief Returns the `searchScopes` property of `NSMetadataQuery`.
     * @details An array of search scopes that limits where the query searches for results. Scopes is an NSArray of NSURL objects (file URLs only) and/or string paths and/or the special string constants below, which specifies the locations to which the search is limited; an empty array means no limits, which is the default state.
     * @return The converted Objective-C result.
     */
        std::vector<Object> search_scopes() const;
        /**
     * @brief Sets the `searchScopes` property of `NSMetadataQuery`.
     * @details An array of search scopes that limits where the query searches for results. Scopes is an NSArray of NSURL objects (file URLs only) and/or string paths and/or the special string constants below, which specifies the locations to which the search is limited; an empty array means no limits, which is the default state.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_search_scopes(const std::vector<Object>& value) const;
        /**
     * @brief Returns the `sortDescriptors` property of `NSMetadataQuery`.
     * @details An array of sort descriptors to use when sorting the query results.
     * @return The converted Objective-C result.
     */
        std::vector<SortDescriptor> sort_descriptors() const;
        /**
     * @brief Sets the `sortDescriptors` property of `NSMetadataQuery`.
     * @details An array of sort descriptors to use when sorting the query results.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_sort_descriptors(const std::vector<SortDescriptor>& value) const;
        /**
     * @brief Returns the `started` property of `NSMetadataQuery`.
     * @details A Boolean value that indicates whether the query has started.
     * @return The converted Objective-C result.
     */
        bool is_started() const;
        /**
     * @brief Returns the `stopped` property of `NSMetadataQuery`.
     * @details A Boolean value that indicates whether the query has been stopped.
     * @return The converted Objective-C result.
     */
        bool is_stopped() const;
        /**
     * @brief Returns the `valueListAttributes` property of `NSMetadataQuery`.
     * @details An array of attributes whose values are gathered by the query.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> value_list_attributes() const;
        /**
     * @brief Sets the `valueListAttributes` property of `NSMetadataQuery`.
     * @details An array of attributes whose values are gathered by the query.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_value_list_attributes(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `valueLists` property of `NSMetadataQuery`.
     * @details A dictionary containing arrays of attribute value tuples, keyed by attribute name. Values are arrays of 'NSMetadataQueryAttributeValueTuple'.
     * @return The converted Objective-C result.
     */
        std::map<std::string, std::vector<MetadataQueryAttributeValueTuple>> value_lists() const;
        /// @brief Signal for the delegate/data-source method behind `replacement_object_for_result_object`; connect a callback with `replacement_object_for_result_object().connect(...)`.
        Signal<MetadataQuery, Object(MetadataItem)> replacement_object_for_result_object() const
        {
            return Signal<MetadataQuery, Object(MetadataItem)>(handle(), "replacement_object_for_result_object");
        }
        /// @brief Signal for the delegate/data-source method behind `replacement_value_for_attribute_value`; connect a callback with `replacement_value_for_attribute_value().connect(...)`.
        Signal<MetadataQuery, Object(std::string, Object)> replacement_value_for_attribute_value() const
        {
            return Signal<MetadataQuery, Object(std::string, Object)>(handle(), "replacement_value_for_attribute_value");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
