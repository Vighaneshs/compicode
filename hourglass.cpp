#include <iostream>
using namespace std;
int main(){
    int t;
    cin >>t;
    for(int i = 0; i < t; i++){
        int s, k, m;
        cin >> s >> k >> m;

        if(k < s){
            int t = m/k;
            int t1 = m%k;
            if(t%2 == 0){
                cout << s - t1 << endl;
            }
            else{
                if( t1 < k )
                    cout << k - t1 << endl;
                else
                    cout << 0 << endl;
            }
        
        }
        else{ 
            int t = m%k;
            if(t < s) cout << s - t << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}