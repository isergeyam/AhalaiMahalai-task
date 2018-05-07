#pragma once
#include <cstddef>
#include <type_traits>
template <size_t Num> constexpr size_t MyXor() { return Num; }
template <size_t Num1, size_t Num2> constexpr size_t MyXor() {
  return Num1 ^ Num2;
}
template <size_t Num1, size_t Num2, size_t... Numbs,
          typename = std::enable_if_t<sizeof...(Numbs) != 0>>
constexpr size_t MyXor() {
  return Num1 ^ Num2 ^ MyXor<Numbs...>();
}
template <size_t X> constexpr size_t FindFIrstBit() {
  size_t X1 = X;
  X1 |= X1 >> 1;
  X1 |= X1 >> 2;
  X1 |= X1 >> 4;
  X1 |= X1 >> 8;
  X1 |= X1 >> 16;
  return X1 - (X1 >> 1);
}
template <bool B, size_t F, size_t S> struct MyCondition {
  static constexpr size_t value = F;
};
template <size_t F, size_t S> struct MyCondition<false, F, S> {
  static constexpr size_t value = S;
};
template <size_t N, size_t Head, size_t... Tail> struct FirstWithBit {
  static constexpr size_t value =
      MyCondition<!bool(Head & N), FirstWithBit<N, Tail...>::value,
                  Head>::value;
};
template <size_t N, size_t Head> struct FirstWithBit<N, Head> {
  static constexpr size_t value = MyCondition<!bool(Head & N), 0, Head>::value;
};
template <size_t N, size_t Head, size_t... Tail> struct GetOnPos {
  static constexpr size_t value = GetOnPos<N - 1, Tail...>::value;
};
template <size_t Head, size_t... Tail> struct GetOnPos<1, Head, Tail...> {
  static constexpr size_t value = Head;
};
template <size_t Head, size_t... Tail> struct GetOnPos<0, Head, Tail...> {
  static constexpr size_t value = 0;
};
template <size_t B> struct MyOperator : std::false_type {};
template <> struct MyOperator<0> : std::true_type {};
template <size_t... Numbs> struct AhalaiMahalai {
  static constexpr size_t __xor = MyXor<Numbs...>();
  static constexpr size_t who = MyCondition<__xor, 1, 2>::value;
  static constexpr size_t __find_first_bit = FindFIrstBit<__xor>();
  static constexpr size_t whence =
      MyCondition<!bool(__xor), 0,
                  FirstWithBit<__find_first_bit, Numbs...>::value>::value;
  static constexpr size_t __elem_on = GetOnPos<whence, Numbs...>::value;
  static constexpr size_t how =
      MyCondition<!bool(__xor), 0,
                  __elem_on - MyXor<__xor, __elem_on>()>::value;
};
