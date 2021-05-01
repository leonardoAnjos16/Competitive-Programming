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

struct Trie {
private:
    vector<vi> trie;
    vector<pair<string, int>> most_occuring;
    vi cnt;

public:
    Trie() {
        most_occuring.pb({ "", 0 });
        trie.pb(vi(30, -1));
        cnt.pb(0);
    }

    pair<string, int> insert(string &s, int idx = 0, int node = 0) {
        if (idx >= size(s)) {
            pair<string, int> aux = { s, ++cnt[node] };
            if (aux.snd > most_occuring[node].snd || (aux.snd == most_occuring[node].snd && aux.fst < most_occuring[node].fst))
                most_occuring[node] = aux;

            return most_occuring[node];
        }

        if (trie[node][s[idx] - 'a'] == -1) {
            trie[node][s[idx] - 'a'] = size(trie);
            most_occuring.pb({ "", 0 });
            trie.pb(vi(30, -1));
            cnt.pb(0);
        }

        auto aux = insert(s, idx + 1, trie[node][s[idx] - 'a']);
        if (aux.snd > most_occuring[node].snd || (aux.snd == most_occuring[node].snd && aux.fst < most_occuring[node].fst))
            most_occuring[node] = aux;

        return most_occuring[node];
    }

    pair<string, int> get_most_occuring(string &prefix) {
        int idx = 0, node = 0;
        while (idx < size(prefix)) {
            if (trie[node][prefix[idx] - 'a'] == -1)
                return { "", 0 };

            node = trie[node][prefix[idx++] - 'a'];
        }

        return most_occuring[node];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Trie trie;
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        trie.insert(s);
    }

    int q; cin >> q;
    while (q--) {
        string s; cin >> s;

        auto ans = trie.get_most_occuring(s);
        if (ans.snd <= 0) cout << "-1\n";
        else cout << ans.fst << " " << ans.snd << "\n";
    }
}