#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int n, m; scanf("%d %d", &n, &m);

    map<int, int> cnt;
    int r = INT_MIN;

    for (int i = 0; i < m; i++) {
        int a; scanf("%d", &a);

        if (cnt.find(a) != cnt.end()) cnt[a]++;
        else cnt[a] = 1;

        r = max(r, cnt[a]);
    }

    int l = 0, d;
    while (l <= r) {
        int mid = (l + r) / 2;

        int days = 0;
        for (map<int, int>::iterator it = cnt.begin(); it != cnt.end() && mid; it++)
            days += it->second / mid;

        if (days < n && mid) r = mid - 1;
        else d = mid, l = mid + 1;
    }

    printf("%d\n", d);
}