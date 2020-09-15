#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int main() {
    int n; scanf("%d", &n);
    char s[MAX]; scanf("%s", s);

    int anton = 0, danik = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') anton++;
        else danik++;
    }

    printf("%s\n", anton == danik ? "Friendship" : (anton > danik ? "Anton" : "Danik"));
}