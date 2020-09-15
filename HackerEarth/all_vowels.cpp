#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 10001
 
int main() {
    int size;
    scanf("%d", &size);
    
    char letters[MAX];
    scanf("%s", letters);
    
    bool vowels[5];
    for (int i = 0; i < 5; i++)
        vowels[i] = false;
    
    for (int i = 0; i < size; i++) {
        if (letters[i] == 'a')
            vowels[0] = true;
        else if (letters[i] == 'e')
            vowels[1] = true;
        else if (letters[i] == 'i')
            vowels[2] = true;
        else if (letters[i] == 'o')
            vowels[3] = true;
        else if (letters[i] == 'u')
            vowels[4] = true;
    }
    
    bool all_vowels = true;
    for (int i = 0; i < 5; i++)
        all_vowels &= vowels[i];
        
    if (all_vowels) printf("YES\n");
    else printf("NO\n");
}