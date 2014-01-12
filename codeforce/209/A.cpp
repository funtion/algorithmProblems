#include<cstdio>
#include<vector>
inline int min(int x,int y){
    return x<y?x:y;
}
struct pt{
    int x,y;
    pt(int _x,int _y){
        x=_x;
        y=_y;
    }
    pt(){
    }
};
int mp[60][60],cl[60][60];

int ans = 4;
int m,n;
std::vector<pt> gd;
void dfs(int deep,int ok){
    if(ok == m*n)
    {
        ans = min(ans,deep);
    }
    if(deep>4){
        return ;
    }
    if(ans == 2)
        return ;
    for(int i=0;i<gd.size();i++){
        pt tar = gd[i];
        std::vector<pt> v;
        int nn = 0;
        for(int i=0;i<tar.x;i++){
            for(int j=0;j<tar.y;j++){
                if(!cl[i][j]){
                    nn++;
                    cl[i][j] = 1;
                    v.push_back(pt(i,j));
                }
            }
        }
        if(nn>0)
            dfs(deep+1,ok+nn);
        while(!v.empty()){
            cl[v.back().x][v.back().y] = 0;
            v.pop_back();
        }
        nn = 0;

        for(int i=tar.x;i<n;i++){
            for(int j=0;j<tar.y;j++){
                if(!cl[i][j]){
                    nn++;
                    cl[i][j] = 1;
                    v.push_back(pt(i,j));
                }
            }
        }
        if(nn>0)
        dfs(deep+1,ok+nn);
        while(!v.empty()){
            cl[v.back().x][v.back().y] = 0;
            v.pop_back();
        }
        nn = 0;

        for(int i=0;i<tar.x;i++){
            for(int j=tar.y;j<m;j++){
                if(!cl[i][j]){
                    nn++;
                    cl[i][j] = 1;
                    v.push_back(pt(i,j));
                }
            }
        }
        if(nn>0)
        dfs(deep+1,ok+nn);
        while(!v.empty()){
            cl[v.back().x][v.back().y] = 0;
            v.pop_back();
        }
        nn = 0;

        for(int i=tar.x;i<n;i++){
            for(int j=tar.y;j<m;j++){
                if(!cl[i][j]){
                    nn++;
                    cl[i][j] = 1;
                    v.push_back(pt(i,j));
                }
            }
        }
        if(nn>0)
            dfs(deep+1,ok+nn);
        while(!v.empty()){
            cl[v.back().x][v.back().y] = 0;
            v.pop_back();
        }
        nn = 0;
    }

}
int main(){

    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&mp[i][j]);
            if(mp[i][j])
                gd.push_back(pt(i,j));
        }
    }

    int ans = 4;
    for(int i=1;i<n-1;i++){
        if(mp[i][0]){
            if(mp[i][m-1]||mp[i-1][0]||mp[i-1][m-1]||mp[i+1][m-1]||mp[i+1][0]){
                ans = 2;
            }else{
                int k = 0;
                for(int j=0;j<n;j++){
                    if(j==i)continue;
                }

            }
        }else if(mp[i][m-1]){
            if(mp[i][0]||mp[i-1][0]||mp[i-1][m-1]||mp[i+1][m-1]||mp[i+1][0]){
                ans = 2;
            }
        }
    }
    printf("%d\n",ans);
}

