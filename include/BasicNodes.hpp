#pragma once

#include <cstdint>

#include "IntToString.hpp"
#include "StringLiteral.hpp"

#define $(x) decltype(type_for<(x)>())

template <typename T>
concept Element = requires {
  T::render();
  requires IsStringLiteral<decltype(T::render())>::value;
};

template <StringLiteral s> struct Text {
  static constexpr auto render() {
    return s;
  }
};

constexpr auto type_for();

template <StringLiteral s> constexpr auto type_for() { return Text<s>{}; }
template <std::intmax_t x> constexpr auto type_for() {
  return Text<IntToString<x>::value>{};
}
