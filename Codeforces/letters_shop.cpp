#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int main() {
    int n; scanf("%d", &n);
    char s[MAX]; scanf("%s", s);

    vector<int> pos[26];
    for (int i = 0; i < n; i++)
        pos[s[i] - 'a'].push_back(i);

    int m; scanf("%d", &m);
    while (m--) {
        char t[MAX]; scanf("%s", t);
        int size = strlen(t);

        int cnt[26] = {0}, min_letters = 0;
        for (int i = 0; i < size; i++)
            min_letters = max(min_letters, pos[t[i] - 'a'][cnt[t[i] - 'a']++]);

        printf("%d\n", ++min_letters);
    }
}