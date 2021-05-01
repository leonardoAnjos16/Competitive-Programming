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

    int R, N, t = 1;
    while (cin >> R >> N, R || N) {
        int ans = (R - N) / N;
        if ((R - N) % N) ans++;
        if (N > R) ans = 0;

        cout << "Case " << t++ << ": ";
        if (ans > 26) cout << "impossible\n";
        else cout << ans << "\n";
    }
}