#include <iostream>
#include <cstring>
using namespace std;

const int N = 110;

int n;
int s[N][N];  // 二维前缀和数组

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
        }
    }
    int ans = -1e9;
    for (int i = 1; i <= n; i++) {  // 枚举矩形左上角的位置
        for (int j = 1; j <= n; j++) {
            for (int k = i; k <= n; k++) {  // 枚举矩形右下角的位置
                for (int l = j; l <= n; l++) {
                    int sum = s[k][l] - s[k][j - 1] - s[i - 1][l] + s[i - 1][j - 1];  // 子矩形的和
                    ans = max(ans, sum);  // 更新最大值
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}