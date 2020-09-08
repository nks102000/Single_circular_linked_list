//1905622 - NITISH KUMAR SONTHALIA
//Circular Linked list
#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void creat_list(struct node ** ,int n);
void display_list(struct node ** );
void add_first_node(struct node ** ,int n);
void add_last_node(struct node ** ,int n);
void add_node(struct node ** ,int n,int p);
void deleteNode(struct node **, int p);
void del_node_with_data(struct node ** ,int n);

int main(){
    struct node *start = NULL;
     int t;

    int f=1;

    while(f){
    printf("\n MENU ");
    printf("\n 1. ADD An Element ");
    printf("\n 2. Display The List ");
    printf("\n 3. Add First Node ");
    printf("\n 4. Add Last Node ");
    printf("\n 5. Add Node At Position ");
    printf("\n 6. Deletion of Node With Data ");
    printf("\n 7. Deletion of Node At Position ");
    printf("\n 8. EXIT ");
    scanf("%d",&t);
    int e,p;

    switch (t)
    {

    case 1:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        creat_list(&start,e);
        break;

    case 2:
        display_list(&start);
        break;

    case 3:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        add_first_node(&start,e);
        break;

    case 4:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        add_last_node(&start,e);
        break;
    
    case 5:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        printf("\n Enter The Position To Be Entered: ");
        scanf("%d",&p);
        add_node(&start,e,p);
        break;

    case 6:
        printf("\n Enter The Element Data: ");
        scanf("%d",&p);
        del_node_with_data(&start,p);
        break;

    case 7:
        printf("\n Enter The Element Position: ");
        scanf("%d",&p);
        deleteNode(&start,p);
        break;

    case 8:
        f=0;
        break;

    default:
        break;
    }
    }
    
    return 0;
}

void creat_list(struct node **st ,int n){
    struct node *temp;

    struct node *new1 = (struct node *)malloc(sizeof(struct node));

    new1->data=n;

    new1->next=*st;

    if(*st==NULL){
        *st=new1;
        new1->next=*st;
    }
    else{
        temp=*st;
        while(temp->next!=*st){
            temp= temp->next;
        }
        temp->next = new1;
    }
}
void display_list(struct node **st ){
    if (*st == NULL){ 
      printf("\n Empty List"); 
      return ;
    }

    struct node*temp=*st;
        printf("Elements in LIST are:");

    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=*st);

}

void add_first_node(struct node **st ,int n){

    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    ptr->data = n;
    ptr->next=*st;
    struct node *temp=*st;
    while(temp->next!=*st){
        temp= temp->next;
    }
    temp->next=ptr;
    *st=ptr;
}

void add_last_node(struct node **st ,int n){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    ptr->data = n;
    ptr->next=*st;
    struct node *temp=*st;
    while(temp->next!=*st){
        temp= temp->next;
    }
    temp->next=ptr;
}

void add_node(struct node **st ,int n,int p){

    if (*st == NULL){ 
      printf("\n Empty List"); 
      return ;
    }

    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    ptr->data=n;	

    int i;

    struct node *temp=*st;

    printf("\n Enter 1 for entering before the given position and 2 for entering after given position");

    int e;

    scanf("%d",&e);

    if(e==1){
    if(p==1)
    {
        ptr->next=*st;
        *st=ptr;
    }
    else{
   	for(i=1;i<p-1;i++){
    	temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    }
    }
    if(e==2){
        p=p+1;
   	for(i=1;i<p-1;i++){
    	temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    }
}

void deleteNode(struct node **st, int p) 
{

   if (*st == NULL){ 
      printf("\n Empty List"); 
      return ;
    }

    printf("\n Enter 1 for deleting the given position and 2 for deletion before given position and 3 for deletion after given position");

    int e;

    scanf("%d",&e);

   struct node* temp = *st; 

    if(e=1){
    if (p == 1) 
    { 
        *st = temp->next;    
        free(temp);         
        return; 
    } 
    else{
    for (int i=1; temp!=NULL && i<p-1; i++) 
         temp = temp->next; 
   
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    struct node *next = temp->next->next; 
  
    free(temp->next); 
  
    temp->next = next; 
    }
    }
    else if(e=2){
        p=p-1;
        if(p=0){
            return;
        }
     if (p == 1) 
    { 
        *st = temp->next;    
        free(temp);         
        return; 
    } 
    else{
    for (int i=1; temp!=NULL && i<p-1; i++) 
         temp = temp->next; 
   
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    struct node *next = temp->next->next; 
  
    free(temp->next); 
  
    temp->next = next; 
    }   
    }
    else if(e=3){
        p=p+1;
     if (p == 1) 
    { 
        *st = temp->next;    
        free(temp);         
        return; 
    } 
    else{
    for (int i=1; temp!=NULL && i<p-1; i++) 
         temp = temp->next; 
   
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    struct node *next = temp->next->next; 
  
    free(temp->next); 
  
    temp->next = next; 
    }   
    }
}

void del_node_with_data(struct node **st ,int n){

    struct node *t1,*t2;

    t1=t2=*st;

    while (t2->data!=n)
    {
        t1=t2;
        t2=t2->next;
    }

    t1->next=t2->next;
    free(t2);
}
