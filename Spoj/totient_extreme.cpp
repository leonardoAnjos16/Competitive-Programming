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

const int MAX = 1e4 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long ps[MAX] = {0};
    for (int i = 1; i < MAX; i++)
        ps[i] = i;

    for (int i = 2; i < MAX; i++)
        if (ps[i] == i)
            for (int j = i; j < MAX; j += i)
                ps[j] -= ps[j] / i;

    for (int i = 2; i < MAX; i++)
        ps[i] += ps[i - 1];

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        long H = ps[N] * ps[N];
        cout << H << "\n";
    }
}