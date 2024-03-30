#include <iostream>
#include <graphics.h>
using namespace std;

class dlc
{
	public:
	void my_line(int x1,int y1,int x2,int y2)
	{
		 
		float dx,dy,xin,yin,x,y;
		int len;
		dx=x2-x1;
		dy=y2-y1;
	
		if(abs(dx)>=abs(dy))
		{
			len=abs(dx);
		}
		else
		{
			len=abs(dy);
		}
	
		xin=dx/len;
		yin=dy/len;
	
		x=x1;
		y=y1;
		int i=0;
		while(i<=len)
		{
			putpixel(round(x),round(y),WHITE);
			x=x+xin;
			y=y+yin;
			i++;
		}
	}
	public:
	void my_circle(int centx, int centy,int r)
	{
		int x,y,p;
		x=0;
	y=r;
	p=3-(2*r);
	
	do
	{
		putpixel(centx+x,centy+y,1);
		putpixel(centx+x,centy-y,2);
		putpixel(centx-x,centy+y,3);
		putpixel(centx-x,centy-y,4);
		putpixel(centx+y,centy+x,5);
		putpixel(centx+y,centy-x,6);
		putpixel(centx-y,centy+x,7);
		putpixel(centx-y,centy-x,8);
		if(p<0)
		{
			p=p+(4*x)+6;
		}
		else
		{
			p=p+(4*(x-y))+10;
			y=y-1;
		}
		x=x+1;

	}
	while(x<y);
	}
};
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	dlc obj1;
	int cx,cy,rad;
	int x1,x2,x3,y1,y2,y3,rads;
	cout<<"Enter the x coordinate of the center of outer circle:";
	cin>>cx;
	cout<<"Enter the y coordinate of the center of outer circle:";
	cin>>cy;
	cout<<"Enter the radius of the  outer circle:";
	cin>>rad;//radis of the outer circle
	rads=rad/2;//radius of the inner circle
	x1=cx;
	y1=cy-rad;
	x2=cx+(0.866025404*rad);
	y2=cy+(0.5*rad);
	x3=cx-(0.866025404*rad);
	y3=cy+(0.5*rad);
	obj1.my_circle(cx,cy,rad);
	obj1.my_line(x1,y1,x2,y2);
	obj1.my_line(x2,y2,x3,y3);
	obj1.my_line(x3,y3,x1,y1);
	obj1.my_circle(cx,cy,rads);
	
	delay(15000);
	closegraph();
	return(0);
	
}


