#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_days;
    while (scanf("%d", &num_days), num_days) {
        multiset<int> bills;
        long long int sum = 0;

        while (num_days--) {
            int num_bills;
            scanf("%d", &num_bills);

            int bill;
            while (num_bills--)
                scanf("%d", &bill), bills.insert(bill);

            multiset<int>::iterator highest = bills.end();
            multiset<int>::iterator lowest = bills.begin();
            sum += *(--highest) - *lowest;

            bills.erase(highest);
            bills.erase(lowest);
        }

        printf("%lld\n", sum);
    }
}