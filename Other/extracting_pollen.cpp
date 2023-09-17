#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e6 + 5;

int nxt[MAX], val[MAX];

int sum_digits(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}

void get_path(int x) {
    if (!x || nxt[x] != -1) return;
    get_path(nxt[x] = x - sum_digits(x));
}

void get_vals() {
    int deg[MAX] = {0};
    for (int i = 0; i < MAX; i++)
        if (nxt[i] != -1)
            deg[nxt[i]]++;

    queue<int> q;
    for (int i = 0; i < MAX; i++)
        if (nxt[i] != -1 && !deg[i])
            q.push(i);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        if (nxt[v] != -1) {
            val[nxt[v]] += val[v];
            if (--deg[nxt[v]] == 0)
                q.push(nxt[v]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    memset(nxt, -1, sizeof nxt);
    memset(val, 0, sizeof val);

    vector<int> F(N);
    for (int i = 0; i < N; i++) {
        cin >> F[i];
        val[F[i]]++;
        get_path(F[i]);
    }

    get_vals();

    vector<int> nums;
    for (int i = MAX - 1; i > 0; i--)
        if (nxt[i] != -1)
            nums.push_back(i);

    nums.push_back(0);

    int ans = -1;
    llong sum = 0LL;
    
    for (int i = 0; i < (int) nums.size() && ans == -1; i++) {
        sum += val[nums[i]];
        if (sum >= K)
            ans = sum_digits(nums[i]);
    }

    if (ans == -1) ans = 0;
    cout << ans << "\n";
}