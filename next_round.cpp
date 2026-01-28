#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    int current_num;
    int count = 0;
    int k_score = 0;
    
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> current_num;

        if(current_num == 0) break;
        if(i == k-1) k_score = current_num;
        if(current_num >= k_score) count++;
        else break;

    }
    
    cout << count;

    return 0;

}