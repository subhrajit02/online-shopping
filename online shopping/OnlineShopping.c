/*onlinebm
password*/
#define LENGTH 100
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int id1=1000;
typedef struct max_purchase_tag
{
	char cname[LENGTH];
	char pname[LENGTH];
	int orders;
	struct max_purchase_tag *next;
}max_purchase;

typedef struct cardpay_tag
{
	int number;
	char card[17];
	char date[10];
}cardpay;

typedef struct id_pay_tag
{
	char id[50];
	int number;
}id_pay;

typedef struct Orders_tag
{
	char pay_method[100];
	struct Orders_tag *next;
}Orders;

//INFO OF EVERY PRODUCT
typedef struct Product_tag
{
	char name[LENGTH];
	int quantity;
	float cost;
	int orders;
	Orders *order_pay;
	int count;
}Product;

//MOBILE PHONE INFORMATION
typedef struct Mobile_Phone_tag
{
	Product product;
	struct Mobile_Phone_tag *next;
}Mobile_Phone;

//MOBILE ACCESSORIES INFORMATION
typedef struct Mobile_Accessories_tag
{
	Product product;
	struct Mobile_Accessories_tag *next;
}Mobile_Accessories;


//COMPUTER AND ACCESSORIES INFORMATION
typedef struct Computer_tag
{
	Product product;
	struct Computer_tag *next;
}Computer;


//ELECTRONICS INFORMATION
typedef struct Electronics_tag
{
	Product product;
	struct Electronics_tag *next;
}Electronics;


//GAMING INFORMATION
typedef struct Gaming_tag
{
	Product product;
	struct Gaming_tag *next;
}Gaming;


//APPLIANCES INFORMATION
typedef struct Appliances_tag
{
	Product product;
	struct Appliances_tag *next;
}Appliances;








typedef struct Wishlist_tag
{
	Mobile_Phone *phones;
	Mobile_Accessories *accessories;
	Computer *computer;
	Electronics *electronics;
	Gaming *gaming;
	Appliances *appliances;
	//struct Wishlist_tag*next;
}Wishlist;

typedef struct History_tag
{
	Mobile_Phone *phones;
	Mobile_Accessories *accessories;
	Computer *computer;
	Electronics *electronics;
	Gaming *gaming;
	Appliances *appliances;
	//struct History_tag*next;
}History;




typedef struct payment_tag
{
	int BNPL_number;
	int COD_number;
	cardpay debit;
	cardpay credit;
	id_pay netbanking;
	id_pay upi;
	id_pay phonepe;
	struct payment_tag*next;
}Payment;

//CONSUMER INFORMATION
typedef struct Consumer_tag
{
	char name[LENGTH];
	char email_id[LENGTH];
	char mobile_number[LENGTH];
	char address[LENGTH];
	char password[LENGTH];
	int id;
	char favourite_purchase[LENGTH];
	Wishlist wishlist;
	History history;	
	Payment payment;
	int fav_payment;
	char fav_payment_mode[LENGTH];
	float refund;
	struct Consumer_tag *next;
}Consumer;


typedef struct List_tag
{
	Consumer *c;
	struct List_tag *next;
}List;

Mobile_Phone*mobile(Mobile_Phone*);
Mobile_Accessories*mobileacc(Mobile_Accessories*);
Electronics*electronics(Electronics*);
Computer*computer(Computer*);
Gaming*game(Gaming*);
Appliances*appliances(Appliances*);
Consumer* signup(Consumer* consumer,List *list[]);
Consumer* signupf(Consumer* consumer,List *list[]);
void signupw(Consumer* consumer);
Consumer* login(Consumer *consumer,int *correct,List *list[]);
void loggedin(Consumer *consumer,Mobile_Phone *mobptr,Mobile_Accessories *mobaccptr,Electronics *elecptr,Computer *cmpptr,Gaming *gamptr,Appliances *appptr,Consumer *user);
void printcustomerinfo(Consumer *consumer);
void printwishlist(Consumer *consumer);
void printhistory(Consumer *consumer);
void payment_mode(Consumer*consumer);
void print_fav_mode(Consumer*consumer,int,char pay[]);
void frequent_purchase(Consumer *consumer);
void max_purchaser(Consumer *consumer);
void top_gadgets(Mobile_Phone **mobpptr,Mobile_Accessories **mobaccpptr,Electronics **elecpptr,Computer **cmppptr,Gaming **gampptr,Appliances **apppptr);
int hash1(char*str);
void refund_function(char acc[]);
Mobile_Phone*mobilef(Mobile_Phone*);
Mobile_Accessories*mobileaccf(Mobile_Accessories*);
Electronics*electronicsf(Electronics*);
Computer*computerf(Computer*);
Gaming*gamef(Gaming*);
Appliances*appliancesf(Appliances*);

void mobilew(Mobile_Phone*);
void mobileaccw(Mobile_Accessories*);
void electronicsw(Electronics*);
void computerw(Computer*);
void gamew(Gaming*);
void appliancesw(Appliances*);
void main()
{
	Mobile_Phone *mobptr1,*mobptr=NULL;
	Mobile_Accessories *mobaccptr1,*mobaccptr=NULL;
	Electronics *elecptr1,*elecptr=NULL;
	Computer *cmpptr1,*cmpptr=NULL;
	Gaming *gamptr1,*gamptr=NULL;
	Appliances *appptr1,*appptr=NULL;
	Consumer *consumer,*user;
	consumer=NULL;
	mobptr=mobilef(mobptr);
	mobaccptr=mobileaccf(mobaccptr);						
	elecptr=electronicsf(elecptr);					
	cmpptr=computerf(cmpptr);					
	gamptr=gamef(gamptr);					
	appptr=appliancesf(appptr);
	int flag=1;
	int num,num1,num3;
	int correct=0;
	char pass[LENGTH];
	char name[LENGTH];
	int cmp1,cmp2,ff;
	List *list[50],*list2,*list3;
	int j,i;
	for(j=0;j<50;j++)
	{
		list[j]=NULL;
	}
	consumer=signupf(consumer,list);
	printf("\nWELCOME TO ONLINE BAZAAR\n");
	while(flag==1)
	{
		printf("1.SIGNUP\n2.LOGIN\n3.LOGIN MERCHANTS\n4.LIST OF ALL PRODUCTS\n5.EXIT\n");
		printf("\nPLEASE ENTER CHOICE\n");
		scanf("%d",&num);
		switch(num)
		{
			case 1:
			consumer=signup(consumer,list);
			j=(consumer->id)%50;
			if(list[j]==NULL)
			{
				list2=malloc(sizeof(List));
				list2->c = consumer;
				list2->next =  NULL;
				list[j]=list2;
			}
			else
			{
				list2=list[j];
				while(list2->next!=NULL)
				{
					list2 = list2->next;
				}
				list3=malloc(sizeof(List));
				list2->next = list3;
				list3->next = NULL;
				list3->c = consumer;
				
			}
			break;
			
			case 2:
			user=login(consumer,&correct,list);
			if(correct==1)
			{
				loggedin(user,mobptr,mobaccptr,elecptr,cmpptr,gamptr,appptr,consumer);
			}
			else
			{
				printf("\nINCORRECT ID OR PASSWORD\n");
			}
			correct=0;
			break;
			
			case 3:
			
			printf("\nONILNE BAZAR MERCHANT LOGIN PAGE\n");
			ff=1;
			printf("\nENTER MERCHANT ID\n");
			scanf("%s",name);
			printf("\nENTER MERCHANT PASSWORD\n");
			scanf("%s",pass);
			cmp1=strcmp(name,"onlinebm");
			cmp2=strcmp(pass,"password");
			if(cmp1==0 && cmp2==0)
			{
				do
				{
					printf("\n1.MOBILE PHONES\n2.MOBILE ACCESSORIES\n3.ELECTRONICS\n4.COMPUTER\n5.GAMING\n6.APPLIANCES\n7.ADD TO CURRENT MOBILE PHONES\n8.ADD TO CURRENT MOBILE ACCESSORIES\n9.ADD TO CURRENT ELECTRONICS\n10.ADD TO CURRENT COMPUTER\n11.ADD TO CURRENT GAMING\n12.ADD TO CURRENT APPLIANCES\n13.LOGOUT\nENTER CHOICE\n");
					scanf("%d",&num1);
					switch(num1)
					{
						case 1:	
						mobptr=mobile(mobptr);
						break;
						
						case 2:
						mobaccptr=mobileacc(mobaccptr);
						break;
						
						case 3:
						elecptr=electronics(elecptr);
						break;
						
						case 4:
						cmpptr=computer(cmpptr);
						break;
						
						case 5:
						gamptr=game(gamptr);
						break;
							
						case 6:
						appptr=appliances(appptr);
						break;
						
						case 7:
						mobptr1=mobptr;
						printf("\nLIST OF PHONES\n");
						i=1;
						while(mobptr1!=NULL)
						{
						
							printf("%d. NAME - %s COST - %f \n",i,(mobptr1->product).name,(mobptr1->product).cost);
							i++;
							mobptr1=mobptr1->next;					
						}
						printf("\nENTER CHOICE\n");
						scanf("%d",&num3);
				
						mobptr1=mobptr;
						i=1;
						while(i<num3 && mobptr1!=NULL)
						{
							i++;
							mobptr1=mobptr1->next;
						}
						if(mobptr1==NULL)
						{
							printf("\nINVALID ORDER\n");
						}
						else
						{
							printf("\nENTER QUANTITY TO ADD\n");
							scanf("%d",&num3);
							(mobptr1->product).quantity  =(mobptr1->product).quantity + num3;
							printf("\nQUANTITY ADDED\n");
						}
						break;
						
						case 8:
						mobaccptr1=mobaccptr;
						printf("\nLIST OF MOBILE ACCESSORIES\n");
						i=1;
						while(mobaccptr1!=NULL)
						{
						
							printf("%d. NAME - %s COST - %f \n",i,(mobaccptr1->product).name,(mobaccptr1->product).cost);
							i++;
							mobaccptr1=mobaccptr1->next;					
						}
						printf("\nENTER CHOICE\n");
						scanf("%d",&num3);
				
						mobaccptr1=mobaccptr;
						i=1;
						while(i<num3 && mobaccptr1!=NULL)
						{
							i++;
							mobaccptr1=mobaccptr1->next;
						}
						if(mobaccptr1==NULL)
						{
							printf("\nINVALID ORDER\n");
						}
						else
						{
							printf("\nENTER QUANTITY TO ADD\n");
							scanf("%d",&num3);
							(mobaccptr1->product).quantity  =(mobaccptr1->product).quantity + num3;
							printf("\nQUANTITY ADDED\n");
						}
						break;
						
						case 9:
						elecptr1=elecptr;
						printf("\nLIST OF ELECTRONICS\n");
						i=1;
						while(elecptr1!=NULL)
						{
						
							printf("%d. NAME - %s COST - %f \n",i,(elecptr1->product).name,(elecptr1->product).cost);
							i++;
							elecptr1=elecptr1->next;					
						}
						printf("\nENTER CHOICE\n");
						scanf("%d",&num3);
				
						elecptr1=elecptr;
						i=1;
						while(i<num3 && elecptr1!=NULL)
						{
							i++;
							elecptr1=elecptr1->next;
						}
						if(elecptr1==NULL)
						{
							printf("\nINVALID ORDER\n");
						}
						else
						{
							printf("\nENTER QUANTITY TO ADD\n");
							scanf("%d",&num3);
							(elecptr1->product).quantity  =(elecptr1->product).quantity + num3;
							printf("\nQUANTITY ADDED\n");
						}
						break;
						
						case 10:
						cmpptr1=cmpptr;
						printf("\nLIST OF COMPUTERS\n");
						i=1;
						while(cmpptr1!=NULL)
						{
						
							printf("%d. NAME - %s COST - %f \n",i,(cmpptr1->product).name,(cmpptr1->product).cost);
							i++;
							cmpptr1=cmpptr1->next;					
						}
						printf("\nENTER CHOICE\n");
						scanf("%d",&num3);
				
						cmpptr1=cmpptr;
						i=1;
						while(i<num3 && cmpptr1!=NULL)
						{
							i++;
							cmpptr1=cmpptr1->next;
						}
						if(cmpptr1==NULL)
						{
							printf("\nINVALID ORDER\n");
						}
						else
						{
							printf("\nENTER QUANTITY TO ADD\n");
							scanf("%d",&num3);
							(cmpptr1->product).quantity  =(cmpptr1->product).quantity + num3;
							printf("\nQUANTITY ADDED\n");
						}
						break;
						
						case 11:
						gamptr1=gamptr;
						printf("\nLIST OF GAMING\n");
						i=1;
						while(gamptr1!=NULL)
						{
						
							printf("%d. NAME - %s COST - %f \n",i,(gamptr1->product).name,(gamptr1->product).cost);
							i++;
							gamptr1=gamptr1->next;					
						}
						printf("\nENTER CHOICE\n");
						scanf("%d",&num3);
				
						gamptr1=gamptr;
						i=1;
						while(i<num3 && gamptr1!=NULL)
						{
							i++;
							gamptr1=gamptr1->next;
						}
						if(gamptr1==NULL)
						{
							printf("\nINVALID ORDER\n");
						}
						else
						{
							printf("\nENTER QUANTITY TO ADD\n");
							scanf("%d",&num3);
							(gamptr1->product).quantity  =(gamptr1->product).quantity + num3;
							printf("\nQUANTITY ADDED\n");
						}
						break;
						
						case 12:
						appptr1=appptr;
						printf("\nLIST OF ELECTRONICS\n");
						i=1;
						while(appptr1!=NULL)
						{
						
							printf("%d. NAME - %s COST - %f \n",i,(appptr1->product).name,(appptr1->product).cost);
							i++;
							appptr1=appptr1->next;					
						}
						printf("\nENTER CHOICE\n");
						scanf("%d",&num3);
				
						appptr1=appptr;
						i=1;
						while(i<num3 && appptr1!=NULL)
						{
							i++;
							appptr1=appptr1->next;
						}
						if(appptr1==NULL)
						{
							printf("\nINVALID ORDER\n");
						}
						else
						{
							printf("\nENTER QUANTITY TO ADD\n");
							scanf("%d",&num3);
							(appptr1->product).quantity = (appptr1->product).quantity +  num3;
							printf("\nQUANTITY ADDED\n");
						}
						break;
						
						case 13:
						ff=0;
						break;
					}
				}while(ff!=0);
			}
			else
			{
				printf("\nINVALID ID OR PASSWORD\n");
			}
			break;
			
			case 4:
			mobptr1=mobptr;
			printf("\nLIST OF PHONES\n");
			i=1;
			while(mobptr1!=NULL)
			{
					
				printf("%d. NAME - %s COST - %f \n",i,(mobptr1->product).name,(mobptr1->product).cost);
				i++;
				mobptr1=mobptr1->next;					
			}
			
			mobaccptr1=mobaccptr;
			printf("\nLIST OF PHONE ACCESSORIES\n");
			i=1;
			while(mobaccptr1!=NULL)
			{
				printf("%d. NAME - %s COST - %f \n",i,(mobaccptr1->product).name,(mobaccptr1->product).cost);
				i++;
				mobaccptr1=mobaccptr1->next;					
			}
			
			elecptr1=elecptr;
			printf("\nLIST OF ELECTRONICS\n");
			i=1;
			while(elecptr1!=NULL)
			{
				printf("%d. NAME - %s COST - %f \n",i,(elecptr1->product).name,(elecptr1->product).cost);
				i++;
				elecptr1=elecptr1->next;					
			}
			
			cmpptr1=cmpptr;
			printf("\nLIST OF COMPUTER \n");
			i=1;
			while(cmpptr1!=NULL)
			{
				printf("%d. NAME - %s COST - %f ",i,(cmpptr1->product).name,(cmpptr1->product).cost);
				i++;
				cmpptr1=cmpptr1->next;					
			}
			
			gamptr1=gamptr;
			printf("\nLIST OF GAMING\n");
			i=1;
			while(gamptr1!=NULL)
			{
				printf("%d. NAME - %s COST - %f \n",i,(gamptr1->product).name,(gamptr1->product).cost);
				i++;
				gamptr1=gamptr1->next;					
			}
			
			appptr1=appptr;
			printf("\nLIST OF APPLIANCES\n");
			i=1;
			while(appptr1!=NULL)
			{
				printf("%d. NAME - %s COST - %f ",i,(appptr1->product).name,(appptr1->product).cost);
				i++;
				appptr1=appptr1->next;					
			}
			break;
			
			case 5:
			mobilew(mobptr);
			mobileaccw(mobaccptr);						
			electronicsw(elecptr);					
			computerw(cmpptr);					
			gamew(gamptr);					
			appliancesw(appptr);
			signupw(consumer);
			printf("\nGOODBYE\n");
			flag=0;
			break;
			
		}
		printf("***********************\n");
		printf("***********************\n");
	}

}

