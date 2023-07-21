#include <bits/stdc++.h>
using namespace std;
#define int long long

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int mod =1e9+7;


int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int vis[101][11];
int grid[101][11];
int n,k;
int cmp_size =0;

void dfs_size(int x, int y, int color){
    vis[x][y] = 1;
    cmp_size++;
    for(int i=0;i<4;i++){
        int x1 =x+dx[i], y1=y+dy[i];
        if(x1>=0 && x1<n && y1>=0 && y1<10 && !vis[x1][y1] && grid[x1][y1] == color){
            dfs_size(x1,y1, grid[x1][y1]);
        }
    }
}

void dfs_delete(int x, int y,int color){
    grid[x][y] = 0;
    
    for(int i=0;i<4;i++){
        int x1 =x+dx[i], y1 = y+dy[i];
        if(x1>=0 && x1<n && y1>=0 && y1<10 && grid[x1][y1] == color){
           dfs_delete(x1,y1,color); 
        }
    }
}

void gravity(){
    
    for(int j=0;j<10;j++){
   
       int p= n-1;
       for(int i=n-1;i>=0;i--){
          if(grid[i][j] != 0){
              swap(grid[i][j] , grid[p][j]);
              p--;
          }
       }
    }    
}

signed main(){
   
   IOS 
  
   cin>>n>>k;
   char ch;
   string s;
   for(int i=0;i<n;i++){
       for(int j=0;j<10;j++){
           cin>>ch;
           grid[i][j] =ch - '0';
       }
   }
   
   int flag  =1;
   
   while(flag){
       flag =0;
       memset(vis,0,sizeof(vis));
       for(int i=0;i<n;i++){
           for(int j=0;j<10;j++){
               if(vis[i][j] == 0 && grid[i][j] !=0){
                   cmp_size = 0;
                   dfs_size(i,j,grid[i][j]);
                   if(cmp_size>=k){
                       dfs_delete(i,j,grid[i][j]);
                       flag=1;
                   }
               }
           }
       }
       gravity();
   }
   
   for(int i=0;i<n;i++){
       for(int j=0;j<10;j++){
           cout << grid[i][j];
       }
       cout << endl;
   }
   
   
  
   return 0;
    
}
