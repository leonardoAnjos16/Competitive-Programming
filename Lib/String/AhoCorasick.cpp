template<typename T = string, const int SIZE = 26, const int OFFSET = 'a'>
struct AhoCorasick {
private:
    struct Node {
        int nxt[SIZE];
        int link, slink, id;

        Node() {
            memset(nxt, 0, sizeof nxt);
            link = slink = 0;
            id = -1;
        }
    };

    int size, patterns;
    vector<Node> nodes;

public:
    AhoCorasick() {
        size = 1;
        patterns = 0;
        nodes.resize(1);
    }

    void insert(T &pattern) {
        int on = 0;
        for (int i = 0; i < (int) pattern.size(); i++) {
            int idx = pattern[i] - OFFSET;
            if (!nodes[on].nxt[idx]) {
                nodes[on].nxt[idx] = size++;
                nodes.emplace_back();
            }

            on = nodes[on].nxt[idx];
        }

        nodes[on].id = patterns++;
    }

    vector<vector<int>> get_matches(T &text) {
        build();

        int on = 0;
        vector<vector<int>> matches(text.size(), vector<int>());

        for (int i = 0; i < (int) text.size(); i++) {
            on = nodes[on].nxt[text[i] - OFFSET];
            Node &node = nodes[on];

            if (node.id != -1)
                matches[i].push_back(node.id);

            int curr = node.slink;
            while (curr) {
                matches[i].push_back(nodes[curr].id);
                curr = nodes[curr].slink;
            }
        }

        return matches;
    }

private:
    void build() {
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int on = q.front(); q.pop();
            Node &node = nodes[on];

            node.slink = nodes[node.link].id != -1 ? node.link : nodes[node.link].slink;
            for (int i = 0; i < SIZE; i++) {
                if (!node.nxt[i]) node.nxt[i] = nodes[node.link].nxt[i];
                else {
                    int to = node.nxt[i];
                    nodes[to].link = (on ? nodes[node.link].nxt[i] : 0);
                    q.push(to);
                }
            }
        }
    }
};