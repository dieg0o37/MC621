#include <bits/stdc++.h>

int string_align(const std::string& s1, const std::string& s2, int match, int mismatch, int gap) {
    int n = s1.length();
    int m = s2.length();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i * gap;
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = j * gap;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int score = (s1[i - 1] == s2[j - 1]) ? match : mismatch;
            int match_mismatch = dp[i - 1][j - 1] + score;
            int del = dp[i - 1][j] + gap;
            int ins = dp[i][j - 1] + gap;
            dp[i][j] = std::max({match_mismatch, del, ins});
        }
    }
    return dp[n][m];
}

int LCS(const std::string& s1, const std::string& s2) {
    int n = s1.length();
    int m = s2.length();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int levenshtein(const std::string& s1, const std::string& s2) {
    int n = s1.length();
    int m = s2.length();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            int substitution = dp[i - 1][j - 1] + cost;
            int deletion = dp[i - 1][j] + 1;
            int insertion = dp[i][j - 1] + 1;
            dp[i][j] = std::min({substitution, deletion, insertion});
        }
    }
    return dp[n][m];
}

int LPS(const std::string& s) {
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());
    return LCS(s, reversed_s);
}

int LPS_dp(const std::string& s) {
    int n = s.length();
    if (n == 0) return 0;
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = 2 + (len == 2 ? 0 : dp[i + 1][j - 1]);
            } else {
                dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][n - 1];
}