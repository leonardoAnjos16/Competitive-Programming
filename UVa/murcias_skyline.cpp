#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    int case_num = 1;

    while (t--) {
        int N; scanf("%d", &N);

        vector<int> h(N), w(N);
        for (int i = 0; i < N; i++)
            scanf("%d", &h[i]);

        for (int i = 0; i < N; i++)
            scanf("%d", &w[i]);

        vector<int> LIS(N), LDS(N);
        for (int i = 0; i < N; i++) {
            LIS[i] = LDS[i] = w[i];
            for (int j = 0; j < i; j++) {
                if (h[j] < h[i]) LIS[i] = max(LIS[i], LIS[j] + w[i]);
                if (h[j] > h[i]) LDS[i] = max(LDS[i], LDS[j] + w[i]);
            }
        }

        int LIS_len = *max_element(LIS.begin(), LIS.end());
        int LDS_len = *max_element(LDS.begin(), LDS.end());

        if (LIS_len >= LDS_len) printf("Case %d. Increasing (%d). Decreasing (%d).\n", case_num++, LIS_len, LDS_len);
        else printf("Case %d. Decreasing (%d). Increasing (%d).\n", case_num++, LDS_len, LIS_len);
    }
}