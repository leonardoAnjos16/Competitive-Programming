#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;

	vector<int> x(N);
	for (int i = 0; i < N; i++)
		cin >> x[i];

	vector<int> y(N);
	for (int i = 0; i < N; i++)
		cin >> y[i];

	for (int i = 0; i < N; i++) {
		if (i) cout << " ";
		vector<int> primes;

		int aux = x[i];
		for (int j = 2; j * j <= aux; j++) {
			if (!(aux % j)) primes.push_back(j);
			while (!(aux % j)) aux /= j;
		}

		if (aux > 1) primes.push_back(aux);

		int ans = 0;
		for (int p: primes)
			for (int j = i - 1, k = 0; k < y[i]; j--, k++)
				if (!(x[j] % p)) {
					ans++;
					break;
				}

		cout << ans;
	}
}