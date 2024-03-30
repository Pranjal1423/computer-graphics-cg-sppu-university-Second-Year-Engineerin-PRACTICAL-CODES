#include <iostream>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

using namespace std;
static int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8,xmin,xmax,ymin,ymax;
int getcode(int x,int y)
{
	int code=0;
	if (y>ymax) code|=TOP;
	if (y<ymin) code|=BOTTOM;
	if (x>xmax) code|=RIGHT;
	if (x<xmin) code|=LEFT;
	return code;
}
int main()
{
	int gd=DETECT, gm;
	initgraph(&gd,&gm,NULL);
	setcolor(WHITE);
	int x1,y1,x2,y2;
	cout<<"Enter the top left and bottom right coordinates of window:"<<endl;
	cin>>xmin>>ymin>>xmax>>ymax;
	cout<<"Enter the end points of the line"<<endl;
	cin>>x1>>y1>>x2>>y2;
	outtext("Before clipping");
	rectangle(xmin,ymin,xmax,ymax);
	line(x1,y1,x2,y2);
	delay(10000);
	
	int outcode1=getcode(x1,y1);
	int outcode2=getcode(x2,y2);
	int accept=0; //declares if the line is to be drawn
	while(1)
	{
		float m=(float)(y2-y1)/(x2-x1);
		//Both end points inside then accept the line
		if(outcode1==0  && outcode2==0)
		{
			accept=1;
			break;
		}
		//if AND of both the codes !=0 then the line is outside so reject the line
		else if((outcode1  & outcode2)!=0)
		{
			break;
		}
		else
		{
			int x,y;
			int temp;
			// to check whether the point is inside or not, if not then calculate intersection
			if(outcode1==0)
				temp=outcode2;
		        else
				temp=outcode1;
				
			if(temp & TOP)
			{
				//line clips the top edge
				x=x1+(ymax-y1)/m;
				y=ymax;
			}
			else if(temp & BOTTOM)
			{
				//line clips the bottom edge
				x=x1+(ymin-y1)/m;
				y=ymin;
			}
			else if(temp & LEFT)
			{
				//line clips the left edge
				x=xmin;
				y=y1+m*(xmin-x1);
			}
			else if(temp & RIGHT)
			{
				//line clips the right edge
				x=xmax;
				y=y1+m*(xmax-x1);
			}
		//check which point earlier we had selected as temp and replace its coordinates
			if(temp==outcode1)
			{
				x1=x;
				y1=y;
				outcode1=getcode(x1,y1);
			}
			else
			{
				x2=x;
				y2=y;
				outcode2=getcode(x2,y2);
			}
		}

		}//while ends

	setcolor(BLUE);
	if(accept)
	{
		cleardevice();
		outtext("After clipping");
		rectangle(xmin,ymin,xmax,ymax);
		line(x1,y1,x2,y2);
	}
	else
	{
		cleardevice();
		outtext("After clipping");
		rectangle(xmin,ymin,xmax,ymax);
	}
	getch();
	
	
	closegraph();
	return 0;
	
}

