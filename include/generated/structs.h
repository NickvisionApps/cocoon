#pragma once

#include <cstdint>
#include "geometry.h"

namespace cocoon
{
    /** @brief Plain C++ mirror of the C structure `NSRange`. */
    struct Range
    {
        std::uint64_t location = {};
        std::uint64_t length = {};
    };

    /** @brief Opaque 32-byte blob holding a `NSDirectionalEdgeInsets` value. */
    struct alignas(8) DirectionalEdgeInsets
    {
        std::uint8_t bytes[32] = {};
    };

    /** @brief Plain C++ mirror of the C structure `CVSMPTETime`. */
    struct CVSMPTETime
    {
        std::int16_t subframes = {};
        std::int16_t subframe_divisor = {};
        unsigned int counter = {};
        unsigned int type = {};
        unsigned int flags = {};
        std::int16_t hours = {};
        std::int16_t minutes = {};
        std::int16_t seconds = {};
        std::int16_t frames = {};
    };

    /** @brief Plain C++ mirror of the C structure `CVTimeStamp`. */
    struct CVTimeStamp
    {
        unsigned int version = {};
        int video_time_scale = {};
        std::int64_t video_time = {};
        std::uint64_t host_time = {};
        double rate_scalar = {};
        std::int64_t video_refresh_period = {};
        CVSMPTETime smpte_time = {};
        std::uint64_t flags = {};
        std::uint64_t reserved = {};
    };

    /** @brief Plain C++ mirror of the C structure `NSAffineTransformStruct`. */
    struct AffineTransformStruct
    {
        double m11 = {};
        double m12 = {};
        double m21 = {};
        double m22 = {};
        double t_x = {};
        double t_y = {};
    };

    /** @brief Opaque 12-byte blob holding a `AEDesc` value. */
    struct alignas(2) AEDesc
    {
        std::uint8_t bytes[12] = {};
    };

    /** @brief Opaque 20-byte blob holding a `NSDecimal` value. */
    struct alignas(4) Decimal
    {
        std::uint8_t bytes[20] = {};
    };

    /** @brief Plain C++ mirror of the C structure `NSOperatingSystemVersion`. */
    struct OperatingSystemVersion
    {
        std::int64_t major_version = {};
        std::int64_t minor_version = {};
        std::int64_t patch_version = {};
    };

    /** @brief Opaque 128-byte blob holding a `CATransform3D` value. */
    struct alignas(8) CATransform3D
    {
        std::uint8_t bytes[128] = {};
    };

    /** @brief Plain C++ mirror of the C structure `CGAffineTransform`. */
    struct AffineTransform3
    {
        double a = {};
        double b = {};
        double c = {};
        double d = {};
        double tx = {};
        double ty = {};
    };

    /** @brief Opaque 40-byte blob holding a `NSHashTableCallBacks` value. */
    struct alignas(8) HashTableCallBacks
    {
        std::uint8_t bytes[40] = {};
    };

    /** @brief Opaque 48-byte blob holding a `NSMapTableKeyCallBacks` value. */
    struct alignas(8) MapTableKeyCallBacks
    {
        std::uint8_t bytes[48] = {};
    };

    /** @brief Opaque 24-byte blob holding a `NSMapTableValueCallBacks` value. */
    struct alignas(8) MapTableValueCallBacks
    {
        std::uint8_t bytes[24] = {};
    };
}
