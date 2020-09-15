#include <bits/stdc++.h>

using namespace std;

int main() {
    int size, numOps;
    cin >> size >> numOps;

    long int *array = new long int[size + 1]();
    for (int i = 0; i < numOps; i++) {
        int left, right, value;
        cin >> left >> right >> value;

        array[left - 1] += value;
        array[right] -= value;
    }

    long int max = 0;
    for (int i = 1; i <= size; i++) {
        array[i] += array[i - 1];
        if (array[i] > max) max = array[i];
    }

    cout << max << endl;

    delete [] array;
    return 0;
}