#include <bits/stdc++.h>

using namespace std;

void print_LIS(const vector<int> &A, const vector<int> &p, int i) {
    if (p[i] == -1) printf("%d\n", A[i]);
    else {
        print_LIS(A, p, p[i]);
        printf("%d\n", A[i]);
    }
}

int main() {
    vector<int> A; int a;
    while (scanf("%d", &a) != EOF) A.push_back(a);
    int n = A.size();

    vector<int> L, L_idx, p(n);
    int size = 0, last = 0;

    for (int i = 0; i < n; i++) {
        int idx = lower_bound(L.begin(), L.end(), A[i]) - L.begin();
        if (idx >= size - 1) last = i;

        if (idx >= size) {
            L.push_back(A[i]);
            L_idx.push_back(i);
            size++;
        } else {
            L[idx] = A[i];
            L_idx[idx] = i;
        }

        p[i] = idx ? L_idx[idx - 1] : -1;
    }

    printf("%d\n-\n", size);
    print_LIS(A, p, last);
}