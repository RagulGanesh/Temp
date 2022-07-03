#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int B[b.length() + 1][a.length() + 1];
    for (int i = 0; i < b.length() + 1; i++)
    {
        for (int j = 0; j < a.length() + 1; j++)
        {
            B[i][j] = 0;
        }
    }
    for (int i = 1; i <= b.length(); i++)
    {
        for (int j = 1; j <= a.length(); j++)
        {
            if (a[j - 1] == '\0' || b[i - 1] == '\0')
            {
                continue;
            }
            else if (a[j - 1] == b[i - 1])
            {
                B[i][j] = 1 + B[i - 1][j - 1];
            }
            else
            {
                B[i][j] = max(B[i - 1][j], B[i][j - 1]);
            }
        }
    }
    for (int i = 0; i <= b.length(); i++)
    {
        for (int j = 0; j <= a.length(); j++)
        {
            cout << B[i][j] << " ";
        }
        cout << "\n";
    }

    int x=b.length(),y=a.length();
    string c;
    while(x>0&&y>0){
        if(a[y-1]==b[x-1]){
            c+=b[x-1];
            x--;
            y--;
        }
        else if(B[x - 1][y] > B[x][y - 1]){
            x--;
        }
        else{
            y--;
        }
    }
    cout<<c;
    return 0;
}