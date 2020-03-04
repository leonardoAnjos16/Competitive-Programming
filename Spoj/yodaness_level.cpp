#include <bits/stdc++.h>

using namespace std;

const int MAX = 3e4 + 5;

int bit[MAX], size;

int LSO(int i) { return (i & -i); }

void update(int i, int v) {
    while (i <= size)
        bit[i] += v, i += LSO(i);
}

int count(int i) {
    int counter = 0;
    while (i > 0)
        counter += bit[i], i -= LSO(i);

    return counter;
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        scanf("%d", &size);
        for (int i = 0; i <= size; i++)
            bit[i] = 0;

        map<string, int> pos;
        string word;

        for (int i = 0; i < size; i++)
            cin >> word, pos[word] = i + 1;

        string words[MAX];
        for (int i = 1; i <= size; i++)
            cin >> words[size - i];

        int num_inv = 0;
        for (int i = 0; i < size; i++) {
            num_inv += count(pos[words[i]]);
            update(pos[words[i]], 1);
        }

        printf("%d\n", num_inv);
    }
}