Consumer* signup(Consumer* consumer,List *list[])
{
	char username[100];
	List *l;int f=0;
	printf("\nWELCOME TO ONLINE BAZAAR SIGNUP PAGE\n");
	Consumer *nptr;
	nptr=(Consumer*)malloc(sizeof(Consumer));
	printf("\nUSE UNDERSCORE(_)IN PLACE OF SPACE\n");
	//printf("\nENTER YOUR NAME\n");
	//scanf("%s",nptr->name);
	printf("\nENTER YOUR EMAIL ID\n");
	scanf("%s",nptr->email_id);
	printf("\nENTER YOUR MOBILE NUMBER\n");
	scanf("%s",nptr->mobile_number);
	printf("\nENTER YOUR ADDRESS\n");
	scanf("%s",nptr->address);
	//id1=hash1(nptr->name);
	//nptr->id=id1;
	do
	{
		f=0;
		printf("\nENTER YOUR NAME WHICH WILL BE USED AS USERNAME\n");
		scanf("%s",nptr->name);
		id1=hash1(nptr->name);
		nptr->id=id1;
		printf("\nENTER PASSWORD\n");
		scanf("%s",nptr->password);	
		l=list[id1%50];
		while(l!=NULL && f==0)
		{
			if(strcmp(l->c->password,nptr->password)==0)
			{
				printf("\nUSERNAME ALREADY TAKEN\n");
				f=1;
			}	
			l=l->next;
		}
	}while(f==1);
	printf("\nCONGRATULATIONS..YOU HAVE JUST SIGNED UP\n");
	printf("YOUR ID IS %d\n",id1);
	nptr->refund=0.0;
	strcpy((nptr->favourite_purchase),"none");
	strcpy((nptr->fav_payment_mode),"none");
	nptr->wishlist.phones=NULL;
	nptr->wishlist.computer=NULL;
	nptr->wishlist.accessories=NULL;
	nptr->wishlist.electronics=NULL;
	nptr->wishlist.gaming=NULL;
	nptr->wishlist.appliances=NULL;
	
	nptr->history.phones=NULL;
	nptr->history.computer=NULL;
	nptr->history.accessories=NULL;
	nptr->history.electronics=NULL;
	nptr->history.gaming=NULL;
	nptr->history.appliances=NULL;

	nptr->payment.BNPL_number=0;
	nptr->payment.COD_number=0;
	nptr->payment.debit.number=0;
	nptr->payment.credit.number=0;
	nptr->payment.netbanking.number=0;
	nptr->payment.upi.number=0;
	nptr->payment.phonepe.number=0;
	nptr->payment.next=NULL;
	nptr->fav_payment=0;

	nptr->next=consumer;
	return nptr;
}

Consumer* login(Consumer *consumer,int *correct,List *list[50])
{
	printf("\nONILNE BAZAR LOGIN PAGE\n");

	int cmp,i;
	char pass[10];
	printf("\nENTER YOUR ID\n");
	scanf("%d",&i);
	printf("\nENTER YOUR PASSWORD\n");
	scanf("%s",pass);
	Consumer *ptr;
	int j=i%50;
	List *l;
	l=list[j];
	while(l!=NULL && (*correct!=1))
	{
		if(l->c->id==i)
		{
			cmp=strcmp((l->c->password),pass);
			if(cmp==0)
			{
				*correct=1;
				ptr=l->c;
			}
		}
		l=l->next;
	}
	/*
	while((consumer!=NULL)&&(*correct!=1))
	{
		if(consumer->id==i)
		{
			cmp=strcmp((consumer->password),pass);
			if(cmp==0)
			{
				*correct=1;
				ptr=consumer;
			}
		}
		consumer=consumer->next;
	}
	*/
	return ptr;
}


