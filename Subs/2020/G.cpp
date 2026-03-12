#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C; cin >> C;

    int ans = 100, curr = 100;
    for (int i = 0; i < C; i++) {
        int V; cin >> V;
        curr += V;
        ans = max(ans, curr);
    }

    cout << ans << "\n";
}