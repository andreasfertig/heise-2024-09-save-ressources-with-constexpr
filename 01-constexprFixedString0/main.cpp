// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <algorithm>
#include <cstdint>
#include <string>
#include <string_view>

template<size_t N>
class FixedString {
  size_t mLength{};
  char   mData[N]{};

public:
  FixedString() = default;
  FixedString(const char* str)
  : mLength{std::char_traits<char>::length(str)}
  {
    std::copy_n(str, size(), mData);
  }

  size_t size() const { return mLength; }

  std::string_view data() const
  {
    return {mData, mLength};
  }
};

template<size_t N>
auto make_fixed_string(const char (&str)[N])
{
  return FixedString<N>{str};
}

static const FixedString<50> x{
  "Hello, embedded World!"};
static const auto y{
  make_fixed_string("Hello, some other planet!")};

int main()
{
  printf("x: %s  %zu\n", x.data().data(), sizeof(x));
  printf("y: %s  %zu\n", y.data().data(), sizeof(y));
}