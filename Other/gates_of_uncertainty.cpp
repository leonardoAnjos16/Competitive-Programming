#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

vector<tuple<int, int, int>> tree;
vector<vector<vector<long>>> memo;

long count(int should, int does, int node = 1) {
    if (!node) return should == does;

    auto [left, right, F] = tree[node];
    if (F != -1 && F != does) return 0LL;

    long &ans = memo[should][does][node];
    if (~ans) return ans;

    if (F == -1) {
        if (!should && !does) {
            ans = count(1, 1, left) * count(1, 1, right);
            ans %= MOD;
        } else if (!should) {
            ans = 0LL;
            for (int i = 0; i <= 1; i++)
                for (int j = 0; j <= 1 - i; j++) {
                    ans += (count(1, i, left) * count(1, j, right)) % MOD;
                    ans %= MOD;
                }
        } else if (!does) {
            ans = 0LL;
            for (int i = 0; i <= 1; i++)
                for (int j = 0; j <= 1 - i; j++) {
                    ans += (count(i, 1, left) * count(j, 1, right)) % MOD;
                    ans %= MOD;
                }
        } else {
            ans = 0LL;
            for (int i = 0; i <= 1; i++)
                for (int j = 0; j <= 1 - i; j++)
                    for (int k = 0; k <= 1; k++)
                        for (int l = 0; l <= 1 - k; l++) {
                            ans += (count(i, k, left) * count(j, l, right)) % MOD;
                            ans %= MOD;
                        }
        }
    } else {
        if (!should) {
            ans = 0LL;
            for (int i = 0; i <= 1; i++)
                for (int j = 0; j <= 1; j++) {
                    ans += (count(1, i, left) * count(1, j, right)) % MOD;
                    ans %= MOD;
                }
        } else {
            ans = 0LL;
            for (int i = 0; i <= 1; i++)
                for (int j = 0; j <= 1 - i; j++)
                    for (int k = 0; k <= 1; k++)
                        for (int l = 0; l <= 1; l++) {
                            ans += (count(i, k, left) * count(j, l, right)) % MOD;
                            ans %= MOD;
                        }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    tree.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        int X, Y, F;
        cin >> X >> Y >> F;
        tree[i] = make_tuple(X, Y, F);
    }

    memo.assign(2, vector<vector<long>>(2, vector<long>(N + 5, -1LL)));

    long ans = (count(0, 1) + count(1, 0)) % MOD;
    cout << ans << "\n";
}