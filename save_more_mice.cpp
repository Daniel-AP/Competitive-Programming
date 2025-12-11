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

        vector<int> mice(k);

        for(int i = 0; i < k; i++) {
            cin >> mice[i];
        }

        sort(mice.begin(), mice.end(), greater<int>());

        int acc = 0;
        int i = 1;

        for(i = 1; i < k; i++) {
            acc += n-mice[i-1];
            if(acc >= mice[i]) break;
        }

        cout << i << endl;

    }

    return 0;

}