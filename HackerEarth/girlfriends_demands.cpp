#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100001
 
int main() {
    char name[MAX];
    scanf("%s", name);
    
    int size = strlen(name);
    
    int num_queries;
    scanf("%d", &num_queries);
    
    while (num_queries--) {
        long long int a, b;
        scanf("%lld %lld", &a, &b);
        
        if (name[--a % size] == name[--b % size]) printf("Yes\n");
        else printf("No\n");
    }
}