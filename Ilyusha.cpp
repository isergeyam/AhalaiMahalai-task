#include "Ahalaimahalai.hpp"
#include <iostream>

int main() {
  constexpr int who = AhalaiMahalai<1, 2, 3, 4, 5, 6>::who;
  constexpr int whence = AhalaiMahalai<1, 2, 3, 4, 5, 6>::whence;
  constexpr int how = AhalaiMahalai<1, 2, 3, 4, 5, 6>::how;
  std::cout << who << " " << whence << " " << how << std::endl;
  // constexpr int __xor = AhalaiMahalai<1, 2, 3, 4>::__xor;
  // constexpr int __elem_on = AhalaiMahalai<1, 2, 3, 4>::__elem_on;
  // constexpr int __find_first_bit = AhalaiMahalai<1, 1, 1,
  // 1>::__find_first_bit;
  // std::cout << __xor << " " << __elem_on << " " << __find_first_bit
  //<< std::endl;
}
