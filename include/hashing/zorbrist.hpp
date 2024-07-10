#pragma once

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <numeric>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief A custom hash function for hashing.
 * This struct provides a custom hash function for hashing integers. The hash is
 * a 64-bit integer. The hash is computed using the splitmix64 algorithm.
 * @param x The integer to hash.
 * @return uint64_t The hash of the integer.
 */
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  uint64_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
} rng;

/**
 * @brief Computes the hash of a vector.
 * This function computes the hash of a vector of integers. The hash is computed
 * by taking the xor of the hashes of the elements of the vector. The hash of an
 * element is computed using the custom hash function.
 * @param v The vector of integers for which to compute the hash.
 * @return vector<int> The hash of the vector.

 */
vector<int> get_hash(const vector<int> &v) {
  vector<int> hash(v.size());
  unordered_set<int, custom_hash> done;
  for (int i = 0; i < v.size(); i++) {
    if (done.find(v[i]) == done.end()) {
      done.insert(v[i]);
      hash[i] = rng(v[i]);
    }
    if (i)
      hash[i] ^= hash[i - 1];
  }
  return hash;
}
