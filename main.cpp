#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include <windows.h>

 
#define bx 20
#define by 20
#define DOLU 'o'
#define BOS  ' '
#define YEM  'x'
#define hiz 100
 


int skor=0;
char tahta[bx][by];
int  yilan[2][bx*by];
bool durmusmu=false;
char sonyon;
int yilan_uzunlugu=4;
int durum=2;
int yem_x;
int yem_y;
 
void yilan_yon(char &c);
void tahta_yazdir();
void tahta_temizle();
bool tahta_icinde_mi(int x,int y);
bool yilan_icinde_mi(int x,int y);
void yilan_yerlestir();
void yilan_hareket(int yon);
void yem_uret();
bool yem_var_mi(int x,int y);
bool engel_var_mi(int x,int y);
void yandin();
void durdur(char &c);


// Color functions

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 

void sp(int skor)
{
	if(skor<200) SetConsoleTextAttribute(hStdout, FOREGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY);
    else SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY);
}
void s()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    //FUNCTION TO ..EHM FORGET COLOR,not sure how to say I know: Stop using color
}

int main()
{
    srand(time(NULL));
    yem_uret();
    //
    yilan[0][0]=9;yilan[1][0]=9;
    yilan[0][1]=9;yilan[1][1]=10;
    yilan[0][2]=9;yilan[1][2]=11;
    yilan[0][3]=9;yilan[1][3]=12;
    //
    char c='d';
    while(c!=27)
    {
        Sleep(hiz);
        tahta_temizle();
        yilan_yerlestir();
        tahta[yem_x][yem_y]=YEM;
        tahta_yazdir();
        yilan_yon(c);
        if(c=='w')
        {
            if(yem_var_mi(yilan[0][yilan_uzunlugu-1]-1,yilan[1][yilan_uzunlugu-1])==true)
            {
                yilan[0][yilan_uzunlugu]=yem_x;
                yilan[1][yilan_uzunlugu]=yem_y;
                yilan_uzunlugu++;
                yem_uret();
                if(skor<200) skor+=10;
                else skor+=20;
            }
            if(engel_var_mi(yilan[0][yilan_uzunlugu-1]-1,yilan[1][yilan_uzunlugu-1]) || durum==3 || tahta_icinde_mi(yilan[0][yilan_uzunlugu-1]-1,yilan[1][yilan_uzunlugu-1])==false || yilan_icinde_mi(yilan[0][yilan_uzunlugu-1]-1,yilan[1][yilan_uzunlugu-1])==false)
            {
                yandin();
            }
            durum=1;
            yilan_hareket(durum);
        }
        else if(c=='a')
        {
            if(yem_var_mi(yilan[0][yilan_uzunlugu-1],yilan[1][yilan_uzunlugu-1]-1)==true)
            {
                yilan[0][yilan_uzunlugu]=yem_x;
                yilan[1][yilan_uzunlugu]=yem_y;
                yilan_uzunlugu++;
                yem_uret();
                if(skor<200) skor+=10;
                else skor+=20;
            }
            if(engel_var_mi(yilan[0][yilan_uzunlugu-1],yilan[1][yilan_uzunlugu-1]-1) || durum==2 || tahta_icinde_mi(yilan[0][yilan_uzunlugu-1],yilan[1][yilan_uzunlugu-1]-1)==false || yilan_icinde_mi(yilan[0][yilan_uzunlugu-1],yilan[1][yilan_uzunlugu-1]-1)==false)
            {
                yandin();
            }
            durum=4;
            yilan_hareket(durum);
        }
        else if(c=='s')
        {
            if(yem_var_mi(yilan[0][yilan_uzunlugu-1]+1,yilan[1][yilan_uzunlugu-1])==true)
            {
                yilan[0][yilan_uzunlugu]=yem_x;
                yilan[1][yilan_uzunlugu]=yem_y;
                yilan_uzunlugu++;
                yem_uret();
                if(skor<200) skor+=10;
                else skor+=20;
            }
            if(engel_var_mi(yilan[0][yilan_uzunlugu-1]+1,yilan[1][yilan_uzunlugu-1]) || durum==1 || tahta_icinde_mi(yilan[0][yilan_uzunlugu-1]+1,yilan[1][yilan_uzunlugu-1])==false || yilan_icinde_mi(yilan[0][yilan_uzunlugu-1]+1,yilan[1][yilan_uzunlugu-1])==false)
            {
                yandin();
            }
            durum=3;
            yilan_hareket(durum);
        }
        else if(c=='d')
        {
            if(yem_var_mi(yilan[0][yilan_uzunlugu-1],yilan[1][yilan_uzunlugu-1]+1)==true)
            {
                yilan[0][yilan_uzunlugu]=yem_x;
                yilan[1][yilan_uzunlugu]=yem_y;
                yilan_uzunlugu++;
                yem_uret();
                if(skor<200) skor+=10;
                else skor+=20;
            }
            if(engel_var_mi(yilan[0][yilan_uzunlugu-1],yilan[1][yilan_uzunlugu-1]+1) || durum==4 || tahta_icinde_mi(yilan[0][yilan_uzunlugu-1],yilan[1][yilan_uzunlugu-1]+1)==false || yilan_icinde_mi(yilan[0][yilan_uzunlugu-1],yilan[1][yilan_uzunlugu-1]+1)==false)
            {
                yandin();
            }
            durum=2;
            yilan_hareket(durum);
        }
        else {}
 
    }
    return 0;
}
 
