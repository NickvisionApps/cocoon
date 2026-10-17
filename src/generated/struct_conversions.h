#pragma once

#import <AppKit/AppKit.h>
#include <cstring>
#include "generated/structs.h"

namespace cocoon::internal
{
    ::NSRange to(const cocoon::Range& value);
    cocoon::Range from(::NSRange value);
    ::NSDirectionalEdgeInsets to(const cocoon::DirectionalEdgeInsets& value);
    cocoon::DirectionalEdgeInsets from(::NSDirectionalEdgeInsets value);
    ::CVSMPTETime to(const cocoon::CVSMPTETime& value);
    cocoon::CVSMPTETime from(::CVSMPTETime value);
    ::CVTimeStamp to(const cocoon::CVTimeStamp& value);
    cocoon::CVTimeStamp from(::CVTimeStamp value);
    ::NSAffineTransformStruct to(const cocoon::AffineTransformStruct& value);
    cocoon::AffineTransformStruct from(::NSAffineTransformStruct value);
    ::AEDesc to(const cocoon::AEDesc& value);
    cocoon::AEDesc from(::AEDesc value);
    ::NSDecimal to(const cocoon::Decimal& value);
    cocoon::Decimal from(::NSDecimal value);
    ::NSOperatingSystemVersion to(const cocoon::OperatingSystemVersion& value);
    cocoon::OperatingSystemVersion from(::NSOperatingSystemVersion value);
    ::CATransform3D to(const cocoon::CATransform3D& value);
    cocoon::CATransform3D from(::CATransform3D value);
    ::CGAffineTransform to(const cocoon::AffineTransform3& value);
    cocoon::AffineTransform3 from(::CGAffineTransform value);
    ::NSHashTableCallBacks to(const cocoon::HashTableCallBacks& value);
    cocoon::HashTableCallBacks from(::NSHashTableCallBacks value);
    ::NSMapTableKeyCallBacks to(const cocoon::MapTableKeyCallBacks& value);
    cocoon::MapTableKeyCallBacks from(::NSMapTableKeyCallBacks value);
    ::NSMapTableValueCallBacks to(const cocoon::MapTableValueCallBacks& value);
    cocoon::MapTableValueCallBacks from(::NSMapTableValueCallBacks value);

    inline ::NSRange to(const cocoon::Range& value)
    {
        ::NSRange result;
        result.location = static_cast<::NSUInteger>(value.location);
        result.length = static_cast<::NSUInteger>(value.length);
        return result;
    }

    inline cocoon::Range from(::NSRange value)
    {
        cocoon::Range result;
        result.location = static_cast<std::uint64_t>(value.location);
        result.length = static_cast<std::uint64_t>(value.length);
        return result;
    }

    inline ::NSDirectionalEdgeInsets to(const cocoon::DirectionalEdgeInsets& value)
    {
        ::NSDirectionalEdgeInsets result;
        std::memcpy(&result, value.bytes, sizeof(result));
        return result;
    }

    inline cocoon::DirectionalEdgeInsets from(::NSDirectionalEdgeInsets value)
    {
        cocoon::DirectionalEdgeInsets result;
        std::memcpy(result.bytes, &value, sizeof(value));
        return result;
    }

    inline ::CVSMPTETime to(const cocoon::CVSMPTETime& value)
    {
        ::CVSMPTETime result;
        result.subframes = static_cast<::SInt16>(value.subframes);
        result.subframeDivisor = static_cast<::SInt16>(value.subframe_divisor);
        result.counter = static_cast<::UInt32>(value.counter);
        result.type = static_cast<::UInt32>(value.type);
        result.flags = static_cast<::UInt32>(value.flags);
        result.hours = static_cast<::SInt16>(value.hours);
        result.minutes = static_cast<::SInt16>(value.minutes);
        result.seconds = static_cast<::SInt16>(value.seconds);
        result.frames = static_cast<::SInt16>(value.frames);
        return result;
    }

    inline cocoon::CVSMPTETime from(::CVSMPTETime value)
    {
        cocoon::CVSMPTETime result;
        result.subframes = static_cast<std::int16_t>(value.subframes);
        result.subframe_divisor = static_cast<std::int16_t>(value.subframeDivisor);
        result.counter = static_cast<unsigned int>(value.counter);
        result.type = static_cast<unsigned int>(value.type);
        result.flags = static_cast<unsigned int>(value.flags);
        result.hours = static_cast<std::int16_t>(value.hours);
        result.minutes = static_cast<std::int16_t>(value.minutes);
        result.seconds = static_cast<std::int16_t>(value.seconds);
        result.frames = static_cast<std::int16_t>(value.frames);
        return result;
    }

    inline ::CVTimeStamp to(const cocoon::CVTimeStamp& value)
    {
        ::CVTimeStamp result;
        result.version = static_cast<::uint32_t>(value.version);
        result.videoTimeScale = static_cast<::int32_t>(value.video_time_scale);
        result.videoTime = static_cast<::int64_t>(value.video_time);
        result.hostTime = static_cast<::uint64_t>(value.host_time);
        result.rateScalar = static_cast<double>(value.rate_scalar);
        result.videoRefreshPeriod = static_cast<::int64_t>(value.video_refresh_period);
        result.smpteTime = cocoon::internal::to(value.smpte_time);
        result.flags = static_cast<::uint64_t>(value.flags);
        result.reserved = static_cast<::uint64_t>(value.reserved);
        return result;
    }

