#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3 + 5;

int main() {
    int n, m; scanf("%d %d", &n, &m);

    string p[MAX];
    for (int i = 0; i < n; i++)
        cin >> p[i];

    string e[MAX];
    for (int i = 0; i < m; i++)
        cin >> e[i];

    sort(e, e + m);

    int common = 0;
    for (int i = 0; i < n; i++)
        common += binary_search(e, e + m, p[i]);

    n -= common;
    m -= common;

    printf("%s\n", (((common % 2) && n >= m) || (!(common % 2) && n > m)) ? "YES" : "NO");
}