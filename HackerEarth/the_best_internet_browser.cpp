#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 205;
 
bool vowel(char c) {
    switch (c) {
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
 
int main() {
    int tc; scanf("%d", &tc);
    while (tc--) {
        char website[MAX];
        scanf("%s", website);
 
        int n = strlen(website);
 
        int cnt = 0;
        for (int i = 4; i < n - 4; i++)
            if (!vowel(website[i])) cnt++;
 
        printf("%d/%d\n", cnt + 4, n);
    }
}