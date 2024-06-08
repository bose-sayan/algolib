#include <cassert>
#include <iostream>

#include "searching/binary_search.h"
#include "searching/linear_search.h"

void test_binary_search() {
  std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  // Test cases
  // 1. Element is present in the vector
  assert(binary_search(v1, 1) == 0);
  assert(binary_search(v1, 5) == 4);
  assert(binary_search(v1, 9) == 8);
  // 2. Element is not present in the vector
  assert(binary_search(v1, 0) == -1);
  assert(binary_search(v1, 10) == -1);
  // 3. Empty vector
  v1.clear();
  assert(binary_search(v1, 1) == -1);

  std::vector<char> v2 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
  // Test cases
  // 1. Element is present in the vector
  assert(binary_search(v2, 'a') == 0);
  assert(binary_search(v2, 'e') == 4);
  assert(binary_search(v2, 'i') == 8);
  // 2. Element is not present in the vector
  assert(binary_search(v2, 'z') == -1);
  assert(binary_search(v2, 'x') == -1);
  // 3. Empty vector
  v2.clear();
  assert(binary_search(v2, 'a') == -1);
}

void test_linear_search() {
  std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  // Test cases
  // 1. Element is present in the vector
  assert(linear_search(v1, 1) == 0);
  assert(linear_search(v1, 5) == 4);
  assert(linear_search(v1, 9) == 8);
  // 2. Element is not present in the vector
  assert(linear_search(v1, 0) == -1);
  assert(linear_search(v1, 10) == -1);
  // 3. Empty vector
  v1.clear();
  assert(linear_search(v1, 1) == -1);

  std::vector<char> v2 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
  // Test cases
  // 1. Element is present in the vector
  assert(linear_search(v2, 'a') == 0);
  assert(linear_search(v2, 'e') == 4);
  assert(linear_search(v2, 'i') == 8);
  // 2. Element is not present in the vector
  assert(linear_search(v2, 'z') == -1);
  assert(linear_search(v2, 'x') == -1);
  // 3. Empty vector
  v2.clear();
  assert(linear_search(v2, 'a') == -1);
}

int main() {
  test_binary_search();
  test_linear_search();
  std::cout << "All tests passed!" << std::endl;
  return 0;
}
