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

const int MAX = 20;
const double INF = 1e18;

int N;
pii students[MAX];
double memo[1 << MAX];

double dist(pii a, pii b) {
    int x = a.fst - b.fst;
    int y = a.snd - b.snd;
    return sqrt(x * x + y * y);
}

double distances(int used = 0) {
    if (used + 1 == (1 << N)) return 0.0;

    double &ans = memo[used];
    if (ans >= 0.0) return ans;

    ans = INF;
    for (int i = 0; i < N; i++) if (!(used & (1 << i)))
        for (int j = 0; j < N; j++) if (i != j && !(used & (1 << j)))
            ans = min(ans, dist(students[i], students[j]) + distances(used | (1 << i) | (1 << j)));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(2) << fixed;

    int t = 1;
    while (cin >> N, N) {
        N *= 2;
        for (int i = 0; i < N; i++) {
            string s; int x, y;
            cin >> s >> x >> y;
            students[i] = { x, y };
        }

        for (int i = 0; i < (1 << N); i++)
            memo[i] = -1;

        double ans = distances();
        cout << "Case " << t++ << ": " << ans << "\n";
    }
}