#include"goupiaoj.h"

struct route
{
	int x;
	int y;
	char name[20];
	char code[20];
};

int goupiaojiemian(int z,float *money1,int *ticketnums)
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"D:\\borlandC\\bgi");

	cleardevice();
	
	struct route zh[18]={{80,100,"����վ","a"},
				{150,120,"����վ","b"},
				{180,170,"��Էʳ��վ","c"},
				{180,250,"�Ƽ�¥վ","d"},
				{220,280,"��һ¥վ","e"},
				{300,290,"��ʮ��վ","f"},
				{330,320,"��С��վ","g"},
				{340,380,"�в�վ","h"},
				{310,440,"��һʳ��վ","i"},
				{120,450,"����վ","j"},
				{170,430,"��ʮ��վ","k"},
				{140,370,"�پ�԰վ","l"},
				{200,330,"��óվ","m"},
				{220,280,"��һ¥վ","n"},
				{260,220,"��С��վ","o"},
				{300,200,"������վ","p"},
				{350,170,"��԰ʳ��վ","q"},
				{360,120,"����վ","r"}};
	struct route *p;
	
	int mouse_x=0,mouse_y=0, mouseclick=0; 
	float money=0;
	char *state1="��;�˳�";
	char *state2="���빺Ʊ";
	int flag=0;//����FLAG��ʹѡվ����ܵ�ȷ��
	int forp;//��ѡվ���վ�Ŵ��ݳ�������д���ı��ļ�
	int flag2=0;//����ѡ����·������»���·
	
	cursor(mouse_x,mouse_y);
	int ticnum=1;//Ʊ��
	
	drawjiemian(z);
	
	for(;;)
	{
		mouseclick=0;
		newmouse(&mouse_x,&mouse_y,&mouseclick);//���
		buttonclick(mouse_x,mouse_y,mouseclick);//ʵ�ֵ��
 		stationchoose(mouse_x,mouse_y,mouseclick,&flag2,&money,z,&flag,&forp,ticnum);//ʵ��ѡվ
		routechoose(&flag2,mouse_x,mouse_y,mouseclick);//ʵ��ѡ��·��
		ticketnum(mouse_x,mouse_y,mouseclick,&ticnum,&money);//ʵ��Ʊ���Ӽ�
		p=zh+forp;
		//ʵ�ָ�վ
		if(540<mouse_x&&mouse_x<630&&60<mouse_y&&mouse_y<90&&mouseclick)
		{
			buttondown(558,60,630,90);
			puts12(570,63,"����",RED,2,2);
			delay(100);
			closegraph();
			return 3;//��ת���ĳ���վ����
		}
        //�˳�������
		if(310<mouse_x&&mouse_x<400&&10<mouse_y&&mouse_y<50&&mouseclick)
		{
			printf("%d",forp);
			writedata(p->name);
			writedata(state1);			
			writedata(" ");	
			delay(100);
			return 0;//���ص����˵�
		}
		//ʵ�ִ���
		if(210<mouse_x&&mouse_x<300&&10<mouse_y&&mouse_y<50&&mouseclick&&flag==1)
		{
			*money1=money;
			*ticketnums=ticnum;
			writedata(p->name);
			writedata(state2);
			writedata(" ");
			delay(100);
			closegraph();
			return 10;//��ת��Ͷ�ҽ���
		}
	}
}

