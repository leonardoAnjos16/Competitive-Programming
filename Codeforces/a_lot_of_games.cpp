#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int WIN = 0;
const int LOSE = 1;

struct Trie {
private:
    int nodes = 1;
    vector<vector<int>> nxt;

public:
    Trie() {
        nxt.emplace_back(26, -1);
    }

    void insert(string &s) {
        int node = 0, idx = 0;
        while (idx < (int) s.size() && nxt[node][s[idx] - 'a'] != -1)
            node = nxt[node][s[idx++] - 'a'];

        while (idx < (int) s.size()) {
            nxt[node][s[idx++] - 'a'] = nodes;
            nxt.emplace_back(26, -1);
            node = nodes++;
        }
    }

    bool can_win() {
        return can(WIN);
    }

    bool can_lose() {
        return can(LOSE);
    }

private:
    bool can(int action, int node = 0) {
        bool leaf = true;
        for (int i = 0; i < 26 && leaf; i++)
            if (nxt[node][i] != -1) leaf = false;

        if (leaf) return action == LOSE ? true : false;

        bool ans = false;
        for (int i = 0; i < 26 && !ans; i++)
            if (nxt[node][i] != -1 && !can(action, nxt[node][i]))
                ans = true;

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    Trie tree;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        tree.insert(s);
    }

    if (tree.can_win() && tree.can_lose()) cout << "First\n";
    else if (tree.can_win() && (k & 1)) cout << "First\n";
    else cout << "Second\n";
}