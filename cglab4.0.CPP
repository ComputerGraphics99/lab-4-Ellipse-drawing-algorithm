#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#define ROUND(a)((int)(a+0.5))
void midpoint(int x1, int y1, int rx, int ry)
{
	int Rx=rx*rx, Ry=ry*ry;
	int Rx2=2*Rx, Ry2=2*Ry;
	int x=0, y=ry, px=0, py=Rx2*y, p;
	void ellipsedraw(int, int , int, int);
	//Region 1
	p=ROUND(Ry-(Rx*ry)+(0.25*Rx));
	while(px<py)
	{
		x++;
		px+=Ry2;
		if(p<0)
			p+=Ry+px;
		else
		{
			y--;
			py+=-Rx2;
			p+=Ry+px-py;
		}
		ellipsedraw(x1,y1, x,y);
	}
	//Region 2
	p=ROUND(Ry*(x+0.5)*(x+0.5)+Rx*(y-1)*(y-1)-Rx*Ry);
	while(y>0)
	{
		y--;
		py+=-Rx2;
		if(p>0)
			p+=Rx-py;
		else
		{
			x++;
			px+=Ry2;
			p+=Rx-py+px;
		}
		ellipsedraw(x1, y1, x, y);
	}
	closegraph();
	getch();
}
void ellipsedraw(int x1, int y1,int x, int y)
{
	putpixel(x1+x, y1+y, 5);
	putpixel(x1-x, y1+y, 5);
	putpixel(x1+x, y1-y, 5);
	putpixel(x1-x, y1-y, 5);
	getch();
}
void textdisplay()
{
	//cout<<"\n\t\t\tPROJECT No.: 04\n";
	//cout<<"\t\t\Midpoint Ellipse Drawing Algorithm\n";
	//cout<<"\n*****SWORNIM KARMA*****\n";
	cout<<"\n\n\t\t\t\tCo-ordiantes:\n";
	cout<<"\t\t\t\t\t(x, y)=(20, 50)\n";
	cout<<"\t\t\t\t\t(Rx, Ry)=(20, 30)";
	getch();
}
void main()
{
	int x1=20, y1=50, rx=20, ry=30;
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "C:\\turboc3\\bgi");
	textdisplay();
	midpoint(x1,y1,rx,ry);
	getch();
}