void drawjiemian(int z)
{
	struct route zh[18]={{80,100,"����վ","a"},
				{150,120,"����վ","b"},
				{180,170,"��Էʳ��վ","c"},
				{180,250,"�Ƽ�¥վ","d"},
				{220,280,"��һ¥վ","e"},
				{300,290,"��ʮ��վ","f"},
				{330,320,"��С��վ","g"},
				{340,380,"�в�վ","h"},
				{310,440,"��һʳ��վ","i"},
				{120,450,"����վ","j"},
				{170,430,"��ʮ��վ","k"},
				{140,370,"�پ�԰վ","l"},
				{200,330,"��óվ","m"},
				{220,280,"��һ¥վ","n"},
				{260,220,"��С��վ","o"},
				{300,200,"������վ","p"},
				{350,170,"��԰ʳ��վ","q"},
				{360,120,"����վ","r"}};

	int i=2,j=2;
	setbkcolor(LIGHTBLUE);
    //������ť���������
	button(10,10,100,50);
	button(110,10,200,50);
	button(210,10,300,50);
	button(310,10,400,50);
	button(558,60,630,90);
	puts12(12,13,"һ����",RED,2,2);
	puts12(112,13,"������",RED,2,2);
	puts12(212,13,"ȷ��",RED,2,2);
	puts12(312,13,"�˳�",RED,2,2);
	puts12(570,63,"����",RED,2,2);
	//��ʾʱ��
	showtime();

	struct route *p;
	//����վ��
	for(p=zh;p<zh+18;p++)
	{
		station(p->x,p->y);
	}
	//����һ����
	setlinestyle(0,0,i);
	setcolor(RED);
	moveto(80,100);
	for(p=zh;p<zh+9;p++)
	{
		lineto(p->x,p->y);
	}             
	//����������
	setlinestyle(0,0,j);
	setcolor(BROWN);
	moveto(120,450);
	for(p=zh+9;p<zh+18;p++)
	{
		lineto(p->x,p->y);
	}                  
	//������վ
	stationb(220,280);
	//�����߿�
	setlinestyle(0,0,3);
	setcolor(MAGENTA);
	moveto(420,0);
	lineto(420,500);
	moveto(0,70);
	lineto(420,70);
	moveto(420,100);
	lineto(640,100);
	
	//������������
	setcolor(RED);
	moveto(490,245);
	lineto(510,230);
	lineto(510,260);
	lineto(490,245);
	setfillstyle(1,WHITE);
	floodfill(495,245,RED);
	moveto(605,245);
	lineto(585,230);
	lineto(585,260);
	lineto(605,245);
	floodfill(600,245,RED);
	
	//������Ϣ
	p=zh+z;
	puts12(455,8,"��ǰ��վ",RED,3,3);
	puts12(430,115,"��",RED,2,2);
	puts12(430,151,"��",RED,2,2);
	puts12(430,60,p->name,YELLOW,2,2);
	puts12(460,115,p->name,YELLOW,2,2);
	puts12(430,193,"��Ʊ��Ϊ",RED,2,2);
	puts12(580,193,"Ԫ",RED,2,2);
	puts12(430,234,"����",RED,2,2);
	//д��վ���ͼ��̴����ķ���
	for(p=zh;p<zh+4;p++)
	{
		puts12(p->x-70,p->y-5,p->name,RED,1,1);
		outtextxy(p->x+6,p->y-5,p->code);
	}
	for(p=zh+5;p<zh+9;p++)
	{
		puts12(p->x-70,p->y-5,p->name,RED,1,1); 
		outtextxy(p->x+6,p->y-5,p->code);
	}
	for(p=zh+9;p<zh+13;p++)
	{
		puts12(p->x-70,p->y-5,p->name,GREEN,1,1);
		outtextxy(p->x+6,p->y-5,p->code);
	}
	for(p=zh+14;p<zh+18;p++)
	{
		puts12(p->x+20,p->y-5,p->name,GREEN,1,1);
		outtextxy(p->x+6,p->y-5,p->code);
	}
	for(p=zh+13;p<zh+14;p++)
	{
		puts16(p->x-80,p->y-5,p->name,YELLOW,1,1);
	}
	//��ͼ
	chatu(423,269,0.9,"D:\\BORLANDC\\lala1l\\PICT\\LZ16.DAT");
}

