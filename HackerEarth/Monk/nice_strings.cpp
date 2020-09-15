#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000
 
int main() {
    int num_strings;
    scanf("%d", &num_strings);
    
    char strings[MAX][MAX];
    for (int i = 0; i < num_strings; i++) {
        scanf("%s", &strings[i]);
        
        int niceness = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(strings[j], strings[i]) < 0)
                niceness++;
        }
        
        printf("%d\n", niceness);
    }
}