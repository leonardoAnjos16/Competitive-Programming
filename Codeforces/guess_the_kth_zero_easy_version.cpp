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

    int n, t;
    cin >> n >> t;

    int k; cin >> k;

    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        cout << "? " << (l + 1) << " " << (mid + 1) << "\n";
        cout.flush();

        int sum; cin >> sum;
        int zeroes = mid - l + 1 - sum;

        if (zeroes >= k) r = mid;
        else k -= zeroes, l = mid + 1;
    }

    cout << "! " << (l + 1) << "\n";
}