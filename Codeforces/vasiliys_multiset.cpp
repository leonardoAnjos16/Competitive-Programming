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

vector<vi> trie(1, vi(2, -1));
vi cnt(1, 0);

int bit(int x, int i) {
    return x & (1 << i) ? 1 : 0;
}

void insert(int x) {
    int idx = 30, node = 0;
    while (idx >= 0 && ~trie[node][bit(x, idx)])
        cnt[node]++, node = trie[node][bit(x, idx--)];

    while (idx >= 0) {
        cnt[node]++;
        node = trie[node][bit(x, idx--)] = size(trie);
        trie.pb(vi(2, -1));
        cnt.pb(0);
    }

    cnt[node]++;
}

void remove(int x) {
    int idx = 30, node = 0;
    while (idx >= 0) {
        cnt[node]--;
        node = trie[node][bit(x, idx--)];
    }

    cnt[node]--;
}

int value(int x) {
    int idx = 30, node = 0, ans = 0;
    while (idx >= 0) {
        int b = bit(x, idx);
        if (~trie[node][1 - b] && cnt[trie[node][1 - b]]) {
            node = trie[node][1 - b];
            if (1 - b) ans |= (1 << idx);
        } else {
            node = trie[node][b];
            if (b) ans |= (1 << idx);
        }

        idx--;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    insert(0);
    int q; cin >> q;
    
    while (q--) {
        char c; int x;
        cin >> c >> x;

        if (c == '+') insert(x);
        else if (c == '-') remove(x);
        else {
            int ans = value(x) ^ x;
            cout << ans << "\n";
        }
    }
}