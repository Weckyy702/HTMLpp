#pragma once

#include <cstdint>

#include "ElementTraits.hpp"
#include "IntToString.hpp"
#include "StringLiteral.hpp"

#define $(x) decltype(type_for<(x)>())

template <StringLiteral s> struct Text : BodyMarker, HeadMarker {
  static constexpr auto render() { return s; }
};

constexpr auto type_for();

template <StringLiteral s> constexpr auto type_for() { return Text<s>{}; }
template <std::intmax_t x> constexpr auto type_for() {
  return Text<IntToString<x>::value>{};
}
