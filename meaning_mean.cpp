#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        make_heap(a.begin(), a.end(), greater<int>());

        while(a.size() > 1) {

            pop_heap(a.begin(), a.end(), greater<int>()); int x = a.back(); a.pop_back();
            pop_heap(a.begin(), a.end(), greater<int>()); int y = a.back(); a.pop_back();

            a.push_back((x+y)/2);
            push_heap(a.begin(), a.end(), greater<int>());

        }

        cout << a[0] << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}