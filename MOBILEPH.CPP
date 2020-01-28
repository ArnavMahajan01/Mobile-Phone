
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<fstream.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>
#include<graphics.h>
void displayOnce();
void drawLine();
int menu();
int option();
int option2();
void shutdown();
int passCheck();
void Messaging();
void WriteMsg();
void outbox();
void Mcontact();
void SaveContact();
int OpenContact();
void Msettings();
void changePass();
void ChangeUser();
void ChangeMode();
void calci();
void organiser();
void timer();
void stopwatch();

int choice1;
char list[100][50];
char listNum[100][50];
time_t now=time(0);
char* dt=ctime(&now);
char password[1][10] = { "Yash21" };
char mode[1][10]={"General"};
int imode=1;
char Epassword[1][10];
int i=0;
int dispOnce_flag=0;
char Euser[1][10]={" Vardhan "};
void main() {


	for(int xyz=0;;xyz++)
	{
		rePass: clrscr();
		dispOnce_flag++;
		if(dispOnce_flag<2)
		{

			displayOnce();
		}
		drawLine();
		passCheck();
		option();

		getch();
	}

}
void displayOnce() {

	clrscr();
	printf("\t\t\tWELCOME!!!\n");
	printf("\nUse Default password as 'Yash21', it can be changed later\n");

	getch();

}

void drawLine() {
	for(int Dl=0;Dl<=25;Dl++)
		cout<<"---";
	cout<<endl;
}
void disp()
{
	drawLine();

	cout<<setw(12)<<"User"<<setw(27)<<"Time"<<setw(30)<<"Mode"<<endl;
	cout<<setw(50)<<dt<<setw(15)<<Euser[0]<<setw(55)<<mode[0]<<endl;
	drawLine();
}
int passCheck() {
	start: system("cls");
	disp();

	char Epassword[1][10];
	cout<<"Forgot Password? : Press ESC"<<endl;
	cout << "Enter PassWord   : ";
	for (int i = 0;; i++) {
		char ch;
		ch = getch();
		if(int(ch)==27)
			shutdown();

		if (isalnum(ch)) {
			Epassword[0][i] = ch;
			cout << ch;
			delay(50);
			cout << '\b';
			cout << 'X';
		}
		if (ch == '\b') {
			cout << '\b';
			cout<<" ";
			cout<<'\b';
			i--;
			i--;
		}
		Epassword[0][i+1]='\0';

		if (strcmp(Epassword[0], password[0]) == 0) {
			cout << "\nPhone Unlocked";
			return 0;
		}
		else
			if(strlen(Epassword[0]) >= strlen(password[0])  )
			{
				cout << "\nDo not match Try again :";
				delay(1500);
				goto start;
			}
	}

}

int option() {
	delay(1500);

	re: clrscr();
	disp();
	printf("1)Menu \t\t  2)ShutDown \t\t 3) Lock Phone\n");
	int ch;
	ch=getch()-48;
	clrscr();
	switch (ch) {
	case 1: option2();
	break;
	case 2:
		shutdown();
		break;
	case 3:main();
	break;
	default:
		printf("Wrong input....Input again");
		goto re;
	}
	return 0;
}
int option2()
{
	clrscr();
	printf("Press ESC to go back to previous menu\n");
	drawLine();
	printf("\t\t\tEnter Your Choice \n\n\t\t1)Messaging   2)Contacts   3)Calculator\n");
	printf("          \t\t 4)Settings   5)Organiser\n");
	drawLine();
	int in_choice;
	in_choice=getch();
	if(in_choice==27)
		option();
	else in_choice-=48;
	switch(in_choice)
	{
	case 1: Messaging();
	break;
	case 2:Mcontact();
	break;
	case 3:calci();
	break;
	case 4: Msettings();
	break;
	case 5: organiser();
	break;
	default: cout<<"wrong input: Re enter";
	getch();
	option2();

	}
	return 0;
}
void Messaging()
{       clrscr();
printf("Press ESC to go back to previous menu\n");
drawLine();

cout<<endl;
cout<<("1> Write Message \t \t 2>Oubox");
int msg_choice;
msg_choice=getch();
if(msg_choice==27)
	option2();
else
	msg_choice-=48;
switch(msg_choice)
{
case 1:WriteMsg();
break;
case 2:outbox();
break;
deafault:"wrong vlue input";
}
}

