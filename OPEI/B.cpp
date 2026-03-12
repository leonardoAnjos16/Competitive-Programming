#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int n, X; llong Y;
vector<llong> nums;
vector<int> ans;

bool possible(llong sum = 0LL, int i = 0) {
    if ((int) ans.size() > X) return false;
    if (i >= n) return (int) ans.size() == X && sum == Y;

    if (possible(sum, i + 1)) return true;

    ans.push_back(i);
    if (possible(sum + nums[i], i + 1))
        return true;

    ans.pop_back();
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Y >> X >> n;

    if (X > 4) return 0;

    nums.resize(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    if (possible())
        for (int i = 0; i < X; i++)
            cout << ans[i] << "\n";
}