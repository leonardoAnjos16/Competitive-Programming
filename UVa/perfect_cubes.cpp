#include <bits/stdc++.h>

using namespace std;

int main() {
    for (int a = 2; a <= 200; a++) {
        int cube = a * a * a;
        for (int b = 2; b * b * b <= cube; b++) {
            for (int c = b; (b * b * b) + (c * c * c) <= cube; c++) {
                int d = round(cbrt(cube - (b * b * b) - (c * c * c)));
                if (d >= c && cube == (b * b * b) + (c * c * c) + (d * d * d))
                    printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
            }
        }
    }
}