    inline cocoon::CVTimeStamp from(::CVTimeStamp value)
    {
        cocoon::CVTimeStamp result;
        result.version = static_cast<unsigned int>(value.version);
        result.video_time_scale = static_cast<int>(value.videoTimeScale);
        result.video_time = static_cast<std::int64_t>(value.videoTime);
        result.host_time = static_cast<std::uint64_t>(value.hostTime);
        result.rate_scalar = static_cast<double>(value.rateScalar);
        result.video_refresh_period = static_cast<std::int64_t>(value.videoRefreshPeriod);
        result.smpte_time = cocoon::internal::from(value.smpteTime);
        result.flags = static_cast<std::uint64_t>(value.flags);
        result.reserved = static_cast<std::uint64_t>(value.reserved);
        return result;
    }

    inline ::NSAffineTransformStruct to(const cocoon::AffineTransformStruct& value)
    {
        ::NSAffineTransformStruct result;
        result.m11 = static_cast<::CGFloat>(value.m11);
        result.m12 = static_cast<::CGFloat>(value.m12);
        result.m21 = static_cast<::CGFloat>(value.m21);
        result.m22 = static_cast<::CGFloat>(value.m22);
        result.tX = static_cast<::CGFloat>(value.t_x);
        result.tY = static_cast<::CGFloat>(value.t_y);
        return result;
    }

    inline cocoon::AffineTransformStruct from(::NSAffineTransformStruct value)
    {
        cocoon::AffineTransformStruct result;
        result.m11 = static_cast<double>(value.m11);
        result.m12 = static_cast<double>(value.m12);
        result.m21 = static_cast<double>(value.m21);
        result.m22 = static_cast<double>(value.m22);
        result.t_x = static_cast<double>(value.tX);
        result.t_y = static_cast<double>(value.tY);
        return result;
    }

    inline ::AEDesc to(const cocoon::AEDesc& value)
    {
        ::AEDesc result;
        std::memcpy(&result, value.bytes, sizeof(result));
        return result;
    }

    inline cocoon::AEDesc from(::AEDesc value)
    {
        cocoon::AEDesc result;
        std::memcpy(result.bytes, &value, sizeof(value));
        return result;
    }

    inline ::NSDecimal to(const cocoon::Decimal& value)
    {
        ::NSDecimal result;
        std::memcpy(&result, value.bytes, sizeof(result));
        return result;
    }

    inline cocoon::Decimal from(::NSDecimal value)
    {
        cocoon::Decimal result;
        std::memcpy(result.bytes, &value, sizeof(value));
        return result;
    }

    inline ::NSOperatingSystemVersion to(const cocoon::OperatingSystemVersion& value)
    {
        ::NSOperatingSystemVersion result;
        result.majorVersion = static_cast<::NSInteger>(value.major_version);
        result.minorVersion = static_cast<::NSInteger>(value.minor_version);
        result.patchVersion = static_cast<::NSInteger>(value.patch_version);
        return result;
    }

    inline cocoon::OperatingSystemVersion from(::NSOperatingSystemVersion value)
    {
        cocoon::OperatingSystemVersion result;
        result.major_version = static_cast<std::int64_t>(value.majorVersion);
        result.minor_version = static_cast<std::int64_t>(value.minorVersion);
        result.patch_version = static_cast<std::int64_t>(value.patchVersion);
        return result;
    }

    inline ::CATransform3D to(const cocoon::CATransform3D& value)
    {
        ::CATransform3D result;
        std::memcpy(&result, value.bytes, sizeof(result));
        return result;
    }

    inline cocoon::CATransform3D from(::CATransform3D value)
    {
        cocoon::CATransform3D result;
        std::memcpy(result.bytes, &value, sizeof(value));
        return result;
    }

    inline ::CGAffineTransform to(const cocoon::AffineTransform3& value)
    {
        ::CGAffineTransform result;
        result.a = static_cast<::CGFloat>(value.a);
        result.b = static_cast<::CGFloat>(value.b);
        result.c = static_cast<::CGFloat>(value.c);
        result.d = static_cast<::CGFloat>(value.d);
        result.tx = static_cast<::CGFloat>(value.tx);
        result.ty = static_cast<::CGFloat>(value.ty);
        return result;
    }

    inline cocoon::AffineTransform3 from(::CGAffineTransform value)
    {
        cocoon::AffineTransform3 result;
        result.a = static_cast<double>(value.a);
        result.b = static_cast<double>(value.b);
        result.c = static_cast<double>(value.c);
        result.d = static_cast<double>(value.d);
        result.tx = static_cast<double>(value.tx);
        result.ty = static_cast<double>(value.ty);
        return result;
    }

    inline ::NSHashTableCallBacks to(const cocoon::HashTableCallBacks& value)
    {
        ::NSHashTableCallBacks result;
        std::memcpy(&result, value.bytes, sizeof(result));
        return result;
    }

    inline cocoon::HashTableCallBacks from(::NSHashTableCallBacks value)
    {
        cocoon::HashTableCallBacks result;
        std::memcpy(result.bytes, &value, sizeof(value));
        return result;
    }

    inline ::NSMapTableKeyCallBacks to(const cocoon::MapTableKeyCallBacks& value)
    {
        ::NSMapTableKeyCallBacks result;
        std::memcpy(&result, value.bytes, sizeof(result));
        return result;
    }

    inline cocoon::MapTableKeyCallBacks from(::NSMapTableKeyCallBacks value)
    {
        cocoon::MapTableKeyCallBacks result;
        std::memcpy(result.bytes, &value, sizeof(value));
        return result;
    }

    inline ::NSMapTableValueCallBacks to(const cocoon::MapTableValueCallBacks& value)
    {
        ::NSMapTableValueCallBacks result;
        std::memcpy(&result, value.bytes, sizeof(result));
        return result;
    }

    inline cocoon::MapTableValueCallBacks from(::NSMapTableValueCallBacks value)
    {
        cocoon::MapTableValueCallBacks result;
        std::memcpy(result.bytes, &value, sizeof(value));
        return result;
    }
}