void tahta_yazdir()
{
	if(skor>190){
			tahta[10][10]='#';	
			tahta[11][10]='#';
			tahta[12][10]='#';
	}
	if(skor>390){
			tahta[10][5]='#';	
			tahta[11][5]='#';
			tahta[12][5]='#';
	}
	
        
    system("cls");
    std::cout<<"YILAN OYUNU"<<std::endl<<"(Dur/Devam ESC) Skor : "<<skor<<std::endl;
   
    std::cout<<std::endl;
    for(int i=0;i<bx;i++)
    {
        for(int j=0;j<by;j++)
        {
            sp(skor);
            std::cout<<tahta[i][j];
            s();
        }
        std::cout<<std::endl;
    }
    
}
 
void tahta_temizle()
{
    for(int i=0;i<bx;i++)
    {
        for(int j=0;j<by;j++)
        {
            tahta[i][j]=BOS;
        }
    }
}
 
bool yilan_icinde_mi(int x,int y)
{
    for(int i=0;i<yilan_uzunlugu;i++)
    {
        if(x==yilan[0][i] && y==yilan[1][i])
        {
            return false;
        }
    }
    return true;
}
 
bool tahta_icinde_mi(int x,int y)
{
    for(int i=0;i<=by-1;i++)
    {
        if(x==-1 && i==y)
        {
            return false;
        }
    }
 
    for(int i=0;i<=by-1;i++)
    {
        if(x==bx && i==y)
        {
            return false;
        }
    }
 
    for(int i=0;i<=bx-1;i++)
    {
        if(y==by && i==x)
        {
            return false;
        }
    }
 
    for(int i=0;i<=bx-1;i++)
    {
        if(y==-1 && i==x)
        {
            return false;
        }
    }
    return true;
}
 
void yilan_yerlestir()
{
    for(int i=0;i<yilan_uzunlugu;i++)
    {
        tahta[yilan[0][i]][yilan[1][i]]=DOLU;
    }
}
 
void yilan_hareket(int yon)
{
    if(yon==1)
    {
        int yilan_son_x=yilan[0][yilan_uzunlugu-1];
        int yilan_son_y=yilan[1][yilan_uzunlugu-1];
 
        int yilan_ilk_x=yilan[0][0];
        int yilan_ilk_y=yilan[1][0];
 
        for(int i=0;i<yilan_uzunlugu-1;i++)
        {
            yilan[0][i]=yilan[0][i+1];
            yilan[1][i]=yilan[1][i+1];
        }
 
        yilan[0][yilan_uzunlugu-1]--;
 
 
    }
    else if(yon==2)
    {
        int yilan_son_x=yilan[0][yilan_uzunlugu-1];
        int yilan_son_y=yilan[1][yilan_uzunlugu-1];
 
        int yilan_ilk_x=yilan[0][0];
        int yilan_ilk_y=yilan[1][0];
 
        for(int i=0;i<yilan_uzunlugu-1;i++)
        {
            yilan[0][i]=yilan[0][i+1];
            yilan[1][i]=yilan[1][i+1];
        }
 
        yilan[1][yilan_uzunlugu-1]++;
    }
    else if(yon==3)
    {
        int yilan_son_x=yilan[0][yilan_uzunlugu-1];
        int yilan_son_y=yilan[1][yilan_uzunlugu-1];
 
        int yilan_ilk_x=yilan[0][0];
        int yilan_ilk_y=yilan[1][0];
 
        for(int i=0;i<yilan_uzunlugu-1;i++)
        {
            yilan[0][i]=yilan[0][i+1];
            yilan[1][i]=yilan[1][i+1];
        }
 
        yilan[0][yilan_uzunlugu-1]++;
    }
    else if(yon==4)
    {
        int yilan_son_x=yilan[0][yilan_uzunlugu-1];
        int yilan_son_y=yilan[1][yilan_uzunlugu-1];
 
        int yilan_ilk_x=yilan[0][0];
        int yilan_ilk_y=yilan[1][0];
 
        for(int i=0;i<yilan_uzunlugu-1;i++)
        {
            yilan[0][i]=yilan[0][i+1];
            yilan[1][i]=yilan[1][i+1];
        }
 
        yilan[1][yilan_uzunlugu-1]--;
    }
}
 
bool yem_var_mi(int x,int y)
{
    if(x==yem_x && y==yem_y)
    {
        return true;
    }
    return false;
}

bool engel_var_mi(int x,int y){
	
	if(skor<400 && skor>200){
		if((x==10 && y==10) || (x==11 && y==10) || (x==12 && y==10)){
			return true;		
		}else return false;
	}
	if(skor>390){
		if((x==10 && y==5) || (x==11 && y==5) || (x==12 && y==5)){
			return true;		
		}else return false;
	}else return false;

}

 
void yilan_yon(char &c)
{
    int tus;
    if (kbhit())
    {
        tus = getch();
        switch(tus)
        {
            case 72:
                c = 'w';
                break;
            case 77:
                c = 'd';
                break;
            case 80:
                c = 's';
                break;
            case 75:
                c = 'a';
                break;
            case 27:
                durdur(c);
                break;
        }
    }
}
 
void yandin()
{
    std::cout<<std::endl<<"Oyun Bitti, Skor:"<<skor;
    Sleep(5000);
    exit(0);
}
 
void durdur(char &c)
{
    if(durmusmu==false)
    {
        sonyon=c;
        c=' ';
        durmusmu=true;
    }
    else
    {
        c=sonyon;
        durmusmu=false;
    }
}
 
void yem_uret()
{
    while(1)
    {
        yem_x=rand()%19+0;
        yem_y=rand()%19+0;
        if(yilan_icinde_mi(yem_x,yem_y)==true)
        {
            break;
        }
    }
}
