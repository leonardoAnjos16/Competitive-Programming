#include <bits/stdc++.h>
 
using namespace std;
 
//#define long long long int
 
const int MAX = 1e5 + 5;
 
int main() {
    int n; scanf("%d", &n);
 
    long cnt[MAX] = {0}, total = 0;
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        total += cnt[a];
        cnt[a]++;
    }
 
    printf("%lld\n", total);
}