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

ll x_prod(const P& p1, const P& p2) {
    return (conj(p1)*p2).Y;
}

void solve() {
    P p1, p2, p3;
    ll x, y;
    cin >> x >> y;
    p1 = {x, y};
    cin >> x >> y;
    p2 = {x, y};
    cin >> x >> y;
    p3 = {x, y};
    P v1 = p3 - p1, v2 = p3 - p2;
    ll prod = x_prod(v1, v2);
    if (prod > 0) {
       cout << "LEFT" << "\n";
    } else if (prod < 0) {
       cout << "RIGHT" << "\n";
    } else {
        cout << "TOUCH" << "\n";
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
