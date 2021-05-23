#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define rall(ds) (ds).rbegin(), (ds).rend()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int D, d, A, B, C;
        cin >> D >> d >> A >> B >> C;

        int aux = d * D;
        if (aux >= 42) cout << C << "\n";
        else if (aux >= 21) cout << B << "\n";
        else if (aux >= 10) cout << A << "\n";
        else cout << "0\n";
    }
}