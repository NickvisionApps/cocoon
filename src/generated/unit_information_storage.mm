#include "generated/unit_information_storage.h"
#include "internal.h"

namespace cocoon
{
    UnitInformationStorage::UnitInformationStorage() : Dimension(nullptr)
    {
    }

    UnitInformationStorage::UnitInformationStorage(std::nullptr_t) : Dimension(nullptr)
    {
    }

    UnitInformationStorage::UnitInformationStorage(Adopt adopt) : Dimension(adopt)
    {
    }

    UnitInformationStorage UnitInformationStorage::bits()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage bits]);
    }

    UnitInformationStorage UnitInformationStorage::bytes()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage bytes]);
    }

    UnitInformationStorage UnitInformationStorage::exabits()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage exabits]);
    }

    UnitInformationStorage UnitInformationStorage::exabytes()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage exabytes]);
    }

    UnitInformationStorage UnitInformationStorage::exbibits()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage exbibits]);
    }

    UnitInformationStorage UnitInformationStorage::exbibytes()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage exbibytes]);
    }

    UnitInformationStorage UnitInformationStorage::gibibits()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage gibibits]);
    }

    UnitInformationStorage UnitInformationStorage::gibibytes()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage gibibytes]);
    }

    UnitInformationStorage UnitInformationStorage::gigabits()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage gigabits]);
    }

    UnitInformationStorage UnitInformationStorage::gigabytes()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage gigabytes]);
    }

    UnitInformationStorage UnitInformationStorage::kibibits()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage kibibits]);
    }

    UnitInformationStorage UnitInformationStorage::kibibytes()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage kibibytes]);
    }

    UnitInformationStorage UnitInformationStorage::kilobits()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage kilobits]);
    }

    UnitInformationStorage UnitInformationStorage::kilobytes()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage kilobytes]);
    }

    UnitInformationStorage UnitInformationStorage::mebibits()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage mebibits]);
    }

    UnitInformationStorage UnitInformationStorage::mebibytes()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage mebibytes]);
    }

    UnitInformationStorage UnitInformationStorage::megabits()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage megabits]);
    }

    UnitInformationStorage UnitInformationStorage::megabytes()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage megabytes]);
    }

    UnitInformationStorage UnitInformationStorage::nibbles()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage nibbles]);
    }

    UnitInformationStorage UnitInformationStorage::pebibits()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage pebibits]);
    }

    UnitInformationStorage UnitInformationStorage::pebibytes()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage pebibytes]);
    }

    UnitInformationStorage UnitInformationStorage::petabits()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage petabits]);
    }

    UnitInformationStorage UnitInformationStorage::petabytes()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage petabytes]);
    }

    UnitInformationStorage UnitInformationStorage::tebibits()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage tebibits]);
    }

    UnitInformationStorage UnitInformationStorage::tebibytes()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage tebibytes]);
    }

    UnitInformationStorage UnitInformationStorage::terabits()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage terabits]);
    }

    UnitInformationStorage UnitInformationStorage::terabytes()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage terabytes]);
    }

    UnitInformationStorage UnitInformationStorage::yobibits()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage yobibits]);
    }

    UnitInformationStorage UnitInformationStorage::yobibytes()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage yobibytes]);
    }

    UnitInformationStorage UnitInformationStorage::yottabits()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage yottabits]);
    }

    UnitInformationStorage UnitInformationStorage::yottabytes()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage yottabytes]);
    }

    UnitInformationStorage UnitInformationStorage::zebibits()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage zebibits]);
    }

    UnitInformationStorage UnitInformationStorage::zebibytes()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage zebibytes]);
    }

    UnitInformationStorage UnitInformationStorage::zettabits()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage zettabits]);
    }

    UnitInformationStorage UnitInformationStorage::zettabytes()
    {
        return cocoon::internal::wrap<UnitInformationStorage>([::NSUnitInformationStorage zettabytes]);
    }
}
