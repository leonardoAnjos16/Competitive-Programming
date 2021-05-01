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

    int T; cin >> T;
    while (T--) {
        string N, M;
        cin >> N >> M;

        sort(all(N));

        bool done = false;
        for (int i = 0; i < size(N) && !done; i++)
            if (N[i] - '0') swap(N[0], N[i]), done = true;

        cout << (M == N ? "AC" : "WA") << "\n";
    }
}