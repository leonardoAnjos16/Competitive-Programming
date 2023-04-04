#include <bits/stdc++.h>

using namespace std;

#define llong __int128

const int MAX = 35;

int m, n, p;
vector<vector<llong>> memo;

llong count(int i = 0, int right = 0) {
    if (i >= p - 1) return right == n - 1;

    llong &ans = memo[i][right];
    if (~ans) return ans;

    ans = (m - 2 * (n - right) - i) * count(i + 1, right);
    if (right + 1 < n)
        ans += 2 * (n - right - 1) * count(i + 1, right + 1);

    return ans;
}

llong gcd(llong a, llong b) {
    if (!b) return a;
    return gcd(b, a % b);
}

void print(llong x) {
    if (!x) cout << "0";
    else {
        string ans = "";
        while (x) {
            ans += '0' + (x % 10);
            x /= 10;
        }

        reverse(ans.begin(), ans.end());
        cout << ans;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    llong comb[MAX][MAX];
    for (int i = 1; i < MAX; i++) {
        comb[i][0] = comb[i][i] = 1LL;
        for (int j = 1; j < i; j++)
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }

    cin >> m >> n >> p;

    if (p < n) cout << "0/1\n";
    else if (!p) cout << "1/1\n";
    else {
        memo.assign(p + 5, vector<llong>(n + 5, -1));

        llong x = 2 * n * count();
        llong y = comb[m][p];

        for (int i = 2; i <= p; i++) {
            if (!(x % i)) x /= i;
            else y *= i;
        }

        llong g = gcd(x, y);
        x /= g; y /= g;

        print(x);
        cout << "/";
        print(y);
        cout << "\n";
    }
}