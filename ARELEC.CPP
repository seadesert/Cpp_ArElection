//Header Files
#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fstream.h>
#include <graphics.h>
//Special characters
#define keyEsc 27
#define keyCr 13
void showmouseptr();
int exit();
int  initmouse();
void hidemouse();
void but();
void clrwin(int select);
void setmousepos(int &xpos,int &ypos);
void getmousepos(int *buttonm,int *x, int *y);
int  navui(int option);
int  voterlist();
void status();
int  start();
void defaultscreen();
int beep();
int result();
int setchoice();
void setpass();
int security();
int startpage();
void nominee();
int cadreg();
void vgf1();
void vgf2();
void vgf3();
void vgf4();
void vgf5();
void vgf6();
int result2();
int collectvote();
void setting();
void nominee();
void drawwindow();
int exitsecurity();
void about();
int menu(int select);
int midx=320;
int midy=239;
union REGS i,o;
int vote;
char cd1[20],cd2[20],cd3[20],cd4[20],cd5[20],cd6[20];
char cl1[5],cl2[5],cl3[5],cl4[5],cl5[5];
double cv1=0,cv2=0,cv3=0,cv4=0,cv5=0,cv6=0;
char pin='*';
char exitpin='-';
int totalvotes=0;
char Char;
int main()
{
     int buttonm,xm,ym;
     int option=0,ch;
     int status, gd= DETECT, gm= DETECT;
     initgraph(&gm,&gm,"..\\bgi");
     status = initmouse();
     startpage();

}
int setchoice()
{       int buttonm=0,xm,ym;
	int option=0,ch;

	navui(option);
	while(1){
  getmousepos(&buttonm,&xm,&ym);

  if(buttonm==1){
   if(xm>=19&&xm<=76&&ym>=60&&ym<=88){
    option=1;
   }else if(xm>=77&&xm<=256&&ym>=60&&ym<=88){
    option=2;
   }else if(xm>=257&&xm<=407&&ym>=60&&ym<=88){
    option=3;
   }else if(xm>=408&&xm<=505&&ym>=60&&ym<=88){
    option=4;
   }else if(xm>=506&&xm<=620&&ym>=60&&ym<=88){
    option=5;
   }else option=0;
   navui(option);
   switch(option){
    case 0:defaultscreen();break;
    case 1:cleardevice();closegraph();exit(); return 0;break;
    case 2:setpass();break;
    case 3:result();break;
    case 4:start();break;
    case 5:about();break;
   }
  }
 }
}
void setpass()
{ drawwindow();
  setcolor(BLACK);
  outtextxy(276,186,"SECURITY_TERMINAL");
  setcolor(WHITE);
  // Press security_passkey after each vote, used to disable multiple votes from a same voter
  outtextxy(164,252,"ENTER THE NEW SECURITY_PASSKEY: (DEFAULT :'*')");
  getch();
  Char=getch();
  pin=Char;
  outtextxy(164,282,"SECURITY_KEY SUCCESFULLY RECORDED");
  showmouseptr();
  // Press exit_passkey on the voting screen to exit
  outtextxy(164,313,"ENTER THE EXIT_PASSKEY: (DEFAULT :'-')");
  getch();
  Char=getch();
  exitpin=Char;
  outtextxy(164,343,"EXIT_KEY SUCCESFULLY RECORDED");
}

