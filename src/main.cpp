#include <unistd.h>

#include "Elements.hpp"

// clang-format off

int main() {
  using html = 
  Document<
    Head<Title<"My title">>,
    Body<
      H1<"My first heading">,
      P<$(12)>
    >
  >;

  constexpr auto s = html::render();

  // tfw std::cout disables compiler optimizations and forces a memcpy :(
  // C time :)
  write(STDOUT_FILENO, s.value, s.length);
}
