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


NODE insert_end(int item,NODE first)
{
	NODE new,last;
    new=getnode();
	new->value=item;
	new->next=NULL;
	if (first==NULL)
	{
		return new;
	}
	if(first->next==NULL)	
	{
		first->next=new;
		return first;
	}
	last=first;
	while(last->next!=NULL)
		last=last->next;
	last->next=new;
	return first;
}

NODE insert_pos(NODE first,int item,int pos)
{
	int count=1;
	int val=item;
	NODE new,curr,prev;
	new=getnode();
	new->value=item;
	new->next=NULL;
	
	if(first==NULL && pos==1)
	return new;
	prev=NULL;
	curr=first;
	while(count!=pos && curr!=NULL)
	{
		prev=curr;
		curr=curr->next;
		count++;
	}
	
	if(count==pos)
	{
		prev->next=new;
		new->next=curr;
		return first;
	}
	
	if(curr==NULL)
	{
		printf("position not fount\n");
		return first;
	}
	
	if(first!=NULL && pos==1)
	first=insert_beg(val,first);
	return first;
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

NODE delete_end(NODE first)
{
    NODE prev,curr;
    if(first==NULL)
     {
        printf("Cannot delete\n");
        return NULL;
    }
    prev=NULL;
    curr=first;
    while(curr->next!=NULL)
    {
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;
    printf("Item deleted=%d",curr->value);
    return first;
}

NODE delete_specific_value(NODE first,int key)
{
    NODE prev,curr;
    if(first==NULL)
    {
        printf("Cannot delete\n");
        return NULL;
    }
    curr=first;
    if(curr->value==key)
    {
        printf("Item deleted=%d",curr->value);
        first=first->next;
        free(curr);
        return first;
    }
    prev=NULL;
    curr=first;
    while(curr->value!=key && curr!=NULL)
    {
        prev=curr;
        curr=curr->next;
    }
    if(curr->value==key)
    {
        prev->next=curr->next;
        printf("%d=Item deleted",curr->value);
        free(curr);
        return first;
    }
    if(curr==NULL)
    {
        printf("End of list reached and item not fount\n");
        return first;
    }
}

void display(NODE first)
{
	NODE temp;
	temp=first;
  printf("Linked List is:");
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
		printf("\n1.Insert @ beg  \n2.Insert @ end  \n3.Insert @ pos  \n4.delete @ beg  \n5.delete @ end  \n6.delete @ specific_value \n7.Display\n");
		printf("\n enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\nEnter the value to be inserted at the begining\n");
			       scanf("%d",&item);
			       first=insert_beg(item,first);
			       break;

            case 2:printf("\nEnter the value to be inserted at the end\n");
			       scanf("%d",&item);
			       first=insert_end(item,first);
                   break;
                   
            case 3:printf("\nEnter the value to be inserted\n");
			       scanf("%d",&item);
			       printf("\nEnter the position at which item should be inserted \n");
			       scanf("%d",&pos);
			       first=insert_pos(first,item,pos);
			       break;
			    
			case 4:first=delete_beg(first);
                   break;

            case 5:first=delete_end(first);
                    break;
                   
            case 6:printf("\nEnter the value to be deleted\n");
			       scanf("%d",&item);
			       first=delete_specific_value(first,item);
			       break;
			        
			case 7:display(first);
			       break;
			         
		    default:exit(0);
			        
		}
		
	}
}
