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

long m1, m2;

long gcd(long a, long b) {
    if (!b) {
        m1 = 1LL;
        m2 = 0LL;
        return a;
    }

    long ans = gcd(b, a % b);

    long aux = m1;
    m1 = m2;
    m2 = aux - m2 * (a / b);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long n;
    while (cin >> n, n) {
        long c1, n1, c2, n2;
        cin >> c1 >> n1 >> c2 >> n2;

        long aux = gcd(n1, n2);
        if (n % aux) cout << "failed\n";
        else {
            m1 *= n / aux;
            m2 *= n / aux;

            long k1 = ceil(-m1 * aux / (n2 + .0));
            long k2 = floor(m2 * aux / (n1 + .0));

            if (k1 > k2) cout << "failed\n";
            else {
                long k = c1 * n2 > c2 * n1 ? k1 : k2;
                m1 += k * (n2 / aux);
                m2 -= k * (n1 / aux);

                cout << m1 << " " << m2 << "\n";
            }
        }
    }
}