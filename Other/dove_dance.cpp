#include <bits/stdc++.h>

using namespace std;

#define long long long int

struct Trie {
private:
    const int MAX = 26;

    int nodes;
    vector<vector<int>> trie;
    vector<int> cnt;

public:
    Trie() {
        nodes = 1;
        trie.emplace_back(MAX, -1);
        cnt.push_back(0);
    }

    void insert(string &s, int node = 0, int i = 0) {
        if (i >= (int) s.size()) cnt[node]++;
        else {
            if (trie[node][s[i] - 'a'] == -1) {
                trie[node][s[i] - 'a'] = nodes++;
                trie.emplace_back(MAX, -1);
                cnt.push_back(0);
            }

            cnt[node]++;
            insert(s, trie[node][s[i] - 'a'], i + 1);
        }
    }

    bool query(string &s, int node = 0, int i = 0) {
        if (i >= (int) s.size()) return cnt[node] > 0;
        if (trie[node][s[i] - 'a'] == -1) return false;
        return query(s, trie[node][s[i] - 'a'], i + 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q; cin >> Q;

    bool reversed = false;
    Trie forward, backward;

    while (Q--) {
        int op; cin >> op;
        if (op == 1) {
            string S; cin >> S;
            if (!reversed) {
                forward.insert(S);
                reverse(S.begin(), S.end());
                backward.insert(S);
            } else {
                backward.insert(S);
                reverse(S.begin(), S.end());
                forward.insert(S);
            }
        } else if (op == 2) {
            string T; cin >> T;

            bool is_prefix;
            if (!reversed) is_prefix = forward.query(T);
            else is_prefix = backward.query(T);

            cout << (is_prefix ? "1" : "0") << "\n";
        } else {
            reversed = !reversed;
        }
    }
}