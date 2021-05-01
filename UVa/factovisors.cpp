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

    long n, m;
    while (cin >> n >> m) {
        long aux = m;
        map<long, int> factors;

        for (long i = 2; i * i <= aux; i++)
            while (!(aux % i)) factors[i]++, aux /= i;

        if (aux > 1) factors[aux]++;

        bool divides = true;
        for (auto p: factors) {
            int cnt = 0;
            long pow = p.fst;

            while (pow <= n) {
                cnt += n / pow;
                pow *= p.fst;
            }

            divides &= p.snd <= cnt;
        }

        string ans = divides ? "divides" : "does not divide";
        cout << m << " " << ans << " " << n << "!\n";
    }
}