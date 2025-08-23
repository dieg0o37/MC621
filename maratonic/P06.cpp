#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Your code here
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> min_points;
    pair<int, int> min_point = {0, 0}, left_point, right_point, cur_point;
    int L = 0, R = N;

    cin >> min_point.first >> min_point.second;
    min_points.insert(min_point);
    cout << L << " " <<  R << "\n";
    M--;

    while (M--) {
        cin >> cur_point.first >> cur_point.second;
        if (cur_point.second == (*min_points.begin()).second) {
            min_points.insert(cur_point);
            cout << L << " " <<  R << "\n";
            continue;
        }
        if (cur_point.first < (*min_points.begin()).first) {
            left_point = cur_point;
            right_point = *min_points.begin();
        } else if (cur_point.first > (*min_points.rbegin()).first){
            right_point = cur_point;
            left_point = *min_points.rbegin();
        } else {
            left_point = (*min_points.lower_bound(cur_point));
            right_point = (*min_points.upper_bound(cur_point));
            L = max(L, left_point.first);
            R = min(R, right_point.first - 2);
            cout << L << " " <<  R << "\n";
            continue;
        }
        if (right_point.second < left_point.second){
            L = max(L, left_point.first);
        } else {
            R = min(R, right_point.first - 2);
        }
        if (cur_point.second < (*min_points.begin()).second) {
            min_points.clear();
            min_points.insert(cur_point);
        }  
        cout << L << " " <<  R << "\n";
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
