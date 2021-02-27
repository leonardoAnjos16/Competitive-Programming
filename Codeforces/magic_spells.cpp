#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define heap(ds, cmp) priority_queue<ds, vector<ds>, cmp>

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    set<int> indices[30];

    for (int i = 0; i < size(s); i++)
        indices[s[i] - 'a'].insert(i);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string a; cin >> a;

        string ans = "";
        int last = -1;

        for (char c: a) {
            auto it = indices[c - 'a'].upper_bound(last);
            if (it == indices[c - 'a'].end()) break;
            else ans += c, last = *it;
        }

        if (last == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << "\n";
    }
}