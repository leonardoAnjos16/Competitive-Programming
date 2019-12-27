#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Heap {
    vector< pair<int, int> > distances;
    int size;

    Heap() {
        this->distances.push_back(make_pair(0, 0));
        this->size = 0;
    }

    void insert(int vertex, int distance) {
        this->distances.push_back(make_pair(vertex, distance));
        this->size++;

        for (int i = this->size; i > 1; i /= 2) {
            if (this->distances[i].second < this->distances[i / 2].second)
                this->swap(&(this->distances[i]), &(this->distances[i / 2]));
        }
    }

    int removeMin() {
        int vertex = this->distances[1].first;
        this->distances[1] = this->distances[this->size--];
        this->distances.pop_back();
        this->heapify(1);

        return vertex;
    }

    bool isEmpty() {
        return this->size == 0;
    }

    void heapify(int pos) {
        if (pos * 2 <= this->size) {
            int sonPos = pos * 2;

            if (sonPos + 1 <= this->size && this->distances[sonPos + 1].second < this->distances[sonPos].second)
                sonPos++;

            if (this->distances[sonPos].second < this->distances[pos].second) {
                this->swap(&(this->distances[sonPos]), &(this->distances[pos]));
                this->heapify(sonPos);
            }
        }
    }

    void swap(pair<int, int> *a, pair<int, int> *b) {
        pair<int, int> aux = *a;
        *a = *b;
        *b = aux;
    }
};

struct Graph {
    vector< pair<int, int> > *connections;
    bool *visited;
    int numVertex;

    Graph(int numVertex) {
        this->connections = new vector< pair<int, int> >[numVertex];
        this->visited = new bool[numVertex];
        this->numVertex = numVertex;
    }

    ~Graph() {
        delete [] this->connections;
        delete [] this->visited;
    }

    void setEdge(int origin, int destiny, int weight) {
        int pos = this->getPos(origin, destiny);
        if (pos == -1)
            this->connections[origin].push_back(make_pair(destiny, weight));
        else if (this->connections[origin][pos].second > weight)
            this->connections[origin][pos].second = weight;
    }

    pair<int, int> getFirst(int vertex) {
        if (!this->connections[vertex].empty())
            return this->connections[vertex][0];

        return make_pair(this->numVertex, 0);
    }

    pair<int, int> getNext(int vertex, int pos) {
        if (pos < this->connections[vertex].size())
            return this->connections[vertex][pos];

        return make_pair(this->numVertex, 0);
    }

    int getPos(int origin, int destiny) {
        for (int i = 0; i < this->connections[origin].size(); i++) {
            if (this->connections[origin][i].first == destiny)
                return i;
        }

        return -1;
    }

    int getWeight(int origin, int destiny) {
        int pos = this->getPos(origin, destiny);
        if (pos != -1)
            return this->connections[origin][pos].second;

        return 0;
    }

    void unmarkAll() {
        for (int i = 0; i < this->numVertex; i++)
            this->visited[i] = false;
    }

    pair<int, int> getMinimumCost(int airportCost) {
        int numAirports = 0;
        this->unmarkAll();

        vector<int> vertices;
        for (int i = 0; i < this->numVertex; i++)
            vertices.push_back(-1);

        for (int i = 0; i < this->numVertex; i++) {
            if (!this->visited[i]) {
                vertices = this->prim(vertices, i);
                numAirports++;
            }
        }

        int minimumCost = numAirports * airportCost;
        for (int i = 0; i < this->numVertex; i++)
            minimumCost += this->getWeight(i, vertices[i]);

        return make_pair(minimumCost, numAirports);
    }

    vector<int> prim(vector<int> vertices, int vertex) {
        Heap aux;
        aux.insert(vertex, 0);

        vector<int> distances;
        for (int i = 0; i < this->numVertex; i++)
            distances.push_back(-1);

        distances[vertex] = 0;
        for (int i = 0; i < this->numVertex; i++) {
            do {
                if (!aux.isEmpty())
                    vertex = aux.removeMin();
                else
                    return vertices;
            } while (this->visited[vertex]);

            this->visited[vertex] = true;
            pair<int, int> first = this->getFirst(vertex);
            int counter = 0;
            while (first.first < this->numVertex) {
                int weight = first.second;
                if (!this->visited[first.first] && (distances[first.first] == -1 || (distances[first.first] > weight))) {
                    distances[first.first] = weight;
                    vertices[first.first] = vertex;
                    aux.insert(first.first, weight);
                }

                first = this->getNext(vertex, ++counter);
            }
        }

        return vertices;
    }
};

int main() {
    int numTestCases;
    cin >> numTestCases;

    for (int i = 1; i <= numTestCases; i++) {
        int numPlaces, numRoads, airportCost;
        cin >> numPlaces >> numRoads >> airportCost;

        Graph roads(numPlaces);
        for (int j = 0; j < numRoads; j++) {
            int origin, destiny, cost;
            cin >> origin >> destiny >> cost;

            if (cost < airportCost) {
                roads.setEdge(origin - 1, destiny - 1, cost);
                roads.setEdge(destiny - 1, origin - 1, cost);
            }
        }

        pair<int, int> bestArrangement = roads.getMinimumCost(airportCost);
        cout << "Case #" << i << ": " << bestArrangement.first << " " << bestArrangement.second << endl;
    }
}