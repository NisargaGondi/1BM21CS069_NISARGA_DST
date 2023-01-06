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
N reversal(N ptr){
    if (ptr==NULL){
        printf("linked list empty\n");
        return ptr;
    }
    else{ N q=NULL;
        while(ptr!=NULL){
             N p=ptr->next;
             ptr->next=q;
             q=ptr;
             ptr=p;
        }
        return q;
    }
}
int main(){
    N head= NULL;
    int a[5];
    for(int i=0;i<5;i++){
        printf("enter the data \n");
        scanf("%d",&a[i]);
        head =insert_rear(head,a[i]);
       
    }
    display(head);
    printf("\n");
    head=reversal(head);
    display(head);

}
