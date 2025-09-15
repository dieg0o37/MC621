#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 2; i < n; i++)
#define Fr(i, n) for(int i = n; i >= 2; i--)

ll factorial(ll a) {
    ll result = 1;
    Fr(i, a) {
        result *= i;
    }
    return result;
}

void solve() {
    ll a, b;
    cin >> a >> b;
    ll min_val = min(a, b);
    cout << factorial(min_val) << "\n";
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    ll t;
    cin >> t;
    while(t--)
    */
        solve();

    return 0;
}
