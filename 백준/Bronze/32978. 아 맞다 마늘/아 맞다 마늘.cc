#include <iostream>
#include <set>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    
    string ingredient[1001];
    for (int i = 0; i < n; i++) cin >> ingredient[i];

    set<string> diff;
    for (int i = 1; i < n; i++) {
        string s; cin >> s;
        diff.insert(s);
    }

    for (int i = 0; i < n; i++) {
        if (!diff.count(ingredient[i])) {
            cout << ingredient[i];
            break;
        }
    }
}