

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node* head = NULL;

void createList(int arr[],int size)
{
    head = (struct node*)malloc(sizeof(struct node));
    head->data = arr[0];
    head->link = NULL;  

    struct node* temp;
    struct node* end = head;

    for(int i = 1;i < size;i++)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->link = NULL;

        end->link = temp;
        end = temp;
    }
}

void countElements()
{
    struct node* ptr = head;
    int count=0;
    while(ptr != NULL)
    {
        count++;
        printf("%d\t",ptr->data);
        ptr = ptr->link;
    }
    printf("\nNumber of elements:%d",count);
}

void insertAtMid(int value,int position){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=99;
    newNode->link=NULL;

struct node* temp=head;
newNode->link=temp->link;
temp->link=newNode;
}

void deleteAtBegin( ){
    struct node* temp=head;
    printf("Value deleted from beginning \n");
    head=head->link;
    free(temp);
}


void deleteAtPosition(int position){
    if (head==NULL || position<1){
        printf("Invalid position");
        return;
    }
    if(position == 1){
        deleteAtBegin();
        return;
    }

    struct node* current= head;
    struct node* previous=NULL;
    for (int i=0;i<position && current!=NULL;i++){
        previous=current;
        current=current->link;
    }
    previous->link=current->link;
printf("Value deleted from position %d = %d\n ",position,current->data);
    free(current);
}


void maxElement()
{
    int max=head->data;
    struct node* temp=head;
    while(temp!=NULL){
        if (temp->data>max){    //temp->head (first value in the list ) 20
            max=temp->data;
        }
        temp=temp->link;
    }
    printf("\n Max element is %d\n",max);
}


void insertAtStart()
{
    struct node* start = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data:");
    scanf("%d",&start->data);
    start->link = head;
    head = start;
}

int main()
{
    int arr[5] = {20,90,30,10,5};
    createList(arr,5);
    insertAtMid(99,4);
    countElements();
    insertAtStart();
    countElements();
    maxElement();
    deleteAtPosition(3);
    

}

// #include<stdio.h>
// #include<stdlib.h>
 

// struct node{
//     int data;
//     struct node* link;
// };

// struct node* head=NULL;

// void createList(int arr[],int size){
//     head=(struct node*)malloc(sizeof (struct node));
//     head->data=arr[0];
//     head->link=NULL;

//     struct node* temp;
//     struct node* end=NULL;

//     for (int i =1; i<size ;i++){
//         temp->data=arr[i];
//         temp->link=NULL;
    
//     end->link=temp;
//     end=temp;
//     }

// }
