#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long K; cin >> K;
    string S; cin >> S;
    int n = S.size();

    int l = 0, r = n - 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        long num = 1LL;
        int idx = 1, rem = 0;

        while (rem < mid && n - idx > mid - rem) {
            int aux = idx;
            while (aux < n && S[aux] == '1') aux++;

            if (aux > n || aux - idx > mid - rem) num <<= 1, num++, idx++;
            else num <<= 1, rem += aux - idx, idx = aux + 1;
        }

        if (rem >= mid)
            while (idx < n) {
                num <<= 1;
                if (S[idx++] == '1')
                    num++;
            }

        if (num > K) l = mid + 1;
        else r = mid - 1, ans = mid;
    }

    cout << ans << "\n";
}