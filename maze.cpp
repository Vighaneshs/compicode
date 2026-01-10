#include <iostream>
#include <vector>

using namespace std;

int target;
void dfs(vector<vector<char>> &g, int i, int j){
    if(i < 0 || j < 0 || i >= g.size() || j >= g[0].size()) return;
    if(g[i][j] != '.') return;
    if(target <= 0) return;
    target--;

    g[i][j] = 'A';
    if(target <= 0) return;
    dfs(g,  i-1, j);
    dfs(g, i+1, j);
    dfs(g, i, j-1);
    dfs(g, i, j+1);
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> g(n, vector<char>(m));
    int es = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
            if(g[i][j] == '.') {
                es++;
            }
        }
    }
    target = es - k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == '.')
            {
                dfs(g, i, j);
                break;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == 'A') g[i][j] = '.';
            else if(g[i][j] == '.') g[i][j] = 'X';
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << g[i][j];
        }
        cout << endl;
    }
    

    return 0;
}