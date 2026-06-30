#include  <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, a, b) for(int i = a; i < b; i++)
#define Fr(i, a, b) for(int i = a; i >=b; i--)
typedef complex<ll> P;
typedef complex<double> Pd;
#define Y imag() 
#define X real()
double xProdD (Pd a, Pd b) {return (conj(a)*b).Y;}
ll xProd (P a, P b) {return (conj(a)*b).Y;}
ll plt(const P& p1, const P& p2) {
    ll val = (conj(p1)*p2).Y;
    return (val == 0) ? 0 : (val < 0) ? -1 : 1;}
double pltD(const Pd& p1, const Pd& p2) {
    double val = (conj(p1)*p2).Y;
    return (val == 0) ? 0 : (val < 0) ? -1 : 1;}

ll calc_double_area(const vector<P>& v) {
    ll ans = 0;
    F(i, 0, v.size() - 1) {
        ans += v[i].X*v[i + 1].Y - v[i + 1].X*v[i].Y;
    }
    return abs(ans);
}
ll euc_dist_floor(const P& a, const P& b) { 
    return (ll)sqrt(pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2));
}
ll na_linha(const P& p1, const P& p2, const P& p3) {
    return ((p3.X <= max(p1.X, p2.X)) && (p3.X >= min(p1.X, p2.X)) &&
            (p3.Y <= max(p1.Y, p2.Y)) && (p3.Y >= min(p1.Y, p2.Y)));
}
ll gcd (ll a, ll b) {
    return (b == 0 ? a : gcd(b, a%b));
}

void solve() {
    ll n;
    cin >> n;
    vector<P> v(n + 1);
    ll x, y;
    cin >> x>> y;
    v[0] = {x, y};
    v[n] = {x, y}; 
    F(i, 1, n) {
        cin >> x >> y;
        v[i] = {x, y};
    }
    ll A = calc_double_area(v);
    ll bound = 0;
    F(i, 0, n) {
        P p1 = v[i], p2 = v[i + 1];
        ll dx = abs(p1.X - p2.X);
        ll dy = abs(p1.Y - p2.Y);
        bound += (gcd(dx, dy));
    }
    ll I = ((A - bound)/2) + 1;
    cout << I << " " << bound <<"\n";
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
