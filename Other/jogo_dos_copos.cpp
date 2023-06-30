#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool ball[3] = { false, true, false };

    int N; cin >> N;
    while (N--) {
        int A, B;
        cin >> A >> B;
        swap(ball[A - 1], ball[B - 1]);
    }

    int ans = ball[0] ? 1 : (ball[1] ? 2 : 3);
    cout << ans << "\n";
}