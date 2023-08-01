int interpolate(int x, vector<int> &ys) {
    int n = (int) ys.size() - 1;
    vector<int> pnum(n + 2);
    vector<int> snum(n + 2);

    pnum[0] = 1;
    for (int i = 1; i <= n; i++)
        pnum[i] = (((1LL * pnum[i - 1] * (x - i)) % MOD) + MOD) % MOD;

    snum[n + 1] = 1;
    for (int i = n; i > 0; i--)
        snum[i] = (((1LL * snum[i + 1] * (x - i)) % MOD) + MOD) % MOD;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int num = (1LL * pnum[i - 1] * snum[i + 1]) % MOD;
        int den = (1LL * invs[n - i] * invs[i - 1]) % MOD;
        if ((n - i) & 1) den = (MOD - den) % MOD;

        int add = (1LL * num * den) % MOD;
        add = (1LL * add * ys[i]) % MOD;
        ans = (ans + add) % MOD;
    }

    return ans;
}