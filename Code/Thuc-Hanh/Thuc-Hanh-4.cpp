#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, w;
    cout << "Moi nhap so luong vat pham: ";
    cin >> n;
    cout << "Moi nhap trong luong toi da cua balo: ";
    cin >> w;

    int khoiluong[n + 1], giatri[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cout << "=======================\n";
        cout << "Trong luong cua vat " << i << ": ";
        cin >> khoiluong[i];
        cout << "Gia tri cua vat " << i << ": ";
        cin >> giatri[i];
    }

    int dp[w + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = w; j >= khoiluong[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - khoiluong[i]] + giatri[i]);
        }
    }

    cout << "Gia tri lon nhat co the dat vao balo la: " << dp[w] << endl;

    return 0;
}

/*
6
11
4 7
3 5
4 8
2 3
2 4
5 9

output: 21
*/
