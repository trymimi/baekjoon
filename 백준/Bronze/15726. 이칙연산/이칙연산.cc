#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    double a, b, c;
    cin >> a >> b >> c;
    
    cout << (int)max(a * b / c, a / b * c);

    return 0;
}