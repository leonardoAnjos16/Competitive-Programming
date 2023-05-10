#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    if (k > n || k > m) cout << "Impossible\n";
    else {
        vector<string> ans(n, string(m, '.'));
        for (int i = 0; i < k; i++)
            ans[i][i] = '*';

        cout << "Possible\n";
        for (string s: ans)
            cout << s << "\n";
    }
}