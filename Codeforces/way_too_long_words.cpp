#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int n; scanf("%d", &n);
    while (n--) {
        char s[MAX]; scanf("%s", s);
        int size = strlen(s);

        if (size <= 10) printf("%s\n", s);
        else {
            string ans = s[0] + to_string(size - 2) + s[size - 1];
            printf("%s\n", ans.c_str());
        }
    }
}