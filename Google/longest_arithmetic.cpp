#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;

        int A[MAX];
        for (int i = 0; i < N; i++)
            cin >> A[i];

        int ans = 2, cnt = 2;
        for (int i = 2; i < N; i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) cnt++;
            else ans = max(ans, cnt), cnt = 2;
        }

        ans = max(ans, cnt);
        cout << "Case #" << t << ": " << ans << "\n";
    }
}