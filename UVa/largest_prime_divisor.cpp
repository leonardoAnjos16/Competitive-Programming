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

    long N;
    while (cin >> N, N) {
        N = abs(N);
        long ans = -1, cnt = 0;

        for (long i = 2; i * i <= N; i++) {
            if (!(N % i)) cnt++, ans = i;
            while (!(N % i)) N /= i;
        }

        if (N > 1) ans = N, cnt++;
        if (cnt < 2) ans = -1;

        cout << ans << "\n";
    }
}