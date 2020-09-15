#include <bits/stdc++.h>

using namespace std;

const int NUM_VERTICES = 26;

int find_diff(char name_1[], char name_2[]) {
    int min_size = min(strlen(name_1), strlen(name_2));
    for (int i = 0; i < min_size; i++)
        if (name_1[i] != name_2[i]) return i;

    return (min_size + 1);
}

void topo_sort(stack<char> *order, vector<int> connections[], int visited[], int vertex, bool *has_cycle) {
    visited[vertex] = 1;
    int num_edges = connections[vertex].size();

    for (int i = 0; i < num_edges; i++) {
        if (!visited[connections[vertex][i]])
            topo_sort(order, connections, visited, connections[vertex][i], has_cycle);
        else if (visited[connections[vertex][i]] == 1)
            *has_cycle = true;
    }

    visited[vertex] = 2;
    order->push((char) (vertex + 'a'));
}

void traverse(stack<char> *order, vector<int> connections[], bool *impossible) {
    int visited[NUM_VERTICES];
    for (int i = 0; i < NUM_VERTICES; i++)
        visited[i] = 0;

    for (int i = 0; i < NUM_VERTICES && !(*impossible); i++)
        if (!visited[i]) topo_sort(order, connections, visited, i, impossible);
}

int main() {
    int num_names;
    scanf("%d", &num_names);

    char names[100][101];
    for (int i = 0; i < num_names; i++)
        scanf("%s", names[i]);

    vector<int> connections[NUM_VERTICES];
    bool impossible = false;

    for (int i = 0; i < num_names - 1 && !impossible; i++) {
        int index = find_diff(names[i], names[i + 1]);
        if (index < strlen(names[i]) && index < strlen(names[i + 1]))
            connections[names[i][index] - 'a'].push_back(names[i + 1][index] - 'a');
        else if (strlen(names[i]) > strlen(names[i + 1]))
            impossible = true;
    }

    stack<char> order;
    traverse(&order, connections, &impossible);

    if (impossible) printf("Impossible\n");
    else {
        while (!order.empty()) {
            printf("%c", order.top());
            order.pop();
        }

        printf("\n");
    }
}