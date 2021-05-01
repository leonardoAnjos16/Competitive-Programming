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

const int MAX = 1e6 + 5;

int trie[MAX][30], cnt[MAX], nodes;

void insert(string &s) {
    int idx = 0, node = 0;
    while (idx < size(s) && ~trie[node][s[idx] - 'a'])
        cnt[node]++, node = trie[node][s[idx++] - 'a'];

    while (idx < size(s)) {
        cnt[node]++;
        node = trie[node][s[idx++] - 'a'] = nodes++;
        memset(trie[node], -1, sizeof trie[node]);
    }

    cnt[node]++;
}

int count(string &s) {
    int idx = 0, node = 0;
    while (idx < size(s)) {
        if (trie[node][s[idx] - 'a'] == -1)
            return 0;

        node = trie[node][s[idx++] - 'a'];
    }

    return cnt[node];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    nodes = 1;
    memset(cnt, 0, sizeof cnt);
    memset(trie[0], -1, sizeof trie[0]);

    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        insert(s);
    }

    while (Q--) {
        string s; cin >> s;
        
        int ans = count(s);
        cout << ans << "\n";
    }
}