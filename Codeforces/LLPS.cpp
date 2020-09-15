#include <bits/stdc++.h>

using namespace std;

const int MAX = 15;

int main() {
    char str[MAX]; scanf("%s", str);
    int n = strlen(str);

    char greatest = 'a';
    int counter = 0;

    for (int i = 0; i < n; i++) {
        if (str[i] == greatest) counter++;
        else if (str[i] > greatest) greatest = str[i], counter = 1;
    }

    for (int i = 0; i < counter; i++)
        printf("%c", greatest);

    printf("\n");
}