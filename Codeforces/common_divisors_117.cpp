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

    string s1, s2;
    cin >> s1 >> s2;

    if (size(s1) > size(s2))
        swap(s1, s2);

    vector<string> potential;
    int n = size(s1), m = size(s2);

    for (int i = 1; i * i <= n; i++) {
        if (!(n % i)) {
            if (!(m % i)) potential.pb(s1.substr(0, i));
            if (i * i < n && !(m % (n / i)))
                potential.pb(s1.substr(0, n / i));
        }
    }

    int ans = 0;
    for (string s: potential) {
        bool divisor = true;
        for (int i = 0; i < n / size(s) && divisor; i++)
            divisor &= s1.substr(i * size(s), size(s)) == s;

        for (int i = 0; i < m / size(s) && divisor; i++)
            divisor &= s2.substr(i * size(s), size(s)) == s;

        if (divisor) ans++;
    }

    cout << ans << "\n";
}