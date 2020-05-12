#include <bits/stdc++.h>

using namespace std;

int main() {
    int M; scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        if (i) printf("\n");
        int N; scanf("%d", &N);

        vector<int> ans;
        int num = 2, sum = 0;

        while (sum + num <= N)
            ans.push_back(num), sum += num++;

        int size = ans.size();
        int rem = N - sum;

        while (rem) {
            int idx = size - 1;
            while (idx >= 0 && rem)
                ans[idx--]++, rem--;
        }

        for (int j = 0; j < size; j++) {
            if (j) printf(" ");
            printf("%d", ans[j]);
        }

        printf("\n");
    }
}