void loggedin(Consumer *consumer,Mobile_Phone *mobptr,Mobile_Accessories *mobaccptr,Electronics *elecptr,Computer *cmpptr,Gaming *gamptr,Appliances *appptr,Consumer *user)
{
	int flag=1;
	int num;
	int num2;
	int num3;
	Mobile_Phone *mobptr1,*mobptr2,*mobptr3,*mobptr5=mobptr;
	Mobile_Accessories *mobaccptr1,*mobaccptr2,*mobaccptr3,*mobaccptr5=mobaccptr;
	Electronics *elecptr1,*elecptr2,*elecptr3,*elecptr5=elecptr;
	Computer *cmpptr1,*cmpptr2,*cmpptr3,*cmpptr5=cmpptr;
	Gaming *gamptr1,*gamptr2,*gamptr3,*gamptr5=gamptr;
	Appliances *appptr1,*appptr2,*appptr3,*appptr5=appptr;
	int i;
	Orders *op,*op1,*op2;
	op1=NULL;
	char pay[100],return_account[20];
	while(flag==1)
	{
		printf("=======================\n");
		printf("=======================\n");
		printf("1.SHOW WISHLIST\n2.SHOW HISTORY\n3.SHOW CUSTOMER INFORMATION\n4.UPDATE WISHLIST OR PLACE AN ORDER\n5.RETURN ORDER\n6.FAVOURITE ORDERS\n7.TOP GADGETS\n8.TOP GADGETS IN ORDER\n9.LOGOUT\n");
		printf("\nPLEASE ENTER CHOICE\n");
		scanf("%d",&num);
		switch(num)
		{
			case 1:
			printwishlist(consumer);
			break;
			
			case 2:
			printhistory(consumer);
			break;
			
			case 3:
			printcustomerinfo(consumer);
			break;
			
			case 4:
			printf("\n1.MOBILE PHONES\n2.MOBILE ACCESSORIES\n3.ELECTRONICS\n4.COMPUTER\n5.GAMING\n6.APPLIANCES\nENTER CHOICE\n");
			scanf("%d",&num2);
			int wish;
			switch(num2)
			{
				case 1:
				mobptr1=mobptr;
				printf("\nLIST OF PHONES\n");
				i=1;
				while(mobptr1!=NULL)
				{
					
					printf("%d. NAME - %s COST - %f \n",i,(mobptr1->product).name,(mobptr1->product).cost);
					i++;
					mobptr1=mobptr1->next;					
				}
				printf("\nENTER CHOICE\n");
				scanf("%d",&num3);
				
				mobptr1=mobptr;
				i=1;
				while(i<num3 && mobptr1!=NULL)
				{
					i++;
					mobptr1=mobptr1->next;
				}
				if(mobptr1==NULL)
				{
					printf("\nINVALID ORDER\n");
				}
				else
				{
					int x=(mobptr1->product).quantity;
					printf("ENTER 0 TO ADD TO WISHLIST \nENTER 1 TO ORDER");
					scanf("%d",&wish);
					if(wish==1)
					{
						if(x==0)
						{
							printf("\nSORRY....ITEM OUT OF STOCK\n");
						}
						else
						{
							if(consumer->fav_payment==0)
							{
								payment_mode(consumer);
								print_fav_mode(consumer,0,pay);
							}
							else
							{
								print_fav_mode(consumer,0,pay);
							}
							printf("\nORDER PLACED SUCCESSFULLY\n");
							(mobptr1->product).quantity=x-1;
							(mobptr1->product).orders++;
							mobptr2=(consumer->history).phones;
							int f=0;
							while(mobptr2!=NULL && f==0)
							{
								if(strcmp((mobptr2->product).name,(mobptr1->product).name)==0)
								{
									(mobptr2->product).orders =(mobptr2->product).orders + 1;
									f=1;
									/*
									op=malloc(sizeof(Orders));
									strcpy(op->pay_method,pay);
									op1=mobptr2->product.order_pay;
									op->next=op1;
									mobptr2->product.order_pay=op;
									*/
								}
								mobptr2=mobptr2->next;
							}
							if(f==0)
							{
								mobptr2=malloc(sizeof(Mobile_Phone));
								strcpy((mobptr2->product).name,(mobptr1->product).name); // CHANGE ARRAY ASSIGNMENT OVER HERE
								(mobptr2->product).cost=(mobptr1->product).cost;
								(mobptr2->product).orders=1;
								mobptr2->next=(consumer->history).phones;
								(consumer->history).phones=mobptr2;
								/*
								op=malloc(sizeof(Orders));
								strcpy(op->pay_method,pay);
								op->next=NULL;
								mobptr2->product.order_pay=op;
								*/
								//strcpy(mobptr2->product.pay_method,pay);
							}
							
						}
					}
					else if(wish==0)
					{
						mobptr2=(consumer->wishlist).phones;
						int f=0;
						while(mobptr2!=NULL && f==0)
						{
							if(strcmp((mobptr2->product).name,(mobptr1->product).name)==0)
							{
								printf("\nITEM ALREADY IN WISHLIST\n");
								//(mobptr2->product).orders =(mobptr2->product).orders + 1;
								f=1;
							}
							mobptr2=mobptr2->next;
						}
						if(f==0)
						{
							printf("\nITEM ADDED TO WISHLIST\n");
							mobptr2=malloc(sizeof(Mobile_Phone));
							
							strcpy((mobptr2->product).name,(mobptr1->product).name); // CHANGE ARRAY ASSIGNMENT OVER HERE
							(mobptr2->product).cost=(mobptr1->product).cost;
							(mobptr2->product).orders=1;
							mobptr2->next=(consumer->wishlist).phones;
							(consumer->wishlist).phones=mobptr2;
						}	
					}	
				}
				break;
			
				case 2:
				mobaccptr1=mobaccptr;
				printf("\nLIST OF PHONE ACCESSORIES\n");
				i=1;
				while(mobaccptr1!=NULL)
				{
					printf("%d. NAME - %s COST - %f \n",i,(mobaccptr1->product).name,(mobaccptr1->product).cost);
					i++;
					mobaccptr1=mobaccptr1->next;					
				}
				printf("\nENTER CHOICE\n");
				scanf("%d",&num3);
				mobaccptr1=mobaccptr;
				i=1;
				while(i<num3 && mobaccptr1!=NULL)
				{
					i++;
					mobaccptr1=mobaccptr1->next;	
				}
				if(mobaccptr1==NULL)
				{
					printf("\nINVALID ORDER\n");
				}
				else
				{
					int x=(mobaccptr1->product).quantity;
					printf("ENTER 0 TO ADD TO WISHLIST \nENTER 1 TO ORDER");
					scanf("%d",&wish);
					if(wish==1)
					{ 
						if(x==0)
						{
							printf("\nSORRY....ITEM OUT OF STOCK\n");
						}
						else
						{
							if(consumer->fav_payment==0)
							{
								payment_mode(consumer);
								print_fav_mode(consumer,0,pay);
							}
							else
							{
								print_fav_mode(consumer,0,pay);
							}
							printf("\nORDER PLACED SUCCESSFULLY\n");
							(mobaccptr1->product).quantity=x-1;
							(mobaccptr1->product).orders++;
							mobaccptr2=(consumer->history).accessories;
							int f=0;
							while(mobaccptr2!=NULL && f==0)
							{
								if(strcmp((mobaccptr2->product).name,(mobaccptr1->product).name)==0)
								{
									(mobaccptr2->product).orders =(mobaccptr2->product).orders + 1;
									f=1;
									/*
									op=malloc(sizeof(Orders));
									strcpy(op->pay_method,pay);
									op1=mobaccptr2->product.order_pay;
									op->next=op1;
									mobaccptr2->product.order_pay=op;
									*/
								}
								mobaccptr2=mobaccptr2->next;
							}
							if(f==0)
							{
								mobaccptr2=malloc(sizeof(Mobile_Accessories));
								strcpy((mobaccptr2->product).name,(mobaccptr1->product).name); // CHANGE ARRAY ASSIGNMENT OVER HERE
								(mobaccptr2->product).cost=(mobaccptr1->product).cost;
								(mobaccptr2->product).orders=1;
								mobaccptr2->next=(consumer->history).accessories;
								(consumer->history).accessories=mobaccptr2;
								/*
								op=malloc(sizeof(Orders));
								strcpy(op->pay_method,pay);
								//op1=mobptr2->product.order_pay;
								op->next=op1;
								mobaccptr2->product.order_pay=op;
								*/
								//strcpy(mobaccptr2->product.pay_method,pay);
							}
						}
					}
					else if(wish==0)
					{
						mobaccptr2=(consumer->wishlist).accessories;
						int f=0;
						while(mobaccptr2!=NULL && f==0)
						{
							if(strcmp((mobaccptr2->product).name,(mobaccptr1->product).name)==0)
							{
								printf("\nITEM ALREADY IN WISHLIST\n");
								//(mobaccptr2->product).orders =(mobaccptr2->product).orders + 1;
								f=1;
							}
							mobaccptr2=mobaccptr2->next;
						}
						if(f==0)
						{
							printf("\nITEM ADDED TO WISHLIST\n");
							mobaccptr2=malloc(sizeof(Mobile_Accessories));		
							strcpy((mobaccptr2->product).name,(mobaccptr1->product).name); // CHANGE ARRAY ASSIGNMENT OVER HERE
							(mobaccptr2->product).cost=(mobaccptr1->product).cost;
							(mobaccptr2->product).orders=1;
							mobaccptr2->next=(consumer->wishlist).accessories;
							(consumer->wishlist).accessories=mobaccptr2;
						}
					}
				}				
				break;
			
				case 3:
				
				
				
				elecptr1=elecptr;
				printf("\nLIST OF ELECTRONICS\n");
				i=1;
				while(elecptr1!=NULL)
				{
					printf("%d. NAME - %s COST - %f \n",i,(elecptr1->product).name,(elecptr1->product).cost);
					i++;
					elecptr1=elecptr1->next;					
				}
				printf("\nENTER CHOICE\n");
				scanf("%d",&num3);
				//int wish;
				elecptr1=elecptr;
				i=1;
				while(i<num3 && elecptr1!=NULL)
				{
					i++;
					elecptr1=elecptr1->next;
				}
				if(elecptr1==NULL)
				{
					printf("\nINVALID ORDER\n");
				}
				else
				{
					int x=(elecptr1->product).quantity;
					printf("ENTER 0 TO ADD TO WISHLIST \nENTER 1 TO ORDER");
					scanf("%d",&wish);
					if(wish==1)
					{
						if(x==0)
						{
							printf("\nSORRY....ITEM OUT OF STOCK\n");
						}
						else
						{
							if(consumer->fav_payment==0)
							{
								payment_mode(consumer);
								print_fav_mode(consumer,0,pay);
							}
							else
							{
								print_fav_mode(consumer,0,pay);
							}
							printf("\nORDER PLACED SUCCESSFULLY\n");
							(elecptr1->product).quantity=x-1;
							(elecptr1->product).orders++;
							elecptr2=(consumer->history).electronics;
							int f=0;
							while(elecptr2!=NULL && f==0)
							{
								if(strcmp((elecptr2->product).name,(elecptr1->product).name)==0)
								{
									(elecptr2->product).orders =(elecptr2->product).orders + 1;
									f=1;
									/*
									op=malloc(sizeof(Orders));
									strcpy(op->pay_method,pay);
									op1=elecptr2->product.order_pay;
									op->next=op1;
									elecptr2->product.order_pay=op;
									*/
								}
								elecptr2=elecptr2->next;
							}
							if(f==0)
							{
								elecptr2=malloc(sizeof(Electronics));
								
								strcpy((elecptr2->product).name,(elecptr1->product).name); // CHANGE ARRAY ASSIGNMENT OVER HERE
								(elecptr2->product).cost=(elecptr1->product).cost;
								(elecptr2->product).orders=1;
								elecptr2->next=(consumer->history).electronics;
								(consumer->history).electronics=elecptr2;
								//strcpy(elecptr2->product.pay_method,pay);
								/*
								op=malloc(sizeof(Orders));
								strcpy(op->pay_method,pay);
								//op1=elecptr2->product.order_pay;
								op->next=op1;
								elecptr2->product.order_pay=op;
								*/
							}
						}
					}
					else if(wish==0)
					{
						elecptr2=(consumer->wishlist).electronics;
						int f=0;
						while(elecptr2!=NULL && f==0)
						{
							if(strcmp((elecptr2->product).name,(elecptr1->product).name)==0)
							{
								printf("\nITEM ALREADY IN WISHLIST\n");
								//(elecptr2->product).orders =(elecptr2->product).orders + 1;
								f=1;
							}
							elecptr2=elecptr2->next;
						}
						if(f==0)
						{
							printf("\nITEM ADDED TO WISHLIST\n");
							elecptr2=malloc(sizeof(Electronics));
							
							strcpy((elecptr2->product).name,(elecptr1->product).name); // CHANGE ARRAY ASSIGNMENT OVER HERE
							(elecptr2->product).cost=(elecptr1->product).cost;
							(elecptr2->product).orders=1;
							elecptr2->next=(consumer->wishlist).electronics;
							(consumer->wishlist).electronics=elecptr2;
						}	
					}	
				}
				break;
			
				case 4:
				cmpptr1=cmpptr;
				printf("\nLIST OF COMPUTER \n");
				i=1;
				while(cmpptr1!=NULL)
				{
					printf("%d. NAME - %s COST - %f \n",i,(cmpptr1->product).name,(cmpptr1->product).cost);
					i++;
					cmpptr1=cmpptr1->next;					
				}
				printf("\nENTER CHOICE\n");
				scanf("%d",&num3);
				//int wish;
				cmpptr1=cmpptr;
				i=1;
				while(i<num3 && cmpptr1!=NULL)
				{
					i++;
					cmpptr1=cmpptr1->next;
				}
				if(cmpptr1==NULL)
				{
					printf("\nINVALID ORDER\n");
				}
				else
				{
					int x=(cmpptr1->product).quantity;
					printf("ENTER 0 TO ADD TO WISHLIST \nENTER 1 TO ORDER");
					scanf("%d",&wish);
					if(wish==1)
					{
						if(x==0)
						{
							printf("\nSORRY....ITEM OUT OF STOCK\n");
						}
						else
						{
							if(consumer->fav_payment==0)
							{
								payment_mode(consumer);
								print_fav_mode(consumer,0,pay);
							}
							else
							{
								print_fav_mode(consumer,0,pay);
							}
							printf("\nORDER PLACED SUCCESSFULLY\n");
							(cmpptr1->product).quantity=x-1;
							(cmpptr1->product).orders++;
							cmpptr2=(consumer->history).computer;
							int f=0;
							while(cmpptr2!=NULL && f==0)
							{
								if(strcmp((cmpptr2->product).name,(cmpptr1->product).name)==0)
								{
									(cmpptr2->product).orders =(cmpptr2->product).orders + 1;
									f=1;
									/*
									op=malloc(sizeof(Orders));
									strcpy(op->pay_method,pay);
									op1=cmpptr2->product.order_pay;
									op->next=op1;
									cmpptr2->product.order_pay=op;
									*/
								}
								cmpptr2=cmpptr2->next;
							}
							if(f==0)
							{
								cmpptr2=malloc(sizeof(Mobile_Accessories));
								
								strcpy((cmpptr2->product).name,(cmpptr1->product).name); // CHANGE ARRAY ASSIGNMENT OVER HERE
								(cmpptr2->product).cost=(cmpptr1->product).cost;
								(cmpptr2->product).orders=1;
								cmpptr2->next=(consumer->history).computer;
								(consumer->history).computer=cmpptr2;
								//strcpy(cmpptr2->product.pay_method,pay);
								/*
								op=malloc(sizeof(Orders));
								strcpy(op->pay_method,pay);
								//op1=cmpptr2->product.order_pay;
								op->next=op1;
								cmpptr2->product.order_pay=op;
								*/
							}
						}
					}
					else if(wish==0)
					{
						cmpptr2=(consumer->wishlist).computer;
						int f=0;
						while(cmpptr2!=NULL && f==0)
						{
							if(strcmp((cmpptr2->product).name,(cmpptr1->product).name)==0)
							{
								printf("\nITEM ALREADY IN WISHLIST\n");
								//(cmpptr2->product).orders =(cmpptr2->product).orders + 1;
								f=1;
							}
							cmpptr2=cmpptr2->next;
						}
						if(f==0)
						{
							printf("\nITEM ADDED TO WISHLIST\n");
							cmpptr2=malloc(sizeof(Computer));
							
							strcpy((cmpptr2->product).name,(cmpptr1->product).name); // CHANGE ARRAY ASSIGNMENT OVER HERE
							(cmpptr2->product).cost=(cmpptr1->product).cost;
							(cmpptr2->product).orders=1;
							cmpptr2->next=(consumer->wishlist).computer;
							(consumer->wishlist).computer=cmpptr2;
						}	
					}	
				}
				break;
			
				case 5:
				gamptr1=gamptr;
				printf("\nLIST OF GAMING\n");
				i=1;
				while(gamptr1!=NULL)
				{
					printf("%d. NAME - %s COST - %f \n",i,(gamptr1->product).name,(gamptr1->product).cost);
					i++;
					gamptr1=gamptr1->next;					
				}
				printf("\nENTER CHOICE\n");
				scanf("%d",&num3);
				//int wish;
				gamptr1=gamptr;
				i=1;
				while(i<num3 && gamptr1!=NULL)
				{
					i++;
					gamptr1=gamptr1->next;
				}
				if(gamptr1==NULL)
				{
					printf("\nINVALID ORDER\n");
				}
				else
				{
					if(consumer->fav_payment==0)
					{
						payment_mode(consumer);
						print_fav_mode(consumer,0,pay);
					}
					else
					{
						print_fav_mode(consumer,0,pay);
					}
					printf("\nORDER PLACED SUCCESSFULLY\n");
					int x=(gamptr1->product).quantity;
					printf("ENTER 0 TO ADD TO WISHLIST \nENTER 1 TO ORDER");
					scanf("%d",&wish);
					if(wish==1)
					{
						if(x==0)
						{
							printf("\nSORRY....ITEM OUT OF STOCK\n");
						}
						else
						{
							(gamptr1->product).quantity=x-1;
							(gamptr1->product).orders++;
							gamptr2=(consumer->history).gaming;
							int f=0;
							while(gamptr2!=NULL && f==0)
							{
								if(strcmp((gamptr2->product).name,(gamptr1->product).name)==0)
								{
									(gamptr2->product).orders =(gamptr2->product).orders + 1;
									f=1;
									/*
									op=malloc(sizeof(Orders));
									strcpy(op->pay_method,pay);
									op1=gamptr2->product.order_pay;
									op->next=op1;
									gamptr2->product.order_pay=op;
									*/
								}
								gamptr2=gamptr2->next;
							}
							if(f==0)
							{
								gamptr2=malloc(sizeof(Gaming));
								
								strcpy((gamptr2->product).name,(gamptr1->product).name); // CHANGE ARRAY ASSIGNMENT OVER HERE
								(gamptr2->product).cost=(gamptr1->product).cost;
								(gamptr2->product).orders=1;
								gamptr2->next=(consumer->history).gaming;
								(consumer->history).gaming=gamptr2;
								//strcpy(gamptr2->product.pay_method,pay);
								/*
								op=malloc(sizeof(Orders));
								strcpy(op->pay_method,pay);
								//op1=mobptr2->product.order_pay;
								op->next=op1;
								gamptr2->product.order_pay=op;
								*/
							}
						}
					}
					else if(wish==0)
					{
						gamptr2=(consumer->wishlist).gaming;
						int f=0;
						while(gamptr2!=NULL && f==0)
						{
							if(strcmp((gamptr2->product).name,(gamptr1->product).name)==0)
							{
								printf("\nITEM ALREADY IN WISHLIST\n");
								//(gamptr2->product).orders =(gamptr2->product).orders + 1;
								f=1;
							}
							gamptr2=gamptr2->next;
						}
						if(f==0)
						{
							printf("\nITEM ADDED TO WISHLIST\n");
							gamptr2=malloc(sizeof(Gaming));
							
							strcpy((gamptr2->product).name,(gamptr1->product).name); // CHANGE ARRAY ASSIGNMENT OVER HERE
							(gamptr2->product).cost=(gamptr1->product).cost;
							(gamptr2->product).orders=1;
							gamptr2->next=(consumer->wishlist).gaming;
							(consumer->wishlist).gaming=gamptr2;
						}	
					}	
				}
				break;
				
				case 6:
				appptr1=appptr;
				printf("\nLIST OF APPLIANCES\n");
				i=1;
				while(appptr1!=NULL)
				{
					printf("%d. NAME - %s COST - %f ",i,(appptr1->product).name,(appptr1->product).cost);
					i++;
					appptr1=appptr1->next;					
				}
				printf("\nENTER CHOICE\n");
				scanf("%d",&num3);
				//int wish;
				appptr1=appptr;
				i=1;
				while(i<num3 && appptr1!=NULL)
				{
					i++;
					appptr1=appptr1->next;
				}
				if(appptr1==NULL)
				{
					printf("\nINVALID ORDER\n");
				}
				else
				{
					int x=(appptr1->product).quantity;
					printf("ENTER 0 TO ADD TO WISHLIST \nENTER 1 TO ORDER");
					scanf("%d",&wish);
					if(wish==1)
					{
						if(x==0)
						{
							printf("\nSORRY....ITEM OUT OF STOCK\n");
						}
						else
						{
							if(consumer->fav_payment==0)
							{
								payment_mode(consumer);
								print_fav_mode(consumer,0,pay);
							}
							else
							{
								print_fav_mode(consumer,0,pay);
							}
							printf("\nORDER PLACED SUCCESSFULLY\n");
							(appptr1->product).quantity=x-1;
							(appptr1->product).orders++;
							appptr2=(consumer->history).appliances;
							int f=0;
							while(appptr2!=NULL && f==0)
							{
								if(strcmp((appptr2->product).name,(appptr1->product).name)==0)
								{
									(appptr2->product).orders =(appptr2->product).orders + 1;
									f=1;
									/*
									op=malloc(sizeof(Orders));
									strcpy(op->pay_method,pay);
									op1=appptr2->product.order_pay;
									op->next=op1;
									appptr2->product.order_pay=op;
									*/
								}
								appptr2=appptr2->next;
							}
							if(f==0)
							{
								appptr2=malloc(sizeof(Appliances));
								
								strcpy((appptr2->product).name,(appptr1->product).name); // CHANGE ARRAY ASSIGNMENT OVER HERE
								(appptr2->product).cost=(appptr1->product).cost;
								(appptr2->product).orders=1;
								appptr2->next=(consumer->history).appliances;
								(consumer->history).appliances=appptr2;
								/*
								op=malloc(sizeof(Orders));
								strcpy(op->pay_method,pay);
								//op1=mobptr2->product.order_pay;
								op->next=op1;
								appptr2->product.order_pay=op;
								*/
								//strcpy(appptr2->product.pay_method,pay);
							}
						}
					}
					else if(wish==0)
					{
						appptr2=(consumer->wishlist).appliances;
						int f=0;
						while(appptr2!=NULL && f==0)
						{
							if(strcmp((appptr2->product).name,(appptr1->product).name)==0)
							{
								printf("\nITEM ALREADY IN WISHLIST\n");
								//(appptr2->product).orders =(appptr2->product).orders + 1;
								f=1;
							}
							appptr2=appptr2->next;
						}
						if(f==0)
						{
							printf("\nITEM ADDED TO WISHLIST\n");
							appptr2=malloc(sizeof(Appliances));
							
							strcpy((appptr2->product).name,(appptr1->product).name); // CHANGE ARRAY ASSIGNMENT OVER HERE
							(appptr2->product).cost=(appptr1->product).cost;
							(appptr2->product).orders=1;
							appptr2->next=(consumer->wishlist).appliances;
							(consumer->wishlist).appliances=appptr2;
						}	
					}	
				}
				break;
				
				
			}//end switch
			break;
			
			case 5:
			printf("\n1.MOBILE PHONES\n2.MOBILE ACCESSORIES\n3.ELECTRONICS\n4.COMPUTER\n5.GAMING\n6.APPLIANCES\nENTER CHOICE\n");
			scanf("%d",&num2);
			switch(num2)
			{
				case 1:
				mobptr1=(consumer->history).phones;
				i=1;
				if(mobptr1==NULL)
				{
					printf("\nNO ORDERS\n");
				}
				else
				{
				printf("\nLIST OF PHONE ORDERS\n");
				while(mobptr1!=NULL)
				{	
					
						printf("%d. NAME - %s ORDER QUANTITY - %d  \n",i,(mobptr1->product).name,(mobptr1->product).orders);
						i++;
					mobptr1=mobptr1->next;
				}
				printf("\nENTER CHOICE\n");	
				scanf("%d",&num3);
				i=0;
				mobptr1=(consumer->history).phones;
				
					while(mobptr1!=NULL && i!=num3)
					{
							i++;
							
						
						if(i!=num3)
						{
							mobptr1=mobptr1->next;
						}
					}
				
				if(mobptr1==NULL)
				{
					printf("\nINVALID ORDER\n");
				}
				else
				{	
					printf("\nENTER BANK ACCOUNT NUMBER FOR REFUND\n");
					scanf("%s",return_account);
					consumer->refund=consumer->refund + (mobptr1->product).cost;
					printf("\nITEM RETURNED\n");
					printf("\nREFUND AMOUNT = %f\n",(mobptr1->product).cost);
					refund_function(return_account);
					(mobptr1->product).orders=(mobptr1->product).orders -1;
					
					if((mobptr1->product).orders == 0)
					{
						mobptr2=(consumer->history).phones;
						mobptr3=NULL;
						while(mobptr2!=NULL && mobptr2!=mobptr1)
						{
							mobptr3=mobptr2;
							mobptr2=mobptr2->next;
						}
						if(mobptr3 ==NULL)
						{
							(consumer->history).phones=mobptr2->next;
						}
						else
						{
							mobptr3->next=mobptr2->next;
						}
						free(mobptr1);
					}
				}
				}
				break;
				

				case 2:
				mobaccptr1=(consumer->history).accessories;
				i=1;
				if(mobaccptr1==NULL)
				{
					printf("\nNO ORDERS\n");
				}
				else
				{
				printf("\nLIST OF PHONE ACCESSORIES ORDERS\n");
				while(mobaccptr1!=NULL)
				{	
					
						printf("%d. NAME - %s ORDER QUANTITY - %d  \n",i,(mobaccptr1->product).name,(mobaccptr1->product).orders);
						i++;
						
					mobaccptr1=mobaccptr1->next;
				}
				printf("\nENTER CHOICE\n");	
				scanf("%d",&num3);
				i=0;
				mobaccptr1=(consumer->history).accessories;
				
					while(mobaccptr1!=NULL && i<num3)
					{
						
							i++;
							
						if(i!=num3)
						{
							mobaccptr1=mobaccptr1->next;
						}
					}
				
				if(mobaccptr1==NULL)
				{
					printf("\nINVALID ORDER\n");
				}
				else
				{	
					printf("\nENTER BANK ACCOUNT NUMBER FOR REFUND\n");
					scanf("%s",return_account);
					consumer->refund=consumer->refund + (mobaccptr1->product).cost;
					printf("\nITEM RETURNED\n");
					printf("\nREFUND AMOUNT = %f\n",(mobaccptr1->product).cost);
					refund_function(return_account);
					(mobaccptr1->product).orders=(mobaccptr1->product).orders -1;
					
					if((mobaccptr1->product).orders == 0)
					{
						mobaccptr2=(consumer->history).accessories;
						mobaccptr3=NULL;
						while(mobaccptr2!=NULL && mobaccptr2!=mobaccptr1)
						{
							mobaccptr3=mobaccptr2;
							mobaccptr2=mobaccptr2->next;
						}
						if(mobaccptr3 ==NULL)
						{
							(consumer->history).accessories=mobaccptr2->next;
						}
						else
						{
							mobaccptr3->next=mobaccptr2->next;
						}
						free(mobaccptr1);
					}
				}
				}
				break;
				
				case 3:
				elecptr1=(consumer->history).electronics;
				i=1;
				if(elecptr1==NULL)
				{
					printf("\nNO ORDERS\n");
				}
				else
				{
				printf("\nLIST OF ELWECTRONICS ORDERS\n");
				while(elecptr1!=NULL)
				{	
						printf("%d. NAME - %s ORDER QUANTITY - %d  \n",i,(elecptr1->product).name,(elecptr1->product).orders);
						i++;
						
					elecptr1=elecptr1->next;
				}
				printf("\nENTER CHOICE\n");	
				scanf("%d",&num3);
				i=0;
				elecptr1=(consumer->history).electronics;
				
					while(elecptr1!=NULL && i<num3)
					{
						
							i++;
							
						if(i!=num3)
						{
							elecptr1=elecptr1->next;
						}
					}
				
				if(elecptr1==NULL)
				{
					printf("\nINVALID ORDER\n");
				}
				else
				{	
					printf("\nENTER BANK ACCOUNT NUMBER FOR REFUND\n");
					scanf("%s",return_account);
					consumer->refund=consumer->refund + (elecptr1->product).cost;
					printf("\nITEM RETURNED\n");
					printf("\nREFUND AMOUNT = %f\n",(elecptr1->product).cost);
					refund_function(return_account);
					(elecptr1->product).orders=(elecptr1->product).orders -1;
					
					if((elecptr1->product).orders == 0)
					{
						elecptr2=(consumer->history).electronics;
						elecptr3=NULL;
						while(elecptr2!=NULL && elecptr2!=elecptr1)
						{
							elecptr3=elecptr2;
							elecptr2=elecptr2->next;
						}
						if(elecptr3 ==NULL)
						{
							(consumer->history).electronics=elecptr2->next;
						}
						else
						{
							elecptr3->next=elecptr2->next;
						}
						free(elecptr1);
					}
				}
				}
				break;
				
				case 4:
				cmpptr1=(consumer->history).computer;
				i=1;
				if(cmpptr1==NULL)
				{
					printf("\nNO ORDERS\n");
				}
				else
				{
				printf("\nLIST OF COMPUTER ORDERS\n");
				while(cmpptr1!=NULL)
				{	
					
						printf("%d. NAME - %s ORDER QUANTITY - %d  \n",i,(cmpptr1->product).name,(cmpptr1->product).orders);
						i++;
						
					cmpptr1=cmpptr1->next;
				}
				printf("\nENTER CHOICE\n");	
				scanf("%d",&num3);
				i=0;
				cmpptr1=(consumer->history).computer;
				
					while(cmpptr1!=NULL && i<num3)
					{
						
							i++;
						
						if(i!=num3)
						{
							cmpptr1=cmpptr1->next;
						}
					}
				
				if(cmpptr1==NULL)
				{
					printf("\nINVALID ORDER\n");
				}
				else
				{	
					printf("\nENTER BANK ACCOUNT NUMBER FOR REFUND\n");
					scanf("%s",return_account);
					consumer->refund=consumer->refund + (cmpptr1->product).cost;
					printf("\nITEM RETURNED\n");
					printf("\nREFUND AMOUNT = %f\n",(cmpptr1->product).cost);
					refund_function(return_account);
					(cmpptr1->product).orders=(cmpptr1->product).orders -1;
					
					if((cmpptr1->product).orders == 0)
					{
						cmpptr2=(consumer->history).computer;
						cmpptr3=NULL;
						while(cmpptr2!=NULL && cmpptr2!=cmpptr1)
						{
							cmpptr3=cmpptr2;
							cmpptr2=cmpptr2->next;
						}
						if(cmpptr3 ==NULL)
						{
							(consumer->history).computer=cmpptr2->next;
						}
						else
						{
							cmpptr3->next=cmpptr2->next;
						}
						free(cmpptr1);
					}
				}
				}
				break;
				
		
				case 5:
				gamptr1=(consumer->history).gaming;
				i=1;
				if(gamptr1==NULL)
				{
					printf("\nNO ORDERS\n");
				}
				else
				{
				printf("\nLIST OF GAMING ORDERS\n");
				while(gamptr1!=NULL)
				{	
					
						printf("%d. NAME - %s ORDER QUANTITY - %d  \n",i,(gamptr1->product).name,(gamptr1->product).orders);
						i++;
						
					gamptr1=gamptr1->next;
				}
				printf("\nENTER CHOICE\n");	
				scanf("%d",&num3);
				i=0;
				gamptr1=(consumer->history).gaming;
				
					while(gamptr1!=NULL && i<num3)
					{
						
							i++;
							
						if(i!=num3)
						{
							gamptr1=gamptr1->next;
						}
					}
				
				if(gamptr1==NULL)
				{
					printf("\nINVALID ORDER\n");
				}
				else
				{	
					printf("\nENTER BANK ACCOUNT NUMBER FOR REFUND\n");
					scanf("%s",return_account);
					consumer->refund=consumer->refund + (gamptr1->product).cost;
					printf("\nITEM RETURNED\n");
					printf("\nREFUND AMOUNT = %f\n",(gamptr1->product).cost);
					refund_function(return_account);
					(gamptr1->product).orders=(gamptr1->product).orders -1;
					
					if((gamptr1->product).orders == 0)
					{
						gamptr2=(consumer->history).gaming;
						gamptr3=NULL;
						while(gamptr2!=NULL && gamptr2!=gamptr1)
						{
							gamptr3=gamptr2;
							gamptr2=gamptr2->next;
						}
						if(gamptr3 ==NULL)
						{
							(consumer->history).gaming=gamptr2->next;
						}
						else
						{
							gamptr3->next=gamptr2->next;
						}
						free(gamptr1);
					}
				}
				}
				break;
				
				
				case 6:
				appptr1=(consumer->history).appliances;
				i=1;
				if(appptr1==NULL)
				{
					printf("\nNO ORDERS\n");
				}
				else
				{
				printf("\nLIST OF COMPUTER ORDERS\n");
				while(appptr1!=NULL)
				{	
					
						printf("%d. NAME - %s ORDER QUANTITY - %d  \n",i,(appptr1->product).name,(appptr1->product).orders);
						i++;
						
					appptr1=appptr1->next;
				}
				printf("\nENTER CHOICE\n");	
				scanf("%d",&num3);
				i=0;
				appptr1=(consumer->history).appliances;
				
					while(appptr1!=NULL && i<num3)
					{
						
							i++;
							
						if(i!=num3)
						{
							appptr1=appptr1->next;
						}
					}
				
				if(appptr1==NULL )
				{
					printf("\nINVALID ORDER\n");
				}
				else
				{	
					printf("\nENTER BANK ACCOUNT NUMBER FOR REFUND\n");
					scanf("%s",return_account);
					consumer->refund=consumer->refund + (appptr1->product).cost;
					printf("\nITEM RETURNED\n");
					printf("\nREFUND AMOUNT = %f\n",(appptr1->product).cost);
					refund_function(return_account);
					(appptr1->product).orders=(appptr1->product).orders -1;
					
					if((appptr1->product).orders == 0)
					{
						appptr2=(consumer->history).appliances;
						appptr3=NULL;
						while(appptr2!=NULL && appptr2!=appptr1)
						{
							appptr3=appptr2;
							appptr2=appptr2->next;
						}
						if(appptr3 ==NULL)
						{
							(consumer->history).appliances=appptr2->next;
						}
						else
						{
							appptr3->next=appptr2->next;
						}
						free(appptr1);
					}
				}
				}
				break;
				
				
			
			}//end inner switch
			break;
			
			case 6:
			frequent_purchase(consumer);
			break;
			case 7:
			max_purchaser(user);
			break;
			case 8:
			top_gadgets(&mobptr5,&mobaccptr5,&elecptr5,&cmpptr5,&gamptr5,&appptr5);
			break;
			
			case 9:
			flag=0;
			printf("\n\nEXITING YOUR SESSION!!\n");
		}//end outer switch(login,signup.....)
	}
}

