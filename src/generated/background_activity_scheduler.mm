#include "generated/background_activity_scheduler.h"
#include "internal.h"

namespace cocoon
{
    BackgroundActivityScheduler::BackgroundActivityScheduler(const std::string& identifier) : BackgroundActivityScheduler(Adopt{cocoon::internal::retain([[::NSBackgroundActivityScheduler alloc] initWithIdentifier:cocoon::internal::to(identifier)])})
    {
    }

    BackgroundActivityScheduler::BackgroundActivityScheduler() : BackgroundActivityScheduler(Adopt{cocoon::internal::retain([[::NSBackgroundActivityScheduler alloc] init])})
    {
    }

    BackgroundActivityScheduler::BackgroundActivityScheduler(std::nullptr_t) : Object(nullptr)
    {
    }

    BackgroundActivityScheduler::BackgroundActivityScheduler(Adopt adopt) : Object(adopt)
    {
    }

    void BackgroundActivityScheduler::invalidate() const
    {
        [cocoon::internal::ns<::NSBackgroundActivityScheduler>(this) invalidate];
    }

    void BackgroundActivityScheduler::schedule_with_block(std::function<void(std::function<void(BackgroundActivityResult)>)> block) const
    {
        [cocoon::internal::ns<::NSBackgroundActivityScheduler>(this) scheduleWithBlock:(block ? (void (^)(::NSBackgroundActivityCompletionHandler)) ^ void(id a127_0) { block([&]() -> std::function<void(BackgroundActivityResult)>
                                                                                                                                                                {
                                                                                                                                                                    auto blk = (::NSBackgroundActivityCompletionHandler)(a127_0);
                                                                                                                                                                    if (!blk)
                                                                                                                                                                    {
                                                                                                                                                                        return {};
                                                                                                                                                                    }
                                                                                                                                                                    return [blk](BackgroundActivityResult a128_0) -> void
                                                                                                                                                                    {
                                                                                                                                                                        blk(static_cast<::NSBackgroundActivityResult>(a128_0));
                                                                                                                                                                    };
                                                                                                                                                                }()); } : (void (^)(::NSBackgroundActivityCompletionHandler))nil)];
    }

    std::string BackgroundActivityScheduler::identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSBackgroundActivityScheduler>(this) identifier]);
    }

    double BackgroundActivityScheduler::interval() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSBackgroundActivityScheduler>(this) interval]);
    }

    void BackgroundActivityScheduler::set_interval(double value) const
    {
        [cocoon::internal::ns<::NSBackgroundActivityScheduler>(this) setInterval:static_cast<::NSTimeInterval>(value)];
    }

    QualityOfService BackgroundActivityScheduler::quality_of_service() const
    {
        return static_cast<QualityOfService>([cocoon::internal::ns<::NSBackgroundActivityScheduler>(this) qualityOfService]);
    }

    void BackgroundActivityScheduler::set_quality_of_service(QualityOfService value) const
    {
        [cocoon::internal::ns<::NSBackgroundActivityScheduler>(this) setQualityOfService:static_cast<::NSQualityOfService>(value)];
    }

    bool BackgroundActivityScheduler::repeats() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBackgroundActivityScheduler>(this) repeats]);
    }

    void BackgroundActivityScheduler::set_repeats(bool value) const
    {
        [cocoon::internal::ns<::NSBackgroundActivityScheduler>(this) setRepeats:static_cast<::BOOL>(value)];
    }

    bool BackgroundActivityScheduler::should_defer() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBackgroundActivityScheduler>(this) shouldDefer]);
    }

    double BackgroundActivityScheduler::tolerance() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSBackgroundActivityScheduler>(this) tolerance]);
    }

    void BackgroundActivityScheduler::set_tolerance(double value) const
    {
        [cocoon::internal::ns<::NSBackgroundActivityScheduler>(this) setTolerance:static_cast<::NSTimeInterval>(value)];
    }
}
