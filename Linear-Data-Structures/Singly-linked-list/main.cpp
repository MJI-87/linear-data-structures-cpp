#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void ins(Node* &head);
void ins_bet(Node* &head);
void del(Node* &head);
void print(Node* &head);
void n_num(Node* &head);
void edit(Node* &head);

int main()
{
   Node* head=nullptr;
   int opt=0;

   do{
        cout<<"1-Insert Node.\n";
        cout<<"2-Insert between nodes.\n";
        cout<<"3-delete Node .\n";
        cout<<"4-Display.\n";
        cout<<"5-Number of Nodes .\n";
        cout<<"6-Edit data .\n";
        cout<<"7-End process.\n";
        cout<<"Enter your choice : ";
        cin>>opt;
        cout<<endl;
    switch(opt){
        case 1 : ins(head) ;break;
        case 2 : ins_bet(head);break;
        case 3 : del(head);break;
        case 4 : print(head);break;
        case 5 : n_num(head);break;
        case 6 : edit(head);  ;break;
        case 7 : cout<<" Ending process. \n";break;
       default : cout<<" wrong input. \n";
    }
   }while(opt!=7);
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

    if(head==nullptr){
        head=newnode;
        return;
    }

    Node* current = head ;
    while(current->next!=nullptr){
        current=current->next;
    }
    current->next=newnode;
}

void ins_bet(Node* &head){
    Node* newnode = new Node;
    Node* current = head;
    Node* next_n ;
    int value=0 , node_1=0, node_2=0;
    cout<<" Enter value of new node : ";
    cin>>value;
    cout<<endl;
    newnode->data=value;

    cout<<" Enter the two Node you want to add this new node between them.\n ";
    cout<<" Node : ";
    cin>>node_1;
    cout<<endl;
    cout<<" Node : ";
    cin>>node_2;
    cout<<endl;
    if(node_1>node_2||node_1==node_2){
        cout<<" Wrong values "<<endl;
        cout<<" You must enter the contract values ​​sequentially."<<endl;
        cout<<"from the beginning of the sequence starting with the value :"<<head->data<<endl;
    }
    else{
        next_n=current->next;
    while(current->next!=nullptr){
        if(current->data==node_1&&next_n->data==node_2){
            break;
        }
        current= current->next;
        next_n=current->next;
     }
     current->next=newnode;
     newnode->next=next_n;
    }
}

void del(Node* &head){
    int check_val;
    Node* current = head;
    Node* previous = head;
    if(head==nullptr){cout<<" Empty list. \n";}
    else {

        cout<<" Enter the value if Node data to delete it : ";
        cin>>check_val;
        cout<<endl;
        current = head->next;

        if(head->data==check_val){
             head = current;
            delete previous;
            return;
        }
        while(current!=nullptr){
         if(current->data==check_val){
            previous->next = current->next;
            delete current;
            break;
        }
         current = current->next;
         previous = previous->next;
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
        Node* current =head;
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
