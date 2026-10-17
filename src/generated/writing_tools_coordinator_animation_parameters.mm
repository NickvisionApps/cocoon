#include "generated/writing_tools_coordinator_animation_parameters.h"
#include "internal.h"

namespace cocoon
{
    WritingToolsCoordinatorAnimationParameters::WritingToolsCoordinatorAnimationParameters() : Object(nullptr)
    {
    }

    WritingToolsCoordinatorAnimationParameters::WritingToolsCoordinatorAnimationParameters(std::nullptr_t) : Object(nullptr)
    {
    }

    WritingToolsCoordinatorAnimationParameters::WritingToolsCoordinatorAnimationParameters(Adopt adopt) : Object(adopt)
    {
    }

    std::function<void()> WritingToolsCoordinatorAnimationParameters::completion_handler() const
    {
        return [&]() -> std::function<void()>
        {
            auto blk = (void (^)(void))([cocoon::internal::ns<::NSWritingToolsCoordinatorAnimationParameters>(this) completionHandler]);
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

    void WritingToolsCoordinatorAnimationParameters::set_completion_handler(std::function<void()> value) const
    {
        [cocoon::internal::ns<::NSWritingToolsCoordinatorAnimationParameters>(this) setCompletionHandler:(value ? (void (^)(void)) ^ void() { value(); } : (void (^)(void))nil)];
    }

    double WritingToolsCoordinatorAnimationParameters::delay() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSWritingToolsCoordinatorAnimationParameters>(this) delay]);
    }

    double WritingToolsCoordinatorAnimationParameters::duration() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSWritingToolsCoordinatorAnimationParameters>(this) duration]);
    }

    std::function<void(float)> WritingToolsCoordinatorAnimationParameters::progress_handler() const
    {
        return [&]() -> std::function<void(float)>
        {
            auto blk = (void (^)(float))([cocoon::internal::ns<::NSWritingToolsCoordinatorAnimationParameters>(this) progressHandler]);
            if (!blk)
            {
                return {};
            }
            return [blk](float a123_0) -> void
            {
                blk(static_cast<float>(a123_0));
            };
        }();
    }

    void WritingToolsCoordinatorAnimationParameters::set_progress_handler(std::function<void(float)> value) const
    {
        [cocoon::internal::ns<::NSWritingToolsCoordinatorAnimationParameters>(this) setProgressHandler:(value ? (void (^)(float)) ^ void(float a124_0) { value(static_cast<float>(a124_0)); } : (void (^)(float))nil)];
    }
}
