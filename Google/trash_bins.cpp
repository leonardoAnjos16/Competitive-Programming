#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        string S; cin >> S;

        vector<int> pos(1, -INF);
        for (int i = 0; i < N; i++)
            if (S[i] == '1') pos.push_back(i);

        pos.push_back(INF);

        int curr = 0;
        long ans = 0LL;

        for (int i = 0; i < N; i++) {
            ans += min(i - pos[curr], pos[curr + 1] - i);
            if (S[i] == '1') curr++;
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }
}