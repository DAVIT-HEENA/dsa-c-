#include<iostream>
using namespace std;
struct node {
    int data;
    struct node *next;
};
void deleteList(struct node* head) {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp; 
    }
}
struct node *create(){
    struct node *newnode =new struct node;
    int item;
    cout<<"enter the data"<<endl;
    cin>>item;
    newnode->data=item;
    newnode->next=NULL;
    return newnode;
}
struct node *atbeginning(struct node *head){
    struct node *temp=create();
    temp->next=head;
    head=temp;
    return head;
}

struct node *atend(struct node *head){
    struct node *temp2=create();
    struct node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=temp2;
    return head;
}

struct node *atposition(struct node*head,int position){
    if (position == 0) {
        return atbeginning(head);
    }
    if (head == NULL || position < 0) {
        cout << "List is empty!" << endl;
        return head;
    }
        struct node *temp2 = create();
    struct node *temp = head;
    int a = 1;
    while (a < position - 1 && temp->next != NULL) {
        temp = temp->next;
        a++;
    }
    if (a != position - 1) {
        cout << "Position out of bounds!" << endl;
        delete temp2;
        return head;
    }
    temp2->next = temp->next;
    temp->next = temp2;

    return head;
}

int main(){
    cout<<"davit"<<endl;
    struct node *head=NULL;
    struct node *temp=NULL;
    head=create();
    cout<<head<<endl<<head->data<<endl<<head->next<<endl;
    head=atbeginning(head);
    cout<<head<<endl<<head->data<<endl<<head->next<<endl;
    head=atend(head);
    cout<<head<<endl<<head->data<<endl<<head->next<<endl;
    head=atposition(head,2);
    cout<<head<<endl<<head->data<<endl<<head->next<<endl;
    temp=head;
    cout<<"list is as follow"<<endl;
    while(temp!=NULL){
        cout<<"["<<temp->data<<"|"<<temp->next<<"]"<<"  ";
        temp=temp->next;
    }
    deleteList(head);
    return 0;
}