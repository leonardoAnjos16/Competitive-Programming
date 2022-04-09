#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int l = 1, r = N;
    while (l < r) {
        int mid = (l + r) / 2;

        cout << "? " << l << " " << mid << "\n";
        cout.flush();

        int left; cin >> left;

        cout << "? " << (mid + 1) << " " << r << "\n";
        cout.flush();

        int right; cin >> right;

        if (left == N - 1) r = mid;
        else if (right == N - 1) l = mid + 1;
        else if (left == N) r = mid;
        else l = mid + 1;
    }

    cout << "! " << l << "\n";
}