#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string a, b, result;
    cin >> a >> b;

    int lena = a.length();
    int lenb = b.length();
    int carry = 0;
    
    while (true) {
        lena--;
        lenb--;
        if (lena < 0 && lenb < 0) {
            if (carry) result += '1';
            break;
        }

        int inta = lena >= 0 ? (int)a[lena] - '0' : 0;
        int intb = lenb >= 0 ? (int)b[lenb] - '0' : 0;
        int temp = inta + intb + carry;
        result += (char)(temp % 10 + '0');
        if (temp / 10) carry = 1;
        else carry = 0;
    }

    for (int i = result.length() - 1; i >= 0; i--) cout << result[i];
    return 0;
}