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

const int MAX = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int phi[MAX];
    for (int i = 1; i < MAX; i++)
        phi[i] = i;

    for (int i = 2; i < MAX; i++)
        if (phi[i] == i)
            for (int j = i; j < MAX; j += i)
                phi[j] -= phi[j] / i;

    int N; cin >> N;

    long ans = 0LL;
    for (int i = 1; i <= N; i++)
        ans += phi[i];

    cout << ans << "\n";
}