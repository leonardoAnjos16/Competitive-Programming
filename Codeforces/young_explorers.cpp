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

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        int e[MAX];
        for (int i = 0; i < N; i++)
            cin >> e[i];

        sort(e, e + N);

        int l = 0, r = 0, ans = 0;
        while (l < N) {
            while (r < N && e[r] > r - l + 1) r++;
            if (r < N) ans++;
            l = ++r;
        }

        cout << ans << "\n";
    }
}