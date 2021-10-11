#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<vector<int>> g;
vector<int> memo;

int pieces(int i) {
    if (g[i].empty()) return 1;

    int &ans = memo[i];
    if (~ans) return ans;

    ans = 0;
    for (auto v: g[i])
        ans = max(ans, pieces(v) + 1);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<vector<int>> p(n);
    map<int, vector<int>> pos;

    for (int i = 0; i < n; i++) {
        int pi; cin >> pi;
        for (int j = 2; j * j <= pi; j++)
            if (!(pi % j)) {
                p[i].push_back(j);
                pos[j].push_back(i);

                while (!(pi % j))
                    pi /= j;
            }

        if (pi > 1) {
            p[i].push_back(pi);
            pos[pi].push_back(i);
        }
    }

    g.assign(n, vector<int>());
    for (int i = 0; i < n; i++)
        for (auto prime: p[i]) {
            auto it = upper_bound(pos[prime].begin(), pos[prime].end(), i);
            if (it != pos[prime].end()) g[i].push_back(*it);
        }

    memo.assign(n, -1);

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, pieces(i));
    
    cout << ans << "\n";
}