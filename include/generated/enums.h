#pragma once

#include <cstdint>

namespace cocoon
{
    /** @brief Wraps the Objective-C option set `CAAutoresizingMask`. Combine option sets with `|` and test them with `test_flag`. */
    enum class CAAutoresizingMask : std::uint32_t
    {
        NotSizable = 0,
        MinXMargin = 1,
        WidthSizable = 2,
        MaxXMargin = 4,
        MinYMargin = 8,
        HeightSizable = 16,
        MaxYMargin = 32,
    };

    constexpr CAAutoresizingMask operator|(CAAutoresizingMask a, CAAutoresizingMask b)
    {
        return static_cast<CAAutoresizingMask>(static_cast<std::uint32_t>(a) | static_cast<std::uint32_t>(b));
    }
    constexpr CAAutoresizingMask operator&(CAAutoresizingMask a, CAAutoresizingMask b)
    {
        return static_cast<CAAutoresizingMask>(static_cast<std::uint32_t>(a) & static_cast<std::uint32_t>(b));
    }
    constexpr bool test_flag(CAAutoresizingMask value, CAAutoresizingMask flag)
    {
        return (static_cast<std::uint32_t>(value) & static_cast<std::uint32_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `CACornerMask`. Combine option sets with `|` and test them with `test_flag`. */
    enum class CACornerMask : std::uint64_t
    {
        MinXMinYCorner = 1,
        MaxXMinYCorner = 2,
        MinXMaxYCorner = 4,
        MaxXMaxYCorner = 8,
    };

    constexpr CACornerMask operator|(CACornerMask a, CACornerMask b)
    {
        return static_cast<CACornerMask>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr CACornerMask operator&(CACornerMask a, CACornerMask b)
    {
        return static_cast<CACornerMask>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(CACornerMask value, CACornerMask flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `CAEdgeAntialiasingMask`. Combine option sets with `|` and test them with `test_flag`. */
    enum class CAEdgeAntialiasingMask : std::uint32_t
    {
        LeftEdge = 1,
        RightEdge = 2,
        BottomEdge = 4,
        TopEdge = 8,
    };

    constexpr CAEdgeAntialiasingMask operator|(CAEdgeAntialiasingMask a, CAEdgeAntialiasingMask b)
    {
        return static_cast<CAEdgeAntialiasingMask>(static_cast<std::uint32_t>(a) | static_cast<std::uint32_t>(b));
    }
    constexpr CAEdgeAntialiasingMask operator&(CAEdgeAntialiasingMask a, CAEdgeAntialiasingMask b)
    {
        return static_cast<CAEdgeAntialiasingMask>(static_cast<std::uint32_t>(a) & static_cast<std::uint32_t>(b));
    }
    constexpr bool test_flag(CAEdgeAntialiasingMask value, CAEdgeAntialiasingMask flag)
    {
        return (static_cast<std::uint32_t>(value) & static_cast<std::uint32_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `CGImagePropertyOrientation`. */
    enum class CGImagePropertyOrientation : std::uint32_t
    {
        Up = 1,
        UpMirrored = 2,
        Down = 3,
        DownMirrored = 4,
        LeftMirrored = 5,
        Right = 6,
        RightMirrored = 7,
        Left = 8,
    };

    /** @brief Wraps the Objective-C enumeration `CGRectEdge`. */
    enum class CGRectEdge : std::uint32_t
    {
        MinXEdge = 0,
        MinYEdge = 1,
        MaxXEdge = 2,
        MaxYEdge = 3,
    };

    /** @brief Wraps the Objective-C option set `NSActivityOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class ActivityOptions : std::uint64_t
    {
        IdleDisplaySleepDisabled = 1099511627776,
        IdleSystemSleepDisabled = 1048576,
        SuddenTerminationDisabled = 16384,
        AutomaticTerminationDisabled = 32768,
        AnimationTrackingEnabled = 35184372088832,
        TrackingEnabled = 70368744177664,
        UserInitiated = 16777215,
        UserInitiatedAllowingIdleSystemSleep = 15728639,
        Background = 255,
        LatencyCritical = 1095216660480,
        UserInteractive = 1095233437695,
    };

    constexpr ActivityOptions operator|(ActivityOptions a, ActivityOptions b)
    {
        return static_cast<ActivityOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr ActivityOptions operator&(ActivityOptions a, ActivityOptions b)
    {
        return static_cast<ActivityOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(ActivityOptions value, ActivityOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSAlertStyle`. */
    enum class AlertStyle : std::uint64_t
    {
        Warning = 0,
        Informational = 1,
        Critical = 2,
    };

    /** @brief Wraps the Objective-C option set `NSAlignmentOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class AlignmentOptions : std::uint64_t
    {
        MinXInward = 1,
        MinYInward = 2,
        MaxXInward = 4,
        MaxYInward = 8,
        WidthInward = 16,
        HeightInward = 32,
        MinXOutward = 256,
        MinYOutward = 512,
        MaxXOutward = 1024,
        MaxYOutward = 2048,
        WidthOutward = 4096,
        HeightOutward = 8192,
        MinXNearest = 65536,
        MinYNearest = 131072,
        MaxXNearest = 262144,
        MaxYNearest = 524288,
        WidthNearest = 1048576,
        HeightNearest = 2097152,
        RectFlipped = 9223372036854775808ULL,
        AllEdgesInward = 15,
        AllEdgesOutward = 3840,
        AllEdgesNearest = 983040,
    };

    constexpr AlignmentOptions operator|(AlignmentOptions a, AlignmentOptions b)
    {
        return static_cast<AlignmentOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr AlignmentOptions operator&(AlignmentOptions a, AlignmentOptions b)
    {
        return static_cast<AlignmentOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(AlignmentOptions value, AlignmentOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSAnimationBlockingMode`. */
    enum class AnimationBlockingMode : std::uint64_t
    {
        Blocking = 0,
        Nonblocking = 1,
        NonblockingThreaded = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSAnimationCurve`. */
    enum class AnimationCurve : std::uint64_t
    {
        EaseInOut = 0,
        EaseIn = 1,
        EaseOut = 2,
        Linear = 3,
    };

    /** @brief Wraps the Objective-C option set `NSAppleEventSendOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class AppleEventSendOptions : std::uint64_t
    {
        NoReply = 1,
        QueueReply = 2,
        WaitForReply = 3,
        NeverInteract = 16,
        CanInteract = 32,
        AlwaysInteract = 48,
        CanSwitchLayer = 64,
        DontRecord = 4096,
        DontExecute = 8192,
        DontAnnotate = 65536,
        DefaultOptions = 35,
    };

    constexpr AppleEventSendOptions operator|(AppleEventSendOptions a, AppleEventSendOptions b)
    {
        return static_cast<AppleEventSendOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr AppleEventSendOptions operator&(AppleEventSendOptions a, AppleEventSendOptions b)
    {
        return static_cast<AppleEventSendOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(AppleEventSendOptions value, AppleEventSendOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSApplicationActivationOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class ApplicationActivationOptions : std::uint64_t
    {
        AllWindows = 1,
        IgnoringOtherApps = 2,
    };

    constexpr ApplicationActivationOptions operator|(ApplicationActivationOptions a, ApplicationActivationOptions b)
    {
        return static_cast<ApplicationActivationOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr ApplicationActivationOptions operator&(ApplicationActivationOptions a, ApplicationActivationOptions b)
    {
        return static_cast<ApplicationActivationOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(ApplicationActivationOptions value, ApplicationActivationOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSApplicationActivationPolicy`. */
    enum class ActivationPolicy : std::int64_t
    {
        Regular = 0,
        Accessory = 1,
        Prohibited = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSApplicationDelegateReply`. */
    enum class ApplicationDelegateReply : std::uint64_t
    {
        Success = 0,
        Cancel = 1,
        Failure = 2,
    };

    /** @brief Wraps the Objective-C option set `NSApplicationOcclusionState`. Combine option sets with `|` and test them with `test_flag`. */
    enum class ApplicationOcclusionState : std::uint64_t
    {
        Visible = 2,
    };

    constexpr ApplicationOcclusionState operator|(ApplicationOcclusionState a, ApplicationOcclusionState b)
    {
        return static_cast<ApplicationOcclusionState>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr ApplicationOcclusionState operator&(ApplicationOcclusionState a, ApplicationOcclusionState b)
    {
        return static_cast<ApplicationOcclusionState>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(ApplicationOcclusionState value, ApplicationOcclusionState flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSApplicationPresentationOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class ApplicationPresentationOptions : std::uint64_t
    {
        Default = 0,
        AutoHideDock = 1,
        HideDock = 2,
        AutoHideMenuBar = 4,
        HideMenuBar = 8,
        DisableAppleMenu = 16,
        DisableProcessSwitching = 32,
        DisableForceQuit = 64,
        DisableSessionTermination = 128,
        DisableHideApplication = 256,
        DisableMenuBarTransparency = 512,
        FullScreen = 1024,
        AutoHideToolbar = 2048,
        DisableCursorLocationAssistance = 4096,
        DisableScreenCornerInteractions = 32768,
    };

    constexpr ApplicationPresentationOptions operator|(ApplicationPresentationOptions a, ApplicationPresentationOptions b)
    {
        return static_cast<ApplicationPresentationOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr ApplicationPresentationOptions operator&(ApplicationPresentationOptions a, ApplicationPresentationOptions b)
    {
        return static_cast<ApplicationPresentationOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(ApplicationPresentationOptions value, ApplicationPresentationOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSApplicationPrintReply`. */
    enum class ApplicationPrintReply : std::uint64_t
    {
        Cancelled = 0,
        Success = 1,
        ReplyLater = 2,
        Failure = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSApplicationTerminateReply`. */
    enum class ApplicationTerminateReply : std::uint64_t
    {
        Cancel = 0,
        Now = 1,
        Later = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSAttributeType`. */
    enum class AttributeType : std::uint64_t
    {
        UndefinedAttributeType = 0,
        Integer16AttributeType = 100,
        Integer32AttributeType = 200,
        Integer64AttributeType = 300,
        DecimalAttributeType = 400,
        DoubleAttributeType = 500,
        FloatAttributeType = 600,
        StringAttributeType = 700,
        BooleanAttributeType = 800,
        DateAttributeType = 900,
        BinaryDataAttributeType = 1000,
        UUIDAttributeType = 1100,
        URIAttributeType = 1200,
        TransformableAttributeType = 1800,
        ObjectIDAttributeType = 2000,
        CompositeAttributeType = 2100,
    };

    /** @brief Wraps the Objective-C option set `NSAttributedStringEnumerationOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class AttributedStringEnumerationOptions : std::uint64_t
    {
        Reverse = 2,
        LongestEffectiveRangeNotRequired = 1048576,
    };

    constexpr AttributedStringEnumerationOptions operator|(AttributedStringEnumerationOptions a, AttributedStringEnumerationOptions b)
    {
        return static_cast<AttributedStringEnumerationOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr AttributedStringEnumerationOptions operator&(AttributedStringEnumerationOptions a, AttributedStringEnumerationOptions b)
    {
        return static_cast<AttributedStringEnumerationOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(AttributedStringEnumerationOptions value, AttributedStringEnumerationOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSAttributedStringFormattingOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class AttributedStringFormattingOptions : std::uint64_t
    {
        InsertArgumentAttributesWithoutMerging = 1,
        ApplyReplacementIndexAttribute = 2,
    };

    constexpr AttributedStringFormattingOptions operator|(AttributedStringFormattingOptions a, AttributedStringFormattingOptions b)
    {
        return static_cast<AttributedStringFormattingOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr AttributedStringFormattingOptions operator&(AttributedStringFormattingOptions a, AttributedStringFormattingOptions b)
    {
        return static_cast<AttributedStringFormattingOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(AttributedStringFormattingOptions value, AttributedStringFormattingOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSAttributedStringMarkdownInterpretedSyntax`. */
    enum class AttributedStringMarkdownInterpretedSyntax : std::int64_t
    {
        Full = 0,
        InlineOnly = 1,
        InlineOnlyPreservingWhitespace = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSAttributedStringMarkdownParsingFailurePolicy`. */
    enum class AttributedStringMarkdownParsingFailurePolicy : std::int64_t
    {
        Error = 0,
        PartiallyParsedIfPossible = 1,
    };

    /** @brief Wraps the Objective-C option set `NSAutoresizingMaskOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class AutoresizingMaskOptions : std::uint64_t
    {
        NotSizable = 0,
        MinXMargin = 1,
        WidthSizable = 2,
        MaxXMargin = 4,
        MinYMargin = 8,
        HeightSizable = 16,
        MaxYMargin = 32,
    };

    constexpr AutoresizingMaskOptions operator|(AutoresizingMaskOptions a, AutoresizingMaskOptions b)
    {
        return static_cast<AutoresizingMaskOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr AutoresizingMaskOptions operator&(AutoresizingMaskOptions a, AutoresizingMaskOptions b)
    {
        return static_cast<AutoresizingMaskOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(AutoresizingMaskOptions value, AutoresizingMaskOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSBackgroundActivityResult`. */
    enum class BackgroundActivityResult : std::int64_t
    {
        Finished = 1,
        Deferred = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSBackgroundStyle`. */
    enum class BackgroundStyle : std::int64_t
    {
        Normal = 0,
        Emphasized = 1,
        Raised = 2,
        Lowered = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSBackingStoreType`. */
    enum class BackingStoreType : std::uint64_t
    {
        Retained = 0,
        Nonretained = 1,
        Buffered = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSBezelStyle`. */
    enum class BezelStyle : std::uint64_t
    {
        Automatic = 0,
        Push = 1,
        FlexiblePush = 2,
        Disclosure = 5,
        Circular = 7,
        HelpButton = 9,
        SmallSquare = 10,
        Toolbar = 11,
        AccessoryBarAction = 12,
        AccessoryBar = 13,
        PushDisclosure = 14,
        Badge = 15,
        Glass = 16,
        ShadowlessSquare = 6,
        TexturedSquare = 8,
        Rounded = 1,
        RegularSquare = 2,
        TexturedRounded = 11,
        RoundRect = 12,
        Recessed = 13,
        RoundedDisclosure = 14,
        Inline = 15,
    };

    /** @brief Wraps the Objective-C enumeration `NSBezierPathElement`. */
    enum class BezierPathElement : std::uint64_t
    {
        MoveTo = 0,
        LineTo = 1,
        CubicCurveTo = 2,
        ClosePath = 3,
        QuadraticCurveTo = 4,
        CurveTo = 2,
    };

    /** @brief Wraps the Objective-C option set `NSBitmapFormat`. Combine option sets with `|` and test them with `test_flag`. */
    enum class BitmapFormat : std::uint64_t
    {
        AlphaFirst = 1,
        AlphaNonpremultiplied = 2,
        FloatingPointSamples = 4,
        SixteenBitLittleEndian = 256,
        ThirtyTwoBitLittleEndian = 512,
        SixteenBitBigEndian = 1024,
        ThirtyTwoBitBigEndian = 2048,
    };

    constexpr BitmapFormat operator|(BitmapFormat a, BitmapFormat b)
    {
        return static_cast<BitmapFormat>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr BitmapFormat operator&(BitmapFormat a, BitmapFormat b)
    {
        return static_cast<BitmapFormat>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(BitmapFormat value, BitmapFormat flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSBitmapImageFileType`. */
    enum class BitmapImageFileType : std::uint64_t
    {
        TIFF = 0,
        BMP = 1,
        GIF = 2,
        JPEG = 3,
        PNG = 4,
        JPEG2000 = 5,
    };

    /** @brief Wraps the Objective-C enumeration `NSBorderType`. */
    enum class BorderType : std::uint64_t
    {
        NoBorder = 0,
        LineBorder = 1,
        BezelBorder = 2,
        GrooveBorder = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSBoxType`. */
    enum class BoxType : std::uint64_t
    {
        Primary = 0,
        Separator = 2,
        Custom = 4,
    };

    /** @brief Wraps the Objective-C enumeration `NSBrowserColumnResizingType`. */
    enum class BrowserColumnResizingType : std::uint64_t
    {
        NoColumnResizing = 0,
        AutoColumnResizing = 1,
        UserColumnResizing = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSBrowserDropOperation`. */
    enum class BrowserDropOperation : std::uint64_t
    {
        On = 0,
        Above = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSButtonType`. */
    enum class ButtonType : std::uint64_t
    {
        MomentaryLight = 0,
        PushOnPushOff = 1,
        Toggle = 2,
        Switch = 3,
        Radio = 4,
        MomentaryChange = 5,
        OnOff = 6,
        MomentaryPushIn = 7,
        Accelerator = 8,
        MultiLevelAccelerator = 9,
    };

    /** @brief Wraps the Objective-C enumeration `NSByteCountFormatterCountStyle`. */
    enum class ByteCountFormatterCountStyle : std::int64_t
    {
        File = 0,
        Memory = 1,
        Decimal = 2,
        Binary = 3,
    };

    /** @brief Wraps the Objective-C option set `NSByteCountFormatterUnits`. Combine option sets with `|` and test them with `test_flag`. */
    enum class ByteCountFormatterUnits : std::uint64_t
    {
        Default = 0,
        Bytes = 1,
        KB = 2,
        MB = 4,
        GB = 8,
        TB = 16,
        PB = 32,
        EB = 64,
        ZB = 128,
        YBOrHigher = 65280,
        All = 65535,
    };

    constexpr ByteCountFormatterUnits operator|(ByteCountFormatterUnits a, ByteCountFormatterUnits b)
    {
        return static_cast<ByteCountFormatterUnits>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr ByteCountFormatterUnits operator&(ByteCountFormatterUnits a, ByteCountFormatterUnits b)
    {
        return static_cast<ByteCountFormatterUnits>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(ByteCountFormatterUnits value, ByteCountFormatterUnits flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSCalendarOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class CalendarOptions : std::uint64_t
    {
        WrapComponents = 1,
        MatchStrictly = 2,
        SearchBackwards = 4,
        MatchPreviousTimePreservingSmallerUnits = 256,
        MatchNextTimePreservingSmallerUnits = 512,
        MatchNextTime = 1024,
        MatchFirst = 4096,
        MatchLast = 8192,
    };

    constexpr CalendarOptions operator|(CalendarOptions a, CalendarOptions b)
    {
        return static_cast<CalendarOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr CalendarOptions operator&(CalendarOptions a, CalendarOptions b)
    {
        return static_cast<CalendarOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(CalendarOptions value, CalendarOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSCalendarUnit`. Combine option sets with `|` and test them with `test_flag`. */
    enum class CalendarUnit : std::uint64_t
    {
        Era = 2,
        Year = 4,
        Month = 8,
        Day = 16,
        Hour = 32,
        Minute = 64,
        Second = 128,
        Weekday = 512,
        WeekdayOrdinal = 1024,
        Quarter = 2048,
        WeekOfMonth = 4096,
        WeekOfYear = 8192,
        YearForWeekOfYear = 16384,
        Nanosecond = 32768,
        DayOfYear = 65536,
        Calendar = 1048576,
        TimeZone = 2097152,
        IsLeapMonth = 1073741824,
        IsRepeatedDay = 2147483648,
        EraCalendarUnit = 2,
        YearCalendarUnit = 4,
        MonthCalendarUnit = 8,
        DayCalendarUnit = 16,
        HourCalendarUnit = 32,
        MinuteCalendarUnit = 64,
        SecondCalendarUnit = 128,
        WeekCalendarUnit = 256,
        WeekdayCalendarUnit = 512,
        WeekdayOrdinalCalendarUnit = 1024,
        QuarterCalendarUnit = 2048,
        WeekOfMonthCalendarUnit = 4096,
        WeekOfYearCalendarUnit = 8192,
        YearForWeekOfYearCalendarUnit = 16384,
        CalendarCalendarUnit = 1048576,
        TimeZoneCalendarUnit = 2097152,
    };

    constexpr CalendarUnit operator|(CalendarUnit a, CalendarUnit b)
    {
        return static_cast<CalendarUnit>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr CalendarUnit operator&(CalendarUnit a, CalendarUnit b)
    {
        return static_cast<CalendarUnit>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(CalendarUnit value, CalendarUnit flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSCellAttribute`. */
    enum class CellAttribute : std::uint64_t
    {
        CellDisabled = 0,
        CellState = 1,
        PushInCell = 2,
        CellEditable = 3,
        ChangeGrayCell = 4,
        CellHighlighted = 5,
        CellLightsByContents = 6,
        CellLightsByGray = 7,
        ChangeBackgroundCell = 8,
        CellLightsByBackground = 9,
        CellIsBordered = 10,
        CellHasOverlappingImage = 11,
        CellHasImageHorizontal = 12,
        CellHasImageOnLeftOrBottom = 13,
        CellChangesContents = 14,
        CellIsInsetButton = 15,
        CellAllowsMixedState = 16,
    };

    /** @brief Wraps the Objective-C option set `NSCellHitResult`. Combine option sets with `|` and test them with `test_flag`. */
    enum class CellHitResult : std::uint64_t
    {
        None = 0,
        ContentArea = 1,
        EditableTextArea = 2,
        TrackableArea = 4,
    };

    constexpr CellHitResult operator|(CellHitResult a, CellHitResult b)
    {
        return static_cast<CellHitResult>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr CellHitResult operator&(CellHitResult a, CellHitResult b)
    {
        return static_cast<CellHitResult>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(CellHitResult value, CellHitResult flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSCellImagePosition`. */
    enum class CellImagePosition : std::uint64_t
    {
        NoImage = 0,
        ImageOnly = 1,
        ImageLeft = 2,
        ImageRight = 3,
        ImageBelow = 4,
        ImageAbove = 5,
        ImageOverlaps = 6,
        ImageLeading = 7,
        ImageTrailing = 8,
    };

    /** @brief Wraps the Objective-C option set `NSCellStyleMask`. Combine option sets with `|` and test them with `test_flag`. */
    enum class CellStyleMask : std::uint64_t
    {
        NoCellMask = 0,
        ContentsCellMask = 1,
        PushInCellMask = 2,
        ChangeGrayCellMask = 4,
        ChangeBackgroundCellMask = 8,
    };

    constexpr CellStyleMask operator|(CellStyleMask a, CellStyleMask b)
    {
        return static_cast<CellStyleMask>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr CellStyleMask operator&(CellStyleMask a, CellStyleMask b)
    {
        return static_cast<CellStyleMask>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(CellStyleMask value, CellStyleMask flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSCellType`. */
    enum class CellType : std::uint64_t
    {
        NullCellType = 0,
        TextCellType = 1,
        ImageCellType = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSCharacterCollection`. */
    enum class CharacterCollection : std::uint64_t
    {
        IdentityMappingCharacterCollection = 0,
        AdobeCNS1CharacterCollection = 1,
        AdobeGB1CharacterCollection = 2,
        AdobeJapan1CharacterCollection = 3,
        AdobeJapan2CharacterCollection = 4,
        AdobeKorea1CharacterCollection = 5,
    };

    /** @brief Wraps the Objective-C enumeration `NSCollectionChangeType`. */
    enum class CollectionChangeType : std::int64_t
    {
        Insert = 0,
        Remove = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSCollectionElementCategory`. */
    enum class CollectionElementCategory : std::int64_t
    {
        Item = 0,
        SupplementaryView = 1,
        DecorationView = 2,
        InterItemGap = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSCollectionLayoutSectionOrthogonalScrollingBehavior`. */
    enum class CollectionLayoutSectionOrthogonalScrollingBehavior : std::int64_t
    {
        None = 0,
        Continuous = 1,
        ContinuousGroupLeadingBoundary = 2,
        Paging = 3,
        GroupPaging = 4,
        GroupPagingCentered = 5,
    };

    /** @brief Wraps the Objective-C enumeration `NSCollectionUpdateAction`. */
    enum class CollectionUpdateAction : std::int64_t
    {
        Insert = 0,
        Delete = 1,
        Reload = 2,
        Move = 3,
        None = 4,
    };

    /** @brief Wraps the Objective-C enumeration `NSCollectionViewDropOperation`. */
    enum class CollectionViewDropOperation : std::int64_t
    {
        On = 0,
        Before = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSCollectionViewItemHighlightState`. */
    enum class CollectionViewItemHighlightState : std::int64_t
    {
        None = 0,
        ForSelection = 1,
        ForDeselection = 2,
        AsDropTarget = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSCollectionViewScrollDirection`. */
    enum class CollectionViewScrollDirection : std::int64_t
    {
        Vertical = 0,
        Horizontal = 1,
    };

    /** @brief Wraps the Objective-C option set `NSCollectionViewScrollPosition`. Combine option sets with `|` and test them with `test_flag`. */
    enum class CollectionViewScrollPosition : std::uint64_t
    {
        None = 0,
        Top = 1,
        CenteredVertically = 2,
        Bottom = 4,
        NearestHorizontalEdge = 512,
        Left = 8,
        CenteredHorizontally = 16,
        Right = 32,
        LeadingEdge = 64,
        TrailingEdge = 128,
        NearestVerticalEdge = 256,
    };

    constexpr CollectionViewScrollPosition operator|(CollectionViewScrollPosition a, CollectionViewScrollPosition b)
    {
        return static_cast<CollectionViewScrollPosition>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr CollectionViewScrollPosition operator&(CollectionViewScrollPosition a, CollectionViewScrollPosition b)
    {
        return static_cast<CollectionViewScrollPosition>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(CollectionViewScrollPosition value, CollectionViewScrollPosition flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSColorPanelMode`. */
    enum class ColorPanelMode : std::int64_t
    {
        None = -1,
        Gray = 0,
        RGB = 1,
        CMYK = 2,
        HSB = 3,
        CustomPalette = 4,
        ColorList = 5,
        Wheel = 6,
        Crayon = 7,
    };

    /** @brief Wraps the Objective-C option set `NSColorPanelOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class ColorPanelOptions : std::uint64_t
    {
        GrayModeMask = 1,
        RGBModeMask = 2,
        CMYKModeMask = 4,
        HSBModeMask = 8,
        CustomPaletteModeMask = 16,
        ColorListModeMask = 32,
        WheelModeMask = 64,
        CrayonModeMask = 128,
        AllModesMask = 65535,
    };

    constexpr ColorPanelOptions operator|(ColorPanelOptions a, ColorPanelOptions b)
    {
        return static_cast<ColorPanelOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr ColorPanelOptions operator&(ColorPanelOptions a, ColorPanelOptions b)
    {
        return static_cast<ColorPanelOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(ColorPanelOptions value, ColorPanelOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSColorRenderingIntent`. */
    enum class ColorRenderingIntent : std::int64_t
    {
        Default = 0,
        AbsoluteColorimetric = 1,
        RelativeColorimetric = 2,
        Perceptual = 3,
        Saturation = 4,
    };

    /** @brief Wraps the Objective-C enumeration `NSColorSpaceModel`. */
    enum class ColorSpaceModel : std::int64_t
    {
        Unknown = -1,
        Gray = 0,
        RGB = 1,
        CMYK = 2,
        LAB = 3,
        DeviceN = 4,
        Indexed = 5,
        Patterned = 6,
    };

    /** @brief Wraps the Objective-C enumeration `NSColorSystemEffect`. */
    enum class ColorSystemEffect : std::int64_t
    {
        None = 0,
        Pressed = 1,
        DeepPressed = 2,
        Disabled = 3,
        Rollover = 4,
    };

    /** @brief Wraps the Objective-C enumeration `NSColorType`. */
    enum class ColorType : std::int64_t
    {
        ComponentBased = 0,
        Pattern = 1,
        Catalog = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSColorWellStyle`. */
    enum class ColorWellStyle : std::int64_t
    {
        Default = 0,
        Minimal = 1,
        Expanded = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSComboButtonStyle`. */
    enum class ComboButtonStyle : std::int64_t
    {
        Split = 0,
        Unified = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSComparisonPredicateModifier`. */
    enum class ComparisonPredicateModifier : std::uint64_t
    {
        DirectPredicateModifier = 0,
        AllPredicateModifier = 1,
        AnyPredicateModifier = 2,
    };

    /** @brief Wraps the Objective-C option set `NSComparisonPredicateOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class ComparisonPredicateOptions : std::uint64_t
    {
        CaseInsensitivePredicateOption = 1,
        DiacriticInsensitivePredicateOption = 2,
        NormalizedPredicateOption = 4,
    };

    constexpr ComparisonPredicateOptions operator|(ComparisonPredicateOptions a, ComparisonPredicateOptions b)
    {
        return static_cast<ComparisonPredicateOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr ComparisonPredicateOptions operator&(ComparisonPredicateOptions a, ComparisonPredicateOptions b)
    {
        return static_cast<ComparisonPredicateOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(ComparisonPredicateOptions value, ComparisonPredicateOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSComparisonResult`. */
    enum class ComparisonResult : std::int64_t
    {
        Ascending = -1,
        Same = 0,
        Descending = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSCompositingOperation`. */
    enum class CompositingOperation : std::uint64_t
    {
        Clear = 0,
        Copy = 1,
        SourceOver = 2,
        SourceIn = 3,
        SourceOut = 4,
        SourceAtop = 5,
        DestinationOver = 6,
        DestinationIn = 7,
        DestinationOut = 8,
        DestinationAtop = 9,
        XOR = 10,
        PlusDarker = 11,
        Highlight = 12,
        PlusLighter = 13,
        Multiply = 14,
        Screen = 15,
        Overlay = 16,
        Darken = 17,
        Lighten = 18,
        ColorDodge = 19,
        ColorBurn = 20,
        SoftLight = 21,
        HardLight = 22,
        Difference = 23,
        Exclusion = 24,
        Hue = 25,
        Saturation = 26,
        Color = 27,
        Luminosity = 28,
    };

    /** @brief Wraps the Objective-C enumeration `NSCompoundPredicateType`. */
    enum class CompoundPredicateType : std::uint64_t
    {
        NotPredicateType = 0,
        AndPredicateType = 1,
        OrPredicateType = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSControlBorderShape`. */
    enum class ControlBorderShape : std::int64_t
    {
        Automatic = 0,
        Capsule = 1,
        RoundedRectangle = 2,
        Circle = 3,
    };

    /** @brief Wraps the Objective-C option set `NSControlCharacterAction`. Combine option sets with `|` and test them with `test_flag`. */
    enum class ControlCharacterAction : std::int64_t
    {
        ZeroAdvancement = 1,
        Whitespace = 2,
        HorizontalTab = 4,
        LineBreak = 8,
        ParagraphBreak = 16,
        ContainerBreak = 32,
    };

    constexpr ControlCharacterAction operator|(ControlCharacterAction a, ControlCharacterAction b)
    {
        return static_cast<ControlCharacterAction>(static_cast<std::int64_t>(a) | static_cast<std::int64_t>(b));
    }
    constexpr ControlCharacterAction operator&(ControlCharacterAction a, ControlCharacterAction b)
    {
        return static_cast<ControlCharacterAction>(static_cast<std::int64_t>(a) & static_cast<std::int64_t>(b));
    }
    constexpr bool test_flag(ControlCharacterAction value, ControlCharacterAction flag)
    {
        return (static_cast<std::int64_t>(value) & static_cast<std::int64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSControlEvents`. Combine option sets with `|` and test them with `test_flag`. */
    enum class ControlEvents : std::uint64_t
    {
        TrackingBegan = 1,
        TrackingRepeated = 2,
        TrackingInside = 4,
        TrackingOutside = 8,
        TrackingEntered = 16,
        TrackingExited = 32,
        TrackingEndedInside = 64,
        TrackingEndedOutside = 128,
        TrackingCancelled = 256,
        ValueChanged = 4096,
        PrimaryActionTriggered = 8192,
        MenuActionTriggered = 16384,
        AllTrackingEvents = 4095,
        ApplicationReserved = 251658240,
        SystemReserved = 4026531840,
        AllEvents = 4294967295,
    };

    constexpr ControlEvents operator|(ControlEvents a, ControlEvents b)
    {
        return static_cast<ControlEvents>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr ControlEvents operator&(ControlEvents a, ControlEvents b)
    {
        return static_cast<ControlEvents>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(ControlEvents value, ControlEvents flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSControlSize`. */
    enum class ControlSize : std::uint64_t
    {
        Regular = 0,
        Small = 1,
        Mini = 2,
        Large = 3,
        ExtraLarge = 4,
    };

    /** @brief Wraps the Objective-C enumeration `NSControlStateValue`. */
    enum class ControlState : std::int64_t
    {
        Mixed = -1,
        Off = 0,
        On = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSControlTint`. */
    enum class ControlTint : std::uint64_t
    {
        DefaultControlTint = 0,
        BlueControlTint = 1,
        GraphiteControlTint = 6,
        ClearControlTint = 7,
    };

    /** @brief Wraps the Objective-C enumeration `NSCorrectionIndicatorType`. */
    enum class CorrectionIndicatorType : std::int64_t
    {
        Default = 0,
        Reversion = 1,
        Guesses = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSCorrectionResponse`. */
    enum class CorrectionResponse : std::int64_t
    {
        None = 0,
        Accepted = 1,
        Rejected = 2,
        Ignored = 3,
        Edited = 4,
        Reverted = 5,
    };

    /** @brief Wraps the Objective-C option set `NSCursorFrameResizeDirections`. Combine option sets with `|` and test them with `test_flag`. */
    enum class CursorFrameResizeDirections : std::uint64_t
    {
        Inward = 1,
        Outward = 2,
        All = 3,
    };

    constexpr CursorFrameResizeDirections operator|(CursorFrameResizeDirections a, CursorFrameResizeDirections b)
    {
        return static_cast<CursorFrameResizeDirections>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr CursorFrameResizeDirections operator&(CursorFrameResizeDirections a, CursorFrameResizeDirections b)
    {
        return static_cast<CursorFrameResizeDirections>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(CursorFrameResizeDirections value, CursorFrameResizeDirections flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSCursorFrameResizePosition`. */
    enum class CursorFrameResizePosition : std::uint64_t
    {
        Top = 1,
        Left = 2,
        Bottom = 4,
        Right = 8,
        TopLeft = 3,
        TopRight = 9,
        BottomLeft = 6,
        BottomRight = 12,
    };

    /** @brief Wraps the Objective-C enumeration `NSDateComponentsFormatterUnitsStyle`. */
    enum class DateComponentsFormatterUnitsStyle : std::int64_t
    {
        Positional = 0,
        Abbreviated = 1,
        Short = 2,
        Full = 3,
        SpellOut = 4,
        Brief = 5,
    };

    /** @brief Wraps the Objective-C option set `NSDateComponentsFormatterZeroFormattingBehavior`. Combine option sets with `|` and test them with `test_flag`. */
    enum class DateComponentsFormatterZeroFormattingBehavior : std::uint64_t
    {
        None = 0,
        Default = 1,
        DropLeading = 2,
        DropMiddle = 4,
        DropTrailing = 8,
        DropAll = 14,
        Pad = 65536,
    };

    constexpr DateComponentsFormatterZeroFormattingBehavior operator|(DateComponentsFormatterZeroFormattingBehavior a, DateComponentsFormatterZeroFormattingBehavior b)
    {
        return static_cast<DateComponentsFormatterZeroFormattingBehavior>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr DateComponentsFormatterZeroFormattingBehavior operator&(DateComponentsFormatterZeroFormattingBehavior a, DateComponentsFormatterZeroFormattingBehavior b)
    {
        return static_cast<DateComponentsFormatterZeroFormattingBehavior>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(DateComponentsFormatterZeroFormattingBehavior value, DateComponentsFormatterZeroFormattingBehavior flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSDateFormatterBehavior`. */
    enum class DateFormatterBehavior : std::uint64_t
    {
        Default = 0,
        _10_0 = 1000,
        _10_4 = 1040,
    };

    /** @brief Wraps the Objective-C enumeration `NSDateFormatterStyle`. */
    enum class DateFormatterStyle : std::uint64_t
    {
        NoStyle = 0,
        ShortStyle = 1,
        MediumStyle = 2,
        LongStyle = 3,
        FullStyle = 4,
    };

    /** @brief Wraps the Objective-C enumeration `NSDateIntervalFormatterStyle`. */
    enum class DateIntervalFormatterStyle : std::uint64_t
    {
        NoStyle = 0,
        ShortStyle = 1,
        MediumStyle = 2,
        LongStyle = 3,
        FullStyle = 4,
    };

    /** @brief Wraps the Objective-C option set `NSDatePickerElementFlags`. Combine option sets with `|` and test them with `test_flag`. */
    enum class DatePickerElementFlags : std::uint64_t
    {
        HourMinute = 12,
        HourMinuteSecond = 14,
        TimeZone = 16,
        YearMonth = 192,
        YearMonthDay = 224,
        Era = 256,
    };

    constexpr DatePickerElementFlags operator|(DatePickerElementFlags a, DatePickerElementFlags b)
    {
        return static_cast<DatePickerElementFlags>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr DatePickerElementFlags operator&(DatePickerElementFlags a, DatePickerElementFlags b)
    {
        return static_cast<DatePickerElementFlags>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(DatePickerElementFlags value, DatePickerElementFlags flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSDatePickerMode`. */
    enum class DatePickerMode : std::uint64_t
    {
        Single = 0,
        Range = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSDatePickerStyle`. */
    enum class DatePickerStyle : std::uint64_t
    {
        TextFieldAndStepper = 0,
        ClockAndCalendar = 1,
        TextField = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSDecodingFailurePolicy`. */
    enum class DecodingFailurePolicy : std::int64_t
    {
        RaiseException = 0,
        SetErrorAndReturn = 1,
    };

    /** @brief Wraps the Objective-C option set `NSDirectionalRectEdge`. Combine option sets with `|` and test them with `test_flag`. */
    enum class DirectionalRectEdge : std::uint64_t
    {
        None = 0,
        Top = 1,
        Leading = 2,
        Bottom = 4,
        Trailing = 8,
        All = 15,
    };

    constexpr DirectionalRectEdge operator|(DirectionalRectEdge a, DirectionalRectEdge b)
    {
        return static_cast<DirectionalRectEdge>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr DirectionalRectEdge operator&(DirectionalRectEdge a, DirectionalRectEdge b)
    {
        return static_cast<DirectionalRectEdge>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(DirectionalRectEdge value, DirectionalRectEdge flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSDirectoryEnumerationOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class DirectoryEnumerationOptions : std::uint64_t
    {
        SkipsSubdirectoryDescendants = 1,
        SkipsPackageDescendants = 2,
        SkipsHiddenFiles = 4,
        IncludesDirectoriesPostOrder = 8,
        ProducesRelativePathURLs = 16,
    };

    constexpr DirectoryEnumerationOptions operator|(DirectoryEnumerationOptions a, DirectoryEnumerationOptions b)
    {
        return static_cast<DirectoryEnumerationOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr DirectoryEnumerationOptions operator&(DirectoryEnumerationOptions a, DirectoryEnumerationOptions b)
    {
        return static_cast<DirectoryEnumerationOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(DirectoryEnumerationOptions value, DirectoryEnumerationOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSDisplayGamut`. */
    enum class DisplayGamut : std::int64_t
    {
        SRGB = 1,
        P3 = 2,
    };

    /** @brief Wraps the Objective-C option set `NSDistributedNotificationOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class DistributedNotificationOptions : std::uint64_t
    {
        DeliverImmediately = 1,
        PostToAllSessions = 2,
    };

    constexpr DistributedNotificationOptions operator|(DistributedNotificationOptions a, DistributedNotificationOptions b)
    {
        return static_cast<DistributedNotificationOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr DistributedNotificationOptions operator&(DistributedNotificationOptions a, DistributedNotificationOptions b)
    {
        return static_cast<DistributedNotificationOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(DistributedNotificationOptions value, DistributedNotificationOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSDocumentChangeType`. */
    enum class DocumentChangeType : std::uint64_t
    {
        Done = 0,
        Undone = 1,
        Redone = 5,
        Cleared = 2,
        ReadOtherContents = 3,
        Autosaved = 4,
        Discardable = 256,
    };

    /** @brief Wraps the Objective-C option set `NSDragOperation`. Combine option sets with `|` and test them with `test_flag`. */
    enum class DragOperation : std::uint64_t
    {
        None = 0,
        Copy = 1,
        Link = 2,
        Generic = 4,
        Private = 8,
        Move = 16,
        Delete = 32,
        Every = 18446744073709551615ULL,
        All_Obsolete = 15,
        All = 15,
    };

    constexpr DragOperation operator|(DragOperation a, DragOperation b)
    {
        return static_cast<DragOperation>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr DragOperation operator&(DragOperation a, DragOperation b)
    {
        return static_cast<DragOperation>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(DragOperation value, DragOperation flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSDraggingFormation`. */
    enum class DraggingFormation : std::int64_t
    {
        Default = 0,
        None = 1,
        Pile = 2,
        List = 3,
        Stack = 4,
    };

    /** @brief Wraps the Objective-C option set `NSDraggingItemEnumerationOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class DraggingItemEnumerationOptions : std::uint64_t
    {
        Concurrent = 1,
        ClearNonenumeratedImages = 65536,
    };

    constexpr DraggingItemEnumerationOptions operator|(DraggingItemEnumerationOptions a, DraggingItemEnumerationOptions b)
    {
        return static_cast<DraggingItemEnumerationOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr DraggingItemEnumerationOptions operator&(DraggingItemEnumerationOptions a, DraggingItemEnumerationOptions b)
    {
        return static_cast<DraggingItemEnumerationOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(DraggingItemEnumerationOptions value, DraggingItemEnumerationOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSEnergyFormatterUnit`. */
    enum class EnergyFormatterUnit : std::int64_t
    {
        Joule = 11,
        Kilojoule = 14,
        Calorie = 1793,
        Kilocalorie = 1794,
    };

    /** @brief Wraps the Objective-C option set `NSEnumerationOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class EnumerationOptions : std::uint64_t
    {
        Concurrent = 1,
        Reverse = 2,
    };

    constexpr EnumerationOptions operator|(EnumerationOptions a, EnumerationOptions b)
    {
        return static_cast<EnumerationOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr EnumerationOptions operator&(EnumerationOptions a, EnumerationOptions b)
    {
        return static_cast<EnumerationOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(EnumerationOptions value, EnumerationOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSEventButtonMask`. Combine option sets with `|` and test them with `test_flag`. */
    enum class EventButtonMask : std::uint64_t
    {
        PenTip = 1,
        PenLowerSide = 2,
        PenUpperSide = 4,
    };

    constexpr EventButtonMask operator|(EventButtonMask a, EventButtonMask b)
    {
        return static_cast<EventButtonMask>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr EventButtonMask operator&(EventButtonMask a, EventButtonMask b)
    {
        return static_cast<EventButtonMask>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(EventButtonMask value, EventButtonMask flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSEventGestureAxis`. */
    enum class EventGestureAxis : std::int64_t
    {
        None = 0,
        Horizontal = 1,
        Vertical = 2,
    };

    /** @brief Wraps the Objective-C option set `NSEventMask`. Combine option sets with `|` and test them with `test_flag`. */
    enum class EventMask : std::uint64_t
    {
        LeftMouseDown = 2,
        LeftMouseUp = 4,
        RightMouseDown = 8,
        RightMouseUp = 16,
        MouseMoved = 32,
        LeftMouseDragged = 64,
        RightMouseDragged = 128,
        MouseEntered = 256,
        MouseExited = 512,
        KeyDown = 1024,
        KeyUp = 2048,
        FlagsChanged = 4096,
        AppKitDefined = 8192,
        SystemDefined = 16384,
        ApplicationDefined = 32768,
        Periodic = 65536,
        CursorUpdate = 131072,
        ScrollWheel = 4194304,
        TabletPoint = 8388608,
        TabletProximity = 16777216,
        OtherMouseDown = 33554432,
        OtherMouseUp = 67108864,
        OtherMouseDragged = 134217728,
        Gesture = 536870912,
        Magnify = 1073741824,
        Swipe = 2147483648,
        Rotate = 262144,
        BeginGesture = 524288,
        EndGesture = 1048576,
        SmartMagnify = 4294967296,
        Pressure = 17179869184,
        DirectTouch = 137438953472,
        ChangeMode = 274877906944,
        MouseCancelled = 1099511627776,
        Any = 18446744073709551615ULL,
    };

    constexpr EventMask operator|(EventMask a, EventMask b)
    {
        return static_cast<EventMask>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr EventMask operator&(EventMask a, EventMask b)
    {
        return static_cast<EventMask>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(EventMask value, EventMask flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSEventModifierFlags`. Combine option sets with `|` and test them with `test_flag`. */
    enum class EventModifierFlags : std::uint64_t
    {
        CapsLock = 65536,
        Shift = 131072,
        Control = 262144,
        Option = 524288,
        Command = 1048576,
        NumericPad = 2097152,
        Help = 4194304,
        Function = 8388608,
        DeviceIndependentFlagsMask = 4294901760,
    };

    constexpr EventModifierFlags operator|(EventModifierFlags a, EventModifierFlags b)
    {
        return static_cast<EventModifierFlags>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr EventModifierFlags operator&(EventModifierFlags a, EventModifierFlags b)
    {
        return static_cast<EventModifierFlags>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(EventModifierFlags value, EventModifierFlags flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSEventPhase`. Combine option sets with `|` and test them with `test_flag`. */
    enum class EventPhase : std::uint64_t
    {
        None = 0,
        Began = 1,
        Stationary = 2,
        Changed = 4,
        Ended = 8,
        Cancelled = 16,
        MayBegin = 32,
    };

    constexpr EventPhase operator|(EventPhase a, EventPhase b)
    {
        return static_cast<EventPhase>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr EventPhase operator&(EventPhase a, EventPhase b)
    {
        return static_cast<EventPhase>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(EventPhase value, EventPhase flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSEventSubtype`. */
    enum class EventSubtype : std::int16_t
    {
        WindowExposed = 0,
        ApplicationActivated = 1,
        ApplicationDeactivated = 2,
        WindowMoved = 4,
        ScreenChanged = 8,
        PowerOff = 1,
        MouseEvent = 0,
        TabletPoint = 1,
        TabletProximity = 2,
        Touch = 3,
    };

    /** @brief Wraps the Objective-C option set `NSEventSwipeTrackingOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class EventSwipeTrackingOptions : std::uint64_t
    {
        LockDirection = 1,
        ClampGestureAmount = 2,
    };

    constexpr EventSwipeTrackingOptions operator|(EventSwipeTrackingOptions a, EventSwipeTrackingOptions b)
    {
        return static_cast<EventSwipeTrackingOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr EventSwipeTrackingOptions operator&(EventSwipeTrackingOptions a, EventSwipeTrackingOptions b)
    {
        return static_cast<EventSwipeTrackingOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(EventSwipeTrackingOptions value, EventSwipeTrackingOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSEventType`. */
    enum class EventType : std::uint64_t
    {
        LeftMouseDown = 1,
        LeftMouseUp = 2,
        RightMouseDown = 3,
        RightMouseUp = 4,
        MouseMoved = 5,
        LeftMouseDragged = 6,
        RightMouseDragged = 7,
        MouseEntered = 8,
        MouseExited = 9,
        KeyDown = 10,
        KeyUp = 11,
        FlagsChanged = 12,
        AppKitDefined = 13,
        SystemDefined = 14,
        ApplicationDefined = 15,
        Periodic = 16,
        CursorUpdate = 17,
        ScrollWheel = 22,
        TabletPoint = 23,
        TabletProximity = 24,
        OtherMouseDown = 25,
        OtherMouseUp = 26,
        OtherMouseDragged = 27,
        Gesture = 29,
        Magnify = 30,
        Swipe = 31,
        Rotate = 18,
        BeginGesture = 19,
        EndGesture = 20,
        SmartMagnify = 32,
        QuickLook = 33,
        Pressure = 34,
        DirectTouch = 37,
        ChangeMode = 38,
        MouseCancelled = 40,
    };

    /** @brief Wraps the Objective-C enumeration `NSExpressionType`. */
    enum class ExpressionType : std::uint64_t
    {
        ConstantValueExpressionType = 0,
        EvaluatedObjectExpressionType = 1,
        VariableExpressionType = 2,
        KeyPathExpressionType = 3,
        FunctionExpressionType = 4,
        UnionSetExpressionType = 5,
        IntersectSetExpressionType = 6,
        MinusSetExpressionType = 7,
        SubqueryExpressionType = 13,
        AggregateExpressionType = 14,
        AnyKeyExpressionType = 15,
        BlockExpressionType = 19,
        ConditionalExpressionType = 20,
    };

    /** @brief Wraps the Objective-C option set `NSFileCoordinatorReadingOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class FileCoordinatorReadingOptions : std::uint64_t
    {
        WithoutChanges = 1,
        ResolvesSymbolicLink = 2,
        ImmediatelyAvailableMetadataOnly = 4,
        ForUploading = 8,
    };

    constexpr FileCoordinatorReadingOptions operator|(FileCoordinatorReadingOptions a, FileCoordinatorReadingOptions b)
    {
        return static_cast<FileCoordinatorReadingOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr FileCoordinatorReadingOptions operator&(FileCoordinatorReadingOptions a, FileCoordinatorReadingOptions b)
    {
        return static_cast<FileCoordinatorReadingOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(FileCoordinatorReadingOptions value, FileCoordinatorReadingOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSFileCoordinatorWritingOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class FileCoordinatorWritingOptions : std::uint64_t
    {
        ForDeleting = 1,
        ForMoving = 2,
        ForMerging = 4,
        ForReplacing = 8,
        ContentIndependentMetadataOnly = 16,
    };

    constexpr FileCoordinatorWritingOptions operator|(FileCoordinatorWritingOptions a, FileCoordinatorWritingOptions b)
    {
        return static_cast<FileCoordinatorWritingOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr FileCoordinatorWritingOptions operator&(FileCoordinatorWritingOptions a, FileCoordinatorWritingOptions b)
    {
        return static_cast<FileCoordinatorWritingOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(FileCoordinatorWritingOptions value, FileCoordinatorWritingOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSFileManagerItemReplacementOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class FileManagerItemReplacementOptions : std::uint64_t
    {
        UsingNewMetadataOnly = 1,
        WithoutDeletingBackupItem = 2,
    };

    constexpr FileManagerItemReplacementOptions operator|(FileManagerItemReplacementOptions a, FileManagerItemReplacementOptions b)
    {
        return static_cast<FileManagerItemReplacementOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr FileManagerItemReplacementOptions operator&(FileManagerItemReplacementOptions a, FileManagerItemReplacementOptions b)
    {
        return static_cast<FileManagerItemReplacementOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(FileManagerItemReplacementOptions value, FileManagerItemReplacementOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSFileManagerResumeSyncBehavior`. */
    enum class FileManagerResumeSyncBehavior : std::int64_t
    {
        PreserveLocalChanges = 0,
        AfterUploadWithFailOnConflict = 1,
        DropLocalChanges = 2,
    };

    /** @brief Wraps the Objective-C option set `NSFileManagerUnmountOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class FileManagerUnmountOptions : std::uint64_t
    {
        AllPartitionsAndEjectDisk = 1,
        WithoutUI = 2,
    };

    constexpr FileManagerUnmountOptions operator|(FileManagerUnmountOptions a, FileManagerUnmountOptions b)
    {
        return static_cast<FileManagerUnmountOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr FileManagerUnmountOptions operator&(FileManagerUnmountOptions a, FileManagerUnmountOptions b)
    {
        return static_cast<FileManagerUnmountOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(FileManagerUnmountOptions value, FileManagerUnmountOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSFileManagerUploadLocalVersionConflictPolicy`. */
    enum class FileManagerUploadLocalVersionConflictPolicy : std::int64_t
    {
        Default = 0,
        FailOnConflict = 1,
    };

    /** @brief Wraps the Objective-C option set `NSFileVersionAddingOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class FileVersionAddingOptions : std::uint64_t
    {
        Moving = 1,
    };

    constexpr FileVersionAddingOptions operator|(FileVersionAddingOptions a, FileVersionAddingOptions b)
    {
        return static_cast<FileVersionAddingOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr FileVersionAddingOptions operator&(FileVersionAddingOptions a, FileVersionAddingOptions b)
    {
        return static_cast<FileVersionAddingOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(FileVersionAddingOptions value, FileVersionAddingOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSFileVersionReplacingOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class FileVersionReplacingOptions : std::uint64_t
    {
        Moving = 1,
    };

    constexpr FileVersionReplacingOptions operator|(FileVersionReplacingOptions a, FileVersionReplacingOptions b)
    {
        return static_cast<FileVersionReplacingOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr FileVersionReplacingOptions operator&(FileVersionReplacingOptions a, FileVersionReplacingOptions b)
    {
        return static_cast<FileVersionReplacingOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(FileVersionReplacingOptions value, FileVersionReplacingOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSFileWrapperReadingOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class FileWrapperReadingOptions : std::uint64_t
    {
        Immediate = 1,
        WithoutMapping = 2,
    };

    constexpr FileWrapperReadingOptions operator|(FileWrapperReadingOptions a, FileWrapperReadingOptions b)
    {
        return static_cast<FileWrapperReadingOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr FileWrapperReadingOptions operator&(FileWrapperReadingOptions a, FileWrapperReadingOptions b)
    {
        return static_cast<FileWrapperReadingOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(FileWrapperReadingOptions value, FileWrapperReadingOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSFileWrapperWritingOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class FileWrapperWritingOptions : std::uint64_t
    {
        Atomic = 1,
        WithNameUpdating = 2,
    };

    constexpr FileWrapperWritingOptions operator|(FileWrapperWritingOptions a, FileWrapperWritingOptions b)
    {
        return static_cast<FileWrapperWritingOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr FileWrapperWritingOptions operator&(FileWrapperWritingOptions a, FileWrapperWritingOptions b)
    {
        return static_cast<FileWrapperWritingOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(FileWrapperWritingOptions value, FileWrapperWritingOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSFocusRingType`. */
    enum class FocusRingType : std::uint64_t
    {
        Default = 0,
        None = 1,
        Exterior = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSFontAction`. */
    enum class FontAction : std::uint64_t
    {
        NoFontChangeAction = 0,
        ViaPanelFontAction = 1,
        AddTraitFontAction = 2,
        SizeUpFontAction = 3,
        SizeDownFontAction = 4,
        HeavierFontAction = 5,
        LighterFontAction = 6,
        RemoveTraitFontAction = 7,
    };

    /** @brief Wraps the Objective-C option set `NSFontAssetRequestOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class FontAssetRequestOptions : std::uint64_t
    {
        I = 1,
    };

    constexpr FontAssetRequestOptions operator|(FontAssetRequestOptions a, FontAssetRequestOptions b)
    {
        return static_cast<FontAssetRequestOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr FontAssetRequestOptions operator&(FontAssetRequestOptions a, FontAssetRequestOptions b)
    {
        return static_cast<FontAssetRequestOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(FontAssetRequestOptions value, FontAssetRequestOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSFontCollectionVisibility`. Combine option sets with `|` and test them with `test_flag`. */
    enum class FontCollectionVisibility : std::uint64_t
    {
        Process = 1,
        User = 2,
        Computer = 4,
    };

    constexpr FontCollectionVisibility operator|(FontCollectionVisibility a, FontCollectionVisibility b)
    {
        return static_cast<FontCollectionVisibility>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr FontCollectionVisibility operator&(FontCollectionVisibility a, FontCollectionVisibility b)
    {
        return static_cast<FontCollectionVisibility>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(FontCollectionVisibility value, FontCollectionVisibility flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSFontDescriptorSymbolicTraits`. Combine option sets with `|` and test them with `test_flag`. */
    enum class FontDescriptorSymbolicTraits : std::uint32_t
    {
        TraitItalic = 1,
        TraitBold = 2,
        TraitExpanded = 32,
        TraitCondensed = 64,
        TraitMonoSpace = 1024,
        TraitVertical = 2048,
        TraitUIOptimized = 4096,
        TraitTightLeading = 32768,
        TraitLooseLeading = 65536,
        ClassMask = 4026531840U,
        ClassUnknown = 0,
        ClassOldStyleSerifs = 268435456,
        ClassTransitionalSerifs = 536870912,
        ClassModernSerifs = 805306368,
        ClassClarendonSerifs = 1073741824,
        ClassSlabSerifs = 1342177280,
        ClassFreeformSerifs = 1879048192,
        ClassSansSerif = 2147483648U,
        ClassOrnamentals = 2415919104U,
        ClassScripts = 2684354560U,
        ClassSymbolic = 3221225472U,
    };

    constexpr FontDescriptorSymbolicTraits operator|(FontDescriptorSymbolicTraits a, FontDescriptorSymbolicTraits b)
    {
        return static_cast<FontDescriptorSymbolicTraits>(static_cast<std::uint32_t>(a) | static_cast<std::uint32_t>(b));
    }
    constexpr FontDescriptorSymbolicTraits operator&(FontDescriptorSymbolicTraits a, FontDescriptorSymbolicTraits b)
    {
        return static_cast<FontDescriptorSymbolicTraits>(static_cast<std::uint32_t>(a) & static_cast<std::uint32_t>(b));
    }
    constexpr bool test_flag(FontDescriptorSymbolicTraits value, FontDescriptorSymbolicTraits flag)
    {
        return (static_cast<std::uint32_t>(value) & static_cast<std::uint32_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSFontRenderingMode`. */
    enum class FontRenderingMode : std::uint64_t
    {
        DefaultRenderingMode = 0,
        AntialiasedRenderingMode = 1,
        IntegerAdvancementsRenderingMode = 2,
        AntialiasedIntegerAdvancementsRenderingMode = 3,
    };

    /** @brief Wraps the Objective-C option set `NSFontTraitMask`. Combine option sets with `|` and test them with `test_flag`. */
    enum class FontTraitMask : std::uint64_t
    {
        ItalicFontMask = 1,
        BoldFontMask = 2,
        UnboldFontMask = 4,
        NonStandardCharacterSetFontMask = 8,
        NarrowFontMask = 16,
        ExpandedFontMask = 32,
        CondensedFontMask = 64,
        SmallCapsFontMask = 128,
        PosterFontMask = 256,
        CompressedFontMask = 512,
        FixedPitchFontMask = 1024,
        UnitalicFontMask = 16777216,
    };

    constexpr FontTraitMask operator|(FontTraitMask a, FontTraitMask b)
    {
        return static_cast<FontTraitMask>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr FontTraitMask operator&(FontTraitMask a, FontTraitMask b)
    {
        return static_cast<FontTraitMask>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(FontTraitMask value, FontTraitMask flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSFormattingContext`. */
    enum class FormattingContext : std::int64_t
    {
        Unknown = 0,
        Dynamic = 1,
        Standalone = 2,
        ListItem = 3,
        BeginningOfSentence = 4,
        MiddleOfSentence = 5,
    };

    /** @brief Wraps the Objective-C enumeration `NSFormattingUnitStyle`. */
    enum class FormattingUnitStyle : std::int64_t
    {
        Short = 1,
        Medium = 2,
        Long = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSGestureRecognizerState`. */
    enum class GestureRecognizerState : std::int64_t
    {
        Possible = 0,
        Began = 1,
        Changed = 2,
        Ended = 3,
        Cancelled = 4,
        Failed = 5,
        Recognized = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSGlassEffectViewStyle`. */
    enum class GlassStyle : std::int64_t
    {
        Regular = 0,
        Clear = 1,
    };

    /** @brief Wraps the Objective-C option set `NSGlyphProperty`. Combine option sets with `|` and test them with `test_flag`. */
    enum class GlyphProperty : std::int64_t
    {
        Null = 1,
        ControlCharacter = 2,
        Elastic = 4,
        NonBaseCharacter = 8,
    };

    constexpr GlyphProperty operator|(GlyphProperty a, GlyphProperty b)
    {
        return static_cast<GlyphProperty>(static_cast<std::int64_t>(a) | static_cast<std::int64_t>(b));
    }
    constexpr GlyphProperty operator&(GlyphProperty a, GlyphProperty b)
    {
        return static_cast<GlyphProperty>(static_cast<std::int64_t>(a) & static_cast<std::int64_t>(b));
    }
    constexpr bool test_flag(GlyphProperty value, GlyphProperty flag)
    {
        return (static_cast<std::int64_t>(value) & static_cast<std::int64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSGradientDrawingOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class GradientDrawingOptions : std::uint64_t
    {
        BeforeStartingLocation = 1,
        AfterEndingLocation = 2,
    };

    constexpr GradientDrawingOptions operator|(GradientDrawingOptions a, GradientDrawingOptions b)
    {
        return static_cast<GradientDrawingOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr GradientDrawingOptions operator&(GradientDrawingOptions a, GradientDrawingOptions b)
    {
        return static_cast<GradientDrawingOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(GradientDrawingOptions value, GradientDrawingOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSGrammaticalCase`. */
    enum class GrammaticalCase : std::int64_t
    {
        NotSet = 0,
        Nominative = 1,
        Accusative = 2,
        Dative = 3,
        Genitive = 4,
        Prepositional = 5,
        Ablative = 6,
        Adessive = 7,
        Allative = 8,
        Elative = 9,
        Illative = 10,
        Essive = 11,
        Inessive = 12,
        Locative = 13,
        Translative = 14,
    };

    /** @brief Wraps the Objective-C enumeration `NSGrammaticalDefiniteness`. */
    enum class GrammaticalDefiniteness : std::int64_t
    {
        NotSet = 0,
        Indefinite = 1,
        Definite = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSGrammaticalDetermination`. */
    enum class GrammaticalDetermination : std::int64_t
    {
        NotSet = 0,
        Independent = 1,
        Dependent = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSGrammaticalGender`. */
    enum class GrammaticalGender : std::int64_t
    {
        NotSet = 0,
        Feminine = 1,
        Masculine = 2,
        Neuter = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSGrammaticalNumber`. */
    enum class GrammaticalNumber : std::int64_t
    {
        NotSet = 0,
        Singular = 1,
        Zero = 2,
        Plural = 3,
        PluralTwo = 4,
        PluralFew = 5,
        PluralMany = 6,
    };

    /** @brief Wraps the Objective-C enumeration `NSGrammaticalPartOfSpeech`. */
    enum class GrammaticalPartOfSpeech : std::int64_t
    {
        NotSet = 0,
        Determiner = 1,
        Pronoun = 2,
        Letter = 3,
        Adverb = 4,
        Particle = 5,
        Adjective = 6,
        Adposition = 7,
        Verb = 8,
        Noun = 9,
        Conjunction = 10,
        Numeral = 11,
        Interjection = 12,
        Preposition = 13,
        Abbreviation = 14,
    };

    /** @brief Wraps the Objective-C enumeration `NSGrammaticalPerson`. */
    enum class GrammaticalPerson : std::int64_t
    {
        NotSet = 0,
        First = 1,
        Second = 2,
        Third = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSGrammaticalPronounType`. */
    enum class GrammaticalPronounType : std::int64_t
    {
        NotSet = 0,
        Personal = 1,
        Reflexive = 2,
        Possessive = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSGridCellPlacement`. */
    enum class GridCellPlacement : std::int64_t
    {
        Inherited = 0,
        None = 1,
        Leading = 2,
        Top = 2,
        Trailing = 3,
        Bottom = 3,
        Center = 4,
        Fill = 5,
    };

    /** @brief Wraps the Objective-C enumeration `NSGridRowAlignment`. */
    enum class GridRowAlignment : std::int64_t
    {
        Inherited = 0,
        None = 1,
        FirstBaseline = 2,
        LastBaseline = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSHTTPCookieAcceptPolicy`. */
    enum class HTTPCookieAcceptPolicy : std::uint64_t
    {
        Always = 0,
        Never = 1,
        OnlyFromMainDocumentDomain = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSHapticFeedbackPerformanceTime`. */
    enum class HapticFeedbackPerformanceTime : std::uint64_t
    {
        Default = 0,
        Now = 1,
        DrawCompleted = 2,
    };

    /** @brief Wraps the Objective-C option set `NSHorizontalDirections`. Combine option sets with `|` and test them with `test_flag`. */
    enum class HorizontalDirections : std::uint64_t
    {
        Left = 1,
        Right = 2,
        All = 3,
    };

    constexpr HorizontalDirections operator|(HorizontalDirections a, HorizontalDirections b)
    {
        return static_cast<HorizontalDirections>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr HorizontalDirections operator&(HorizontalDirections a, HorizontalDirections b)
    {
        return static_cast<HorizontalDirections>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(HorizontalDirections value, HorizontalDirections flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSISO8601DateFormatOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class ISO8601DateFormatOptions : std::uint64_t
    {
        Year = 1,
        Month = 2,
        WeekOfYear = 4,
        Day = 16,
        Time = 32,
        TimeZone = 64,
        SpaceBetweenDateAndTime = 128,
        DashSeparatorInDate = 256,
        ColonSeparatorInTime = 512,
        ColonSeparatorInTimeZone = 1024,
        FractionalSeconds = 2048,
        FullDate = 275,
        FullTime = 1632,
        InternetDateTime = 1907,
    };

    constexpr ISO8601DateFormatOptions operator|(ISO8601DateFormatOptions a, ISO8601DateFormatOptions b)
    {
        return static_cast<ISO8601DateFormatOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr ISO8601DateFormatOptions operator&(ISO8601DateFormatOptions a, ISO8601DateFormatOptions b)
    {
        return static_cast<ISO8601DateFormatOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(ISO8601DateFormatOptions value, ISO8601DateFormatOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSImageAlignment`. */
    enum class ImageAlignment : std::uint64_t
    {
        Center = 0,
        Top = 1,
        TopLeft = 2,
        TopRight = 3,
        Left = 4,
        Bottom = 5,
        BottomLeft = 6,
        BottomRight = 7,
        Right = 8,
    };

    /** @brief Wraps the Objective-C enumeration `NSImageCacheMode`. */
    enum class ImageCacheMode : std::uint64_t
    {
        Default = 0,
        Always = 1,
        BySize = 2,
        Never = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSImageDynamicRange`. */
    enum class ImageDynamicRange : std::int64_t
    {
        Unspecified = -1,
        Standard = 0,
        ConstrainedHigh = 1,
        High = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSImageFrameStyle`. */
    enum class ImageFrameStyle : std::uint64_t
    {
        None = 0,
        Photo = 1,
        GrayBezel = 2,
        Groove = 3,
        Button = 4,
    };

    /** @brief Wraps the Objective-C enumeration `NSImageInterpolation`. */
    enum class ImageInterpolation : std::uint64_t
    {
        Default = 0,
        None = 1,
        Low = 2,
        Medium = 4,
        High = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSImageLayoutDirection`. */
    enum class ImageLayoutDirection : std::int64_t
    {
        Unspecified = -1,
        LeftToRight = 2,
        RightToLeft = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSImageResizingMode`. */
    enum class ImageResizingMode : std::int64_t
    {
        Tile = 0,
        Stretch = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSImageScaling`. */
    enum class ImageScaling : std::uint64_t
    {
        ImageScaleProportionallyDown = 0,
        ImageScaleAxesIndependently = 1,
        ImageScaleNone = 2,
        ImageScaleProportionallyUpOrDown = 3,
        ScaleProportionally = 0,
        ScaleToFit = 1,
        ScaleNone = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSImageSymbolColorRenderingMode`. */
    enum class ImageSymbolColorRenderingMode : std::int64_t
    {
        Automatic = 0,
        Flat = 1,
        Gradient = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSImageSymbolScale`. */
    enum class ImageSymbolScale : std::int64_t
    {
        Small = 1,
        Medium = 2,
        Large = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSImageSymbolVariableValueMode`. */
    enum class ImageSymbolVariableValueMode : std::int64_t
    {
        Automatic = 0,
        Color = 1,
        Draw = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSInsertionPosition`. */
    enum class InsertionPosition : std::uint64_t
    {
        After = 0,
        Before = 1,
        Beginning = 2,
        End = 3,
        Replace = 4,
    };

    /** @brief Wraps the Objective-C option set `NSItemProviderFileOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class ItemProviderFileOptions : std::int64_t
    {
        Place = 1,
    };

    constexpr ItemProviderFileOptions operator|(ItemProviderFileOptions a, ItemProviderFileOptions b)
    {
        return static_cast<ItemProviderFileOptions>(static_cast<std::int64_t>(a) | static_cast<std::int64_t>(b));
    }
    constexpr ItemProviderFileOptions operator&(ItemProviderFileOptions a, ItemProviderFileOptions b)
    {
        return static_cast<ItemProviderFileOptions>(static_cast<std::int64_t>(a) & static_cast<std::int64_t>(b));
    }
    constexpr bool test_flag(ItemProviderFileOptions value, ItemProviderFileOptions flag)
    {
        return (static_cast<std::int64_t>(value) & static_cast<std::int64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSItemProviderRepresentationVisibility`. */
    enum class ItemProviderRepresentationVisibility : std::int64_t
    {
        All = 0,
        Group = 2,
        OwnProcess = 3,
    };

    /** @brief Wraps the Objective-C option set `NSJSONReadingOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class JSONReadingOptions : std::uint64_t
    {
        MutableContainers = 1,
        MutableLeaves = 2,
        FragmentsAllowed = 4,
        JSON5Allowed = 8,
        TopLevelDictionaryAssumed = 16,
        AllowFragments = 4,
    };

    constexpr JSONReadingOptions operator|(JSONReadingOptions a, JSONReadingOptions b)
    {
        return static_cast<JSONReadingOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr JSONReadingOptions operator&(JSONReadingOptions a, JSONReadingOptions b)
    {
        return static_cast<JSONReadingOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(JSONReadingOptions value, JSONReadingOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSJSONWritingOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class JSONWritingOptions : std::uint64_t
    {
        PrettyPrinted = 1,
        SortedKeys = 2,
        FragmentsAllowed = 4,
        WithoutEscapingSlashes = 8,
    };

    constexpr JSONWritingOptions operator|(JSONWritingOptions a, JSONWritingOptions b)
    {
        return static_cast<JSONWritingOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr JSONWritingOptions operator&(JSONWritingOptions a, JSONWritingOptions b)
    {
        return static_cast<JSONWritingOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(JSONWritingOptions value, JSONWritingOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSKeyValueObservingOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class KeyValueObservingOptions : std::uint64_t
    {
        New = 1,
        Old = 2,
        Initial = 4,
        Prior = 8,
    };

    constexpr KeyValueObservingOptions operator|(KeyValueObservingOptions a, KeyValueObservingOptions b)
    {
        return static_cast<KeyValueObservingOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr KeyValueObservingOptions operator&(KeyValueObservingOptions a, KeyValueObservingOptions b)
    {
        return static_cast<KeyValueObservingOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(KeyValueObservingOptions value, KeyValueObservingOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSLayoutAttribute`. */
    enum class LayoutAttribute : std::int64_t
    {
        Left = 1,
        Right = 2,
        Top = 3,
        Bottom = 4,
        Leading = 5,
        Trailing = 6,
        Width = 7,
        Height = 8,
        CenterX = 9,
        CenterY = 10,
        LastBaseline = 11,
        Baseline = 11,
        FirstBaseline = 12,
        NotAnAttribute = 0,
    };

    /** @brief Wraps the Objective-C enumeration `NSLayoutConstraintOrientation`. */
    enum class ConstraintOrientation : std::int64_t
    {
        Horizontal = 0,
        Vertical = 1,
    };

    /** @brief Wraps the Objective-C option set `NSLayoutFormatOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class LayoutFormatOptions : std::uint64_t
    {
        AlignAllLeft = 2,
        AlignAllRight = 4,
        AlignAllTop = 8,
        AlignAllBottom = 16,
        AlignAllLeading = 32,
        AlignAllTrailing = 64,
        AlignAllCenterX = 512,
        AlignAllCenterY = 1024,
        AlignAllLastBaseline = 2048,
        AlignAllFirstBaseline = 4096,
        AlignAllBaseline = 2048,
        AlignmentMask = 65535,
        DirectionLeadingToTrailing = 0,
        DirectionLeftToRight = 65536,
        DirectionRightToLeft = 131072,
        DirectionMask = 196608,
    };

    constexpr LayoutFormatOptions operator|(LayoutFormatOptions a, LayoutFormatOptions b)
    {
        return static_cast<LayoutFormatOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr LayoutFormatOptions operator&(LayoutFormatOptions a, LayoutFormatOptions b)
    {
        return static_cast<LayoutFormatOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(LayoutFormatOptions value, LayoutFormatOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSLayoutRelation`. */
    enum class LayoutRelation : std::int64_t
    {
        LessThanOrEqual = -1,
        Equal = 0,
        GreaterThanOrEqual = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSLengthFormatterUnit`. */
    enum class LengthFormatterUnit : std::int64_t
    {
        Millimeter = 8,
        Centimeter = 9,
        Meter = 11,
        Kilometer = 14,
        Inch = 1281,
        Foot = 1282,
        Yard = 1283,
        Mile = 1284,
    };

    /** @brief Wraps the Objective-C enumeration `NSLevelIndicatorPlaceholderVisibility`. */
    enum class LevelIndicatorPlaceholderVisibility : std::int64_t
    {
        Automatic = 0,
        Always = 1,
        WhileEditing = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSLevelIndicatorStyle`. */
    enum class LevelIndicatorStyle : std::uint64_t
    {
        Relevancy = 0,
        ContinuousCapacity = 1,
        DiscreteCapacity = 2,
        Rating = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSLineBreakMode`. */
    enum class LineBreakMode : std::uint64_t
    {
        WordWrapping = 0,
        CharWrapping = 1,
        Clipping = 2,
        TruncatingHead = 3,
        TruncatingTail = 4,
        TruncatingMiddle = 5,
    };

    /** @brief Wraps the Objective-C option set `NSLineBreakStrategy`. Combine option sets with `|` and test them with `test_flag`. */
    enum class LineBreakStrategy : std::uint64_t
    {
        None = 0,
        PushOut = 1,
        HangulWordPriority = 2,
        Standard = 65535,
    };

    constexpr LineBreakStrategy operator|(LineBreakStrategy a, LineBreakStrategy b)
    {
        return static_cast<LineBreakStrategy>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr LineBreakStrategy operator&(LineBreakStrategy a, LineBreakStrategy b)
    {
        return static_cast<LineBreakStrategy>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(LineBreakStrategy value, LineBreakStrategy flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSLineCapStyle`. */
    enum class LineCapStyle : std::uint64_t
    {
        Butt = 0,
        Round = 1,
        Square = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSLineJoinStyle`. */
    enum class LineJoinStyle : std::uint64_t
    {
        Miter = 0,
        Round = 1,
        Bevel = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSLineMovementDirection`. */
    enum class LineMovementDirection : std::uint64_t
    {
        DoesntMove = 0,
        MovesLeft = 1,
        MovesRight = 2,
        MovesDown = 3,
        MovesUp = 4,
    };

    /** @brief Wraps the Objective-C enumeration `NSLineSweepDirection`. */
    enum class LineSweepDirection : std::uint64_t
    {
        Left = 0,
        Right = 1,
        Down = 2,
        Up = 3,
    };

    /** @brief Wraps the Objective-C option set `NSLinguisticTaggerOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class LinguisticTaggerOptions : std::uint64_t
    {
        OmitWords = 1,
        OmitPunctuation = 2,
        OmitWhitespace = 4,
        OmitOther = 8,
        JoinNames = 16,
    };

    constexpr LinguisticTaggerOptions operator|(LinguisticTaggerOptions a, LinguisticTaggerOptions b)
    {
        return static_cast<LinguisticTaggerOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr LinguisticTaggerOptions operator&(LinguisticTaggerOptions a, LinguisticTaggerOptions b)
    {
        return static_cast<LinguisticTaggerOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(LinguisticTaggerOptions value, LinguisticTaggerOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSLinguisticTaggerUnit`. */
    enum class LinguisticTaggerUnit : std::int64_t
    {
        Word = 0,
        Sentence = 1,
        Paragraph = 2,
        Document = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSLocaleLanguageDirection`. */
    enum class LocaleLanguageDirection : std::uint64_t
    {
        Unknown = 0,
        LeftToRight = 1,
        RightToLeft = 2,
        TopToBottom = 3,
        BottomToTop = 4,
    };

    /** @brief Wraps the Objective-C option set `NSMachPortOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class MachPortOptions : std::uint64_t
    {
        None = 0,
        SendRight = 1,
        ReceiveRight = 2,
    };

    constexpr MachPortOptions operator|(MachPortOptions a, MachPortOptions b)
    {
        return static_cast<MachPortOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr MachPortOptions operator&(MachPortOptions a, MachPortOptions b)
    {
        return static_cast<MachPortOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(MachPortOptions value, MachPortOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSManagedObjectContextConcurrencyType`. */
    enum class ManagedObjectContextConcurrencyType : std::uint64_t
    {
        ConfinementConcurrencyType = 0,
        PrivateQueueConcurrencyType = 1,
        MainQueueConcurrencyType = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSMassFormatterUnit`. */
    enum class MassFormatterUnit : std::int64_t
    {
        Gram = 11,
        Kilogram = 14,
        Ounce = 1537,
        Pound = 1538,
        Stone = 1539,
    };

    /** @brief Wraps the Objective-C option set `NSMatchingFlags`. Combine option sets with `|` and test them with `test_flag`. */
    enum class MatchingFlags : std::uint64_t
    {
        Progress = 1,
        Completed = 2,
        HitEnd = 4,
        RequiredEnd = 8,
        InternalError = 16,
    };

    constexpr MatchingFlags operator|(MatchingFlags a, MatchingFlags b)
    {
        return static_cast<MatchingFlags>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr MatchingFlags operator&(MatchingFlags a, MatchingFlags b)
    {
        return static_cast<MatchingFlags>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(MatchingFlags value, MatchingFlags flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSMatchingOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class MatchingOptions : std::uint64_t
    {
        ReportProgress = 1,
        ReportCompletion = 2,
        Anchored = 4,
        WithTransparentBounds = 8,
        WithoutAnchoringBounds = 16,
    };

    constexpr MatchingOptions operator|(MatchingOptions a, MatchingOptions b)
    {
        return static_cast<MatchingOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr MatchingOptions operator&(MatchingOptions a, MatchingOptions b)
    {
        return static_cast<MatchingOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(MatchingOptions value, MatchingOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSMatrixMode`. */
    enum class MatrixMode : std::uint64_t
    {
        RadioModeMatrix = 0,
        HighlightModeMatrix = 1,
        ListModeMatrix = 2,
        TrackModeMatrix = 3,
    };

    /** @brief Wraps the Objective-C option set `NSMeasurementFormatterUnitOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class MeasurementFormatterUnitOptions : std::uint64_t
    {
        ProvidedUnit = 1,
        NaturalScale = 2,
        TemperatureWithoutUnit = 4,
    };

    constexpr MeasurementFormatterUnitOptions operator|(MeasurementFormatterUnitOptions a, MeasurementFormatterUnitOptions b)
    {
        return static_cast<MeasurementFormatterUnitOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr MeasurementFormatterUnitOptions operator&(MeasurementFormatterUnitOptions a, MeasurementFormatterUnitOptions b)
    {
        return static_cast<MeasurementFormatterUnitOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(MeasurementFormatterUnitOptions value, MeasurementFormatterUnitOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSMediaLibrary`. Combine option sets with `|` and test them with `test_flag`. */
    enum class MediaLibrary : std::uint64_t
    {
        Audio = 1,
        Image = 2,
        Movie = 4,
    };

    constexpr MediaLibrary operator|(MediaLibrary a, MediaLibrary b)
    {
        return static_cast<MediaLibrary>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr MediaLibrary operator&(MediaLibrary a, MediaLibrary b)
    {
        return static_cast<MediaLibrary>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(MediaLibrary value, MediaLibrary flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSMenuItemBadgeType`. */
    enum class MenuItemBadgeType : std::int64_t
    {
        None = 0,
        Updates = 1,
        NewItems = 2,
        Alerts = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSMenuItemImageVisibility`. */
    enum class MenuItemImageVisibility : std::int64_t
    {
        Automatic = 0,
        Visible = 1,
        Hidden = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSMenuPresentationStyle`. */
    enum class MenuPresentationStyle : std::int64_t
    {
        Regular = 0,
        Palette = 1,
    };

    /** @brief Wraps the Objective-C option set `NSMenuProperties`. Combine option sets with `|` and test them with `test_flag`. */
    enum class MenuProperties : std::uint64_t
    {
        Title = 1,
        AttributedTitle = 2,
        KeyEquivalent = 4,
        Image = 8,
        Enabled = 16,
        AccessibilityDescription = 32,
    };

    constexpr MenuProperties operator|(MenuProperties a, MenuProperties b)
    {
        return static_cast<MenuProperties>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr MenuProperties operator&(MenuProperties a, MenuProperties b)
    {
        return static_cast<MenuProperties>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(MenuProperties value, MenuProperties flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSMenuSelectionMode`. */
    enum class MenuSelectionMode : std::int64_t
    {
        Automatic = 0,
        SelectOne = 1,
        SelectAny = 2,
    };

    /** @brief Wraps the Objective-C option set `NSNetServiceOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class NetServiceOptions : std::uint64_t
    {
        NoAutoRename = 1,
        ListenForConnections = 2,
    };

    constexpr NetServiceOptions operator|(NetServiceOptions a, NetServiceOptions b)
    {
        return static_cast<NetServiceOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr NetServiceOptions operator&(NetServiceOptions a, NetServiceOptions b)
    {
        return static_cast<NetServiceOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(NetServiceOptions value, NetServiceOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSNotificationCoalescing`. Combine option sets with `|` and test them with `test_flag`. */
    enum class NotificationCoalescing : std::uint64_t
    {
        NotificationNoCoalescing = 0,
        OnName = 1,
        OnSender = 2,
    };

    constexpr NotificationCoalescing operator|(NotificationCoalescing a, NotificationCoalescing b)
    {
        return static_cast<NotificationCoalescing>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr NotificationCoalescing operator&(NotificationCoalescing a, NotificationCoalescing b)
    {
        return static_cast<NotificationCoalescing>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(NotificationCoalescing value, NotificationCoalescing flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSNotificationSuspensionBehavior`. */
    enum class NotificationSuspensionBehavior : std::uint64_t
    {
        Drop = 1,
        Coalesce = 2,
        Hold = 3,
        DeliverImmediately = 4,
    };

    /** @brief Wraps the Objective-C enumeration `NSNumberFormatterBehavior`. */
    enum class NumberFormatterBehavior : std::uint64_t
    {
        Default = 0,
        _10_0 = 1000,
        _10_4 = 1040,
    };

    /** @brief Wraps the Objective-C enumeration `NSNumberFormatterPadPosition`. */
    enum class NumberFormatterPadPosition : std::uint64_t
    {
        BeforePrefix = 0,
        AfterPrefix = 1,
        BeforeSuffix = 2,
        AfterSuffix = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSNumberFormatterRoundingMode`. */
    enum class NumberFormatterRoundingMode : std::uint64_t
    {
        Ceiling = 0,
        Floor = 1,
        Down = 2,
        Up = 3,
        HalfEven = 4,
        HalfDown = 5,
        HalfUp = 6,
    };

    /** @brief Wraps the Objective-C enumeration `NSNumberFormatterStyle`. */
    enum class NumberFormatterStyle : std::uint64_t
    {
        NoStyle = 0,
        DecimalStyle = 1,
        CurrencyStyle = 2,
        PercentStyle = 3,
        ScientificStyle = 4,
        SpellOutStyle = 5,
        OrdinalStyle = 6,
        CurrencyISOCodeStyle = 8,
        CurrencyPluralStyle = 9,
        CurrencyAccountingStyle = 10,
    };

    /** @brief Wraps the Objective-C enumeration `NSOpenGLContextParameter`. */
    enum class OpenGLContextParameter : std::int64_t
    {
        SwapInterval = 222,
        SurfaceOrder = 235,
        SurfaceOpacity = 236,
        SurfaceBackingSize = 304,
        ReclaimResources = 308,
        CurrentRendererID = 309,
        GPUVertexProcessing = 310,
        GPUFragmentProcessing = 311,
        HasDrawable = 314,
        MPSwapsInFlight = 315,
        SwapRectangle = 200,
        SwapRectangleEnable = 201,
        RasterizationEnable = 221,
        StateValidation = 301,
        SurfaceSurfaceVolatile = 306,
    };

    /** @brief Wraps the Objective-C enumeration `NSOperationQueuePriority`. */
    enum class OperationQueuePriority : std::int64_t
    {
        VeryLow = -8,
        Low = -4,
        Normal = 0,
        High = 4,
        VeryHigh = 8,
    };

    /** @brief Wraps the Objective-C option set `NSPDFPanelOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class PDFPanelOptions : std::int64_t
    {
        ShowsPaperSize = 4,
        ShowsOrientation = 8,
        RequestsParentDirectory = 16777216,
    };

    constexpr PDFPanelOptions operator|(PDFPanelOptions a, PDFPanelOptions b)
    {
        return static_cast<PDFPanelOptions>(static_cast<std::int64_t>(a) | static_cast<std::int64_t>(b));
    }
    constexpr PDFPanelOptions operator&(PDFPanelOptions a, PDFPanelOptions b)
    {
        return static_cast<PDFPanelOptions>(static_cast<std::int64_t>(a) & static_cast<std::int64_t>(b));
    }
    constexpr bool test_flag(PDFPanelOptions value, PDFPanelOptions flag)
    {
        return (static_cast<std::int64_t>(value) & static_cast<std::int64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSPageControllerTransitionStyle`. */
    enum class PageControllerTransitionStyle : std::int64_t
    {
        StackHistory = 0,
        StackBook = 1,
        HorizontalStrip = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSPageLayoutResult`. */
    enum class PageLayoutResult : std::int64_t
    {
        Cancelled = 0,
        Changed = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSPaperOrientation`. */
    enum class PaperOrientation : std::int64_t
    {
        Portrait = 0,
        Landscape = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSPasteboardAccessBehavior`. */
    enum class PasteboardAccessBehavior : std::int64_t
    {
        Default = 0,
        Ask = 1,
        AlwaysAllow = 2,
        AlwaysDeny = 3,
    };

    /** @brief Wraps the Objective-C option set `NSPasteboardContentsOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class PasteboardContentsOptions : std::uint64_t
    {
        Only = 1,
    };

    constexpr PasteboardContentsOptions operator|(PasteboardContentsOptions a, PasteboardContentsOptions b)
    {
        return static_cast<PasteboardContentsOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr PasteboardContentsOptions operator&(PasteboardContentsOptions a, PasteboardContentsOptions b)
    {
        return static_cast<PasteboardContentsOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(PasteboardContentsOptions value, PasteboardContentsOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSPathStyle`. */
    enum class PathStyle : std::int64_t
    {
        Standard = 0,
        PopUp = 2,
        NavigationBar = 1,
    };

    /** @brief Wraps the Objective-C option set `NSPersonNameComponentsFormatterOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class PersonNameComponentsFormatterOptions : std::uint64_t
    {
        Phonetic = 2,
    };

    constexpr PersonNameComponentsFormatterOptions operator|(PersonNameComponentsFormatterOptions a, PersonNameComponentsFormatterOptions b)
    {
        return static_cast<PersonNameComponentsFormatterOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr PersonNameComponentsFormatterOptions operator&(PersonNameComponentsFormatterOptions a, PersonNameComponentsFormatterOptions b)
    {
        return static_cast<PersonNameComponentsFormatterOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(PersonNameComponentsFormatterOptions value, PersonNameComponentsFormatterOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSPersonNameComponentsFormatterStyle`. */
    enum class PersonNameComponentsFormatterStyle : std::int64_t
    {
        Default = 0,
        Short = 1,
        Medium = 2,
        Long = 3,
        Abbreviated = 4,
    };

    /** @brief Wraps the Objective-C enumeration `NSPickerTouchBarItemControlRepresentation`. */
    enum class PickerTouchBarItemControlRepresentation : std::int64_t
    {
        Automatic = 0,
        Expanded = 1,
        Collapsed = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSPickerTouchBarItemSelectionMode`. */
    enum class PickerTouchBarItemSelectionMode : std::int64_t
    {
        SelectOne = 0,
        SelectAny = 1,
        Momentary = 2,
    };

    /** @brief Wraps the Objective-C option set `NSPointerFunctionsOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class PointerFunctionsOptions : std::uint64_t
    {
        StrongMemory = 0,
        ZeroingWeakMemory = 1,
        OpaqueMemory = 2,
        MallocMemory = 3,
        MachVirtualMemory = 4,
        WeakMemory = 5,
        ObjectPersonality = 0,
        OpaquePersonality = 256,
        ObjectPointerPersonality = 512,
        CStringPersonality = 768,
        StructPersonality = 1024,
        IntegerPersonality = 1280,
        CopyIn = 65536,
    };

    constexpr PointerFunctionsOptions operator|(PointerFunctionsOptions a, PointerFunctionsOptions b)
    {
        return static_cast<PointerFunctionsOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr PointerFunctionsOptions operator&(PointerFunctionsOptions a, PointerFunctionsOptions b)
    {
        return static_cast<PointerFunctionsOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(PointerFunctionsOptions value, PointerFunctionsOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSPointingDeviceType`. */
    enum class PointingDeviceType : std::uint64_t
    {
        Unknown = 0,
        Pen = 1,
        Cursor = 2,
        Eraser = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSPopUpArrowPosition`. */
    enum class PopUpArrowPosition : std::uint64_t
    {
        NoArrow = 0,
        ArrowAtCenter = 1,
        ArrowAtBottom = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSPopoverBehavior`. */
    enum class PopoverBehavior : std::int64_t
    {
        ApplicationDefined = 0,
        Transient = 1,
        Semitransient = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSPostingStyle`. */
    enum class PostingStyle : std::uint64_t
    {
        WhenIdle = 1,
        ASAP = 2,
        Now = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSPredicateOperatorType`. */
    enum class PredicateOperatorType : std::uint64_t
    {
        LessThanPredicateOperatorType = 0,
        LessThanOrEqualToPredicateOperatorType = 1,
        GreaterThanPredicateOperatorType = 2,
        GreaterThanOrEqualToPredicateOperatorType = 3,
        EqualToPredicateOperatorType = 4,
        NotEqualToPredicateOperatorType = 5,
        MatchesPredicateOperatorType = 6,
        LikePredicateOperatorType = 7,
        BeginsWithPredicateOperatorType = 8,
        EndsWithPredicateOperatorType = 9,
        InPredicateOperatorType = 10,
        CustomSelectorPredicateOperatorType = 11,
        ContainsPredicateOperatorType = 99,
        BetweenPredicateOperatorType = 100,
    };

    /** @brief Wraps the Objective-C enumeration `NSPresentationIntentKind`. */
    enum class PresentationIntentKind : std::int64_t
    {
        Paragraph = 0,
        Header = 1,
        OrderedList = 2,
        UnorderedList = 3,
        ListItem = 4,
        CodeBlock = 5,
        BlockQuote = 6,
        ThematicBreak = 7,
        Table = 8,
        TableHeaderRow = 9,
        TableRow = 10,
        TableCell = 11,
    };

    /** @brief Wraps the Objective-C enumeration `NSPressureBehavior`. */
    enum class PressureBehavior : std::int64_t
    {
        Unknown = -1,
        PrimaryDefault = 0,
        PrimaryClick = 1,
        PrimaryGeneric = 2,
        PrimaryAccelerator = 3,
        PrimaryDeepClick = 5,
        PrimaryDeepDrag = 6,
    };

    /** @brief Wraps the Objective-C option set `NSPrintPanelOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class PrintPanelOptions : std::uint64_t
    {
        Copies = 1,
        PageRange = 2,
        PaperSize = 4,
        Orientation = 8,
        Scaling = 16,
        PrintSelection = 32,
        PageSetupAccessory = 256,
        Preview = 131072,
    };

    constexpr PrintPanelOptions operator|(PrintPanelOptions a, PrintPanelOptions b)
    {
        return static_cast<PrintPanelOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr PrintPanelOptions operator&(PrintPanelOptions a, PrintPanelOptions b)
    {
        return static_cast<PrintPanelOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(PrintPanelOptions value, PrintPanelOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSPrintPanelResult`. */
    enum class PrintPanelResult : std::int64_t
    {
        Cancelled = 0,
        Printed = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSPrintRenderingQuality`. */
    enum class PrintRenderingQuality : std::int64_t
    {
        Best = 0,
        Responsive = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSPrintingPageOrder`. */
    enum class PrintingPageOrder : std::int64_t
    {
        DescendingPageOrder = -1,
        SpecialPageOrder = 0,
        AscendingPageOrder = 1,
        UnknownPageOrder = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSPrintingPaginationMode`. */
    enum class PrintingPaginationMode : std::uint64_t
    {
        Automatic = 0,
        Fit = 1,
        Clip = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSProcessInfoThermalState`. */
    enum class ProcessInfoThermalState : std::int64_t
    {
        Nominal = 0,
        Fair = 1,
        Serious = 2,
        Critical = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSProgressIndicatorStyle`. */
    enum class ProgressIndicatorStyle : std::uint64_t
    {
        Bar = 0,
        Spinning = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSPropertyListFormat`. */
    enum class PropertyListFormat : std::uint64_t
    {
        OpenStepFormat = 1,
        XMLFormat_v1_0 = 100,
        BinaryFormat_v1_0 = 200,
    };

    /** @brief Wraps the Objective-C option set `NSPropertyListMutabilityOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class PropertyListMutabilityOptions : std::uint64_t
    {
        Immutable = 0,
        MutableContainers = 1,
        MutableContainersAndLeaves = 2,
    };

    constexpr PropertyListMutabilityOptions operator|(PropertyListMutabilityOptions a, PropertyListMutabilityOptions b)
    {
        return static_cast<PropertyListMutabilityOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr PropertyListMutabilityOptions operator&(PropertyListMutabilityOptions a, PropertyListMutabilityOptions b)
    {
        return static_cast<PropertyListMutabilityOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(PropertyListMutabilityOptions value, PropertyListMutabilityOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSQualityOfService`. */
    enum class QualityOfService : std::int64_t
    {
        UserInteractive = 33,
        UserInitiated = 25,
        Utility = 17,
        Background = 9,
        Default = -1,
    };

    /** @brief Wraps the Objective-C enumeration `NSRectAlignment`. */
    enum class RectAlignment : std::int64_t
    {
        None = 0,
        Top = 1,
        TopLeading = 2,
        Leading = 3,
        BottomLeading = 4,
        Bottom = 5,
        BottomTrailing = 6,
        Trailing = 7,
        TopTrailing = 8,
    };

    /** @brief Wraps the Objective-C enumeration `NSRectEdge`. */
    enum class RectEdge : std::uint64_t
    {
        MinX = 0,
        MinY = 1,
        MaxX = 2,
        MaxY = 3,
        MinXEdge = 0,
        MinYEdge = 1,
        MaxXEdge = 2,
        MaxYEdge = 3,
    };

    /** @brief Wraps the Objective-C option set `NSRegularExpressionOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class RegularExpressionOptions : std::uint64_t
    {
        CaseInsensitive = 1,
        AllowCommentsAndWhitespace = 2,
        IgnoreMetacharacters = 4,
        DotMatchesLineSeparators = 8,
        AnchorsMatchLines = 16,
        UseUnixLineSeparators = 32,
        UseUnicodeWordBoundaries = 64,
    };

    constexpr RegularExpressionOptions operator|(RegularExpressionOptions a, RegularExpressionOptions b)
    {
        return static_cast<RegularExpressionOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr RegularExpressionOptions operator&(RegularExpressionOptions a, RegularExpressionOptions b)
    {
        return static_cast<RegularExpressionOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(RegularExpressionOptions value, RegularExpressionOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSRelativeDateTimeFormatterStyle`. */
    enum class RelativeDateTimeFormatterStyle : std::int64_t
    {
        Numeric = 0,
        Named = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSRelativeDateTimeFormatterUnitsStyle`. */
    enum class RelativeDateTimeFormatterUnitsStyle : std::int64_t
    {
        Full = 0,
        SpellOut = 1,
        Short = 2,
        Abbreviated = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSRelativePosition`. */
    enum class RelativePosition : std::uint64_t
    {
        After = 0,
        Before = 1,
    };

    /** @brief Wraps the Objective-C option set `NSRemoteNotificationType`. Combine option sets with `|` and test them with `test_flag`. */
    enum class RemoteNotificationType : std::uint64_t
    {
        None = 0,
        Badge = 1,
        Sound = 2,
        Alert = 4,
    };

    constexpr RemoteNotificationType operator|(RemoteNotificationType a, RemoteNotificationType b)
    {
        return static_cast<RemoteNotificationType>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr RemoteNotificationType operator&(RemoteNotificationType a, RemoteNotificationType b)
    {
        return static_cast<RemoteNotificationType>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(RemoteNotificationType value, RemoteNotificationType flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSRequestUserAttentionType`. */
    enum class RequestUserAttentionType : std::uint64_t
    {
        CriticalRequest = 0,
        InformationalRequest = 10,
    };

    /** @brief Wraps the Objective-C enumeration `NSRoundingMode`. */
    enum class RoundingMode : std::uint64_t
    {
        Plain = 0,
        Down = 1,
        Up = 2,
        Bankers = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSRuleEditorNestingMode`. */
    enum class RuleEditorNestingMode : std::uint64_t
    {
        Single = 0,
        List = 1,
        Compound = 2,
        Simple = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSRuleEditorRowType`. */
    enum class RuleEditorRowType : std::uint64_t
    {
        Simple = 0,
        Compound = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSRulerOrientation`. */
    enum class RulerOrientation : std::uint64_t
    {
        HorizontalRuler = 0,
        VerticalRuler = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSSaveOperationType`. */
    enum class SaveOperationType : std::uint64_t
    {
        SaveOperation = 0,
        SaveAsOperation = 1,
        SaveToOperation = 2,
        AutosaveInPlaceOperation = 4,
        AutosaveElsewhereOperation = 3,
        AutosaveAsOperation = 5,
        AutosaveOperation = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSSaveOptions`. */
    enum class SaveOptions : std::uint64_t
    {
        Yes = 0,
        No = 1,
        Ask = 2,
    };

    /** @brief Wraps the Objective-C option set `NSScreenTouchCapabilities`. Combine option sets with `|` and test them with `test_flag`. */
    enum class ScreenTouchCapabilities : std::uint64_t
    {
        None = 0,
        MultiTouch = 1,
    };

    constexpr ScreenTouchCapabilities operator|(ScreenTouchCapabilities a, ScreenTouchCapabilities b)
    {
        return static_cast<ScreenTouchCapabilities>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr ScreenTouchCapabilities operator&(ScreenTouchCapabilities a, ScreenTouchCapabilities b)
    {
        return static_cast<ScreenTouchCapabilities>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(ScreenTouchCapabilities value, ScreenTouchCapabilities flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSScrollElasticity`. */
    enum class ScrollElasticity : std::int64_t
    {
        Automatic = 0,
        None = 1,
        Allowed = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSScrollViewFindBarPosition`. */
    enum class ScrollViewFindBarPosition : std::int64_t
    {
        AboveHorizontalRuler = 0,
        AboveContent = 1,
        BelowContent = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSScrollerKnobStyle`. */
    enum class ScrollerKnobStyle : std::int64_t
    {
        Default = 0,
        Dark = 1,
        Light = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSScrollerPart`. */
    enum class ScrollerPart : std::uint64_t
    {
        NoPart = 0,
        DecrementPage = 1,
        Knob = 2,
        IncrementPage = 3,
        DecrementLine = 4,
        IncrementLine = 5,
        KnobSlot = 6,
    };

    /** @brief Wraps the Objective-C enumeration `NSScrollerStyle`. */
    enum class ScrollerStyle : std::int64_t
    {
        Legacy = 0,
        Overlay = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSScrubberAlignment`. */
    enum class ScrubberAlignment : std::int64_t
    {
        None = 0,
        Leading = 1,
        Trailing = 2,
        Center = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSScrubberMode`. */
    enum class ScrubberMode : std::int64_t
    {
        Fixed = 0,
        Free = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSSearchPathDirectory`. */
    enum class SearchPathDirectory : std::uint64_t
    {
        ApplicationDirectory = 1,
        DemoApplicationDirectory = 2,
        DeveloperApplicationDirectory = 3,
        AdminApplicationDirectory = 4,
        LibraryDirectory = 5,
        DeveloperDirectory = 6,
        UserDirectory = 7,
        DocumentationDirectory = 8,
        DocumentDirectory = 9,
        CoreServiceDirectory = 10,
        AutosavedInformationDirectory = 11,
        DesktopDirectory = 12,
        CachesDirectory = 13,
        ApplicationSupportDirectory = 14,
        DownloadsDirectory = 15,
        InputMethodsDirectory = 16,
        MoviesDirectory = 17,
        MusicDirectory = 18,
        PicturesDirectory = 19,
        PrinterDescriptionDirectory = 20,
        SharedPublicDirectory = 21,
        PreferencePanesDirectory = 22,
        ApplicationScriptsDirectory = 23,
        ItemReplacementDirectory = 99,
        AllApplicationsDirectory = 100,
        AllLibrariesDirectory = 101,
        TrashDirectory = 102,
    };

    /** @brief Wraps the Objective-C option set `NSSearchPathDomainMask`. Combine option sets with `|` and test them with `test_flag`. */
    enum class SearchPathDomainMask : std::uint64_t
    {
        UserDomainMask = 1,
        LocalDomainMask = 2,
        NetworkDomainMask = 4,
        SystemDomainMask = 8,
        AllDomainsMask = 65535,
    };

    constexpr SearchPathDomainMask operator|(SearchPathDomainMask a, SearchPathDomainMask b)
    {
        return static_cast<SearchPathDomainMask>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr SearchPathDomainMask operator&(SearchPathDomainMask a, SearchPathDomainMask b)
    {
        return static_cast<SearchPathDomainMask>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(SearchPathDomainMask value, SearchPathDomainMask flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSSegmentDistribution`. */
    enum class SegmentDistribution : std::int64_t
    {
        Fit = 0,
        Fill = 1,
        FillEqually = 2,
        FillProportionally = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSSegmentStyle`. */
    enum class SegmentStyle : std::int64_t
    {
        Automatic = 0,
        Rounded = 1,
        RoundRect = 3,
        TexturedSquare = 4,
        SmallSquare = 6,
        Separated = 8,
        TexturedRounded = 2,
        Capsule = 5,
    };

    /** @brief Wraps the Objective-C enumeration `NSSegmentSwitchTracking`. */
    enum class SegmentSwitchTracking : std::uint64_t
    {
        SelectOne = 0,
        SelectAny = 1,
        Momentary = 2,
        MomentaryAccelerator = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSSegmentedControlRole`. */
    enum class SegmentedControlRole : std::int64_t
    {
        Automatic = 0,
        Tabs = 1,
        ValueSelection = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSSelectionAffinity`. */
    enum class SelectionAffinity : std::uint64_t
    {
        Upstream = 0,
        Downstream = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSSelectionDirection`. */
    enum class SelectionDirection : std::uint64_t
    {
        DirectSelection = 0,
        SelectingNext = 1,
        SelectingPrevious = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSSelectionGranularity`. */
    enum class SelectionGranularity : std::uint64_t
    {
        Character = 0,
        Word = 1,
        Paragraph = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSSharingCollaborationMode`. */
    enum class SharingCollaborationMode : std::int64_t
    {
        SendCopy = 0,
        Collaborate = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSSharingContentScope`. */
    enum class SharingContentScope : std::int64_t
    {
        Item = 0,
        Partial = 1,
        Full = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSSliderType`. */
    enum class SliderType : std::uint64_t
    {
        Linear = 0,
        Circular = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSSpeechBoundary`. */
    enum class SpeechBoundary : std::uint64_t
    {
        ImmediateBoundary = 0,
        WordBoundary = 1,
        SentenceBoundary = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSSplitViewDividerStyle`. */
    enum class DividerStyle : std::int64_t
    {
        Thick = 1,
        Thin = 2,
        PaneSplitter = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSSplitViewItemBehavior`. */
    enum class SplitViewItemBehavior : std::int64_t
    {
        Default = 0,
        Sidebar = 1,
        ContentList = 2,
        Inspector = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSSplitViewItemCollapseBehavior`. */
    enum class SplitViewItemCollapseBehavior : std::int64_t
    {
        Default = 0,
        PreferResizingSplitViewWithFixedSiblings = 1,
        PreferResizingSiblingsWithFixedSplitView = 2,
        UseConstraints = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSStackViewDistribution`. */
    enum class StackViewDistribution : std::int64_t
    {
        GravityAreas = -1,
        Fill = 0,
        FillEqually = 1,
        FillProportionally = 2,
        EqualSpacing = 3,
        EqualCentering = 4,
    };

    /** @brief Wraps the Objective-C enumeration `NSStackViewGravity`. */
    enum class StackViewGravity : std::int64_t
    {
        Top = 1,
        Leading = 1,
        Center = 2,
        Bottom = 3,
        Trailing = 3,
    };

    /** @brief Wraps the Objective-C option set `NSStatusItemBehavior`. Combine option sets with `|` and test them with `test_flag`. */
    enum class StatusItemBehavior : std::uint64_t
    {
        RemovalAllowed = 2,
        TerminationOnRemoval = 4,
    };

    constexpr StatusItemBehavior operator|(StatusItemBehavior a, StatusItemBehavior b)
    {
        return static_cast<StatusItemBehavior>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr StatusItemBehavior operator&(StatusItemBehavior a, StatusItemBehavior b)
    {
        return static_cast<StatusItemBehavior>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(StatusItemBehavior value, StatusItemBehavior flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSStreamEvent`. Combine option sets with `|` and test them with `test_flag`. */
    enum class StreamEvent : std::uint64_t
    {
        None = 0,
        OpenCompleted = 1,
        HasBytesAvailable = 2,
        HasSpaceAvailable = 4,
        ErrorOccurred = 8,
        EndEncountered = 16,
    };

    constexpr StreamEvent operator|(StreamEvent a, StreamEvent b)
    {
        return static_cast<StreamEvent>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr StreamEvent operator&(StreamEvent a, StreamEvent b)
    {
        return static_cast<StreamEvent>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(StreamEvent value, StreamEvent flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSStreamStatus`. */
    enum class StreamStatus : std::uint64_t
    {
        NotOpen = 0,
        Opening = 1,
        Open = 2,
        Reading = 3,
        Writing = 4,
        AtEnd = 5,
        Closed = 6,
        Error = 7,
    };

    /** @brief Wraps the Objective-C option set `NSStringDrawingOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class StringDrawingOptions : std::int64_t
    {
        UsesLineFragmentOrigin = 1,
        UsesFontLeading = 2,
        UsesDeviceMetrics = 8,
        TruncatesLastVisibleLine = 32,
        OptionsResolvesNaturalAlignmentWithBaseWritingDirection = 512,
        DisableScreenFontSubstitution = 4,
        OneShot = 16,
    };

    constexpr StringDrawingOptions operator|(StringDrawingOptions a, StringDrawingOptions b)
    {
        return static_cast<StringDrawingOptions>(static_cast<std::int64_t>(a) | static_cast<std::int64_t>(b));
    }
    constexpr StringDrawingOptions operator&(StringDrawingOptions a, StringDrawingOptions b)
    {
        return static_cast<StringDrawingOptions>(static_cast<std::int64_t>(a) & static_cast<std::int64_t>(b));
    }
    constexpr bool test_flag(StringDrawingOptions value, StringDrawingOptions flag)
    {
        return (static_cast<std::int64_t>(value) & static_cast<std::int64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSStringEnumerationOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class StringEnumerationOptions : std::uint64_t
    {
        ByLines = 0,
        ByParagraphs = 1,
        ByComposedCharacterSequences = 2,
        ByWords = 3,
        BySentences = 4,
        ByCaretPositions = 5,
        ByDeletionClusters = 6,
        Reverse = 256,
        SubstringNotRequired = 512,
        Localized = 1024,
    };

    constexpr StringEnumerationOptions operator|(StringEnumerationOptions a, StringEnumerationOptions b)
    {
        return static_cast<StringEnumerationOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr StringEnumerationOptions operator&(StringEnumerationOptions a, StringEnumerationOptions b)
    {
        return static_cast<StringEnumerationOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(StringEnumerationOptions value, StringEnumerationOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSTIFFCompression`. */
    enum class TIFFCompression : std::uint64_t
    {
        None = 1,
        CCITTFAX3 = 3,
        CCITTFAX4 = 4,
        LZW = 5,
        JPEG = 6,
        NEXT = 32766,
        PackBits = 32773,
        OldJPEG = 32865,
    };

    /** @brief Wraps the Objective-C enumeration `NSTabPosition`. */
    enum class TabPosition : std::uint64_t
    {
        None = 0,
        Top = 1,
        Left = 2,
        Bottom = 3,
        Right = 4,
    };

    /** @brief Wraps the Objective-C enumeration `NSTabState`. */
    enum class TabState : std::uint64_t
    {
        SelectedTab = 0,
        BackgroundTab = 1,
        PressedTab = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSTabViewBorderType`. */
    enum class TabViewBorderType : std::uint64_t
    {
        None = 0,
        Line = 1,
        Bezel = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSTabViewControllerTabStyle`. */
    enum class TabViewControllerTabStyle : std::int64_t
    {
        SegmentedControlOnTop = 0,
        SegmentedControlOnBottom = 1,
        Toolbar = 2,
        Unspecified = -1,
    };

    /** @brief Wraps the Objective-C enumeration `NSTabViewType`. */
    enum class TabViewType : std::uint64_t
    {
        TopTabsBezelBorder = 0,
        LeftTabsBezelBorder = 1,
        BottomTabsBezelBorder = 2,
        RightTabsBezelBorder = 3,
        NoTabsBezelBorder = 4,
        NoTabsLineBorder = 5,
        NoTabsNoBorder = 6,
    };

    /** @brief Wraps the Objective-C option set `NSTableColumnResizingOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class TableColumnResizingOptions : std::uint64_t
    {
        NoResizing = 0,
        AutoresizingMask = 1,
        UserResizingMask = 2,
    };

    constexpr TableColumnResizingOptions operator|(TableColumnResizingOptions a, TableColumnResizingOptions b)
    {
        return static_cast<TableColumnResizingOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr TableColumnResizingOptions operator&(TableColumnResizingOptions a, TableColumnResizingOptions b)
    {
        return static_cast<TableColumnResizingOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(TableColumnResizingOptions value, TableColumnResizingOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSTableRowActionEdge`. */
    enum class TableRowActionEdge : std::int64_t
    {
        Leading = 0,
        Trailing = 1,
    };

    /** @brief Wraps the Objective-C option set `NSTableViewAnimationOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class TableViewAnimationOptions : std::uint64_t
    {
        EffectNone = 0,
        EffectFade = 1,
        EffectGap = 2,
        SlideUp = 16,
        SlideDown = 32,
        SlideLeft = 48,
        SlideRight = 64,
    };

    constexpr TableViewAnimationOptions operator|(TableViewAnimationOptions a, TableViewAnimationOptions b)
    {
        return static_cast<TableViewAnimationOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr TableViewAnimationOptions operator&(TableViewAnimationOptions a, TableViewAnimationOptions b)
    {
        return static_cast<TableViewAnimationOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(TableViewAnimationOptions value, TableViewAnimationOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSTableViewColumnAutoresizingStyle`. */
    enum class TableViewColumnAutoresizingStyle : std::uint64_t
    {
        NoColumnAutoresizing = 0,
        UniformColumnAutoresizingStyle = 1,
        SequentialColumnAutoresizingStyle = 2,
        ReverseSequentialColumnAutoresizingStyle = 3,
        LastColumnOnlyAutoresizingStyle = 4,
        FirstColumnOnlyAutoresizingStyle = 5,
    };

    /** @brief Wraps the Objective-C enumeration `NSTableViewDraggingDestinationFeedbackStyle`. */
    enum class TableViewDraggingDestinationFeedbackStyle : std::int64_t
    {
        None = -1,
        Regular = 0,
        SourceList = 1,
        Gap = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSTableViewDropOperation`. */
    enum class TableViewDropOperation : std::uint64_t
    {
        On = 0,
        Above = 1,
    };

    /** @brief Wraps the Objective-C option set `NSTableViewGridLineStyle`. Combine option sets with `|` and test them with `test_flag`. */
    enum class TableViewGridLineStyle : std::uint64_t
    {
        GridNone = 0,
        SolidVerticalGridLineMask = 1,
        SolidHorizontalGridLineMask = 2,
        DashedHorizontalGridLineMask = 8,
    };

    constexpr TableViewGridLineStyle operator|(TableViewGridLineStyle a, TableViewGridLineStyle b)
    {
        return static_cast<TableViewGridLineStyle>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr TableViewGridLineStyle operator&(TableViewGridLineStyle a, TableViewGridLineStyle b)
    {
        return static_cast<TableViewGridLineStyle>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(TableViewGridLineStyle value, TableViewGridLineStyle flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSTableViewRowActionStyle`. */
    enum class TableViewRowActionStyle : std::int64_t
    {
        Regular = 0,
        Destructive = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSTableViewRowSizeStyle`. */
    enum class TableViewRowSizeStyle : std::int64_t
    {
        Default = -1,
        Custom = 0,
        Small = 1,
        Medium = 2,
        Large = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSTableViewSelectionHighlightStyle`. */
    enum class TableViewSelectionHighlightStyle : std::int64_t
    {
        None = -1,
        Regular = 0,
        SourceList = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSTableViewStyle`. */
    enum class TableViewStyle : std::int64_t
    {
        Automatic = 0,
        FullWidth = 1,
        Inset = 2,
        SourceList = 3,
        Plain = 4,
    };

    /** @brief Wraps the Objective-C enumeration `NSTaskTerminationReason`. */
    enum class TaskTerminationReason : std::int64_t
    {
        Exit = 1,
        UncaughtSignal = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSTestComparisonOperation`. */
    enum class TestComparisonOperation : std::uint64_t
    {
        EqualToComparison = 0,
        LessThanOrEqualToComparison = 1,
        LessThanComparison = 2,
        GreaterThanOrEqualToComparison = 3,
        GreaterThanComparison = 4,
        BeginsWithComparison = 5,
        EndsWithComparison = 6,
        ContainsComparison = 7,
    };

    /** @brief Wraps the Objective-C enumeration `NSTextAlignment`. */
    enum class TextAlignment : std::int64_t
    {
        Left = 0,
        Center = 1,
        Right = 2,
        Justified = 3,
        Natural = 4,
    };

    /** @brief Wraps the Objective-C option set `NSTextAttachmentViewProviderReusePolicy`. Combine option sets with `|` and test them with `test_flag`. */
    enum class TextAttachmentViewProviderReusePolicy : std::uint64_t
    {
        OnScrollingOutOfViewport = 1,
        OnEditingInlineParagraphs = 2,
    };

    constexpr TextAttachmentViewProviderReusePolicy operator|(TextAttachmentViewProviderReusePolicy a, TextAttachmentViewProviderReusePolicy b)
    {
        return static_cast<TextAttachmentViewProviderReusePolicy>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr TextAttachmentViewProviderReusePolicy operator&(TextAttachmentViewProviderReusePolicy a, TextAttachmentViewProviderReusePolicy b)
    {
        return static_cast<TextAttachmentViewProviderReusePolicy>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(TextAttachmentViewProviderReusePolicy value, TextAttachmentViewProviderReusePolicy flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSTextBlockDimension`. */
    enum class TextBlockDimension : std::int64_t
    {
        Width = 0,
        MinimumWidth = 1,
        MaximumWidth = 2,
        Height = 4,
        MinimumHeight = 5,
        MaximumHeight = 6,
        TextBlockWidth = 0,
        TextBlockMinimumWidth = 1,
        TextBlockMaximumWidth = 2,
        TextBlockHeight = 4,
        TextBlockMinimumHeight = 5,
        TextBlockMaximumHeight = 6,
    };

    /** @brief Wraps the Objective-C enumeration `NSTextBlockLayer`. */
    enum class TextBlockLayer : std::int64_t
    {
        Padding = -1,
        Border = 0,
        Margin = 1,
        TextBlockPadding = -1,
        TextBlockBorder = 0,
        TextBlockMargin = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSTextBlockValueType`. */
    enum class TextBlockValueType : std::int64_t
    {
        Absolute = 0,
        Percentage = 1,
        TextBlockAbsoluteValueType = 0,
        TextBlockPercentageValueType = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSTextBlockVerticalAlignment`. */
    enum class TextBlockVerticalAlignment : std::int64_t
    {
        Top = 0,
        Middle = 1,
        Bottom = 2,
        Baseline = 3,
        TextBlockTopAlignment = 0,
        TextBlockMiddleAlignment = 1,
        TextBlockBottomAlignment = 2,
        TextBlockBaselineAlignment = 3,
    };

    /** @brief Wraps the Objective-C option set `NSTextCheckingType`. Combine option sets with `|` and test them with `test_flag`. */
    enum class TextCheckingType : std::uint64_t
    {
        Orthography = 1,
        Spelling = 2,
        Grammar = 4,
        Date = 8,
        Address = 16,
        Link = 32,
        Quote = 64,
        Dash = 128,
        Replacement = 256,
        Correction = 512,
        RegularExpression = 1024,
        PhoneNumber = 2048,
        TransitInformation = 4096,
    };

    constexpr TextCheckingType operator|(TextCheckingType a, TextCheckingType b)
    {
        return static_cast<TextCheckingType>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr TextCheckingType operator&(TextCheckingType a, TextCheckingType b)
    {
        return static_cast<TextCheckingType>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(TextCheckingType value, TextCheckingType flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSTextContentManagerEnumerationOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class TextContentManagerEnumerationOptions : std::uint64_t
    {
        None = 0,
        Reverse = 1,
    };

    constexpr TextContentManagerEnumerationOptions operator|(TextContentManagerEnumerationOptions a, TextContentManagerEnumerationOptions b)
    {
        return static_cast<TextContentManagerEnumerationOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr TextContentManagerEnumerationOptions operator&(TextContentManagerEnumerationOptions a, TextContentManagerEnumerationOptions b)
    {
        return static_cast<TextContentManagerEnumerationOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(TextContentManagerEnumerationOptions value, TextContentManagerEnumerationOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSTextFieldBezelStyle`. */
    enum class TextFieldBezelStyle : std::uint64_t
    {
        SquareBezel = 0,
        RoundedBezel = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSTextFinderAction`. */
    enum class TextFinderAction : std::int64_t
    {
        ShowFindInterface = 1,
        NextMatch = 2,
        PreviousMatch = 3,
        ReplaceAll = 4,
        Replace = 5,
        ReplaceAndFind = 6,
        SetSearchString = 7,
        ReplaceAllInSelection = 8,
        SelectAll = 9,
        SelectAllInSelection = 10,
        HideFindInterface = 11,
        ShowReplaceInterface = 12,
        HideReplaceInterface = 13,
    };

    /** @brief Wraps the Objective-C enumeration `NSTextInputTraitType`. */
    enum class TextInputTraitType : std::int64_t
    {
        Default = 0,
        No = 1,
        Yes = 2,
    };

    /** @brief Wraps the Objective-C option set `NSTextInsertionIndicatorAutomaticModeOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class TextInsertionIndicatorAutomaticModeOptions : std::int64_t
    {
        ShowEffectsView = 1,
        ShowWhileTracking = 2,
    };

    constexpr TextInsertionIndicatorAutomaticModeOptions operator|(TextInsertionIndicatorAutomaticModeOptions a, TextInsertionIndicatorAutomaticModeOptions b)
    {
        return static_cast<TextInsertionIndicatorAutomaticModeOptions>(static_cast<std::int64_t>(a) | static_cast<std::int64_t>(b));
    }
    constexpr TextInsertionIndicatorAutomaticModeOptions operator&(TextInsertionIndicatorAutomaticModeOptions a, TextInsertionIndicatorAutomaticModeOptions b)
    {
        return static_cast<TextInsertionIndicatorAutomaticModeOptions>(static_cast<std::int64_t>(a) & static_cast<std::int64_t>(b));
    }
    constexpr bool test_flag(TextInsertionIndicatorAutomaticModeOptions value, TextInsertionIndicatorAutomaticModeOptions flag)
    {
        return (static_cast<std::int64_t>(value) & static_cast<std::int64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSTextInsertionIndicatorDisplayMode`. */
    enum class TextInsertionIndicatorDisplayMode : std::int64_t
    {
        Automatic = 0,
        Hidden = 1,
        Visible = 2,
    };

    /** @brief Wraps the Objective-C option set `NSTextLayoutFragmentEnumerationOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class TextLayoutFragmentEnumerationOptions : std::uint64_t
    {
        None = 0,
        Reverse = 1,
        EstimatesSize = 2,
        EnsuresLayout = 4,
        EnsuresExtraLineFragment = 8,
    };

    constexpr TextLayoutFragmentEnumerationOptions operator|(TextLayoutFragmentEnumerationOptions a, TextLayoutFragmentEnumerationOptions b)
    {
        return static_cast<TextLayoutFragmentEnumerationOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr TextLayoutFragmentEnumerationOptions operator&(TextLayoutFragmentEnumerationOptions a, TextLayoutFragmentEnumerationOptions b)
    {
        return static_cast<TextLayoutFragmentEnumerationOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(TextLayoutFragmentEnumerationOptions value, TextLayoutFragmentEnumerationOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSTextLayoutFragmentState`. */
    enum class TextLayoutFragmentState : std::uint64_t
    {
        None = 0,
        EstimatedUsageBounds = 1,
        CalculatedUsageBounds = 2,
        LayoutAvailable = 3,
    };

    /** @brief Wraps the Objective-C option set `NSTextLayoutManagerSegmentOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class TextLayoutManagerSegmentOptions : std::uint64_t
    {
        None = 0,
        RangeNotRequired = 1,
        MiddleFragmentsExcluded = 2,
        HeadSegmentExtended = 4,
        TailSegmentExtended = 8,
        UpstreamAffinity = 16,
    };

    constexpr TextLayoutManagerSegmentOptions operator|(TextLayoutManagerSegmentOptions a, TextLayoutManagerSegmentOptions b)
    {
        return static_cast<TextLayoutManagerSegmentOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr TextLayoutManagerSegmentOptions operator&(TextLayoutManagerSegmentOptions a, TextLayoutManagerSegmentOptions b)
    {
        return static_cast<TextLayoutManagerSegmentOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(TextLayoutManagerSegmentOptions value, TextLayoutManagerSegmentOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSTextLayoutManagerSegmentType`. */
    enum class TextLayoutManagerSegmentType : std::int64_t
    {
        Standard = 0,
        Selection = 1,
        Highlight = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSTextLayoutOrientation`. */
    enum class TextLayoutOrientation : std::int64_t
    {
        Horizontal = 0,
        Vertical = 1,
    };

    /** @brief Wraps the Objective-C option set `NSTextListOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class TextListOptions : std::uint64_t
    {
        Marker = 1,
    };

    constexpr TextListOptions operator|(TextListOptions a, TextListOptions b)
    {
        return static_cast<TextListOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr TextListOptions operator&(TextListOptions a, TextListOptions b)
    {
        return static_cast<TextListOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(TextListOptions value, TextListOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSTextSelectionAffinity`. */
    enum class TextSelectionAffinity : std::int64_t
    {
        Upstream = 0,
        Downstream = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSTextSelectionGranularity`. */
    enum class TextSelectionGranularity : std::int64_t
    {
        Character = 0,
        Word = 1,
        Paragraph = 2,
        Line = 3,
        Sentence = 4,
    };

    /** @brief Wraps the Objective-C enumeration `NSTextSelectionMode`. */
    enum class TextSelectionMode : std::int64_t
    {
        Editable = 0,
        Selectable = 1,
        NonInteractive = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSTextSelectionNavigationDestination`. */
    enum class TextSelectionNavigationDestination : std::int64_t
    {
        Character = 0,
        Word = 1,
        Line = 2,
        Sentence = 3,
        Paragraph = 4,
        Container = 5,
        Document = 6,
    };

    /** @brief Wraps the Objective-C enumeration `NSTextSelectionNavigationDirection`. */
    enum class TextSelectionNavigationDirection : std::int64_t
    {
        Forward = 0,
        Backward = 1,
        Right = 2,
        Left = 3,
        Up = 4,
        Down = 5,
    };

    /** @brief Wraps the Objective-C enumeration `NSTextSelectionNavigationLayoutOrientation`. */
    enum class TextSelectionNavigationLayoutOrientation : std::int64_t
    {
        Horizontal = 0,
        Vertical = 1,
    };

    /** @brief Wraps the Objective-C option set `NSTextSelectionNavigationModifier`. Combine option sets with `|` and test them with `test_flag`. */
    enum class TextSelectionNavigationModifier : std::uint64_t
    {
        Extend = 1,
        Visual = 2,
        Multiple = 4,
    };

    constexpr TextSelectionNavigationModifier operator|(TextSelectionNavigationModifier a, TextSelectionNavigationModifier b)
    {
        return static_cast<TextSelectionNavigationModifier>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr TextSelectionNavigationModifier operator&(TextSelectionNavigationModifier a, TextSelectionNavigationModifier b)
    {
        return static_cast<TextSelectionNavigationModifier>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(TextSelectionNavigationModifier value, TextSelectionNavigationModifier flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSTextSelectionNavigationWritingDirection`. */
    enum class TextSelectionNavigationWritingDirection : std::int64_t
    {
        LeftToRight = 0,
        RightToLeft = 1,
    };

    /** @brief Wraps the Objective-C option set `NSTextStorageEditActions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class TextStorageEditActions : std::uint64_t
    {
        Attributes = 1,
        Characters = 2,
    };

    constexpr TextStorageEditActions operator|(TextStorageEditActions a, TextStorageEditActions b)
    {
        return static_cast<TextStorageEditActions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr TextStorageEditActions operator&(TextStorageEditActions a, TextStorageEditActions b)
    {
        return static_cast<TextStorageEditActions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(TextStorageEditActions value, TextStorageEditActions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSTextTabType`. */
    enum class TextTabType : std::uint64_t
    {
        LeftTabStopType = 0,
        RightTabStopType = 1,
        CenterTabStopType = 2,
        DecimalTabStopType = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSTextTableLayoutAlgorithm`. */
    enum class TextTableLayoutAlgorithm : std::int64_t
    {
        Automatic = 0,
        Fixed = 1,
        TextTableAutomaticLayoutAlgorithm = 0,
        TextTableFixedLayoutAlgorithm = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSTickMarkPosition`. */
    enum class TickMarkPosition : std::uint64_t
    {
        Below = 0,
        Above = 1,
        Leading = 1,
        Trailing = 0,
    };

    /** @brief Wraps the Objective-C enumeration `NSTimeZoneNameStyle`. */
    enum class TimeZoneNameStyle : std::int64_t
    {
        Standard = 0,
        ShortStandard = 1,
        DaylightSaving = 2,
        ShortDaylightSaving = 3,
        Generic = 4,
        ShortGeneric = 5,
    };

    /** @brief Wraps the Objective-C enumeration `NSTintProminence`. */
    enum class TintProminence : std::int64_t
    {
        Automatic = 0,
        None = 1,
        Primary = 2,
        Secondary = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSTitlePosition`. */
    enum class TitlePosition : std::uint64_t
    {
        NoTitle = 0,
        AboveTop = 1,
        AtTop = 2,
        BelowTop = 3,
        AboveBottom = 4,
        AtBottom = 5,
        BelowBottom = 6,
    };

    /** @brief Wraps the Objective-C enumeration `NSTitlebarSeparatorStyle`. */
    enum class TitlebarSeparatorStyle : std::int64_t
    {
        Automatic = 0,
        None = 1,
        Line = 2,
        Shadow = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSTokenStyle`. */
    enum class TokenStyle : std::uint64_t
    {
        Default = 0,
        None = 1,
        Rounded = 2,
        Squared = 3,
        PlainSquared = 4,
    };

    /** @brief Wraps the Objective-C enumeration `NSToolbarDisplayMode`. */
    enum class ToolbarDisplayMode : std::uint64_t
    {
        Default = 0,
        IconAndLabel = 1,
        IconOnly = 2,
        LabelOnly = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSToolbarItemGroupControlRepresentation`. */
    enum class ToolbarItemGroupControlRepresentation : std::int64_t
    {
        Automatic = 0,
        Expanded = 1,
        Collapsed = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSToolbarItemGroupRole`. */
    enum class ToolbarItemGroupRole : std::int64_t
    {
        Automatic = 0,
        Tabs = 1,
        ValueSelection = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSToolbarItemGroupSelectionMode`. */
    enum class ToolbarItemGroupSelectionMode : std::int64_t
    {
        SelectOne = 0,
        SelectAny = 1,
        Momentary = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSToolbarItemStyle`. */
    enum class ToolbarItemStyle : std::int64_t
    {
        Plain = 0,
        Prominent = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSToolbarSizeMode`. */
    enum class ToolbarSizeMode : std::uint64_t
    {
        Default = 0,
        Regular = 1,
        Small = 2,
    };

    /** @brief Wraps the Objective-C option set `NSTouchPhase`. Combine option sets with `|` and test them with `test_flag`. */
    enum class TouchPhase : std::uint64_t
    {
        Began = 1,
        Moved = 2,
        Stationary = 4,
        Ended = 8,
        Cancelled = 16,
        Touching = 7,
        Any = 18446744073709551615ULL,
    };

    constexpr TouchPhase operator|(TouchPhase a, TouchPhase b)
    {
        return static_cast<TouchPhase>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr TouchPhase operator&(TouchPhase a, TouchPhase b)
    {
        return static_cast<TouchPhase>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(TouchPhase value, TouchPhase flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSTouchType`. */
    enum class TouchType : std::int64_t
    {
        Direct = 0,
        Indirect = 1,
    };

    /** @brief Wraps the Objective-C option set `NSTouchTypeMask`. Combine option sets with `|` and test them with `test_flag`. */
    enum class TouchTypeMask : std::uint64_t
    {
        Direct = 1,
        Indirect = 2,
    };

    constexpr TouchTypeMask operator|(TouchTypeMask a, TouchTypeMask b)
    {
        return static_cast<TouchTypeMask>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr TouchTypeMask operator&(TouchTypeMask a, TouchTypeMask b)
    {
        return static_cast<TouchTypeMask>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(TouchTypeMask value, TouchTypeMask flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSTrackingAreaOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class TrackingAreaOptions : std::uint64_t
    {
        MouseEnteredAndExited = 1,
        MouseMoved = 2,
        CursorUpdate = 4,
        ActiveWhenFirstResponder = 16,
        ActiveInKeyWindow = 32,
        ActiveInActiveApp = 64,
        ActiveAlways = 128,
        AssumeInside = 256,
        InVisibleRect = 512,
        EnabledDuringMouseDrag = 1024,
    };

    constexpr TrackingAreaOptions operator|(TrackingAreaOptions a, TrackingAreaOptions b)
    {
        return static_cast<TrackingAreaOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr TrackingAreaOptions operator&(TrackingAreaOptions a, TrackingAreaOptions b)
    {
        return static_cast<TrackingAreaOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(TrackingAreaOptions value, TrackingAreaOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSTypesetterBehavior`. */
    enum class TypesetterBehavior : std::int64_t
    {
        TypesetterLatestBehavior = -1,
        TypesetterOriginalBehavior = 0,
        _10_2_WithCompatibility = 1,
        _10_2 = 2,
        _10_3 = 3,
        _10_4 = 4,
    };

    /** @brief Wraps the Objective-C option set `NSTypesetterControlCharacterAction`. Combine option sets with `|` and test them with `test_flag`. */
    enum class TypesetterControlCharacterAction : std::uint64_t
    {
        ZeroAdvancementAction = 1,
        WhitespaceAction = 2,
        HorizontalTabAction = 4,
        LineBreakAction = 8,
        ParagraphBreakAction = 16,
        ContainerBreakAction = 32,
    };

    constexpr TypesetterControlCharacterAction operator|(TypesetterControlCharacterAction a, TypesetterControlCharacterAction b)
    {
        return static_cast<TypesetterControlCharacterAction>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr TypesetterControlCharacterAction operator&(TypesetterControlCharacterAction a, TypesetterControlCharacterAction b)
    {
        return static_cast<TypesetterControlCharacterAction>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(TypesetterControlCharacterAction value, TypesetterControlCharacterAction flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSURLBookmarkCreationOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class URLBookmarkCreationOptions : std::uint64_t
    {
        PreferFileIDResolution = 256,
        MinimalBookmark = 512,
        SuitableForBookmarkFile = 1024,
        WithSecurityScope = 2048,
        SecurityScopeAllowOnlyReadAccess = 4096,
        WithoutImplicitSecurityScope = 536870912,
    };

    constexpr URLBookmarkCreationOptions operator|(URLBookmarkCreationOptions a, URLBookmarkCreationOptions b)
    {
        return static_cast<URLBookmarkCreationOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr URLBookmarkCreationOptions operator&(URLBookmarkCreationOptions a, URLBookmarkCreationOptions b)
    {
        return static_cast<URLBookmarkCreationOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(URLBookmarkCreationOptions value, URLBookmarkCreationOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSURLBookmarkResolutionOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class URLBookmarkResolutionOptions : std::uint64_t
    {
        WithoutUI = 256,
        WithoutMounting = 512,
        WithSecurityScope = 1024,
        WithoutImplicitStartAccessing = 32768,
    };

    constexpr URLBookmarkResolutionOptions operator|(URLBookmarkResolutionOptions a, URLBookmarkResolutionOptions b)
    {
        return static_cast<URLBookmarkResolutionOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr URLBookmarkResolutionOptions operator&(URLBookmarkResolutionOptions a, URLBookmarkResolutionOptions b)
    {
        return static_cast<URLBookmarkResolutionOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(URLBookmarkResolutionOptions value, URLBookmarkResolutionOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSURLCacheStoragePolicy`. */
    enum class URLCacheStoragePolicy : std::uint64_t
    {
        Allowed = 0,
        AllowedInMemoryOnly = 1,
        NotAllowed = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSURLCredentialPersistence`. */
    enum class URLCredentialPersistence : std::uint64_t
    {
        None = 0,
        ForSession = 1,
        Permanent = 2,
        Synchronizable = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSURLRelationship`. */
    enum class URLRelationship : std::int64_t
    {
        Contains = 0,
        Same = 1,
        Other = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSURLRequestAttribution`. */
    enum class URLRequestAttribution : std::uint64_t
    {
        Developer = 0,
        User = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSURLRequestCachePolicy`. */
    enum class URLRequestCachePolicy : std::uint64_t
    {
        UseProtocolCachePolicy = 0,
        ReloadIgnoringLocalCacheData = 1,
        ReloadIgnoringLocalAndRemoteCacheData = 4,
        ReloadIgnoringCacheData = 1,
        ReturnCacheDataElseLoad = 2,
        ReturnCacheDataDontLoad = 3,
        ReloadRevalidatingCacheData = 5,
    };

    /** @brief Wraps the Objective-C enumeration `NSURLRequestNetworkServiceType`. */
    enum class URLRequestNetworkServiceType : std::uint64_t
    {
        Default = 0,
        VoIP = 1,
        Video = 2,
        Background = 3,
        Voice = 4,
        ResponsiveData = 6,
        AVStreaming = 8,
        ResponsiveAV = 9,
        CallSignaling = 11,
    };

    /** @brief Wraps the Objective-C enumeration `NSURLSessionAuthChallengeDisposition`. */
    enum class URLSessionAuthChallengeDisposition : std::int64_t
    {
        UseCredential = 0,
        PerformDefaultHandling = 1,
        CancelAuthenticationChallenge = 2,
        RejectProtectionSpace = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSURLSessionDelayedRequestDisposition`. */
    enum class URLSessionDelayedRequestDisposition : std::int64_t
    {
        ContinueLoading = 0,
        UseNewRequest = 1,
        Cancel = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSURLSessionTaskMetricsDomainResolutionProtocol`. */
    enum class URLSessionTaskMetricsDomainResolutionProtocol : std::int64_t
    {
        Unknown = 0,
        UDP = 1,
        TCP = 2,
        TLS = 3,
        HTTPS = 4,
    };

    /** @brief Wraps the Objective-C enumeration `NSURLSessionTaskMetricsResourceFetchType`. */
    enum class URLSessionTaskMetricsResourceFetchType : std::int64_t
    {
        Unknown = 0,
        NetworkLoad = 1,
        ServerPush = 2,
        LocalCache = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSURLSessionTaskState`. */
    enum class URLSessionTaskState : std::int64_t
    {
        Running = 0,
        Suspended = 1,
        Canceling = 2,
        Completed = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSURLSessionWebSocketCloseCode`. */
    enum class URLSessionWebSocketCloseCode : std::int64_t
    {
        Invalid = 0,
        NormalClosure = 1000,
        GoingAway = 1001,
        ProtocolError = 1002,
        UnsupportedData = 1003,
        NoStatusReceived = 1005,
        AbnormalClosure = 1006,
        InvalidFramePayloadData = 1007,
        PolicyViolation = 1008,
        MessageTooBig = 1009,
        MandatoryExtensionMissing = 1010,
        InternalServerError = 1011,
        TLSHandshakeFailure = 1015,
    };

    /** @brief Wraps the Objective-C enumeration `NSURLSessionWebSocketMessageType`. */
    enum class URLSessionWebSocketMessageType : std::int64_t
    {
        Data = 0,
        String = 1,
    };

    /** @brief Wraps the Objective-C option set `NSUnderlineStyle`. Combine option sets with `|` and test them with `test_flag`. */
    enum class UnderlineStyle : std::int64_t
    {
        None = 0,
        Single = 1,
        Thick = 2,
        Double = 9,
        PatternSolid = 0,
        PatternDot = 256,
        PatternDash = 512,
        PatternDashDot = 768,
        PatternDashDotDot = 1024,
        ByWord = 32768,
    };

    constexpr UnderlineStyle operator|(UnderlineStyle a, UnderlineStyle b)
    {
        return static_cast<UnderlineStyle>(static_cast<std::int64_t>(a) | static_cast<std::int64_t>(b));
    }
    constexpr UnderlineStyle operator&(UnderlineStyle a, UnderlineStyle b)
    {
        return static_cast<UnderlineStyle>(static_cast<std::int64_t>(a) & static_cast<std::int64_t>(b));
    }
    constexpr bool test_flag(UnderlineStyle value, UnderlineStyle flag)
    {
        return (static_cast<std::int64_t>(value) & static_cast<std::int64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSUsableScrollerParts`. */
    enum class UsableScrollerParts : std::uint64_t
    {
        NoScrollerParts = 0,
        OnlyScrollerArrows = 1,
        AllScrollerParts = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSUserInterfaceLayoutDirection`. */
    enum class UserInterfaceLayoutDirection : std::int64_t
    {
        LeftToRight = 0,
        RightToLeft = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSUserInterfaceLayoutOrientation`. */
    enum class Orientation : std::int64_t
    {
        Horizontal = 0,
        Vertical = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSUserNotificationActivationType`. */
    enum class UserNotificationActivationType : std::int64_t
    {
        None = 0,
        ContentsClicked = 1,
        ActionButtonClicked = 2,
        Replied = 3,
        AdditionalActionClicked = 4,
    };

    /** @brief Wraps the Objective-C option set `NSVerticalDirections`. Combine option sets with `|` and test them with `test_flag`. */
    enum class VerticalDirections : std::uint64_t
    {
        Up = 1,
        Down = 2,
        All = 3,
    };

    constexpr VerticalDirections operator|(VerticalDirections a, VerticalDirections b)
    {
        return static_cast<VerticalDirections>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr VerticalDirections operator&(VerticalDirections a, VerticalDirections b)
    {
        return static_cast<VerticalDirections>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(VerticalDirections value, VerticalDirections flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSViewControllerTransitionOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class ViewControllerTransitionOptions : std::uint64_t
    {
        None = 0,
        Crossfade = 1,
        SlideUp = 16,
        SlideDown = 32,
        SlideLeft = 64,
        SlideRight = 128,
        SlideForward = 320,
        SlideBackward = 384,
        AllowUserInteraction = 4096,
    };

    constexpr ViewControllerTransitionOptions operator|(ViewControllerTransitionOptions a, ViewControllerTransitionOptions b)
    {
        return static_cast<ViewControllerTransitionOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr ViewControllerTransitionOptions operator&(ViewControllerTransitionOptions a, ViewControllerTransitionOptions b)
    {
        return static_cast<ViewControllerTransitionOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(ViewControllerTransitionOptions value, ViewControllerTransitionOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSViewExclusiveGestureBehavior`. */
    enum class ViewExclusiveGestureBehavior : std::int64_t
    {
        Inherit = 0,
        Exclusive = 1,
        NotExclusive = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSViewLayerContentsPlacement`. */
    enum class ViewLayerContentsPlacement : std::int64_t
    {
        ScaleAxesIndependently = 0,
        ScaleProportionallyToFit = 1,
        ScaleProportionallyToFill = 2,
        Center = 3,
        Top = 4,
        TopRight = 5,
        Right = 6,
        BottomRight = 7,
        Bottom = 8,
        BottomLeft = 9,
        Left = 10,
        TopLeft = 11,
    };

    /** @brief Wraps the Objective-C enumeration `NSViewLayerContentsRedrawPolicy`. */
    enum class ViewLayerContentsRedrawPolicy : std::int64_t
    {
        Never = 0,
        OnSetNeedsDisplay = 1,
        DuringViewResize = 2,
        BeforeViewResize = 3,
        Crossfade = 4,
    };

    /** @brief Wraps the Objective-C enumeration `NSViewLayoutRegionAdaptivityAxis`. */
    enum class ViewLayoutRegionAdaptivityAxis : std::int64_t
    {
        None = 0,
        Horizontal = 1,
        Vertical = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSVisualEffectBlendingMode`. */
    enum class VisualEffectBlendingMode : std::int64_t
    {
        BehindWindow = 0,
        WithinWindow = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSVisualEffectMaterial`. */
    enum class VisualEffectMaterial : std::int64_t
    {
        Titlebar = 3,
        Selection = 4,
        Menu = 5,
        Popover = 6,
        Sidebar = 7,
        HeaderView = 10,
        Sheet = 11,
        WindowBackground = 12,
        HUDWindow = 13,
        FullScreenUI = 15,
        ToolTip = 17,
        ContentBackground = 18,
        UnderWindowBackground = 21,
        UnderPageBackground = 22,
        AppearanceBased = 0,
        Light = 1,
        Dark = 2,
        MediumLight = 8,
        UltraDark = 9,
    };

    /** @brief Wraps the Objective-C enumeration `NSVisualEffectState`. */
    enum class VisualEffectState : std::int64_t
    {
        FollowsWindowActiveState = 0,
        Active = 1,
        Inactive = 2,
    };

    /** @brief Wraps the Objective-C option set `NSVolumeEnumerationOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class VolumeEnumerationOptions : std::uint64_t
    {
        SkipHiddenVolumes = 2,
        ProduceFileReferenceURLs = 4,
    };

    constexpr VolumeEnumerationOptions operator|(VolumeEnumerationOptions a, VolumeEnumerationOptions b)
    {
        return static_cast<VolumeEnumerationOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr VolumeEnumerationOptions operator&(VolumeEnumerationOptions a, VolumeEnumerationOptions b)
    {
        return static_cast<VolumeEnumerationOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(VolumeEnumerationOptions value, VolumeEnumerationOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSWhoseSubelementIdentifier`. */
    enum class WhoseSubelementIdentifier : std::uint64_t
    {
        IndexSubelement = 0,
        EverySubelement = 1,
        MiddleSubelement = 2,
        RandomSubelement = 3,
        NoSubelement = 4,
    };

    /** @brief Wraps the Objective-C enumeration `NSWindingRule`. */
    enum class WindingRule : std::uint64_t
    {
        NonZero = 0,
        EvenOdd = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSWindowAnimationBehavior`. */
    enum class WindowAnimationBehavior : std::int64_t
    {
        Default = 0,
        None = 2,
        DocumentWindow = 3,
        UtilityWindow = 4,
        AlertPanel = 5,
    };

    /** @brief Wraps the Objective-C enumeration `NSWindowButton`. */
    enum class WindowButton : std::uint64_t
    {
        CloseButton = 0,
        MiniaturizeButton = 1,
        ZoomButton = 2,
        ToolbarButton = 3,
        DocumentIconButton = 4,
        DocumentVersionsButton = 6,
    };

    /** @brief Wraps the Objective-C option set `NSWindowCollectionBehavior`. Combine option sets with `|` and test them with `test_flag`. */
    enum class WindowCollectionBehavior : std::uint64_t
    {
        Default = 0,
        CanJoinAllSpaces = 1,
        MoveToActiveSpace = 2,
        Managed = 4,
        Transient = 8,
        Stationary = 16,
        ParticipatesInCycle = 32,
        IgnoresCycle = 64,
        FullScreenPrimary = 128,
        FullScreenAuxiliary = 256,
        FullScreenNone = 512,
        FullScreenAllowsTiling = 2048,
        FullScreenDisallowsTiling = 4096,
        Primary = 65536,
        Auxiliary = 131072,
        CanJoinAllApplications = 262144,
    };

    constexpr WindowCollectionBehavior operator|(WindowCollectionBehavior a, WindowCollectionBehavior b)
    {
        return static_cast<WindowCollectionBehavior>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr WindowCollectionBehavior operator&(WindowCollectionBehavior a, WindowCollectionBehavior b)
    {
        return static_cast<WindowCollectionBehavior>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(WindowCollectionBehavior value, WindowCollectionBehavior flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSWindowDepth`. */
    enum class WindowDepth : std::int32_t
    {
        TwentyfourBitRGB = 520,
        SixtyfourBitRGB = 528,
        OnehundredtwentyeightBitRGB = 544,
    };

    /** @brief Wraps the Objective-C option set `NSWindowListOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class WindowListOptions : std::int64_t
    {
        Back = 1,
    };

    constexpr WindowListOptions operator|(WindowListOptions a, WindowListOptions b)
    {
        return static_cast<WindowListOptions>(static_cast<std::int64_t>(a) | static_cast<std::int64_t>(b));
    }
    constexpr WindowListOptions operator&(WindowListOptions a, WindowListOptions b)
    {
        return static_cast<WindowListOptions>(static_cast<std::int64_t>(a) & static_cast<std::int64_t>(b));
    }
    constexpr bool test_flag(WindowListOptions value, WindowListOptions flag)
    {
        return (static_cast<std::int64_t>(value) & static_cast<std::int64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSWindowNumberListOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class WindowNumberListOptions : std::uint64_t
    {
        Applications = 1,
        Spaces = 16,
    };

    constexpr WindowNumberListOptions operator|(WindowNumberListOptions a, WindowNumberListOptions b)
    {
        return static_cast<WindowNumberListOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr WindowNumberListOptions operator&(WindowNumberListOptions a, WindowNumberListOptions b)
    {
        return static_cast<WindowNumberListOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(WindowNumberListOptions value, WindowNumberListOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C option set `NSWindowOcclusionState`. Combine option sets with `|` and test them with `test_flag`. */
    enum class WindowOcclusionState : std::uint64_t
    {
        Visible = 2,
    };

    constexpr WindowOcclusionState operator|(WindowOcclusionState a, WindowOcclusionState b)
    {
        return static_cast<WindowOcclusionState>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr WindowOcclusionState operator&(WindowOcclusionState a, WindowOcclusionState b)
    {
        return static_cast<WindowOcclusionState>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(WindowOcclusionState value, WindowOcclusionState flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSWindowOrderingMode`. */
    enum class WindowOrderingMode : std::int64_t
    {
        Above = 1,
        Below = -1,
        Out = 0,
    };

    /** @brief Wraps the Objective-C enumeration `NSWindowSharingType`. */
    enum class WindowSharingType : std::uint64_t
    {
        None = 0,
        ReadOnly = 1,
    };

    /** @brief Wraps the Objective-C option set `NSWindowStyleMask`. Combine option sets with `|` and test them with `test_flag`. */
    enum class WindowStyle : std::uint64_t
    {
        Borderless = 0,
        Titled = 1,
        Closable = 2,
        Miniaturizable = 4,
        Resizable = 8,
        TexturedBackground = 256,
        UnifiedTitleAndToolbar = 4096,
        FullScreen = 16384,
        FullSizeContentView = 32768,
        UtilityWindow = 16,
        DocModalWindow = 64,
        NonactivatingPanel = 128,
        HUDWindow = 8192,
    };

    constexpr WindowStyle operator|(WindowStyle a, WindowStyle b)
    {
        return static_cast<WindowStyle>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr WindowStyle operator&(WindowStyle a, WindowStyle b)
    {
        return static_cast<WindowStyle>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(WindowStyle value, WindowStyle flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSWindowTabbingMode`. */
    enum class WindowTabbingMode : std::int64_t
    {
        Automatic = 0,
        Preferred = 1,
        Disallowed = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSWindowTitleVisibility`. */
    enum class TitleVisibility : std::int64_t
    {
        Visible = 0,
        Hidden = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSWindowToolbarStyle`. */
    enum class ToolbarStyle : std::int64_t
    {
        Automatic = 0,
        Expanded = 1,
        Preference = 2,
        Unified = 3,
        UnifiedCompact = 4,
    };

    /** @brief Wraps the Objective-C enumeration `NSWindowUserTabbingPreference`. */
    enum class WindowUserTabbingPreference : std::int64_t
    {
        Manual = 0,
        Always = 1,
        InFullScreen = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSWorkspaceAuthorizationType`. */
    enum class WorkspaceAuthorizationType : std::int64_t
    {
        CreateSymbolicLink = 0,
        SetAttributes = 1,
        ReplaceFile = 2,
    };

    /** @brief Wraps the Objective-C option set `NSWorkspaceIconCreationOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class WorkspaceIconCreationOptions : std::uint64_t
    {
        QuickDrawElementsIconCreationOption = 2,
        _10_4ElementsIconCreationOption = 4,
    };

    constexpr WorkspaceIconCreationOptions operator|(WorkspaceIconCreationOptions a, WorkspaceIconCreationOptions b)
    {
        return static_cast<WorkspaceIconCreationOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr WorkspaceIconCreationOptions operator&(WorkspaceIconCreationOptions a, WorkspaceIconCreationOptions b)
    {
        return static_cast<WorkspaceIconCreationOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(WorkspaceIconCreationOptions value, WorkspaceIconCreationOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSWritingDirection`. */
    enum class WritingDirection : std::int64_t
    {
        Natural = -1,
        LeftToRight = 0,
        RightToLeft = 1,
    };

    /** @brief Wraps the Objective-C enumeration `NSWritingToolsBehavior`. */
    enum class WritingToolsBehavior : std::int64_t
    {
        None = -1,
        Default = 0,
        Complete = 1,
        Limited = 2,
    };

    /** @brief Wraps the Objective-C enumeration `NSWritingToolsCoordinatorState`. */
    enum class WritingToolsCoordinatorState : std::int64_t
    {
        Inactive = 0,
        Noninteractive = 1,
        InteractiveResting = 2,
        InteractiveStreaming = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSWritingToolsCoordinatorTextAnimation`. */
    enum class WritingToolsCoordinatorTextAnimation : std::int64_t
    {
        Anticipate = 0,
        Remove = 1,
        Insert = 2,
        AnticipateInactive = 8,
        Translate = 9,
        IndicateGrammar = 10,
    };

    /** @brief Wraps the Objective-C enumeration `NSWritingToolsCoordinatorTextUpdateReason`. */
    enum class WritingToolsCoordinatorTextUpdateReason : std::int64_t
    {
        Typing = 0,
        UndoRedo = 1,
    };

    /** @brief Wraps the Objective-C option set `NSWritingToolsResultOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class WritingToolsResultOptions : std::uint64_t
    {
        Default = 0,
        PlainText = 1,
        RichText = 2,
        List = 4,
        Table = 8,
        PresentationIntent = 16,
    };

    constexpr WritingToolsResultOptions operator|(WritingToolsResultOptions a, WritingToolsResultOptions b)
    {
        return static_cast<WritingToolsResultOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr WritingToolsResultOptions operator&(WritingToolsResultOptions a, WritingToolsResultOptions b)
    {
        return static_cast<WritingToolsResultOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(WritingToolsResultOptions value, WritingToolsResultOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSXMLDTDNodeKind`. */
    enum class XMLDTDNodeKind : std::uint64_t
    {
        EntityGeneralKind = 1,
        EntityParsedKind = 2,
        EntityUnparsedKind = 3,
        EntityParameterKind = 4,
        EntityPredefined = 5,
        AttributeCDATAKind = 6,
        AttributeIDKind = 7,
        AttributeIDRefKind = 8,
        AttributeIDRefsKind = 9,
        AttributeEntityKind = 10,
        AttributeEntitiesKind = 11,
        AttributeNMTokenKind = 12,
        AttributeNMTokensKind = 13,
        AttributeEnumerationKind = 14,
        AttributeNotationKind = 15,
        ElementDeclarationUndefinedKind = 16,
        ElementDeclarationEmptyKind = 17,
        ElementDeclarationAnyKind = 18,
        ElementDeclarationMixedKind = 19,
        ElementDeclarationElementKind = 20,
    };

    /** @brief Wraps the Objective-C enumeration `NSXMLDocumentContentKind`. */
    enum class XMLDocumentContentKind : std::uint64_t
    {
        XMLKind = 0,
        XHTMLKind = 1,
        HTMLKind = 2,
        TextKind = 3,
    };

    /** @brief Wraps the Objective-C enumeration `NSXMLNodeKind`. */
    enum class XMLNodeKind : std::uint64_t
    {
        InvalidKind = 0,
        DocumentKind = 1,
        ElementKind = 2,
        AttributeKind = 3,
        NamespaceKind = 4,
        ProcessingInstructionKind = 5,
        CommentKind = 6,
        TextKind = 7,
        DTDKind = 8,
        EntityDeclarationKind = 9,
        AttributeDeclarationKind = 10,
        ElementDeclarationKind = 11,
        NotationDeclarationKind = 12,
    };

    /** @brief Wraps the Objective-C option set `NSXMLNodeOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class XMLNodeOptions : std::uint64_t
    {
        NodeOptionsNone = 0,
        NodeIsCDATA = 1,
        NodeExpandEmptyElement = 2,
        NodeCompactEmptyElement = 4,
        NodeUseSingleQuotes = 8,
        NodeUseDoubleQuotes = 16,
        NodeNeverEscapeContents = 32,
        DocumentTidyHTML = 512,
        DocumentTidyXML = 1024,
        DocumentValidate = 8192,
        NodeLoadExternalEntitiesAlways = 16384,
        NodeLoadExternalEntitiesSameOriginOnly = 32768,
        NodeLoadExternalEntitiesNever = 524288,
        DocumentXInclude = 65536,
        NodePrettyPrint = 131072,
        DocumentIncludeContentTypeDeclaration = 262144,
        NodePreserveNamespaceOrder = 1048576,
        NodePreserveAttributeOrder = 2097152,
        NodePreserveEntities = 4194304,
        NodePreservePrefixes = 8388608,
        NodePreserveCDATA = 16777216,
        NodePreserveWhitespace = 33554432,
        NodePreserveDTD = 67108864,
        NodePreserveCharacterReferences = 134217728,
        NodePromoteSignificantWhitespace = 268435456,
        NodePreserveEmptyElements = 6,
        NodePreserveQuotes = 24,
        NodePreserveAll = 4293918750,
    };

    constexpr XMLNodeOptions operator|(XMLNodeOptions a, XMLNodeOptions b)
    {
        return static_cast<XMLNodeOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr XMLNodeOptions operator&(XMLNodeOptions a, XMLNodeOptions b)
    {
        return static_cast<XMLNodeOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(XMLNodeOptions value, XMLNodeOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `NSXMLParserExternalEntityResolvingPolicy`. */
    enum class XMLParserExternalEntityResolvingPolicy : std::uint64_t
    {
        Never = 0,
        NoNetwork = 1,
        SameOriginOnly = 2,
        Always = 3,
    };

    /** @brief Wraps the Objective-C option set `NSXPCConnectionOptions`. Combine option sets with `|` and test them with `test_flag`. */
    enum class XPCConnectionOptions : std::uint64_t
    {
        Privileged = 4096,
    };

    constexpr XPCConnectionOptions operator|(XPCConnectionOptions a, XPCConnectionOptions b)
    {
        return static_cast<XPCConnectionOptions>(static_cast<std::uint64_t>(a) | static_cast<std::uint64_t>(b));
    }
    constexpr XPCConnectionOptions operator&(XPCConnectionOptions a, XPCConnectionOptions b)
    {
        return static_cast<XPCConnectionOptions>(static_cast<std::uint64_t>(a) & static_cast<std::uint64_t>(b));
    }
    constexpr bool test_flag(XPCConnectionOptions value, XPCConnectionOptions flag)
    {
        return (static_cast<std::uint64_t>(value) & static_cast<std::uint64_t>(flag)) != 0;
    }

    /** @brief Wraps the Objective-C enumeration `SSLProtocol`. */
    enum class SSLProtocol : std::int32_t
    {
        kSSLProtocolUnknown = 0,
        kTLSProtocol1 = 4,
        kTLSProtocol11 = 7,
        kTLSProtocol12 = 8,
        kDTLSProtocol1 = 9,
        kTLSProtocol13 = 10,
        kDTLSProtocol12 = 11,
        kTLSProtocolMaxSupported = 999,
        kSSLProtocol2 = 1,
        kSSLProtocol3 = 2,
        kSSLProtocol3Only = 3,
        kTLSProtocol1Only = 5,
        kSSLProtocolAll = 6,
    };

    /** @brief Wraps the Objective-C enumeration `tls_protocol_version_t`. */
    enum class tls_protocol_version_t : std::uint16_t
    {
        TLSv10 = 769,
        TLSv11 = 770,
        TLSv12 = 771,
        TLSv13 = 772,
        DTLSv10 = 65279,
        DTLSv12 = 65277,
    };
}
