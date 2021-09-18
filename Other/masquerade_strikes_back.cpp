#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, int> last;
    map<int, bool> inv;

    int n; cin >> n;
    vector<pair<int, int>> ans(n);

    for (int i = 0; i < n; i++) {
        int c; cin >> c;

        if (!last.count(c)) last[c] = 1, ans[i] = make_pair(1, c);
        else if (!inv[c] && last[c] * last[c] < c) inv[c] = true, ans[i] = make_pair(c / last[c], last[c]);
        else {
            inv[c] = false;
            bool done = false;

            for (int j = last[c] + 1; j * j <= c && !done; j++)
                if (!(c % j)) last[c] = j, done = true;

            if (!done) {
                cout << "NO\n";
                return 0;
            }

            ans[i] = make_pair(last[c], c / last[c]);
        }
    }

    cout << "YES\n";
    for (auto [a, b]: ans)
        cout << a << " " << b << "\n";
}