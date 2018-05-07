#include "Ahalaimahalai.hpp"
#include <iostream>

int main() {
  constexpr int who = AhalaiMahalai<1, 2, 3, 4, 5, 6>::who;
  constexpr int whence = AhalaiMahalai<1, 2, 3, 4, 5, 6>::whence;
  constexpr int how = AhalaiMahalai<1, 2, 3, 4, 5, 6>::how;
  std::cout << who << " " << whence << " " << how << std::endl;
}
