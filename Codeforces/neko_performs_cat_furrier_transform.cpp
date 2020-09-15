#include <bits/stdc++.h>

using namespace std;

int first_zero(int n) {
    int aux = n, cnt = 0;
    while (aux) cnt++, aux >>= 1;

    while (--cnt >= 0)
        if (!(n & (1 << cnt)))
            return cnt;

    return -1;
}

int main() {
    int x; scanf("%d", &x);

    int moves = 0, aux;
    vector<int> n;

    while ((aux = first_zero(x)) != -1) {
        if (++moves & 1) {
            n.push_back(++aux);
            x ^= (1 << aux) - 1;
        } else x++;
    }

    printf("%d\n", moves);
    for (int i = 0; i < (int) n.size(); i++) {
        if (i) printf(" ");
        printf("%d", n[i]);
    }
}