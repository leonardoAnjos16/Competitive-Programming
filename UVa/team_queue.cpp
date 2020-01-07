#include <bits/stdc++.h>

using namespace std;

struct Team {
    int team_ID;
    queue<int> team_queue;
};

int main() {
    int num_teams, case_num = 1;
    while (scanf("%d", &num_teams), num_teams) {
        map<int, int> ID_to_team;
        for (int i = 0; i < num_teams; i++) {
            int num_elements;
            scanf("%d", &num_elements);

            while (num_elements--) {
                int ID; scanf("%d", &ID);
                ID_to_team[ID] = i;
            }
        }

        deque<Team> team_queues;
        char command;

        printf("Scenario #%d\n", case_num++);
        while (scanf("%s", &command), command != 'S') {
            if (command == 'E') {
                int ID; scanf("%d", &ID);
                int team_ID = ID_to_team[ID];

                int counter = 0;
                while (counter < team_queues.size() && (team_queues[counter].team_queue.empty() || team_queues[counter].team_ID != team_ID))
                    counter++;

                if (counter >= team_queues.size()) {
                    Team new_team;
                    new_team.team_ID = team_ID;
                    new_team.team_queue.push(ID);
                    team_queues.push_back(new_team);
                }
                else team_queues[counter].team_queue.push(ID);
            } else {
                while (team_queues.front().team_queue.empty())
                    team_queues.pop_front();

                printf("%d\n", team_queues.front().team_queue.front());
                team_queues.front().team_queue.pop();
            }
        }

        printf("\n");
    }
}