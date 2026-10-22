#include "generated/progress.h"
#include "internal.h"

namespace cocoon
{
    Progress::Progress(const Progress& parent_progress_or_nil, const std::map<std::string, Object>& user_info_or_nil) : Progress(Adopt{cocoon::internal::retain([[::NSProgress alloc] initWithParent:cocoon::internal::native<::NSProgress>(parent_progress_or_nil)
                                                                                                                                                                                            userInfo:cocoon::internal::to_dictionary(user_info_or_nil, [](const std::string& k) -> id
                                                                                                                                                                                                                                     {
                                                                                                                                                                                                                                         return cocoon::internal::to(k);
                                                                                                                                                                                                                                     },
                                                                                                                                                                                                                                     [](const Object& v) -> id
                                                                                                                                                                                                                                     {
                                                                                                                                                                                                                                         return cocoon::internal::native_id(v);
                                                                                                                                                                                                                                     })])})
    {
    }

    Progress::Progress(std::int64_t unit_count) : Progress(Adopt{cocoon::internal::retain([::NSProgress progressWithTotalUnitCount:static_cast<::int64_t>(unit_count)])})
    {
    }

    Progress::Progress(std::int64_t unit_count, const Progress& parent, std::int64_t portion_of_parent_total_unit_count) : Progress(Adopt{cocoon::internal::retain([::NSProgress progressWithTotalUnitCount:static_cast<::int64_t>(unit_count) parent:cocoon::internal::native<::NSProgress>(parent) pendingUnitCount:static_cast<::int64_t>(portion_of_parent_total_unit_count)])})
    {
    }

    Progress::Progress() : Progress(Adopt{cocoon::internal::retain([[::NSProgress alloc] init])})
    {
    }

    Progress::Progress(std::nullptr_t) : Object(nullptr)
    {
    }

    Progress::Progress(Adopt adopt) : Object(adopt)
    {
    }

    void Progress::add_child(const Progress& child, std::int64_t in_unit_count) const
    {
        [cocoon::internal::ns<::NSProgress>(this) addChild:cocoon::internal::native<::NSProgress>(child) withPendingUnitCount:static_cast<::int64_t>(in_unit_count)];
    }

    Object Progress::add_subscriber_for_file_url(const URL& url, std::function<std::function<void()>(Progress)> publishing_handler)
    {
        return cocoon::internal::wrap<Object>([::NSProgress addSubscriberForFileURL:cocoon::internal::native<::NSURL>(url) withPublishingHandler:(publishing_handler ? (::NSProgressPublishingHandler) ^ id(::NSProgress * a205_0) { auto __r = publishing_handler(cocoon::internal::wrap<Progress>(a205_0)); return (__r ? (::NSProgressUnpublishingHandler)^void() { __r(); } : (::NSProgressUnpublishingHandler)nil); } : (::NSProgressPublishingHandler)nil)]);
    }

    void Progress::become_current_with_pending_unit_count(std::int64_t unit_count) const
    {
        [cocoon::internal::ns<::NSProgress>(this) becomeCurrentWithPendingUnitCount:static_cast<::int64_t>(unit_count)];
    }

    void Progress::cancel() const
    {
        [cocoon::internal::ns<::NSProgress>(this) cancel];
    }

    Progress Progress::current_progress()
    {
        return cocoon::internal::wrap<Progress>([::NSProgress currentProgress]);
    }

    Progress Progress::discrete_progress_with_total_unit_count(std::int64_t unit_count)
    {
        return cocoon::internal::wrap<Progress>([::NSProgress discreteProgressWithTotalUnitCount:static_cast<::int64_t>(unit_count)]);
    }

    void Progress::pause() const
    {
        [cocoon::internal::ns<::NSProgress>(this) pause];
    }

    void Progress::perform_as_current_with_pending_unit_count(std::int64_t unit_count, std::function<void()> work) const
    {
        [cocoon::internal::ns<::NSProgress>(this) performAsCurrentWithPendingUnitCount:static_cast<::int64_t>(unit_count) usingBlock:(work ? (void (^)(void)) ^ void() { work(); } : (void (^)(void))nil)];
    }

    void Progress::publish() const
    {
        [cocoon::internal::ns<::NSProgress>(this) publish];
    }

    void Progress::remove_subscriber(const Object& subscriber)
    {
        [::NSProgress removeSubscriber:cocoon::internal::native_id(subscriber)];
    }

    void Progress::resign_current() const
    {
        [cocoon::internal::ns<::NSProgress>(this) resignCurrent];
    }

    void Progress::resume() const
    {
        [cocoon::internal::ns<::NSProgress>(this) resume];
    }

    void Progress::set_user_info_object(const Object& object_or_nil, const std::string& key) const
    {
        [cocoon::internal::ns<::NSProgress>(this) setUserInfoObject:cocoon::internal::native_id(object_or_nil) forKey:cocoon::internal::to(key)];
    }

    void Progress::unpublish() const
    {
        [cocoon::internal::ns<::NSProgress>(this) unpublish];
    }

