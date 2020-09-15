#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int size;
    scanf("%d", &size);

    char a[MAX], b[MAX];
    scanf("%s", a);
    scanf("%s", b);

    int pos = 0;
    while (++pos < size && a[pos] <= b[pos]);

    if (pos < size) printf("YES\n1 %d\n", pos + 1);
    else if (a[0] > b[0] && size > 2) printf("YES\n2 3\n");
    else if (a[0] > b[0] && a[1] == b[1]) printf("YES\n1 2\n");
    else printf("NO\n");
}