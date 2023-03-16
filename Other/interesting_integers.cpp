#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size = 2;
    vector<llong> fibs(2, 1LL);

    while (fibs[size - 1] + fibs[size - 2] <= MAX) {
        fibs.push_back(fibs[size - 1] + fibs[size - 2]);
        size++;
    }

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;

        int a = 1, b = n - 1;
        for (int i = 1; i < size; i++) {
            llong x = i <= 2 ? 0 : (i & 1 ? fibs[i - 3] : -fibs[i - 3]);
            llong y = i <= 2 ? 1 : (i & 1 ? -fibs[i - 2] : fibs[i - 2]);

            x *= n;
            y *= n;

            int l = 0, r = MAX, k = MAX + 1;
            while (l <= r) {
                int mid = (l + r) / 2;

                llong dx = fibs[i - 1] * mid;
                llong dy = fibs[i] * mid;

                llong nx = x < y ? x + dx : x - dx;
                llong ny = x < y ? y - dy : y + dy;

                if (x < y) {
                    if (nx < ny) l = mid + 1;
                    else r = mid - 1, k = mid;
                } else {
                    if (nx < ny) r = mid - 1;
                    else l = mid + 1, k = mid;
                }
            }

            assert(k <= MAX);

            llong dx = fibs[i - 1] * k;
            llong dy = fibs[i] * k;

            if (x < y) {
                x += dx;
                y -= dy;
            } else {
                x -= dx;
                y += dy;
            }

            if (y > 0) {
                if (x < b) a = y, b = x;
                else if (x == b) a = y;
            }
        }

        cout << a << " " << b << "\n";
    }
}