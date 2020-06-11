#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    vector<int> A;
    int h, case_num = 1;
    bool first = true;

    while (scanf("%d", &h), h != -1) {
        if (!first) printf("\n");
        else first = false;

        do A.push_back(h);
        while (scanf("%d", &h), h != -1);

        vector<int> LNIS;
        for (int i = 0; i < (int) A.size(); i++) {
            int idx = upper_bound(LNIS.begin(), LNIS.end(), A[i], cmp) - LNIS.begin();

            if (idx >= (int) LNIS.size()) LNIS.push_back(A[i]);
            else LNIS[idx] = A[i];
        }

        int ans = LNIS.size();
        printf("Test #%d:\n", case_num++);
        printf("  maximum possible interceptions: %d\n", ans);

        A.clear();
    }
}