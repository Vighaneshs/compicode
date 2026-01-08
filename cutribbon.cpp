#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int dp[n+1];
    vector<bool> dp2(n+1, false);
    dp2[0] = true;
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        int p1 = 0, p2 = 0, p3 = 0;
        if(i-a >= 0 && dp2[i-a]) p1 = 1 + dp[i-a];
        if(i-b >= 0 && dp2[i-b]) p2 = 1 + dp[i-b];
        if(i-c >= 0 && dp2[i-c]) p3 = 1 + dp[i-c];
        dp[i] = max(p1, max(p2, p3));
        if(dp[i] > 0) dp2[i] = true;  
    }   
    cout << dp[n];
    return 0;
}

