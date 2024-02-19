#pragma once

#include "StringLiteral.hpp"
#include <type_traits>

template <typename T>
concept Element = requires {
  T::render();
  requires IsStringLiteral<decltype(T::render())>::value;
};

struct DocumentMarker {};

struct HeadMarker {};

template <typename T>
concept HeadElement = std::is_base_of_v<HeadMarker, T>;

struct BodyMarker {};

template <typename T>
concept BodyElement = std::is_base_of_v<BodyMarker, T>;
