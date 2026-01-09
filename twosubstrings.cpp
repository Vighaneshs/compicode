#include <iostream>

using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    bool dp[2][n+2];

    dp[0][0] = false;
    dp[0][1] = false;

    dp[0][1] = false;
    dp[1][1] = false;
    // AB is 1
    // BA is 0
    for(int i = 1; i <n; i++){
        if(s[i-1] == 'A' && s[i] == 'B'){
            if(dp[0][i-1]){
                cout << "YES";
                return 0;
            }
            dp[1][i+1] = true;
            dp[0][i+1] = dp[0][i];
        } else if(s[i-1] == 'B' && s[i] == 'A'){
            if(dp[1][i-1]){
                cout << "YES";
                return 0;
            }
            dp[0][i+1] = true;
            dp[1][i+1] = dp[1][i];
        }else{
            dp[0][i+1] = dp[0][i];
            dp[1][i+1] = dp[1][i];
        }

    }
    cout << "NO";
    return 0;
}