#include <bits/stdc++.h>

using namespace std;

bool cover_all(vector<pair<int, int>> &ranges, int l, int r) {
    sort(ranges.begin(), ranges.end());
    if (ranges[0].first > l) return false;

    int cr = ranges[0].second;
    for (int i = 1; i < (int) ranges.size(); i++) {
        if (ranges[i].first > cr + 1) return false;
        cr = ranges[i].second;
    }

    return cr == r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int l = 0, r = p - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;

            vector<pair<int, int>> ranges;
            for (int i = 0; i < n; i++)
                ranges.emplace_back(a[i], a[i]);

            if (a.back() + mid < p) ranges.emplace_back(a.back(), a.back() + mid);
            else {
                ranges.emplace_back(a.back(), p - 1);
                ranges.emplace_back(0, a.back() + mid - p);

                int idx = n - 2;
                while (idx >= 0 && a[idx] == p - 1) idx--;

                if (idx < 0) ranges.emplace_back(1, 1);
                else ranges.emplace_back(a[idx], a[idx] + 1);
            }

            if (!cover_all(ranges, 0, p - 1)) l = mid + 1;
            else r = mid - 1, ans = mid;
        }

        assert(ans != -1);
        cout << ans << "\n";
    }
}