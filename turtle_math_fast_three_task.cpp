    #include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int sum = accumulate(a.begin(), a.end(), 0);
        int diff = 3;

        for(int e: a) {
            if((sum-e)%3 == 0) {
                diff = 1;
                break;
            }
        }

        cout << min((3-sum%3)%3, diff) << endl;
        
    }

    return 0;

}