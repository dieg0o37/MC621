#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 2; i <= n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)

void solve() {
    ll X;
    cin >> X;
    ll resto;
    ll i;
    if (X == 1) {
        X++;
        cout << X << "\n";
        return;
    }
    if (X == 2) {
        cout << X << "\n";
        return;
    }
    do {
        ll limite = sqrt(X);
        for(i = 2; i <= limite; i++) {
            resto = X%i;
            if (resto == 0) break;
        }
        if (i == limite + 1) {
            cout << X << "\n";
            return;
        }
        X++;
    } while (true);
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
