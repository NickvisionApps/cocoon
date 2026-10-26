#pragma once

#include "generated/availability.h"
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
         */
        void disable_updates() const;
        /**
         * @brief Calls `-[NSMetadataQuery enableUpdates]`.
         */
        void enable_updates() const;
        /**
         * @brief Calls `-[NSMetadataQuery enumerateResultsUsingBlock:]`.
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void enumerate_results_using_block(std::function<void(Object, std::uint64_t, bool&)> block) const;
        /**
         * @brief Calls `-[NSMetadataQuery enumerateResultsWithOptions:usingBlock:]`.
         * @param opts Argument converted to the Objective-C parameter of the same role.
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void enumerate_results_with_options(EnumerationOptions opts, std::function<void(Object, std::uint64_t, bool&)> block) const;
        /**
         * @brief Calls `-[NSMetadataQuery indexOfResult:]`.
         * @param result Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::uint64_t index_of_result(const Object& result) const;
        /**
         * @brief Calls `-[NSMetadataQuery resultAtIndex:]`.
         * @param idx Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object result_at_index(std::uint64_t idx) const;
        /**
         * @brief Calls `-[NSMetadataQuery startQuery]`.
         * @return The converted Objective-C result.
         */
        bool start_query() const;
        /**
         * @brief Calls `-[NSMetadataQuery stopQuery]`.
         */
        void stop_query() const;
        /**
         * @brief Calls `-[NSMetadataQuery valueOfAttribute:forResultAtIndex:]`.
         * @param attr_name Argument converted to the Objective-C parameter of the same role.
         * @param idx Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object value_of_attribute(const std::string& attr_name, std::uint64_t idx) const;
        /**
         * @brief Returns the `gathering` property of `NSMetadataQuery`.
         * @return The converted Objective-C result.
         */
        bool is_gathering() const;
        /**
         * @brief Returns the `groupedResults` property of `NSMetadataQuery`.
         * @return The converted Objective-C result.
         */
        std::vector<MetadataQueryResultGroup> grouped_results() const;
        /**
         * @brief Returns the `groupingAttributes` property of `NSMetadataQuery`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> grouping_attributes() const;
        /**
         * @brief Sets the `groupingAttributes` property of `NSMetadataQuery`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_grouping_attributes(const std::vector<std::string>& value) const;
        /**
         * @brief Returns the `notificationBatchingInterval` property of `NSMetadataQuery`.
         * @return The converted Objective-C result.
         */
        double notification_batching_interval() const;
        /**
         * @brief Sets the `notificationBatchingInterval` property of `NSMetadataQuery`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_notification_batching_interval(double value) const;
        /**
         * @brief Returns the `operationQueue` property of `NSMetadataQuery`.
         * @return The converted Objective-C result.
         */
        OperationQueue operation_queue() const;
        /**
         * @brief Sets the `operationQueue` property of `NSMetadataQuery`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_operation_queue(const OperationQueue& value) const;
        /**
         * @brief Returns the `predicate` property of `NSMetadataQuery`.
         * @return The converted Objective-C result.
         */
        Predicate predicate() const;
        /**
         * @brief Sets the `predicate` property of `NSMetadataQuery`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_predicate(const Predicate& value) const;
        /**
         * @brief Returns the `resultCount` property of `NSMetadataQuery`.
         * @return The converted Objective-C result.
         */
        std::uint64_t result_count() const;
        /**
         * @brief Returns the `results` property of `NSMetadataQuery`.
         * @return The converted Objective-C result.
         */
        std::vector<Object> results() const;
        /**
         * @brief Returns the `searchItems` property of `NSMetadataQuery`.
         * @return The converted Objective-C result.
         */
        std::vector<Object> search_items() const;
        /**
         * @brief Sets the `searchItems` property of `NSMetadataQuery`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_search_items(const std::vector<Object>& value) const;
        /**
         * @brief Returns the `searchScopes` property of `NSMetadataQuery`.
         * @return The converted Objective-C result.
         */
        std::vector<Object> search_scopes() const;
        /**
         * @brief Sets the `searchScopes` property of `NSMetadataQuery`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_search_scopes(const std::vector<Object>& value) const;
        /**
         * @brief Returns the `sortDescriptors` property of `NSMetadataQuery`.
         * @return The converted Objective-C result.
         */
        std::vector<SortDescriptor> sort_descriptors() const;
        /**
         * @brief Sets the `sortDescriptors` property of `NSMetadataQuery`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_sort_descriptors(const std::vector<SortDescriptor>& value) const;
        /**
         * @brief Returns the `started` property of `NSMetadataQuery`.
         * @return The converted Objective-C result.
         */
        bool is_started() const;
        /**
         * @brief Returns the `stopped` property of `NSMetadataQuery`.
         * @return The converted Objective-C result.
         */
        bool is_stopped() const;
        /**
         * @brief Returns the `valueListAttributes` property of `NSMetadataQuery`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> value_list_attributes() const;
        /**
         * @brief Sets the `valueListAttributes` property of `NSMetadataQuery`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_value_list_attributes(const std::vector<std::string>& value) const;
        /**
         * @brief Returns the `valueLists` property of `NSMetadataQuery`.
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
