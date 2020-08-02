class LargestRectangleCalculator {
 public:
  // Add ctor and dtor.
  LargestRectangleCalculator(std::vector<int> bar_heights) {
      heights = bar_heights;
      max_area = -1;
      left = -1;
      right = -1;
  }
 
  std::pair<int, int> GetLargestRectangularAreaUnderCurve() {
    // Implement me
    if (max_area == -1) {
        CalculateLargestRectangle();
    }
    return {left, right};
  }
 
  void CalculateLargestRectangle() {
    // Implement me
      int bar_num = heights.size();
      switch(bar_num) {
          case 0:
            max_area = 0;
            break;
          default:
            std::vector<int> stack(1, -1);
            for (int i = 0; i < bar_num; ++i) {
              while (stack.back() != -1 && (heights[stack.back()] > heights[i])) {
                  update_max(stack, i);
              }
              stack.push_back(i);
            }
            while (stack.back() != -1) {
                update_max(stack, bar_num);
            }
      }
  }
 
 private:
   // Add private members.
   std::vector<int> heights;
   int left;
   int right;
   int max_area;
   
   void update_max(std::vector<int>& stack, int i) {
      int idx = stack.back();
      stack.pop_back();
      int curr_area = heights[idx] * (i -  stack.back() - 1);
      if (max_area < curr_area) {
          max_area = curr_area;
          left = stack.back() + 1;
          right = i - 1;
      }
   }
};
 