void printcustomerinfo(Consumer *consumer)
{
	printf("\nCUSTOMER INFORMATION\n");
	printf("NAME %s \n",consumer->name);
	printf("EMAIL ID %s \n",consumer->email_id);
	printf("MOBILE %s \n",consumer->mobile_number);
	printf("ADDRESS %s \n",consumer->address);
	printf("ID %d \n",consumer->id);
}


void printwishlist(Consumer *consumer)
{
	printf("\nDISPLAYING WISHLIST\n");
	Consumer *user;
	user=consumer;
	
	Mobile_Phone *mp=(user->wishlist).phones;
	printf("\nMOBILE PHONES\n");
	while(mp!=NULL)
	{
		printf("%s %f \n",(mp->product).name,(mp->product).cost);
		mp=mp->next;
	}
	
	Mobile_Accessories *ma=(user->wishlist).accessories;
	printf("\nMOBILE ACCESSORIES\n");
	while(ma!=NULL)
	{
		printf("%s %f \n",(ma->product).name,(ma->product).cost);
		ma=ma->next;
	}	
	
	Computer *com=(user->wishlist).computer;
	printf("\nCOMPUTER\n");
	while(com!=NULL)
	{
		printf("%s %f \n",(com->product).name,(com->product).cost);
		com=com->next;
	}
	
	Electronics *elec=(user->wishlist).electronics;
	printf("\nELECTRONICS\n");
	while(elec!=NULL)
	{
		printf("%s %f \n",(elec->product).name,(elec->product).cost);
		elec=elec->next;
	}	
	
	Gaming *game=(user->wishlist).gaming;
	printf("\nGAMING\n");
	while(game!=NULL)
	{
		printf("%s %f \n",(game->product).name,(game->product).cost);
		game=game->next;
	}	
	
	Appliances *app=(user->wishlist).appliances;
	printf("\nAPPLIANCES\n");
	while(app!=NULL)
	{
		printf("%s %f \n",(app->product).name,(app->product).cost);
		app=app->next;
	}
	printf("\nEND OF LIST\n");	
	
}

