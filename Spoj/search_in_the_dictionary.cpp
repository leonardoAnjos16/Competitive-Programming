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

const int MAX = 3e5 + 5;

int trie[MAX][30], nodes;
bool terminal[MAX];

bool find(string &s) {
    int idx = 0, node = 0;
    while (idx < size(s)) {
        if (trie[node][s[idx] - 'a'] == -1)
            return false;

        node = trie[node][s[idx++] - 'a'];
    }

    return terminal[node];
}

void insert(string &s) {
    if (find(s)) return;

    int idx = 0, node = 0;
    while (idx < size(s) && ~trie[node][s[idx] - 'a'])
        node = trie[node][s[idx++] - 'a'];

    while (idx < size(s)) {
        node = trie[node][s[idx++] - 'a'] = nodes++;
        memset(trie[node], -1, sizeof trie[node]);
    }

    terminal[node] = true;
}

void get_words(vector<string> &v, string s, int node) {
    for (int i = 0; i < 26; i++) {
        if (~trie[node][i]) {
            if (terminal[trie[node][i]])
                v.pb(s + (char) (i + 'a'));

            get_words(v, s + (char) (i + 'a'), trie[node][i]);
        }
    }
}

vector<string> words(string &prefix) {
    int idx = 0, node = 0;
    while (idx < size(prefix)) {
        if (trie[node][prefix[idx] - 'a'] == -1)
            return vector<string>();

        node = trie[node][prefix[idx++] - 'a'];
    }

    vector<string> ans;
    get_words(ans, prefix, node);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    nodes = 1;
    memset(trie[0], -1, sizeof trie[0]);
    memset(terminal, 0, sizeof terminal);

    int N; cin >> N;
    while (N--) {
        string s;
        cin >> s;
        insert(s);
    }

    int K; cin >> K;
    for (int k = 1; k <= K; k++) {
        string s; cin >> s;

        vector<string> ans = words(s);
        cout << "Case #" << k << ":\n";

        if (ans.empty()) cout << "No match.\n";
        else for (auto s: ans) cout << s << "\n";
    }
}