void buttonclick(int mouse_x,int mouse_y,int mouseclick)
{		
	//ʵ�ֵ����ťЧ��/*******************ÿ��ѡ��ť���ػ��ĸ���ť*****/
	if(10<mouse_x&&mouse_x<100&&10<mouse_y&&mouse_y<50&&mouseclick)
	{
		buttondown(10,10,100,50);
		button(110,10,200,50);
		button(210,10,300,50);
		button(310,10,400,50);
		puts12(12,13,"һ����",RED,2,2);
		puts12(112,13,"������",RED,2,2);
		puts12(212,13,"ȷ��",RED,2,2);
		puts12(312,13,"�˳�",RED,2,2);
	}
	if(110<mouse_x&&mouse_x<200&&10<mouse_y&&mouse_y<50&&mouseclick)
	{
		buttondown(110,10,200,50);
		button(10,10,100,50);
		button(210,10,300,50);
		button(310,10,400,50);
		puts12(12,13,"һ����",RED,2,2);
		puts12(112,13,"������",RED,2,2);
		puts12(212,13,"ȷ��",RED,2,2);
		puts12(312,13,"�˳�",RED,2,2);
	}
	if(210<mouse_x&&mouse_x<300&&10<mouse_y&&mouse_y<50&&mouseclick)
	{
		buttondown(210,10,300,50);
		button(10,10,100,50);
		button(110,10,200,50);
		button(310,10,400,50);
		puts12(12,13,"һ����",RED,2,2);
		puts12(112,13,"������",RED,2,2);
		puts12(212,13,"ȷ��",RED,2,2);
		puts12(312,13,"�˳�",RED,2,2);
	}
	if(310<mouse_x&&mouse_x<400&&10<mouse_y&&mouse_y<50&&mouseclick)
	{
		buttondown(310,10,400,50);
		button(10,10,100,50);
		button(110,10,200,50);
		button(210,10,300,50);
		puts12(12,13,"һ����",RED,2,2);
		puts12(112,13,"������",RED,2,2);
		puts12(212,13,"ȷ��",RED,2,2);
		puts12(312,13,"�˳�",RED,2,2);
	}
}

void routechoose(int *flag2,int mouse_x,int mouse_y,int mouseclick)
{
	struct route zh[18]={{80,100,"����վ","a"},
				{150,120,"����վ","b"},
				{180,170,"��Էʳ��վ","c"},
				{180,250,"�Ƽ�¥վ","d"},
				{220,280,"��һ¥վ","e"},
				{300,290,"��ʮ��վ","f"},
				{330,320,"��С��վ","g"},
				{340,380,"�в�վ","h"},
				{310,440,"��һʳ��վ","i"},
				{120,450,"����վ","j"},
				{170,430,"��ʮ��վ","k"},
				{140,370,"�پ�԰վ","l"},
				{200,330,"��óվ","m"},
				{220,280,"��һ¥վ","n"},
				{260,220,"��С��վ","o"},
				{300,200,"������վ","p"},
				{350,170,"��԰ʳ��վ","q"},
				{360,120,"����վ","r"}};
	struct route *p;
	//ʵ��ѡ��·��
	if(10<mouse_x&&mouse_x<100&&10<mouse_y&&mouse_y<50&&mouseclick)
	{
		*flag2=1;//ʹѡվ����ʱ�����ػ���·
		setlinestyle(0,0,3);//�ôֵ����߸���ԭ��
		setcolor(LIGHTBLUE);
		moveto(80,100);
		for(p=zh;p<zh+9;p++)
		{
			lineto(p->x,p->y);
		}             
		moveto(120,450);
		for(p=zh+9;p<zh+18;p++)
		{
			lineto(p->x,p->y);
		}       
		setlinestyle(0,0,3);//����ѡ��·
		setcolor(RED);
		moveto(80,100);
		for(p=zh;p<zh+9;p++)
		{
			lineto(p->x,p->y);
		}  
		setlinestyle(0,0,1);//��δ��ѡ��·
		setcolor(BROWN);
		moveto(120,450);
		for(p=zh+9;p<zh+18;p++)
		{
			lineto(p->x,p->y);
		}              
	}  
	if(110<mouse_x&&mouse_x<200&&10<mouse_y&&mouse_y<50&&mouseclick)
	{
		*flag2=1;//ʹѡվ����ʱ�����ػ���·
		setlinestyle(0,0,3);//�ôֵ����߸���ԭ��
		setcolor(LIGHTBLUE);
		moveto(80,100);
		for(p=zh;p<zh+9;p++)
		{
			lineto(p->x,p->y);
		}             
		moveto(120,450);
		for(p=zh+9;p<zh+18;p++)
		{
			lineto(p->x,p->y);
		}   
		
		setlinestyle(0,0,3);//����ѡ��·
		setcolor(BROWN);
		moveto(120,450);
		for(p=zh+9;p<zh+18;p++)
		{
			lineto(p->x,p->y);
		}   
		setlinestyle(0,0,1);//��δ��ѡ��·
		setcolor(RED);
		moveto(80,100);
		for(p=zh;p<zh+9;p++)
		{
			lineto(p->x,p->y);
		}      
	}    
}

