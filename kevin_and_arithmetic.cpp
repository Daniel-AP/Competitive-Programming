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

        int even = 0;
        int odd = 0;

        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x%2 == 0) even++;
            else odd++;
        }

        
        if(even > 0) cout << odd+1 << endl;
        else cout << (odd+(odd>1))/2 << endl;

    }

    return 0;

}