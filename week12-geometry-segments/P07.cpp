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

bool li(P a1, P b1, P a2, P b2) {
    ll o1, o2, o3, o4;
    o1 = plt(b2 - b1, b2 - a1);
    o2 = plt(a2 - b1, a2 - a1);
    o3 = plt(b1 - b2, b1 - a2);
    o4 = plt(a1 - b2, a1 - a2);

    if (o1 != o2 && o3 != o4) {
        return true;
    }

    if (o1 == 0 && na_linha(b1, a1, b2)){
        return true;
    } else if (o2 == 0 && na_linha(b1, a1, a2)){
        return true;
    } else if (o3 == 0 && na_linha(b2, a2, b1)) {
        return true;
    } else if (o4 == 0 && na_linha(b2, a2, a1)) {
        return true;
    } else {
        return false;
    }
}

void solve() {
    ll M;
    cin >> M;
    vector<pair<P, P>> v(M);
    F(i, 0, M) {
        P a, b;
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a = {x1, y1};
        b = {x2, y2};
        v[i] = make_pair(a, b);
    }
    ll n_quero = 0;
    vector<bool> iso(M, true);
    for (int i = 0; i < M; ++i) {
        for (int j = i + 1; j < M; ++j) {
            if (!iso[i] && !iso[j]) continue;
            auto s1 = v[i];
            auto s2 = v[j];
            if (li(s1.first, s1.second, s2.first, s2.second)) {
                if (iso[i] != iso[j]) {
                    n_quero++;
                } else if (iso[i]){
                    n_quero += 2;
                } 
                iso[j] = false;
                iso[i] = false;
            }
        }
    }
    cout << M - n_quero << "\n";
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