void printhistory(Consumer *consumer)
{
	printf("\nDISPLAYING ORDER HISTORY\n");
	Consumer *user;
	user=consumer;
	Mobile_Phone *mp=(user->history).phones;
	printf("\nMOBILE PHONES\n");
	while(mp!=NULL)
	{
		printf("%s %f \n",(mp->product).name,(mp->product).cost);
		mp=mp->next;
	}
	
	Mobile_Accessories *ma=(user->history).accessories;
	printf("\nMOBILE ACCESSORIES\n");
	while(ma!=NULL)
	{
		printf("%s %f \n",(ma->product).name,(ma->product).cost);
		ma=ma->next;
	}	
	
	Computer *com=(user->history).computer;
	printf("\nCOMPUTER\n");
	while(com!=NULL)
	{
		printf("%s %f \n",(com->product).name,(com->product).cost);
		com=com->next;
	}
	
	Electronics *elec=(user->history).electronics;
	printf("\nELECTRONICS\n");
	while(elec!=NULL)
	{
		printf("%s %f \n",(elec->product).name,(elec->product).cost);
		elec=elec->next;
	}	
	
	Gaming *game=(user->history).gaming;
	printf("\nGAMING\n");
	while(game!=NULL)
	{
		printf("%s %f \n",(game->product).name,(game->product).cost);
		game=game->next;
	}	
	
	Appliances *app=(user->history).appliances;
	printf("\nAPPLIANCES\n");
	while(app!=NULL)
	{
		printf("%s %f \n",(app->product).name,(app->product).cost);
		app=app->next;
	}
	printf("\nEND OF LIST\n");	
	
}



Mobile_Phone*mobile(Mobile_Phone* lptr)
{
	Mobile_Phone* nptr;
	int flag,cost,quantity;
	char name[100];
	nptr=(Mobile_Phone*)malloc(sizeof(Mobile_Phone));
	printf("\nNAME OF MOBILE PHONE\n");
	scanf("%s",name);
	strcpy((nptr->product.name),name);
	printf("\nQUANTITY OF MOBILE PHONE\n");
	scanf("%d",&quantity);
	nptr->product.quantity=quantity;
	printf("\nCOST OF MOBILE PHONE\n");
	scanf("%d",&cost);
	nptr->product.cost=cost;
	nptr->product.orders=0;
	nptr->product.order_pay=NULL;
	nptr->next=lptr;
	lptr=nptr;

	return lptr;

}


Mobile_Accessories*mobileacc(Mobile_Accessories*lptr)
{
	Mobile_Accessories* nptr;
	int flag,cost,quantity;
	char name[100];
	nptr=(Mobile_Accessories*)malloc(sizeof(Mobile_Accessories));
	printf("\nNAME OF MOBILE ACCESSORY\n");
	scanf("%s",name);
	strcpy((nptr->product.name),name);
	printf("\nQUANTITY OF MOBILE ACCESSORY\n");
	scanf("%d",&quantity);
	nptr->product.quantity=quantity;
	printf("\nCOST OF MOBILE ACCESSORY\n");
	scanf("%d",&cost);
	nptr->product.cost=cost;
	nptr->product.orders=0;
	nptr->product.order_pay=NULL;
	nptr->next=lptr;
	lptr=nptr;

	return lptr;

}
Electronics*electronics(Electronics*lptr)
{
	Electronics* nptr;
	int flag,cost,quantity;
	char name[100];
	nptr=(Electronics*)malloc(sizeof(Electronics));
	printf("\nNAME OF ELECTRONICS\n");
	scanf("%s",name);
	strcpy((nptr->product.name),name);
	printf("\nQUANTITY OF ELECTRONICS\n");
	scanf("%d",&quantity);
	nptr->product.quantity=quantity;
	printf("\nCOST OF ELECTRONICS\n");
	scanf("%d",&cost);
	nptr->product.cost=cost;
	nptr->product.orders=0;
	nptr->product.order_pay=NULL;
	nptr->next=lptr;
	lptr=nptr;
	return lptr;
}
Computer*computer(Computer*lptr)
{
	Computer* nptr;
	int flag,cost,quantity;
	char name[100];
	nptr=(Computer*)malloc(sizeof(Computer));
	printf("\nNAME OF COMPUTER\n");
	scanf("%s",name);
	strcpy((nptr->product.name),name);
	printf("\nQUANTITY OF COMPUTER\n");
	scanf("%d",&quantity);
	nptr->product.quantity=quantity;
	printf("\nCOST OF COMPUTER\n");
	scanf("%d",&cost);
	nptr->product.cost=cost;
	nptr->product.orders=0;
	nptr->product.order_pay=NULL;
	nptr->next=lptr;
	lptr=nptr;

	return lptr;
}

Gaming*game(Gaming*lptr)
{
	Gaming* nptr;
	int flag,cost,quantity;
	char name[100];
	nptr=(Gaming*)malloc(sizeof(Gaming));
	printf("\nNAME OF GAMING\n");
	scanf("%s",name);
	strcpy((nptr->product.name),name);
	printf("\nQUANTITY OF GAMING\n");
	scanf("%d",&quantity);
	nptr->product.quantity=quantity;
	printf("\nCOST OF GAMING\n");
	scanf("%d",&cost);
	nptr->product.cost=cost;
	nptr->product.orders=0;
	nptr->product.order_pay=NULL;
	nptr->next=lptr;
	lptr=nptr;

	return lptr;
}

Appliances*appliances(Appliances*lptr)
{
	Appliances* nptr;
	int flag,cost,quantity;
	char name[100];
	nptr=(Appliances*)malloc(sizeof(Appliances));
	printf("\nNAME OF APPLIANCE\n");
	scanf("%s",name);
	strcpy((nptr->product.name),name);
	printf("\nQUANTITY OF APPLIANCE\n");
	scanf("%d",&quantity);
	nptr->product.quantity=quantity;
	printf("\nCOST OF APPLIANCE\n");
	scanf("%d",&cost);
	nptr->product.cost=cost;
	nptr->product.orders=0;
	nptr->product.order_pay=NULL;
	nptr->next=lptr;
	lptr=nptr;
	return lptr;
}
void payment_mode(Consumer*consumer)
{
	int fav_p;
	char card[17],id[50];
	char date[10];
	int cmp1;
	printf("\n1.BUY NOW PAY LATER\n2.CASH ON DELIVERY\n3.DEBIT CARD\n4.CREDIT CARD\n5.NET BANKING\n6.UPI\n7.PhonePe\n");
	printf("ENTER YOUR FAVOURITE PAYMENT METHOD\n");
	scanf("%d",&fav_p);
	switch(fav_p)
	{
		case 1:
		consumer->fav_payment=1;
		strcpy((consumer->fav_payment_mode),"bnpl");
		break;
		case 2:
		consumer->fav_payment=1;
		strcpy((consumer->fav_payment_mode),"cod");
		break;
		case 3:		
		consumer->fav_payment=1;
		strcpy((consumer->fav_payment_mode),"debit");
		if((consumer->payment.debit.number)<1)
		{
			printf("\nENTER DEBIT CARD NUMBER\n");
			scanf("%s",card);
			printf("\nENTER EXPIRY DATE(mm/yy)\n");
			scanf("%s",date);
			strcpy((consumer->payment.debit.card),card);
			strcpy((consumer->payment.debit.date),date);
		}
		break;
		case 4:		
		consumer->fav_payment=1;
		strcpy((consumer->fav_payment_mode),"credit");
		if((consumer->payment.credit.number)<1)
		{
			printf("\nENTER CREDIT CARD NUMBER\n");
			scanf("%s",card);
			printf("\nENTER EXPIRY DATE(mm/yy)\n");
			scanf("%s",date);
			strcpy((consumer->payment.credit.card),card);
			strcpy((consumer->payment.credit.date),date);
		}
		break;
		case 5:		
		consumer->fav_payment=1;
		strcpy((consumer->fav_payment_mode),"netbanking");
		if((consumer->payment.netbanking.number)<1)
		{
			printf("Enter your netbanking id");
			scanf("%s",id);
			strcpy((consumer->payment.netbanking.id),id);
		}
		break;
		case 6:		
		consumer->fav_payment=1;
		strcpy((consumer->fav_payment_mode),"upi");
		if((consumer->payment.upi.number)<1)
		{
			printf("\nENTER UPI ID\n");
			scanf("%s",id);
			strcpy((consumer->payment.upi.id),id);
		}
		break;
		case 7:		
		consumer->fav_payment=1;
		strcpy((consumer->fav_payment_mode),"phonepe");
		if((consumer->payment.phonepe.number)<1)
		{
			printf("\nENTER PhonePe ID\n");
			scanf("%s",id);
			strcpy((consumer->payment.phonepe.id),id);
		}
		break;
	}
	
}


void print_fav_mode(Consumer*consumer,int come,char pay[])
{
	char fav_payment[15],cvv[4],otp[5],passwd[15],ss[100];
	int flag,flag1,flag2,flag3,flag4,flag5,flag6,flag7;
	int choice,fav=0;
	if(come==0)
	{
		if((consumer->payment.BNPL_number)>fav)
		{
			strcpy((consumer->fav_payment_mode),"bnpl");
			fav=(consumer->payment.BNPL_number);
		}
		if((consumer->payment.COD_number)>fav)
		{
			strcpy((consumer->fav_payment_mode),"cod");
			fav=(consumer->payment.COD_number);
		}
		if(((consumer->payment.debit.number))>fav)
		{
			strcpy((consumer->fav_payment_mode),"debit");
			fav=(consumer->payment.debit.number);
		}
		if(((consumer->payment.credit.number))>fav)
		{
			strcpy((consumer->fav_payment_mode),"credit");
			fav=(consumer->payment.credit.number);
		}
		if(((consumer->payment.netbanking.number))>fav)
		{
			strcpy((consumer->fav_payment_mode),"netbanking");
			fav=(consumer->payment.netbanking.number);
		}
		if(((consumer->payment.upi.number))>fav)
		{
			strcpy((consumer->fav_payment_mode),"upi");
			fav=(consumer->payment.upi.number);
		}
		if(((consumer->payment.phonepe.number))>fav)
		{
			strcpy((consumer->fav_payment_mode),"phonepe");
			fav=(consumer->payment.phonepe.number);
		}

	}
	flag1=strcmp((consumer->fav_payment_mode),"bnpl");
	flag2=strcmp((consumer->fav_payment_mode),"cod");
	flag3=strcmp((consumer->fav_payment_mode),"debit");
	flag4=strcmp((consumer->fav_payment_mode),"credit");
	flag5=strcmp((consumer->fav_payment_mode),"netbanking");
	flag6=strcmp((consumer->fav_payment_mode),"upi");
	flag7=strcmp((consumer->fav_payment_mode),"phonepe");
	if(flag1==0)
	{
		printf("\nYOUR FAVOURITE PAYMENT METHOD IS \" BUY NOW PAY LATER \"\n");
		printf("\nPRESS1 TO USE THIS METHOD\nOTHERWISE PRESS 0\n");
		scanf("%d",&choice);
		if(choice==0)
		{
			payment_mode(consumer);
			print_fav_mode(consumer,1,ss);
			strcpy(pay,ss);
		}
		else
		{
			strcpy(pay,"BUY NOW PAY LATER");
			(consumer->payment.BNPL_number)++;
		}
	}
	else if(flag2==0)
	{
		printf("\nYOUR FAVOURITE PAYMENT METHOD IS \" CASH ON DELIVERY\"\n");
		printf("\nPRESS1 TO USE THIS METHOD\nOTHERWISE PRESS 0\n");
		scanf("%d",&choice);
		if(choice==0)
		{
			payment_mode(consumer);
			print_fav_mode(consumer,1,ss);
			strcpy(pay,ss);
		}
		else
		{
			strcpy(pay,"CASH ON DELIVERY");
			(consumer->payment.COD_number)++;
		}
	}
	else if(flag3==0)
	{
		printf("\nYOUR FAVOURITE PAYMENT METHOD IS \" DEBIT CARD \"\n");
		printf("Your card number is %s and Expiry date is %s\n",consumer->payment.debit.card,consumer->payment.debit.date);
		printf("\nPRESS1 TO USE THIS METHOD\nOTHERWISE PRESS 0\n");
		scanf("%d",&choice);
		if(choice==0)
		{
			payment_mode(consumer);
			print_fav_mode(consumer,1,ss);
			strcpy(pay,ss);
		}
		else
		{
			strcpy(pay,"DEBIT CARD");
			printf("Enter your cvv");
			scanf("%s",cvv);
			printf("Enter your otp sent to your mobile number");
			scanf("%s",otp);
			(consumer->payment.debit.number)++;
			flag=1;
			
		}
	}
	else if(flag4==0)
	{
		printf("\nYOUR FAVOURITE PAYMENT METHOD IS \" CREDIT CARD \"\n");
		printf("Your card number is %s and Expiry date is %s\n",consumer->payment.credit.card,consumer->payment.credit.date);
		printf("\nPRESS1 TO USE THIS METHOD\nOTHERWISE PRESS 0\n");
		scanf("%d",&choice);
		if(choice==0)
		{
			payment_mode(consumer);
			print_fav_mode(consumer,1,ss);
			strcpy(pay,ss);
		}
		else
		{
			strcpy(pay,"CREDIT CARD");
			printf("Enter your cvv");
			scanf("%s",cvv);
			printf("Enter your otp sent to your mobile number");
			scanf("%s",otp);
			(consumer->payment.credit.number)++;
		}
	}
	else if(flag5==0)
	{
		printf("\nYOUR FAVOURITE PAYMENT METHOD IS \" NET BANKING \"\n");
		printf("Your Net Banking id is %s \n",consumer->payment.netbanking.id);
		printf("\nPRESS1 TO USE THIS METHOD\nOTHERWISE PRESS 0\n");
		scanf("%d",&choice);
		if(choice==0)
		{
			payment_mode(consumer);
			print_fav_mode(consumer,1,ss);
			strcpy(pay,ss);
		}
		else
		{
			strcpy(pay,"NET BANKING");
			printf("Enter your password");
			scanf("%s",passwd);
			printf("Enter your otp sent to your mobile number");
			scanf("%s",otp);
			(consumer->payment.netbanking.number)++;
		}
	}
	else if(flag6==0)
	{
		printf("\nYOUR FAVOURITE PAYMENT METHOD IS \" UPI \"\n");
		printf("\nUPI ID%s \n",consumer->payment.upi.id);
		printf("\nPRESS1 TO USE THIS METHOD\nOTHERWISE PRESS 0\n");
		scanf("%d",&choice);
		if(choice==0)
		{
			payment_mode(consumer);
			print_fav_mode(consumer,1,ss);
			strcpy(pay,ss);
		}
		else
		{
			strcpy(pay,"UPI");
			printf("Enter your password");
			scanf("%s",passwd);
			printf("Enter your otp sent to your mobile number");
			scanf("%s",otp);
			(consumer->payment.upi.number)++;
		}
	}
	else if(flag7==0)
	{
		printf("\nYOUR FAVOURITE PAYMENT METHOD IS \" PhonePe \"\n");
		printf("\nPhonePe ID %s \n",consumer->payment.phonepe.id);
		printf("\nPRESS1 TO USE THIS METHOD\nOTHERWISE PRESS 0\n");
		scanf("%d",&choice);
		if(choice==0)
		{
			payment_mode(consumer);
			print_fav_mode(consumer,1,ss);
			strcpy(pay,ss);
		}
		else
		{
			strcpy(pay,"PhonePe");
			printf("Enter your password");
			scanf("%s",passwd);
			printf("Enter your otp sent to your mobile number");
			scanf("%s",otp);
			(consumer->payment.phonepe.number)++;
		}
	}
}