int start()
{	cleardevice();
	int maxx,maxy;
	struct totalvotes tv;
	maxx=getmaxx();
	maxy=getmaxy();
	setfillstyle(1,8);
	bar (0,0,maxx,maxy);
	setfillstyle(1,3);
	bar(0,0,639,35);
	setfillstyle(1,RED);
	bar(592,0,639,35);
	setcolor(WHITE);
	line (602,7,626,27);
	line (626,7,602,27);
	setfillstyle(1,LIGHTBLUE);
	bar (5,46,635,88);
	bar (5,96,635,138);
	bar (5,146,635,188);
	bar (5,197,635,239);
	bar (5,248,635,290);
	bar (5,299,635,341);
	bar (5,300,635,341);
	bar (7,356,629,461);
	setfillstyle(1,CYAN);
	bar (532,46,635,88);
	bar (532,96,635,138);
	bar (532,146,635,188);
	bar (532,197,635,239);
	bar (532,248,635,290);
	bar (532,299,635,341);
	bar (532,300,635,341);
	bar (7,356,629,386);
	setfillstyle(1,LIGHTGREEN);
	bar (502,356,567,386);
	setcolor(WHITE);
	settextstyle(2,0,5);
	int midx=getmaxx()/2;
	outtextxy(midx-140,20,"=== Student Council Election 2017 ===");
	setcolor(15);
	settextstyle(2,0,5);
	outtextxy(550,63, "VOTE");
	outtextxy(550,110,"VOTE");
	outtextxy(550,160,"VOTE");
	outtextxy(550,213,"VOTE");
	outtextxy(550,263,"VOTE");
	outtextxy(550,312,"VOTE");       //****************** THE FOLLOWING ARE TO BE CHANGED ***********************
	outtextxy(39,60, "Candidate 1:  ABDUL RAHIM SHAIKH MP,XII A  Symbol: CANDLE ");
	outtextxy(39,105,"Candidate 2:  KIRAN RAVINDRA GADAGKAR,XI B Symbol:TICK MARK ");
	outtextxy(39,160,"Candidate 3:  SACHIN SURYA KR,XII B        Symbol: RING ");
	outtextxy(39,210,"Candidate 4:  SATWIK BM,X A               Symbol: BAT AND BALL");
	outtextxy(39,260,"Candidate 5:  UTHISTHA B,IX A              Symbol: BULB");
	outtextxy(39,310,"Candidate 6:  NOTA                        Symbol: NOTA");
	setcolor(LIGHTGREEN);
	setcolor(WHITE);
	settextstyle(2,0,5);
	outtextxy(60,362,"console");
    outtextxy(390,362,"status:");

    showmouseptr();
    setmousepos(midx,midy);
    collectvote();
}
collectvote()
{
	int buttonm,xm,ym;
	while(1){
  getmousepos(&buttonm,&xm,&ym);
  if(buttonm==1){
   if(xm>=532&&xm<=634&&ym>=46&&ym<=88){
    vote=1;vgf1();beep();status();
   }else if(xm>=532&&xm<=634&&ym>=96&&ym<=138){
    vote=2;vgf2();beep();status();
   }else if(xm>=532&&xm<=634&&ym>=147&&ym<=188){
    vote=3;vgf3();beep();status();
   }else if(xm>=532&&xm<=634&&ym>=197&&ym<=239){
    vote=4;vgf4();beep();status();
   }else if(xm>=532&&xm<=634&&ym>=248&&ym<=291){
    vote=5;vgf5();beep();status();
   }else if(xm>=532&&xm<=634&&ym>=299&&ym<=341){
    vote=6;vgf6();beep();status();
   }else if(xm>=593&&xm<=638&&ym>=0&&ym<=35){
   vote=7;
   } else vote=0;
   switch(vote){
    case 0:outtextxy(42,400,"ILLEGAL COMMAND : Try Again" );start();break;
    case 1:outtextxy(42,390,"SUCCESFULLY VOTED FOR CAND_1");delay(3000);cv1++;totalvotes++;security();break;
    case 2:outtextxy(42,390,"SUCCESFULLY VOTED FOR CAND_2");delay(3000);cv2++;totalvotes++;security();break;
    case 3:outtextxy(42,390,"SUCCESFULLY VOTED FOR CAND_3");delay(3000);cv3++;totalvotes++;security();break;
    case 4:outtextxy(42,390,"SUCCESFULLY VOTED FOR CAND_4");delay(3000);cv4++;totalvotes++;security();break;
    case 5:outtextxy(42,390,"SUCCESFULLY VOTED FOR CAND_5");delay(3000);cv5++;totalvotes++;security();break;
    case 6:outtextxy(42,390,"SUCCESFULLY VOTED FOR NOTA");delay(3000);cv6++;totalvotes++;security(); break;
    case 7:exitsecurity(); break;
   }
  }
 }
    result();
}
void about()
{ settextstyle(2,0,5);
  drawwindow();
  setcolor(BLACK);
  outtextxy(140,186,"                    About");
  setcolor(WHITE);
  outtextxy(140,251,"Developer:          Arun Sri Krishna, XII Science");
  outtextxy(140,314,"Developed for:      Demonstration School, Mysore");
  outtextxy(140,282,"Title:              ARGANISA E-VOTER ver.2.0");
  outtextxy(140,331,"Date:               19/07/2017 ");
  outtextxy(140,360,"Developed Using:    C++");
  getch();
  showmouseptr();
 }
int startpage()
{   int maxx=getmaxx(),maxy=getmaxy();
    cleardevice();
    setfillstyle(1,LIGHTBLUE);
 bar(0,0,getmaxx(),getmaxy());
 setcolor(WHITE);
 settextstyle(4, 0, 6);
 outtextxy((getmaxx()-textwidth("Arganisa"))/3,100,"Arganisa");
 settextstyle(3, 0, 6);
 outtextxy((getmaxx()-textwidth("Election"))/3,200,"Election");
 outtextxy((getmaxx()-textwidth("Program"))/3,300,"Program");
 setfillstyle(1,BLUE);
 bar(getmaxx()-150,200,getmaxx()-12,237);
 settextstyle (3,0,2);
 outtextxy(getmaxx()-110,205,"Start");
 showmouseptr();
 int buttonm,xm,ym;
 setcolor(WHITE);
 line(getmaxx()-180,0,getmaxx()-180,getmaxy());
 setmousepos(midx,midy);
  while (1)
  { getmousepos(&buttonm,&xm,&ym);
  if(buttonm==1&&xm>=getmaxx()-150&&xm<=getmaxx()+8&&ym>=200&&ym<=237)
   setchoice();
  }
 }

