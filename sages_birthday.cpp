#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> prices(n);
    vector<int> sorted;

    for(int i = 0; i < n; i++) cin >> prices[i];

    sorted = prices;
    sort(sorted.begin(), sorted.end());

    for(int i = 0; i < n; i++) {
        if(i%2 == 0) {
            prices[i] = sorted[(n)/2+i/2];
        } else {
            prices[i] = sorted[i/2];
        }
    }

    cout << (n-1)/2 << endl;

    for(int i = 0; i < n; i++) cout << prices[i] << " ";

    cout << endl;

    return 0;

}