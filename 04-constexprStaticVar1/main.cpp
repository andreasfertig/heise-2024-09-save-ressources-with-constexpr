// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <array>
#include <span>
#include <string_view>

void Check(int, std::span<const std::string_view>) {}

constexpr auto getElement(int idx)
{
  static constexpr std::array<std::string_view, 5>
    data{"Hello", "CppCon", "2024"};

  Check(idx, data);

  return data[idx];
}

int main() { return getElement(2).size(); }