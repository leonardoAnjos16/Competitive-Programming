#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

int N;
vector<int> X;
vector<vector<vector<int>>> memo;

bool possible(int ta, int tb, int tc, int i = 0) {
    if (ta < 0 || tb < 0 || tc < 0) return false;
    if (i >= N) return true;

    int &ans = memo[i][ta][tb];
    if (~ans) return ans;

    if (possible(ta - X[i], tb, tc, i + 1))
        return ans = true;

    if (possible(ta, tb - X[i], tc, i + 1))
        return ans = true;

    if (possible(ta, tb, tc - X[i], i + 1))
        return ans = true;

    return ans = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C;
    cin >> N >> A >> B >> C;

    int sum = 0;
    int fastest = max({ A, B, C });

    X.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        sum += X[i];
    }

    int l = 0, r = (sum + fastest - 1) / fastest, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        memo.assign(N + 5, vector<vector<int>>(mid * A + 5, vector<int>(mid * B + 5, -1)));

        if (!possible(mid * A, mid * B, mid * C)) l = mid + 1;
        else r = mid - 1, ans = mid;
    }

    assert(ans != -1);
    cout << ans << "\n";
}