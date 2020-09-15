#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k; cin >> n >> k;
    string s; cin >> s;

    set<char> letters; char c;
    for (int i = 0; i < k; i++) {
        cin >> c;
        letters.insert(c);
    }

    int idx = 0;
    long cnt = 0LL, ans = 0LL;

    while (idx < n) {
        while (idx < n && letters.count(s[idx])) idx++, cnt++;
        ans += cnt * (cnt + 1) / 2LL; idx++; cnt = 0;
    }

    ans += cnt * (cnt + 1) / 2LL;
    printf("%lld\n", ans);
}