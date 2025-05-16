#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void traversalLinkedList(struct Node* ptr){
    while(ptr !=NULL)
    {
    printf("Element: %d\n", ptr-> data);
    ptr=ptr->next;
    }
} 
// insertion  at Beginning
struct Node* insertatBeginnning(struct Node* head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data = data;
    return ptr;
}
// insertion at index I
struct Node * insertatIndex(struct Node * head, int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;
    while(i != index-1){
       p = p->next;
       i++;
    }
    ptr -> data = data; 
    ptr -> next = p->next;
    p ->next = ptr;
    return  head;
}

// insertion at the end
struct Node* insertatEnd(struct Node* head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->next = head;
    struct Node * p = head;
    while(p->next != NULL){
        p=p->next;
    }
    p -> next= ptr;
    ptr->data = data;
    ptr->next= NULL;
    return head;  
}
// insertion after the Node 
struct Node  * insertafterNode(struct Node* head,struct Node *prevNode, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr->next = prevNode -> next;
    prevNode ->next =ptr;
   
    return head;  
}











// Case1 : Deletion of first element from linked list
struct Node * deleteFirst(struct Node * head ){
    struct Node * ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

// Case 2 : Deletion of element at a given index from the linked list
struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node * p = head;
    struct Node * q = head->next;
    for (int i=0 ; i<index - 1 ; i++){
        p = p-> next;
        q = q-> next;
    }
    p -> next = NULL;
    free(q);
    return head;
}

// Case 3 : Deletion of the last element
struct Node * deleteAtEnd(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q-> next != NULL){
        p = p->next;
        q = q->next;
    }
    p -> next = q -> next;
    free(q);
    return head;
}

  
int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    // allocate memory in nodes in the linked list
    // they will be in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
 

    // link first and second Node
    head -> data = 10;
    head -> next = second;
    // link first and second Node 
    second -> data = 50;
    second -> next = third;
    // insert the third Node
    third -> data = 71;
    third -> next = fourth;
    // terminate the fourth Node
    fourth -> data = 53;
    fourth -> next = NULL;
// traversal of linked list

    printf("Linked List after inserting at beginning\n");
    traversalLinkedList(head);
    head = insertatBeginnning(head,56);
    printf("Linked List after inserting at beginning\n");
    traversalLinkedList(head);
    printf("Linked List after inserting at ith index\n");
    head = insertatIndex(head,100,3);
    traversalLinkedList(head);
    printf("Linked List after inserting at End\n");
    head = insertatEnd(head,1);
    traversalLinkedList(head);
    head = insertafterNode(head, second, 101);
    traversalLinkedList(head);
















    printf("Linked List before deletion :\n");
    traversalLinkedList(head);\

    head = deleteFirst(head);
    printf("Linked List after deletion :\n");
    traversalLinkedList(head);

    printf("Linked list after  deleting the last element:\n");
    head = deleteAtEnd(head);
    traversalLinkedList(head);

    return 0;
}