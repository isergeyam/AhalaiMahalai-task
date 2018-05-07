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
template <bool B, size_t F, size_t S> struct MyCondition {
  static constexpr size_t value = F;
};
template <size_t F, size_t S> struct MyCondition<false, F, S> {
  static constexpr size_t value = S;
};
template <size_t X, int N> struct FindFirstBit {
  static constexpr size_t value =
      MyCondition<X >= (1 << N), 1 << N, FindFirstBit<X, N - 1>::value>::value;
};
template <size_t X> struct FindFirstBit<X, -1> {
  static constexpr size_t value = 0;
};
template <size_t N1, size_t N, size_t Head, size_t... Tail>
struct FirstWithBit {
  static constexpr size_t value =
      MyCondition<!bool(Head & N), FirstWithBit<N1 + 1, N, Tail...>::value,
                  N1>::value;
};
template <size_t N1, size_t N, size_t Head> struct FirstWithBit<N1, N, Head> {
  static constexpr size_t value = MyCondition<!bool(Head & N), 0, N1>::value;
};
template <int N, size_t Head, size_t... Tail> struct GetOnPos {
  static constexpr size_t value = GetOnPos<N - 1, Tail...>::value;
};
template <size_t Head, size_t... Tail> struct GetOnPos<0, Head, Tail...> {
  static constexpr size_t value = Head;
};
template <size_t Head, size_t... Tail> struct GetOnPos<-1, Head, Tail...> {
  static constexpr size_t value = 0;
};
template <size_t B> struct MyOperator : std::false_type {};
template <> struct MyOperator<0> : std::true_type {};
template <size_t... Numbs> struct AhalaiMahalai {
  static constexpr size_t __xor = MyXor<Numbs...>();
  static constexpr size_t who = MyCondition<__xor, 0, 1>::value + 1;
  static constexpr size_t __find_first_bit = FindFirstBit<__xor, 31>::value;
  static constexpr size_t whence =
      MyCondition<!bool(__xor), 0,
                  FirstWithBit<0, __find_first_bit, Numbs...>::value>::value +
      1;
  static constexpr size_t __elem_on = GetOnPos<whence - 1, Numbs...>::value;
  static constexpr size_t how =
      MyCondition<!bool(__xor), 0,
                  __elem_on - MyXor<__xor, __elem_on>()>::value;
};
