#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

void ins(Node* &head);
void ins_bet(Node* &head);
void del(Node* &head);
void print(Node* &head);
void n_num(Node* &head);
void edit(Node* &head);
void mov_in_list(Node* &head);

int main()
{
   Node* head=nullptr;
   int opt=0 , value;

   do{
        cout<<"1-Insert to Linked list.\n";
        cout<<"2-Insert between nodes. \n";
        cout<<"3-delete Node .\n";
        cout<<"4-Display.\n";
        cout<<"5-Number of Nodes .\n";
        cout<<"6-Edit data .\n";
        cout<<"7-Move in list.\n";
        cout<<"8-End process.\n";
        cout<<"Enter your choice : ";
        cin>>opt;
        cout<<endl;
    switch(opt){
        case 1 : ins(head) ;break;
        case 2 : ins_bet(head);break;
        case 3 : del(head);break;
        case 4 : print(head);break;
        case 5 : n_num(head);break;
        case 6 : edit(head); break;
        case 7 : mov_in_list(head);break;
        case 8 : cout<<" Ending process. \n";break;
       default : cout<<" wrong input. \n";
    }
   }while(opt!=8);
    return 0;
}

void ins(Node* &head ){
    int value;
    cout<<" Enter value : ";
    cin>>value;
    cout<<endl;

    Node* newnode = new Node;
    newnode->data=value;
    newnode->next=nullptr;
    newnode->prev=nullptr;

    if(head==nullptr){
        head=newnode;
        return;
    }

    Node* current = head ;
    while(current->next!=nullptr){
        current=current->next;
    }
    current->next=newnode;
    newnode->prev= current;
}

void del(Node* &head){
    int check_val;
    Node* current = head;
    Node* prev_n;
    Node* next_n;

    if(head==nullptr){cout<<" Empty list. \n";}
    else {
        cout<<" Enter the value if Node data to delete it : ";
        cin>>check_val;
        cout<<endl;
        if(head->data==check_val){
            prev_n=head;
            current=current->next;
             head = current;
             head->prev=nullptr;
            delete prev_n;
            return;
        }
        while(current!=nullptr){

        if(current->next==nullptr&&current->data==check_val){
            cout<<" check nullptr---\n";
            prev_n=current->prev;
            prev_n->next=nullptr;
            delete current;
            break;
        }
         if(current->data==check_val){
            prev_n=current->prev;
            next_n=current->next;
            //prev_n->next=next_n->prev;  <- focus on this mistake
            prev_n->next=next_n;
            next_n->prev=prev_n;
            delete current;
            break;
        }
         current = current->next;
        }
    }
}

void print(Node* &head){
    Node* current = head;
    if(head==nullptr){
        cout<<"The list is empty. \n";
    }
    else {

        while(current!=nullptr){
             cout<<current->data<<" ";
             current = current->next;
        }
        cout<<endl;
    }
}

void n_num(Node* &head){
    int coun=0;
    if(head==nullptr){
        cout<<" Empty list. \n";
    }
    else {
        Node* current = head;
        while(current!=nullptr){

            coun+=1;
            current = current->next;
        }
        cout<<" Number of Nodes : "<<coun<<endl;
    }
}

void edit(Node* &head){
    Node* current = head;
    int value , new_v;
    if(head==nullptr){cout<<" empty list .\n";}
    else {
            cout<<" enter the value you want to make an edition on it : ";
            cin>>value;
        while(current!=nullptr){
            if(current->data==value){
                cout<<" Enter new value : ";
                cin>>new_v;
                current->data=new_v;
            }
            current = current->next;
        }
    }
}
void ins_bet(Node* &head){

    Node* ins_node = new Node;
    Node* current = head;
    Node* prev_n;
    int val_1=0, val_2=0, node_val=0;

    cout<<" enter the new node value ";
    cin>>node_val;
    ins_node->data=node_val;
    ins_node->next=nullptr;
    ins_node->prev=nullptr;
    cout<<endl;
    cout<<endl;
    cout<<" Enter the Between any two nodes \n you want to add your new node ? \n";
    cout<<" Node number  1 : ";
    cin>>val_1;
    cout<<endl;
    cout<<" Node number  2 : ";
    cin>>val_2;
    cout<<endl;

    while(current->data!=val_2){
         current=current->next;
         cout<<" current :  "<<current->data<<endl;
         prev_n=current->prev;
    }
    ins_node->next=current;
    ins_node->prev=prev_n;
    current->prev=ins_node;
    prev_n->next=ins_node;
}

void mov_in_list(Node* &head){
    Node* mov=head;
    int opt=0;
    cout<<" Move in this list from the head : "<<head->data<<endl;
    do{
        cout<<"1-Step for front. \n";
        cout<<"2-Step for back.\n ";
        cout<<"3-Exit from moving in the list.\n";
        cout<<" Enter your choice : ";
        cin>>opt;
        cout<<endl;
        cout<<endl;
        switch(opt){
        case 1 : if(mov->next!=nullptr){mov=mov->next;}
                 else{ cout<<" Next is = nullptr \n";}
                 cout<<"current node is :"<<mov->data<<"\n"<<endl;break;
        case 2 :if(mov->prev!=nullptr){mov=mov->prev;}
                 else{ cout<<" This is the first Node \n No previous node behind this. \n"; }
                 cout<<"current node is :"<<mov->data<<"\n"<<endl;break;
        case 3 : cout<<" Exit...\n ";break;
        default : cout<<" wrong input .\n ";
        }
    }while(opt!=3);
}
