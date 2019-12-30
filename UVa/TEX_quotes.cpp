#include <bits/stdc++.h>

using namespace std;

int main() {
    string phrase;
    bool leading = true;
    
    while (getline(cin, phrase)) {
        int size = phrase.size();
        for (int i = 0; i < size; i++) {
            if (phrase[i] == '"') {
                if (leading) printf("``");
                else printf("''");

                leading = !leading;
            } else printf("%c", phrase[i]);
        }
        
        printf("\n");
    }
}