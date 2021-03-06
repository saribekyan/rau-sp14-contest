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
    cout << n << ' ' << f << '\n' << flush;

    vector< pair<int, int> > vp;
    for (int i = 0; i < n; ++i) {
        int v, p;
        in >> v >> p;
        vp.push_back(make_pair(v, p - 1));
    }
    in.close();

    int m = 100 + n / 5 + 1;
    while (m--) {
        string s;
        if (!(cin >> s)) {
            out << "PE\n";
            out << "The program never outputted YES or NO\n";
            fclose(stdout);
            fclose(stdin);
            out.close();
            return PE;
        }

        if (s == "YES" || s == "NO") {
            if (cin >> s) {
                out << "PE\n";
                out << "YES/NO should be the last line of the program\n";
                out.close();
                fclose(stdout);
                fclose(stdin);
                return PE;
            }
            out << s << '\n';
            out.close();
            fclose(stdout);
            fclose(stdin);
            return OK;
        }

        if (s != "OPEN") {
            out << "PE\n";
            out << "Output can start only with YES/NO/OPEN\n";
            out.close();
            fclose(stdout);
            fclose(stdin);
            return PE;
        }

        string num;
        cin >> num;

        int x = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (!('0' <= num[i] && num[i] <= '9')) {
                out << "PE\n";
                out << "Not a number\n";
                out.close();
                fclose(stdout);
                fclose(stdin);
                return PE;
            }

            x = x * 10 + num[i] - '0';
            if (x > n) {
                out << "PE\n";
                out << "Box number is too large\n";
                out.close();
                fclose(stdout);
                fclose(stdin);
                return PE;
            }
        }
        if (x > n || x < 1) {
            out << "PE\n";
            out << "Invalid box is too large or small\n";
            out.close();
            fclose(stdout);
            fclose(stdin);
            return PE;
        }

        --x;
        cout << vp[x].first << ' ' << vp[x].second << '\n' << flush;
    }
    out << "PE\n";
    out << "Output is too long\n";
    out.close();
    fclose(stdout);
    fclose(stdin);
    return PE;
}

