#include <string>
#include <vector>

size_t longest_balanced(std::string str) {
  size_t max_balanced = 0;
  size_t curr_balanced = 0; 
  int balance = 0;
  for (char c : str) {
    if (c == '(') {
      balance = std::max(0, balance) + 1;
      continue;
    }
    balance--;
    if (balance >= 0) {
      curr_balanced++;
    }
    if (balance <= 0) {
      max_balanced = std::max(max_balanced, curr_balanced);
      curr_balanced = 0;
    } 
  }
  max_balanced = std::max(max_balanced, curr_balanced);
  return 2 * max_balanced;
}
