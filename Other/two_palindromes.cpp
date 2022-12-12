#include <bits/stdc++.h>

using namespace std;

int MAX = 26;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;

    int cnt[MAX] = {0};
    for (char c: s)
        cnt[c - 'a']++;

    for (char c: t)
        cnt[c - 'a']++;

    int odd = 0;
    for (int i = 0; i < MAX; i++)
        if (cnt[i] & 1) odd++;

    cout << (odd <= 1 ? "YES" : "NO") << "\n";
}