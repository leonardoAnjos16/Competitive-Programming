#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int T; scanf("%d", &T);
    int case_num = 1;

    while (T--) {
        int N, M, L; scanf("%d %d %d", &N, &M, &L);

        vector< pair<int, string> > ans;
        for (int i = 0; i < L; i++) {
            char str[MAX]; scanf("%s", str);

            int idx = 0;
            char name[MAX];

            while (str[idx] != ':') name[idx] = str[idx], idx++;
            name[idx++] = '\0';

            string prices(str);
            prices = prices.substr(idx);

            int A, B; sscanf(prices.c_str(), "%d,%d", &A, &B);

            int cost = 0, paperwork = N;
            while (paperwork / 2 >= M && B <= A * ceil(paperwork / 2.0))
                cost += B, paperwork /= 2;

            cost += (paperwork - M) * A;
            ans.push_back({cost, string(name)});
        }

        sort(ans.begin(), ans.end());
        printf("Case %d\n", case_num++);

        for (int i = 0; i < L; i++)
            printf("%s %d\n", ans[i].second.c_str(), ans[i].first);
    }
}