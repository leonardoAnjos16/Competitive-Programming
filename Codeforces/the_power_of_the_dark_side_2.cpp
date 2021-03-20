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

const int MAX = 5e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    pll jedis[MAX];
    vector<long> aux;

    for (int i = 0; i < n; i++) {
        long a, b, c;
        cin >> a >> b >> c;

        long sum = a + b + c;
        long mx = max({ a, b, c });

        aux.pb(sum - mx);
        jedis[i] = { sum, sum - mx };
    }

    sort(all(aux));
    for (int i = 0; i < n; i++) {
        int ans = ub(all(aux), jedis[i].fst - 2) - aux.begin();
        if (jedis[i].snd <= jedis[i].fst - 2) ans--;
        cout << ans << " ";
    }

    cout << "\n";
}