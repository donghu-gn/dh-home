#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<easyx.h> 
#define DU 3.1415926/180
int x0,y0,r,s1,s2;
void init()
{
	while(1)
	{
		printf("请依次输入扇形参数(整数)：x0,y0,r(r>0),s1,s2(0<=s1,s2<=360&&s1!=s2)");
		scanf(x0,y0,r,s1,s2);
		if(r<=0||s1<0||s1>360||s2<0||s2>360||s1==s2)
			printf("输入有误，请重新输入。");
		else break; 
	}
	s1=s1*DU;
	s2=s2*DU;
	if(s2>s1) int sz=(s1+s2)/2*DU;    //sz为种子角度 
	if(s2<s1) int sz=(360-s1+s2)/2*DU; 
	const double x1=x0+r*cos(s1),y1=y0+r*sin(s1);
	const double x2=x0+r*cos(s2),y2=y0+r*sin(s2);
	const double xz=x0+r/2*cos(sz),yz=y0+r/2*sin(sz); 
	double k1=double(x1-x0)/(y1-y0);
	double k2=double(x2-x0)/(y2-y0);
	
}
void MidPointLine(int x0,int y0,int x1,int y1,int color)
{
	int dx,dy,incrE,incrNE,d,x,y;
	dx=x1-x0;
	dy=y1-y0;
	d=dx-2*dy;
	incrE=-2*dy;
	incrNE=2*(dx-dy);
	x=x0,y=y0;
	PutPixel(x,y,color);
	while(x<x1)
	{
		if(d>0) d+=incrE;
		else
		{
			d+=incrNE;
			y++;
			x++;
		}
		PutPixel(x,y,color);
	}
}
void CirclePoint(int x,int y,int color)
{
	if(s1<90&&s2<=90&&s1<s2)	//1
	{
		if(x2<=x&&x=<x1&&y1<=y&&y<=y2) PutPixel(x,y,color);
		if(x2<=y&&y=<x1&&y1<=x&&x<=y2) PutPixel(y,x,color);
	}
	if(s1<90&&s2<=90&&s1>s2)	//2
	{
		PutPixel(x,y,color);
		PutPixel(-x,y,color);
		PutPixel(x,-y,color);
		PutPixel(-x,-y,color);
		PutPixel(y,x,color);
		PutPixel(-y,x,color);
		PutPixel(y,-x,color);
		PutPixel(-y,-x,color);
		if(x2<=x&&x=<x1&&y1<=y&&y<=y2) PutPixel(x,y,BLACK);
		if(x2<=y&&y=<x1&&y1<=x&&x<=y2) PutPixel(y,x,BLACK);
	}
	if(90<=s1&&s1<180&&90<s2&&s2<=180&&s1<s2)	//3
	{
		if(x2<=-x&&-x=<x1&&y2<=y&&y<=y1) PutPixel(-x,y,color);
		if(x2<=y&&y=<x1&&y2<=x&&x<=y1) PutPixel(-y,x,color);
	}
	if(90<=s1&&s1<180&&90<s2&&s2<=180&&s1>s2)	//4
	{
		PutPixel(x,y,color);
		PutPixel(-x,y,color);
		PutPixel(x,-y,color);
		PutPixel(-x,-y,color);
		PutPixel(y,x,color);
		PutPixel(-y,x,color);
		PutPixel(y,-x,color);
		PutPixel(-y,-x,color);
		if(x2<=-x&&-x=<x1&&y2<=y&&y<=y1) PutPixel(-x,y,BLACK);
		if(x2<=y&&y=<x1&&y2<=x&&x<=y1) PutPixel(-y,x,BLACK);
	}
	if(180<=s1&&s1<270&&180<s2&&s2<=270&&s1<s2)	//5
	{
		if(x1<=-x&&-x=<x2&&y2<=-y&&-y<=y1) PutPixel(-x,-y,color);
		if(x1<=-y&&-y=<x2&&y2<=-x&&-x<=y1) PutPixel(-y,-x,color);
	}
	if(180<=s1&&s1<270&&180<s2&&s2<=270&&s1>s2)	//6
	{
		PutPixel(x,y,color);
		PutPixel(-x,y,color);
		PutPixel(x,-y,color);
		PutPixel(-x,-y,color);
		PutPixel(y,x,color);
		PutPixel(-y,x,color);
		PutPixel(y,-x,color);
		PutPixel(-y,-x,color);
		if(x1<=-x&&-x=<x2&&y2<=-y&&-y<=y1) PutPixel(-x,-y,BLACK);
		if(x1<=-y&&-y=<x2&&y2<=-x&&-x<=y1) PutPixel(-y,-x,BLACK);
	}
	if(270<=s1&&s1<360&&270<s2&&s2<=360&&s1<s2)	//7
	{
		if(x1<=x&&x=<x2&&y1<=-y&&-y<=y2) PutPixel(x,-y,color);
		if(x1<=y&&y=<x2&&y1<=-x&&-x<=y2) PutPixel(y,-x,color);
	}
	if(270<=s1&&s1<360&&270<s2&&s2<=360&&s1>s2)	//8
	{
		PutPixel(x,y,color);
		PutPixel(-x,y,color);
		PutPixel(x,-y,color);
		PutPixel(-x,-y,color);
		PutPixel(y,x,color);
		PutPixel(-y,x,color);
		PutPixel(y,-x,color);
		PutPixel(-y,-x,color);
		if(x1<=x&&x=<x2&&y1<=-y&&-y<=y2) PutPixel(-x,-y,BLACK);
		if(x1<=y&&y=<x2&&y1<=-x&&-x<=y2) PutPixel(-y,-x,BLACK);
	}
	if(0<=s1&&s1<=90&&90<s2&&s2<=180)	//9
	{
		if(x2<=x&&x<=x1&&y>=0) PutPixel(x,y,color);
		if(x2<=y&&y<=x1&&x>=0) PutPixel(y,x,color);
		if(x2<=-x&&-x<=x1&&y>=0) PutPixel(-x,y,color);
		if(x2<=-y&&-y<=x1&&x>=0) PutPixel(-y,x,color);
	}
	if(0<=s2&&s2<=90&&90<s1&&s1<=180)	//10
	{
		PutPixel(x,y,color);
		PutPixel(-x,y,color);
		PutPixel(x,-y,color);
		PutPixel(-x,-y,color);
		PutPixel(y,x,color);
		PutPixel(-y,x,color);
		PutPixel(y,-x,color);
		PutPixel(-y,-x,color);
		if(x2<=x&&x<=x1&&y>=0) PutPixel(x,y,BLACK);
		if(x2<=y&&y<=x1&&x>=0) PutPixel(y,x,BLACK);
		if(x2<=-x&&-x<=x1&&y>=0) PutPixel(-x,y,BLACK);
		if(x2<=-y&&-y<=x1&&x>=0) PutPixel(-y,x,BLACK);
	}
	if(90<=s1&&s1<=180&&180<s2&&s2<=270)	//11
	{
		if(y2<=y&&y<=y1&&-x<=0) PutPixel(-x,y,color);
		if(y2<=x&&x<=y1&&-y<=0) PutPixel(-y,x,color);
		if(y2<=-y&&-y<=y1&&-x<=0) PutPixel(-x,-y,color);
		if(y2<=-x&&-x<=y1&&-y<=0) PutPixel(-y,-x,color);
	}
	if(90<=s1&&s1<=180&&180<s2&&s2<=270)	//12
	{
		PutPixel(x,y,color);
		PutPixel(-x,y,color);
		PutPixel(x,-y,color);
		PutPixel(-x,-y,color);
		PutPixel(y,x,color);
		PutPixel(-y,x,color);
		PutPixel(y,-x,color);
		PutPixel(-y,-x,color);
		if(y2<=y&&y<=y1&&-x<=0) PutPixel(-x,y,BLACK);
		if(y2<=x&&x<=y1&&-y<=0) PutPixel(-y,x,BLACK);
		if(y2<=-y&&-y<=y1&&-x<=0) PutPixel(-x,-y,BLACK);
		if(y2<=-x&&-x<=y1&&-y<=0) PutPixel(-y,-x,BLACK);
	}
	if(180<=s1&&s1<=270&&270<s2&&s2<=360)	//13
	{
		if(x1<=x&&x<=x2&&-y<=0) PutPixel(x,-y,color);
		if(x1<=y&&y<=x2&&-x<=0) PutPixel(y,-x,color);
		if(x1<=-x&&-x<=x2&&-y<=0) PutPixel(-x,-y,color);
		if(x1<=-y&&-y<=x2&&-x<=0) PutPixel(-y,-x,color);
	}
	if(180<=s1&&s1<=270&&270<s2&&s2<=360)	//14
	{
		PutPixel(x,y,color);
		PutPixel(-x,y,color);
		PutPixel(x,-y,color);
		PutPixel(-x,-y,color);
		PutPixel(y,x,color);
		PutPixel(-y,x,color);
		PutPixel(y,-x,color);
		PutPixel(-y,-x,color);
		if(x1<=x&&x<=x2&&-y<=0) PutPixel(x,-y,BLACK);
		if(x1<=y&&y<=x2&&-x<=0) PutPixel(y,-x,BLACK);
		if(x1<=-x&&-x<=x2&&-y<=0) PutPixel(-x,-y,BLACK);
		if(x1<=-y&&-y<=x2&&-x<=0) PutPixel(-y,-x,BLACK);
	}
	if(270<=s1&&s1<=360&&0<s2&&s2<=90)	//15
	{
		if(y1<=y&&y<=y2&&x>=0) PutPixel(x,y,color);
		if(y1<=x&&x<=y2&&y>=0) PutPixel(y,x,color);
		if(y1<=-y&&-y<=y2&&x>=0) PutPixel(x,-y,color);
		if(y1<=-x&&-x<=y2&&y>=0) PutPixel(y,-x,color);
	}
	if(270<=s1&&s1<=360&&0<s2&&s2<=90)	//16
	{
		PutPixel(x,y,color);
		PutPixel(-x,y,color);
		PutPixel(x,-y,color);
		PutPixel(-x,-y,color);
		PutPixel(y,x,color);
		PutPixel(-y,x,color);
		PutPixel(y,-x,color);
		PutPixel(-y,-x,color);
		if(y1<=y&&y<=y2&&x>=0) PutPixel(x,y,BLACK);
		if(y1<=x&&x<=y2&&y>=0) PutPixel(y,x,BLACK);
		if(y1<=-y&&-y<=y2&&x>=0) PutPixel(x,-y,BLACK);
		if(y1<=-x&&-x<=y2&&y>=0) PutPixel(y,-x,BLACK);
	}
	if(0<=s1&&s1<90&&180<s2&&s2<=270)	//17
	{
		if(-r<=x&&x<=x1&&y>=0) PutPixel(x,y,color);
		if(-r<=y&&y<=x1&&x>=0) PutPixel(y,x,color);
		if(-r<=-x&&-x<=x1&&y>=0) PutPixel(-x,y,color);
		if(-r<=-y&&-y<=x1&&x>=0) PutPixel(-y,x,color);
		if(-r<=-x&&-x=<x2&&-y<=0) PutPixel(-x,-y,color);
		if(-r<=-y&&-y=<x2&&-x<=0) PutPixel(-y,-x,color);
	}
	if(90<=s1&&s1<180&&270<s2&&s2<=360)	//18
	{
		if(-r<=y&&y<=y1&&-x<=0) PutPixel(-x,y,color);
		if(-r<=x&&x<=y1&&-y<=0) PutPixel(-y,x,color);
		if(-r<=-y&&-y<=y1&&-x<=0) PutPixel(-x,-y,color);
		if(-r<=-x&&-x<=y1&&-y<=0) PutPixel(-y,-x,color);
		if(-r<=x&&x=<x2&&y1<=-y&&x>=0) PutPixel(x,-y,color);
		if(-r<=y&&y=<x2&&y1<=-x&&y>=0) PutPixel(y,-x,color);
	}
	if(180<=s1&&s1<270&&0<s2&&s2<=90)	//19
	{
		if(x1<=x&&x<=r&&-y<=0) PutPixel(x,-y,color);
		if(x1<=y&&y<=r&&-x<=0) PutPixel(y,-x,color);
		if(x1<=-x&&-x<=r&&-y<=0) PutPixel(-x,-y,color);
		if(x1<=-y&&-y<=r&&-x<=0) PutPixel(-y,-x,color);
		if(x2<=x&&x=<r&&y>=0) PutPixel(x,y,color);
		if(x2<=y&&y=<r&&x>=0) PutPixel(y,x,color);
	}
	if(270<=s1&&s1<360&&90<s2&&s2<=180)	//20
	{
		if(x2<=x&&x<=r&&y>=0) PutPixel(x,y,color);
		if(x2<=y&&y<=r&&x>=0) PutPixel(y,x,color);
		if(x2<=-x&&-x<=r&&y>=0) PutPixel(-x,y,color);
		if(x2<=-y&&-y<=r&&x>=0) PutPixel(-y,x,color);
		if(x1<=x&&x=<r&&-y<=0) PutPixel(x,-y,color);
		if(x1<=y&&y=<r&&-x<=0) PutPixel(y,-x,color);
	}
	
}
void MidPointCircle(int radius,int color)
{
	int x,y,d;
	x=0;
	y=radius;
	d=5-4*radius;
	CirclePoints(x,y,color);
	while(y>x)
	{
		if(d<=0) d+=8*x+12;
		else
		{
			d+=8*(x-y)+20;
			y--;
		}
		x++;
		CirclePoints(x,y,color);
	}
}
void FloodFill4(int x,int y,int oldColor,int newColor)
{
	if(GetPixel(x,y)==oldColor)
	{
		PutPixel(x,y,color);
		FloodFill4(x,y+1,oldColor,newColor);
		FloodFill4(x,y-1,oldColor,newColor);
		FloodFill4(x-1,y,oldColor,newColor);
		FloodFill4(x+1,y,oldColor,newColor);
	}
}
int main()
{
	init();                // 初始化 
	initgraph(600, 600);   // 设置画布大小
    setorigin(300,300);    // 设置坐标原点 
	MidPointLine(x0,y0,x1,y1,WHITE);
	MidPointLine(x0,y0,x2,y2,WHITE);
	MidPointCircle(r,WHITE); 
	FloodFill4(xz,yz,BLACK,WHITE); 
}
