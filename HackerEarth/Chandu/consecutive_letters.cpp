#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 35;
 
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        char S[MAX]; scanf("%s", S);
        int n = strlen(S);
 
        printf("%c", S[0]);
        for (int i = 1; i < n; i++)
            if (S[i] != S[i - 1]) printf("%c", S[i]);
 
        printf("\n");
    }
}