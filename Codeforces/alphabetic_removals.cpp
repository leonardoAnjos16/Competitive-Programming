#include <bits/stdc++.h>

using namespace std;

const int MAX = 4e5 + 5;

int main() {
    int n, k; scanf("%d %d", &n, &k);
    char s[MAX]; scanf("%s", s);

    bitset<MAX> rem;
    for (char c = 'a'; c <= 'z' && k; c++)
        for (int i = 0; i < n && k; i++)
            if (!rem[i] && s[i] == c)
                rem[i] = true, k--;

    for (int i = 0; i < n; i++)
        if (!rem[i]) printf("%c", s[i]);

    printf("\n");
}