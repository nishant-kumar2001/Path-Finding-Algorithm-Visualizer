 #include<bits/stdc++.h>
#include<conio.h>;
#include<windows.h>;
using namespace std;
const int width=55,height=25;
int sx,sy,dx,dy;
bool game;
int dp[26][56];
int vis[25][55];
int row[]={-1,1,0,0};
int col[]={0,0,-1,1};
queue<pair<pair<int,int>,int>> pq;
void setup()
{
    game=false;
    cout<<"Enter starting position within range[55,25]\n";
    cin>>sx>>sy;
    cout<<"Enter ending position within range[55,25]\n";
    cin>>dx>>dy;
    pq.push({{sx,sy},0});
    memset(vis,0,sizeof(vis));
    vis[sy][sx]=1;
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<56;j++)
            dp[i][j]=INT_MAX;
    }
    dp[sy][sx]=0;
}
void draw()
{
    system("cls");
    for(int i=0;i<=width;i++)
    cout<<"#";
    cout<<"\n";
    for(int i=1;i<height;i++)
    {
        for(int j=0;j<=width;j++)
        {
            if(j==0)
            cout<<"#";
            else if(i==sy&&j==sx)
            cout<<"S";
            else if(i==dy&&j==dx)
            cout<<"F";
            else if(j==width)
            cout<<"#";
            else
            {
                if(vis[i][j]==1)
                    cout<<".";
                else
                    cout<<" ";
            }
        }
        cout<<"\n";
    }
    for(int i=0;i<=width;i++)
    cout<<"#";
    cout<<"\n";
}
void logic()
{
    int cx,cy,dist;
    cx=pq.front().first.first;
    cy=pq.front().first.second;
    dist=pq.front().second;
    if(cx==dx&&cy==dy)
    {
        game=true;
        return;
    }
    pq.pop();
    for(int i=0;i<4;i++)
    {
        if((cx+row[i]>0)&&(cx+row[i]<width)&&(cy+col[i]>0)&&(cy+col[i]<height)&&(!vis[cy+col[i]][cx+row[i]]))
        {
            vis[cy+col[i]][cx+row[i]]=1;
            pq.push({{cx+row[i],cy+col[i]},dist+1});
            dp[cy+col[i]][cx+row[i]]=dist+1;
        }
    }
}
int main()
{
    setup();
    while(!game)
    {
        draw();
        logic();
    }
    memset(vis,0,sizeof(vis));
    queue<pair<int,int>> qu;
    qu.push({dx,dy});
    int k=dp[dy][dx];
    while(!qu.empty())
    {
        int cx,cy;
        cx=qu.front().first;
        cy=qu.front().second;
        if(cx==sx&&cy==sy)
            break;
        qu.pop();
        for(int i=0;i<4;i++)
        {
            if((cx+row[i]>0)&&(cx+row[i]<width)&&(cy+col[i]>0)&&(cy+col[i]<height)&&(!vis[cy+col[i]][cx+row[i]]))
            {
                if(dp[cy+col[i]][cx+row[i]]==k-1)
                {
                    vis[cy+col[i]][cx+row[i]]=1;
                    qu.push({cx+row[i],cy+col[i]});
                    k--;
                    break;
                }
            }
        }
    }
    draw();
}
