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

    int L = 1, R = N;
    while (L < R) {
        int mid = (L + R) / 2;

        cout << L << " " << mid << "\n";
        cout.flush();

        int cnt; cin >> cnt;
        if (cnt) R = mid;
        else L = mid + 1;
    }

    cout << "! " << L << "\n";
}