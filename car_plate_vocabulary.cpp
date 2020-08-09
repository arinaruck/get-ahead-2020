class ShortestWordFinder {
 public:
  ShortestWordFinder(std::vector<std::string> vocabulary) {
    vocab = vocabulary;
  }
  
  int to_lower_ord(char c) {
    if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
    return c - 'a';
  }
  
  bool contains_all(std::string& word, std::vector<int> char_vocab, std::vector<int>& idx) {
    for (char c : word) {
      char_vocab[to_lower_ord(c)]--;
    }
    for (int i : idx) {
      if (char_vocab[i] > 0) return false;
    }
    return true;
  }

  std::string GetShortestWordIn(std::string license_plate) {
    int num_chars = 26;
    std::vector<int> char_vocab(num_chars, 0);
    std::vector<int> idx;
    int min_length = 0;
    std::string curr_best = "";
    for (char c : license_plate) {
      if (isalpha(c)) {
        int i = to_lower_ord(c);
        char_vocab[i]++;
        idx.push_back(i);
      }
    }
    for (std::string word : vocab) {
      if (contains_all(word, char_vocab, idx) && (word.length() < min_length || min_length == 0)) {
        min_length = word.length();
        curr_best = word;
      }
    }
    return curr_best;
  }
 private:
  std::vector<std::string> vocab;
};
