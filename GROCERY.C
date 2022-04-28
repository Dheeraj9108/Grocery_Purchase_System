#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct NODE{
	char item[20];
	int price;
	struct NODE*link;
};
typedef struct NODE* node;
node first,last,temp=NULL;
char vg[][15]={"Tomato","Potato"};
char frtt[][15]={"Apple","Mango"};
char mt[][15]={"Chicken","Pork","Turkey"};
char sefd[][15]={"Fish","Frawn"};
char rc[][30]={"Basumati","Sonamasuri"};
int vp[]={40,50};
int fp[]={100,80};
node getnode(){
	node x;
	x=(node)malloc(sizeof(struct NODE));
	x->link=NULL;
	return x;
}
void veg(){
	int cur,w;
	char c[5];
	do{
		clrscr();
		printf("NAME\tPRICE\kg\n");
		printf("1.Tomato\t40\n2.potato\t50\n");
		printf("Select your item \n");
		scanf("%d",&cur);
		printf("enter the quantity\n");
		scanf("%d",&w);
		temp=getnode();
		temp->price=w*vp[cur-1];
		strcpy(temp->item,vg[cur-1]);
		if(first==NULL){
			first=temp;
			last=temp;
		}else{
			last->link=temp;
			last=temp;
		}
		printf("do you need more vegitables enter(y/n)\n");
		scanf("%s",c);
	}while(c[0]=='y' || c[0]=='Y');
	clrscr();

}
void frt(){
	int cur,w;
	char c[5];
	do{
		clrscr();
		printf("NAME\tPRICE \ kg\n");
		printf("1.Apple\t100\n2.Mango\t80\n");
		printf("Select your item \n");
		scanf("%d",&cur);
		temp=getnode();
		printf("enter the quantity\n");
		scanf("%d",&w);
		temp->price=w*fp[cur-1];
		strcpy(temp->item,frtt[cur-1]);
		if(first==NULL){
			first=temp;
			last=temp;
		}else{
			last->link=temp;
			last=temp;
		}
		printf("do you need more frts enter(y/n)\n");
		scanf("%s",c);
	}while(c[0]=='y' || c[0]=='Y');
	clrscr();

}
void bill(){
	node ptr;
	int i,j,k,sum=0;
	ptr=first;
	clrscr();
	if(first==NULL){
		printf("You haven't purchased any items\n");
	}else{
		printf("please wait your bill is processing ");
		for(i=0;i<4;i++){
			for(j=0;j<10000;j++){
				for(k=0;k<4000;k++){

				}
			}
			printf(" . ");
		}
		printf("\nNAME\t PRICE\n");
			while(ptr!=NULL){
			printf("%s\t%d\n",ptr->item,ptr->price);
			sum+=ptr->price;
			ptr=ptr->link;
		}
	}
	printf("Total amount = %d",sum);
}
void sec(){
	int ch,i;
	char a[5];
	label1:
	clrscr();
	while(1){
		printf(">>>>> M.I.T.E <<<<<\n");
		printf("1.VEGITABLE\t\t2.FRUITS\n3.SPEICES\t\t4.LEAF VEGITABLES\n5.RICE\t\t\t6.CEREALS\n7.MEAT\t\t\t8.DAIRY\n9.BAKING\t\t10.SEA FOOD\t 11.BILLING\n\nenter your choice\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:veg();
				break;
			case 2:frt();
				break;
		     /*	case 3:spcs();
				break;
			case 4:lfveg();
				break;
			case 5:rc();
				break;
			case 6:crls();
				break;
			case 7:mt();
				break;
			case 8:dyry();
				break;
			case 9:bkng();
				break;
			case 10:sefd();
				break;*/
			case 11:clrscr();
				for(i=0;i<10;i++){
					printf("\n");
				}
				for(i=0;i<4;i++){
					printf("\t");
				}

				printf("are you sure (y/n) \n");
				scanf("%s",a);
				if(a[0]=='n' || a[0]=='N'){
					goto label1;
				}else{
					return;
				}
			default:printf("INVALID CHOICE\n");
		}
	}
}
void main(){
	sec();
	bill();
	getch();
}
