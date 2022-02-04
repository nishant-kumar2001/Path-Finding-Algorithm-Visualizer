 #include<bits/stdc++.h>
#include<conio.h>;
#include<windows.h>;
using namespace std;
const int width=55,height=25;
int sx,sy,dx,dy;
bool game;
int vis[25][55];
int row[]={-1,1,0,0};
int col[]={0,0,-1,1};
queue<pair<pair<int,int>,int>> pq;
void setup()
{
    game=false;
    sx=20;sy=10;
    dx=24;dy=13;
    pq.push({{sx,sy},0});
    memset(vis,0,sizeof(vis));
    vis[sy][sx]=1;
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
    cout<<cx<<" "<<cy<<" "<<dist<<"\n";
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
}
