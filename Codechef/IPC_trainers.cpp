#include <iostream>

using namespace std;

struct Node {
    int numberLectures;
    int sadness;
    Node *next;

    Node(int numberLectures, int sadness) {
        this->numberLectures = numberLectures;
        this->sadness = sadness;
        this->next = NULL;
    }
};

struct LinkedList {
    Node *head;
    Node *curr;
    int size;

    LinkedList() {
        this->head = NULL;
        this->curr = NULL;
        this->size = 0;
    }

    ~LinkedList() {
        for (int i = 0; i < this->size; i++) {
            Node *aux = this->head->next;
            delete this->head;
            this->head = aux;
        }

        this->head = NULL;
        this->curr = NULL;
        this->size = 0;
    }

    void insert(int numberLectures, int sadness) {
        if (this->head == NULL)
            this->head = this->curr = new Node(numberLectures, sadness);
        else {
            this->curr->next = new Node(numberLectures, sadness);
            this->curr = this->curr->next;
        }

        this->size++;
    }

    void moveToStart() {
        this->curr = this->head;
    }

    void next() {
        this->curr = this->curr->next;
    }
};

struct Heap {
    long long int **sadness;
    int size;

    Heap(int numberTrainers) {
        this->sadness = new long long int*[numberTrainers + 1];
        this->size = 0;
    }

    ~Heap() {
        for (int i = 1; i <= this->size; i++)
            delete [] this->sadness[i];

        delete [] this->sadness;
    }

    void insert(long long int sadness, long long int numberLectures) {
        long long int *newTrainer = new long long int[2];
        newTrainer[0] = sadness;
        newTrainer[1] = numberLectures;

        this->sadness[++this->size] = newTrainer;

        for (int i = this->size; i > 1 && this->sadness[i][0] > this->sadness[i / 2][0]; i /= 2) {
            long long int *aux = this->sadness[i];
            this->sadness[i] = this->sadness[i / 2];
            this->sadness[i / 2] = aux;
        }
    }

    void remove() {
        if (this->size > 0) {
            this->sadness[1][1]--;

            if (this->sadness[1][1] == 0) {
                delete [] this->sadness[1];
                this->sadness[1] = this->sadness[this->size--];
                heapify(1);
            }
        }
    }

    void heapify(int index) {
        if (index <= this->size / 2) {
            int indexSon = index * 2;

            if (indexSon + 1 <= this->size && this->sadness[indexSon + 1][0] > this->sadness[indexSon][0])
                indexSon++;

            if (this->sadness[indexSon][0] > this->sadness[index][0]) {
                long long int *aux = this->sadness[index];
                this->sadness[index] = this->sadness[indexSon];
                this->sadness[indexSon] = aux;

                heapify(indexSon);
            }
        }
    }

    long long int getSum() {
        long long int sum = 0;
        for (int i = 1; i <= this->size; i++)
            sum += this->sadness[i][0] * this->sadness[i][1];

        return sum;
    }
};

int main() {
    int numberTestCases;
    cin >> numberTestCases;

    for (int i = 0; i < numberTestCases; i++) {
        int numberTrainers, numberDays;
        cin >> numberTrainers >> numberDays;

        LinkedList *trainers = new LinkedList[numberDays];
        for (int j = 0; j < numberTrainers; j++) {
            long long int day, lectures, sadness;
            cin >> day >> lectures >> sadness;

            trainers[day - 1].insert(lectures, sadness);
        }

        Heap heap(numberTrainers);
        for (int j = 0; j < numberDays; j++) {
            trainers[j].moveToStart();
            for (int k = 0; k < trainers[j].size; k++) {
                heap.insert(trainers[j].curr->sadness, trainers[j].curr->numberLectures);
                trainers[j].next();
            }

            heap.remove();
        }

        cout << heap.getSum() << endl;
        delete [] trainers;
    }
}