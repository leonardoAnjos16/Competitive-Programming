#include <bits/stdc++.h>

using namespace std;

const int MAX = 15;

int fact(int n) {
    if (!n) return 1;
    else return n * fact(n - 1);
}

int main() {
    char str[MAX]; scanf("%s", str);

    int n = strlen(str), f_pos = 0;
    for (int i = 0; i < n; i++)
        f_pos += str[i] == '+' ? 1 : -1;

    scanf("%s", str);

    int pos = 0, unrec = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '+') pos++;
        else if (str[i] == '-') pos--;
        else unrec++;
    }

    int dist = f_pos - pos;

    if (unrec < abs(dist) || ((dist + unrec) & 1)) printf("%.10lf\n", 0.0);
    else {
        int plus = (dist + unrec) >> 1;
        int minus = unrec - plus;

        double num_perm = fact(unrec) / (fact(plus) * fact(minus));
        double prob = num_perm / (1 << unrec);

        printf("%.10lf\n", prob);
    }
}