#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string digits;
    cin >> digits;
	digits = "0" + digits;	
	int i;
	for (i = digits.size() - 2; i >= 0 && digits[i] == '1'; digits[i--]='0');		
	digits[i] = digits[i + 1] = '1';
    cout << digits << endl;
    return 0;
}

