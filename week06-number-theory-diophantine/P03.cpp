#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fact(ll n) {
    ll ans = 1;
    while (n) {
        ans *= n;
        n--;
    }
    return ans;
}


int main(){
    ll a, b;
    cin >> a >> b;
    if (a == 0) {
        if (b < 5) {
            cout << fact(b)%10 << "\n";
        } else {
            cout << 0 << "\n";
        }
        return 0;
    }

    if (a == b) {
        cout << 1 << "\n";
        return 0;
    } 

    ll ans = (a + 1)%10;
    ll temp = ans;
    if (b - a >= 5) cout << 0 << "\n";
    else {
        for (ll i = 0; i < b - a - 1; i++) {
            ans = (ans*(temp + 1)%10)%10;
            temp = (temp + 1)%10;
        }
        cout << ans << "\n";
    }
    return 0;
}