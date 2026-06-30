#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, a, b) for(int i = a; i < b; i++)
#define Fr(i, a, b) for(int i = a; i >=b; i--)
typedef complex<ll> Pd;
#define Y imag() 
#define X real()
double xProdD (Pd a, Pd b) {return (conj(a)*b).Y;}
double pltD(const Pd& p1, const Pd& p2) {
    double val = (conj(p1)*p2).Y;
    return (val == 0) ? 0 : (val < 0) ? -1 : 1;
}

struct PdHash {
    size_t operator()(const Pd& p) const {
        return hash<ll>()(p.X) ^ (hash<ll>()(p.Y) << 1);
    }
};

ll Ar(Pd a, Pd b) {
    return pow((a.X - b.X), 2) + pow((a.Y - b.Y), 2);
}

void solve() {
    int N;
    cin >> N;
    ll max_A = 0;
    vector<Pd> v(N);
    unordered_set<Pd, PdHash> point_set;

    F(i, 0, N) {
        ll x, y;
        cin >> x >> y;
        v[i] = {x, y};
        point_set.insert(v[i]);
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            auto p1 = v[i];
            auto p2 = v[j];
            
            Pd vec = p2 - p1;

            Pd vec_cw = {vec.Y, -vec.X};
            Pd p3_cw = p1 + vec_cw;
            Pd p4_cw = p2 + vec_cw;

            if (point_set.count(p3_cw) && point_set.count(p4_cw)) {
                max_A = max(max_A, Ar(p1, p2));
            }

            Pd vec_ccw = {-vec.Y, vec.X};
            Pd p3_ccw = p1 + vec_ccw;
            Pd p4_ccw = p2 + vec_ccw;

            if (point_set.count(p3_ccw) && point_set.count(p4_ccw)) {
                max_A = max(max_A, Ar(p1, p2));
            }
        }    
    }
    cout << max_A << "\n";
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