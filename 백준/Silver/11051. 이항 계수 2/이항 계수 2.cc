#include <iostream>
using namespace std;

#define MAX 1001
int comb[MAX][MAX];

void build_pascal() {
    for (int i = 0; i < MAX; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % 10007;
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    build_pascal();
    cout << comb[n][k];
}