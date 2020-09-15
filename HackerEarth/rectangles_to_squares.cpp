#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
 
int main() {
    ll m, n; scanf("%lld %lld", &m, &n);
    ll size = gcd(m, n);
        
    if (size == 1) printf("No\n");
    else printf("Yes\n");
}