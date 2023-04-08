#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int query(int x, int y) {
    cout << "? " << x << " " << y << "\n";
    cout.flush();

    int steps;
    cin >> steps;
    return steps;
}

void answer(int x, int y) {
    cout << "! " << x << " " << y << "\n";
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int a = query(1, 1);
        if (a + 1 > n) {
            int b = query(1, a + 1);
            answer(b + 1, a + 1);
        } else if (a + 1 > m) {
            int b = query(a + 1, 1);
            answer(a + 1, b + 1);
        } else {
            int b = query(1, a + 1);
            int c = query(a + 1, 1);

            if (b < a) answer(b + 1, a + 1);
            else if (c < a) answer(a + 1, c + 1);
            else answer(a + 1, a + 1);
        }
    }
}