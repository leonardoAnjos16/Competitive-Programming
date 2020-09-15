#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int size_first, size_second;
        scanf("%d %d", &size_first, &size_second);

        multiset<int> first_list;
        int number;

        while (size_first--)
            scanf("%d", &number), first_list.insert(number);

        int counter = 0;
        while (size_second--) {
            scanf("%d", &number);

            multiset<int>::iterator it = first_list.find(number);
            if (it == first_list.end()) counter++;
            else first_list.erase(it);
        }

        int num_removed = counter + first_list.size();
        printf("%d\n", num_removed);
    }
}