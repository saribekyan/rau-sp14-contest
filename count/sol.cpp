#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Normalizes the input. See readme.txt
void normalize(string &digits) {
    int n = digits.size();
    digits = "0" + digits;
    if (digits.size() > 2 && digits[digits.size() - 3] == '1' && digits[digits.size() - 2] == '0') {
        digits[digits.size() - 3] = '0';
        digits[digits.size() - 2] = '1';
    }
    digits[digits.size() - 1] = '0';
    for (int i = 2; i < digits.size(); ++i)
        if (digits[i] == '1' && digits[i - 1] == '1') {
            digits[i - 2] = '1';
            digits[i] = digits[i - 1] = '0';
        }
    int p;
    for (p = 0; p < digits.size() && digits[p] == '0'; ++p);
    if (p == digits.size())
        digits = "0";
    else
        digits = digits.substr(p);
}

long long get_value(string digits) {
     vector<long long> f;
     f.push_back(0);
     f.push_back(1);
     for (int i = 2; i <= 80; ++i)
         f.push_back(f[i-1] + f[i-2]);
     long long ret = 0;
     for (int i = 0; i < digits.size(); ++i)
         if (digits[digits.size() - i - 1] == '1')
             ret += f[i];
     return ret;
}
int main() {
    string digits;
    cin >> digits;
    //cout << get_value(digits) << '\n';
    normalize(digits);

    if (digits.size() == 1) {
        cout << "10\n";
        return 0;
    }
    if (digits.size() == 2) {
        cout << "1000\n";
        return 0;
    }
    digits[digits.size() - 3] = '1';
    normalize(digits);
    //cout << get_value(digits) << '\n';
    cout << digits << '\n';
    return 0;
}

