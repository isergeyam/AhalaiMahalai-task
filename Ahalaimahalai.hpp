#pragma once
#include <cstddef>
#include <type_traits>
template <size_t Num1, size_t Num2> constexpr size_t MyXor() {
  return Num1 ^ Num2;
}
template <size_t Num1, size_t Num2, size_t... Numbs,
          typename = std::enable_if_t<sizeof...(Numbs) != 0>>
constexpr size_t MyXor() {
  return Num1 ^ Num2 ^ MyXor<Numbs...>();
}
template <size_t B> struct MyOperator : std::false_type {};
template <> struct MyOperator<0> : std::true_type {};
template <size_t... Numbs> struct AhalaiMahalai {
  static constexpr size_t __xor = MyXor<Numbs...>();
  static constexpr size_t who = size_t(MyOperator<__xor>::value) + 1;
};