void stationchoose(int mouse_x,int mouse_y,int mouseclick,int *flag2,float *money,int z,int *flag,int *forp,int ticnum)
{
	struct route zh[18]={{80,100,"����վ","a"},
				{150,120,"����վ","b"},
				{180,170,"��Էʳ��վ","c"},
				{180,250,"�Ƽ�¥վ","d"},
				{220,280,"��һ¥վ","e"},
				{300,290,"��ʮ��վ","f"},
				{330,320,"��С��վ","g"},
				{340,380,"�в�վ","h"},
				{310,440,"��һʳ��վ","i"},
				{120,450,"����վ","j"},
				{170,430,"��ʮ��վ","k"},
				{140,370,"�پ�԰վ","l"},
				{200,330,"��óվ","m"},
				{220,280,"��һ¥վ","n"},
				{260,220,"��С��վ","o"},
				{300,200,"������վ","p"},
				{350,170,"��԰ʳ��վ","q"},
				{360,120,"����վ","r"}};
				
	struct route *p;	
	
	int num=0;//վ���

	char *mon;//������ʾ����CHAR���ͱ���
	char *tinum;//Ʊ�����ǵ�ַ���Կɸ���
	int dec,sign;//����Ľ�FLOATת��λCHAR����Ҫ�ı���
	float moneyy;//�������*MONEY��ֲ��ʾ����Ļ��
	float ticnumm;//���ڽ���TICNUM������ת��ΪFLOAT�����ڽ�������ת������ʾ
	//ʵ�����ѡվ
	if(mouseclick)
	{
		num=xuanzhan(mouse_x,mouse_y,mouseclick);
		mouseclick=0;
	}
	//ʵ�ּ���ѡվ
	int ch;
	if(kbhit())
	{
		ch=bioskey(0);
		num=kbxuanzhan(ch);
	}

	//ѡվ֮���ˢ�°�ť������·��
	if(num!=0&&num<19)
	{
		*flag=1;//ʹȷ����ť��Ч
		*forp=num-1;
		setfillstyle(1,LIGHTBLUE);//����ԭ��վ��Ʊ��
		bar(460,150,640,180);
		bar(525,190,580,220);
		bar(520,230,580,260);
		*money=ticnum*calculate(num,z);//����Ʊ��
		moneyy=*money;
		mon=fcvt(moneyy,1,&dec,&sign);//��ʾƱ��
		settextstyle(1,0,3);
		outtextxy(535,190,mon);
		if(moneyy<10)
		{
			outtextxy(546,194,".");
		}
		if(moneyy>=10)
		{
			outtextxy(561,194,".");
		}	
		ticnumm=(float)ticnum;
		tinum=fcvt(ticnumm,0,&dec,&sign);
		outtextxy(540,230,tinum);
		passroute(num,z);//����·��
		p=zh+num-1;
		puts12(460,150,p->name,YELLOW,2,2);
		if(*flag2==1)//ˢ�°�ť�ػ���·
		{
		    button(10,10,100,50);
			button(110,10,200,50);
			button(210,10,300,50);
			button(310,10,400,50);
			puts12(12,13,"һ����",RED,2,2);
			puts12(112,13,"������",RED,2,2);
			puts12(212,13,"ȷ��",RED,2,2);
			puts12(312,13,"�˳�",RED,2,2);
			setlinestyle(0,0,3);
			setcolor(LIGHTBLUE);
			moveto(80,100);
			for(p=zh;p<zh+9;p++)
			{
				lineto(p->x,p->y);
			}             
			moveto(120,450);
			for(p=zh+9;p<zh+18;p++)
			{
				lineto(p->x,p->y);
			}       
			setlinestyle(0,0,1);
			setcolor(BROWN);
			moveto(120,450);
			for(p=zh+9;p<zh+18;p++)
			{
				lineto(p->x,p->y);
			}              
			setlinestyle(0,0,1);
			setcolor(RED);
			moveto(80,100);
			for(p=zh;p<zh+9;p++)
			{
				lineto(p->x,p->y);
			}      
			*flag2=0;
		}	
	}
}

