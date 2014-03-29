#include <string>
#include "../testlib.h"
using namespace std;

int main(int argc, char * argv[]) {
    setName("compares log of interactor to actual output");
    registerTestlibCmd(argc, argv);

    string rec = ouf.readString();
    string exp = ans.readString();

    if (exp != rec)
        quitf(_wa, "expected: %s, received: %s", exp.c_str(), rec.c_str());
    quitf(_ok, "answer: %s", exp.c_str());
    return 0;
}

