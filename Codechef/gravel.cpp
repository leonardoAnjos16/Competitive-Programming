#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<ll> bit;
int num_gravels;

int LSO(int i) { return (i & -i); }

void update(int i, ll k) {
    while (i <= num_gravels)
        bit[i] += k, i += LSO(i);
}

void update(int a, int b, ll k) {
    update(a, k);
    update(b + 1, -k);
}

ll get_val(int i) {
    ll sum = 0;
    while (i > 0)
        sum += bit[i], i -= LSO(i);

    return sum;
}

int main() {
    int num_ops; ll init_val;
    scanf("%d %d %lld\n", &num_gravels, &num_ops, &init_val);

    bit.assign(num_gravels + 1, 0);
    update(1, num_gravels, init_val);

    while (num_ops--) {
        char type; scanf("%c", &type);
        if (type == 'S') {
            int u, v; ll k;
            scanf("%d %d %lld\n", &u, &v, &k);
            update(u, v, k);
        } else {
            int p; scanf("%d\n", &p);
            ll val = get_val(p);
            printf("%lld\n", val);
        }
    }
}