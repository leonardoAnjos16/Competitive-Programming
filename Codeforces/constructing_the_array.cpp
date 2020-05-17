#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

class Compare {
    public:
        bool operator() (pair<int, int> a, pair<int, int> b) {
            return a.second - a.first == b.second - b.first ? a.first > b.first : a.second - a.first < b.second - b.first;
        }
};

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        priority_queue<pair<int, int>, vector< pair<int, int> >, Compare> aux;
        aux.push({0, n - 1});

        int ans[MAX] = {0}, num = 1;
        while (!aux.empty()) {
            int l = aux.top().first, r = aux.top().second; aux.pop();
            if (l > r) continue;

            int mid = (l + r) / 2; ans[mid] = num++;
            aux.push({l, mid - 1});
            aux.push({mid + 1, r});
        }

        for (int i = 0; i < n; i++) {
            if (i) printf(" ");
            printf("%d", ans[i]);
        }

        printf("\n");
    }
}