void frequent_purchase(Consumer *consumer)
{
	int flag=1;
	Mobile_Phone *mp1, *mp,*mp2,*mp3,*tmp;
	mp=(consumer->history).phones;
	mp1=NULL;
	Mobile_Accessories *ma1, *ma,*ma2,*ma3,*tmp1;
	ma=(consumer->history).accessories;
	ma1=NULL;
	Computer *com1, *com,*com2,*com3,*tmp2;
	com=(consumer->history).computer;
	com1=NULL;
	Electronics *elec1, *elec,*elec2,*elec3,*tmp3;
	elec=(consumer->history).electronics;
	elec1=NULL;
	Gaming *game1, *game,*game2,*game3,*tmp4;
	game=(consumer->history).gaming;
	game1=NULL;
	Appliances *app1, *app,*app2,*app3,*tmp5;
	app=(consumer->history).appliances;
	app1=NULL;
	while(mp!=NULL)
	{
		tmp=mp->next;
		if(mp1==NULL || ((mp1->product).orders < (mp->product).orders) )
		{
			
			mp->next=mp1;
			mp1=mp;
		}
		else
		{
			mp2=mp1->next;
			mp3=mp1;
			while(mp2!=NULL && ((mp2->product).orders > (mp->product).orders))
			{
				mp3=mp2;
				mp2=mp2->next;
			}
			mp3->next=mp;
			//tmp=mp;
			mp->next=mp2;
			//mp=tmp;
			
		}
		mp=tmp;
	}
	if(mp1!=NULL)
	{
		(consumer->history).phones=mp1;
		printf("\nMOST BOUGTH MOBILE PHONE\n");
		printf("NAME - %s \nORDERS - %d \n",((consumer->history).phones->product).name,((consumer->history).phones->product).orders);
	}
	
	
	while(ma!=NULL)
	{
		tmp1=ma->next;
		if(ma1==NULL || ((ma1->product).orders < (ma->product).orders) )
		{
			
			ma->next=ma1;
			ma1=ma;
			
		}
		else
		{
			ma2=ma1;
			ma3=NULL;
			while(ma2!=NULL && ((ma2->product).orders > (ma->product).orders))
			{
				ma3=ma2;
				ma2=ma2->next;
			}
			
			ma3->next=ma;
			//tmp1=ma;
			ma->next=ma2;
			//ma=tmp1;
			
		}
		ma=tmp1;
	}
	if(ma1!=NULL)
	{
		(consumer->history).accessories=ma1;
		printf("\nMOST BOUGTH MOBILE ACCESSORIES\n");
		printf("NAME - %s \nORDERS - %d \n",((consumer->history).accessories->product).name,((consumer->history).accessories->product).orders);
	}
	
	
	
	while(com!=NULL)
	{
		tmp2=com->next;
		if(com1==NULL || ((com1->product).orders < (com->product).orders) )
		{
			
			com->next=com1;
			com1=com;
		}
		else
		{
			com2=com1;
			com3=NULL;
			while(com2!=NULL && ((com2->product).orders > (com->product).orders))
			{
				com3=com2;
				com2=com2->next;
			}
			
			com3->next=com;
			//tmp2=com;
			com->next=com2;
		}
		com=tmp2;
	}
	if(com!=NULL)
	{
		(consumer->history).computer=com1;
		printf("\nMOST BOUGTH COMPUTER\n");
		printf("NAME - %s \nORDERS - %d \n",((consumer->history).computer->product).name,((consumer->history).computer->product).orders);
	}
	
	while(elec!=NULL)
	{
		tmp3=elec->next;
		if(elec1==NULL || ((elec1->product).orders < (elec->product).orders) )
		{
			
			elec->next=elec1;
			elec1=elec;
			
		}
		else
		{
			elec2=elec1;
			elec3=NULL;
			while(elec2!=NULL && ((elec2->product).orders > (elec->product).orders))
			{
				elec3=elec2;
				elec2=elec2->next;
			}
			elec3->next=elec;
			//tmp3=elec;
			elec->next=elec2;
			//elec=tmp3;
			
		}
		elec=tmp3;
	}
	if(elec1!=NULL)
	{
		(consumer->history).electronics=elec1;
		printf("\nMOST BOUGTH ELECRONICS\n");
		printf("NAME - %s \nORDERS - %d \n",((consumer->history).electronics->product).name,((consumer->history).electronics->product).orders);
	}
	
	
	while(game!=NULL)
	{
		tmp4=game->next;
		if(game1==NULL || ((game1->product).orders < (game->product).orders) )
		{
			
			game->next=game1;
			game1=game;
			
		}
		else
		{
			game2=game1;
			game3=NULL;
			while(game2!=NULL && ((game2->product).orders > (game->product).orders))
			{
				game3=game2;
				game2=game2->next;
			}
			
			game3->next=game;
			//tmp4=game;
			game->next=game2;
			//game=tmp4;
			
		}
		game=tmp4;
	}
	if(game1!=NULL)
	{
		(consumer->history).gaming=game1;
		printf("\nMOST BOUGTH GAMING\n");
		printf("NAME - %s \nORDERS - %d \n",((consumer->history).gaming->product).name,((consumer->history).gaming->product).orders);
	}
	
	
	
	while(app!=NULL)
	{
		tmp5=app->next;
		if(app1==NULL || ((app1->product).orders < (app->product).orders) )
		{
			
			app->next=app1;
			app1=app;
			
		}
		else
		{
			app2=app1;
			app3=NULL;
			while(app2!=NULL && ((app2->product).orders > (app->product).orders))
			{
				app3=app2;
				app2=app2->next;
			}

			app3->next=app;
			//tmp5=app;
			app->next=app2;
			//app=tmp5;
			
		}
		app=tmp5;
	}
	if(app1!=NULL)
	{
		(consumer->history).appliances=app1;
		printf("\nMOST BOUGTH APPLIANCES\n");
		printf("NAME - %s \nORDERS - %d \n",((consumer->history).appliances->product).name,((consumer->history).appliances->product).orders);
	}
	
	
}

void max_purchaser(Consumer *consumer)
{
	Consumer *consumer1;
	consumer1=consumer;
	/*while(consumer1!=NULL)
	{
		frequent_purchase(consumer1,0);
		consumer1=consumer1->next;
	}*/
	
	Mobile_Phone *mp;
	Mobile_Accessories *ma;
	
	Computer *com;
	
	Electronics *elec;
	
	Gaming *game;
	
	Appliances *app;
	
	
	
	
	
	max_purchase *purchase,*purchase1,*purchase2,*purchase3;;
	purchase=NULL;
	while(consumer1!=NULL)
	{
		mp=(consumer1->history).phones;
		while(mp!=NULL)
		{
			purchase1=malloc(sizeof(max_purchase));
			strcpy(purchase1->cname,consumer->name);
			strcpy(purchase1->pname,(mp->product).name);
			purchase1->orders=(mp->product).orders;
			purchase1->next=NULL;
			if(purchase==NULL || (purchase1->orders > purchase->orders))
			{
				purchase1->next=purchase;
				purchase=purchase1;
			}
			else
			{
				purchase2=purchase;
				purchase3=purchase->next;
				while(purchase3!=NULL && (purchase1->orders < purchase3->orders))
				{
					purchase2=purchase3;
					purchase3=purchase3->next;
				}
				purchase2->next=purchase1;
				purchase1->next=purchase3;
			}
			mp=mp->next;
		}
		
		
		ma=(consumer->history).accessories;
		while(ma!=NULL)
		{
			purchase1=malloc(sizeof(max_purchase));
			strcpy(purchase1->cname,consumer->name);
			strcpy(purchase1->pname,(ma->product).name);
			purchase1->orders=(ma->product).orders;
			if(purchase==NULL || (purchase1->orders > purchase->orders))
			{
				purchase1->next=purchase;
				purchase=purchase1->next;
			}
			else
			{
				purchase2=purchase;
				purchase3=purchase->next;
				while(purchase3!=NULL && (purchase1->orders < purchase3->orders))
				{
					purchase2=purchase3;
					purchase3=purchase3->next;
				}
				purchase2->next=purchase1;
				purchase1->next=purchase3;
			}
			ma=ma->next;
		}
		
		
		com=(consumer->history).computer;
		while(com!=NULL)
		{
			purchase1=malloc(sizeof(max_purchase));
			strcpy(purchase1->cname,consumer->name);
			strcpy(purchase1->pname,(com->product).name);
			purchase1->orders=(com->product).orders;
			if(purchase==NULL || (purchase1->orders > purchase->orders))
			{
				purchase1->next=purchase;
				purchase=purchase1;
			}
			else
			{
				purchase2=purchase;
				purchase3=purchase->next;
				while(purchase3!=NULL && (purchase1->orders < purchase3->orders))
				{
					purchase2=purchase3;
					purchase3=purchase3->next;
				}
				purchase2->next=purchase1;
				purchase1->next=purchase3;
			}
			com=com->next;
		}
		
		
		elec=(consumer->history).electronics;
		while(elec!=NULL)
		{
			purchase1=malloc(sizeof(max_purchase));
			strcpy(purchase1->cname,consumer->name);
			strcpy(purchase1->pname,(elec->product).name);
			purchase1->orders=(elec->product).orders;
			if(purchase==NULL || (purchase1->orders > purchase->orders))
			{
				purchase1->next=purchase;
				purchase=purchase1;
			}
			else
			{
				purchase2=purchase;
				purchase3=purchase->next;
				while(purchase3!=NULL && (purchase1->orders < purchase3->orders))
				{
					purchase2=purchase3;
					purchase3=purchase3->next;
				}
				purchase2->next=purchase1;
				purchase1->next=purchase3;
			}
			elec=elec->next;
		}
		
		
		game=(consumer->history).gaming;
		while(game!=NULL)
		{
			purchase1=malloc(sizeof(max_purchase));
			strcpy(purchase1->cname,consumer->name);
			strcpy(purchase1->pname,(game->product).name);
			purchase1->orders=(game->product).orders;
			if(purchase==NULL || (purchase1->orders > purchase->orders))
			{
				purchase1->next=purchase;
				purchase=purchase1;
			}
			else
			{
				purchase2=purchase;
				purchase3=purchase->next;
				while(purchase3!=NULL && (purchase1->orders < purchase3->orders))
				{
					purchase2=purchase3;
					purchase3=purchase3->next;
				}
				purchase2->next=purchase1;
				purchase1->next=purchase3;
			}
			game=game->next;
		}
		
		
		app=(consumer->history).appliances;
		while(app!=NULL)
		{
			purchase1=malloc(sizeof(max_purchase));
			strcpy(purchase1->cname,consumer->name);
			strcpy(purchase1->pname,(app->product).name);
			purchase1->orders=(app->product).orders;
			if(purchase==NULL || (purchase1->orders > purchase->orders))
			{
				purchase1->next=purchase;
				purchase=purchase1;
			}
			else
			{
				purchase2=purchase;
				purchase3=purchase->next;
				while(purchase3!=NULL && (purchase1->orders < purchase3->orders))
				{
					purchase2=purchase3;
					purchase3=purchase3->next;
				}
				purchase2->next=purchase1;
				purchase1->next=purchase3;
			}
			app=app->next;
		}
		consumer1=consumer1->next;
	}
	purchase1=purchase;
	printf("\nMOST FREQUENT CUSTOMERS\n");
	int i=1;
	while(purchase1!=NULL)
	{
		printf("%d. CUSTOMER- %s   PRODUCT- %s   ORDERS- %d \n",i,purchase1->cname,purchase1->pname,purchase1->orders);
		purchase1=purchase1->next;
		i++;
	}
	
}

