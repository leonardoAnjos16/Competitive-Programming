#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e6 + 5;

int last_prime[MAX], pos[MAX];
vector<int> multiples[MAX];

int memo[MAX], nxt[MAX];

int max_conspiracy(int v) {
  int &ans = memo[v];
  if (~ans) return ans;

  ans = 1;

  int x = v;
  while (x > 1) {
    int p = last_prime[x];
    while (x % p == 0) x /= p;

    auto it = upper_bound(multiples[p].begin(), multiples[p].end(), v);
    if (it != multiples[p].end()) {
      int nans = max_conspiracy(*it) + 1;
      if (nans > ans) {
        ans = nans;
        nxt[v] = *it;
      }
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(last_prime, -1, sizeof last_prime);
  for (int i = 2; i < MAX; i++)
    if (last_prime[i] == -1)
      for (int j = i; j < MAX; j += i)
        last_prime[j] = i;

  int n; cin >> n;

  memset(pos, -1, sizeof pos);

  int start = -1;
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    pos[a] = i + 1;
    start = a;

    int v = a;
    while (v > 1) {
      int p = last_prime[v];
      while (v % p == 0) v /= p;
      multiples[p].push_back(a);
    }
  }

  for (int i = 0; i < MAX; i++) {
    sort(multiples[i].begin(), multiples[i].end());
    multiples[i].erase(unique(multiples[i].begin(), multiples[i].end()), multiples[i].end());
  }

  memset(memo, -1, sizeof memo);
  memset(nxt, -1, sizeof nxt);

  int ans = 1;
  for (int i = 2; i < MAX; i++) {
    if (pos[i] == -1) continue;

    int nans = max_conspiracy(i);
    if (nans > ans) {
      ans = nans;
      start = i;
    }
  }

  cout << ans << "\n";

  int curr = start;
  vector<int> sequence(1, pos[start]);

  while (nxt[curr] != -1) {
    sequence.push_back(pos[nxt[curr]]);
    curr = nxt[curr];
  }

  for (int i = 0; i < ans; i++) {
    if (i) cout << " ";
    cout << sequence[i];
  }

  cout << "\n";
}