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

int trie[MAX][30], nodes;

void insert(string &s) {
    int idx = 0, node = 0;
    while (idx < size(s) && ~trie[node][s[idx] - 'a'])
        node = trie[node][s[idx++] - 'a'];

    while (idx < size(s)) {
        node = trie[node][s[idx++] - 'a'] = nodes++;
        memset(trie[node], -1, sizeof trie[node]);
    }
}

pair<bool, bool> outcomes(int node = 0) {
    bool can_play = false;
    pair<bool, bool> ans = { false, false };

    for (int i = 0; i < 26; i++)
        if (~trie[node][i]) {
            can_play = true;
            auto aux = outcomes(trie[node][i]);
            ans.fst |= !aux.fst; ans.snd |= !aux.snd;
        }

    if (!can_play)
        ans.fst = true;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    nodes = 1;
    memset(trie[0], -1, sizeof trie[0]);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert(s);
    }

    pll ans = outcomes();
    if (ans.fst && ans.snd) cout << "First\n";
    else if (!ans.snd) cout << "Second\n";
    else if (k & 1) cout << "First\n";
    else cout << "Second\n";
}