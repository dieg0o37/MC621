#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)

ll binary_search(vector<ll> v, ll target, ll n) {
    ll mid, start, end;
    end = n - 1;
    start = 0;
    while (end >= start ) {
        mid = start + (end - start)/2;
        if (v[mid] == target) {
            return 1;
        } 
        if (v[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return 0;

}

void solve() {
    ll n, x;
    cin >> n >> x;
    ll v1[n/2 + 1];
    ll v2[n/2];
    F(i, n) {
        if (i < n/2) {
            cin >> v1[i];
        } else {
            cin >> v2[i - n/2];
        }
    }
    vector<ll> s1, s2;
    ll total = 0;
    ll limite = n/2;
    if (n%2 != 0) {
        limite += 1;
    }
    for (int i = 1; i < (1 << limite); ++i) {
        ll soma = 0;
        bool estourou = false;
        for(int j = 0; j < limite; j++) {
            if ((i >> j) & 1) {
                if (soma + v2[j] > x) {
                    estourou = true;
                    break;
                }
                soma += v2[j];
            }
        }
        if (soma == x && !estourou) {
            total++;
            soma = 0;
            continue;
        }
        if (!estourou) {
            s2.push_back(soma);
            soma = 0;
        }
    }
    limite = n/2;
    for (int i = 1; i < (1 << limite); ++i) {
        ll soma = 0;
        bool estourou = false;
        for(int j = 0; j < limite; j++) {
            if ((i >> j) & 1) {
                if (soma + v1[j] > x) {
                    estourou = true;
                    break;
                }
                soma += v1[j];
            }
        }
        if (soma == x && !estourou) {
            total++;
            soma = 0;
            continue;
        }
        if (!estourou) {
            s1.push_back(soma);
            soma = 0;
        }
    }
    sort(s2.begin(), s2.end());
    for (auto c: s1) {
        ll target = x - c;
        if (binary_search(s2, target, s2.size())) {
            total++;
        }
    }
    cout << total << "\n";
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
