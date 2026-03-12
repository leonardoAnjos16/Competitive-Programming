#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int second = 2;
    for (int i = 3; i <= n; i++) {
        cout << "2 1 " << second << " " << i << "\n";
        cout.flush();

        int sign; cin >> sign;
        if (sign < 0) second = i;
    }

    int mid = -1;
    vector<llong> area(n + 1);

    for (int i = 2; i <= n; i++)
        if (i != second) {
            cout << "1 1 " << second << " " << i << "\n";
            cout.flush();

            cin >> area[i];
            if (mid == -1 || area[i] > area[mid])
                mid = i;
        }

    vector<pair<llong, int>> left, right;
    for (int i = 2; i <= n; i++)
        if (i != second && i != mid) {
            cout << "2 1 " << mid << " " << i << "\n";
            cout.flush();

            int sign; cin >> sign;
            if (sign > 0) left.emplace_back(area[i], i);
            else right.emplace_back(area[i], i);
        }

    sort(left.rbegin(), left.rend());
    sort(right.begin(), right.end());

    cout << "0 1 " << second;
    for (auto [a, idx]: right)
        cout << " " << idx;

    cout << " " << mid;
    for (auto [a, idx]: left)
        cout << " " << idx;

    cout << "\n";
    cout.flush();
}