// osa_k
// precompute : O(N loglog N), prime factorization query : O(log N)

#include <algorithm>
#include <vector>

// snippet-begin
class osa_k {
  static constexpr int n_ = 2000000;

 public:
  osa_k() { build(); }

  std::vector<std::pair<int, int>> prime_factor(int n) {
    std::vector<std::pair<int, int>> res;
    while (n != 1) {
      int p = min_factor[n];
      int cnt = 0;
      while (min_factor[n] == p) ++cnt, n /= p;
      res.emplace_back(p, cnt);
    }
    return res;
  }

 private:
  bool is_prime[n_];
  int min_factor[n_];

  void build() {
    std::fill(is_prime, is_prime + n_, true);
    std::fill(min_factor, min_factor + n_, -1);
    is_prime[0] = is_prime[1] = false;
    min_factor[0] = 0, min_factor[1] = 1;

    for (int i = 2; i < n_; ++i) {
      if (is_prime[i]) {
        min_factor[i] = i;
        for (int j = 2 * i; j < n_; j += i) {
          is_prime[j] = false;
          if (min_factor[j] == -1) min_factor[j] = i;
        }
      }
    }
  }
};
// snippet-end
