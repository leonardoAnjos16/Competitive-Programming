#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int NUMVERTEX = 10000;

struct Graph {
    bool *visited;

    Graph() {
        this->visited = new bool[NUMVERTEX];
    }

    ~Graph() {
        delete [] this->visited;
    }

    int setAllEdges(int *buttons, int numButtons, int currentCode, int unlockCode) {
        this->unmarkAll();
        queue< pair<int, int> > aux;
        aux.push(make_pair(currentCode, 0));

        while (!aux.empty()) {
            currentCode = aux.front().first;
            int path = aux.front().second;
            aux.pop();

            int counter = 0;
            while (counter < numButtons) {
                int first = (currentCode + buttons[counter++]) % NUMVERTEX;

                if (!this->visited[currentCode])
                    aux.push(make_pair(first, path + 1));

                if (first == unlockCode)
                    return path + 1;
            }

            this->visited[currentCode] = true;
        }

        return -1;
    }

    void unmarkAll() {
        for (int i = 0; i < NUMVERTEX; i++)
            this->visited[i] = false;
    }
};

int main() {
    int currentCode, unlockCode, numButtons, counter = 1;
    cin >> currentCode >> unlockCode >> numButtons;

    while (currentCode != 0 || unlockCode != 0 || numButtons != 0) {
        Graph codes;
        int *buttons = new int[numButtons];

        for (int i = 0; i < numButtons; i++)
            cin >> buttons[i];

        int answer = codes.setAllEdges(buttons, numButtons, currentCode, unlockCode);
        cout << "Case " << counter << ": " << flush;

        if (answer != -1)
            cout << answer << endl;
        else
            cout << "Permanently Locked" << endl;

        delete [] buttons;

        cin >> currentCode >> unlockCode >> numButtons;
        counter++;
    }

    return 0;
}