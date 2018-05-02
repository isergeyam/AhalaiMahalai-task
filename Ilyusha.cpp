#include "Ahalaimahalai.hpp"
#include <iostream>

int main() {
  constexpr int who = AhalaiMahalai<1, 2, 3, 4>::who;
  std::cout << who;
}
