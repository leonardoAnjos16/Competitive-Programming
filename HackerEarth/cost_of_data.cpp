#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100
 
struct Node {
    char letter;
    Node* children[26];
    
    Node(char letter) {
        this->letter = letter;
        for (int i = 0; i < 26; i++)
            this->children[i] = NULL;
    }
};
 
struct Tree {
    Node *head;
    int num_nodes;
    
    Tree() {
        head = new Node('-');
        num_nodes = 1;
    }
    
    void insert(char word[]) {
        insert(word, 0, head);
    }
    
    void insert(char word[], int index, Node *node) {
        if (index < strlen(word)) {
            if (node->children[word[index] - 'a'] == NULL) {
                node->children[word[index] - 'a'] = new Node(word[index]);
                num_nodes++;
            }
                
            insert(word, index + 1, node->children[word[index] - 'a']);
        }
    }
};
 
int main() {
    int num_strings;
    scanf("%d", &num_strings);
    
    Tree tree;
    while (num_strings--) {
        char word[MAX]; scanf("%s", word);
        tree.insert(word);
    }
    
    printf("%d\n", tree.num_nodes);
}