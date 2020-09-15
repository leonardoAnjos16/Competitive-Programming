#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int n, k; scanf("%d %d", &n, &k);

    int a[MAX], cnt[MAX] = {0};
    vector<int> indices;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (!cnt[a[i]]) indices.push_back(i + 1);
        cnt[a[i]]++;
    }

    int size = indices.size();
    if (size < k) printf("NO\n");
    else {
        printf("YES\n");
        for (int i = 0; i < k; i++)
            printf("%d ", indices[i]);

        printf("\n");
    }
}