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

    long L; int G;
    cin >> L >> G;

    long ans = 0LL;
    for (int i = 0; i < G; i++) {
        long p; int d;
        cin >> p >> d;
        ans = max(ans, d ? L - p : p);
    }

    cout << ans << "\n";
}