#include <cassert>
#include <iostream>
#include <vector>


using namespace std;

struct tree {
  int value;
  vector<tree> children;
};


void dfs_longest(const tree* root, int par, int curr, int& longest) {
  int val = root->value;
  if (val == par + 1) curr++;
  else curr = 1;
  longest = std::max(longest, curr);
  for (tree child : root->children) {
    dfs_longest(&child, val, curr, longest);
  }
}

int longest_path(const tree &root) {
  /* Implement me */
  int longest = 0;
  dfs_longest(&root, -1, 0, longest);
  return longest;
}
