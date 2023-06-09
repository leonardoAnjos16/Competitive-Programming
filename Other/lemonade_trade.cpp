#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int N; cin >> N;

    map<string, ldouble> mx;
    mx["pink"] = logl(1.0L);

    for (int i = 0; i < N; i++) {
        string O, W; ldouble R;
        cin >> O >> W >> R;

        if (!mx.count(W)) continue;

        if (!mx.count(O)) mx[O] = mx[W] + logl(R);
        else mx[O] = max(mx[O], mx[W] + logl(R));
    }

    if (!mx.count("blue")) cout << 0.0L << "\n";
    else {
        if (mx["blue"] > 10.0L) cout << 10.0L << "\n";
        else {
            ldouble ans = min(exp(mx["blue"]), 10.0L);
            cout << ans << "\n";
        }
    }
}