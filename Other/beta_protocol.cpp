#include <bits/stdc++.h>

using namespace std;

struct Trie {
private:
    int nodes;
    vector<int> cnt;
    vector<vector<int>> nxt;

public:
    Trie() {
        nodes = 1;
        cnt.assign(1, 0);
        nxt.assign(1, vector<int>(2, -1));
    }

    void insert(string &s) {
        int node = 0;
        for (int i = 0; i < (int) s.size(); i++) {
            cnt[node]++;
            if (nxt[node][s[i] - '0'] == -1) {
                cnt.push_back(0);
                nxt.emplace_back(2, -1);
                nxt[node][s[i] - '0'] = nodes++;
            }

            node = nxt[node][s[i] - '0'];
        }

        cnt[node]++;
    }

    int count_questions(int node = 0) {
        if (node == -1) return 1;

        int ans = 1;
        if (cnt[node] == 1) return ans;

        ans += count_questions(nxt[node][0]);
        ans += count_questions(nxt[node][1]);

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    Trie trie;
    for (int i = 0; i < N; i++) {
        string ID; cin >> ID;
        trie.insert(ID);
    }

    int ans = trie.count_questions();
    cout << ans << "\n";
}