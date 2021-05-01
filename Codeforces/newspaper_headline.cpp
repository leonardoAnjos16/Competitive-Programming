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

    string s1, s2;
    cin >> s1 >> s2;

    vi pos[30];
    for (int i = 0; i < size(s1); i++)
        pos[s1[i] - 'a'].pb(i);

    int last = -1, ans = 1;
    for (char c: s2) {
        if (!size(pos[c - 'a'])) {
            cout << "-1\n";
            return 0;
        }

        auto it = ub(all(pos[c - 'a']), last);
        if (it != pos[c - 'a'].end()) last = *it;
        else ans++, last = pos[c - 'a'][0];
    }

    cout << ans << "\n";
}