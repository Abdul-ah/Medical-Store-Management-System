#include<stdio.h>
//#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
//#include<string.h>
//#include<ctype.h>

//COORD coord = {0, 0};
int i,sup_id=1,cust_id=0,medi_id=0;
char ch;

struct supplier{
	char name[30];
	char mobile[11];
	char email[50];
	int sup_id;
	char city[20];
	int num;
	struct supplier* next;
};
struct supplier* supplies=NULL;

struct customer{
	char name[30];
	char mobile[11];
	char email[50];
	int cust_id;
	char city[20];
	struct customer* next;
};
struct customer* customerise=NULL;

struct medicine{
	int med_id;
	char name[40];
	int rack,quantity;
	char company[50];
	char supplier_name[30];
	float unit,sales;
	char manu[11],expir[11];
	struct medicine* next;
};
struct medicine* medi=NULL;

bool welcome();
void wbox();
void initialize();
void subbox();
void pos_cursor(int x, int y);
void home();
void t();
void action();
void supplier();
void add_supplier();
void insert_supply();
void update_supplier();
void update_supplierfile();
void show_suppliers();
void search_supplier();
void add_customer();
void insert_customer();
void supplier();
void customer();
void update_customer();
void update_customerfile();
void show_customer();
void search_customer();
void medicine();
void purchase_medicine();
void insert_medicine();
void sell_medicine();
void medicine_list();
void find_medicine();
void report();
void about();

int main(){
	while(!welcome()){
		system("cls");
		pos_cursor(24,38);
		printf("Invalid Username or Password!!!");
	}
	action();
	initialize();
	home();
}

