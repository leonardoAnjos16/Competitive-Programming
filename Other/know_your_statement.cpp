#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct Trie {
private:
    int nodes;
    vector<vector<int>> nxt;
    vector<set<int>> end, pass;

public:
    Trie() {
        nodes = 1;
        nxt.assign(1, vector<int>(26, -1));
        end.assign(1, set<int>());
        pass.assign(1, set<int>());
    }

    void insert(string &s, int v) {
        int node = 0;
        for (char c: s) {
            if (nxt[node][c - 'a'] == -1) {
                nxt.emplace_back(26, -1);
                end.push_back(set<int>());
                pass.push_back(set<int>());
                nxt[node][c - 'a'] = nodes++;
            }

            pass[node].insert(v);
            node = nxt[node][c - 'a'];
        }

        end[node].insert(v);
        pass[node].insert(v);
    }

    void erase(string &s, int v) {
        int node = 0;
        for (char c: s) {
            pass[node].erase(v);
            node = nxt[node][c - 'a'];
        }

        end[node].erase(v);
        pass[node].erase(v);
    }

    bool vprefix(string &s, int l, int r) {
        int node = 0;
        for (char c: s) {
            node = nxt[node][c - 'a'];
            if (node == -1) return false;

            auto it = end[node].lower_bound(l);
            if (it != end[node].end() && *it <= r)
                return true;
        }

        return false;
    }

    bool sprefix(string &s, int l, int r) {
        int node = 0;
        for (char c: s) {
            node = nxt[node][c - 'a'];
            if (node == -1) return false;
        }

        auto it = pass[node].lower_bound(l);
        return it != pass[node].end() && *it <= r;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    Trie trie;
    vector<string> strs(n);

    for (int i = 0; i < n; i++) {
        cin >> strs[i];
        trie.insert(strs[i], i);
    }

    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int i; string s;
            cin >> i >> s;

            trie.erase(strs[i - 1], i - 1);
            trie.insert(s, i - 1);
            strs[i - 1] = s;
        } else {
            int l, r; string s;
            cin >> l >> r >> s;

            bool ans = op == 2 ? trie.vprefix(s, l - 1, r - 1) : trie.sprefix(s, l - 1, r - 1);
            cout << (ans ? "Y" : "N") << "\n";
        }
    }
}