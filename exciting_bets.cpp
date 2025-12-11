#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while(t--) {

        ll a, b;
        cin >> a >> b;

        if(a == b) {
            cout << 0 << " " << 0 << endl;
        } else {
            ll diff = abs(a-b);
            cout << abs(a-b) << " " << min(a%diff, diff-a%diff) << endl;
        }

    }
    
}