#include <iostream>
using namespace std;

void ins_que(int que[], int &f , int &r , int &si);
void del_que(int &f , int &r , int &si);
void used_size_que(int &f , int &r , int &si);
void display_que(int que[] , int &f , int &r, int &si);

int main()
{
    int f=-1 , r=-1 ,opt , sizeofarr=0;
    cout<<" Enter size of queue : ";
    cin>>sizeofarr;
    int que[sizeofarr];

    while(opt!=5){

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
        case 2: del_que(f,r,sizeofarr);break;
        case 3: used_size_que(f,r,sizeofarr);break;
        case 4: display_que(que,f,r,sizeofarr);break;
        case 5: cout<<" Ending process. \n";break;
        default: cout<<"_________Wrong input_________\n";
        }
    }
    return 0;
}

void ins_que(int que[] , int &f , int &r , int &si){
    int num;
   if((f==0&&r+1==si)||(f>0&&r+1==f)){ // we can make the condition like this -> (r+1)%si==f and all of these states will be in one
    cout<<"Over flow\n";
   }
   else if(f>0&&r+1==si){

        r=(r+1)%si;
        cout<<" enter number : ";
        cin>>num;
        que[r]=num;
        cout<<endl;
   }
   else {
        r+=1;
        cout<<" r =  "<<r<<" size =  "<<si<<endl;
        cout<<" enter number : ";
        cin>>num;
        que[r]=num;
        cout<<endl;
        if(f<0){f+=1;}
   }
}

void del_que(int &f , int &r, int &si){

    if(f<0&&r<0){
        cout<<" queue is empty.  \n";
    }
    else if(f==r){
        f=-1;
        r=-1;
        cout<<" last element deleted successfully. \n";
    }
    else if(f+1==si){
        f=(f+1)%si;//f=0
    }
    else {
        f+=1;
    }
}

void used_size_que( int &f , int &r , int &si){
   int counter;
    if(f<0&&r<0){
        cout<<" circular queue is empty.\n ";
    }
    else {

        if(f<r){
     counter=0;
     for(int i=f ; i<=r ;i++){
        counter+=1;
        }
        cout<<" Used size of "<<si<<" is : "<<counter<<endl;
    cout<<endl;
    }
    else {
        counter=0;
        for(int i=f ; i<si ;i++){
            counter+=1;
        }
        for(int i=0 ; i<=r ;i++){
           counter+=1;
        }
        cout<<" Used size of "<<si<<" is : "<<counter<<endl;
    cout<<endl;
    }

    }
}

void display_que(int que[] , int &f , int &r , int &si){
    if(f<0&&r<0){
        cout<<" Queue is empty. \n";
    }

    else if(f==r){
        for(int i=f ; i<r+1 ;i++){
        cout<<que[i]<<" ";
        }
    }

    else if(f<r){
     for(int i=f ; i<=r ;i++){
        cout<<que[i]<<" ";
        }
    cout<<endl;
    }
    else {
        for(int i=f ; i<si ;i++){
        cout<<que[i]<<" ";
        }
        for(int i=0 ; i<=r ;i++){
        cout<<que[i]<<" ";
        }
    cout<<endl;
    }
}
