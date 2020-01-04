#include <bits/stdc++.h>

using namespace std;

struct node {
    char character;
    node *next;
};

struct linked_list {
    node *front, *rear, *curr;
    int size;
};

node *create_node(char character = '-', node *next = NULL) {
    node *new_node = new node;
    new_node->character = character;
    new_node->next = next;
    return new_node;
}

linked_list *create_list() {
    linked_list *new_list = new linked_list;
    new_list->front = new_list->rear = new_list->curr = create_node();
    new_list->size = 0;
    return new_list;
}

void insert(linked_list *list, char character) {
    list->curr->next = create_node(character, list->curr->next);
    if (list->curr == list->rear) list->rear = list->curr->next;
    list->curr = list->curr->next;
    list->size++;
}

void move_curr(linked_list *list, node *new_pos) {
    list->curr = new_pos;
}

string to_string(linked_list *list) {
    string text = "";

    move_curr(list, list->front);
    while (list->curr != list->rear)
        text += list->curr->next->character, list->curr = list->curr->next;

    return text;
}

int main() {
    string line;
    while (cin >> line) {
        linked_list *list = create_list();
        int size = line.size();

        for (int i = 0; i < size; i++) {
            if (line[i] == '[') move_curr(list, list->front);
            else if (line[i] == ']') move_curr(list, list->rear);
            else insert(list, line[i]);
        }

        string beiju_text = to_string(list);
        printf("%s\n", beiju_text.c_str());
    }
}