bool welcome(){
	wbox();
	t();
	char user[30],pass[30];
	char username[6]="1";
	char password[6]="1";
	pos_cursor(25,10);
	printf("Welcome to Pharmacy");
	pos_cursor(20,25);
	printf("Enter Login Details");
	pos_cursor(30,27);
	printf("Username: ");
	pos_cursor(30,29);
	printf("Password: ");
	pos_cursor(41,27);
	gets(user);
	pos_cursor(41,29);
	gets(pass);
	if(strcmp(user,username)==0 && strcmp(pass,password)==0){
		return 1;
	}
	else{
		return 0;
	}
}
void wbox()
{
	for(i=5;i<=75;i++)
	{
		pos_cursor(i,5);
		printf("%c",219);
		pos_cursor(74,40);
		printf("%c",219);
		pos_cursor(i,40);
		printf("%c",219);
	}
	for(i=5;i<=40;i++)
	{
		pos_cursor(5,i);
		printf("%c",219);
		pos_cursor(75,i);
		printf("%c",219);
	}
}
void initialize(){
	FILE *supp,*custo,*med;
	supp=fopen("supplierslist.txt","r");
	fflush(stdin);
	while(1){
		fflush(stdin);
		if(feof(supp)){
			break;
		}
		struct supplier* temp=(struct supplier*)malloc(sizeof(struct supplier));
		fscanf(supp,"%d",&temp->num);
		fscanf(supp,"%s",temp->name);
		fscanf(supp,"%s",temp->city);
		fscanf(supp,"%s",temp->mobile);
		fscanf(supp,"%s",temp->email);
		temp->next=NULL;
		temp->next=NULL;
		if(supplies==NULL){
			supplies=temp;
			supplies->sup_id=sup_id;
		}
		else{
			fflush(stdin);
			struct supplier* ptr=supplies;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			sup_id++;
			ptr->next=temp;
			temp->sup_id=sup_id;
		}
	}
	fclose(supp);
	custo=fopen("customerlist.txt","r");
	while(feof(custo)!=1){
		if(feof(custo)){
			break;
		}
		struct customer* temp=(struct customer*)malloc(sizeof(struct customer));
		fscanf(custo,"%s",temp->name);
		fscanf(custo,"%s",temp->city);
		fscanf(custo,"%s",temp->mobile);
		fscanf(custo,"%s",temp->email);
		temp->next=NULL;
		if(customerise==NULL){
			cust_id++;
			customerise=temp;
			customerise->cust_id=cust_id;
		}
		else{
			struct customer* ptr=customerise;
			while(ptr->next!=NULL){
			ptr=ptr->next;
			}
			cust_id++;
			ptr->next=temp;
			temp->cust_id=cust_id;
		}
	}
	fclose(custo);
	med=fopen("Medicinelist.txt","r");
	fflush(stdin);
	while(1){
		fflush(stdin);
		if(feof(med)){
			break;
		}
		struct medicine* temp=(struct medicine*)malloc(sizeof(struct medicine));
		fscanf(med,"%s",temp->name);
		fscanf(med,"%s",temp->supplier_name);
		fscanf(med,"%s",temp->company);
		fscanf(med,"%d",&temp->quantity);
		fscanf(med,"%d",&temp->rack);
		fscanf(med,"%s",temp->manu);
		fscanf(med,"%s",temp->expir);
		temp->next=NULL;
		if(medi==NULL){
			medi_id++;
			medi=temp;
			medi->med_id=medi_id;
		}
		else{
			struct medicine* ptr=medi;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			medi_id++;
			ptr->next=temp;
			temp->med_id=medi_id;
		}
	}
	fclose(med);	
}
void pos_cursor(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void home(){
	system("cls");
	wbox();
	t();
	for(i=0;i<=70;i++){
		pos_cursor(i+5,9);
		printf("%c",219);
	}
	pos_cursor(7,7);
	printf("Supplier Info");
	pos_cursor(23,7);
	printf("Customer Info");
	pos_cursor(39,7);
	printf("Medicine");
	pos_cursor(50,7);
	printf("Reports");
	pos_cursor(60,7);
	printf("About");
	pos_cursor(68,7);
	printf("Exit");
	pos_cursor(10,38);
	printf("Enter First Character to Proceed: ");
	ch=toupper(getche());
    switch(ch)
    {
    	case 'S':
    		supplier();
    		break;
    	case 'C':
    		customer();
    		break;
    	case 'M':
    		medicine(); 
    		break;
    	case 'R':
    		report();
    		break;
    	case 'A':
    		about();
    		break;
    	case 'E':
    		pos_cursor(24,24);
    		printf("Are you sure want to Exit(Y/N): ");
    		char ex;
    		ex=toupper(getch());
    		if(ex=='Y'){
    			action();
    			Sleep(2000);
    			system("cls");
    			pos_cursor(15,10);
    			printf("Thank You. Visit Again!");
    			pos_cursor(1,20);
    			exit(0);
			}
			else{
				home();
			}
    		break;
    	default:
			pos_cursor(11,34);
			printf("Invalid. Enter from these characters only (S,C,M,R,B,A,E).");
			Sleep(4000);
			home();
	}
}
void t()
{
	system("COLOR 02");
	//system("color 9f");
	time_t t = time(0);
	struct tm * now = localtime( & t );
	pos_cursor(76,42);
	printf("Time: %d:%d:%d",now->tm_hour, now->tm_min,now->tm_sec);
	pos_cursor(76,39);
	printf("Date: %d-%d-%d\n",now->tm_mday,now->tm_mon,now->tm_year);
	return ;
}
void action()
{
	for (i=45; i>=1; i--)
	{
		Sleep(30);
		pos_cursor(0,i);
	}
	system("cls");
	pos_cursor(1,1);
	printf("Please wait...");
	for (i=1; i<=15; i++)
	{
		Sleep(40);
		pos_cursor(0,i);
	}
}
void subbox()
{
	pos_cursor(1,6);
	printf("%c",201);
	for(i=1;i<79;i++)
	{
		pos_cursor(1+i,6);
		printf("%c",205);
	}

	pos_cursor(80,6);
	printf("%c",187);
	pos_cursor(1,6);
	for(i=5;i<35;i++)
	{
		pos_cursor(1,2+i);
		printf("%c",186);
	}
	pos_cursor(1,37);
	printf("%c",200);
	for(i=1;i<79;i++)
	{
		pos_cursor(1+i,37);
		printf("%c",205);
	}
	pos_cursor(80,37);
	printf("%c",188);
	pos_cursor(80,6);
	for(i=5;i<35;i++)
	{
		pos_cursor(80,2+i);
		printf("%c",186);
	}
	t();
}
void supplier(){
	system("cls");
	subbox();
	pos_cursor(34,3);
	printf("----------------");
	pos_cursor(35,4);
	printf("Supplier MENU");
	pos_cursor(34,5);
	printf("----------------");
	pos_cursor(25,11);
	printf("Add New Supplier");
	pos_cursor(26,15);
	printf("Update Supplier");
	pos_cursor(25,19);
	printf("Search Supplier");
	pos_cursor(25,23);
	printf("List of Existing Supplier");
	pos_cursor(25,27);
	printf("Main Menu");
	pos_cursor(3,36);
	printf("Enter First Character to Proceed: ");
	ch=toupper(getche());
	switch(ch)
	{
	case 'A':
		action();
		add_supplier();
		break;
	case 'U':
		action();
		update_supplier();
		break;
	case 'L':
		action();
		show_suppliers();
		break;
	case 'S':
		action();
		search_supplier();
		break;
	case 'M':
		action();
		home();
		break;
	default:
		pos_cursor(11,34);
		printf("Invalid. Enter from these characters only (A,U,L,S,M).");
		Sleep(4000);
		supplier();
	  }
}

void add_supplier(){
	fflush(stdin);
	system("cls");
	subbox();
	pos_cursor(34,3);
	printf("----------------");
	pos_cursor(35,4);
	printf("Supplier Entry");
	pos_cursor(34,5);
	printf("----------------");
	sup_id++;
	pos_cursor(5,10);
	printf("Supplier id: %d",sup_id);
	pos_cursor(5,15);
	printf("City: ");
	pos_cursor(40,10);
	printf("Supplier name: ");
	pos_cursor(40,15);
	printf("Contact: ");
	pos_cursor(5,20);
	printf("Email Id: ");
	insert_supply();
}
void insert_supply(){
	struct supplier* temp=(struct supplier*)malloc(sizeof(struct supplier));
	fflush(stdin);
	pos_cursor(55,10);
	gets(temp->name);
	pos_cursor(12,15);
	gets(temp->city);
	pos_cursor(15,20);
	gets(temp->email);
	pos_cursor(49,15);
	gets(temp->mobile);
	temp->next=NULL;
	temp->sup_id=sup_id;
	if(supplies==NULL){
		supplies=temp;
	}
	else{
		struct supplier* ptr;
		ptr=supplies;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
	pos_cursor(3,35);
	printf("Supplier Added successfully :)\n");
	FILE* f1;
	f1=fopen("Reports.txt","a");
	fputs("\nNew Supplier is Added\nDetails:",f1);
	fputs("\n",f1);
	fputs("Supplier ID: ",f1);
	char ch=sup_id+48;
	putw(ch,f1);
	fputs("\n",f1);
	fputs("Name: ",f1);
	fputs(temp->name,f1);
	fputs("\n",f1);
	fputs("City: ",f1);
	fputs(temp->city,f1);
	fputs("\n",f1);
	fputs("Contact Number: ",f1);
	fputs(temp->mobile,f1);
	fputs("\n",f1);
	fputs("Email Address: ",f1);
	fputs(temp->email,f1);
	fputs("\n",f1);
	fclose(f1);
	pos_cursor(3,36);
	printf("Add more Suppliers!(Y/N): ");
	ch=toupper(getche());
	if(ch=='Y'){
		add_supplier();
	}
	else{
	FILE *fptr,*fp;
	fptr=fopen("suppliers.txt","w");
	fp=fopen("supplierslist.txt","w");
	if(fptr==NULL && fp==NULL){
		printf("Can't open file :( ");
		Sleep(2000);
	}
	else{
		struct supplier* ptr=supplies;
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n",fptr);
			fputs("Supplier ID: ",fptr);
			char ch=supplies->sup_id+48;
			putw(ch,fptr);
			fputs("\n",fptr);
			fputs("Name: ",fptr);
			fputs(supplies->name,fptr);
			fputs(supplies->name,fp);
			fputs("\n",fptr);
			fputs("\n",fp);
			fputs("City: ",fptr);
			fputs(supplies->city,fptr);
			fputs(supplies->city,fp);
			fputs("\n",fptr);
			fputs("\n",fp);
			fputs("Contact Number: ",fptr);
			fputs(supplies->mobile,fptr);
			fputs(supplies->mobile,fp);
			fputs("\n",fptr);
			fputs("\n",fp);
			fputs("Email: ",fptr);
			fputs(supplies->email,fptr);
			fputs(supplies->email,fp);
			fputs("\n",fptr);
			fputs("\n",fp);
			fputs("Number: ",fptr);
			fprintf(fptr,"%d",supplies->num);
			fprintf(fp,"%d",supplies->num);
			fputs("\n",fptr);
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n",fptr);
			ptr=supplies->next;
			while(ptr!=NULL){
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n",fptr);
			fputs("Supplier ID: ",fptr);
			char ch=ptr->sup_id+48;
			putw(ch,fptr);
			fputs("\n",fp);
			fputs("\n",fptr);
			fputs("Name: ",fptr);
			fputs(ptr->name,fptr);
			fputs(ptr->name,fp);
			fputs("\n",fptr);
			fputs("\n",fp);
			fputs("City: ",fptr);
			fputs(ptr->city,fptr);
			fputs(ptr->city,fp);
			fputs("\n",fptr);
			fputs("\n",fp);
			fputs("Contact Number: ",fptr);
			fputs(ptr->mobile,fptr);
			fputs(ptr->mobile,fp);
			fputs("\n",fptr);
			fputs("\n",fp);
			fputs("Email: ",fptr);
			fputs(ptr->email,fptr);
			fputs(ptr->email,fp);
			fputs("\n",fp);
			fputs("\n",fptr);
			fputs("Number: ",fptr);
			fprintf(fptr,"%d",ptr->num);
			fprintf(fp,"%d",ptr->num);
			fputs("\n",fptr);
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n",fptr);
			ptr=ptr->next;
		}
	}
	fclose(fptr);
	fclose(fp);
	supplier();
	}
}
void update_supplier(){
	system("cls");
	subbox();
	pos_cursor(34,3);
	printf("----------------");
	pos_cursor(37,4);
	printf("Updation");
	pos_cursor(34,5);
	printf("----------------");
	int found=0;
	struct supplier* ptr;
	ptr=supplies;
	int key;
	fflush(stdin);
	pos_cursor(3,10);
	printf("Enter the supplier id: ");
	scanf("%d",&key);
	while(ptr!=NULL){
		if(ptr->sup_id == key){
			found=1;
			break;
		}
		else{
			ptr=ptr->next;
		}
	}
	if(found!=1){
		pos_cursor(15,34);
		printf("No supplier id is Incorrect, Come Again");
		update_supplier();
	}
	else{
		system("cls");
		subbox();
		pos_cursor(6,11);
		printf("What should be updated: (Name/City/Mobile Number/Email)\n");
		pos_cursor(3,36);
		printf("Enter First Character to Proceed: ");
		ch=toupper(getche());
		FILE* f1;
		f1=fopen("Reports.txt","a");
		fflush(stdin);
		switch(ch)
		{
			case 'N':
				system("cls");
				subbox();
				pos_cursor(20,11);
				printf("Enter Name to update: ");
				fflush(stdin);
				gets(ptr->name);
				pos_cursor(3,35);
				printf("Updatated Name Successfully :)\n");
				fputs("\nSupplier is Updated\nDetails:",f1);
				fputs("\n",f1);
				fputs("Supplier ID: ",f1);
				ch=ptr->sup_id+48;
				putw(ch,f1);
				fputs("\n",f1);
				fputs("Supplier Name changed to: ",f1);
				fputs(ptr->name,f1);
				fputs("\n",f1);
				fclose(f1);
				update_supplierfile();
				pos_cursor(3,36);
				printf("Change any other Details (Y/N): ");
				ch=toupper(getche());
				if(ch=='Y'){
					update_supplier();
				}
				else{
					supplier();
				}
				break;
			case 'C':
				system("cls");
				subbox();
				pos_cursor(20,11);
				printf("Enter new address(City Name) to update: ");
				fflush(stdin);
				gets(ptr->city);
				pos_cursor(3,35);
				printf("Updatated Address Successfully :)\n");
				FILE* f1;
				f1=fopen("Reports.txt","a");
				fputs("\nSupplier is Updated\nDetails:",f1);
				fputs("\n",f1);
				fputs("Supplier ID: ",f1);
				ch=ptr->sup_id+48;
				putw(ch,f1);
				fputs("\n",f1);
				fputs("Supplier address changed to: ",f1);
				fputs(ptr->city,f1);
				fputs("\n",f1);
				fclose(f1);
				update_supplierfile();
				pos_cursor(3,36);
				printf("Change any other Details (Y/N): ");
				ch=toupper(getche());
				if(ch=='Y'){
					update_supplier();
				}
				else{
					supplier();
				}
				break;
			case 'E':
				system("cls");
				subbox();
				pos_cursor(20,11);
				printf("Enter Email address to update: ");
				gets(ptr->email);
				pos_cursor(3,35);
				printf("Updatated Email Address Successfully :)\n");
				FILE* f2;
				f2=fopen("Reports.txt","a");
				fputs("\nSupplier is Updated\nDetails:",f2);
				fputs("\n",f2);
				fputs("Supplier ID: ",f2);
				ch=ptr->sup_id+48;
				putw(ch,f2);
				fputs("\n",f2);
				fputs("Supplier Email changed to: ",f2);
				fputs(ptr->email,f2);
				fputs("\n",f2);
				fclose(f2);
				pos_cursor(3,36);
				printf("Change any other Details (Y/N): ");
				update_supplierfile();
				ch=toupper(getche());
				if(ch=='Y'){
					update_supplier();
				}
				else{
					supplier();
				}
				break;
			case 'M':
				system("cls");
				subbox();
				pos_cursor(20,11);
				printf("Enter Mobile Number to update: ");
				fflush(stdin);
				gets(ptr->mobile);
				pos_cursor(3,35);
				printf("Updatated Mobile Number Successfully :)\n");
				FILE* f3;
				f3=fopen("Reports.txt","a");
				fputs("\nSupplier is Updated\nDetails:",f3);
				fputs("\n",f3);
				fputs("Supplier ID: ",f3);
				ch=ptr->sup_id+48;
				putw(ch,f3);
				fputs("\n",f3);
				fputs("Supplier Contact Number changed to: ",f3);
				fputs(ptr->mobile,f3);
				fputs("\n",f3);
				fclose(f3);
				pos_cursor(3,36);
				printf("Change any other Details (Y/N): ");
				update_supplierfile();
				ch=toupper(getche());
				if(ch=='Y'){
					update_supplier();
				}
				else{
					supplier();
				}
				break;
			default:
				pos_cursor(3,35);
				printf("Invalid try again :( ");
				Sleep(2000);
				update_supplier();
		}
	}
}
void update_supplierfile(){
	FILE *fptr,*fp;
	fptr=fopen("suppliers.txt","w");
	fp=fopen("supplierslist.txt","w");
	if(fptr==NULL && fp==NULL){
		printf("Can't open file :( ");
		Sleep(2000);
	}
	else{
		struct supplier* ptr=supplies;
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n",fptr);
			fputs("Supplier ID: ",fptr);
			char ch=supplies->sup_id+48;
			putw(ch,fptr);
			fputs("\n",fptr);
			fputs("Name: ",fptr);
			fputs(supplies->name,fptr);
			fputs(supplies->name,fp);
			fputs("\n",fptr);
			fputs("\n",fp);
			fputs("City: ",fptr);
			fputs(supplies->city,fptr);
			fputs(supplies->city,fp);
			fputs("\n",fptr);
			fputs("\n",fp);
			fputs("Contact Number: ",fptr);
			fputs(supplies->mobile,fptr);
			fputs(supplies->mobile,fp);
			fputs("\n",fptr);
			fputs("\n",fp);
			fputs("Email: ",fptr);
			fputs(supplies->email,fptr);
			fputs(supplies->email,fp);
			fputs("\n",fptr);
			fputs("\n",fp);
			fputs("Number: ",fptr);
			fprintf(fptr,"%d",supplies->num);
			fprintf(fp,"%d",supplies->num);
			fputs("\n",fptr);
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n",fptr);
			ptr=supplies->next;
			while(ptr!=NULL){
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n",fptr);
			fputs("Supplier ID: ",fptr);
			char ch=ptr->sup_id+48;
			putw(ch,fptr);
			fputs("\n",fp);
			fputs("\n",fptr);
			fputs("Name: ",fptr);
			fputs(ptr->name,fptr);
			fputs(ptr->name,fp);
			fputs("\n",fptr);
			fputs("\n",fp);
			fputs("City: ",fptr);
			fputs(ptr->city,fptr);
			fputs(ptr->city,fp);
			fputs("\n",fptr);
			fputs("\n",fp);
			fputs("Contact Number: ",fptr);
			fputs(ptr->mobile,fptr);
			fputs(ptr->mobile,fp);
			fputs("\n",fptr);
			fputs("\n",fp);
			fputs("Email: ",fptr);
			fputs(ptr->email,fptr);
			fputs(ptr->email,fp);
			fputs("\n",fptr);
			fputs("\n",fp);
			fputs("Number: ",fptr);
			fprintf(fptr,"%d",ptr->num);
			fprintf(fp,"%d",ptr->num);
			fputs("\n",fptr);
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n",fptr);
			ptr=ptr->next;
		}
	}
	fclose(fptr);
	fclose(fp);
	supplier();
}
void show_suppliers(){
	system("cls");
	subbox();
	pos_cursor(30,3);
	printf("-----------------------");
	pos_cursor(33,4);
	printf("List of Suppliers");
	pos_cursor(30,5);
	printf("-----------------------");
	pos_cursor(5,10);
	printf("The Supplier List is shown below: ");
	struct supplier* temp;
	temp=supplies;
	int i=12;
	while(temp!=NULL){
		pos_cursor(15,i);
		printf("Supplier ID: %d",temp->sup_id);
		i++;
		pos_cursor(15,i);
		printf("Name: ");
		puts(temp->name);
		i++;
		pos_cursor(15,i);
		printf("Contact Number: %s\n",temp->mobile);
		i++;
		pos_cursor(15,i);
		printf("Email: %s\n",temp->email);
		i++;
		pos_cursor(15,i);
		printf("Number: %d\n",temp->num);
		i=i+2;
		temp=temp->next;
	}
	pos_cursor(3,36);
	printf("Enter any key to continue... ");
	ch=toupper(getche());
	supplier();
}
void search_supplier(){
	system("cls");
	subbox();
	pos_cursor(30,3);
	printf("-----------------------");
	pos_cursor(33,4);
	printf("Search a Supplier");
	pos_cursor(30,5);
	printf("-----------------------");
	pos_cursor(5,10);
	struct supplier* temp;
	temp=supplies;
	int found=0;
	printf("Enter the name of the supplier: ");
	char key[30];
	gets(key);
	while(temp!=NULL){
		if(strcmp(key,temp->name)==0){
			pos_cursor(5,12);
			printf("Supplier found :)");
			pos_cursor(5,14);
			printf("Supplier Id: %d",temp->sup_id);
			pos_cursor(5,15);
			printf("Name: ");
			puts(temp->name);
			pos_cursor(5,16);
			printf("City: ");
			puts(temp->city);
			pos_cursor(5,17);
			printf("Mobile Number: %s",temp->mobile);
			pos_cursor(5,18);
			printf("Email Address: %s",temp->email);
			found=1;
			pos_cursor(5,19);
			printf("Enter any key to go Main Menu: ");
			ch=toupper(getche());
			supplier();
			break;
		}
		else{
			temp=temp->next;
		}
	}
	if(found==0){
		pos_cursor(3,35);
		printf("Supplier Not Found!!!");
		pos_cursor(3,36);
		printf("Search again(Y/N)");
		ch=toupper(getche());
		switch(ch){
			case 'Y':
				search_supplier();
				break;
			default:
				supplier();
				break;
		}
	}
}

void customer(){
	system("cls");
	subbox();
	pos_cursor(34,3);
	printf("------------------");
	pos_cursor(36,4);
	printf("Customer MENU");
	pos_cursor(34,5);
	printf("------------------");
	pos_cursor(25,11);
	printf("Add New Customer");
	pos_cursor(26,15);
	printf("Update Customer");
	pos_cursor(25,19);
	printf("Search Customer");
	pos_cursor(25,23);
	printf("List of Existing Customer");
	pos_cursor(25,27);
	printf("Main Menu");
	pos_cursor(3,36);
	printf("Enter First Character to Proceed: ");
	ch=toupper(getche());
	switch(ch)
	{
	case 'A':
		action();
		add_customer();
		break;
	case 'U':
		action();
		update_customer();
		break;
	case 'L':
		action();
		show_customer();
		break;
	case 'S':
		action();
		search_customer();
		break;
	case 'M':
		action();
		home();
		break;
	default:
		pos_cursor(11,34);
		printf("Invalid. Enter from these characters only (A,U,L,S,M).");
		Sleep(4000);
		supplier();
	  }
}

void add_customer(){
	system("cls");
	subbox();
	pos_cursor(34,3);
	printf("----------------");
	pos_cursor(35,4);
	printf("Customer Entry");
	pos_cursor(34,5);
	printf("----------------");
	cust_id++;
	pos_cursor(5,10);
	printf("Customer id: %d",cust_id);
	pos_cursor(5,15);
	printf("City: ");
	pos_cursor(40,10);
	printf("Customer name: ");
	pos_cursor(40,15);
	printf("Contact: ");
	pos_cursor(5,20);
	printf("Email Id: ");
	insert_customer();
}
void insert_customer(){
	struct customer* temp=(struct customer*)malloc(sizeof(struct customer));
	fflush(stdin);
	pos_cursor(55,10);
	gets(temp->name);
	pos_cursor(12,15);
	gets(temp->city);
	pos_cursor(15,20);
	gets(temp->email);
	pos_cursor(49,15);
	gets(temp->mobile);
	temp->next=NULL;
	temp->cust_id=cust_id;
	if(customerise==NULL){
		customerise=temp;
	}
	else{
		struct customer* ptr;
		ptr=customerise;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
	pos_cursor(3,35);
	printf("Customer Added successfully :)\n");
	FILE* f1;
	f1=fopen("Reports.txt","a");
	fputs("\nNew Customer is Added\nDetails:",f1);
	fputs("\n",f1);
	fputs("Customer ID: ",f1);
	char ch=cust_id+48;
	putw(ch,f1);
	fputs("\n",f1);
	fputs("Name: ",f1);
	fputs(temp->name,f1);
	fputs("\n",f1);
	fputs("City: ",f1);
	fputs(temp->city,f1);
	fputs("\n",f1);
	fputs("Contact Number: ",f1);
	fputs(temp->mobile,f1);
	fputs("\n",f1);
	fputs("Email Address: ",f1);
	fputs(temp->email,f1);
	fputs("\n",f1);
	fclose(f1);
	pos_cursor(3,36);
	printf("Add more Customer!(Y/N): ");
	ch=toupper(getche());
	if(ch=='Y'){
		add_customer();
	}
	else{
	FILE *fptr,*fp1;
	fptr=fopen("customer.txt","w");
	fp1=fopen("customerlist.txt","w+");
	if(fptr==NULL && fp1==NULL){
		printf("Can't open file :( ");
		Sleep(2000);
	}
	else{
		struct customer* ptr=customerise;
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n",fptr);
			fputs("Customer ID: ",fptr);
			char ch=customerise->cust_id+48;
			putw(ch,fptr);
			fputs("\n",fptr);
			fputs("Name: ",fptr);
			fputs(customerise->name,fptr);
			fputs(customerise->name,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("City: ",fptr);
			fputs(customerise->city,fptr);
			fputs(customerise->city,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Contact Number: ",fptr);
			fputs(customerise->mobile,fptr);
			fputs(customerise->mobile,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Email: ",fptr);
			fputs(customerise->email,fptr);
			fputs(customerise->email,fp1);
			fputs("\n",fptr);
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n",fptr);
			ptr=ptr->next;
			while(ptr!=NULL){
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n",fptr);
			fputs("Customer ID: ",fptr);
			char ch=ptr->cust_id+48;
			putw(ch,fptr);
			fputs("\n",fp1);
			fputs("\n",fptr);
			fputs("Name: ",fptr);
			fputs(ptr->name,fptr);
			fputs(ptr->name,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("City: ",fptr);
			fputs(ptr->city,fptr);
			fputs(ptr->city,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Contact Number: ",fptr);
			fputs(ptr->mobile,fptr);
			fputs(ptr->mobile,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Email: ",fptr);
			fputs(ptr->email,fptr);
			fputs(ptr->email,fp1);
			fputs("\n",fptr);
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n",fptr);
			ptr=ptr->next;
			}
	}
	fclose(fptr);
	fclose(fp1);
	customer();
	}
}
void update_customer(){
	system("cls");
	subbox();
	pos_cursor(34,3);
	printf("----------------");
	pos_cursor(37,4);
	printf("Updation");
	pos_cursor(34,5);
	printf("----------------");
	int found=0;
	struct customer* ptr;
	ptr=customerise;
	int key;
	fflush(stdin);
	pos_cursor(3,10);
	printf("Enter the Customer id: ");
	scanf("%d",&key);
	while(ptr!=NULL){
		if(ptr->cust_id == key){
			found=1;
			break;
		}
		else{
			ptr=ptr->next;
		}
	}
	if(found!=1){
		pos_cursor(15,34);
		printf("No Customer id is Incorrect, Come Again");
		Sleep(2000);
		update_customer();
	}
	else{
		system("cls");
		subbox();
		pos_cursor(6,11);
		printf("What should be updated: (Name/City/Mobile Number/Email)\n");
		pos_cursor(3,36);
		printf("Enter First Character to Proceed: ");
		ch=toupper(getche());
		FILE* f1;
		f1=fopen("Reports.txt","a");
		fflush(stdin);
		switch(ch)
		{
			case 'N':
				system("cls");
				subbox();
				pos_cursor(20,11);
				printf("Enter Name to update: ");
				fflush(stdin);
				gets(ptr->name);
				pos_cursor(3,35);
				printf("Updatated Name Successfully :)\n");
				fputs("\nCustomer is Updated\nDetails:",f1);
				fputs("\n",f1);
				fputs("Customer ID: ",f1);
				ch=ptr->cust_id+48;
				putw(ch,f1);
				fputs("\n",f1);
				fputs("Customer Name changed to: ",f1);
				fputs(ptr->name,f1);
				fputs("\n",f1);
				fclose(f1);
				pos_cursor(3,36);
				printf("Change any other Details (Y/N)");
				update_customerfile();
				ch=toupper(getche());
				if(ch=='Y'){
					update_customer();
				}
				else{
					customer();
				}
				break;
			case 'C':
				system("cls");
				subbox();
				pos_cursor(20,11);
				printf("Enter new address(City Name) to update: ");
				fflush(stdin);
				gets(ptr->city);
				pos_cursor(3,35);
				printf("Updatated Address Successfully :)\n");
				FILE* f1;
				f1=fopen("Reports.txt","a");
				fputs("\nCustomer is Updated\nDetails:",f1);
				fputs("\n",f1);
				fputs("Customer ID: ",f1);
				ch=ptr->cust_id+48;
				putw(ch,f1);
				fputs("\n",f1);
				fputs("Customer address changed to: ",f1);
				fputs(ptr->city,f1);
				fputs("\n",f1);
				fclose(f1);
				pos_cursor(3,36);
				printf("Change any other Details (Y/N)");
				update_customerfile();
				ch=toupper(getche());
				if(ch=='Y'){
					update_customer();
				}
				else{
					customer();
				}
				break;
			case 'E':
				system("cls");
				subbox();
				pos_cursor(20,11);
				printf("Enter Email address to update: ");
				fflush(stdin);
				gets(ptr->email);
				pos_cursor(3,35);
				printf("Updatated Email Address Successfully :)\n");
				FILE* f2;
				f2=fopen("Reports.txt","a");
				fputs("\nCustomer is Updated\nDetails:",f2);
				fputs("\n",f2);
				fputs("Customer ID: ",f2);
				ch=ptr->cust_id+48;
				putw(ch,f2);
				fputs("\n",f2);
				fputs("Customer Email changed to: ",f2);
				fputs(ptr->email,f2);
				fputs("\n",f2);
				fclose(f2);
				pos_cursor(3,36);
				printf("Change any other Details (Y/N)");
				update_customerfile();
				ch=toupper(getche());
				if(ch=='Y'){
					update_customer();
				}
				else{
					customer();
				}
				break;
			case 'M':
				system("cls");
				subbox();
				pos_cursor(20,11);
				printf("Enter Mobile Number to update: ");
				fflush(stdin);
				gets(ptr->mobile);
				pos_cursor(3,35);
				printf("Updatated Mobile Number Successfully :)\n");
				FILE* f3;
				f3=fopen("Reports.txt","a");
				fputs("\nCustomer is Updated\nDetails:",f3);
				fputs("\n",f3);
				fputs("Customer ID: ",f3);
				ch=ptr->cust_id+48;
				putw(ch,f3);
				fputs("\n",f3);
				fputs("Customer Contact Number changed to: ",f3);
				fputs(ptr->mobile,f3);
				fputs("\n",f3);
				fclose(f3);
				pos_cursor(3,36);
				printf("Change any other Details (Y/N)");
				update_customerfile();
				ch=toupper(getche());
				if(ch=='Y'){
					update_customer();
				}
				else{
					customer();
				}
				break;
			default:
				pos_cursor(3,35);
				printf("Invalid try again :( ");
				Sleep(2000);
				update_customer();
		}
	}
}
void update_customerfile(){
		FILE *fptr,*fp1;
	fptr=fopen("customer.txt","w");
	fp1=fopen("customerlist.txt","w+");
	if(fptr==NULL && fp1==NULL){
		printf("Can't open file :( ");
		Sleep(2000);
	}
	else{
		struct customer* ptr=customerise;
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n",fptr);
			fputs("Customer ID: ",fptr);
			char ch=customerise->cust_id+48;
			putw(ch,fptr);
			fputs("\n",fptr);
			fputs("Name: ",fptr);
			fputs(customerise->name,fptr);
			fputs(customerise->name,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("City: ",fptr);
			fputs(customerise->city,fptr);
			fputs(customerise->city,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Contact Number: ",fptr);
			fputs(customerise->mobile,fptr);
			fputs(customerise->mobile,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Email: ",fptr);
			fputs(customerise->email,fptr);
			fputs(customerise->email,fp1);
			fputs("\n",fptr);
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n",fptr);
			ptr=ptr->next;
			while(ptr!=NULL){
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n",fptr);
			fputs("Customer ID: ",fptr);
			char ch=ptr->cust_id+48;
			putw(ch,fptr);
			fputs("\n",fp1);
			fputs("\n",fptr);
			fputs("Name: ",fptr);
			fputs(ptr->name,fptr);
			fputs(ptr->name,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("City: ",fptr);
			fputs(ptr->city,fptr);
			fputs(ptr->city,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Contact Number: ",fptr);
			fputs(ptr->mobile,fptr);
			fputs(ptr->mobile,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Email: ",fptr);
			fputs(ptr->email,fptr);
			fputs(ptr->email,fp1);
			fputs("\n",fptr);
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n",fptr);
			ptr=ptr->next;
			}
	fclose(fptr);
	fclose(fp1);
	customer();
	}
}
void show_customer(){
	system("cls");
	subbox();
	pos_cursor(30,3);
	printf("-----------------------");
	pos_cursor(33,4);
	printf("List of Customers");
	pos_cursor(30,5);
	printf("-----------------------");
	pos_cursor(5,10);
	printf("The Customer List is shown below: ");
	struct customer* temp;
	temp=customerise;
	int i=12;
	while(temp!=NULL){
		pos_cursor(15,i);
		printf("Customer ID: %d",temp->cust_id);
		i++;
		pos_cursor(15,i);
		printf("Name: ");
		puts(temp->name);
		i++;
		pos_cursor(15,i);
		printf("Contact Number: %s\n",temp->mobile);
		i++;
		pos_cursor(15,i);
		printf("Email: %s\n",temp->email);
		i=i+2;
		temp=temp->next;
	}
	pos_cursor(3,36);
	printf("Enter any key to continue...  ");
	ch=toupper(getche());
	customer();
}
void search_customer(){
	system("cls");
	subbox();
	pos_cursor(30,3);
	printf("-----------------------");
	pos_cursor(33,4);
	printf("Search a Customer");
	pos_cursor(30,5);
	printf("-----------------------");
	pos_cursor(5,10);
	struct customer* temp;
	temp=customerise;
	int found=0;
	printf("Enter the name of the customer: ");
	char key[30];
	gets(key);
	while(temp!=NULL){
		if(strcmp(key,temp->name)==0){
			pos_cursor(5,12);
			printf("Customer found :)");
			pos_cursor(5,14);
			printf("Customer ID: %d",temp->cust_id);
			pos_cursor(5,15);
			printf("Name: ");
			puts(temp->name);
			pos_cursor(5,16);
			printf("City: ");
			puts(temp->city);
			pos_cursor(5,17);
			printf("Mobile Number: %s",temp->mobile);
			pos_cursor(5,18);
			printf("Email Address: %s",temp->email);
			found=1;
			pos_cursor(5,19);
			printf("Enter any key to go Main Menu: ");
			ch=toupper(getche());
			supplier();
			break;
		}
		else{
			temp=temp->next;
		}
	}
	if(found==0){
		pos_cursor(3,35);
		printf("Customer Not Found!!!");
		pos_cursor(3,36);
		printf("Search again(Y/N)");
		ch=toupper(getche());
		switch(ch){
			case 'Y':
				search_customer();
				break;
			default:
				customer();
				break;
		}
	}
}
void medicine(){
	system("cls");
	subbox();
	pos_cursor(34,3);
	printf("------------------");
	pos_cursor(35,4);
	printf("Medicine Info");
	pos_cursor(34,5);
	printf("------------------");
	pos_cursor(25,11);
	printf("Purchase New Medicine");
	pos_cursor(26,15);
	printf("Sell Medicine");
	pos_cursor(25,19);
	printf("Available Stock");
	pos_cursor(25,23);
	printf("Find Medicine");
	pos_cursor(25,27);
	printf("Main Menu");
	pos_cursor(3,36);
	printf("Enter First Character to Proceed: ");
	ch=toupper(getche());
	switch(ch)
	{
	case 'P':
		action();
		purchase_medicine();
		break;
	case 'S':
		sell_medicine();
		action();
		break;
	case 'A':
		medicine_list();
		action();
		break;
	case 'F':
		find_medicine();
		action();
		break;
	case 'M':
		action();
		home();
		break;
	default:
		pos_cursor(11,34);
		printf("Invalid. Enter from these characters only (A,U,L,S,M).");
		Sleep(4000);
		medicine();
	  }
}
void purchase_medicine(){
	system("cls");
	subbox();
	pos_cursor(34,3);
	printf("-------------------");
	pos_cursor(36,4);
	printf("Purchase Medicine");
	pos_cursor(34,5);
	printf("-------------------");
	medi_id++;
	pos_cursor(5,10);
	printf("Medicine ID: ");
	pos_cursor(5,15);
	printf("Medicine Name: ");
	pos_cursor(45,10);
	printf("Supplier Name: ");
	pos_cursor(45,15);
	printf("Quantity: ");
	pos_cursor(5,20);
	printf("Company Name: ");
	pos_cursor(45,20);
	printf("Rack Number: ");
	pos_cursor(5,25);
	printf("Unit price: ");
	pos_cursor(45,25);
	printf("Sales price: ");
	pos_cursor(5,30);
	printf("MFG.Date(dd/mm/yy): ");
	pos_cursor(45,30);
	printf("EXP.Date(dd/mm/yy): ");
	insert_medicine();
}
void insert_medicine(){
	struct medicine* temp=(struct medicine*)malloc(sizeof(struct medicine));
	temp->med_id=medi_id;
	pos_cursor(18,10);
	printf("%d",temp->med_id);
	pos_cursor(20,15);
	fflush(stdin);
	gets(temp->name);
	pos_cursor(19,20);
	gets(temp->company);
	pos_cursor(60,10);
	gets(temp->supplier_name);
	pos_cursor(55,15);
	scanf("%d",&temp->quantity);
	pos_cursor(58,20);
	scanf("%d",&temp->rack);
	pos_cursor(17,25);
	scanf("%f",&temp->unit);
	fflush(stdin);
	pos_cursor(58,25);
	scanf("%f",&temp->sales);
	pos_cursor(26,30);
	fflush(stdin);
	gets(temp->manu);
	pos_cursor(66,30);
	gets(temp->expir);
	temp->next=NULL;
	struct supplier* ptr=supplies;
	int found=0;
	while(ptr!=NULL){
		if(strcmp(temp->supplier_name,ptr->name)==0){
			found=1;
			break;
		}
		else{
			ptr=ptr->next;
		}
	}
	if(found==1){
		if(medi==NULL){
			medi=temp;
		}
		else{
			struct medicine* ptr;
			ptr=medi;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			ptr->next=temp;
		}	
		pos_cursor(3,35);
		printf("Medicine Added successfully :)\n");
		FILE* f1;
		f1=fopen("Reports.txt","a");
		fputs("\nNew Medicine is Added\nDetails:",f1);
		fputs("\n",f1);
		fputs("Medicine ID: ",f1);
		char ch=medi_id+48;
		putw(ch,f1);
		fputs("\n",f1);
		fputs("Medicine Name: ",f1);
		fputs(temp->name,f1);
		fputs("\n",f1);
		fputs("Supplied by: ",f1);
		fputs(temp->supplier_name,f1);
		fputs("\n",f1);
		fputs("Company Name: ",f1);
		fputs(temp->company,f1);
		fputs("\n",f1);
		fputs("Quantity Added: ",f1);
		fprintf(f1,"%d",temp->quantity);
		fputs("\n",f1);
		fputs("Rack Number: ",f1);
		fprintf(f1,"%d",temp->rack);
		fputs("\n",f1);
		fputs("Manufacture Date: ",f1);
		fputs(temp->manu,f1);
		fputs("\n",f1);
		fputs("Expire Date: ",f1);
		fputs(temp->expir,f1);
		fputs("\n",f1);
		fclose(f1);
		pos_cursor(3,36);
		printf("Add more Medicine!(Y/N): ");
		ch=toupper(getche());
		if(ch=='Y'){
			purchase_medicine();
		}
		else{
		FILE *fptr,*fp1;
		fptr=fopen("Medicine.txt","w");
		fp1=fopen("Medicinelist.txt","w");
		if(fptr==NULL && fp1==NULL){
			printf("Can't open file :( ");
			Sleep(2000);
		}
		else{
			struct medicine* ptr=medi;
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n",fptr);
			fputs("Medicine ID: ",fptr);
			char ch=medi->med_id+48;
			putw(ch,fptr);
			fputs("\n",fptr);
			fputs("Medicine Name: ",fptr);
			fputs(medi->name,fptr);
			fputs(medi->name,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Supplier Name: ",fptr);
			fputs(medi->supplier_name,fptr);
			fputs(medi->supplier_name,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Company Name: ",fptr);
			fputs(medi->company,fptr);
			fputs(medi->company,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Quantity Left: ",fptr);
			fprintf(fptr,"%d",medi->quantity);
			fprintf(fp1,"%d",medi->quantity);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Rack Number: ",fptr);
			fprintf(fptr,"%d",medi->rack);
			fprintf(fp1,"%d",medi->rack);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Manufacture Date: ",fptr);
			fflush(stdin);
			fputs(medi->manu,fptr);
			fputs(medi->manu,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Expiry Date: ",fptr);
			fputs(medi->expir,fptr);
			fputs(medi->expir,fp1);
			fputs("\n",fptr);
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n",fptr);
			ptr=ptr->next;
			while(ptr!=NULL){
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n",fptr);
			fputs("Medicine ID: ",fptr);
			char ch=ptr->med_id+48;
			putw(ch,fptr);
			fputs("\n",fp1);
			fputs("\n",fptr);
			fputs("Medicine Name: ",fptr);
			fputs(ptr->name,fptr);
			fputs(ptr->name,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Supplier Name: ",fptr);
			fputs(ptr->supplier_name,fptr);
			fputs(ptr->supplier_name,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Company Name: ",fptr);
			fputs(ptr->company,fptr);
			fputs(ptr->company,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Quantity Left: ",fptr);
			fprintf(fptr,"%d",ptr->quantity);
			fprintf(fp1,"%d",ptr->quantity);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Rack Number: ",fptr);
			fprintf(fptr,"%d",ptr->rack);
			fprintf(fp1,"%d",ptr->rack);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Manufacture Date: ",fptr);
			fputs(ptr->manu,fptr);
			fputs(ptr->manu,fp1);
			fputs("\n",fptr);
			fputs("\n",fp1);
			fputs("Expiry Date: ",fptr);
			fputs(ptr->expir,fptr);
			fputs(ptr->expir,fp1);
			fputs("\n",fptr);
			fputs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n",fptr);
			ptr=ptr->next;
			}
	fclose(fptr);
	fclose(fp1);
	medicine();
	}
}
}
	else{
		medi_id--;
		pos_cursor(7,33);
		printf("No such Supplier Exists!!!");
		pos_cursor(7,34);
		printf("Add New Supplier(Y/N): ");
		ch=toupper(getche());
		switch(ch){
			case 'Y':
				add_supplier();
				break;
			default:
				Sleep(1000);
				medicine();
		}
	}
}
void sell_medicine(){
	system("cls");
	subbox();
	fflush(stdin);
	pos_cursor(34,3);
	printf("-------------------");
	pos_cursor(38,4);
	printf("Sell Medicine");
	pos_cursor(34,5);
	printf("-------------------");
	pos_cursor(5,10);
	printf("Medicine Name: ");
	pos_cursor(45,10);
	printf("Customer Name: ");
	pos_cursor(5,20);
	printf("Quantity Need: ");
	pos_cursor(45,25);
	printf("Unit Price: ");
	char medname[40];
	int quant;
	int unit,final;
	pos_cursor(20,10);
	gets(medname);
	fflush(stdin);
	pos_cursor(60,10);
	char custname[30];
	gets(custname);
	pos_cursor(20,20);
	scanf("%d",&quant);
	pos_cursor(57,25);
	scanf("%d",&unit);
	final=unit*quant;
	int found=0;
	struct customer* ptr=customerise;
	while(ptr!=NULL){
		if(strcmp(custname,ptr->name)==0){
			found=1;
			break;
		}
		else{
			ptr=ptr->next;
		}
	}
	if(found==1){
		pos_cursor(3,35);
		printf("Medicine Sold :)\n");
		pos_cursor(3,36);
		FILE* f1;
		f1=fopen("Reports.txt","a");
		fputs("\nNew Medicine is Sold\nDetails:",f1);
//		fputs("\n",f1);
//		fputs("Medicine ID: ",f1);
//		char ch=ptr->+48;
//		putw(ch,f1);
		fputs("\n",f1);
		fputs("Medicine Name: ",f1);
		fputs(medname,f1);
		fputs("\n",f1);
		fputs("Customer Name: ",f1);
		fputs(ptr->name,f1);
		fputs("\n",f1);
		fputs("Quantity brought: ",f1);
		char ch=quant+48;
		putw(ch,f1);
		fputs("\n",f1);
		fputs("Unit Price: ",f1);
		ch=unit+48;
		putw(ch,f1);
		fputs("\n",f1);
		fputs("Total: ",f1);
		ch=final+48;
		putw(ch,f1);
		fputs("\n",f1);
		fclose(f1);
		printf("Sell any more Medicine!(Y/N): ");
		ch=toupper(getche());
		if(ch=='Y'){
			sell_medicine();
		}
		else{
			Sleep(1000);
			medicine();
		}
	}
	else{
		pos_cursor(7,33);
		printf("No such Customer Exists!!!");
		pos_cursor(7,34);
		printf("Add New Customer(Y/N): ");
		ch=toupper(getche());
		switch(ch){
			case 'Y':
				sell_medicine();
				break;
			default:
				Sleep(1000);
				medicine();
		}
	}
}
void medicine_list(){
	system("cls");
	subbox();
	pos_cursor(30,3);
	printf("-----------------------");
	pos_cursor(33,4);
	printf("List of Medicines");
	pos_cursor(30,5);
	printf("-----------------------");
	pos_cursor(5,10);
	printf("The Medicine List is shown below: ");
	struct medicine* temp;
	temp=medi;
	int i=12;
	while(temp!=NULL){
		pos_cursor(15,i);
		printf("Medicine ID: %d",temp->med_id);
		i++;
		pos_cursor(15,i);
		printf("Medicine Name: ");
		puts(temp->name);
		i++;
		pos_cursor(15,i);
		printf("Supplier by: %s\n",temp->supplier_name);
		i++;
		pos_cursor(15,i);
		printf("Expiry Date: %s\n",temp->expir);
		i=i+2;
		temp=temp->next;
	}
	pos_cursor(3,36);
	printf("Enter any key to continue...  ");
	ch=toupper(getche());
	medicine();
}
void find_medicine(){
	system("cls");
	subbox();
	pos_cursor(30,3);
	printf("-----------------------");
	pos_cursor(33,4);
	printf("Find a Medicine");
	pos_cursor(30,5);
	printf("-----------------------");
	pos_cursor(5,10);
	struct medicine* temp;
	temp=medi;
	int found=0;
	printf("Enter the name of the Medicine: ");
	char key[30];
	gets(key);
	while(temp!=NULL){
		if(strcmp(key,temp->name)==0){
			pos_cursor(5,12);
			printf("Medicine found :)");
			pos_cursor(5,14);
			printf("Medicine ID: %d",temp->med_id);
			pos_cursor(5,15);
			printf("Medicine Name: ");
			puts(temp->name);
			pos_cursor(5,16);
			printf("Supplier Name: ");
			puts(temp->supplier_name);
			pos_cursor(5,17);
			printf("Expiry Date: %s",temp->expir);
			found=1;
			pos_cursor(5,19);
			printf("Enter any key to go Main Menu: ");
			ch=toupper(getche());
			medicine();
			break;
		}
		else{
			temp=temp->next;
		}
	}
	if(found==0){
		pos_cursor(3,35);
		printf("Medicine Not Found!!!");
		pos_cursor(3,36);
		printf("Search again(Y/N): ");
		ch=toupper(getche());
		switch(ch){
			case 'Y':
				find_medicine();
				break;
			default:
				medicine();
				break;
		}
	}
}
void report(){
	FILE* fptr;
	fptr=fopen("Reports.txt","r");
	action();
	system("cls");
	if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    ch = fgetc(fptr);
    while (ch != EOF)
    {
        printf ("%c", ch);
        ch = fgetc(fptr);
    }
    fclose(fptr);
    printf("\nEnter any key to Main Menu...");
    ch=toupper(getche());
    home();
}

void about(){
	system("cls");
	subbox();
	pos_cursor(30,3);
	printf("--------------");
	pos_cursor(33,4);
	printf("About Us");
	pos_cursor(30,5);
	printf("--------------");
	pos_cursor(8,10);
	printf("$$$ This Project is about Medical Store Management System");
	pos_cursor(8,11);
	printf("$$$ Here we have 3 main sections i.e., Suppliers,Customers");
	pos_cursor(5,12);
	printf("and Medicine");
	pos_cursor(8,13);
	printf("$$$ Each of them could be easily Accessed, Modified and Removed");
	pos_cursor(8,14);
	printf("$$$ We use Data Structures in C (Single Linked List) to store");
	pos_cursor(5,15);
	printf("details and hence modified");
	pos_cursor(8,16);
	printf("$$$ Every details and activities are monitered and stored in Files");
	pos_cursor(8,17);
	printf("$$$ We use unique functions that are defined in the header File");
	pos_cursor(5,18);
	printf("windows.h and time.h");
	pos_cursor(8,19);
	printf("$$$ From windows.h we could build a function that could move the");
	pos_cursor(5,20);
	printf("output cursor at specified position");
	pos_cursor(8,21);
	printf("$$$ From time.h we could build a function that could output us the");
	pos_cursor(5,22);
	printf("current time");
	pos_cursor(8,23);
	printf("$$$ Enter any key to go Main Menu: ");
	ch=toupper(getche());
	home();
}
