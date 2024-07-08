#ifndef MOS_H
#define MOS_H

#include <algorithm>
#include <vector>
using namespace std;

// Global

/**
 * @brief The block size for Mo's algorithm
 */
int block_size; // Todo: Set appropriate block size

/**
 * @brief A structure to represent a query on a range [l, r]
 * This structure represents a query on a range [l, r]. The structure contains
 an id to identify the query and the left and right endpoints of the range.
 * @param l The left endpoint of the range.
 * @param r The right endpoint of the range.
 * @param id The id of the query.
 */
struct Query {
  int l, r, id;
  Query(int L, int R, int idx) {
    this->l = L;
    this->r = R;
    this->id = idx;
  }
  bool operator<(const Query &other) const {
    return make_pair(l / block_size, r) <
           make_pair(other.l / block_size, other.r);
  }
};

void remove_idx(int); // Todo: Remove value at index from the data structure
void add_idx(int);    // Todo: Add value at index to the data structure

/**
 * @brief Answer multiple queries on a range [l, r] using Mo's algorithm
 * This function answers multiple queries on a range [l, r] using Mo's
 * algorithm. The queries are sorted in increasing order of the left endpoint
 * and then in increasing order of the right endpoint. The function maintains a
 * data structure that reflects the range [l, r] and updates it as it moves from
 * one query to the next. The function returns a vector of answers to the
 * queries.
 * @param queries A vector of Query objects representing the queries.
 * @return vector<int> A vector of integers representing the answers to the
 * queries.
 */
vector<int> answerQueries(vector<Query> &queries) {
  vector<int> answers(queries.size());
  sort(queries.begin(), queries.end());

  // Todo: Initialize the data structure

  int curL = 0,
      curR = 0; // The data structure will always reflect the range [curL, curR]

  // Todo: insert first index element to data structure

  for (const Query &q : queries) {
    while (curL > q.l) {
      add_idx(--curL);
    }
    while (curR < q.r) {
      add_idx(++curR);
    }
    while (curL < q.l) {
      remove_idx(curL++);
    }
    while (curR > q.r) {
      remove_idx(curR--);
    }
    answers[q.id] = -1; // Todo: Get correct answer for the current range from
                        // data structure
  }
  return answers;
}

#endif // MOS_H