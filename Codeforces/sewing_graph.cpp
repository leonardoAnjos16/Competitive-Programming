#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 1e3 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    pair<pii, int> holes[MAX];
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        holes[i] = { { x, y }, i + 1 };
    }

    sort(holes, holes + N);

    cout << (N - 1) * 2 + 1 << "\n";
    for (int i = 1; i + 1 < N; i += 2)
        cout << holes[i].snd << " " << holes[i + 1].snd << " ";

    for (int i = N - 1 - N % 2; i - 1 >= 0; i -= 2)
        cout << holes[i].snd << " " << holes[i - 1].snd << " ";

    cout << holes[1].snd << "\n";
}