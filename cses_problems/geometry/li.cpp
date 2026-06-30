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

ll plt(const P& p1, const P& p2) {
    ll val = (conj(p1)*p2).Y;
    if (val == 0) return 0;
    return (val < 0) ? -1 : 1;
}

ll na_linha(const P& p1, const P& p2, const P& p3) {
    return ((p3.X <= max(p1.X, p2.X)) && (p3.X >= min(p1.X, p2.X)) &&
            (p3.Y <= max(p1.Y, p2.Y)) && (p3.Y >= min(p1.Y, p2.Y)));
}

void solve() {
    P a1, b1;
    P a2, b2;
    ll x, y;
    cin >> x >> y;
    a1 = {x, y};
    cin >> x >> y;
    b1 = {x, y};
    cin >> x >> y;
    a2 = {x, y};
    cin >> x >> y;
    b2 = {x, y};


    ll o1, o2, o3, o4;
    o1 = plt(b2 - b1, b2 - a1);
    o2 = plt(a2 - b1, a2 - a1);
    o3 = plt(b1 - b2, b1 - a2);
    o4 = plt(a1 - b2, a1 - a2);

    if (o1 != o2 && o3 != o4) {
        cout << "YES" << "\n";
        return;
    }

    if (o1 == 0 && na_linha(b1, a1, b2)){
        cout << "YES" << "\n";
    } else if (o2 == 0 && na_linha(b1, a1, a2)){
        cout << "YES" << "\n";
    } else if (o3 == 0 && na_linha(b2, a2, b1)) {
        cout << "YES" << "\n";
    } else if (o4 == 0 && na_linha(b2, a2, a1)) {
        cout << "YES" << "\n";
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
