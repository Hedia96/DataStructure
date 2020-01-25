#include <stdio.h>
#include <conio.h>

#define Normal 0x07
#define highlight 0x70
#define ESC 27
#define Enter 13
#define Home  71
#define End   79
#define Up    72
#define Down  80
#define Tab 9

typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
}Node;

typedef struct DoublyLinkedList
{
	Node* start;
	Node* end;
}List;

void InitList(List* Lp);
Node* CreateNode();
void AppendNode (List* Lp, Node* ele);
Node* SearchNode(List L, int value);
int DeleteNode(List* Lp, int value);
void InsertNode(List* Lp, Node*ele);
void FreeList(List* Lp);
void DisplayList(List* Lp);
void SortList(List* Lp);

void main(void)
{
char menu[9][30]={"Initialize List", "Append element", "Insert element", "Search in List", "Delete element", "Delete List", "Sort List", "Display List", "Exit"};
int col=35;
int row=2;
int loc=0;
char key;
char i;
int terminate=0;  //flag
int choice;
List *linkedlist;
Node *Newnode;
int num;


do
{
 clrscr();

 for(i=0; i<9; i++)
 {
  if(i==loc)
  {
   textattr(highlight);
  }
  gotoxy(col, row + 2*i);
  cprintf("%s", menu[i]);
  textattr(Normal);
 }

 flushall();
 key=getch();

 switch (key)
 {
  case NULL:

  key= getch();

	switch(key)
	{
	 case Up:
	 loc--;
	 if(loc<0) loc=8;
	 break;

	 case Down:
	 loc++;
	 if(loc>8) loc=0;
	 break;

	 case Home:
	 loc=0;
	 break;

	 case End:
	 loc=8;
	 break;

	}
  break;

  case Enter:

	switch(loc)
	{
	 case 0:
	 clrscr();
	 InitList(linkedlist);
	 printf("Doubly Linked List is initiated.\n");
	 printf("\nPress any key to continue...");
	 getch();
	 break;
	 
	 case 1:
	 clrscr();
	 Newnode = CreateNode();
	 printf("Enter data to append: ");
	 scanf("%d",&num);
	 Newnode->data = num;
	 AppendNode(linkedlist,Newnode);
	 printf("\nPress any key to continue...");
	 getch();
	 break;

	 case 2:
	 clrscr();
	 Newnode = CreateNode();
	 printf("Enter data to insert: ");
	 scanf("%d",&num);
	 Newnode->data = num;
	 InsertNode(linkedlist,Newnode);
	 printf("\nPress any key to continue...");
	 getch();
	 break;
	 
	 case 3:
	 clrscr();
	 printf("Enter data to search in list: ");
	 scanf("%d",&num);
	 if (SearchNode(*linkedlist,num) == NULL)
	 {
		 printf("Data is NOT FOUND in list");
	 }
	 else
	 {
		 printf("Data is FOUND in list");
	 }
	 printf("\nPress any key to continue...");
	 getch();
	 break;
	 
	 case 4:
	 clrscr();
	 printf("Enter data to delete in list: ");
	 scanf("%d",&num);
	 if(  DeleteNode(linkedlist,num) ==0 )
	 {
		 printf("Delete is unsuccessful because list is already empty!");
	 }
	 else
	 {
		 printf("Node deleted successfully!");
	 }
	 printf("\nPress any key to continue...");
	 getch();
	 break;

	 case 5:
	 clrscr();
	 printf("All list is deleted!");
	 FreeList(linkedlist);
	 printf("\nPress any key to continue...");
	 getch();
	 break;
	 
	 case 6:
	 clrscr();
	 printf("All list is Sorted!");
	 SortList(linkedlist);
	 printf("\nPress any key to continue...");
	 getch();
	 break;
	 
	 case 7:
	 clrscr();
	 printf("---Displaying List---\n");
	 DisplayList(linkedlist);
	 printf("\nPress any key to continue...");
	 getch();
	 break;

	 case 8:
	 terminate=1;
	}

  break;

  case ESC:
  terminate=1;
  break;

  case Tab:
  loc++;
  if(loc>8) loc=0;
  break;
 }

}
while(terminate==0);

gotoxy(1,1);
clrscr();
printf("The program is exiting. Press any key to exit it.");
getch();
}

void InitList(List* Lp)
{
	Lp->start=NULL;
	Lp->end=NULL;
}

Node* CreateNode()
{
	return (Node*) malloc ( sizeof(Node) );
}

void AppendNode (List* Lp, Node* ele)
{
	if(Lp->start == NULL)
	{
		Lp->start = Lp->end = ele;
		ele->next= ele->prev= NULL;
	}
	else
	{
		ele->prev = Lp->end;
		Lp->end->next= ele;
		Lp->end=ele;
		ele->next=NULL;
		
	}
}

Node* SearchNode(List L, int value)
{
	Node* temp;
	if(L.start == NULL)
		return NULL;
	temp= L.start;
	while( temp!= NULL && temp->data !=value)
		temp = temp->next;
	return temp;
}

int DeleteNode(List* Lp, int value)
{
	Node* temp= Lp->start;
	if(!temp) return 0;
	temp =SearchNode(*Lp, value);
	if(!temp) return 0;
	if(Lp-> start == Lp->end && temp== Lp->start)
		Lp->start=Lp->end=NULL;
	else if(Lp-> start != Lp->end && temp== Lp->start)
	{
		Lp->start = temp->next;
		Lp->start->prev= NULL;
	}
	else if(temp == Lp->end)
	{
		Lp->end = temp->prev;
		Lp->end->next= NULL;
	}
	else
	{
		temp->prev->next= temp->next;
		temp->next->prev=temp->prev;
	}
	free(temp);
	return 1;
}

void InsertNode(List* Lp, Node*ele)
{
	Node* temp= Lp->start;
	if(!temp)
	{
		AppendNode(Lp,ele);
		return;
	}
	while(temp && temp->data < ele->data)
	{
		temp = temp->next;
	}
	if(temp == NULL)
	{
		AppendNode(Lp,ele);
		return;
	}
	if(temp == Lp->start)
	{
		temp->prev = ele;
		Lp->start = ele;
		ele->next=temp;
		ele->prev= NULL;
	}
	else
	{
		temp->prev->next=ele;
		ele->prev=temp->prev;
		ele->next=temp;
		temp->prev=ele;
	}
}

void FreeList(List* Lp)
{
	Node* temp= Lp->start;
	while(temp)
	{
		DeleteNode(Lp, temp->data);
		temp= Lp->start;
		
	}
}

void DisplayList(List* Lp)
{
	Node* temp= Lp->start;
	int index=1;
	if(temp == NULL)
		printf("List is empty.");
	while(temp!= NULL)
	{
		printf("Element %d in List = %d\n",index,temp->data);
		temp=temp->next;
		index++;
	}
}

void SortList(List* Lp)
{
	int index=0;
	int i;
	int Temporary;
	int flag;
	Node* temp= Lp->start;
	while(temp->next != NULL)
	{
		flag=0;
		while(temp->next != NULL)
		{
			if(flag ==0)
			{
				temp= Lp->start;
				flag=1;
			}
			
			if( (temp->data) > (temp->next->data) )
			{
			Temporary= temp->data;
			temp->data= temp->next->data;
			temp->next->data = Temporary;
			}
			temp= temp->next;
		}
		temp= Lp->start;
		index++;
		for(i=0; i< index; i++)
		{
			temp= temp->next;
		}
	}
}


























