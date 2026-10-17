#include "generated/text_insertion_indicator.h"
#include "internal.h"

namespace cocoon
{
    TextInsertionIndicator::TextInsertionIndicator() : TextInsertionIndicator(Adopt{cocoon::internal::retain([[::NSTextInsertionIndicator alloc] init])})
    {
    }

    TextInsertionIndicator::TextInsertionIndicator(std::nullptr_t) : View(nullptr)
    {
    }

    TextInsertionIndicator::TextInsertionIndicator(Adopt adopt) : View(adopt)
    {
    }

    TextInsertionIndicatorAutomaticModeOptions TextInsertionIndicator::automatic_mode_options() const
    {
        return static_cast<TextInsertionIndicatorAutomaticModeOptions>([cocoon::internal::ns<::NSTextInsertionIndicator>(this) automaticModeOptions]);
    }

    void TextInsertionIndicator::set_automatic_mode_options(TextInsertionIndicatorAutomaticModeOptions value) const
    {
        [cocoon::internal::ns<::NSTextInsertionIndicator>(this) setAutomaticModeOptions:static_cast<::NSTextInsertionIndicatorAutomaticModeOptions>(value)];
    }

    Color TextInsertionIndicator::color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSTextInsertionIndicator>(this) color]);
    }

    void TextInsertionIndicator::set_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSTextInsertionIndicator>(this) setColor:cocoon::internal::native<::NSColor>(value)];
    }

    TextInsertionIndicatorDisplayMode TextInsertionIndicator::display_mode() const
    {
        return static_cast<TextInsertionIndicatorDisplayMode>([cocoon::internal::ns<::NSTextInsertionIndicator>(this) displayMode]);
    }

    void TextInsertionIndicator::set_display_mode(TextInsertionIndicatorDisplayMode value) const
    {
        [cocoon::internal::ns<::NSTextInsertionIndicator>(this) setDisplayMode:static_cast<::NSTextInsertionIndicatorDisplayMode>(value)];
    }

    std::function<void(View)> TextInsertionIndicator::effects_view_inserter() const
    {
        return [&]() -> std::function<void(View)>
        {
            auto blk = (void (^)(::NSView*))([cocoon::internal::ns<::NSTextInsertionIndicator>(this) effectsViewInserter]);
            if (!blk)
            {
                return {};
            }
            return [blk](View a96_0) -> void
            {
                blk(cocoon::internal::native<::NSView>(a96_0));
            };
        }();
    }

    void TextInsertionIndicator::set_effects_view_inserter(std::function<void(View)> value) const
    {
        [cocoon::internal::ns<::NSTextInsertionIndicator>(this) setEffectsViewInserter:(value ? (void (^)(::NSView*)) ^ void(::NSView * a97_0) { value(cocoon::internal::wrap<View>(a97_0)); } : (void (^)(::NSView*))nil)];
    }
}
