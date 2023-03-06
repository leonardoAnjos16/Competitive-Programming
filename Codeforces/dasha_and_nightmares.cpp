#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 26;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    llong ans = 0LL;
    unordered_map<int, int> masks[2][MAX];

    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        int odd = (int) s.size() % 2, mask = 0, letter = 0;
        for (char c: s) {
            mask ^= (1 << (c - 'a'));
            letter |= (1 << (c - 'a'));
        }

        for (int i = 0; i < MAX; i++)
            if (!(letter & (1 << i))) {
                int target = mask ^ ((1 << MAX) - 1);
                if (target & (1 << i)) target ^= (1 << i);

                ans += masks[1 - odd][i][target];
                masks[odd][i][mask]++;
            }
    }

    cout << ans << "\n";
}