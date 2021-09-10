#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("bulls.in", "r", stdin);
    freopen("bulls.out", "w", stdout);

    string s, t;
    cin >> s >> t;

    int cnt[2][10] = {0};
    for (int i = 0; i < 4; i++)
        cnt[0][s[i] - '0']++;

    for (int i = 0; i < 4; i++)
        cnt[1][t[i] - '0']++;

    int bulls = 0;
    for (int i = 0; i < 4; i++)
        if (s[i] == t[i]) {
            bulls++;
            cnt[0][s[i] - '0']--;
            cnt[1][t[i] - '0']--;
        }

    int cows = 0;
    for (int i = 0; i < 10; i++)
        cows += min(cnt[0][i], cnt[1][i]);

    cout << bulls << " " << cows << "\n";
}