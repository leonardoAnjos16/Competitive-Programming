#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e5 + 5;

map<int, string> word;

struct Trie {
private:
    int q;
    vector<vi> trie;
    vi index, smallest;

public:
    Trie() {
        q = 0;
        index.assign(1, -1);
        smallest.assign(1, -1);
        trie.assign(1, vi(30, -1));
    }

    int insert(string &s, int idx = 0, int node = 0) {
        if (idx >= size(s)) {
            word[++q] = s;
            index[node] = q;

            if (smallest[node] == -1 || compare(s, word[smallest[node]]))
                smallest[node] = q;

            return smallest[node];
        }
        
        if (trie[node][s[idx] - 'a'] == -1) {
            trie[node][s[idx] - 'a'] = size(trie);
            trie.pb(vi(30, -1));
            smallest.pb(-1);
            index.pb(-1);
        }

        int nxt = insert(s, idx + 1, trie[node][s[idx] - 'a']);
        if (smallest[node] == -1 || compare(word[nxt], word[smallest[node]]))
            smallest[node] = nxt;

        return smallest[node];
    }

    void remove(string &s, int idx = 0, int node = 0) {
        if (idx >= size(s)) index[node] = -1, q++;
        else remove(s, idx + 1, trie[node][s[idx] - 'a']);

        smallest[node] = index[node];
        for (int i = 0; i < 26; i++) {
            int n = trie[node][i];
            if (n == -1) continue;

            if (smallest[node] == -1 || (smallest[n] != -1 && compare(word[smallest[n]], word[smallest[node]])))
                smallest[node] = smallest[n];
        }
    }

    int get_index(string &s) {
        int idx = 0, node = 0; q++;
        while (idx < size(s)) {
            if (trie[node][s[idx] - 'a'] == -1)
                return -1;

            node = trie[node][s[idx++] - 'a'];
        }

        return smallest[node];
    }

private:
    bool compare(string &s, string &t) {
        return size(s) < size(t) || (size(s) == size(t) && s < t);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Trie trie;
    int Q; cin >> Q;

    while (Q--) {
        int op; cin >> op;
        if (op == 1) {
            string X; cin >> X;
            trie.insert(X);
        } else if (op == 2) {
            int X; cin >> X;
            trie.remove(word[X]);
        } else {
            string X; cin >> X;

            int ans = trie.get_index(X);
            cout << ans << "\n";
        }
    }
}