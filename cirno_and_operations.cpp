#include <bits/stdc++.h>
using namespace std;

pair<vector<long long>, long long> difference(vector<long long> a) {

    vector<long long> r;
    long long t = 0;

    for(int i = 1; i < a.size(); i++) {
        r.push_back(a[i]-a[i-1]);
        t += a[i]-a[i-1];
    }

    return { r, t };

}


void solve() {

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;

        vector<long long> a(n);
        long long m = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i],
            m += a[i];
        }

        while(a.size() != 1) {
            pair<vector<long long>, long long> d1 = difference(a);
            reverse(a.begin(), a.end());
            pair<vector<long long>, long long> d2 = difference(a);
            if(d1.second > d2.second) a = d1.first;
            else a = d2.first;
            m = max(max(d1.second, d2.second), m);
        }

        cout << m << endl;

    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}