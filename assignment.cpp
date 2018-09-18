#include "iGraphics.h"

double x=300, y=550,a=13,b=25,lx=240;
int score=0;
int health = 100,flag=0;
char s[50];
char h[50];

void repeat()
{
	itoa(health,h,10);
	itoa(score,s,10);
	y-=3;

	if(y-b<=47)
	{
		if(x>=lx &&  x<=lx+128 && y-b>=19)
		{
			if(x>=lx+43 && x<=lx+85) score+=5;
			else if((x>lx+22 && x<43) || (x>85 && x<=106)) score+=3;
			else score++;
			itoa(score,s,10);
			
			y=550;
			x=rand() % 585 + 15;
		}
		
	}
	if(y-b<=0)
	{
		y=550;
		x=rand() % 585 + 15;
		health=health-20;
		itoa(health,h,10);
	}
	if(health==0)
	{
		exit(0);
	}
}
void stop()
{
	exit(0);
}
void iDraw()
{
	iClear();
		iSetColor(29,63,13);
		iShowBMP(0,0,"back.bmp");
		iFilledEllipse(x, y, a, b);
		iShowBMP(x-8,y-8,"rad.bmp");
		iLine(x,y-b,x,y-b-5);
		iLine(x-1,y-b+1,x-1,y-b-3);
		iLine(x+1,y-b+1,x+1,y-b-3);
		iLine(x-5,y+b-5,x-5,y+b+5);
		iLine(x-6,y+b-3,x-6,y+b+7);
		iLine(x-7,y+b-2,x-7,y+b+9);
		iLine(x-8,y+b-1,x-8,y+b+11);
		iLine(x+5,y+b-5,x+5,y+b+5);
		iLine(x+6,y+b-3,x+6,y+b+7);
		iLine(x+7,y+b-2,x+7,y+b+9);
		iLine(x+8,y+b-1,x+8,y+b+11);
		iShowBMP(lx,10,"target.bmp");
		iSetColor(220,20,188);
		iText(10,370,"SCORE ",GLUT_BITMAP_HELVETICA_12);
		iText(60,370,s,GLUT_BITMAP_HELVETICA_12);
		iSetColor(255,50,50);
		iText(515,370,"HEALTH ",GLUT_BITMAP_HELVETICA_12);
		iText(570,370,h,GLUT_BITMAP_HELVETICA_12);
		iSetColor(50,80,200);
		iText(100,370,"PG-UP to PAUSE",GLUT_BITMAP_HELVETICA_12);
		iText(350,370,"PG-DOWN to RESUME",GLUT_BITMAP_HELVETICA_12);
		iSetColor(102,102,255);
		iText(lx+2,30,"  1   3      5       3   1",GLUT_BITMAP_HELVETICA_12);
}
void iMouseMove(int mx, int my)
{

}
void iMouse(int button, int state, int mx, int my)
{

}
void iKeyboard(unsigned char key)
{

}
void iSpecialKeyboard(unsigned char key)
{
	
	if (key == GLUT_KEY_LEFT && lx>0 && flag == 0)
	{
		lx -= 10;
	}
	if (key == GLUT_KEY_RIGHT && lx < 470 && flag == 0)
	{
		lx += 10;
	}
	if(key == GLUT_KEY_PAGE_UP)
	{
		iPauseTimer(0);
		iPauseTimer(1);
		flag=1;
		
	}
	if(key == GLUT_KEY_PAGE_DOWN)
	{
		iResumeTimer(0);
		iResumeTimer(1);
		flag=0;
	}
}
int main()
{
	iSetTimer(5,repeat);
	iSetTimer(120100,stop);
	iInitialize(600, 400);
	return 0;
}