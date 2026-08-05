#include <iostream>
using namespace std;

void ins_que(int que[], int &f , int &r , int &si);
void del_que(int &f , int &r );
void used_size_que(int &f , int &r , int &si);
void display_que(int que[] , int &f , int &r);

int main()
{
    int f=-1 , r=-1 ,opt , sizeofarr=0;
    cout<<" Enter size of queue : ";
    cin>>sizeofarr;
    int que[sizeofarr];

    do{

        cout<<" 1-Insert number. \n";
        cout<<" 2-Delete number. \n";
        cout<<" 3-Size of queue. \n";
        cout<<" 4-Display queue. \n";
        cout<<" 5- End process . \n";
        cout<<" Enter your choice : ";
        cin>>opt;
        cout<<endl;

        switch(opt){

        case 1: ins_que(que,f,r,sizeofarr);break;
        case 2: del_que(f,r);break;
        case 3: used_size_que(f,r,sizeofarr);break;
        case 4: display_que(que,f,r);break;
        case 5: cout<<" Ending process. \n";break;
        default: cout<<"_________Wrong input_________\n";
        }
    }while(opt!=5);
    return 0;
}

void ins_que(int que[] , int &f , int &r , int &si){
    int num;

    if(r<0){
        r+=1;
        cout<<" enter number : ";
        cin>>num;
        que[r]=num;
        cout<<endl;
        f+=1;

    }
    else if(r==si-1){
        cout<<" Queue size is full of elements.\n ";
    }
    else {
        r+=1;
        cout<<" enter number : ";
        cin>>num;
        que[r]=num;
        cout<<endl;
    }
}

void del_que(int &f , int &r){

    if(f<0&&r<0){
        cout<<" queue is empty.  \n";
    }
    else if(f>-1&&f==r){
        f=-1;
        r=-1;
        cout<<" last element deleted successfully. \n";
    }
    else {
        f+=1;
    }
}

void used_size_que( int &f , int &r , int &si){
    if(f<0&&r<0){
        cout<<" queue is empty.\n ";
        cout<<" Full size of queue is : "<<si<<endl;
        cout<<" Used size in queue is : "<<0<<endl;
    }
    else {

    int counter=0 ;
    for(int i=f ; i<=r ; i++){
        counter++;
    }
    cout<<" Full size of queue is : "<<si<<endl;
    cout<<" Used size in queue is : "<<counter<<endl;
    }
}

void display_que(int que[] , int &f , int &r){
    if(f<0&&r<0){
        cout<<" Queue is empty. \n";
    }
    else{
     for(int i=f ; i<=r ;i++){
        cout<<que[i]<<" ";
        if(i==10){
            cout<<endl;
        }
    }
    cout<<endl;
    }
}
