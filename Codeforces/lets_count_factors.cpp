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

    int N; cin >> N;
    while (N--) {
        int A, B;
        cin >> A >> B;

        map<int, int> factors;
        for (long i = 2LL; i * i <= A; i++)
            while (!(A % i)) factors[i]++, A /= i;

        if (A > 1) factors[A]++;

        for (long i = 2LL; i * i <= B; i++)
            while (!(B % i)) factors[i]++, B /= i;

        if (B > 1) factors[B]++;

        int ans = size(factors);
        cout << ans << "\n";
    }
}