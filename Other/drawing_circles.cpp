#include <bits/stdc++.h>

using namespace std;

long double radius(long double r1, long double r2) {
    long double s1 = sqrt(r1);
    long double s2 = sqrt(r2);

    long double s = s1 + s2;
    return r1 * r2 / (s * s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    long double r1, r2; int N;
    cin >> r1 >> r2 >> N;

    priority_queue<tuple<long double, long double, long double>> heap;
    heap.emplace(radius(r1, r2), r1, r2);

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";

        long double ans;
        tie(ans, r1, r2) = heap.top();
        heap.pop();

        cout << ans;

        heap.emplace(radius(r1, ans), r1, ans);
        heap.emplace(radius(ans, r2), ans, r2);
    }

    cout << "\n";
}