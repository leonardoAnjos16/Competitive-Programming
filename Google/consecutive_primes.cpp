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

bool is_prime(long n) {
    for (long i = 2; i * i <= n; i++)
        if (!(n % i)) return false;

    return true;
}

long next_prime(long n) {
    while (!is_prime(n)) n++;
    return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        long Z; cin >> Z;

        long l = 2, r = sqrt(Z), ans;
        while (l <= r) {
            long mid = (l + r) / 2;

            long p = next_prime(mid);
            long q = next_prime(p + 1);

            if (p * q > Z) r = mid - 1;
            else ans = p * q, l = mid + 1;
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }
}