#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong MAX = 1e18;

llong mult(llong a, llong b) {
    // a * b > MAX
    // a > MAX / b
    if (a > MAX / b)
        return MAX + 1;

    return a * b;
}

llong sum(llong a, llong b) {
    if (a + b > MAX)
        return MAX + 1;

    return a + b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, s, m, d, n;
    cin >> r >> s >> m >> d >> n;

    vector<int> b(r);
    for (int i = 0; i < r; i++)
        cin >> b[i];

    vector<vector<int>> ingredients(s + m + d, vector<int>());
    for (int i = 0; i < s + m + d; i++) {
        int k; cin >> k;

        ingredients[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> ingredients[i][j];
            ingredients[i][j]--;
        }
    }

    vector<vector<bool>> bad(s + m + d, vector<bool>(s + m + d, false));
    for (int i = 0; i < n; i++) {
        int i1, i2;
        cin >> i1 >> i2;
        bad[i1 - 1][i2 - 1] = bad[i2 - 1][i1 - 1] = true;
    }

    llong ans = 0LL;
    for (int i = 0; i < s; i++)
        for (int j = s; j < s + m; j++)
            for (int k = s + m; k < s + m + d; k++)
                if (!bad[i][j] && !bad[i][k] && !bad[j][k]) {
                    set<int> used;
                    for (int ingredient: ingredients[i])
                        used.insert(ingredient);

                    for (int ingredient: ingredients[j])
                        used.insert(ingredient);

                    for (int ingredient: ingredients[k])
                        used.insert(ingredient);

                    llong extra = 1LL;
                    for (int ingredient: used)
                        extra = mult(extra, b[ingredient]);

                    ans = sum(ans, extra);
                }

    if (ans > MAX) cout << "too many\n";
    else cout << ans << "\n";
}