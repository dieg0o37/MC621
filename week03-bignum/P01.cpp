#include <bits/stdc++.h>
// Using std namespace for clarity in this self-contained file
using namespace std;

// Using a constant for max digits is good practice
const int MAX_DIGITS = 5000;


enum Sign {
    PLUS = 1,
    MINUS = -1
};

/*
TODO from original file:
SOMA - FIXED
SUBTRACAO - FIXED
MULTIPLICACAO - FIXED
DIVISAO - FIXED
XOR - Not implemented
CONVERSAO DE BASE - Added string/ll conversions
MODULO - Not implemented
*/

struct bignum {
    // --- Data Members ---
    // Using vector<char> for safety and proper memory management.
    // Each char stores a single digit (0-9).
    vector<char> num;
    int signbit;
    int lastdigit; // Index of the most significant digit

    // --- Constructor ---
    bignum() {
        num.assign(MAX_DIGITS, 0); // Allocate and zero-out the vector
        signbit = PLUS;
        lastdigit = 0;
    }

    // --- Utility Functions ---
    // (Moved from global scope into the struct for better organization)

    /// @brief Trims leading zeros (e.g., 00123 -> 123)
    void zero_justify() {
        while (lastdigit > 0 && num[lastdigit] == 0) {
            lastdigit--;
        }
        // A number that is just 0 should have PLUS sign
        if (lastdigit == 0 && num[0] == 0) {
            signbit = PLUS;
        }
    }
};

// --- Forward Declarations ---
void big_subtract(bignum* n1, bignum* n2, bignum* result);
int big_compare(bignum* n1, bignum* n2);

// --- Conversion Functions ---

/// @brief Converts a long long to a bignum
void ll_to_bignum(long long s, bignum *n) {
    if (s == 0) {
        n->lastdigit = 0;
        n->num[0] = 0;
        n->signbit = PLUS;
        return;
    }

    n->signbit = (s >= 0) ? PLUS : MINUS;
    
    // Use fill on the vector directly
    fill(n->num.begin(), n->num.end(), 0);
    n->lastdigit = -1;

    long long t = abs(s);
    while (t > 0) {
        n->lastdigit++;
        n->num[n->lastdigit] = t % 10;
        t /= 10;
    }
}

/// @brief Converts a string to a bignum
void string_to_bignum(const string& s, bignum* n) {
    if (s.empty() || (s.length() == 1 && s[0] == '0')) {
        ll_to_bignum(0, n);
        return;
    }

    int start = 0;
    if (s[0] == '-') {
        n->signbit = MINUS;
        start = 1;
    } else if (s[0] == '+') {
        n->signbit = PLUS;
        start = 1;
    } else {
        n->signbit = PLUS;
    }

    fill(n->num.begin(), n->num.end(), 0);
    n->lastdigit = -1;

    for (int i = s.length() - 1; i >= start; i--) {
        n->lastdigit++;
        n->num[n->lastdigit] = s[i] - '0';
    }
    n->zero_justify();
}


/// @brief Converts a bignum to a string for printing
string bignum_to_string(bignum* n) {
    if (n->lastdigit == 0 && n->num[0] == 0) {
        return "0";
    }

    string s = "";
    if (n->signbit == MINUS) {
        s += "-";
    }
    for (int i = n->lastdigit; i >= 0; i--) {
        s += to_string(n->num[i]);
    }
    return s;
}

// Overload << operator for easy printing
ostream& operator<<(ostream& os, bignum* n) {
    os << bignum_to_string(n);
    return os;
}


// --- Core Logic Functions ---

/// @return 1 if n1 > n2, -1 if n2 > n1, and 0 if n1 == n2
int big_compare(bignum* n1, bignum* n2) {
    if (n1->signbit == PLUS && n2->signbit == MINUS) return 1;
    if (n1->signbit == MINUS && n2->signbit == PLUS) return -1;

    // If signs are the same, comparison depends on the sign
    int sign_factor = (n1->signbit == PLUS) ? 1 : -1;

    if (n1->lastdigit > n2->lastdigit) return 1 * sign_factor;
    if (n2->lastdigit > n1->lastdigit) return -1 * sign_factor;

    for (int i = n1->lastdigit; i >= 0; i--) {
        if (n1->num[i] > n2->num[i]) return 1 * sign_factor;
        if (n1->num[i] < n2->num[i]) return -1 * sign_factor;
    }

    return 0; // Numbers are equal
}

