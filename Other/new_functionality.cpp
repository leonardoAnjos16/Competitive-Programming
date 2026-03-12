#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;

  int a, b;
  cin >> a >> b;

  int c, d;
  cin >> c >> d;

  if (a == c) cout << (d - b) << "\n";
  else {
    int ans = (c - a - 1) * (n + 1);
    ans += n + 1 - b + d;

    cout << ans << "\n";
  }
}