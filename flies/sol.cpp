/*
 ans = (n+k-1)!/n!*(k-1)! = (n+1)*(n+2)*...*(n+k-1)! / 1*2*...*(k-1)!
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
     
    int n, k;

    cin >> n>> k;
        
    if (k == 1)  
    {
        cout << "1"<<endl;
        return 0;
    }

    vector<int> a(k-1), b(k-1);

    for (int i = 0; i < k - 1; ++i) 
    {
        a[i] = n + i + 1;
        b[i] = i + 1;
    }

    int p[]={2, 3, 5, 7, 11, 13, 17, 19, 23};
    int m =  sizeof(p)/sizeof(int);


    for (int j = 0; j < m; ++j)
    {            
        int u = 0, v = 0;      
        do
        {
            for (; u < k - 1 && a[u] % p[j] != 0; ++u);
            for (; v < k - 1 && b[v] % p[j] != 0; ++v);

            if (u < k - 1 && v < k - 1)
            {
                a[u] /= p[j];
                b[v] /= p[j];
            }
        }        
        while (u < k - 1 && v < k - 1);        
        
    }

    long long ans = 1;

    for (int i = 0; i < k - 1; ++i)  ans *= a[i];
    for (int i = 0; i < k - 1; ++i)  ans /= b[i];

    cout << ans<< endl;
    return 0;

}