/// @brief Adds two bignums: result = n1 + n2
void big_add(bignum* n1, bignum* n2, bignum* result) {
    // If signs are different, delegate to subtraction: a + (-b) = a - b
    if (n1->signbit != n2->signbit) {
        if (n1->signbit == MINUS) { // -a + b = b - a
            bignum temp_n1 = *n1;
            temp_n1.signbit = PLUS;
            big_subtract(n2, &temp_n1, result);
        } else { // a + (-b) = a - b
            bignum temp_n2 = *n2;
            temp_n2.signbit = PLUS;
            big_subtract(n1, &temp_n2, result);
        }
        return;
    }

    // Signs are the same
    result->signbit = n1->signbit;
    result->lastdigit = max(n1->lastdigit, n2->lastdigit) + 1;
    int carry = 0;

    for (int i = 0; i <= result->lastdigit; i++) {
        int sum = carry + n1->num[i] + n2->num[i];
        result->num[i] = sum % 10;
        carry = sum / 10;
    }
    result->zero_justify();
}


/// @brief Subtracts two bignums: result = n1 - n2
void big_subtract(bignum* n1, bignum* n2, bignum* result) {
    // If signs are different, delegate to addition: a - (-b) = a + b
    if (n1->signbit != n2->signbit) {
        bignum temp_n2 = *n2;
        temp_n2.signbit = n1->signbit; // Now signs are the same
        big_add(n1, &temp_n2, result);
        return;
    }
    
    // Create temporary positive versions for comparison
    bignum temp_n1 = *n1;
    temp_n1.signbit = PLUS;
    bignum temp_n2 = *n2;
    temp_n2.signbit = PLUS;

    // Determine which number is larger in magnitude
    if (big_compare(&temp_n1, &temp_n2) == -1) { // |n1| < |n2|
        big_subtract(n2, n1, result); // result = n2 - n1
        result->signbit = (n1->signbit == PLUS) ? MINUS : PLUS; // Invert the sign
        return;
    }

    // At this point, |n1| >= |n2| and they have the same original sign
    result->signbit = n1->signbit;
    result->lastdigit = n1->lastdigit;
    int borrow = 0;

    for (int i = 0; i <= n1->lastdigit; i++) {
        int v = (n1->num[i] - borrow - n2->num[i]);
        if (v < 0) {
            v += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result->num[i] = v;
    }
    result->zero_justify();
}

/// @brief Shifts digits to the left by d places (multiplies by 10^d)
void big_digit_shift(bignum *n, int d) {
    if (n->lastdigit == 0 && n->num[0] == 0) return;
    for (int i = n->lastdigit; i >= 0; i--) {
        n->num[i + d] = n->num[i];
    }
    for (int i = 0; i < d; i++) {
        n->num[i] = 0;
    }
    n->lastdigit += d;
}

/// @brief Multiplies two bignums: result = n1 * n2
/// This uses the standard grade-school multiplication algorithm.
void big_mult(bignum* n1, bignum* n2, bignum* result) {
    bignum temp_res;
    temp_res.signbit = n1->signbit * n2->signbit;

    for (int i = 0; i <= n1->lastdigit; i++) {
        int carry = 0;
        for (int j = 0; j <= n2->lastdigit; j++) {
            int product = n1->num[i] * n2->num[j] + temp_res.num[i + j] + carry;
            temp_res.num[i + j] = product % 10;
            carry = product / 10;
        }
        // Propagate the final carry
        int k = n2->lastdigit + 1;
        while(carry > 0) {
            int product = temp_res.num[i+k] + carry;
            temp_res.num[i+k] = product % 10;
            carry = product / 10;
            k++;
        }
    }
    temp_res.lastdigit = n1->lastdigit + n2->lastdigit + 1;
    temp_res.zero_justify();
    *result = temp_res;
}


void solve() {
    string line;
    bool first = false, sec = false, sum = false;
    bignum max;
    ll_to_bignum((long long)INT_MAX, &max);
    while (getline(cin, line, '\n'))  {
        if (line.empty()) {
            break;
        }
        stringstream ss(line);
        char op;
        string params[2];
        ss >> params[0];
        ss >> op;
        ss >> params[1];
        cout << params[0] << " " <<  op << " " << params[1] << "\n";
        bignum n1, n2, res;
        string_to_bignum(params[0], &n1);
        if (big_compare(&n1, &max) == 1) {
            cout << "first number too big" << "\n";
        }
        if (op == '+') {
            string_to_bignum(op + params[1], &n2);
            if (big_compare(&n2, &max) == 1) {
                cout << "second number too big" << "\n";
            }
            big_add(&n1, &n2, &res);
            if (big_compare(&res, &max) == 1){
                cout << "result too big" << "\n";
            }
        } else {
            string_to_bignum(params[1], &n2);
            if (big_compare(&n2, &max) == 1) {
                cout << "second number too big" << "\n";

            }
            big_mult(&n1, &n2, &res);
            if (big_compare(&res, &max) == 1){
                cout << "result too big" << "\n";
            }
        }
    }
    
    
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
