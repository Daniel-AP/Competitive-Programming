#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, prev(0), c(1), m(0);
    cin >> n;

    vector<int> sushi(n);

    for(int i = 0; i < n; i++) {

        cin >> sushi[i];

    }

    for(int i = 1; i < n; i++) {

        if(sushi[i-1] != sushi[i]) {
            prev = c;
            c = 0;
        }

        c++;
        m = max(m, min(prev, c)*2);

    }
    
    cout << m << endl;

    return 0;

}