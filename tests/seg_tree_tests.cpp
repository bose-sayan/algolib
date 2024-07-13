#include <cassert>
#include <iostream>

#include "range_query/seg_tree.hpp"

void test_seg_tree() {
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  SegTree<int> st(0, v.size() - 1, v);
  // Test cases
  // Check if the seg tree is built correctly
  assert(st.query(0, 0) == 1);
  assert(st.query(1, 1) == 2);
  assert(st.query(2, 2) == 3);
  assert(st.query(8, 8) == 9);
  // 1. Update operation
  st.update(0, 10);
  assert(st.query(0, 0) == 10);
  st.update(4, 20);
  assert(st.query(4, 4) == 20);
  st.update(8, 30);
  assert(st.query(8, 8) == 30); // 10, 2, 3, 4, 20, 6, 7, 8, 30
  // 2. Query operation
  assert(st.query(0, 4) == 39);
  assert(st.query(3, 7) == 45);
  assert(st.query(1, 8) == 80);
  // 3. Update and query operation
  st.update(5, 50); // 10, 2, 3, 4, 20, 50, 7, 8, 30
  assert(st.query(0, 8) == 134);
  st.update(7, 70); // 10, 2, 3, 4, 20, 50, 7, 70, 30
  assert(st.query(0, 8) == 196);
}

int main() {
  test_seg_tree();
  std::cout << "SegTree tests passed!" << std::endl;
  return 0;
}