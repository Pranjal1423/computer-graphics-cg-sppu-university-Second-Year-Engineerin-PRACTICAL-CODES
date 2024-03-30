#include <iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

void move(int j,int h , int &x, int &y)
{
    if(j==1)
        y=y-h;
    else if(j==2)
        x=x+h;
    else if(j==3)
        y=y+h;
    else if(j==4)
        x=x-h;
    lineto(x,y);
}
void hilbert(int u,int r,int d,int l,int i,int h,int &x,int&y)
{
    if(i>0)
    {   
        i--;
        hilbert(r,u,l,d,i,h,x,y);
        move(u,h,x,y);
        hilbert(u,r,d,l,i,h,x,y);
        move(r,h,x,y);
        hilbert(u,r,d,l,i,h,x,y);
        move(d,h,x,y);
        hilbert(l,d,r,u,i,h,x,y);
    }
}
int main()
{
    int x,y,n,h=15,u=1,r=2,d=3,l=4;
    cout<<"Enter start point"<<endl;
    cin>>x>>y;
    cout<<"Enter value of n "<<endl;
    cin>>n;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    moveto(x,y);
    hilbert(u,r,d,l,n,h,x,y);
    getch();
    closegraph();
    return 0;
}
