#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<long long int> tests(n, 0LL);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        while (k--) {
            int solution; cin >> solution;
            tests[i] |= 1LL << (solution - 1);
        }
    }

    int ans = (1 << n) - 1;
    for (int i = 0; i < (1 << n); i++) {
        long long int solutions = 0LL;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                solutions |= tests[j];

        if (solutions == (1LL << m) - 1LL && __builtin_popcount(i) < __builtin_popcount(ans))
            ans = i;
    }

    cout << __builtin_popcount(ans) << "\n";

    bool space = false;
    for (int i = 0; i < n; i++)
        if (ans & (1 << i)) {
            if (space) cout << " ";
            space = true;

            cout << (i + 1);
        }

    cout << "\n";
}