void WriteMsg()
{


	clrscr();
	time_t now=time(0);
	char* dt=ctime(&now);
	cout<<"Write the Message"<<endl;
	char p[512];
	gets(p);
	reEnter:
	int i=0;
	clrscr();
	ifstream myf("names.txt");
	if (!myf) {
		cout << "Errorin reading Contact List file";
	} else {
		while (myf) {
			myf.getline(list[i], 500);
			if (myf)
				i++;
		}
	}

	int stor;
	ifstream myf1("storeNum.txt");
	if (!myf1) {
		cout << "Error in reading from file 'storeNum'"<<endl;
		getch();
	}
	else {
		myf1 >> stor;
	}
	myf1.close();

	myf.close();


	char templist[100][50];
	char templistNum[100][50];
	for(i=0;i<=stor;i++)
	{
		for(int j=0;j<stor-1-i;j++)
		{

			if(strcmpi(list[j],list[j+1])>0)
			{


				strcpy(templist[j],list[j]);
				strcpy(list[j],list[j+1]);
				strcpy(list[j+1],templist[j]);

			}
		}
	}

	cout<<"press Esc to go back to previous menu"<<endl;
	drawLine();
	for (int k = 0; k <= stor-1; k++)
		cout <<k+1<<"> " <<list[k] << endl;

	cout<<"Enter List Number of the Contact"<<endl;
	char acc;
	acc=getch();
	if(acc==27)
		Messaging();
	else
		acc-=48;
	if((acc>stor)||(acc<=0))
	{cout<<"contact dont exist";
	delay(1500);
	goto reEnter;
	}
	char temp[20];
	for(int x=0;x<10;x++)

		temp[x]=list[acc-1][x];

	temp[x]='\0';

	fstream file1("storeMsgNum.txt", ios::in | ios::out);
	if (!file1) {
		cout << "Error in opening file 'storeNumForMsg'"<<endl;
	}
	int str;
	ifstream myf2("storeMsgNum.txt");
	if (!myf2) {
		cout << "Error in reading from file 'storeNum'"<<endl;
	}
	else {
		myf2 >> str;}
	file1<<str+1;
	myf2.close();


	fstream file("outbox.txt", ios::in|ios::out|ios::app);
	if(!file)
	{
		cout<<"Coundnt open outbox file";
	}
	else
	{
		file<<"\n"<<str<<"> Message is:-\n"<<p<<"\nMessage sent to \n'"<<temp<<"' at  "<<dt<<endl;
		cout<<"writing"<<endl<<"Please Wait...";
		delay(2000);
		clrscr();
		cout<<"Message sent and content saved to outbox.\n";



	}
	file.close();

	cout<<"Enter Esc to return to previous menu or press any key to close";
	int check;
	check=getch();
	if(check==27)
		Messaging();

}




void outbox()
{
	clrscr();
	char str[255];

	ifstream myf("outbox.txt");
	if(!myf)
	{
		cout<<"Could not open source file...";
		getch();
	}
	else
	{
		cout<<"OUTBOX"<<endl<<endl;
		int even=0;
		while(myf)
		{
			myf.getline(str,255);
			if(myf)
			{ even ++;
			cout<<str<<endl;
			if((even>5)&&(even%5==0))
				getch();

			}
		}
		getch();
	}
	myf.close();
	cout<<"Enter Esc to return to previous menu or press any key to close";
	int check;
	check=getch();
	if(check==27)
		Messaging();

}
void Mcontact()
{
	clrscr();
	printf("Press ESC to go back to previous menu\n");
	drawLine();
	cout<<endl;
	cout<<"1> Save New Contact \t\t\t\t 2>Open Contact list";
	int Mcon_choice;
	Mcon_choice=getch();
	if(Mcon_choice==27)
		option2();
	else
		Mcon_choice-=48;
	switch(Mcon_choice)
	{
	case 1: SaveContact();
	break;
	case 2 :OpenContact();
	break;
	default: cout<<"Wrong input: Enter Again.";
	getch();
	Mcontact();
	}

}



