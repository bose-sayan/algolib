#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>

/**
 * @brief Performs a binary search on a sorted vector.
 *
 * This function performs a binary search on a sorted vector to find the index
 * of a given key. If the key is not present in the vector, the function returns
 * -1.
 *
 * @tparam T The type of elements in the vector. The type T must support
 * comparison operators.
 * @param v The sorted vector in which to search for the key.
 * @param key The value to search for in the vector.
 * @return int The index of the key in the vector if found, otherwise -1.
 */

template <typename T> int binary_search(std::vector<T> const &v, T key) {
  int l = 0, h = int(v.size()) - 1;
  while (l <= h) {
    int m = l + (h - l) / 2;
    if (v[m] == key)
      return m;
    if (v[m] < key)
      l = m + 1;
    else
      h = m - 1;
  }
  return -1;
}

#endif // BINARY_SEARCH_H