void passroute(int num,int z)
{
	int x=num-1;
	int k=0;
	int a1[9]={80,150,180,180,220,300,330,340,310};
	int b1[9]={100,120,170,250,280,290,320,380,440};
	int a2[9]={120,170,140,200,220,260,300,350,360};
	int b2[9]={450,430,370,330,280,220,200,170,120};

	setlinestyle(0,0,1);
	setcolor(RED);
	moveto(a1[0],b1[0]);
	for(k=0;k<9;k++)
	{
		lineto(a1[k],b1[k]);
	}             
	setcolor(BROWN);
	moveto(a2[0],b2[0]);
	for(k=0;k<9;k++)
	{
		lineto(a2[k],b2[k]);
	}       
    
	setlinestyle(0,0,1);
	setcolor(GREEN);	
	if(0<=z&&z<=3)
	{
		if(0<=x&&x<=4)
		{
			moveto(a1[z],b1[z]);
			if(x>z)
			{
				for(k=z;k<=x;k++)
				{
					lineto(a1[k],b1[k]);
				}
			}
			if(z>x)
			{
				for(k=z;k>=x;k--)
				{
					lineto(a1[k],b1[k]);
				}
			}
		}
		if(5<=x&&x<=8)
		{
			moveto(a1[z],b1[z]);
			for(k=z;k<=x;k++)
			{
				lineto(a1[k],b1[k]);
			}
		}
		if(8<x&&x<13)
		{
			moveto(a1[z],b1[z]);
			for(k=z;k<5;k++)
			{
				lineto(a1[k],b1[k]);
			}
			for(k=13;k>=x;k--)
			{
				lineto(a2[k-9],b2[k-9]);
			}
		}
		if(13<x&&x<18)
		{
			moveto(a1[z],b1[z]);
			for(k=z;k<5;k++)
			{
				lineto(a1[k],b1[k]);
			}
			for(k=13;k<=x;k++)
			{
				lineto(a2[k-9],b2[k-9]);
			}
		}
	}
	if(5<=z&&z<=8)
	{
		if(0<=x&&x<=4)
		{
			moveto(a1[z],b1[z]);
			for(k=z;k>=x;k--)
			{
				lineto(a1[k],b1[k]);
			}
		}
		if(5<=x&&x<=8)
		{
			moveto(a1[z],b1[z]);
			if(z>x)
			{
				for(k=z;k>=x;k--)
				{
					lineto(a1[k],b1[k]);
				}
			}
			if(z<x)
			{
				for(k=z;k<=x;k++)
				{
					lineto(a1[k],b1[k]);
				}
			}
		}
		if(8<x&&x<13)
		{
			moveto(a1[z],b1[z]);
			for(k=z;k>=4;k--)
			{
				lineto(a1[k],b1[k]);
			}
			for(k=13;k>=x;k--)
			{
				lineto(a2[k-9],b2[k-9]);
			}
		}
		if(13<x&&x<18)
		{
			moveto(a1[z],b1[z]);
			for(k=z;k>=4;k--)
			{
				lineto(a1[k],b1[k]);
			}
			for(k=13;k<=x;k++)
			{
				lineto(a2[k-9],b2[k-9]);
			}
		}
	}
	if(9<=z&&z<=12)
	{
		if(0<=x&&x<=4)
		{
			moveto(a2[z-9],b2[z-9]);
			for(k=z;k<=13;k++)
			{
				lineto(a2[k-9],b2[k-9]);
			}
			for(k=4;k>=x;k--)
			{
				lineto(a1[k],b1[k]);
			}
		}
		if(5<=x&&x<=8)
		{
			moveto(a2[z-9],b2[z-9]);
			for(k=z;k<=13;k++)
			{
				lineto(a2[k-9],b2[k-9]);
			}
			for(k=4;k<=x;k++)
			{
				lineto(a1[k],b1[k]);
			}
		}
		if(9<=x&&x<=12)
		{
			moveto(a2[z-9],b2[z-9]);
			if(z>x)
			{	
				for(k=z;k>=x;k--)
				{
					lineto(a2[k-9],b2[k-9]);
				}
			}
			if(z<x)
			{
				for(k=z;k<=x;k++)
				{
					lineto(a2[k-9],b2[k-9]);
				}
			}
		}
		if(14<=x&&x<=17)
		{
			moveto(a2[z-9],b2[z-9]);
			for(k=z;k<=x;k++)
			{
				lineto(a2[k-9],b2[k-9]);
			}
		}
	}
	if(14<=z&&z<=17)
	{
		if(0<=x&&x<=4)
		{
			moveto(a2[z-9],b2[z-9]);
			for(k=z;k>=13;k--)
			{
				lineto(a2[k-9],b2[k-9]);
			}
			for(k=4;k>=x;k--)
			{
				lineto(a1[k],b1[k]);
			}
		}
		if(5<=x&&x<=8)
		{
			moveto(a2[z-9],b2[z-9]);
			for(k=z;k>=13;k--)
			{
				lineto(a2[k-9],b2[k-9]);
			}
			for(k=4;k<=x;k++)
			{
				lineto(a1[k],b1[k]);
			}
		}
		if(9<=x&&x<=12)
		{
			moveto(a2[z-9],b2[z-9]);
			for(k=z;k>=x;k--)
			{
				lineto(a2[k-9],b2[k-9]);
			}
		}
		if(14<=x&&x<=17)
		{
			moveto(a2[z-9],b2[z-9]);
			if(z>x)
			{
				for(k=z;k>=x;k--)
				{
					lineto(a2[k-9],b2[k-9]);
				}
			}
			if(z<x)
			{
				for(k=z;k<=x;k++)
				{
					lineto(a2[k-9],b2[k-9]);
				}
			}
		}
	}
	if(z==4||z==13)
	{
		moveto(a1[4],b1[4]);
		if(0<=x&&x<=3)
		{
			for(k=4;k>=x;k--)
			{
				lineto(a1[k],b1[k]);
			}
		}
		if(5<=x&&x<=8)
		{
			for(k=4;k<=x;k++)
			{
				lineto(a1[k],b1[k]);
			}
		}
		if(9<=x&&x<=12)
		{
			for(k=13;k>=x;k--)
			{
				lineto(a2[k-9],b2[k-9]);
			}
		}
		if(14<=x&&x<=17)
		{
			for(k=13;k<=x;k++)
			{
				lineto(a2[k-9],b2[k-9]);
			}
		}
	}
}


