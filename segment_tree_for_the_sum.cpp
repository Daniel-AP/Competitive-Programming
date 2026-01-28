#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

struct Seg {
	int n;
	vector<int> s;

	Seg(int n, vector<int> &a) : n(n), s(2*n) {
		// Copy original array into second half of s (leaf nodes)
		for(int i = 0; i < n; i++) {
            s[i+n] = a[i];
        }
		
		// Build internal nodes from bottom up
		for(int i = n-1; i >= 0; i--) {
			s[i] = s[2*i]+s[2*i+1];
		}
	}

	void update(int i, int v) {
		i += n;        // Move index to leaf
		s[i] = v;      // Set new value
		while(i > 1) { 
			i /= 2;    // Move to parent
			s[i] = s[2*i]+s[2*i+1]; // Update parent
		}
	}

	int get(int l, int r) {

        // The query is of the following form: [l, r)

        // These variables will hold the max values collected from left and right halves
        int la = 0, ra = 0;

        // Shift the range to point to the leaf layer in the segment tree
        l += n;
        r += n;

        // While the interval is non-empty
        while(l < r) {
            // If l is a right child (odd index), it cannot be part of the same parent range
            if(l%2 == 1) {
                la = la+s[l];  // Include s[l] in result
                l++;                 // Move to next segment
            }

            // If r is a right child, then r-1 is a left child, we need to include it
            if(r%2 == 1) {
                r--;                 // Move to left sibling
                ra = s[r]+ra;  // Include s[r] in result
            }

            // Move one level up in the tree (parent range)
            l /= 2;
            r /= 2;
        }

        // Return the maximum value found across the selected left and right parts
        return la+ra;
    }

};

void solve() {

    int n, m; cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    Seg seg(n, a);

    while(m--) {
        int o; cin >> o;
        if(o == 1) {
            int i, v; cin >> i >> v;
            seg.update(i, v);
        } else {
            int l, r; cin >> l >> r;
            cout << seg.get(l, r) << "\n";
        }
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}