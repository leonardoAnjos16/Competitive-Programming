#include <bits/stdc++.h>

using namespace std;

#define elephant pair<int, int>
#define weight first
#define IQ second

#define triple pair<elephant, int>
#define info first
#define index second

bool cmp(const triple &a, const triple &b) {
    return a.info.weight == b.info.weight ? a.info.IQ > b.info.IQ : a.info.weight < b.info.weight;
}

void print_LIS(const vector<triple> &data, const vector<int> &p, int i) {
    if (p[i] != -1) print_LIS(data, p, p[i]);
    printf("%d\n", data[i].index);
}

int main() {
    vector<triple> data; int w, s, n = 0;
    while (scanf("%d %d", &w, &s) != EOF) data.push_back({{w, s}, ++n});
    sort(data.begin(), data.end(), cmp);

    vector<int> dp(n), p(n);
    int ans = 0, last = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = 1; p[i] = -1;
        for (int j = 0; j < i; j++)
            if (data[j].info.weight < data[i].info.weight && data[j].info.IQ > data[i].info.IQ && 1 + dp[j] > dp[i])
                dp[i] = 1 + dp[j], p[i] = j;

        if (dp[i] > ans) ans = dp[i], last = i;
    }

    printf("%d\n", ans);
    print_LIS(data, p, last);
}