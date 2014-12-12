
class Solution {
 public:
  int singleNumber(int A[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
      res ^= A[i];
    }
    return res;
  }
};

int main() {
  Solution sol;
  int A[] = {3, 3, 1, 2, 1};
  sol.singleNumber(A, 5);
}
