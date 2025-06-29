#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;
typedef struct{
    Node*top;
}Stack;
void stack(Stack*s){
    s->top = NULL;
}
int empty(Stack*s){
    return s->top == NULL;
}
void push (Stack*s, int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node ->next = s->top;
    s-> top = new_node;
}
int pop (Stack*s){
    if(empty(s)){
        printf("stack underflow\n");
        return -1;
    }
    Node*temp = s->top;
    int data = temp -> data;
    s->top = s->top->next;
    free(temp);
    return data;
}
int peek(Stack*s){
    if(empty(s)){
        printf("Stack is empty\n");
        return -1;
    }
    return s-> top -> data;
}
void display(Stack*s){
    if(empty(s)){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    Node*current = s->top;
    while(current != NULL){
        printf("%d", current->data);
        current = current -> next;
    }

}

int main(){
    Stack s;
    stack(&s);
    push(&s, 10 );
    push(&s, 20);
    push(&s, 30);
    display(&s);
    printf("\nPopped: %d\n", pop(&s));
    display(&s);
    printf("\nTop element: %d\n", peek(&s));
    return 0;
}
