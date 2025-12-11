#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;
    int s = n*(n+1)/2;

    vector<int> a, b;
    int turn = 0;

    if(s%2 == 1) cout << "NO" << endl;
    else {

        for(int i = n; i >= 1; i-=2) {
            if(turn%2 == 0) {
                a.push_back(i);
                b.push_back(i-1);
            }
            else {
                b.push_back(i);
                if(i-1 > 0) a.push_back(i-1);
            }
            turn++;
        }

        cout << "YES" << endl;
        cout << a.size() << endl;
        for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
        cout << endl;
        cout << b.size() << endl;
        for(int i = 0; i < b.size(); i++) cout << b[i] << " ";
        cout << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}