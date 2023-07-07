#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int LOG = 24;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int a[1 << LOG] = {0};
    for (int i = 0; i < n; i++) {
        string word; cin >> word;

        sort(word.begin(), word.end());
        word.erase(unique(word.begin(), word.end()), word.end());

        int sz = word.size();
        for (int j = 1; j < (1 << sz); j++) {
            int mask = 0;
            for (int k = 0; k < sz; k++)
                if (j & (1 << k))
                    mask |= 1 << (word[k] - 'a');

            a[mask] += __builtin_popcount(j) & 1 ? 1 : -1;
        }
    }

    llong cnt[1 << LOG] = {0LL};
    for (int i = 0; i < (1 << LOG); i++)
        cnt[i] = a[i];

    for (int i = 0; i < LOG; i++)
        for (int j = 0; j < (1 << LOG); j++)
            if (j & (1 << i))
                cnt[j] += cnt[j ^ (1 << i)];

    llong ans = 0LL;
    for (int i = 0; i < (1 << LOG); i++)
        ans ^= cnt[i] * cnt[i];

    cout << ans << "\n";
}