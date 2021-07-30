#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    int n = s.size();

    int m; cin >> m;
    vector<int> invs(n + 1, 0);

    while (m--) {
        int a; cin >> a;
        invs[a - 1]++;
        invs[n - a + 1]--;
    }

    for (int i = 1; i < n; i++)
        invs[i] += invs[i - 1];

    for (int i = 0; i < n; i++)
        assert(invs[i] == invs[n - i - 1]);

    for (int i = 0; i < n / 2; i++)
        if (invs[i] & 1)
            swap(s[i], s[n - i - 1]);

    cout << s << "\n";
}