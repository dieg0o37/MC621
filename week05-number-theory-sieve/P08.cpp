#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)

void solve() {
    ll N;
    cin >> N;
    ll primo = 0, p;
    if (N == 3) {
        cout << 3 << "\n";
        return;
    } else if (N == 2) {
        cout << 2 << "\n";
        return;
    }
    ll pp = 1;
    while (primo != 2) {
        for(p = 2; p*p <= N; p++) {
            if (N%p == 0) {
                break;
            }
        }
        if (p*p > N) {
            primo = N;
            pp *= primo;
            cout << pp << "\n";
            //return;
        }
        N--;
    }
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
