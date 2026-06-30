#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)
// find earliest train that arrives on station i for 1<=i<= N-1
// say that train arrives in c seconds
// total min time is c + sum Cj for i <= j <= N - 1
// keep a list of min_times initialized to infinity
// min_times[0] = S0 + Ctotal
// min_times[1] = min(S0 + C1 + Csum, S1 + Csum) (C1 + Csum = Ctotal => = min(min_times[0], S1 + Ctotal))
typedef struct  est
{
    ll S, F, C;
} est;



void solve() {
    ll N;
    cin >> N;
    vector<est> v(N);
    F(i, N - 1) {
        cin >> v[i].C >> v[i].S >> v[i].F;
    }
    
    v[N - 1].S = 0;
    F(j ,N) {
        ll res = v[j].S;
        for(ll i = j; i <  N - 1; i ++){
            res +=  v[i].C;
            if (i != N - 2){
                ll x = -res + v[i + 1].S;
                if (x > 0){
                    res += x;
                } else if (x < 0) {
                    if (res % v[i+1].F != 0) {
                        res += v[i+1].F - (res % v[i+1].F);
                    }
                }
            }
        }
        cout << res << "\n";
        res = 0;
    }
    //F(i, N) cout << v[i].t_total << "\n";
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
