#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int ans = 0;
    vector<bool> seen(n + 1, false);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (!seen[x - 1]) ans++;
        seen[x] = true;
    }

    cout << ans << "\n";
}