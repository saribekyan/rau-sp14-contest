#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define OK 0
#define PE 4
#define WA 5

void finish() {
    int c;
    while ((c = getchar()) != EOF) {}
    fclose(stdout);
}
int main(int argc, char * argv[]) {
    ifstream in(argv[1]);
    ofstream out(argv[2]);
    ifstream ans(argv[3]);
    int n, f;
    in >> n >> f;
    cout << n << ' ' << f << '\n';

    vector< pair<int, int> > vp;
    for (int i = 0; i < n; ++i) {
        int v, p;
        in >> v >> p;
        vp.push_back(make_pair(v, p));
    }
    in.close();

    string corr;
    ans >> corr;
    ans.close();

    int m = 100 + n / 5 + 1;
    while (m--) {
        string s;
        if (!(cin >> s)) {
            out << "PE\n";
            out.close();
            cerr << "The program never outputted YES or NO\n";
            return PE;
        }

        if (s == "YES" || s == "NO") {
            if (cin >> s) {
                out << "PE\n";
                finish();
                out.close();
                cerr << "YES/NO should be the last line of the program\n";
                return PE;
            }
            out << s << '\n';
            out.close();
            return (s == corr) ? OK : WA;
        }

        if (s != "OPEN") {
            out << "PE\n";
            out.close();
            finish();
            cerr << "Output can start only with YES/NO/OPEN\n";
            return PE;
        }

        string num;
        cin >> num;

        int x = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (!('0' <= num[i] && num[i] <= '9')) {
                out << "PE\n";
                out.close();
                finish();
                cerr << "Not a number\n";
                return PE;
            }

            x = x * 10 + num[i] - '0';
            if (x > n) {
                out << "PE\n";
                out.close();
                finish();
                cerr << "Box number is too large\n";
                return PE;
            }
        }
        if (x > n || x < 1) {
            out << "PE\n";
            out.close();
            finish();
            cerr << "Invalid box is too large or small\n";
            return PE;
        }

        --x;
        cout << vp[x].first << ' ' << vp[x].second << '\n';
    }
    finish();
    out << "PE\n";
    cerr << "Output is too long\n";
    out.close();
    return PE;
}

