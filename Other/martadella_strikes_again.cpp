#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        long double R, r;
        cin >> R >> r;

        long double pi = acos(-1.0);
        long double first_area = pi* R * R;
        long double second_area = 2 * pi * r * r;

        cout << (first_area > second_area ? "1" : "2") << "\n";
    }
}