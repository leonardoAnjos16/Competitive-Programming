#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        llong ans = 0LL;
        for (int i = 1; i <= N; i++)
            ans += 1LL * i * i * M;

        cout << ans << "\n";
    }
}