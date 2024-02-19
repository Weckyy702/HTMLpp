#pragma once

#include "StringLiteral.hpp"

template <StringLiteral A, StringLiteral B, StringLiteral... Rest>
struct Concat {
  constexpr static auto value = Concat<A, Concat<B, Rest...>::value>::value;
};

template <StringLiteral a, StringLiteral b> struct Concat<a, b> {
  constexpr static auto value = StringLiteral<a.length + b.length + 1>(a, b);
};
