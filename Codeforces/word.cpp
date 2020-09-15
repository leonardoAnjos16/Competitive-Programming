#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    char s[MAX]; scanf("%s", s);
    int n = strlen(s);

    int lower = 0, upper = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') lower++;
        else upper++;
    }

    if (lower >= upper)
        for (int i = 0; i < n; i++)
            s[i] = tolower(s[i]);
    else
        for (int i = 0; i < n; i++)
            s[i] = toupper(s[i]);

    printf("%s\n", s);
}