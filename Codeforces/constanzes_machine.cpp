#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
#define MOD 1000000007

int main() {
    char word[MAX];
    scanf("%s", word);

    int size = strlen(word);
    int num_strings[MAX];

    num_strings[0] = 1;
    num_strings[1] = word[0] == 'm' || word[0] == 'w' ? 0 : 1;

    bool zero = false;
    for (int i = 2; i <= size && !zero; i++) {
        if (word[i - 1] == 'm' || word[i - 1] == 'w') {
            num_strings[size] = 0;
            zero = true;
        } else if ((word[i - 1] == 'n' || word[i - 1] == 'u') && word[i - 1] == word[i - 2]) {
            num_strings[i] = (num_strings[i - 1] + num_strings[i - 2]) % MOD;
        } else {
            num_strings[i] = num_strings[i - 1];
        }
    }

    printf("%d\n", num_strings[size]);
}