#include <bits/stdc++.h>

using namespace std;

int main() {
    int population, commands, case_num = 1;
    while (scanf("%d %d", &population, &commands), population || commands) {
        deque<int> people;
        int size = min(population, commands);

        for (int i = 1; i <= size; i++)
            people.push_back(i);

        printf("Case %d:\n", case_num++);
        for (int i = 0; i < commands; i++) {
            char command;
            scanf("%s", &command);

            if (command == 'N') {
                printf("%d\n", people.front());
                people.push_back(people.front());
                people.pop_front();
            } else {
                int ID;
                scanf("%d", &ID);

                for (int i = 0; i < people.size(); i++)
                    if (people[i] == ID)
                        people.erase(people.begin() + i);

                people.push_front(ID);
            }
        }
    }
}