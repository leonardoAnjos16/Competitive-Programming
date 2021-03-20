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

    set<long> numbers;
    for (long i = 1; i <= 1e4; i++)
        numbers.insert(i * i * i);

    int t; cin >> t;
    while (t--) {
        long x; cin >> x;

        bool possible = false;
        for (long i = 1; i * i * i < x && !possible; i++)
            if (numbers.count(x - i * i * i)) possible = true;

        cout << (possible ? "YES" : "NO") << "\n";
    }
}