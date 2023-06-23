#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    string s; cin >> s;

    int idx = 0, ans = 0;
    while (idx < N) {
        while (idx < N && s[idx] == 'b') idx++;

        int cnt = 0;
        while (idx < N && s[idx] == 'a')
            idx++, cnt++;

        if (cnt > 1) ans += cnt;
    }

    cout << ans << "\n";
}