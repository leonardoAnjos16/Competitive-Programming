#include <bits/stdc++.h>

using namespace std;

#define long long long int

int n, k;
vector<int> A;
vector<vector<int>> memo;

bool possible(int i, int j) {
	if (i > j) return false;
	if (A[i] != A[j]) return false;
	if (i == j) return true;

	int &ans = memo[i][j];
	if (~ans) return ans;

	for (int l = 1; l <= k; l++)
		for (int m = 1; m <= k; m++)
			if (i + l < n && j - m >= 0)
				if (possible(i + l, j - m))
					return ans = true;

	return ans = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	A.resize(n);

	for (int i = 0; i < n; i++)
		cin >> A[i];

	memo.assign(n, vector<int>(n, -1));

	cout << (possible(0, n - 1) ? "YES" : "NO") << "\n";
}
