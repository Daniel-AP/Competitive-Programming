#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {

        int n, m;
        cin >> n >> m;
        
        int perimiter = m*4;

        int x, y;
        cin >> x >> y;

        n--;

        while(n--) {

            int x, y;
            cin >> x >> y;

            int intersection = m-x+m-y;

            perimiter += m*4;
            perimiter -= intersection*2;

        }

        cout << perimiter << endl;

    }

    return 0;

}