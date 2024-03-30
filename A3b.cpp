#include <iostream>
#include <graphics.h>
#include <cmath>
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
		putpixel(centx+x,centy+y,WHITE);//4
		putpixel(centx+x,centy-y,WHITE);//1
		putpixel(centx-x,centy+y,WHITE);//5
		putpixel(centx-x,centy-y,WHITE);//8
		putpixel(centx+y,centy+x,WHITE);//3
		putpixel(centx+y,centy-x,WHITE);//2
		putpixel(centx-y,centy+x,WHITE);//6
		putpixel(centx-y,centy-x,WHITE);//7
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
	int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8,D,d,r,cx,cy;
	cout<<"Enter the first x coordinate of the diagnol of the rectangle:";
	cin>>x1;
	cout<<"Enter the first y coordinate of the diagnol of the rectangle:";
	cin>>y1;
	/*cout<<"Enter the second x coordinate of the diagnol of the rectangle:";
	cin>>x2;
	cout<<"Enter the second y coordinate of the diagnol of the rectangle:";
	cin>>y2;*/
        x2=getmaxx();
	y2=getmaxy();
	x3=x2;
	y3=y1;
	x4=x1;
	y4=y2;
	x5=(x1+x3)/2;
	y5=y1;
	x6=x3;
	y6=(y3+y2)/2;
	x7=x5;
	y7=y2;
	x8=x1;
	y8=y6;
	D=x3-x1;
	d=y2-y3;
	r=(D*d)/(2*sqrt((d*d)+(D*D)));
	cx=x5;
	cy=y8;
	obj1.my_line(x1,y1,x4,y4);
	obj1.my_line(x4,y4,x2,y2);
	obj1.my_line(x2,y2,x3,y3);
	obj1.my_line(x3,y3,x1,y1);
	obj1.my_line(x5,y5,x6,y6);
	obj1.my_line(x6,y6,x7,y7);
	obj1.my_line(x7,y7,x8,y8);
	obj1.my_line(x8,y8,x5,y5);
	obj1.my_circle(cx,cy,r);
	delay(15000);
	closegraph();
	return(0);
	
}