    bool Progress::is_cancellable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSProgress>(this) isCancellable]);
    }

    void Progress::set_cancellable(bool value) const
    {
        [cocoon::internal::ns<::NSProgress>(this) setCancellable:static_cast<::BOOL>(value)];
    }

    std::function<void()> Progress::cancellation_handler() const
    {
        return [&]() -> std::function<void()>
        {
            auto blk = (void (^)(void))([cocoon::internal::ns<::NSProgress>(this) cancellationHandler]);
            if (!blk)
            {
                return {};
            }
            return [blk]() -> void
            {
                blk();
            };
        }();
    }

    void Progress::set_cancellation_handler(std::function<void()> value) const
    {
        [cocoon::internal::ns<::NSProgress>(this) setCancellationHandler:(value ? (void (^)(void)) ^ void() { value(); } : (void (^)(void))nil)];
    }

    bool Progress::is_cancelled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSProgress>(this) isCancelled]);
    }

    std::int64_t Progress::completed_unit_count() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSProgress>(this) completedUnitCount]);
    }

    void Progress::set_completed_unit_count(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSProgress>(this) setCompletedUnitCount:static_cast<::int64_t>(value)];
    }

    Number Progress::estimated_time_remaining() const
    {
        return cocoon::internal::wrap<Number>([cocoon::internal::ns<::NSProgress>(this) estimatedTimeRemaining]);
    }

    void Progress::set_estimated_time_remaining(const Number& value) const
    {
        [cocoon::internal::ns<::NSProgress>(this) setEstimatedTimeRemaining:cocoon::internal::native<::NSNumber>(value)];
    }

    Number Progress::file_completed_count() const
    {
        return cocoon::internal::wrap<Number>([cocoon::internal::ns<::NSProgress>(this) fileCompletedCount]);
    }

    void Progress::set_file_completed_count(const Number& value) const
    {
        [cocoon::internal::ns<::NSProgress>(this) setFileCompletedCount:cocoon::internal::native<::NSNumber>(value)];
    }

    std::string Progress::file_operation_kind() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSProgress>(this) fileOperationKind]);
    }

    void Progress::set_file_operation_kind(const std::string& value) const
    {
        [cocoon::internal::ns<::NSProgress>(this) setFileOperationKind:cocoon::internal::to(value)];
    }

    Number Progress::file_total_count() const
    {
        return cocoon::internal::wrap<Number>([cocoon::internal::ns<::NSProgress>(this) fileTotalCount]);
    }

    void Progress::set_file_total_count(const Number& value) const
    {
        [cocoon::internal::ns<::NSProgress>(this) setFileTotalCount:cocoon::internal::native<::NSNumber>(value)];
    }

    URL Progress::file_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSProgress>(this) fileURL]);
    }

    void Progress::set_file_url(const URL& value) const
    {
        [cocoon::internal::ns<::NSProgress>(this) setFileURL:cocoon::internal::native<::NSURL>(value)];
    }

    bool Progress::is_finished() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSProgress>(this) isFinished]);
    }

    double Progress::fraction_completed() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSProgress>(this) fractionCompleted]);
    }

    bool Progress::is_indeterminate() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSProgress>(this) isIndeterminate]);
    }

    std::string Progress::kind() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSProgress>(this) kind]);
    }

    void Progress::set_kind(const std::string& value) const
    {
        [cocoon::internal::ns<::NSProgress>(this) setKind:cocoon::internal::to(value)];
    }

    std::string Progress::localized_additional_description() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSProgress>(this) localizedAdditionalDescription]);
    }

    void Progress::set_localized_additional_description(const std::string& value) const
    {
        [cocoon::internal::ns<::NSProgress>(this) setLocalizedAdditionalDescription:cocoon::internal::to(value)];
    }

    std::string Progress::localized_description() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSProgress>(this) localizedDescription]);
    }

    void Progress::set_localized_description(const std::string& value) const
    {
        [cocoon::internal::ns<::NSProgress>(this) setLocalizedDescription:cocoon::internal::to(value)];
    }

    bool Progress::is_old() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSProgress>(this) isOld]);
    }

    bool Progress::is_pausable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSProgress>(this) isPausable]);
    }

    void Progress::set_pausable(bool value) const
    {
        [cocoon::internal::ns<::NSProgress>(this) setPausable:static_cast<::BOOL>(value)];
    }

    bool Progress::is_paused() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSProgress>(this) isPaused]);
    }

    std::function<void()> Progress::pausing_handler() const
    {
        return [&]() -> std::function<void()>
        {
            auto blk = (void (^)(void))([cocoon::internal::ns<::NSProgress>(this) pausingHandler]);
            if (!blk)
            {
                return {};
            }
            return [blk]() -> void
            {
                blk();
            };
        }();
    }

    void Progress::set_pausing_handler(std::function<void()> value) const
    {
        [cocoon::internal::ns<::NSProgress>(this) setPausingHandler:(value ? (void (^)(void)) ^ void() { value(); } : (void (^)(void))nil)];
    }

    std::function<void()> Progress::resuming_handler() const
    {
        return [&]() -> std::function<void()>
        {
            auto blk = (void (^)(void))([cocoon::internal::ns<::NSProgress>(this) resumingHandler]);
            if (!blk)
            {
                return {};
            }
            return [blk]() -> void
            {
                blk();
            };
        }();
    }

    void Progress::set_resuming_handler(std::function<void()> value) const
    {
        [cocoon::internal::ns<::NSProgress>(this) setResumingHandler:(value ? (void (^)(void)) ^ void() { value(); } : (void (^)(void))nil)];
    }

    Number Progress::throughput() const
    {
        return cocoon::internal::wrap<Number>([cocoon::internal::ns<::NSProgress>(this) throughput]);
    }

    void Progress::set_throughput(const Number& value) const
    {
        [cocoon::internal::ns<::NSProgress>(this) setThroughput:cocoon::internal::native<::NSNumber>(value)];
    }

    std::int64_t Progress::total_unit_count() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSProgress>(this) totalUnitCount]);
    }

    void Progress::set_total_unit_count(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSProgress>(this) setTotalUnitCount:static_cast<::int64_t>(value)];
    }

    std::map<std::string, Object> Progress::user_info() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSProgress>(this) userInfo], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }
}
