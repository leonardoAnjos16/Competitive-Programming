#include <bits/stdc++.h>

using namespace std;

struct Trie {
private:
    int nodes;
    vector<vector<int>> nxt;
    vector<int> cnt;

public:
    Trie(): nodes(1) {
        cnt.push_back(0);
        nxt.emplace_back(26, -1);
    }

    void insert(string &s) {
        int node = 0;
        for (char c: s) {
            if (nxt[node][c - 'a'] == -1) {
                cnt.push_back(0);
                nxt.emplace_back(26, -1);
                nxt[node][c - 'a'] = nodes++;
            }

            cnt[node]++;
            node = nxt[node][c - 'a'];
        }

        cnt[node]++;
    }

    int query(string &s) {
        int before = 0, after = 0;
        return query(s, before, after);
    }

private:
    int query(string &s, int &before, int &after, int idx = 0, int node = 0) {
        if (idx >= (int) s.size()) {
            after += cnt[node] - 1;
            return idx + min(before, after + 1) + 1;
        }

        int ans = query(s, before, after, idx + 1, nxt[node][s[idx] - 'a']);

        before += cnt[node];
        for (char c = 'a'; c <= 'z'; c++)
            before -= nxt[node][c - 'a'] != -1 ? cnt[nxt[node][c - 'a']] : 0;

        for (char c = 'a'; c < s[idx]; c++)
            before += nxt[node][c - 'a'] != -1 ? cnt[nxt[node][c - 'a']] : 0;

        for (char c = s[idx] + 1; c <= 'z'; c++)
            after += nxt[node][c - 'a'] != -1 ? cnt[nxt[node][c - 'a']] : 0;

        return ans = min(ans, idx + min(before, after + 1) + 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        Trie trie;
        vector<string> file(N);

        for (int i = 0; i < N; i++) {
            cin >> file[i];
            trie.insert(file[i]);
        }

        for (int i = 0; i < N; i++) {
            if (i) cout << " ";

            int ans = trie.query(file[i]);
            cout << ans;
        }

        cout << "\n";
    }
}