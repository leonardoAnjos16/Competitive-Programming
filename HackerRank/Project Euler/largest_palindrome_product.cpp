#include <bits/stdc++.h>

using namespace std;

bool isPalyndrom(string number) {
    int length = number.length();
    for (int i = 0; i < length; i++) {
        if (number[i] != number[length - 1 - i])
            return false;
    }

    return true;
}

bool isProduct(int number) {
    for (int i = 100; i < 1000; i++) {
        if (number % i == 0 && (number / i) >= 100 && (number / i) < 1000)
            return true;
    }

    return false;
}

int main() {
    int numCases;
    cin >> numCases;

    for (int i = 0; i < numCases; i++) {
        int number;
        cin >> number;

        int counter = number - 1;
        while (true) {
            if (isPalyndrom(to_string(counter)) && isProduct(counter))
                break;

            counter--;
        }

        cout << counter << endl;
    }

    return 0;
}