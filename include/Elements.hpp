#pragma once

#include "BasicNodes.hpp"
#include "Concat.hpp"
#include "ElementTraits.hpp"
#include "StringLiteral.hpp"

template <typename Marker, StringLiteral prefix, StringLiteral suffix,
          Element... Children>
struct SimpleElementMarker : Marker {
  static constexpr auto render() {
    return Concat<prefix, (Children::render())..., suffix>::value;
  }
};

template <Element... Children> struct Document;

template <StringLiteral prefix, StringLiteral suffix, HeadElement... Children>
using SimpleHeadElement =
    SimpleElementMarker<HeadMarker, prefix, suffix, Children...>;

template <HeadElement... Children>
struct Head : SimpleHeadElement<"<head>", "</head>", Children...> {};

template <StringLiteral s>
struct Title : SimpleHeadElement<"<title>", "</title>", Text<s>> {};

template <StringLiteral prefix, StringLiteral suffix, BodyElement... Children>
using SimpleBodyElement =
    SimpleElementMarker<BodyMarker, prefix, suffix, Children...>;

template <BodyElement... Children>
struct Body : SimpleBodyElement<"<body>", "</body>", Children...> {};

template <StringLiteral S>
struct H1 : SimpleBodyElement<"<h1>", "</h1>", Text<S>> {};

template <Element... Children>
struct Div : SimpleBodyElement<"<div>", "</div>", Children...> {};

template <Element Child> struct Li;

template <Element... Children>
struct Ul : SimpleBodyElement<"<ul>", "</ul>", Li<Children>...> {};

template <Element Child>
struct Li : SimpleBodyElement<"<li>", "</li>", Child> {};

template <Element Child> struct P : SimpleBodyElement<"<p>", "</p>", Child> {};

template <HeadElement... HeadChildren, BodyElement... BodyChildren>
struct Document<Head<HeadChildren...>, Body<BodyChildren...>>
    : SimpleElementMarker<DocumentMarker, "<!DOCTYPE html><html>", "</html>",
                          Head<HeadChildren...>, Body<BodyChildren...>> {};