void ticketnum(int mouse_x,int mouse_y,int mouseclick,int *ticnum,float *money)
{
	char *mon;
	char *tinum;
	int dec,sign;
	float moneyy;//�������*MONEY��ֲ��ʾ����Ļ��
	float ticnumm;
	int k;
	float t;
	float m;
	k=*ticnum;
	t=(float)k;
	m=(*money)/t;
	int flag3;

	if(495<mouse_x&&mouse_x<510&&235<mouse_y&&mouse_y<255&&mouseclick&&k>1)
	{
		*ticnum=k-1;
		mouseclick=0;
		flag3=1;
		delay(300);
		
	}
	if(585<mouse_x&&mouse_x<600&&235<mouse_y&&mouse_y<255&&mouseclick&&k<9)
	{
		*ticnum=k+1;
		mouseclick=0;
		flag3=1;
		delay(300);
		
	}	
	if(flag3==1)
	{
		setfillstyle(1,LIGHTBLUE);
		bar(525,190,580,222);
		bar(520,230,580,260);
		ticnumm=(float)(*ticnum);
		*money=ticnumm*m;//����Ʊ��
		moneyy=*money;
		mon=fcvt(moneyy,1,&dec,&sign);//��ʾƱ��
		settextstyle(1,0,3);
		outtextxy(535,190,mon);
		if(moneyy<10)
		{
			outtextxy(546,194,".");
		}
		if(moneyy>=10)
		{
			outtextxy(561,194,".");
		}	
		ticnumm=(float)(*ticnum);
		tinum=fcvt(ticnumm,0,&dec,&sign);
		outtextxy(540,230,tinum);
		flag3=0;
	}
}