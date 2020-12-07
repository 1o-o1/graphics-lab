#include<bits/stdc++.h>
#define b1 first.first
#define b2 first.second
#define b3 second.first
#define b4 second.second
#define s second
#define f first
#define pbk push_back

using namespace std;
typedef long long int ll;
typedef pair<double,double> pd;
typedef pair<bool,bool> pb;
typedef pair<pb,pb> pbb;
const int mx=1e6;


double xmin,xmax,ymin,ymax;
vector<vector<pd>> v,ans;
vector<vector<pbb>> bit;

pbb bit_cal(int x,int y)
{
     pbb tmp;
     tmp.b1=0;tmp.b2=0;tmp.b3=0;tmp.b4=0;
        if(y>ymax)
            tmp.b1=1;
        if(y<ymin)
            tmp.b2=1;
        if(x>xmax)
            tmp.b3=1;
        if(x<xmin)
            tmp.b4=1;
            return tmp;
}

int clipable(int i)
{
    int sum=0,andsum=0;

        sum+=(bit[i][0].b1+bit[i][1].b1);
        andsum+=(bit[i][0].b1&bit[i][1].b1);

        sum+=(bit[i][0].b2+bit[i][1].b2);
        andsum+=(bit[i][0].b2&bit[i][1].b2);

        sum+=(bit[i][0].b3+bit[i][1].b3);
        andsum+=(bit[i][0].b3&bit[i][1].b3);

        sum+=(bit[i][0].b4+bit[i][1].b4);
        andsum+=(bit[i][0].b4&bit[i][1].b4);
    if(sum==0)
        return 0;
    else if(andsum==0)
        return 1;
    else
        return -1;
}
void bit_init(void)
{
    int i,j;
for(i=0;i<v.size();i++)
{
    vector<pbb> bit2;
    for(j=0;j<v[i].size();j++)
    {
        pbb tmp;
        tmp=bit_cal(v[i][j].f,v[i][j].s);
        bit2.pbk(tmp);
    }
    bit.pbk(bit2);
}

}
void cohen(void)
{
    bit_init();
    int i,j;
    for(i=0;i<v.size();i++)
    {
        if(clipable(i)==0)
            ans.push_back(v[i]);
        else if(clipable(i)==1)
        {
            double y1=v[i][0].s,y2=v[i][1].s;
            double x1=v[i][0].f,x2=v[i][1].f;
            double dy=y1-y2,dx=x1-x2;
            double m=dy/dx;
            double c=y1-m*x1;
            for(j=0;j<v[i].size();j++)
            {
                int f=0;
                if(bit[i][j].b1)
                   {v[i][j].s=ymax;f=1;}
                if(bit[i][j].b2)
                    {v[i][j].s=ymin;f=1;}
                if(f==1&&dy!=0&&dx!=0)
                    v[i][j].f=(v[i][j].s-c)/m;
                else{
                if(bit[i][j].b3)
                    {v[i][j].f=xmax;f=2;}
                if(bit[i][j].b4)
                   {v[i][j].f=xmin;f=2;}
                if(f==2&&dy!=0&&dx!=0)
                    v[i][j].s=m*v[i][j].f+c;}


            }
            ans.push_back(v[i]);
        }
    }
}

void liang(void){

    int i,j;
    for(i=0;i<v.size();i++)
    {

            double y1=v[i][0].s,y2=v[i][1].s;
            double x1=v[i][0].f,x2=v[i][1].f;
            double dy=y2-y1,dx=x2-x1;
            double p[4]={-1*dx,dx,-1*dy,dy},r[4],u1=0,u2=1;
            double q[4]={x1-xmin,xmax-x1,y1-ymin,ymax-y1};
             bool f=0;
            for(j=0;j<4;j++)
             {
                 //cout<<p[j]<<" "<<q[j]<<endl;
                 if(p[j]==0&&q[j]<0)
                 {
                     f=1;break;
                 }
                 else if(p[j]<0)
                 {
                     r[j]=q[j]/p[j];
                     u1=max(u1,r[j]);
                 }
                 else if(p[j]>0)
                 {
                     r[j]=q[j]/p[j];
                     u2=min(u2,r[j]);
                 }

             }
             if(u1<=u2&&!f)
             {
                 v[i][0].f=x1+dx*u1;
                 v[i][0].s=y1+dy*u1;
                 v[i][1].f=x1+dx*u2;
                 v[i][1].s=y1+dy*u2;
                 ans.push_back(v[i]);
             }
        }
}



int main()
{
    int i,j,n,l;

    cout<<"Enter clip window xmin ymin xmax ymax\n"; ///"change it"
    cin>>xmin>>ymin>>xmax>>ymax;

    cout<<"Enter number of shape\n";///"change it"
    cin>>n;

    for (i=0; i<n; i++)
    {
        cout<<"enter number of vertex and them n x y\n";
        cin>>l;
        pd point;
        vector<pd> shape;
        for(j=0;j<l;j++)
        {cin>>point.f>>point.s;
        shape.pbk(point);}
        v.pbk(shape);
    }
    liang();
    for(i=0; ans.size(); i++)
    {
        for(j=0;j<ans[i].size();j++)
            {cout<<ans[i][j].f<<" "<<ans[i][j].s<<" : ";
            //cout<<bit[i][j].b1<<" "<<bit[i][j].b2<<" "<<bit[i][j].b3<<" "<<bit[i][j].b4<<" : ";
            }
            cout<<endl;
    }

    return 0;
}
/*
1 2 9 8
5
2
3 7
3 10
2
2 3
8 4
2
8 9
6 6
2
-1 7
11 1
2
11 10
11 6
*/
