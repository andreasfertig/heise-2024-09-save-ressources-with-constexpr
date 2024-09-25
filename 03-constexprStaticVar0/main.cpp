// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <array>
#include <span>
#include <string_view>

void Check(int, std::span<const std::string_view>) {}

auto getElement(int idx)
{
  constexpr std::array<std::string_view, 5> data{
    "Hello", "CppCon", "2024"};

  Check(idx, data);

  return data[idx];  // #A Should be .at
}

int main() { return getElement(2).size(); }