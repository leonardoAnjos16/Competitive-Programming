#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;
const int MOD = 1e9 + 7;

int facts[MAX], invs[MAX];

int exp(int a, int n) {
  if (!n) return 1;

  int ans = exp(a, n >> 1);
  ans = (1LL * ans * ans) % MOD;

  if (!(n & 1)) return ans;
  return (1LL * ans * a) % MOD;
}

int mod_mult_inv(int a, int m) {
  return exp(a, m - 2);
}

int comb(int n, int k) {
  int num = facts[n];
  int den = (1LL * invs[k] * invs[n - k]) % MOD;
  return (1LL * num * den) % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  facts[0] = invs[0] = 1;
  for (int i = 1; i < MAX; i++) {
    facts[i] = (1LL * facts[i - 1] * i) % MOD;
    invs[i] = mod_mult_inv(facts[i], MOD);
  }

  int H, W, N;
  cin >> H >> W >> N;

  vector<pair<int, int>> walls(N);
  for (int i = 0; i < N; i++) {
    int r, c;
    cin >> r >> c;
    walls[i] = make_pair(r - 1, c - 1);
  }

  sort(walls.begin(), walls.end(), [&](pair<int, int> const &a, pair<int, int> const &b) {
    return a.first + a.second < b.first + b.second;
  });

  walls.emplace_back(H - 1, W - 1);

  vector<tuple<int, int, int>> processed;
  for (auto [r, c]: walls) {
    int v = comb(r + c, c);
    for (auto [pr, pc, pv]: processed) {
      if (r >= pr && c >= pc) {
        int dr = r - pr, dc = c - pc;
        int take = (1LL * pv * comb(dr + dc, dc)) % MOD;
        v = (v - take + MOD) % MOD;
      }
    }

    processed.emplace_back(r, c, v);
  }

  auto [_r, _c, ans] = processed.back();
  cout << ans << "\n";
}