#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

#include "shared.hpp"

#define FMT_HEADER_ONLY
#include <fmt/format.h>

int main(void) {
  //   auto res = std::reduce(std::execution::par_unseq, list.begin(),
  //   list.end());
  auto res = std::reduce(std::execution::par_unseq, list.begin(), list.end(), 0,
                         [&](int sum, int num) { return sum + num; });
  std::cout << "The result is " << res << std::endl;

  return 0;
}
