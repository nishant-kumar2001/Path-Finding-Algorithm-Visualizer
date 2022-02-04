#include<bits/stdc++.h>
#include<windows.h>;
using namespace std;
const int width=60,height=26;
int sx,sy,dx,dy;
bool game;
int dp[height+1][width+1];
int vis[height][width];
int arr[height+1][width+1];
int row[]={-1,1,0,0};
int col[]={0,0,-1,1};
queue<pair<pair<int,int>,int>> pq;
void setup()
{
    game=false;
    while(1)
    {
        cout<<"Enter starting position within range["<<width<<","<<height<<"]\n";
        cin>>sx>>sy;
        if(arr[sy][sx]==0)
            cout<<"Wall is on the given position\n";
        else
            break;
    }
    while(1)
    {
        cout<<"Enter ending position within range["<<width<<","<<height<<"]\n";
        cin>>dx>>dy;
        if(arr[dy][dx]==0)
            cout<<"Wall is on the given position\n";
        else
            break;
    }
    pq.push({{sx,sy},0});
    memset(vis,0,sizeof(vis));
    vis[sy][sx]=1;
    for(int i=0;i<=height;i++)
    {
        for(int j=0;j<=width;j++)
            dp[i][j]=INT_MAX;
    }
    dp[sy][sx]=0;
}
void wall()
{
    memset(arr,-1,sizeof(arr));
    for(int i=1,j=width-5;i<height-2&&j>5;i++,j--)
        arr[i][j]=0;
    for(int i=5,j=3;i<height-3&&j<width-8;i++,j++)
        arr[i][j]=0;
    for(int j=6;j<(width)/3;j++)
        arr[height-7][j]=0;
    for(int j=3;j<width/2;j++)
        arr[height/4][j]=0;
    for(int i=4;i<height-8;i++)
    {
        arr[i][6]=0;
        arr[i+4][width-6]=0;
    }
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
                if(arr[i][j]==0)
                    cout<<"|";
                else if(vis[i][j]==1)
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
    int k=pq.front().second;
    while(1)
    {
    int cx,cy,dist;
    cx=pq.front().first.first;
    cy=pq.front().first.second;
    dist=pq.front().second;
    if(dist>k)
        return ;
    if(cx==dx&&cy==dy)
    {
        game=true;
        return;
    }
    pq.pop();
    for(int i=0;i<4;i++)
    {
        if((cx+row[i]>0)&&(cx+row[i]<width)&&(cy+col[i]>0)&&(cy+col[i]<height)&&(!vis[cy+col[i]][cx+row[i]])&&(arr[cy+col[i]][cx+row[i]]==-1))
        {
            vis[cy+col[i]][cx+row[i]]=1;
            pq.push({{cx+row[i],cy+col[i]},dist+1});
            dp[cy+col[i]][cx+row[i]]=dist+1;
        }
    }
    }
}
int main()
{
    wall();
    setup();
    while(!game)
    {
        draw();
        logic();
        if(pq.size()==0)
            break;
    }
    memset(vis,0,sizeof(vis));
    queue<pair<int,int>> qu;
    qu.push({dx,dy});
    int k=dp[dy][dx];
    if(k==INT_MAX)
    {
        cout<<"\nNOT POSSIBLE TO REACH ENDING POSITION NOOB\n";
        return 0;
    }
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
