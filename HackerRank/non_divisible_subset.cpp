#include <bits/stdc++.h>

using namespace std;

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int get_subset_size(vector<int> numbers, int size, int non_factor) {
    vector<int> frequencies(non_factor);
    for (int i = 0; i < non_factor; i++) frequencies[i] = 0;

    for (int i = 0; i < size; i++)
        frequencies[numbers[i] % non_factor]++;

    if (frequencies[0] > 1) frequencies[0] = 1;
    if (non_factor % 2 == 0 && frequencies[non_factor / 2]  > 1) frequencies[non_factor / 2] = 1;

    int max_size = frequencies[0];
    for (int i = 1; i <= non_factor / 2; i++)
        max_size += max(frequencies[i], frequencies[non_factor - i]);

    return max_size;
}

int main() {
    int size, non_factor;
    cin >> size >> non_factor;

    vector<int> numbers(size);
    for (int i = 0; i < size; i++) cin >> numbers[i];

    int max_size = get_subset_size(numbers, size, non_factor);
    cout << max_size << endl;
    return 0;
}