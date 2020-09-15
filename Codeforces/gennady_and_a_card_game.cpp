#include <bits/stdc++.h>

using namespace std;

int main() {
    char deck[5];
    scanf("%s", deck);

    char hand[5];
    bool possible = false;

    for (int i = 0; i < 5; i++) {
        scanf("%s", hand);
        possible |= hand[0] == deck[0] || hand[1] == deck[1];
    }

    printf("%s\n", possible ? "YES" : "NO");
}