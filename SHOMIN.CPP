#include"jinzhan.h"

void shuomin()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"D:\\borlandC\\bgi");

	setfillstyle(1,WHITE);
	bar(0,0,640,460);
	puts12(3,40,"����ģ�����м��Զ���Ʊϵͳ",BLACK,4,4);
	puts12(145,203,"ף��·;���һ·˳��",RED,3,3);
	puts12(102,313,"����",RED,2,2);
	puts12(170,313,"����",BLUE,2,2);
	settextstyle(0,0,2);
	setcolor(BLACK);
	outtextxy(265,316,"U201314538");
        outtextxy(265,346,"U201314552");
	puts12(170,343,"Ф��",BLUE,2,2);
	puts12(430,313,"�Զ���ѧԺ",RED,2,2);
	puts12(430,343,"һ����һ��",BLUE,2,2);
	puts12(500,440,"�Զ���ѧԺ��Ȩ����",BLACK,1,1);
	
	getch();
	cleardevice();

	bar(0,0,640,460);
	puts12(102,43,"�������˵�ѡ��ѡվ����Ͷ�ҳ�Ʊ",RED,2,2);
	puts12(102,93,"�ڽ���ѡվ����Ը��ĳ���վ",RED,2,2);
	puts12(102,143,"�ڽ���ѡվ����Ը����յ�վ����Ҫ��Ʊ��",RED,2,2);
	puts12(102,193,"Ȼ���ȷ��Ҳ���Խ���Ͷ�ҽ���",RED,2,2);
	puts12(102,243,"���ߵ��˳��������˵�",RED,2,2);
	puts12(102,293,"Ͷ�ҽ���Ҳ���Է������˵�",RED,2,2);
	puts12(102,343,"��ʵ�ܺö�",RED,2,2);
	puts12(102,393,"�ǵø�����лл",BLUE,2,2);
	circle(460,300,10);
	circle(500,300,10);
	circle(480,320,60);
	setfillstyle(1,BLACK);
	floodfill(460,300,BLACK);
	floodfill(500,300,BLACK);
	moveto(480,320);
	lineto(475,340);
	lineto(485,340);
	moveto(450,350);
	lineto(470,360);
	lineto(490,360);
	lineto(510,350);
	lineto(450,350);
	setfillstyle(1,RED);
	floodfill(470,353,BLACK);
	
	getch();
	closegraph();
}