#include <bits/stdc++.h>

using namespace std;

#define llong long long int

template<typename T = string, typename U = char, const int SIZE = 26, const int OFFSET = 'a'>
struct Trie {
private:
    int nodes;
    vector<int> cnt;
    vector<vector<int>> nxt;

public:
    Trie() {
        nodes = 1;
        cnt.assign(1, 0);
        nxt.assign(1, vector<int>(SIZE, -1));
    }

    void insert(T &s) {
        int node = 0;
        for (U c: s) {
            if (nxt[node][c - OFFSET] == -1) {
                nxt[node][c - OFFSET] = nodes++;
                nxt.emplace_back(SIZE, -1);
                cnt.push_back(0);
            }

            cnt[node]++;
            node = nxt[node][c - OFFSET];
        }

        cnt[node]++;
    }

    bool prefix(string &s) {
        int node = 0;
        for (U c: s) {
            if (nxt[node][c - OFFSET] == -1)
                return false;

            node = nxt[node][c - OFFSET];
        }

        return cnt[node] > 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<string> numbers(n);
        Trie<string, char, 10, '0'> trie;

        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
            trie.insert(numbers[i]);
        }

        bool consistent = true;
        for (int i = 0; i < n && consistent; i++)
            if (trie.prefix(numbers[i]))
                consistent = false;

        cout << (consistent ? "YES" : "NO") << "\n";
    }
}