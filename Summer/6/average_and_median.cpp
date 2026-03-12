#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const long double EPS = 1e-9;
const long double NOA = 1e18;
const int NOM = 1e5 + 5;

int N;
vector<int> A;
vector<vector<long double>> amemo;
vector<vector<int>> mmemo;

int sign(long double x) {
    return abs(x) < EPS ? 0 : (x > EPS ? 1 : -1);
}

long double asum(long double average, bool last = true, int i = 0) {
    if (i >= N) return 0.0L;

    long double &ans = amemo[last][i];
    if (sign(ans - NOA) != 0) return ans;

    ans = asum(average, true, i + 1) + A[i] - average;
    if (last) ans = max(ans, asum(average, false, i + 1));

    return ans;
}

int msum(int median, bool last = true, int i = 0) {
    if (i >= N) return 0;

    int &ans = mmemo[last][i];
    if (ans != NOM) return ans;

    ans = msum(median, true, i + 1) + (A[i] >= median ? 1 : -1);
    if (last) ans = max(ans, msum(median, false, i + 1));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(6) << fixed;

    cin >> N;

    A.resize(N);
    int mx = INT_MIN;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        mx = max(mx, A[i]);
    }

    long double l = 0.0L, r = mx, average;
    for (int i = 0; i < 50; i++) {
        long double mid = (l + r) / 2.0L;

        amemo.assign(2, vector<long double>(N + 5, NOA));

        if (sign(asum(mid)) < 0) r = mid;
        else average = l = mid;
    }

    cout << average << "\n";

    int lo = 0, hi = mx, median;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        mmemo.assign(2, vector<int>(N + 5, NOM));

        if (msum(mid) <= 0) hi = mid - 1;
        else lo = mid + 1, median = mid;
    }

    cout << median << "\n";
}