#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e3 + 5;

int cnt[MAX] = {0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, D;
  cin >> n >> D;

  for (int i = 0; i < D; i++) {
    int f, s;
    cin >> f >> s;

    cnt[f]++;
    cnt[s]++;
  }

  int mx = 0;
  for (int i = 1; i <= n; i++)
    mx = max(mx, cnt[i]);

  int start = mx, step = 1;
  if (n & 1) {
    step = 2;
    if (start & 1) start++;
  }

  int problem = -1;
  for (int i = 1; i <= n; i++) {
    int missing = start - cnt[i];
    if (2 * missing > n * start - 2 * D)
      problem = missing;
  }

  if (problem == -1) cout << start << "\n";
  else {
    int num = 2 * problem - (n * start - 2 * D);
    int den = step * (n - 2);
    assert(den);

    int inc = (num + den - 1) / den;
    int ans = start + step * inc;
    cout << ans << "\n";
  }
}