#include <iostream>

using namespace std;

int main() {
    int numberBooks, money;
    while (cin >> numberBooks) {
        int *prices = new int[numberBooks];
        for (int i = 0; i < numberBooks; i++)
            cin >> prices[i];

        cin >> money;

        for (int i = 0; i < numberBooks; i++) {
            for (int j = 0; j < numberBooks - i - 1; j++) {
                if (prices[j] < prices[j + 1]) {
                    int aux = prices[j];
                    prices[j] = prices[j + 1];
                    prices[j + 1] = aux;
                }
            }
        }

        int distance = 1;
        int first, second;
        bool done = false;
        for (int i = 0; i < numberBooks && !done; i++, distance++) {
            for (int j = 0; j < numberBooks - distance && !done; j++) {
                if (prices[j] + prices[j + distance] == money) {
                    first = prices[j + distance];
                    second = prices[j];
                    done = true;
                }
            }
        }

        cout << "Peter should buy books whose prices are " << first << " and " << second << "." << endl << endl;
    }
}