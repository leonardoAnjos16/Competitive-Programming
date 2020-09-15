#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    vector<int> numbers(size);
    for (int i = 1; i <= size; i++) cin >> numbers[size - i];
    for (int i = 0; i < size; i++) cout << numbers[i] << " " << flush;

    return 0;
}