#include <iostream>
using namespace std;

void push(int sta[], int &p , int &si);
void pop(int &p);
void used_size_sta(int &p);
void display_sta(int sta[] , int &p);

int main()
{
    int p=-1 ,opt=0 , sizeofarr=0;
    cout<<" Enter size of stack : ";
    cin>>sizeofarr;
    int sta[sizeofarr];

    do{

        cout<<" 1-Push element. \n";
        cout<<" 2-Pop element. \n";
        cout<<" 3-Size of stack. \n";
        cout<<" 4-Display stack. \n";
        cout<<" 5- End process . \n";
        cout<<" Enter your choice : ";
        cin>>opt;
        cout<<endl;

        switch(opt){

        case 1: push(sta,p,sizeofarr);break;
        case 2: pop(p);break;
        case 3: used_size_sta(p);break;
        case 4: display_sta(sta,p);break;
        case 5: cout<<" Ending process. \n";break;
        default: cout<<"_________Wrong input_________\n";
        }
    }while(opt!=5);
    return 0;
}

void push(int sta[] , int &p , int &si){
    int num;
    if(p==si-1){
    cout<<" Overflow \n";
    }

    else {
    cout<<" Enter value : ";
    cin>>num;
    cout<<endl;
    p+=1;
    sta[p]=num;
    }
}

void pop(int &p){
    if(p<0){
        cout<<" Stack is empty.\n";
    }
    else{
     p-=1;
    }
}

void used_size_sta( int &p){
    int counter=0;
    if(p<0){
        cout<<" Stack is empty .\n";
    }
    else{
        for(int i=0 ; i<=p ; i++){
            counter+=1;
        }
        cout<<" used size is : "<<counter<<endl;
    }
}

void display_sta(int sta[] , int &p){
    if(p<0){
        cout<<" stack is empty. \n";
    }
    else{
     for(int i=p ; i>=0 ; i--){
        cout<<sta[i]<<endl;;
    }
    cout<<endl;
    }
}
