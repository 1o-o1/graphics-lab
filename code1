#include<bits/stdc++.h>
#define b1 first.first
#define b1 first.second
#define b3 second.first
#define b4 second.second
#define s second
#define f first
#define pb push_back

using namespace std;
typedef long long int ll;
typedef pair<double,double> pd;
typedef pair<bool,bool> pb;
typedef pair<pb,pb> pbb;
const int mx=1e6;


int xmin,xmax,ymin,ymax;
vector<vector<pd>> v,ans;
vector<vector<pbb>> bit;
/**
void bit_cal()
{
    for(i=0; i<li.size(); i++)
    {
        if(li[i].y1>ymax)
            bit[i][0]=1;
        if(li[i].y1<ymin)
            bit[i][1]=1;
        if(li[i].x1>xmax)
            bit[i][2]=1;
        if(li[i].x1<xmin)
            bit[i][3]=1;

        if(li[i].y2>ymax)
            bit[i][4]=1;
        if(li[i].y2<ymin)
            bit[i][5]=1;
        if(li[i].x2>xmax)
            bit[i][6]=1;
        if(li[i].x2<xmin)
            bit[i][7]=1;
    }
}
//int clipable(int i)
{
    int sum=0,andsum=0;
    for(j=0; j<4; j++)
    {
        sum+=(bit[i][j]+bit[i][j+4]);
        andsum+=(bit[i][j]&bit[i][j+4]);
    }
    if(sum==0)
        return 0;
    else if(andsum==0)
        return 1;
    else
        return -1;
}
void cohen(void)
{

}**/
int main()
{
    int i,j,n,l;

    cout<<"Enter clip window\n"; ///"change it"
    cin>>xmin>>xmax>>ymin>>ymax;
    cout<<"Enter number of shape\n";///"change it"
    cin>>n;

    for (i=0; i<n; i++)
    {
        cout<<"enter number of vertex\n";
        cin>>l;
        pd point;
        vector<pd> shape;
        for(j=0;j<l;j++)
        {cin>>point.f>>point.s;
        shape.pb(point);}
        v.pb(shape);
    }
    for(i=0; v.size(); i++)
    {
        for(j=0;j<v[i].size();j++)
            cout<<v[i][j].f<<" "<<v[i][j].s<<" : ";
            cout<<endl;
    }

    return 0;
}