void SaveContact()
{
	int i = 0;

	clrscr();
	fstream file1("storeNum.txt", ios::in | ios::out);
	if (!file1) {
		cout << "Error in opening file 'storeNum'"<<endl;
	}

	int stor;
	ifstream myf1("storeNum.txt");
	if (!myf1) {
		cout << "Error in reading from file 'storeNum'"<<endl;
	}
	else {
		myf1 >> stor;
	}
	myf1.close();

	file1 << stor + 1 << endl;
	file1.close();
	clrscr();

	fstream file("names.txt", ios::in | ios::out | ios::app);
	if (!file) {
		cout << "Error in creating contact list file"<<endl;
	} else {
		cout << "Enter name" << endl;
		int count = 0;
		//	file<<stor+1<<"> ";
		while (count != 20) {



			char accept = getch();

			if (accept == '\r') {
				count--;
				cout << endl;
				break;
			}
			if(accept=='\b') {


				cout<<'\b';
				cout<<" ";
				cout<<'\b';
			       //	cout<<'\b';
			       count-=2;

			}
			cout << accept;
			file << accept;
			count++;

			if (count == 20) {

				cout << endl << "exeeded limit ";
				delay(1500);
				for (int i = 0; i <= 13; i++) //to  eliminate entered text"exeeded limit"
					cout << '\b';
			}

		}
		cout << "Enter number." << endl;
		gets(listNum[stor]);
		for(int i=0;i<=20-count;i++)
		{
			file<<" ";

		}
		file <<": " << listNum[stor] << endl;
		cout<<"Contact saved to Contact List\n";
	}
	file.close();

	cout<<"Enter Esc to return to previous menu or press any key to close";
	int check;
	check=getch();
	if(check==27)
		Mcontact();
}

int OpenContact()
{


	clrscr();	int i = 0;
	char list[100][50];
	char listNum[100][50];

	clrscr();
	fstream file1("storeNum.txt", ios::in | ios::out);
	if (!file1) {
		cout << "Error in opening file 'storeNum'"<<endl;
	}

	int stor;
	ifstream myf1("storeNum.txt");
	if (!myf1) {
		cout << "Error in reading from file 'storeNum'"<<endl;
	}
	else {
		myf1 >> stor;
	}
	myf1.close();


	file1.close();
	clrscr();

	fstream file("names.txt", ios::in | ios::out | ios::app);
	if (!file) {
		cout << "Error in creating contact list file"<<endl;
	}
	file.close();
	clrscr();
	char str[500];
	ifstream myf("names.txt");
	if (!myf) {
		cout << "Errorin reading Contact List file";
	} else {
		while (myf) {
			myf.getline(list[i], 500);
			if (myf)
				i++;
		}
	}
	myf.close();


	char templist[100][50];
	char templistNum[100][50];
	for(i=0;i<=stor;i++)
	{
		for(int j=0;j<stor-1-i;j++)
		{

			if(strcmpi(list[j],list[j+1])>0)
			{


				strcpy(templist[j],list[j]);
				strcpy(list[j],list[j+1]);
				strcpy(list[j+1],templist[j]);


			}
		} }
	for (int k = 0; k <= stor-1; k++)
		cout <<k+1<<"> "<< list[k] << endl;
	getch();


	cout<<"Enter Esc to return to previous menu or press any key to close";
	int check;
	check=getch();
	if(check==27)
		Mcontact();
}
void Msettings()
{        clrscr();
printf("Press ESC to go back to previous menu\n");
drawLine();
cout<<endl;
cout<<" 1>Change Password\n 2>Change user Settings\n 3>Change User mode";
int Mset_choice;
Mset_choice=getch();
if(Mset_choice==27)
	option2();
else
	Mset_choice-=48;
switch(Mset_choice)
{
case 1:  changePass();
break;
case 2 : ChangeUser();
break;
case 3:  ChangeMode();
break;
default: cout<<"Wrong input: Enter Again.";
getch();
Msettings();
}
}

