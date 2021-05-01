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

    int n;
    while (cin >> n, ~n) {
        long cnt = 2, sum, ans = 1;
        while ((sum = (cnt - 1) * cnt / 2) < n)
            if (!((n - sum) % cnt++)) ans = cnt - 1;

        long A = (n - (ans - 1) * ans / 2) / ans;
        long B = A + ans - 1;

        cout << n << " = " << A << " + ... + " << B << "\n";
    }
}