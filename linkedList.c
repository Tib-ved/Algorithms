#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

void insertNode(struct Node **head_ref){
  struct Node *temp = malloc(sizeof(struct Node));
  int val;
  printf("\n Enter the data for the node: ");
  scanf("%d", &val);
  temp->data = val;
  temp->next = *head_ref;
  *head_ref = temp;
}
  
void printList(struct Node *n){
  while(n!= NULL){
    if(n->next == NULL)
      printf("%d",n->data);
    else
      printf("%d -> ",n->data);
    n=n->next;
  }
}

void deleteNode(struct Node **head_ref, int key){
  struct Node *temp = *head_ref, *prev;
  if(temp!=NULL && temp->data == key){
    *head_ref = temp->next;
    free(temp);
    return;
  }

  while(temp!= NULL && temp->data != key){
    prev= temp;
    temp=temp->next;
  }
  if (temp==NULL) return;
  prev->next =temp->next;
  free(temp);
}

void printMiddle(struct Node *head_ref){
  struct Node *doubled = head_ref;
  struct Node *single = head_ref;

  while(doubled->next != NULL){
    doubled= doubled->next->next;
    single=single->next;
  }

  printf("\n%d is the Middle Element.",single->data);
}

void reverse(struct Node **head)
{
    if (!head)
        return;
    reverseUtil(*head, NULL, head);
}
 
// A simple and tail recursive function to reverse
// a linked list.  prev is passed as NULL initially.
void reverseUtil(struct Node *curr,struct Node *prev,struct Node **head)
{
    /* If last node mark it head*/
    if (!curr->next)
    {
        *head = curr;
 
        /* Update next to prev node */
        curr->next = prev;
        return;
    }
 
    /* Save curr->next node for recursive call */
   struct Node *next = curr->next;
 
    /* and update next ..*/
    curr->next = prev;
 
    reverseUtil(next, curr, head);
}

void printReverse(struct Node *head_ref)
{
  struct Node *next = malloc(sizeof(struct Node));
  if(head_ref->next != NULL)
    {
       next = head_ref->next;
       printReverse(next);
    }
  printf("%d ", head_ref->data);
}
  
int main(){
  struct Node* head = malloc(sizeof(struct Node));
  struct Node *current = head;
  struct Node *prev = NULL;
  struct Node *next = NULL;
      
  int ch=0, inp =0;
  while(ch!=-1){
    printf("\n\t\tLinked List\n1. Create a node.\n2. Delete a node with specific value.\n3. Print Middle Element.\n4. Reverse Linked List.\n5. Print Reverse Linked List.\n Enter -1 to exit.\nEnter your choice: ");
    scanf("%d",&ch);
    if(ch == -1) return 0;
    switch(ch){
    case 1:
      insertNode(&head);
      printList(head);
      break;
    case 2:
      printf("Enter the value to be deleted: ");
      scanf("%d", &inp);
      deleteNode(&head, inp);
      printList(head);
      break;
    case 3:
      printMiddle(head);
      break;
    case 4:
      reverse(&head);
      printList(head);
      break;
    case 5:
      printReverse(head);
      break;
    default:
      printf("\nWrong coice. Try again.");
      break;
    }
  }
  return 0;
}
