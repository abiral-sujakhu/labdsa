#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 5

int stack_arr[max];
int top=-1;
void push(int data){
    if(top==max-1)
    {
        printf("stack is overflow");
        return;
    }
    top=top+1;
    stack_arr[top]=data;
}
void pop(){
    if(top==-1)
    {
        printf("stack is underflow");
        return;
    }
    top=top-1;
}
void display(){
    if(top==-1)
    {
        printf("stack is empty");
        return;
    }
    for(int i=top;i>=0;i--)
    {
        printf("%d\n",stack_arr[i]);
    }
}

int main()
{
    int choice, data;
    while(1)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}


