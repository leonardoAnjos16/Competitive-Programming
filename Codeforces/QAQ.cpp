#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    char str[MAX]; scanf("%s", str);
    int n = strlen(str);
    
    int num_QAQ = 0;
    for (int i = 0; i < n - 2; i++) if (str[i] == 'Q')
        for (int j = i + 1; j < n - 1; j++) if (str[j] == 'A')
            for (int k = j + 1; k < n; k++) if (str[k] == 'Q')
                num_QAQ++;

    printf("%d\n", num_QAQ);
}