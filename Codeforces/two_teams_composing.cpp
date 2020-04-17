#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int cnt[MAX] = {0};
        set<int> aux;

        int max_cnt = INT_MIN;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            max_cnt = max(max_cnt, ++cnt[a]);
            aux.insert(a);
        }

        int unique = aux.size();

        if (max_cnt == unique) printf("%d\n", max_cnt - 1);
        else printf("%d\n", min(max_cnt, unique));
    }
}