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

const int MAX = 105;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int A[MAX];
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int B[MAX];
    for (int i = 0; i < N; i++)
        cin >> B[i];

    int l = A[0], r = B[0];
    for (int i = 1; i < N; i++) {
        l = max(l, A[i]);
        r = min(r, B[i]);
    }

    int ans = r >= l ? r - l + 1 : 0;
    cout << ans << "\n";
}