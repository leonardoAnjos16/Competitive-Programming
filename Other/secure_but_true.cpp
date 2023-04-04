#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e12;

string letters = "AHIMOTUVWXY";

llong count(int size) {
    llong ans = 1LL;
    for (int i = 0; i < size && ans < INF; i++)
        ans *= 11LL;

    return ans;
}

string solve(int size, int idx, int start = 0) {
    string ans = "";
    for (int i = 0; i < size; i++) {
        while (start < 11 && count(size - i - 1) < idx)
            start++, idx -= count(size - i - 1);

        assert(start < 11);
        ans += letters[start];
        start = 0;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int K; string S;
        cin >> K >> S;

        int n = S.size();
        llong same_size = 0LL;

        for (int i = 0; i < n && same_size < INF; i++) {
            int idx = upper_bound(letters.begin(), letters.end(), S[i]) - letters.begin();
            same_size += (11LL - idx) * count(n - i - 1);
        }

        if (same_size >= K) {
            int idx = n - 1;
            llong cnt = 0LL;

            int aux = upper_bound(letters.begin(), letters.end(), S[idx]) - letters.begin();
            while (idx > 0 && cnt + (11LL - aux) * count(n - idx - 1) < K) {
                cnt += (11LL - aux) * count(n - idx - 1);
                aux = upper_bound(letters.begin(), letters.end(), S[--idx]) - letters.begin();
            }

            K -= cnt;
            string ans = S.substr(0, idx) + solve(n - idx, K, aux);
            cout << ans << "\n";
        } else {
            int size = n + 1;
            llong cnt = same_size;

            while (cnt + count(size) < K)
                cnt += count(size++);

            K -= cnt;
            string ans = solve(size, K);
            cout << ans << "\n";
        }
    }
}