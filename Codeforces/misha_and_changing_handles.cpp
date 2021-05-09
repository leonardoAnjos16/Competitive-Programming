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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;

    set<string> seen;
    vector<string> handles;
    map<string, string> changes;

    while (q--) {
        string o, n;
        cin >> o >> n;

        if (!seen.count(o))
            handles.pb(o);

        seen.insert(o);
        seen.insert(n);
        changes[o] = n;
    }

    cout << size(handles) << "\n";
    for (string h: handles) {
        string s = changes[h];
        while (changes.count(s))
            s = changes[s];

        cout << h << " " << s << "\n";
    }
}