void changePass()
{
	start: system("cls");
	cout<<"enter Existing Password"<<endl;

	char Epassword3[1][10];
	int flag=0;
	cout<<"Forgot Password? : Press ESC"<<endl;
	cout << "Enter PassWord   : ";
	for (int i3 = 0;; i3++) {
		char ch;
		ch = getch();
		if(int(ch)==27)
			Msettings();

		if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z')
				|| (ch >= 'A' && ch <= 'Z')) {
			Epassword3[0][i3] = ch;
			cout << ch;
			delay(50);
			cout << '\b';
			cout << 'X';
		}
		if (ch == '\b') {
			cout << '\b';
			i3--;
			i3--;
		}
		Epassword3[0][i3+1]='\0';

		if (strcmp(Epassword3[0], password[0]) == 0) {
			cout<<"\nUser Authenticated\n";
			delay(150);
			break;
		}
		if(strlen(Epassword[0]) >= strlen(password[0])  )
		{
			cout << "\nDo not match Try again :";
			flag++;
			delay(2000);
			goto start;
		}
		if(flag==2)  {
			cout<<"Exeding the limit:  Try again later\n";

			Msettings();
		}
	}

	start2:  char Epassword2[1][10];
	char Epassword4[1][10];
	cout<<"\nEnter newPassword..."<<endl;


	for ( i3 = 0;; i3++) {

		char	ch = getch();
		if(int(ch)==27)
			Msettings();

		if (isalnum(ch)) {
			Epassword2[0][i3] = ch;
			cout << ch;
			delay(50);
			cout << '\b';
			cout << 'X';
		}
		if (ch == '\b') {
			cout << '\b';
			i3--;
			i3--;
		}
		if(ch=='\r')
		{
			Epassword2[0][i3]='\0';
			break;
		}
		else
			Epassword2[0][i3+1]='\0';
	}

	if(strlen(Epassword2[0])>=7)
	{
		cout<<"\nExceeding Character Limit: Enter Agian";
		getch();

		goto start2;
	}
	if(strlen(Epassword2[0])<3)
	{
		cout<<"\nMinimum number of Characters should be 3 : Try Again";
		getch();
		goto start2;
	}   clrscr();
	cout<<"\n Re-Enter newPassword..."<<endl;


	for ( i3 = 0;; i3++) {

		char ch = getch();
		if(int(ch)==27)
			Msettings();

		if (isalnum(ch)) {
			Epassword4[0][i3] = ch;
			cout << ch;
			delay(50);
			cout << '\b';
			cout << 'X';
		}
		if (ch == '\b') {
			cout << '\b';
			i3--;
			i3--;
		}
		if(ch=='\r')
		{
			Epassword4[0][i3]='\0';
			break;
		}
		else
			Epassword4[0][i3+1]='\0';
	}
	if(strcmp(Epassword2[0], Epassword4[0])==0)
	{
		strcpy( password[0],Epassword2[0]);
		cout<<"\npassword changed Succesfully";
		getch();
		Msettings();
	}
	else
	{cout<<"\nNew Password Entered Do not match: Try Again";
	getch();
	clrscr();
	goto start2;
	}
}

void ChangeUser()
{

	clrscr();
	printf("Press ESC to go back to previous menu\n");
	drawLine();
	cout<<endl;
	cout<<"enter user name :";
	char choice;
	char User[1][10];
	for(int z=0;z<=10;z++)
	{     choice=getch();
	if(int(choice)==27)
		Msettings();

	else 	if (isalnum(choice)) {
		User[0][z] = choice;
		User[0][z+1]='\0';
		cout << choice;
	}
	else if( choice=='\r')
	{
		User[0][z]='\0';
		break;
	}
	}
	strcpy(Euser[0],User[0]);
	cout<<"\nUser name Changed:\n";
	getch();
	Msettings();

}
void ChangeMode()
{

	char a1[1][10]={"General"};
	char a2[1][10]={"Silent"};

	clrscr();
	printf("Press ESC to go back to previous menu\n");
	drawLine();
	cout<<endl;
	cout<<"current mode of Mobile is "<<mode[0]<<" press 1 to change or ESC to leave\n";
	int choice;
	choice=getch();
	if(choice==27)
		Msettings();
	else choice-=48;
	if(choice==1)
	{
		if(imode==1)
		{
			strcpy(mode[0],a2[0]);
			imode=0;
		}
		else if(imode==0)
		{
			strcpy(mode[0],a1[0]) ;
			imode=1;
		}
		cout<<"\nUser mode Changed\n";
		getch();
		Msettings();
	}
}

