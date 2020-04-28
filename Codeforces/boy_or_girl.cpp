#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    char s[MAX]; scanf("%s", s);
    int n = strlen(s);

    set<char> distinct;
    for (int i = 0; i < n; i++)
        distinct.insert(s[i]);

    int size = distinct.size();
    printf("%s\n", size % 2 ? "IGNORE HIM!" : "CHAT WITH HER!");
}