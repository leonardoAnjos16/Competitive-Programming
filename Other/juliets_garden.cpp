#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<bool> vis(n, false);
    int curr = 1, minute = 1, cnt = 0;

    while (!vis[curr - 1]) {
        cnt++;
        vis[curr - 1] = true;

        curr = (curr + minute - 1) % n + 1;
        minute++;
    }

    cout << (cnt >= n ? "YES" : "NO") << "\n";
}