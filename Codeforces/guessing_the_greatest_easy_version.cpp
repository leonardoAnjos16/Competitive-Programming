#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int l = 1, r = n;
    while (l + 1 < r) {
        cout << "? " << l << " " << r << "\n";
        cout.flush();

        int i; cin >> i;

        int mid = (l + r) / 2, nl = mid, nr = r;
        if (i <= mid) nl = l, nr = mid;

        cout << "? " << nl << " " << nr << "\n";
        cout.flush();

        int j; cin >> j;

        if (i == j) l = nl, r = nr;
        else if (nl == mid) r = mid;
        else l = mid;
    }

    assert(r == l + 1);

    cout << "? " << l << " " << r << "\n";
    cout.flush();

    int i; cin >> i;
    cout << "! " << (i == l ? r : l) << "\n";
    cout.flush();
}