#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, A, B;
        cin >> N >> A >> B;

        string S; cin >> S;

        int ans = 0;
        for (int i = 0; i < N; i++)
            ans += (S[i] == '0' ? A : B);

        cout << ans << "\n";
    }
}