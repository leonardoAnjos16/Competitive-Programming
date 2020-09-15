#include <bits/stdc++.h>

using namespace std;

#define MAX 200000

int main() {
    int size;
    scanf("%d", &size);

    string names[MAX];
    for (int i = 1; i <= size; i++)
        cin >> names[size - i];

    map<string, int> dict;
    for (int i = 0; i < size; i++) {
        if (dict.find(names[i]) == dict.end()) {
            cout << names[i] << endl;
            dict[names[i]] == 1;
        }
    }
}