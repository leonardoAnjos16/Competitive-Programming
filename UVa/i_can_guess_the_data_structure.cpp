#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_commands;
    while (scanf("%d", &num_commands) != EOF) {
        stack<int> Stack;
        queue<int> Queue;
        priority_queue<int> Heap;

        vector<bool> structure(3, true);
        bool impossible = false;
        
        while (num_commands--) {
            int type, x;
            scanf("%d %d", &type, &x);

            if (!impossible) {
                if (type == 1) {
                    Stack.push(x);
                    Queue.push(x);
                    Heap.push(x);
                } else if (Stack.empty()) {
                    impossible = true;
                } else {
                    if (Stack.top() != x) structure[0] = false;
                    if (Queue.front() != x) structure[1] = false;
                    if (Heap.top() != x) structure[2] = false;

                    Stack.pop();
                    Queue.pop();
                    Heap.pop();
                }
            }
        }

        int num_true = 0;
        for (auto boolean: structure)
            if (boolean) num_true++;

        if (impossible || !num_true) printf("impossible\n");
        else if (num_true > 1) printf("not sure\n");
        else if (structure[0]) printf("stack\n");
        else if (structure[1]) printf("queue\n");
        else printf("priority queue\n");
    }
}