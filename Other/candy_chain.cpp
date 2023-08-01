#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e9 + 5;
const int NOANS = INT_MAX;

struct Trie {
private:
    int nodes;
    vector<int> value;
    vector<vector<int>> nxt;

public:
    Trie() {
        nodes = 1;
        value.assign(1, 0);
        nxt.assign(1, vector<int>(26, -1));
    }

    void insert(string &s, int v) {
        int node = 0;
        for (int i = 0; i < (int) s.size(); i++) {
            if (nxt[node][s[i] - 'a'] == -1) {
                nxt[node][s[i] - 'a'] = nodes++;
                nxt.emplace_back(26, -1);
                value.push_back(0);
            }

            node = nxt[node][s[i] - 'a'];
        }

        value[node] = max(value[node], v);
    }

    int size() {
        return nodes;
    }

    int get_next(int node, char c) {
        return nxt[node][c - 'a'];
    }

    int get_value(int node) {
        return value[node];
    }
};

Trie trie;
string chain;
vector<vector<vector<int>>> memo;

int max_earnings(int l, int r, int node = 0) {
    if (node == -1) return -INF;
    if (l > r) return trie.get_value(node);

    int &ans = memo[l][r][node];
    if (ans != NOANS) return ans;

    ans = -INF;
    if (node) ans = trie.get_value(node) + max_earnings(l, r);

    for (int m = l; m <= r; m++)
        ans = max(ans, max_earnings(l, m - 1) + max_earnings(m + 1, r, trie.get_next(node, chain[m])));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> chain;

    int C; cin >> C;
    while (C--) {
        string portion; int P;
        cin >> portion >> P;

        trie.insert(portion, P);

        reverse(portion.begin(), portion.end());
        trie.insert(portion, P);
    }

    int n = chain.size();
    memo.assign(n + 5, vector<vector<int>>(n + 5, vector<int>(trie.size() + 5, NOANS)));

    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        for (int j = 1; j <= i; j++)
            dp[i] = max(dp[i], dp[j - 1] + max_earnings(j - 1, i - 1));
    }

    int ans = dp[n];
    cout << ans << "\n";
}