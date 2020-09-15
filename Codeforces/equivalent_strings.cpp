#include<bits/stdc++.h>

using namespace std;

#define MAX 200001

bool are_equivalent(char string_1[], char string_2[], int size, int pos_1 = 0, int pos_2 = 0) {
    bool equal = true;
    for (int i = 0; i < size && equal; i++)
        if (string_1[pos_1 + i] != string_2[pos_2 + i])
            equal = false;

    if (equal) return true;
    else if (size % 2) return false;
    else {
        int half = size / 2;
        if (are_equivalent(string_1, string_2, half, pos_1, pos_2) && are_equivalent(string_1, string_2, half, pos_1 + half, pos_2 + half)) return true;
        else if (are_equivalent(string_1, string_2, half, pos_1, pos_2 + half) && are_equivalent(string_1, string_2, half, pos_1 + half, pos_2)) return true;
        else return false;
    }
}

int main() {
    char string_1[MAX], string_2[MAX];
    scanf("%s\n%s", string_1, string_2);

    int size = strlen(string_1);
    bool equivalent = are_equivalent(string_1, string_2, size);

    if (equivalent) printf("YES\n");
    else printf("NO\n");
}