void calci()
{    do
{
	clrscr();
	int accept;
	printf("Enter digit");
	cout<<endl;
	double num1;
	double num2;
	int op;
	double res;
	cout<<"1. for +"<<endl;
	cout<<"2. for -"<<endl;
	cout<<"3. for *"<<endl;
	cout<<"4. for /"<<endl;
	cout<<"5. for ^"<<endl;
	cout<<"6. for !"<<endl<<endl;
	cout<<"Number 1"<<'\t'<<'\t'<<"Operation" <<'\t'<<'\t'<<"Number 2"<<endl<<endl;
	cin>>num1;

	cout<<'\t'<<'\t'<<'\t';

	op=getch()-48;

	cout<<op;

	cout<<'\t'<<'\t'<<'\t';

	outer:if(op!=6)
	{
		cin>>num2;
		if(op==4&&num2==0)
		{
			cout<<"Number 2 cannot be zero while dividing, Renter:"<<endl;
			goto outer;
		}
	}
	switch(op)
	{
	case 1:res=num1+num2;
	break;

	case 2:res=num1-num2;
	break;

	case 3:res=num1*num2;
	break;

	case 4:res=num1/num2;
	break;

	case 5:res=pow(num1, num2);
	break;

	case 6:res=1;
	for(int fact=num1; fact>0; fact--)
		res*=fact;
	break;

	default:"wrong input";
	}
	cout<<endl<<endl;
	cout<<'\t'<<'\t'<<"Result";
	cout<<'\t'<<'\t'<<" "<<res<<endl<<endl;

	cout<<"press 1 to recalculate or press ESC to go back to previous menu";
	choice1=getch();
	if(choice1==27)
		option2();
	else choice1-=48;

}while(choice1==1);


}
void organiser()
{

	clrscr();
	printf("Press ESC to go back to previous menu\n");
	drawLine();
	cout<<endl;
	cout<<"1> Timer\n";
	cout<<"2> Game\n";
	cout<<"3> Stopwatch\n";
	int choice;
	choice=getch();
	if(choice==27)
		option2();
	else choice-=48;
	if (choice==1)
		timer();
    //	else
       //	 if(choice==2)
       //	 main1();
	 else
	 if(choice==3)
	 stopwatch();
	      //	game();
	else
	{  cout<<"wrong input";
	getch();
	organiser();
	}
}

void timer()
{
	do
	{
		clrscr();
		int  s1,m1,h1;

		printf("enter minutes......zero is advisable so that u dont wait till it finishes\n");
		cin>>m1;

		printf("enter seconds....small number is advisable\n");

		cin>>s1;

		delay(1000);
		clrscr();

		printf("mins:secs");
		int flag=0;

		for(int m=m1;m>=0;m--)
		{	if(flag==0)
			for(int s=s1;s>=0; s--)
			{
				flag+=1;
				cout<<"0";
				cout<<m;
				cout<<":";
				cout<<s;
				delay(1000);
				printf("\f");
				clrscr();

			}
		if(m1!=0)
		{
			m--;
			for(int s3=59; s3>=0;s3--)
			{

				cout<<"0";
				cout<<m;
				cout<<":";
				cout<<s3;
				delay(1000);
				printf("\f");
				clrscr();
			}
		}
		}
		for(int i3=0;i3<=3;i3++)
		{
			printf("countdown complete!!!");
			delay(1000);
			clrscr();

		}
		printf("enter 1 to restart the timer else hit ESC to return to previous menu");
		choice1=getch();
		if(choice1==27)
			option2();
		else choice1-=48;

	}while(choice1==1 );


}
	void stopwatch()

	{
	clrscr();
	delay(500);
	cout<<"STOPWATCH\n";
	cout<<"Press ENTER to start\n";
	char strt;
	strt=getch();
       if(strt=='\r')
       {
	clock_t start, end;
	start = clock();
	int sec=0;
	int msec=0;


	for(int i=0; ;i++)

	 {
	 if(!kbhit()==0)
	 {
	 char ch=getch();
	 if (ch==0)
	 {
	end = clock();
	printf("The time was: %f\n", (end - start) / CLK_TCK);

	  break;
	   }
	   }
	     end=clock();
	      cout<<((end - start) / (CLK_TCK));
		cout<<"\n Press END to stop ";
	      delay(100);
	     clrscr();

	   }



	   getch();

	 }

       }


	void shutdown()
	{
		delay(800);
		clrscr();
		printf("Good Bye");
		delay(3000);
		exit (EXIT_SUCCESS);
	}
