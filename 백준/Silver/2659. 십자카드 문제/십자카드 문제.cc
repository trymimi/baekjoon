#include <iostream>
#include <set>
using namespace std;

int FindMin(int arr[4]) {
    int num = 10000;
    for (int i = 0; i < 4; i++) {
        int temp = arr[i] * 1000 + arr[(i + 1) % 4] * 100 + arr[(i + 2) % 4] * 10 + arr[(i + 3) % 4];
        num = min(num, temp);
    }
    return num;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int a[4];
    for (int i = 0; i < 4; i++) cin >> a[i];

    int num = FindMin(a);

    set<int> set;
    for (int n1 = 1; n1 <= 9; n1++) {
        for (int n2 = 1; n2 <= 9; n2++) {
            for (int n3 = 1; n3 <= 9; n3++) {
                for (int n4 = 1; n4 <= 9; n4++) {
                    int arr[4] = { n1, n2, n3, n4 };
                    int temp = FindMin(arr);
                    set.insert(temp);
                }
            }
        }
    }

    cout << distance(set.begin(), set.find(num)) + 1;
}