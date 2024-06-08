#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <vector>
/**
 * @brief Performs a linear search on a vector.
 *
 * This function performs a linear search on a vector to find the index of a
 * given key. If the key is not present in the vector, the function returns -1.
 *
 * @tparam T The type of elements in the vector. The type T must support
 * comparison operators.
 * @param v The vector in which to search for the key.
 * @param key The value to search for in the vector.
 * @return int The index of the key in the vector if found, otherwise -1.
 */

template <typename T> int linear_search(std::vector<T> const &v, T key) {
  for (int i = 0; i < int(v.size()); i++) {
    if (v[i] == key)
      return i;
  }
  return -1;
}

#endif // LINEAR_SEARCH_H