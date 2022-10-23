#pragma once

#include <string_view>

#include "for_each.h"

// MAKE_ENUM macro that creates enum class and string_view convertion function
// given enum_name, enum_type and enum entries
// NOTE: convertion function would be generated only if MAKE_CONVERTION_FUNCTION is 1
// and it should be set before inclusion of this file
// i.e. #define MAKE_CONVERTION_FUNCTION 1
//	#include "enum.h"
//
// Usage:
//	MAKE_ENUM(my_enum, uint8_t, A, B, C) -> enum class my_enum : uint8_t { A, B, C };
//	and convertion function if you opt for it
//
//	my_enum value = my_enum::A;
//	std::string_view sv = my_enum_to_sv(value);
//	static_assert(sv == "A");

#ifndef MAKE_CONVERTION_FUNCTION
#define MAKE_CONVERTION_FUNCTION 0
#endif

#define ENUM_CASE(value)                                           \
    case value: return #value##sv;

#if MAKE_CONVERTION_FUNCTION == 1

#define MAKE_ENUM(enum_name, enum_type, ...)                       \
    enum class enum_name : enum_type {                             \
	__VA_ARGS__                                                \
    };                                                             \
                                                                   \
    constexpr std::string_view enum_name##_to_sv(enum_name value)  \
    {                                                              \
        using enum enum_name;                                      \
        using namespace std::literals;                             \
        switch(value) {                                            \
            FOR_EACH(ENUM_CASE, __VA_ARGS__)                       \
            default: return ""sv;                                  \
        }                                                          \
    }				

#else

#define MAKE_ENUM(enum_name, enum_type, ...)                       \
    enum class enum_name : enum_type {                             \
	__VA_ARGS__                                                \
    };

#endif
