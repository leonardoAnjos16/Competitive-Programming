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

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * (b / gcd(a, b));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N, N) {
        vector<int> divs;
        for (long i = 1; i * i <= N; i++) {
            if (!(N % i)) {
                divs.pb(i);
                if (i * i < N)
                    divs.pb(N / i);
            }
        }

        sort(all(divs));

        int ans = 0;
        for (int i = 0; i < size(divs); i++)
            for (int j = i; j < size(divs); j++)
                if (lcm(divs[i], divs[j]) == N) ans++;

        cout << N << " " << ans << "\n";
    }
}