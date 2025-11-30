#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<string> parcel;
    int ch;
    string p;

    while(true){
        cout<<"\n1 Add Parcel\n2 Process Parcel\n3 Show Pending\n4 Exit\nEnter: ";
        cin>>ch;

        if(ch==1){
            cin>>p;
            parcel.push(p);
        }
        else if(ch==2){
            if(parcel.empty()) cout<<"No parcel!\n";
            else{ cout<<"Processed: "<<parcel.front()<<endl; parcel.pop(); }
        }
        else if(ch==3){
            queue<string> temp=parcel;
            cout<<"Pending: ";
            while(!temp.empty()){ cout<<temp.front()<<" "; temp.pop();}
            cout<<endl;
        }
        else break;
    }
}
