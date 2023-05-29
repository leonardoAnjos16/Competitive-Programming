#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MOD = 1e9 + 7;

template<typename T = string, typename U = char, const int SIZE = 26, const int OFFSET = 'a'>
struct AhoCorasick {
private:
    struct Node {
        int nxt[SIZE];
        int link, slink, id;
        int parent;
        U label;

        Node(int parent = -1, U label = '-'): parent(parent), label(label) {
            memset(nxt, -1, sizeof nxt);
            link = slink = id = -1;
        }

        int& operator [](U label) {
            return nxt[label - OFFSET];
        }
    };

    int size, patterns;
    vector<Node> nodes;

public:
    AhoCorasick() {
        size = 1;
        patterns = 0;
        nodes.resize(1);
    }

    void insert(T &pattern) {
        int node = 0;
        for (int i = 0; i < (int) pattern.size(); i++) {
            if (nodes[node][pattern[i]] == -1) {
                nodes[node][pattern[i]] = size++;
                nodes.emplace_back(node, pattern[i]);
            }

            node = nodes[node][pattern[i]];
        }

        nodes[node].id = patterns++;
    }

    int id(int node) {
        return nodes[node].id;
    }

    int next(int node, U label) {
        if (nodes[node][label] == -1) {
            if (!node) nodes[node][label] = 0;
            else nodes[node][label] = next(next_suffix(node), label);
        }

        return nodes[node][label];
    }

    int next_suffix(int node) {
        if (!node || !nodes[node].parent) return 0;

        if (nodes[node].link == -1)
            nodes[node].link = next(next_suffix(nodes[node].parent), nodes[node].label);

        return nodes[node].link;
    }

    int next_terminal(int node) {
        if (!node || !nodes[node].parent) return 0;

        if (nodes[node].slink == -1) {
            nodes[node].slink = next_suffix(node);
            if (nodes[node].slink && nodes[nodes[node].slink].id == -1)
                nodes[node].slink = next_terminal(nodes[node].slink);
        }

        return nodes[node].slink;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    AhoCorasick matcher;
    vector<string> words(N);

    for (int i = 0; i < N; i++) {
        cin >> words[i];
        matcher.insert(words[i]);
    }

    string S; cin >> S;
    N = S.size();

    vector<int> dp(N + 1, 0);
    dp[0] = 1;

    int node = 0;
    for (int i = 1; i <= N; i++) {
        node = matcher.next(node, S[i - 1]);
        if (matcher.id(node) != -1) {
            int sz = words[matcher.id(node)].size();
            dp[i] = (dp[i] + dp[i - sz]) % MOD;
        }

        int curr = matcher.next_terminal(node);
        while (curr) {
            int sz = words[matcher.id(curr)].size();
            dp[i] = (dp[i] + dp[i - sz]) % MOD;
            curr = matcher.next_terminal(curr);
        }
    }

    int ans = dp[N];
    cout << ans << "\n";
}