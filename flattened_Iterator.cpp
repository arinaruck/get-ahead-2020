#include <vector>

class Iterator {
public:
  virtual bool hasNext() const = 0;
  virtual int next() = 0;
};

class FlattenedIterator : public Iterator {
  int max_idx;
  int cur_idx = 0;
  std::vector<Iterator*> iters;
public:
  explicit FlattenedIterator(const std::vector<Iterator*>& subiterators) {
    iters = subiterators;
    max_idx = subiterators.size();
    next_idx();
  }

  void next_idx() {
    if (!max_idx) return;
    for (int shift = 0; shift < max_idx; shift++) {
      if (iters[(cur_idx + shift) % max_idx]->hasNext()) {
        cur_idx = (cur_idx + shift) % max_idx;
        return;
      }
    }
    cur_idx = -1;
  }
  
  bool hasNext() const override {
    return max_idx && cur_idx > -1;
  }
  
  int next() override {
    if (!hasNext()) return NULL;
    int next = iters[cur_idx]->next();
    cur_idx = (cur_idx + 1) % max_idx;
    next_idx();
    return next;
  }
};
