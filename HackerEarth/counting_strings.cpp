#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000001
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        char word[MAX]; scanf("%s", word);
        long long int num_valid_strs = 0;
        
        int size = strlen(word);
        for (int i = 0; i < size; i++) {
            if (word[i] == 'a' || word[i] == 'z') {
                int counter = i - 1;
                while (counter >= 0 && word[counter] != 'a' && word[counter] != 'z')
                    counter--;
                    
                counter++;
                num_valid_strs += (size - i) * (i - counter + 1);
            }
        }
        
        printf("%lld\n", num_valid_strs);
    }
}