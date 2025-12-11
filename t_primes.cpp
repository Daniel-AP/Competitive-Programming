#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

unordered_set<ll> sieve(ll n) {

    if(n <= 2) return {};

    ll m = n/2;
    vector<bool> s(m, true);
    unordered_set<ll> squares = {4};

    for(ll i = 3; i*i < n; i += 2) {
        if(s[i/2]) {
            for(ll j = (i*i)/2; j < m; j += i) {
                s[j] = false;
            }
        }
    }

    for(ll i = 1; i < m; i++) {
        if(s[i]) squares.insert((2*i+1)*(2*i+1));
    }

    return squares;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    unordered_set<ll> squares = sieve(1e6+1);

    for(int i = 0; i < n; i++) {
        if(squares.count(a[i])) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;

}