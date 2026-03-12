#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, d;
  cin >> n >> m >> d;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] -= d;
  }

  vector<int> b(m);
  for (int i = 0; i < m; i++)
    cin >> b[i];

  int slava_a = a[n - 1];
  int slava_b = a[n - 1] + d;

  bool in_a = false, done = false;
  int ia = 0, ib = 0, t = 0, ridden = 0;

  while (!done) {
    if (in_a) {
      while (ia < n && a[ia] < t) ia++;
      if (ia >= n || a[ia] + d >= slava_a) done = true;
      else t = a[ia] + d + 1, ridden++, in_a = false;
    } else {
      while (ib < m && b[ib] < t) ib++;
      if (ib >= m || b[ib] + d >= slava_a) done = true;
      else t = b[ib] + d + 1, ridden++, in_a = true;
    }
  }

  cout << (in_a ? "A" : "B") << " " << ridden << "\n";
}