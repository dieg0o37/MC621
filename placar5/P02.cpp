#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)


void solve() {
    ll X;
    cin >> X;
    ll p;
    ll divs = 0;
    if (X == 1 || X == 2 || X == 3) {
        cout << "NO" << "\n";
    }

    for (p = 2; p*p <= X; p++) {

        if (X%p == 0) {
            divs++;
            while(X%p == 0) {
                X /= p;
            }
        }

        if (divs > 1) {
            cout << "NO" << "\n";
            return;
        }
    }

    if (divs == 1) {
        if (X == 1) {
            cout << "YES" << "\n";
            return;
        } else if (X == 2 || X == 3) { 
            cout << "NO" << "\n";
            return;
        } else {
            for (p = 2; p*p <= X; p++) {
                if (X%p == 0) {
                    cout << "NO" << "\n";
                    return;
                }
            }
            cout << "YES" << "\n";
            return;
        }
    } else {
        cout << "NO" << "\n";
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    ll t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
