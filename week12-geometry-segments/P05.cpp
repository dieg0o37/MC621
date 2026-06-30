#include  <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, a, b) for(int i = a; i < b; i++)
#define Fr(i, a, b) for(int i = a; i >=b; i--)
typedef complex<ll> P;
#define Y imag() 
#define X real()
#define epsilon 1e17

ll gcd(ll a, ll b) {
    if (b > a) {
        b ^= a;
        a ^= b;
        b ^= a;
    }
    return (b == 0) ? a : gcd(b,a%b);
}

int solve() {
    int n;
    cin >> n;

    vector<P> points(n);
    F(i, 0, n) {
        ll x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    set<tuple<ll, ll, ll>> unique_lines;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto p1 = points[i];
            auto p2 = points[j];
            ll A = p2.Y - p1.Y;
            ll B = p1.X - p2.X;
            ll C = p2.X*p1.Y - p1.X*p2.Y;
            ll common_divisor = gcd(gcd(abs(A), abs(B)), abs(C));
            A /= common_divisor;
            B /= common_divisor;
            C /= common_divisor;
            if (A < 0 || (A == 0 && B < 0)) { //normaliza
                A = -A;
                B = -B;
                C = -C;
            }
            
            unique_lines.insert({A, B, C});
        }
    }

    ll lines = unique_lines.size();
    ll pairs = lines * (lines - 1) / 2;
    map<pair<ll, ll>, ll> slope_counts;

    for (const auto& line : unique_lines) {
        ll A = get<0>(line);
        ll B = get<1>(line);
        ll slope= gcd(abs(A), abs(B));
        A /= slope;
        B /= slope;
        if (A < 0 || (A == 0 && B < 0)) {
            A = -A;
            B = -B;
        }
        slope_counts[{A, B}]++;
    }
    ll parallel_pairs = 0;
    for (const auto& entry : slope_counts) {
        ll count = entry.second;
        if (count > 1) {
            parallel_pairs += count * (count - 1) / 2;
        }
    }
    cout << pairs - parallel_pairs << "\n";

    return 0;
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
