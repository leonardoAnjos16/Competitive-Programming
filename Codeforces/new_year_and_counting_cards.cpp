#include <bits/stdc++.h>

using namespace std;

const int MAX = 55;

bool vowel(char c) {
    switch(c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

bool odd_digit(char c) {
    int digit = c - '0';
    return c >= '0' && c <= '9' && (digit % 2) == 1;
}

int main() {
    char s[MAX]; scanf("%s", s);
    int n = strlen(s);

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (vowel(s[i]) || odd_digit(s[i])) ans++;

    printf("%d\n", ans);
}