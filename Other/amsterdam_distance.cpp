#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

const ldouble INF = 1e18 + 5;
const ldouble PI = acos(-1.0L);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(8) << fixed;

    int M, N; ldouble R;
    cin >> M >> N >> R;

    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    ldouble ans = INF, space = R / N;
    for (int i = 0; i <= N; i++)
        ans = min(ans, abs(ay - i) * space + PI * i * space * abs(ax - bx) / M + abs(by - i) * space);

    cout << ans << "\n";
}