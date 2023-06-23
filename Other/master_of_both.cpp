#include <bits/stdc++.h>

using namespace std;

#define llong long long int

llong extra = 0LL;
llong inversions[26][26] = {0LL};

struct Trie {
private:
    int nodes;
    vector<int> cnt;
    vector<vector<int>> nxt;

public:
    Trie() {
        nodes = 1;
        cnt.assign(1, 0);
        nxt.assign(1, vector<int>(26, -1));
    }

    void insert(string &s) {
        int node = 0;
        for (char c: s) {
            if (nxt[node][c - 'a'] == -1) {
                nxt[node][c - 'a'] = nodes++;
                nxt.emplace_back(26, -1);
                cnt.push_back(0);
            }

            cnt[node]++;
            node = nxt[node][c - 'a'];
        }

        cnt[node]++;
    }

    void solve(string &s) {
        int node = 0;
        for (char c: s) {
            if (node == -1) break;

            for (char d = 'a'; d <= 'z'; d++)
                if (nxt[node][d - 'a'] != -1)
                    inversions[c - 'a'][d - 'a'] += cnt[nxt[node][d - 'a']];

            node = nxt[node][c - 'a'];
        }

        if (node != -1)
            for (char c = 'a'; c <= 'z'; c++)
                if (nxt[node][c - 'a'] != -1)
                    extra += cnt[nxt[node][c - 'a']];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    Trie trie;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        trie.solve(s);
        trie.insert(s);
    }

    while (q--) {
        string t; cin >> t;

        llong ans = extra;
        for (int i = 0; i < 26; i++)
            for (int j = i + 1; j < 26; j++)
                ans += inversions[t[i] - 'a'][t[j] - 'a'];

        cout << ans << "\n";
    }
}