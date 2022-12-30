#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *next;
};

typedef struct node *NODE;

NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	if (temp==NULL)
	{
		printf("Memory not allocated\n");
		return NULL;
	}
	
	return temp;
}

NODE insert_beg(int item,NODE first)
{
	NODE new;
	new=getnode();
	new->value=item;
	new->next=NULL;
	if(first==NULL)
	{
		return new;
	}
	else
	{
		new->next=first;
		first=new;
		return first;
	}
}

NODE delete_beg(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("Cannot delete\n");
        return NULL;
    }
    temp=first;
    temp=temp->next;
    printf("Item deleted=%d",first->value);
    free(first);
    return temp;
}


void display(NODE first)
{
	NODE temp;
	temp=first;
     printf("Stack is :");
	while(temp!=NULL)
	{  
		printf("\n%d",temp->value);
		temp=temp->next;
	}
}

void main()
{
	NODE first=NULL;
	int choice,pos,item;
	while(1)
	{
        printf("\n1.Insert \n2.delete \n3.Display\n");
		printf("\n enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
        {
            case 1:printf("\nEnter the value to be inserted\n");
			       scanf("%d",&item);
			       first=insert_beg(item,first);
                   break;

            case 2:first=delete_beg(first);
                   break;
            
            case 3:display(first);
			       break;

            default:exit(0);
			        
		}
		
	}
}
