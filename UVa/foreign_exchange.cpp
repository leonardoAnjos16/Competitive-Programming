#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n), n) {
        map<pair<int, int>, int> cnt;
        for (int i = 0; i < n; i++) {
            int u, v; scanf("%d %d", &u, &v);
            cnt[{u, v}]++;
        }

        bool possible = true;
        for (auto it = cnt.begin(); it != cnt.end() && possible; it++)
            if (it->second != cnt[{it->first.second, it->first.first}])
                possible = false;

        printf("%s\n", possible ? "YES" : "NO");
    }
}