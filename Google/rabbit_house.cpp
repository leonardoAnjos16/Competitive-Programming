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

const int MAX = 305;

int R, C;
int G[MAX][MAX];
int A[MAX][MAX];

bool get_boxes(int i = 0, int j = 0) {
    if (i >= R) return true;
    if (j >= C) return get_boxes(i + 1);
    
    int mx = 0;
    if (i > 0) mx = max(mx, A[i - 1][j]);
    if (j > 0) mx = max(mx, A[i][j - 1]);

    A[i][j] = max(A[i][j], mx - 1);
    if (i > 0 && abs(A[i][j] - A[i - 1][j]) > 1) {
        A[i - 1][j] = A[i][j] - 1;
        return get_boxes(i - 1, j);
    }

    if (j > 0 && abs(A[i][j] - A[i][j - 1]) > 1) {
        A[i][j - 1] = A[i][j] - 1;
        return get_boxes(i, j - 1);
    }

    return get_boxes(i, j + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> R >> C;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                cin >> G[i][j];
                A[i][j] = G[i][j];
            }

        get_boxes();

        long ans = 0LL;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                assert(A[i][j] >= G[i][j]);
                ans += A[i][j] - G[i][j];
            }

        cout << "Case #" << t << ": " << ans << "\n";
    }
}