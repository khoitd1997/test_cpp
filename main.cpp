#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

template <typename T> void get(const T &val) {
  // do nothing
}
template <typename T> void get(const std::vector<T> &vals) {
  // do nothing
}

int main(void) {
  std::vector<int> someNum;
  get(someNum);
  return 0;
}