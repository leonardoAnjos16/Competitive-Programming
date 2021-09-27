#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d[3];
    for (int i = 0; i < 3; i++)
        cin >> d[i];

    int s[3];
    for (int i = 0; i < 3; i++)
        cin >> s[i];

    int ans = 0;
    do {
        int cnt = 0;
        for (int i = 0; i < 3; i++)
            cnt += s[i] > d[i];

        ans = max(ans, cnt);
    } while (next_permutation(s, s + 3));

    cout << ans << "\n";
}