#include <bits/stdc++.h>

using namespace std;

const int MAX = 15;

int main() {
    int C; scanf("%d", &C);
    while (C--) {
        int N; scanf("%d", &N);

        bool is_bop = true;
        while (N--) {
            char sound[MAX]; scanf("%s", sound);
            if (strcmp(sound, "BEEP") && strcmp(sound, "BOOP")) is_bop = false;
        }

        if (is_bop) printf("IT'S A BOP!\n");
        else printf("IT'S NOT A BOP!\n");
    }
}