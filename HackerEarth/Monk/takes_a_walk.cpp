#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100001
 
bool is_vowel(char letter) {
    switch(letter) {
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
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        char trees[MAX];
        scanf("%s", trees);
        
        int size = strlen(trees);
        int counter = 0;
        
        for (int i = 0; i < size; i++) {
            trees[i] = tolower(trees[i]);
            if (is_vowel(trees[i])) counter++;
        }
        
        printf("%d\n", counter);
    }
}