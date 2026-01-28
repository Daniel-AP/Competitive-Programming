#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

// MUST BE AN ASSOCIATIVE AND INVERTIBLE OPERATION

int op(int a, int b) {
    return a+b;
}

int inv(int a) {
    return -a;
}

const int neu = 0;

struct BIT {

    int n;
    vector<int> t;

    BIT(int n, vector<int>& a) : n(n), t(n+1, neu) {

        for(int i = 1; i <= n; i++) {
            t[i] = op(t[i], a[i-1]);
            int j = i+(i&-i);
            if(j <= n) t[j] = op(t[j], t[i]);
        }

    }

    void update(int i, int val) {

        int curr = range(i, i);
        int x = op(val, inv(curr));

        while(i <= n) {
            t[i] = op(t[i], x);
            i += i&-i;
        }

    }

    int query(int i) {

        int ans = neu;

        while(i > 0) {
            ans = op(ans, t[i]);
            i -= i&-i;
        }

        return ans;

    }

    int range(int l, int r) {
        
        return op(query(r), inv(query(l-1)));

    }

};

// struct BIT {

//     int n;               // Size of the array
//     vector<int> tree;    // The BIT array (1-based indexing)

//     // Constructor: initialize BIT of size 'size'
//     BIT(int n, const vector<int>& arr) : n(n), tree(n+1) {

//         for(int i = 1; i <= n; i++) {
//             tree[i] += arr[i-1]; 
//             int j = i+(i&-i);
//             if(j <= n) tree[j] += tree[i];
//         }

//     }

//     // Add 'val' to index 'i' (1-based)
//     void update(int i, int val) {
//         // Traverse all nodes that are responsible for index 'i'
//         while(i <= n) {
//             tree[i] += val;      // Update current node
//             i += i&-i;         // Move to next node responsible for index i
//             // 'i&-i' isolates the lowest set bit
//             // Adding it moves to the next interval that includes i
               // its the only way to incremente the LSB
               // only ranges greater than i include i
//         }
//     }

//     // Query prefix sum from 1 to index 'i'
//     int query(int i) {
//         int sum = 0;
//         // Traverse all relevant nodes to accumulate the sum
//         while(i > 0) {
//             sum += tree[i];      // Add current node's value
//             i -= i&-i;         // Allows us to move the parent node which is the next number with a greater LSB
//             // because all ranges of the same size are disjoint then we can only check larger ranges (greater LSB)
//             // Subtracting 'i&-i' moves to the previous interval
//         }
//         return sum;
//     }

//     // Query sum of range [l, r]
//     int range(int l, int r) {
//         // Use prefix sums to get range sum
//         // sum(l..r) = sum(1..r)-sum(1..(l-1))
//         return query(r)-query(l-1);
//     }

// };

void solve() {

    
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}