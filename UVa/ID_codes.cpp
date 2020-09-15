#include <bits/stdc++.h>

using namespace std;

#define MAX 51

int main() {
    char letters[MAX];
    while (scanf("%s", letters) && letters[0] != '#') {
        int size = strlen(letters);
        if (next_permutation(letters, letters + size)) printf("%s\n", letters);
        else printf("No Successor\n");
    }
}