int navui(int option) { but();
 char ch, menu[6][20]={"EXIT","SECURITY_TERMINAL","RESULT","START","ABOUT",""};
 char date[11];
 struct date da;
 hidemouse();
 int maxx=getmaxx();
 int maxy=getmaxy();

 setfillstyle (1,WHITE);
 bar (0,0,maxx,maxy);
 setfillstyle(1,LIGHTBLUE);
 bar (19,30,619,88);
 setfillstyle(1,8);
 bar (19,89,619,459);
 setfillstyle (1,3);
 bar (19,60,76,88);
 bar (77,60,255,88);
 bar (255,60,406,88);
 bar (407,60,504,88);
 bar (505,60,619,88);
 settextstyle(2,0,5);
 setcolor(WHITE);
 outtextxy(midx-130,40,"=== Student Council Election 2017 ===");
 getdate(&da);
 setcolor(WHITE);
 settextstyle(2,0,4);
 outtextxy(37,72,menu[0]);
 outtextxy(120,72,menu[1]);
 outtextxy(300,72,menu[2]);
 outtextxy(440,72,menu[3]);
 outtextxy(545,72,menu[4]);

 showmouseptr();
 setcolor(WHITE);
 line (76,88,76,59);
 line (19,59,619,59);
 line (77,59,77,88);
 line (255,60,255,88);
 line (256,88,256,60);
 line (406,88,406,60);
 line (407,60,407,88);
 line (504,60,504,88);
 line (505,88,505,60);




  setcolor(1);
  switch(option){
   case 2: hidemouse();
    outtextxy(120,72,menu[1]);
    break;
   case 3: hidemouse();
    outtextxy(300,72,menu[2]);
    break;
   case 4: hidemouse();
    outtextxy(440,72,menu[3]);
    break;
   case 5: hidemouse();
    outtextxy(545,72,menu[4]);
    break;
  }
  sprintf(date,"%02d/%02d/%d",da.da_day,da.da_mon,da.da_year);
  setcolor(0);
  outtextxy(550,40,date);
 return option;
}


//Mouse functions
int initmouse()
{
     i.x.ax = 0;
     int86(0X33,&i,&o);
     return (o.x.ax);
}
void showmouseptr()
{
    i.x.ax = 1;
    int86(0X33,&i,&o);

}
void hidemouse()
{
    i.x.ax=2;
    int86(0x33,&i,&o);
}
void setmousepos(int &xpos,int &ypos)
{
 i.x.ax=4;
 i.x.cx=xpos;
 i.x.dx=ypos;
 int86(0x33,&i,&o);
}
void getmousepos(int *buttonm,int *x, int *y)
{
 i.x.ax=3;
 int86(0x33,&i,&o);
 *buttonm=o.x.bx;
 *x=o.x.cx;
 *y=o.x.dx;
}

void but()
{
}

int exit()
{
setchoice();
}

//Beep sound function
int beep()
{
  sound(600);
  delay(3000);
  nosound();
}

