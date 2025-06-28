#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    string file, result;
    cin >> result;
    int len = result.length();
    while (--n) {
        cin >> file;
        for (int i = 0; i < len; i++) {
            if (result[i] != file[i]) result[i] = '?';
        }
    }

    cout << result;
}