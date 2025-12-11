#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;

        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int count = 0; 

        for(int i = n-2; i >= 0; i--) {
            if(a[i+1] == 0) {
                count = -1;
                break;
            }
            while(a[i] >= a[i+1]) {
                a[i] /= 2;
                count++;
            }
        }

        cout << count << endl;

    }

    return 0;

}