#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    
    queue<int> arr;
    for (int i = 1; i <= n; i++) arr.push(i);
    
    cout << "<";
    while (!arr.empty()) {
        for (int i = 1; i < k; i++) {
            arr.push(arr.front());
            arr.pop();
        }
        cout << arr.front();
        arr.pop();
        if (!arr.empty()) cout << ", ";
    }
    cout << ">";
}