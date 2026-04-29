int phi(int n) {

	int ans = n;

	for(int p = 2; p*p <= n; p++) {
		if(n%p == 0) {
			while(n%p == 0) { n /= p; }
			ans -= ans/p;
		}
	}

	if(n > 1) ans -= ans / n;

	return ans;

}

const int N = 1000000;
vector<int> phi(N);

void sieve() {

	for(int i = 1; i < N; i++) phi[i] = i;
	for(int i = 2; i < N; i++) {
		if(phi[i] == i) {
			for(int j = i; j < N; j += i) { phi[j] -= phi[j] / i; }
		}
	}

}