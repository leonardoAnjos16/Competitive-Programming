#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, t, d, s;
    cin >> a >> b >> t >> d >> s;

    if (b < a) cout << "0\n";
    else {
        int l = 0, r = INF, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;

            int marbles = mid;
            long double pos = a * d;

            while (pos < t) {
                // sa = pos + a * time
                // sb = b * time
                // pos + a * time = b * time
                // (b - a) * time = pos
                // time = pos / (b - a)
                // s = pos + a * pos / (b - a)

                long double time = pos / (b - a);
                if (pos + a * time >= t) pos += a * time;
                else if (!marbles) break;
                else {
                    marbles--;
                    pos += a * time;
                    pos += a * (pos / b + s);
                }
            }

            if (pos < t) l = mid + 1;
            else r = mid - 1, ans = mid;
        }

        cout << ans << "\n";
    }
}