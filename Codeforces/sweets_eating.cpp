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

    int n, m;
    cin >> n >> m;

    long a[MAX];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    long ps[MAX];
    for (int i = 0; i < m; i++)
        ps[i] = a[i];

    for (int i = m; i < n; i++)
        ps[i] = ps[i - m] + a[i];

    long ans[MAX] = { a[0] };
    for (int i = 1; i < m; i++)
        ans[i] = ans[i - 1] + a[i];

    for (int i = m; i < n; i++)
        ans[i] = ans[i - 1] + ps[i - m] + a[i];

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    cout << "\n";
}