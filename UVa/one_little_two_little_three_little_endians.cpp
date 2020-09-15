#include <bits/stdc++.h>

using namespace std;

int main() {
    int number;
    while (scanf("%d", &number) != EOF) {
        int other_endian = 0, bit_pos = 24, counter = 0;
        while (bit_pos >= 0) {
            if (number & (1 << bit_pos))
                other_endian |= (1 << counter);

            if (++bit_pos % 8 == 0) bit_pos -= 16;
            counter++;
        }

        printf("%d converts to %d\n", number, other_endian);
    }
}