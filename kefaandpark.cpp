#include <iostream>
#include <vector>
using namespace std;


void dfs(vector<vector<int>> &adj, int m, int index, int cc, int*g, int &tc){
    int vis = 0;
    int nc = g[index];
    g[index] = -1;
    for(int i = 0; i < adj[index].size(); i++){
        int neigh = adj[index][i];
        if(g[neigh] >= 0 && cc + nc <= m){
            if(nc == 1){
                dfs(adj, m, neigh, cc + nc, g, tc);
                vis++;
            } else {
                dfs(adj, m, neigh, 0, g, tc);
                vis++;
            }
        } 
    }
    if(vis == 0 && cc + nc <= m) tc++;
}

int main(){
    int n, m;
    cin >> n >> m;
    int g[n];
    for(int i = 0; i < n; i++) cin >> g[i];

    vector<vector<int>> adj(n, vector<int>());

    for(int i = 0 ; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }


    int tc = 0;
    dfs(adj, m, 0, 0, g, tc);
    cout << tc;

    return 0;
}