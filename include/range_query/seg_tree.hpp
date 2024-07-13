#pragma once

#include <vector>

/**
 * @brief Segment Tree
 * @tparam T type of data

* @note 1. 0-based indexing
*       2. Default combine operation is sum
*       3. Default identity element is 0
*       4. Default update operation is assignment
*       5. Default query operation is range sum
*       6. Change combine, identity, update, query functions as needed
*
 */
template <typename T> struct SegTree {
  int lb, rb;
  T data;
  SegTree *left, *right;

  // Combine operation
  T combine(const T &a, const T &b) { return a + b; } // TODO: change this

  // Constructor
  SegTree() : lb(0), rb(0), data(), left(nullptr), right(nullptr) {}
  SegTree(const int &l, const int &r) {
    lb = l, rb = r;
    if (l == r) {
      data = T();
      left = right = nullptr;
      return;
    }
    int m = (l + r) / 2;
    left = new SegTree(l, m);
    right = new SegTree(m + 1, r);
    data = combine(left->data, right->data);
  }
  SegTree(const int &l, const int &r, const std::vector<T> &v) {
    lb = l, rb = r;
    if (l == r) {
      data = v[l];
      left = right = nullptr;
      return;
    }
    int m = (l + r) / 2;
    left = new SegTree(l, m, v);
    right = new SegTree(m + 1, r, v);
    data = combine(left->data, right->data);
  }

  // Destructor
  ~SegTree() {
    if (left)
      delete left;
    if (right)
      delete right;
  }

  // Update operation
  void update(const int &idx, const T &val) {
    if (lb == rb) {
      data = val;
      return;
    }
    if (idx <= left->rb)
      left->update(idx, val);
    else
      right->update(idx, val);
    data = combine(left->data, right->data);
  }

  // Query operation
  T query(const int &l, const int &r) {
    if (l > rb || r < lb)
      return T(); // TODO: return identity element
    if (l <= lb && rb <= r)
      return data;
    return combine(left->query(l, r), right->query(l, r));
  }
};