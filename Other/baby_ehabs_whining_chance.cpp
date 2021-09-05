#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("lis.in", "r", stdin);

    string n; cin >> n;
    int sz = n.size();

    int ans = 9 * (sz - 1);
    ans += n[0] - '0';

    bool all_nine = true;
    for (int i = 1; i < sz && all_nine; i++)
        if (n[i] != '9') all_nine = false;

    if (!all_nine) ans--;
    cout << ans << "\n";
}