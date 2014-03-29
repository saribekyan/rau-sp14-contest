#include <fstream>
#include <string>
#include "../testlib.h"
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
    for (int iter = 0; iter < digits.size(); ++iter) {
        for (int i = 2; i < digits.size(); ++i)
            if (digits[i] == '1' && digits[i - 1] == '1') {
                digits[i - 2] = '1';
                digits[i] = digits[i - 1] = '0';
            }
    }
    int p;
    for (p = 0; p < digits.size() && digits[p] == '0'; ++p);
    if (p == digits.size())
        digits = "0";
    else
        digits = digits.substr(p);
}
int main(int argc, char * argv[]) {
    setName("compares to Fibonacci representations");
    registerTestlibCmd(argc, argv);

    string rec = ouf.readString();
    if (rec.size() > 2000) {
        quitf(_pe, "output too long");
    }
    for (int i = 0; i < rec.size(); ++i)
        if (rec[i] != '0' && rec[i] != '1')
            quitf(_pe, "output contains a non-valid character: %c", rec[i]);
    string exp = ans.readString();
    normalize(rec);

    if (exp != rec)
        quitf(_wa, "expected (sample): %s", exp.c_str());
    quitf(_ok, "answer: %s", exp.c_str());
    return 0;
}

