#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct Trie {
private:
    int k, nodes;
    vector<vector<int>> nxt;
    vector<int> indices;

public:
    Trie(int k): k(k) {
        nodes = 1;
        indices.assign(1, -1);
        nxt.assign(1, vector<int>(2, -1));
    }

    void insert(int x, int idx) {
        int node = 0;
        for (int i = k - 1; i >= 0; i--) {
            if (nxt[node][bit(x, i)] == -1) {
                nxt[node][bit(x, i)] = nodes++;
                nxt.emplace_back(2, -1);
                indices.push_back(-1);
            }

            node = nxt[node][bit(x, i)];
        }

        indices[node] = idx;
    }

    tuple<int, int, int> query(int x) {
        int ans = 0, chosen = 0, node = 0;
        for (int i = k - 1; i >= 0; i--) {
            assert(node != -1);
            if (nxt[node][bit(x, i)] == -1) node = nxt[node][1 - bit(x, i)];
            else {
                ans += 1 << i;
                if (!bit(x, i)) chosen |= (1 << i);
                node = nxt[node][bit(x, i)];
            }
        }

        return make_tuple(ans, indices[node], chosen);
    }

private:
    int bit(int x, int i) {
        return x & (1 << i) ? 1 : 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        Trie trie(k);
        int mx = -1, i1 = -1, i2 = -1, x = -1;

        int a; cin >> a;
        trie.insert(a, 0);

        for (int i = 1; i < n; i++) {
            cin >> a;

            auto [nmx, idx, nx] = trie.query(a);
            if (nmx > mx) {
                mx = nmx;
                i1 = idx + 1;
                i2 = i + 1;
                x = nx;
            }

            trie.insert(a, i);
        }

        cout << i1 << " " << i2 << " " << x << "\n";
    }
}