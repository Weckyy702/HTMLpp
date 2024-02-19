#pragma once

#include "BasicNodes.hpp"
#include "Concat.hpp"
#include "StringLiteral.hpp"

template <StringLiteral prefix, StringLiteral suffix, Element... Children>
struct SimpleElement {
  static constexpr auto render() {
    return Concat<prefix, (Children::render())..., suffix>::value;
  }
};

template <Element Child> struct P : SimpleElement<"<p>", "</p>", Child> {};
template <Element... Children>
struct Div : SimpleElement<"<div>", "</div>", Children...> {};

template <Element Child> struct Li : SimpleElement<"<li>", "</li>", Child> {};

template <Element... Children>
struct Ul : SimpleElement<"<ul>", "</ul>", Li<Children>...> {};

template <Element... Children>
struct Document
    : SimpleElement<"<!DOCTYPE html><html>", "</html>", Children...> {};

template <Element... Children>
struct Body : SimpleElement<"<body>", "</body>", Children...> {};

template <StringLiteral S>
struct H1 : SimpleElement<"<h1>", "</h1>", Text<S>> {};
