#include <bits/stdc++.h>

using namespace std;

#define llong long long int

struct Tree {
private:
    struct Node {
        Node *parent;
        vector<int> data;
        vector<Node*> children;

        Node(int v, Node *left = NULL, Node *right = NULL): parent(NULL) {
            data.assign(1, v);
            children.resize(2);
            children[0] = left;
            children[1] = right;
        }

        void push(int v) {
            data.push_back(v);
            int idx = (int) data.size() - 1;

            while (idx > 0 && data[idx] < data[idx - 1]) {
                swap(data[idx], data[idx - 1]);
                idx--;
            }

            children.push_back(NULL);
        }

        void push(Node *child) {
            int idx = 0;
            while (idx < (int) children.size() && children[idx] != child) idx++;
            assert(idx < (int) children.size());

            children.push_back(NULL);
            for (int i = (int) children.size() - 1; i > idx; i--)
                children[i] = children[i - 1];

            data.push_back(-1);
            for (int i = (int) data.size() - 1; i > idx; i--)
                data[i] = data[i - 1];

            data[idx] = child->data[1];

            children[idx] = new Node(child->data[0], child->children[0], child->children[1]);
            if (child->children[0] != NULL) child->children[0]->parent = child->children[1]->parent = children[idx];

            children[idx + 1] = new Node(child->data[2], child->children[2], child->children[3]);
            if (child->children[2] != NULL) child->children[2]->parent = child->children[3]->parent = children[idx + 1];

            children[idx]->parent = children[idx + 1]->parent = this;
        }
    };

    Node *root;

public:
    Tree(): root(NULL) {}

    void insert(int v) {
        if (root == NULL) root = new Node(v);
        else insert(v, root);
    }

    void preorder() {
        preorder(root);
    }

private:
    void insert(int v, Node *node) {
        if (node->data.size() >= 3) {
            if (node == root) {
                Node *left = new Node(root->data[0], root->children[0], root->children[1]);
                if (root->children[0] != NULL) root->children[0]->parent = root->children[1]->parent = left;

                Node *right = new Node(root->data[2], root->children[2], root->children[3]);
                if (root->children[2] != NULL) root->children[2]->parent = root->children[3]->parent = right;

                Node *new_root = new Node(root->data[1], left, right);
                left->parent = right->parent = new_root;

                root = new_root;
                node = root;
            } else {
                node->parent->push(node);
                node = node->parent;
            }
        }
        
        if (node->children[0] == NULL) node->push(v);
        else {
            int idx = 0;
            while (idx < (int) node->data.size() && node->data[idx] < v) idx++;
            insert(v, node->children[idx]);
        }
    }

    void preorder(Node *node) {
        if (node == NULL) return;

        for (int i = 0; i < (int) node->data.size(); i++) {
            if (i) cout << " ";
            cout << node->data[i];
        }

        cout << "\n";

        for (Node *child: node->children)
            preorder(child);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;

        Tree tree;
        while (n--) {
            int a; cin >> a;
            tree.insert(a);
        }

        cout << "Case #" << t << ":\n";
        tree.preorder();
    }
}