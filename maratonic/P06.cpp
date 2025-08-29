#include <bits/stdc++.h>
using namespace std;

int L = 0, R= 0;
void update(pair<int, int> leftp, pair<int, int> rightp) {
    if (leftp.second < rightp.second) { 
        R = min(R, rightp.first - 2);
    } else if (leftp.second > rightp.second) { 
        L = max(L, leftp.first);
    } else {
        return;
    }
}
void solve() {
    // Your code here
    int N, M;
    cin >> N >> M;
    L =0;
    R = N;
    set<pair<int, int>> points;
    pair<int, int> point = {0, 0}, left_point, right_point, cur_point;
    bool l = true, r = true;
    cin >> point.first >> point.second;
    points.insert(point);
    cout << L << " " <<  R << "\n";
    M--;

    while (M--) {
        cin >> cur_point.first >> cur_point.second;
        auto it_left = points.lower_bound(cur_point);
        auto it_right = points.upper_bound(cur_point);

        // Check if left_point exists (point strictly less than cur_point)
        if (it_left == points.begin()) {
            l = false; // no point to the left
        } else {
            --it_left;
            left_point = *it_left;
            l = true;
        }

        // Check if right_point exists (point strictly greater than cur_point)
        if (it_right == points.end()) {
            r = false; // no point to the right
        } else {
            right_point = *it_right;
            r = true;
        }
        if (r) {
            update(cur_point, right_point);
        }   
        if (l) {
            update(left_point, cur_point);
        }
        points.insert(cur_point);
        cout << L << " " <<  R << "\n";
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
