#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        string A; cin >> A;
        string B; cin >> B;

        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            bool change = false;
            for (int i = 0; i < N && !change; i++)
                if (A[i] != c && B[i] == c) change = true;

            ans += change;
        }

        cout << ans << "\n";
    }
}