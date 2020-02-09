#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 105
 
int main() {
    int counter[26] = {0};
    char letter;
    
    set<char> letters;
    while (scanf("%c", &letter), letter != '\n')
        letters.insert(letter);
    
    int num_strs; scanf("%d", &num_strs);
    char word[MAX];
    
    int num_possible = 0;
    while (num_strs--) {
        scanf("%s", word);
        int size = strlen(word);
        
        bool possible = true;
        for (int i = 0; i < size; i++)
            if (letters.find(word[i]) == letters.end())
                possible = false;
                
        if (possible) num_possible++;
    }
    
    printf("%d\n", num_possible);
}