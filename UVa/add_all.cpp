#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    while (scanf("%d", &size), size) {
        priority_queue< int, vector<int>, greater<int> > numbers;
        int number;

        while (size--)
            scanf("%d", &number), numbers.push(number);

        long long int total_cost = 0;
        while (numbers.size() > 1) {
            int sum = numbers.top(); numbers.pop();
            sum += numbers.top(); numbers.pop();
            numbers.push(sum);

            total_cost += sum;
        }

        printf("%lld\n", total_cost);
    }
}