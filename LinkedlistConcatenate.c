#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};
typedef struct node * N;
N insert_rear(N ptr,int data){
    N p=(N)malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    if(ptr==NULL){
        return p;
    }
    N q= ptr;
    while(q->next!=NULL){
        q=q->next;

    }
    q->next=p;
    // q->data=data;
    // p->next=NULL;
    return ptr;

}
void display(N ptr){
    {N p=ptr;
   
    if(ptr==NULL){
        printf("list is empty\n");
    }
    else
    while(p!=NULL){
    printf("%d\t",p->data);
    p=p->next;
}
    }
   
}
N concat(N head1, N head2)
{
   
    N p=head1;
    if(head1==NULL && head2!=NULL)
    return head2;
    else if(head2==NULL && head1!=NULL)
    return head1;
    else if(head1==NULL && head2==NULL)
    {
        printf("Both the linked lists are empty to concatenate!\n");
        return NULL;
    }
    else
    {
       
        while(p->next!=NULL)
        {
            p=p->next;
        }
        printf("%d\n",p->data);
        p->next=head2;
        return head1;
}
}
int main(){
    N head1= NULL;
    N head2=NULL;
    int a[5],b[5];
    for(int i=0;i<5;i++){
        printf("enter the data for first linked list\n");
        scanf("%d",&a[i]);
        head1 =insert_rear(head1,a[i]);
       
    }
    for(int i=0;i<5;i++){
        printf("enter the data for second linked list\n");
        scanf("%d",&b[i]);
        head2 =insert_rear(head2,b[i]);
       
    }
    display(head1);
    printf("\n");
    display(head2);
    printf("\n");
    head1=concat(head1,head2);
    printf("After Concatenating both the linked list\n");
    display(head1);

    // display(head1);

}
