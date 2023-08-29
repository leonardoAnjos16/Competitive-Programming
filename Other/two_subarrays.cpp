#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const llong INF = 1e18 + 5;
const llong NOANS = -INF;

const int NONE = 0;
const int FIRST_ODD = 1;
const int FIRST_EVEN = 2;
const int MIDDLE = 3;
const int SECOND_ODD = 4;
const int SECOND_EVEN = 5;
const int DONE = 6;

int N;
vector<int> A;
vector<vector<llong>> memo;
int sign_first, sign_second;

llong min_diff(int status, int i) {
    // cout << status << " " << i << "\n";
    if (status == DONE) return 0;
    if (i >= N) return status == SECOND_ODD || status == SECOND_EVEN ? 0 : INF;

    llong &ans = memo[status][i];
    if (ans != NOANS) return ans;

    ans = INF;
    if (status == NONE) ans = min(min_diff(NONE, i + 1), sign_first * A[i] + min_diff(FIRST_EVEN, i + 1));
    else if (status == MIDDLE) ans = min(min_diff(MIDDLE, i + 1), sign_second * A[i] + min_diff(SECOND_EVEN, i + 1));
    else if (status == FIRST_ODD) ans = min(min_diff(MIDDLE, i), sign_first * A[i] + min_diff(FIRST_EVEN, i + 1));
    else if (status == FIRST_EVEN) ans = min(min_diff(MIDDLE, i), -sign_first * A[i] + min_diff(FIRST_ODD, i + 1));
    else if (status == SECOND_ODD) ans = min(min_diff(DONE, i), sign_second * A[i] + min_diff(SECOND_EVEN, i + 1));
    else ans = min(min_diff(DONE, i), -sign_second * A[i] + min_diff(SECOND_ODD, i + 1));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        cin >> N;

        A.resize(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        sign_first = 1; sign_second = -1;
        memo.assign(DONE + 5, vector<llong>(N + 5, NOANS));

        llong ans = min(min_diff(NONE, 0), A[0] + min_diff(FIRST_EVEN, 1));

        sign_first = -1; sign_second = 1;
        memo.assign(DONE + 5, vector<llong>(N + 5, NOANS));

        ans = min({ ans, min_diff(NONE, 0), -A[0] + min_diff(FIRST_EVEN, 1) });

        ans = abs(ans);
        cout << ans << "\n";
    }
}