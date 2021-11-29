#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct Trie {
private:
    vector<vector<int>> nxt;
    vector<int> cnt;

public:
    Trie() {
        nxt.assign(1, vector<int>(2, -1));
        cnt.assign(1, 0);
    }

    void insert(long v, int i = 61, int node = 0) {
        cnt[node]++;
        if (i >= 0) {
            int bit = (v & (1LL << i)) ? 1 : 0;
            if (nxt[node][bit] == -1) {
                nxt[node][bit] = nxt.size();
                nxt.emplace_back(2, -1);
                cnt.push_back(0);
            }

            insert(v, i - 1, nxt[node][bit]);
        }
    }

    void remove(long v, int i = 61, int node = 0) {
        assert(cnt[node]-- > 0);
        if (i >= 0) {
            int bit = (v & (1LL << i)) ? 1 : 0;
            remove(v, i - 1, nxt[node][bit]);
        }
    }

    int query(long v, int i = 61, int node = 0) {
        int bit = (v & (1LL << i)) ? 1 : 0, aux = nxt[node][bit];
        if (i < 0 || aux == -1 || !cnt[aux]) return 0;
        return 1 + query(v, i - 1, nxt[node][bit]);
    }
};

int N;
vector<int> A;
vector<vector<int>> tree;
vector<vector<pair<int, int>>> queries;
vector<int> ans;

void solve(Trie &trie, int node = 0, int parent = -1) {
    trie.insert(A[node]);
    for (auto [V, idx]: queries[node])
        ans[idx] = trie.query(V);

    for (auto child: tree[node])
        if (child != parent)
            solve(trie, child, node);

    trie.remove(A[node]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        cin >> N;

        A.resize(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        tree.assign(N, vector<int>());
        for (int i = 1; i < N; i++) {
            int u, v;
            cin >> u >> v;

            tree[u - 1].push_back(v - 1);
            tree[v - 1].push_back(u - 1);
        }

        int Q; cin >> Q;
        queries.assign(N, vector<pair<int, int>>());
        ans.resize(Q);

        for (int i = 0; i < Q; i++) {
            int V, X;
            cin >> V >> X;
            queries[X - 1].emplace_back(V, i);
        }

        Trie trie;
        solve(trie);

        for (int i = 0; i < Q; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}