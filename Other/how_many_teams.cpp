#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int to_int(string s) {
  int ans = 0;
  for (char c: s) {
    ans <<= 1;
    if (c == '1') ans++;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K;
  cin >> N >> K;

  vector<llong> f(1 << K, 0LL);
  for (int i = 0; i < N; i++) {
    string H; cin >> H;
    f[to_int(H)]++;
  }

  for (int i = 0; i < K; i++)
    for (int j = 0; j < (1 << K); j++)
      if (j & (1 << i))
        f[j] += f[j ^ (1 << i)];

  for (int i = 0; i < (1 << K); i++)
    f[i] = f[i] * (f[i] - 1) * (f[i] - 2) / 6;

  for (int i = 0; i < K; i++)
    for (int j = 0; j < (1 << K); j++)
      if (j & (1 << i))
        f[j] -= f[j ^ (1 << i)];

  int M; cin >> M;
  while (M--) {
    string E; cin >> E;

    llong ans = f[to_int(E)];
    cout << ans << "\n";
  }
}