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

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        int A[MAX], g = 0;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            g = gcd(g, A[i]);
        }

        int ans = 0;
        for (int i = 0; i < N; i++)
            ans += A[i] / g;

        cout << ans << "\n";
    }
}