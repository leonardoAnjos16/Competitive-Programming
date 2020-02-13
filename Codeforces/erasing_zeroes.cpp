#include <bits/stdc++.h>

using namespace std;

#define MAX 105

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        char str[MAX]; scanf("%s", str);
        int size = strlen(str);

        int start = 0, end = size - 1;
        while (start < size && str[start] == '0') start++;
        while (end >= 0 && str[end] == '0') end--;

        int num_zeroes = 0;
        for (int i = start + 1; i < end; i++)
            if (str[i] == '0') num_zeroes++;

        printf("%d\n", num_zeroes);
    }
}