void top_gadgets(Mobile_Phone **mobpptr,Mobile_Accessories **mobaccpptr,Electronics **elecpptr,Computer **cmppptr,Gaming **gampptr,Appliances **apppptr)
{
	Mobile_Phone *mobptr,*mop=NULL;
	mobptr=*mobpptr;

	if(mobptr!=NULL)
	{
		mop=malloc(sizeof(Mobile_Phone));
		strcpy(mop->product.name,mobptr->product.name);
		mop->product.quantity=mobptr->product.quantity;
		mop->product.cost=mobptr->product.cost;
		mop->product.orders=mobptr->product.orders;
		mop->next=mobptr->next;
		mobptr=mop;
	}
	Mobile_Phone *mobptr1,*mobptr2,*mobptr3=NULL;



	Mobile_Accessories *mobaccptr,*moap=NULL;
	mobaccptr=*mobaccpptr;

	if(mobaccptr!=NULL)
	{
		moap=malloc(sizeof(Mobile_Accessories));
		strcpy(moap->product.name,mobaccptr->product.name);
		moap->product.quantity=mobaccptr->product.quantity;
		moap->product.cost=mobaccptr->product.cost;
		moap->product.orders=mobaccptr->product.orders;
		moap->next=mobaccptr->next;
		mobaccptr=moap;
	}
	Mobile_Accessories *mobaccptr1,*mobaccptr2,*mobaccptr3=NULL;


	Electronics *elecptr,*elp=NULL;
	elecptr=*elecpptr;

	if(elecptr!=NULL)
	{
		elp=malloc(sizeof(Electronics));
		strcpy(elp->product.name,elecptr->product.name);
		elp->product.quantity=elecptr->product.quantity;
		elp->product.cost=elecptr->product.cost;
		elp->product.orders=elecptr->product.orders;
		elp->next=elecptr->next;
		elecptr=elp;
	}
	Electronics *elecptr1,*elecptr2,*elecptr3=NULL;


	Computer *cmpptr,*cmlp=NULL;
	cmpptr=*cmppptr;

	if(cmpptr!=NULL)
	{
		cmlp=malloc(sizeof(Computer));
		strcpy(cmlp->product.name,cmpptr->product.name);
		cmlp->product.quantity=cmpptr->product.quantity;
		cmlp->product.cost=cmpptr->product.cost;
		cmlp->product.orders=cmpptr->product.orders;
		cmlp->next=cmpptr->next;
		cmpptr=cmlp;
	}
	Computer *cmpptr1,*cmpptr2,*cmpptr3=NULL;

	Gaming *gamptr,*gp=NULL;
	gamptr=*gampptr;

	if(gamptr!=NULL)
	{
		gp=malloc(sizeof(Gaming));
		strcpy(gp->product.name,gamptr->product.name);
		gp->product.quantity=gamptr->product.quantity;
		gp->product.cost=gamptr->product.cost;
		gp->product.orders=gamptr->product.orders;
		gp->next=gamptr->next;
		gamptr=gp;
	}
	Gaming *gamptr1,*gamptr2,*gamptr3=NULL;
	


	Appliances *appptr,*alp=NULL;
	appptr=*apppptr;

	if(appptr!=NULL)
	{
		alp=malloc(sizeof(Appliances));
		strcpy(alp->product.name,appptr->product.name);
		alp->product.quantity=appptr->product.quantity;
		alp->product.cost=appptr->product.cost;
		alp->product.orders=appptr->product.orders;
		alp->next=appptr->next;
		appptr=alp;
	}
	Appliances *appptr1,*appptr2,*appptr3=NULL;


	


	int flag=1;
	int flag1=0;
	int count=0;
	if(mobptr!=NULL)
	{
		mobptr=mop;
		mobptr1=mop;
		flag1=0;
		count=0;
		while(mobptr1!=NULL)
		{
			count++;
			mobptr1=mobptr1->next;
		}
		while(flag1<(count-1))
		{
			mobptr1=mobptr;
			while(mobptr1->next!=NULL)
			{
				if(mobptr1->next->next!=NULL)
				{
					if(mobptr1->next->product.orders<mobptr1->next->next->product.orders)
					{
						mobptr2=mobptr1->next;
						mobptr1->next=mobptr2->next;
						mobptr2->next=mobptr1->next->next;
						mobptr1->next->next=mobptr2;
					}
				}
				mobptr1=mobptr1->next;
			}
			flag1++;
		}
	
		if(mobptr!=NULL)
		{
			if(mobptr->next!=NULL)
			{
				(*mobpptr)->next=mop->next;
				mobptr=mop;
				mobptr1=mobptr;
				if(mobptr1->product.orders<mobptr1->next->product.orders)
				{
					mobptr2=mobptr1;
					mobptr1=mobptr1->next;
					while((mobptr1!=NULL)&&(flag==1))
					{
						flag=0;
						if(mobptr1->product.orders>=mobptr2->product.orders)
						{
							mobptr3=mobptr1;
							mobptr1=mobptr1->next;
							flag=1;
						}
					}
				}	
				if(mobptr3!=NULL)
				{
					mobptr1=mobptr3;
					mobptr2->next=mobptr1->next;
					mobptr1->next=mobptr2;
				}
				if(mobptr3!=NULL)
				{
					mobptr=mobptr->next;
				}
				if(mobptr3!=NULL)
				{
				(**mobpptr)=*((*mobpptr)->next);
				}	
			}
		}
		printf("\nMOBILES ARE\n");
		mobptr=*mobpptr;	
		while(mobptr!=NULL)
		{
			printf("Name is %s and quantity is %d\n",mobptr->product.name,mobptr->product.orders);
			mobptr=mobptr->next;
		}
	}	
			
		
		

	

	//int flag=1;
	//int flag1=0;
	//int count=0;
	mobaccptr=moap;
	mobaccptr1=moap;
	if(mobaccptr!=NULL)
	{
		mobaccptr=moap;
		mobaccptr1=moap;
		flag1=0;
		count=0;
		while(mobaccptr1!=NULL)
		{
			count++;
			mobaccptr1=mobaccptr1->next;
		}
		while(flag1<(count-1))
		{
			mobaccptr1=mobaccptr;
			while(mobaccptr1->next!=NULL)
			{
				if(mobaccptr1->next->next!=NULL)
				{
					if(mobaccptr1->next->product.orders<mobaccptr1->next->next->product.orders)
					{
						mobaccptr2=mobaccptr1->next;
						mobaccptr1->next=mobaccptr2->next;
						mobaccptr2->next=mobaccptr1->next->next;
						mobaccptr1->next->next=mobaccptr2;
					}
				}
				mobaccptr1=mobaccptr1->next;
			}
			flag1++;
		}
	
		
		if(mobaccptr!=NULL)
		{
			if(mobaccptr->next!=NULL)
			{
				(*mobaccpptr)->next=moap->next;
				mobaccptr=moap;
				mobaccptr1=mobaccptr;
				if(mobaccptr1->product.orders<mobaccptr1->next->product.orders)
				{
					mobaccptr2=mobaccptr1;
					mobaccptr1=mobaccptr1->next;
					while((mobaccptr1!=NULL)&&(flag==1))
					{
						flag=0;
						if(mobaccptr1->product.orders>=mobaccptr2->product.orders)
						{
							mobaccptr3=mobaccptr1;
							mobaccptr1=mobaccptr1->next;
							flag=1;
						}
					}
				}
				if(mobaccptr3!=NULL)
				{
					mobaccptr1=mobaccptr3;
					mobaccptr2->next=mobaccptr1->next;
					mobaccptr1->next=mobaccptr2;
				}
				if(mobaccptr3!=NULL)
				{
					mobaccptr=mobaccptr->next;
				}
				if(mobaccptr3!=NULL)
				{
				(**mobaccpptr)=*((*mobaccpptr)->next);
				}	
			}
		}
		printf("\nMOBILE ACCESSORIES ARE\n");
		mobaccptr=*mobaccpptr;	
		while(mobaccptr!=NULL)
		{
			printf("Name is %s and quantity is %d\n",mobaccptr->product.name,mobaccptr->product.orders);
			mobaccptr=mobaccptr->next;
		}
	}	
	
	//int flag=1;
	//int flag1=0;
	//int count=0;
	elecptr=elp;
	elecptr1=elp;
	if(elecptr!=NULL)
	{
		elecptr=elp;
		elecptr1=elp;
		flag1=0;
		count=0;
		while(elecptr1!=NULL)
		{
			count++;
			elecptr1=elecptr1->next;
		}
		while(flag1<(count-1))
		{
			elecptr1=elecptr;
			while(elecptr1->next!=NULL)
			{
				if(elecptr1->next->next!=NULL)
				{
					if(elecptr1->next->product.orders<elecptr1->next->next->product.orders)
					{
						elecptr2=elecptr1->next;
						elecptr1->next=elecptr2->next;
						elecptr2->next=elecptr1->next->next;
						elecptr1->next->next=elecptr2;
					}
				}
				elecptr1=elecptr1->next;
			}
			flag1++;
		}
	
		if(elecptr!=NULL)
		{
			if(elecptr->next!=NULL)
			{
				(*elecpptr)->next=elp->next;
				elecptr=elp;
				elecptr1=elecptr;
				if(elecptr1->product.orders<elecptr1->next->product.orders)
				{
					elecptr2=elecptr1;
					elecptr1=elecptr1->next;
					while((elecptr1!=NULL)&&(flag==1))
					{
						flag=0;
						if(elecptr1->product.orders>=elecptr2->product.orders)
						{
							elecptr3=elecptr1;
							elecptr1=elecptr1->next;
							flag=1;
						}
					}
				}
				if(elecptr3!=NULL)
				{
					elecptr1=elecptr3;
					elecptr2->next=elecptr1->next;
					elecptr1->next=elecptr2;
				}
				if(elecptr3!=NULL)
				{
					elecptr=elecptr->next;
				}
				if(elecptr3!=NULL)
				{
				(**elecpptr)=*((*elecpptr)->next);
				}	
			}
		}
		printf("\nELECTRONICS ARE\n");
		elecptr=*elecpptr;	
		while(elecptr!=NULL)
		{
			printf("Name is %s and quantity is %d\n",elecptr->product.name,elecptr->product.orders);
			elecptr=elecptr->next;
		}
	}	

	


	//int flag=1;
	//int flag1=0;
	//int count=0;
	if(cmpptr!=NULL)
	{
		cmpptr=cmlp;
		cmpptr1=cmlp;
		flag1=0;
		count=0;
		while(cmpptr1!=NULL)
		{
			count++;
			cmpptr1=cmpptr1->next;
		}
		while(flag1<(count-1))
		{
			cmpptr1=cmpptr;
			while(cmpptr1->next!=NULL)
			{
				if(cmpptr1->next->next!=NULL)
				{
					if(cmpptr1->next->product.orders<cmpptr1->next->next->product.orders)
					{
						cmpptr2=cmpptr1->next;
						cmpptr1->next=cmpptr2->next;
						cmpptr2->next=cmpptr1->next->next;
						cmpptr1->next->next=cmpptr2;
					}
				}
				cmpptr1=cmpptr1->next;
			}
			flag1++;
		}
	
		if(cmpptr!=NULL)
		{
			if(cmpptr->next!=NULL)
			{
				(*cmppptr)->next=cmlp->next;
				cmpptr=cmlp;
				cmpptr1=cmpptr;
				if(cmpptr1->product.orders<cmpptr1->next->product.orders)
				{
					cmpptr2=cmpptr1;
					cmpptr1=cmpptr1->next;
					while((cmpptr1!=NULL)&&(flag==1))
					{
						flag=0;
						if(cmpptr1->product.orders>=cmpptr2->product.orders)
						{
							cmpptr3=cmpptr1;
							cmpptr1=cmpptr1->next;
							flag=1;
						}
					}
				}
				if(cmpptr3!=NULL)
				{
					cmpptr1=cmpptr3;
					cmpptr2->next=cmpptr1->next;
					cmpptr1->next=cmpptr2;
				}
				if(cmpptr3!=NULL)
				{
					cmpptr=cmpptr->next;
				}
				if(cmpptr3!=NULL)
				{
				(**cmppptr)=*((*cmppptr)->next);
				}	
			}
		}
		printf("\nCOMPUTER ACCESSORIES ARE\n");
		cmpptr=*cmppptr;	
		while(cmpptr!=NULL)
		{
			printf("Name is %s and quantity is %d\n",cmpptr->product.name,cmpptr->product.orders);
			cmpptr=cmpptr->next;
		}
	}	
	
	//int flag=1;
	//int flag1=0;
	//int count=0;
	if(gamptr!=NULL)
	{
		gamptr=gp;
		gamptr1=gp;
		flag1=0;
		count=0;
		while(gamptr1!=NULL)
		{
			count++;
			gamptr1=gamptr1->next;
		}
		while(flag1<(count-1))
		{
			gamptr1=gamptr;
			while(gamptr1->next!=NULL)
			{
				if(gamptr1->next->next!=NULL)
				{
					if(gamptr1->next->product.orders<gamptr1->next->next->product.orders)
					{
						gamptr2=gamptr1->next;
						gamptr1->next=gamptr2->next;
						gamptr2->next=gamptr1->next->next;
						gamptr1->next->next=gamptr2;
					}
				}
				gamptr1=gamptr1->next;
			}
			flag1++;
		}
	
		if(gamptr!=NULL)
		{
			if(gamptr->next!=NULL)
			{
				(*gampptr)->next=gp->next;
				gamptr=gp;
				gamptr1=gamptr;
				if(gamptr1->product.orders<gamptr1->next->product.orders)
				{
					gamptr2=gamptr1;
					gamptr1=gamptr1->next;
					while((gamptr1!=NULL)&&(flag==1))
					{
						flag=0;
						if(gamptr1->product.orders>=gamptr2->product.orders)
						{
							gamptr3=gamptr1;
							gamptr1=gamptr1->next;
							flag=1;
						}
					}
				}
				if(gamptr3!=NULL)
				{
					gamptr1=gamptr3;
					gamptr2->next=gamptr1->next;
					gamptr1->next=gamptr2;
				}
				if(gamptr3!=NULL)
				{
					gamptr=gamptr->next;
				}
				if(gamptr3!=NULL)
				{
				(**gampptr)=*((*gampptr)->next);
				}	
			}
		}
		printf("\nGAMING ACCESSORIES ARE\n");
		gamptr=*gampptr;	
		while(gamptr!=NULL)
		{
			printf("Name is %s and quantity is %d\n",gamptr->product.name,gamptr->product.orders);
			gamptr=gamptr->next;
		}
	}	

	
	
	
	//int flag=1;
	//int flag1=0;
	//int count=0;
	if(appptr!=NULL)
	{
		appptr=alp;
		appptr1=alp;
		flag1=0;
		count=0;
		while(appptr1!=NULL)
		{
			count++;
			appptr1=appptr1->next;
		}
		while(flag1<(count-1))
		{
			appptr1=appptr;
			while(appptr1->next!=NULL)
			{
				if(appptr1->next->next!=NULL)
				{
					if(appptr1->next->product.orders<appptr1->next->next->product.orders)
					{
						appptr2=appptr1->next;
						appptr1->next=appptr2->next;
						appptr2->next=appptr1->next->next;
						appptr1->next->next=appptr2;
					}
				}
				appptr1=appptr1->next;
			}
			flag1++;
		}
	
		if(appptr!=NULL)
		{
			if(appptr->next!=NULL)
			{
				(*apppptr)->next=alp->next;
				appptr=alp;
				appptr1=appptr;
				if(appptr1->product.orders<appptr1->next->product.orders)
				{
					appptr2=appptr1;
					appptr1=appptr1->next;
					while((appptr1!=NULL)&&(flag==1))
					{
						flag=0;
						if(appptr1->product.orders>=appptr2->product.orders)
						{
							appptr3=appptr1;
							appptr1=appptr1->next;
							flag=1;
						}
					}
				}
				if(appptr3!=NULL)
				{
					appptr1=appptr3;
					appptr2->next=appptr1->next;
					appptr1->next=appptr2;
				}
				if(appptr3!=NULL)
				{
					appptr=appptr->next;
				}
				if(appptr3!=NULL)
				{
				(**apppptr)=*((*apppptr)->next);
				}	
			}
		}
		printf("\nHOME AND KITCHEN APPLIANCES ARE\n");
		appptr=*apppptr;	
		while(appptr!=NULL)
		{
			printf("Name is %s and quantity is %d\n",appptr->product.name,appptr->product.orders);
			appptr=appptr->next;
		}
	}	
}
int hash1(char*str)
{
	int sum=0;
	int num;
	int i=0;
	char c=*(str+i);
	while(c!='\0')
	{
		num='c';
		num=num*i;
		sum=sum+num;
		i++;
		c=*(str+i);
			
	}
	return sum;
}	


