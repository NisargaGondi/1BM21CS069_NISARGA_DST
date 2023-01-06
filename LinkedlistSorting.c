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
// N concat(N head1, N head2)
N sort(N head){
    int temp;
    N p= head;
    if(head==NULL){
        printf("linked list empty\n");
        return NULL;
    }
    else{
        while(p->next!=NULL){
            N q=p->next;
            while(q!=NULL){
                if(p->data>q->data){
                    temp=p->data;
                    p->data=q->data;
                    q->data=temp;
                }
                q=q->next;
       
                    }
                    p=p->next;
    }
return head;
}
}


int main(){
    N head= NULL;
   
    int a[5];
    for(int i=0;i<5;i++){
        printf("enter the data for  linked list\n");
        scanf("%d",&a[i]);
        head =insert_rear(head,a[i]);
       
    }
    display(head);
printf("\n");
// printf("\n");
head=sort(head);
display(head);

   

    // display(head1);

}
