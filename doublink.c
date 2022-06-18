#include<stdio.h>
#include<stdlib.h>
void main()
{
	struct node
	{
		struct node *prev;
		int data;
		struct node *next;
	};
	struct node *head=NULL, *pos=NULL, *tail=NULL, *del=NULL;
	
	int ch, entry;
	while (1)
	{
		printf("\n1.Insert (Front)\n2.Insert (End)\n3.Display\n4.Delete (head)\n5.Delete (tail)\n6.Exit\n");
		printf("\nEnter your choice:\t");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			{
				printf("\nEnter data:\t");
				scanf("%d",&entry);
				if(head==NULL)
				{
					head=(struct node *)malloc(sizeof(struct node));
					head->prev=NULL;
					head->data=entry;
					head->next=NULL;
					pos=head;
					tail=head;
				}
				else 
				{
					head->prev=(struct node*)malloc(sizeof(struct node));
					head->prev->next=head;
					head->prev->data=entry;
					head->prev->prev=NULL;
					head=head->prev;
				}
				break;
			}
			
			case 2:
			{
				printf("\nEnter data:\t");
				scanf("%d",&entry);
				if(head==NULL)
				{
					head=(struct node *)malloc(sizeof(struct node));
					head->prev=NULL;
					head->data=entry;
					head->next=NULL;
					pos=head;
					tail=head;
				}
				else 
				{
					tail->next=(struct node*)malloc(sizeof(struct node));
					tail->next->prev=tail;
					tail->next->data=entry;
					tail->next->next=NULL;
					tail=tail->next;
				}
				break;
			}
			
			case 3:
			{
				pos=head;
				printf("\nElements are:\n");
				while (pos!=NULL)
				{
					printf("%d",pos->data);
					printf("\t\n");
					pos=pos->next;
				}
				break;
			}
			
			case 4:
			{ 	
				if(head->next==NULL)
				{
					printf("\nData to be deleted is %d",head->data);
					head=NULL;
					break;
				}
				
				del=head;
				head=head->next;
				del->next=NULL;
				head->prev=NULL;
				printf("\nData to be deleted is %d",del->data);
				free(del);
				printf("\n");
				break;
			}
			
			case 5:
			{ 
				if(head->next==NULL)
				{
					printf("\nData to be deleted is %d",head->data);
					head=NULL;
					break;
				}
				
				del=tail;
				tail=tail->prev;
				del->prev=NULL;
				tail->next=NULL;
				printf("\nData to be deleted is %d",del->data);
				free(del);
				printf("\n");
				break;		
			}
		
			
			case 6:
			{
				printf("\nGoodbye");
				exit(0);
			}
			
			default:
			{
				printf("Invalid choice");
				break;
			}
		}
	}
}



