#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int n; scanf("%d", &n);
    
    int squares[MAX] = {1};
    for (int i = 1; i < n; i++)
        squares[i] = squares[i - 1] + 4 * i;

    printf("%d\n", squares[n - 1]);
}