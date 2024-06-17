#pragma once

#include <algorithm>
#include <cstddef>
#include <type_traits>

template <std::size_t N> struct StringLiteral {
  constexpr static auto length = N - 1;

  consteval StringLiteral(const char (&str)[N]) {
    std::copy_n(str, length, value);
  }

  template <std::size_t A, std::size_t B>
  consteval StringLiteral(StringLiteral<A> a, StringLiteral<B> b) {
    std::copy_n(a.value, a.length, value);
    std::copy_n(b.value, b.length, value + a.length);
  }

  char value[length];
};

template <StringLiteral S> constexpr auto operator""_s() { return S; }

template <typename T> struct IsStringLiteral;

template <std::size_t N>
struct IsStringLiteral<StringLiteral<N>> : std::true_type {};

template <std::size_t N>
struct IsStringLiteral<const StringLiteral<N>> : std::true_type {};
