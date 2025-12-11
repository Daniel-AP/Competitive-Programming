#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n+1);
    vector<long long> forward(n+1);
    vector<long long> backward(n+1);

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) {
        forward[i] = (a[i-1] > a[i] ? a[i-1]-a[i] : 0) + forward[i-1];
    }

    for(int i = n-1; i > 0; i--) {
        backward[i] = (a[i+1] > a[i] ? a[i+1]-a[i] : 0) + backward[i+1];
    }
    
    for(int i = 0; i < m; i++) {

        int s, j, d(0);
        cin >> s >> j;

        if(s < j) {
            cout << forward[j]-forward[s] << endl;
        } else {
            cout << backward[j]-backward[s] << endl;
        }

    }

    return 0;

}