void refund_function(char acc[])
{
	printf("\nREFUND INITIATED\n");
}


//Input from file
Mobile_Phone*mobilef(Mobile_Phone* lptr)
{
	int i,a,b,j;
	FILE* fp;
	char str[100];
	fp=fopen("mobile.txt","r");
	while(fscanf(fp," %99s",str)==1)
	{
		Mobile_Phone* nptr;
		nptr=(Mobile_Phone*)malloc(sizeof(Mobile_Phone));
		int flag,cost,quantity;
		strcpy((nptr->product.name),str);
		fscanf(fp,"%f",&nptr->product.cost);
		fscanf(fp," %d",&nptr->product.quantity);
		fscanf(fp,"%d",&nptr->product.orders);
		nptr->next=lptr;
		lptr=nptr;
	}
	fclose(fp);
	return lptr;

}

Mobile_Accessories*mobileaccf(Mobile_Accessories* lptr)
{
	int i,a,b,j;
	FILE* fp;
	char str[100];
	fp=fopen("mobileacc.txt","r");
	while(fscanf(fp," %99s",str)==1)
	{
		Mobile_Accessories* nptr;
		nptr=(Mobile_Accessories*)malloc(sizeof(Mobile_Accessories));
		int flag,cost,quantity;
		strcpy((nptr->product.name),str);
		fscanf(fp,"%f",&nptr->product.cost);
		fscanf(fp," %d",&nptr->product.quantity);
		fscanf(fp,"%d",&nptr->product.orders);
		nptr->next=lptr;
		lptr=nptr;
	}

	return lptr;

}


Computer*computerf(Computer* lptr)
{
	int i,a,b,j;
	FILE* fp;
	char str[100];
	fp=fopen("computer.txt","r");
	while(fscanf(fp," %99s",str)==1)
	{
		Computer* nptr;
		nptr=(Computer*)malloc(sizeof(Computer));
		int flag,cost,quantity;
		strcpy((nptr->product.name),str);
		fscanf(fp,"%f",&nptr->product.cost);
		fscanf(fp,"%d",&nptr->product.quantity);
		fscanf(fp,"%d",&nptr->product.orders);
		nptr->next=lptr;
		lptr=nptr;
	}

	return lptr;

}

Electronics*electronicsf(Electronics*lptr)
{
	int i,a,b,j;
	FILE* fp;
	char str[100];
	fp=fopen("electronics.txt","r");
	while(fscanf(fp," %99s",str)==1)
	{
		Electronics* nptr;
		nptr=(Electronics*)malloc(sizeof(Electronics));
		int flag,cost,quantity;
		strcpy((nptr->product.name),str);
		fscanf(fp," %f",&nptr->product.cost);
		fscanf(fp," %d",&nptr->product.quantity);
		fscanf(fp," %d",&nptr->product.orders);
		nptr->next=lptr;
		lptr=nptr;
	}

	return lptr;

}

Gaming*gamef(Gaming*lptr)
{
	int i,a,b,j;
	FILE* fp;
	char str[100];
	fp=fopen("game.txt","r");
	while(fscanf(fp," %99s",str)==1)
	{
		Gaming* nptr;
		nptr=(Gaming*)malloc(sizeof(Gaming));
		int flag,cost,quantity;
		strcpy((nptr->product.name),str);
		fscanf(fp,"%f",&nptr->product.cost);
		fscanf(fp," %d",&nptr->product.quantity);
		fscanf(fp,"%d",&nptr->product.orders);
		nptr->next=lptr;
		lptr=nptr;
	}

	return lptr;

}

Appliances*appliancesf(Appliances*lptr)
{
	int i,a,b,j;
	FILE* fp;
	char str[100];
	fp=fopen("appliances.txt","r");
	while(fscanf(fp," %99s",str)==1)
	{
		Appliances* nptr;
		nptr=(Appliances*)malloc(sizeof(Appliances));
		int flag,cost,quantity;
		strcpy((nptr->product.name),str);
		fscanf(fp," %f",&nptr->product.cost);
		fscanf(fp," %d",&nptr->product.quantity);
		fscanf(fp,"%d",&nptr->product.orders);
		//nptr->product.orders=0;
		nptr->next=lptr;
		lptr=nptr;
	}

	return lptr;

}
void mobilew(Mobile_Phone* lptr)
{
	int i,a,b,j;
	FILE* fp;
	char str[100];
	char cost[100];
	char quantity[100];
	fp=fopen("mobile.txt","w");
	while(lptr!=NULL)
	{
		fputs(lptr->product.name,fp);
		fputs(" ",fp);
		fprintf(fp,"%f",lptr->product.cost);
		fputs(" ",fp);
		fprintf(fp,"%d",lptr->product.quantity);
		fputs(" ",fp);
		fprintf(fp,"%d",lptr->product.orders);
		fputs("\n",fp);
		lptr=lptr->next;
	}
	fclose(fp);

}

void mobileaccw(Mobile_Accessories* lptr)
{
	int i,a,b,j;
	FILE* fp1;
	char str[100];
	char cost[100];
	char quantity[100];
	fp1=fopen("mobileacc.txt","w");
	while(lptr!=NULL)
	{
		fputs(lptr->product.name,fp1);
		fputs(" ",fp1);
		fprintf(fp1,"%f",lptr->product.cost);
		fputs(" ",fp1);
		fprintf(fp1,"%d",lptr->product.quantity);
		fputs(" ",fp1);
		fprintf(fp1,"%d",lptr->product.orders);
		fputs("\n",fp1);
		lptr=lptr->next;
	}
	fclose(fp1);

}
void computerw(Computer* lptr)
{
	int i,a,b,j;
	FILE* fp;
	char str[100];
	char cost[100];
	char quantity[100];
	fp=fopen("computer.txt","w");
	while(lptr!=NULL)
	{
		fputs(lptr->product.name,fp);
		fputs(" ",fp);
		fprintf(fp,"%f",lptr->product.cost);
		fputs(" ",fp);
		fprintf(fp,"%d",lptr->product.quantity);
		fputs(" ",fp);
		fprintf(fp,"%d",lptr->product.orders);
		fputs("\n",fp);
		lptr=lptr->next;
	}
	fclose(fp);

}
void electronicsw(Electronics* lptr)
{
	int i,a,b,j;
	FILE* fp;
	char str[100];
	char cost[100];
	char quantity[100];
	fp=fopen("electronics.txt","w");
	while(lptr!=NULL)
	{
		fputs(lptr->product.name,fp);
		fputs(" ",fp);
		fprintf(fp,"%f",lptr->product.cost);
		fputs(" ",fp);
		fprintf(fp,"%d",lptr->product.quantity);
		fputs(" ",fp);
		fprintf(fp,"%d",lptr->product.orders);
		fputs("\n",fp);
		lptr=lptr->next;
	}
	fclose(fp);

}
void gamew(Gaming* lptr)
{
	int i,a,b,j;
	FILE* fp;
	char str[100];
	char cost[100];
	char quantity[100];
	fp=fopen("game.txt","w");
	while(lptr!=NULL)
	{
		fputs(lptr->product.name,fp);
		fputs(" ",fp);
		fprintf(fp,"%f",lptr->product.cost);
		fputs(" ",fp);
		fprintf(fp,"%d",lptr->product.quantity);
		fputs(" ",fp);
		fprintf(fp,"%d",lptr->product.orders);
		fputs("\n",fp);
		lptr=lptr->next;
	}
	fclose(fp);

}
void appliancesw(Appliances* lptr)
{
	int i,a,b,j;
	FILE* fp;
	char str[100];
	char cost[100];
	char quantity[100];
	fp=fopen("appliances.txt","w");
	while(lptr!=NULL)
	{
		fputs(lptr->product.name,fp);
		fputs(" ",fp);
		fprintf(fp,"%f",lptr->product.cost);
		fputs(" ",fp);
		fprintf(fp,"%d",lptr->product.quantity);
		fputs(" ",fp);
		fprintf(fp,"%d",lptr->product.orders);
		fputs("\n",fp);
		lptr=lptr->next;
	}
	fclose(fp);

}

Consumer* signupf(Consumer* lptr,List *list[])
{
	int i,a,b,j;
	FILE* fp;
	char str[100];
	fp=fopen("customer.txt","r");
	List*l,*l1;
	Consumer*nptr=NULL;
	
	while(fscanf(fp," %99s",str)==1)
	{
		nptr=(Consumer*)malloc(sizeof(Consumer));
		strcpy(nptr->name,str);
		if(fscanf(fp," %99s",str)==1)
		{
			strcpy(nptr->email_id,str);
		}
		if(fscanf(fp," %99s",str)==1)
		{
			strcpy(nptr->mobile_number,str);
		}
		if(fscanf(fp," %99s",str)==1)
		{
			strcpy(nptr->address,str);
		}
		if(fscanf(fp," %99s",str)==1)
		{
			strcpy(nptr->password,str);
		}
		if(fscanf(fp," %99s",str)==1)
		{
			i=0;
			a=0;
			while(str[i]!='\0')
			{
				i++;
			}
			i=i-1;
			j=1;
			while(i>=0)
			{
				b=(((int)str[i])-48);
				b=b*j;	
				a=a+b;
				j=j*10;
				i--;
			}
			nptr->id=a;
			l=list[a%50];
			l1=malloc(sizeof(List));
			l1->c=nptr;
			l1->next=l;
			list[a%50]=l1;
			
		}
		if(fscanf(fp," %99s",str)==1)
		{
			strcpy(nptr->fav_payment_mode,str);
		}
		fscanf(fp,"%d",&nptr->fav_payment);
		if(fscanf(fp," %99s",str)==1)
		{
			strcpy(nptr->fav_payment_mode,str);
		}
		fscanf(fp,"%f",&nptr->refund);
		
		
		strcpy((nptr->favourite_purchase),"none");
		nptr->wishlist.phones=NULL;
		nptr->wishlist.computer=NULL;
		nptr->wishlist.accessories=NULL;
		nptr->wishlist.electronics=NULL;
		nptr->wishlist.gaming=NULL;
		nptr->wishlist.appliances=NULL;
	
		nptr->history.phones=NULL;
		nptr->history.computer=NULL;
		nptr->history.accessories=NULL;
		nptr->history.electronics=NULL;
		nptr->history.gaming=NULL;
		nptr->history.appliances=NULL;
	
		nptr->payment.BNPL_number=0;
		nptr->payment.COD_number=0;
		nptr->payment.debit.number=0;
		nptr->payment.credit.number=0;
		nptr->payment.netbanking.number=0;
		nptr->payment.upi.number=0;
		nptr->payment.phonepe.number=0;
		nptr->payment.next=NULL;
		nptr->fav_payment=0;
		
		nptr->next=lptr;
		lptr=nptr;
	}
	return lptr;
}
void signupw(Consumer* lptr)
{
	int i,a,b,j;
	FILE* fp;
	char str[100];
	char cost[100];
	char quantity[100];
	fp=fopen("customer.txt","w");
	while(lptr!=NULL)
	{
		fputs(lptr->name,fp);
		fputs(" ",fp);
		fputs(lptr->email_id,fp);
		fputs(" ",fp);
		fputs(lptr->mobile_number,fp);
		
		fputs(" ",fp);
		fputs(lptr->address,fp);
		fputs(" ",fp);
		fputs(lptr->password,fp);
		fputs(" ",fp);
		fprintf(fp,"%d",lptr->id);
		fputs(" ",fp);
		fprintf(fp,"%d",lptr->fav_payment);
		fputs(" ",fp);
		fputs(lptr->fav_payment_mode,fp);
		fputs(" ",fp);
		fprintf(fp,"%f",lptr->refund);
		fputs("\n",fp);
		lptr=lptr->next;
	}
	fclose(fp);

}

