#include <cassert>
#include <iostream>

#include "strings/kmp.hpp"

void test_prefix_function() {
  std::string s = "abacaba";
  std::vector<int> expected = {0, 0, 1, 0, 1, 2, 3};
  std::vector<int> result = compute_prefix_function(s);
  assert(result == expected);

  s = "aaaaa";
  expected = {0, 1, 2, 3, 4};
  result = compute_prefix_function(s);
  assert(result == expected);

  s = "abcabcabc";
  expected = {0, 0, 0, 1, 2, 3, 4, 5, 6};
  result = compute_prefix_function(s);
  assert(result == expected);

  s = "abcabcdabcabcd";
  expected = {0, 0, 0, 1, 2, 3, 0, 1, 2, 3, 4, 5, 6, 7};
  result = compute_prefix_function(s);
  assert(result == expected);

  s = "a";
  expected = {0};
  result = compute_prefix_function(s);
  assert(result == expected);

  s = "";
  expected = {};
  result = compute_prefix_function(s);
  assert(result == expected);
}

void test_kmp_function() {
  std::string text = "abacaba";
  std::string pattern = "aba";
  std::vector<int> expected = {0, 4};
  std::vector<int> result = kmp(text, pattern);
  assert(result == expected);

  text = "aaaaa";
  pattern = "aa";
  expected = {0, 1, 2, 3};
  result = kmp(text, pattern);
  assert(result == expected);

  text = "abcabcabc";
  pattern = "abc";
  expected = {0, 3, 6};
  result = kmp(text, pattern);
  assert(result == expected);

  text = "abcabcdabcabcd";
  pattern = "abcd";
  expected = {3, 10};
  result = kmp(text, pattern);
  assert(result == expected);

  text = "a";
  pattern = "a";
  expected = {0};
  result = kmp(text, pattern);
  assert(result == expected);

  text = "";
  pattern = "";
  expected = {0};
  result = kmp(text, pattern);
  assert(result == expected);

  text = "sdasdasd";
  pattern = "";
  expected = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  result = kmp(text, pattern);
  assert(result == expected);

  text = "";
  pattern = "a";
  expected = {};
  result = kmp(text, pattern);
  assert(result == expected);

  text = "abasfafafaf";
  pattern = "a";
  expected = {0, 2, 5, 7, 9};
  result = kmp(text, pattern);
  assert(result == expected);

  text = "abasfafafaf";
  pattern = "pap";
  expected = {};
  result = kmp(text, pattern);
  assert(result == expected);
}

int main() {
  test_prefix_function();
  test_kmp_function();
  std::cout << "KMP tests passed!\n";
  return 0;
}