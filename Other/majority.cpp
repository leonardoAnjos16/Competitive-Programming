#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int V; cin >> V;

        map<int, int> cnt;
        while (V--) {
            int vote;
            cin >> vote;
            cnt[vote]++;
        }

        int ans = -1;
        for (auto [vote, count]: cnt)
            if (count > cnt[ans]) ans = vote;

        cout << ans << "\n";
    }
}