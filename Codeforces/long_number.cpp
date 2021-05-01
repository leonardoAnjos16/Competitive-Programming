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

    int n; cin >> n;
    string a; cin >> a;

    int f[10] = {0};
    for (int i = 1; i < 10; i++)
        cin >> f[i];

    int idx = 0;
    while (idx < n && f[a[idx] - '0'] <= a[idx] - '0') idx++;
    while (idx < n && f[a[idx] - '0'] >= a[idx] - '0') a[idx] = f[a[idx] - '0'] + '0', idx++;

    cout << a << "\n";
}