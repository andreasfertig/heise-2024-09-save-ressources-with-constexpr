// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <algorithm>
#include <cstdint>
#include <string>
#include <string_view>

#ifndef CONSTEXPR
#  define CONSTEXPR constexpr
#endif

template<size_t N>
class FixedString {
  size_t mLength{};
  char   mData[N]{};

public:
  FixedString() = default;
  constexpr FixedString(const char* str)
  : mLength{std::char_traits<char>::length(str)}
  {
    std::copy_n(str, size(), mData);
  }

  constexpr size_t size() const { return mLength; }

  constexpr std::string_view data() const
  {
    return {mData, mLength};
  }
};

template<size_t N>
constexpr auto make_fixed_string(const char (&str)[N])
{
  return FixedString<N>{str};
}

constexpr static FixedString<50> x{
  "Hello, embedded World!"};
constexpr static auto y{
  make_fixed_string("Hello, some other planet!")};

int main()
{
  printf("x: %s  %zu\n", x.data().data(), sizeof(x));
  printf("y: %s  %zu\n", y.data().data(), sizeof(y));
}