void status()
{
setfillstyle(1,RED);
bar (502,356,567,386);
}
int result()
{
 cleardevice();
 closegraph();
 textbackground(WHITE);
 window(1,1,80,25);
 clrscr();
 textbackground(MAGENTA);
 window(2,2,79,24);
 clrscr();
 textcolor(WHITE);
clrscr();
cout<<endl<<endl<<endl;
gotoxy(5,5);
cout<<"\t\t\t\t      Results \n";
cout<<" ------------------------------------------------------------------------------";
cout<<endl<<endl;
cout<<"\t\t    Total votes : "<<totalvotes<<endl<<endl;
//********************* THE FOLLOWING NAMES ARE TO BE CHANGED ************************************
cout<<"\t\t"<<"Candidate 1\tABDUL RAHIM SHAIKH MP  "<<" : "<<cv1<<endl<<endl;
cout<<"\t\t"<<"Candidate 2\tKIRAN RAVINDRA GADAGKAR"<<" : "<<cv2<<endl<<endl;
cout<<"\t\t"<<"Candidate 3\tSACHIN SURYA KR        "<<" : "<<cv3<<endl<<endl;
cout<<"\t\t"<<"Candidate 4\tSATWIK BM	       "<<" : "<<cv4<<endl<<endl;
cout<<"\t\t"<<"Candidate 5\tUTHISTHA B            "<<" : "<<cv5<<endl<<endl;
cout<<"\t\t"<<"NOTA                                   "<<" : "<<cv6<<endl<<endl;
getch();
clrscr();
 textbackground(WHITE);
 window(1,1,80,25);
 clrscr();
 textbackground(LIGHTMAGENTA);
 window(2,2,79,24);
 clrscr();
gotoxy(5,5);
cout<<"Do You Want to Save the Current Result(s) : (1=YES, 2=NO) : ";
char inup;
cin>>inup;
if (inup=='1')
{
gotoxy(5,6);
cout<<"Enter the Class : ";
char class1[5];
char class2;
cin>>class1;
gotoxy(5,7);
cout<<"Enter the Section : ";
cin>>class2;
ofstream myfile ("result.txt",ofstream::app);

//********************* THE FOLLOWING NAMES ARE TO BE CHANGED ************************************
	 myfile<<"\n HEAD-BOY ELECTION - 2017 \n";
	 myfile<<"\n Class :  "<<class1<<"\n Section:  "<<class2<<" \n\n\n";
	 myfile<<" CAND 1: ABDUL RAHIM SHAIKH MP   = "<<cv1<<"\n";
	 myfile<<" CAND 2: KIRAN RAVINDRA GADAGKAR = "<<cv2<<"\n";
	 myfile<<" CAND 3: SACHIN SURYA KR 	  = "<<cv3<<"\n";
	 myfile<<" CAND 4: SATWIK BM 		  = "<<cv4<<"\n";
	 myfile<<" CAND 5: UTHISTHA B 		  = "<<cv5<<"\n";
	 myfile<<" NOTA  :  			  ="<<cv6<<"\n";
}
gotoxy(5,8);
cout<<"Do You Want to Reset the Voting Counter? (1=YES, 2=NO):";
char opt123;
cin>>opt123;
if (opt123=='1')
{
   cv1=0,cv2=0,cv3=0,cv4=0,cv5=0,cv6=0;
}

int status, gd= DETECT, gm= DETECT;
     initgraph(&gm,&gm,"..\\bgi");
	showmouseptr();
exit();
}
int security()
{
outtextxy(42,420,"ENTER THE SECURITY PIN :");Char=getch(); if (Char==pin) {start();} else { outtextxy(42,440,"INVALID SECURITY PIN! RE-ENTER THE PIN"); security(); }
}
int exitsecurity()
{
outtextxy(42,420,"ENTER THE EXIT PIN :");
getch(); Char=getch(); if (Char==exitpin) { result();} else start();
}

void drawwindow()
{
   setmousepos(0,0);
   setfillstyle(1,LIGHTGRAY);
   bar(40,162,590,430);
   setfillstyle(1,LIGHTBLUE);
   bar(40,162,590,206);
}

//Home page or Instructions page
void defaultscreen()
{  setmousepos(midx,midy);
   drawwindow();
   setcolor(WHITE);
   outtextxy(250,186," Instructions");
   outtextxy(100,230," Arganisa E-Voter is a easy to use and build for reliabilty and convience");
   outtextxy(100,250," All you need to do is Click On 'VOTE' Button for your respective candidate");
   outtextxy(100,270," You wish to vote, And make sure that the status bar AFTER voting");
   outtextxy(100,290," turns RED , and BEFORE voting it is GREEN");
   outtextxy(100,330," Happy Voting!");
   outtextxy(300,340," -Arun Sri Krishna");

}

void vgf1()
{
	setfillstyle(1,12);
	setmousepos(midx,midy);
	bar (532,46,635,88);
	outtextxy(550,63, "VOTE");
}
void vgf2()
{
	setfillstyle(1,12);
	setmousepos(midx,midy);
	bar (532,96,635,138);
	outtextxy(550,110,"VOTE");
}
void vgf3()
{   setfillstyle(1,12);
	setmousepos(midx,midy);
	bar (532,146,635,188);
	outtextxy(550,160,"VOTE");
}
void vgf4()
{   setfillstyle(1,12);
	setmousepos(midx,midy);
	bar (532,197,635,239);
	outtextxy(550,213,"VOTE");
}
void vgf5()
{   setfillstyle(1,12);
	setmousepos(midx,midy);
	bar (532,248,635,290);
	outtextxy(550,263,"VOTE");
}
void vgf6()
{   setfillstyle(1,12);
	setmousepos(midx,midy);
	bar (532,300,635,341);
	outtextxy(550,312,"VOTE");
}
