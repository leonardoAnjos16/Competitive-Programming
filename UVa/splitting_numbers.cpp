#include <bits/stdc++.h>

using namespace std;

#define NUM_BITS 31

int main() {
    int number;
    while (scanf("%d", &number), number) {
        int a, b, counter;
        a = b = counter = 0;

        for (int i = 0; i < NUM_BITS; i++) {
            if (number & (1 << i)) {
                if (counter++ % 2) b |= (1 << i);
                else a |= (1 << i);
            }
        }

        printf("%d %d\n", a, b);
    }
}