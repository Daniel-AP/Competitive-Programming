#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        int n, k;
        cin >> n >> k;

        int target = k*(n/k+(n%k!=0));
        int base = target/n;
        int mod = target%n;
        
        cout << base+mod/n+(mod%n!=0) << endl;

    }

    return 0;

}