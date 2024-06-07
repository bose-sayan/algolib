#include <vector>
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