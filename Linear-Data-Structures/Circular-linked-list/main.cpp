#include <iostream>
using namespace std;

struct Node{
    string name;
    int scors;
    Node *next;
};
void info(Node* &head);
void game_play(Node* &head);
bool  game_math(int num);
void print(Node* &head);

int main()
{
   Node* head;
   int opt=0 , value;


      info(head);
      game_play(head);
    return 0;
}


void info(Node* &head ){
    string name , name_2;
    cout<<" Enter your name player_1 : ";
    cin>>name;
    cout<<endl;

    Node* newnode = new Node;
    Node* newnode_2 = new Node;

    newnode->name=name;
    newnode->scors=0;
    newnode->next=newnode_2;
    head = newnode;

    cout<<" Enter your name player_2: ";
    cin>>name_2;
    cout<<endl;

     newnode_2->name=name_2;
     newnode_2->scors=0;
     newnode_2->next=nullptr;


     return;
}

void game_play(Node* &head){
    Node* newnode=head->next;
    Node* current=head;
    int rounds=0, num=0;
    cout<<" Player : "<<head->name<<endl;
    cout<<" Player : "<<newnode->name<<endl;
    cout<<" You have 5 rounds for both of you to play \n the roles are cleared for you before the game match \n";
    cout<<" Good Luck for you in this game ... \n";
    cout<<endl;


    do{
            rounds+=1;
            cout<<" Round  : "<<rounds<<endl;
            cout<<current->name<<" Enter the number : ";
            cin>>num;
            cout<<endl;
            if(game_math(num)){
                current->scors+=1;
            }
            if(current->next==nullptr){current->next=head;}
            else{
                current = current->next;
            }

      }while(rounds!=10);
        print(head);
}

bool game_math(int num){
return ((num*2)/2)%2==0;
}


void print(Node* &head){
    Node* current = head->next;
    cout<<head->name<<" : "<<head->scors<<endl;
    cout<<current->name<<" : "<<current->scors<<endl;
    if(head->scors<current->scors){
        cout<<current->name<<" : the winner in the game. \n";
    }
    else if(head->scors>current->scors){
        cout<<head->name<<" : the winner in the game. \n";
    }
    else {
        cout<<" Draw between players good luck in next time.";
    }
}


