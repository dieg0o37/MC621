#include  <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, a, b) for(int i = a; i < b; i++)
#define Fr(i, a, b) for(int i = a; i >=b; i--)
typedef complex<ll> P;
typedef complex<double> Pd;
#define Y imag() 
#define X real()
bool sort_x(Pd s1, Pd s2) {return (s1.X < s2.X);}
bool sort_y(Pd s1, Pd s2) {return (s1.Y < s2.Y);}

ll calc_half_area(const vector<P>& v) {
    ll ans = 0;
    F(i, 0, v.size() - 1) {
        ans += v[i].X*v[i + 1].Y - v[i + 1].X*v[i].Y;
    }
    return abs(ans);
}


void solve() {
    ll n;
    cin >> n;
    vector<P> v(n + 1);
    ll x, y;
    ll xf, yf;
    cin >> xf >> yf;
    v[0] = {xf, yf};
    v[n] = {xf, yf}; 
    F(i, 1, n) {
        cin >> x >> y;
        v[i] = {x, y};
    }
    cout << calc_half_area(v) << "\n";
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
