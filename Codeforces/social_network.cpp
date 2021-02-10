#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; scanf("%d %d", &n, &k);
    deque<int> messages;

    for (int i = 0; i < n; i++) {
        int id; scanf("%d", &id);

        bool present = false;
        for (auto it = messages.begin(); it != messages.end() && !present; it++)
            if (*it == id) present = true;

        if (!present) {
            if ((int) messages.size() >= k) messages.pop_back();
            messages.push_front(id);
        }
    }

    printf("%d\n", (int) messages.size());
    for (auto it = messages.begin(); it != messages.end(); it++)
        printf("%d ", *it);
}