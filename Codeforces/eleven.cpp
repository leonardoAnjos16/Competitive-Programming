#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);

    string ans = "";
    int a = 1, b = 1;

    for (int i = 1; i <= n; i++) {
        if (i != b) ans += 'o';
        else {
            ans += 'O';

            int aux = b;
            b = a + b;
            a = aux;
        }
    }

    printf("%s\n", ans.c_str());
}