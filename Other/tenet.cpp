#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = (1 << 26) + 5;

int cnt[MAX] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    string S; cin >> S;

    cnt[0] = 1;
    int mask = 0;
    llong ans = 0LL;

    for (int i = 0; i < N; i++) {
        int idx = S[i] - 'a';
        mask ^= (1 << idx);

        ans += cnt[mask];
        for (int j = 0; j < 26; j++)
            ans += cnt[mask ^ (1 << j)];

        cnt[mask]++;
    }

    cout << ans << "\n";
}