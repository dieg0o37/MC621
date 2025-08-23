#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    // Your code here

    ll n;
    while(cin >> n){
        ll a_0 = 0, a_1 = 1, a_2 = 2;
        ll a_n = -1;

        if (n == 1) {
            cout << a_0 << "\n";
        } else if (n == 2) {
            cout << a_1 << "\n";
        } else if (n == 3) {
            cout << a_2 << "\n";
        }

        n -= 3;
        for (int i = 0; i < n; i++) {
            a_n = ((a_0 + a_1 + a_2)%(ll)(1e9 + 9));
            a_0 = a_1;
            a_1 = a_2;
            a_2 = a_n;
        }
        if (a_n != -1)
            cout << a_n << "\n";
    }
    
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Uncomment the following lines to read from a file instead of stdin
    /*
    #ifndef ONLINE_JUDGE
        freopen("P05.in", "r", stdin);
    #endif
    */

    solve();

    return 0;
}
