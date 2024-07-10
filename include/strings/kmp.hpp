#pragma once

#include <numeric>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief Computes the prefix function of a string.
 *
 * This function computes the prefix function of a string. The prefix function
 * of a string is an array of integers where the i-th element is the length of
 * the longest proper prefix of the substring s[0..i] which is also a suffix of
 * this substring.
 *
 * @param s The string for which to compute the prefix function.
 * @return vector<int> The prefix function of the string.
 */
vector<int> compute_prefix_function(const string &s) {
  int n = int(s.length());
  vector<int> pref(n);
  if (!n)
    return pref;
  pref[0] = 0;
  for (int i = 1; i < n; i++) {
    int toExtendIdx = i - 1;
    while (toExtendIdx >= 0) {
      int longestPrefLen = pref[toExtendIdx];
      if (s[i] == s[longestPrefLen]) {
        pref[i] = longestPrefLen + 1;
        break;
      }
      toExtendIdx = longestPrefLen - 1;
    }
  }
  return pref;
}

/**
  * @brief Finds all occurrences of a pattern in a text using the
  Knuth-Morris-Pratt algorithm.
  *
  * This function finds all occurrences of a pattern in a text using the
  Knuth-Morris-Pratt
  * algorithm. The function returns a vector of integers where each integer is
  the starting
  * index of an occurrence of the pattern in the text.
  *
  * @param text The text in which to search for the pattern.
  * @param pattern The pattern to search for in the text.
  * @return vector<int> A vector of integers where each integer is the starting
  index of an occurrence of the pattern in the text.
*/
vector<int> kmp(const string &text, const string &pattern) {
  if (pattern.empty()) {
    vector<int> matches(text.length() + 1);
    iota(matches.begin(), matches.end(), 0);
    return matches;
  }
  string s = pattern + "#" + text;
  vector<int> pref = compute_prefix_function(s);
  vector<int> matches;
  int n = int(text.length()), m = int(pattern.length());
  for (int i = m + 1; i < m + 1 + n; i++) {
    if (pref[i] == m)
      matches.push_back(i - 2 * m);
  }
  return matches;
}
