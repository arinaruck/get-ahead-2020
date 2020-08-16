// C++ Solution
#include <stdlib.h>

#include <string>
#include <vector>

using Grid = std::vector<std::vector<char>>;

// This is a quick but non-comprehensive and non-efficient implementation
// of the dictionary. Since a dictionary has been provided to us, we don't worry
// about this bit. Note: An efficient implementation of a Dictionary here would
// involve a Trie. In an interview you don't have to code this class, the problem
// clearly states that you have it available already.
class Dictionary {
 public:
  Dictionary(std::vector<std::string> words) : words_(words) {}

  bool IsWord(const std::string& to_match) {
    return std::find(words_.begin(), words_.end(), to_match) != words_.end();
  }

  bool IsPrefix(const std::string& to_match) {
    for (const auto& word : words_) {
      if (word.find(to_match) == 0) return true;
    }
    return false;
  }

  bool empty() { return words_.empty(); }

 private:
  std::vector<std::string> words_;
};

class LongestWordFinder {
 public:
  LongestWordFinder(Dictionary dictionary, Grid grid) :
  dict(dictionary), grid(grid) {
    n = grid.size();
    m = grid[0].size();
  }

  std::string FindLongestWord() {
    // Implement.
    std::string longest = "";
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        Grid used(n, std::vector<char>(m));
        std::string curr = LongestFromPos(i, j, used, "", "");
        if (curr.length() > longest.length()) longest = curr;
      }
    }
    return longest;
  }
  
  bool is_valid_pos(int i, int j, Grid& used) {
    return (i >= 0 && i < n) && (j >= 0 && j < m) && !(used[i][j]);
  }
  
  std::string LongestFromPos(int i, int j, Grid used, 
                            std::string best_word, std::string best_substr) {
      used[i][j] = 1;
      best_substr = best_substr + grid[i][j];
      if (dict.IsWord(best_substr)) best_word = best_substr;
      for (int dir_x : dirs) {
        for (int dir_y : dirs) {
          int new_i = i + dir_x;
          int new_j = j + dir_y;
          if (is_valid_pos(new_i, new_j, used) && dict.IsPrefix(best_substr + grid[new_i][new_j])) {
            std::string curr = LongestFromPos(new_i, new_j, used, best_word, best_substr);
            if (curr.length() > best_word.length()) best_word = curr;
          }
        }
      } 
      return best_word;
  }
  private:
    Dictionary dict;
    Grid grid;
    int n;
    int m;
    std::vector<int> dirs = {-1, 0, 1};
};
