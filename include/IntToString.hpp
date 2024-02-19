#pragma once

#include <cstdint>

#include "Concat.hpp"
#include "StringLiteral.hpp"

#define IMPL_DIGIT_TO_STRING(digit)                                            \
  template <> struct DigitToString<digit> {                                    \
    static constexpr auto value = #digit##_s;                                  \
  };

template <std::intmax_t digit> struct DigitToString;

IMPL_DIGIT_TO_STRING(0)
IMPL_DIGIT_TO_STRING(1)
IMPL_DIGIT_TO_STRING(2)
IMPL_DIGIT_TO_STRING(3)
IMPL_DIGIT_TO_STRING(4)
IMPL_DIGIT_TO_STRING(5)
IMPL_DIGIT_TO_STRING(6)
IMPL_DIGIT_TO_STRING(7)
IMPL_DIGIT_TO_STRING(8)
IMPL_DIGIT_TO_STRING(9)

template <intmax_t x, bool is_first = true> struct PositiveIntToString {
  static constexpr auto value =
      Concat<PositiveIntToString<x / 10, false>::value,
             DigitToString<x % 10>::value>::value;
};

template <> struct PositiveIntToString<0, false> {
  static constexpr auto value = ""_s;
};
template <> struct PositiveIntToString<0> {
  static constexpr auto value = "0"_s;
};

template <intmax_t x> struct NegativeIntToString {
  static constexpr auto value =
      Concat<"-"_s, PositiveIntToString<(-x)>::value>::value;
};

template <intmax_t x> struct HandleSign;

template <intmax_t x>
  requires(x >= 0)
struct HandleSign<x> {
  static constexpr auto value = PositiveIntToString<x>::value;
};

template <intmax_t x>
  requires(x < 0)
struct HandleSign<x> {
  static constexpr auto value = NegativeIntToString<x>::value;
};

template <intmax_t x> struct IntToString {
  static constexpr auto value = HandleSign<x>::value;
};
