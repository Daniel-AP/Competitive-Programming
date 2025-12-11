#include <bits/stdc++.h>
using namespace std;

#define int long long

int multinomial(vector<int> numerators, vector<int> denominators) {

    int nums = 1, denoms = 1;
    int n = numerators.size();

    for(int i = 0; i < n; i++) {
        nums *= numerators[i];
        denoms *= denominators[i];
        int g = gcd(nums, denoms);
        nums /= g; denoms /= g;
    }

    return nums/denoms;

}

void solve() {

    string s, prev; cin >> s;
    int n = s.length();

    sort(s.begin(), s.end());

    map<char, int> freq;
    vector<int> numerators(n), denominators;

    denominators.reserve(n);

    iota(numerators.begin(), numerators.end(), 1);
    for(int i = 0; i < n; i++) denominators.push_back(++freq[s[i]]);

    denominators.resize(n, 1);

    cout << multinomial(numerators, denominators) << endl;

    do {
        if(s == prev) continue;

        cout << s << endl;
        prev = s;

    } while(next_permutation(s.begin(), s.end()));

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}