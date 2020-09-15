#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; scanf("%d %d", &n, &k);

    int problems = 0, minutes = 0;
    while (problems <= n && minutes <= (240 - k)) minutes += 5 * ++problems;

    printf("%d\n", --problems);
}