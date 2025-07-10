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
    
    int stack = 0;
    int result[5001];
    while (!arr.empty()) {
        stack++;
        int a = arr.front();
        arr.pop();
        if (stack % k == 0) result[stack / k] = a;
        else arr.push(a);
    }
    
    cout << "<";
    for (int i = 1; i < n; i++) cout << result[i] << ", ";
    cout << result[n] << ">";
}