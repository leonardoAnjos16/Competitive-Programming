#include <bits/stdc++.h>

using namespace std;

int main() {
    int dollars;
    scanf("%d", &dollars);

    int bills[] = { 1, 5, 10, 20, 100 };

    int num_bills = 0;
    for (int i = 4; i >= 0; i--) {
        num_bills += dollars / bills[i];
        dollars %= bills[i];
    }

    printf("%d\n", num_bills);
}