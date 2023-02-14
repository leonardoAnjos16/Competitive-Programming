#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 30;

const int digit[MAX] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    map<llong, int> cnt;
    while (N--) {
        string s; cin >> s;

        llong id = 0LL;
        for (char c: s) {
            id *= 10LL;
            id += digit[c - 'a'];
        }

        cnt[id]++;
    }

    while (Q--) {
        llong id; cin >> id;

        int ans = cnt[id];
        cout << ans << "\n";
    }
}