#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)

ll gcd(ll a, ll b) { 
    while (b) {
        a %= b;
        a ^= b;
        b ^= a;
        a ^= b;
    }
    return a;

}

void solve() {
    while (true) {
        ll m, n;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        //vector<ll> rounds[n];
        ll tik;
        ll last_round[n];
        ll last_sum = 0;
        F(i, n) {
            F(j, m) {
                cin >> tik;
                //rounds[i].push_back(tik);
            }
            last_sum += tik;
            last_round[i] = tik;
        }

        ll common_divisor = LONG_MAX;
        
        F(i, n) {
            if (last_round[i] == 0) {
                cout << 0 << " / " << 1 << "\n";
                continue;
            } 
            if (last_sum == 0) {
                cout << 1 << " / " << n << "\n";
                continue;
            }
            ll sum_temp;
            sum_temp = last_sum;

            while (common_divisor != 1) {
                common_divisor = gcd(sum_temp, last_round[i]);
                sum_temp /= common_divisor;
                last_round[i] /= common_divisor;
            }
            common_divisor = LONG_MAX;
            cout << last_round[i] << " / " << sum_temp  << "\n";
        }
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
