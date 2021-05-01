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

const int MAX = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pii> respect(n, pii(1, 1));
    for (int i = 0; i < n; i++) {
        int p, c;
        cin >> p >> c;

        respect[i].fst = c;
        if (~p)
            respect[p - 1].snd &= c;
    }

    bool done = false;
    for (int i = 0; i < n; i++)
        if (respect[i] == make_pair(1, 1))
            cout << (i + 1) << " ", done = true;

    if (done) cout << "\n";
    else cout << "-1\n";
}