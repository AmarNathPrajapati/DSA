/*
Design an array which abstract data type have
set of value-- total size, used_size, and a base pointer with basic method
*/
#include<iostream>
using namespace std;

class myArray{
    public:
    int total_size;
    int used_size;
    int *ptr;
    myArray(int tsize, int usize){
        total_size = tsize;
        used_size = usize;
        ptr = new int[tsize];
    }
    void set(){
        int n;
        for (int i = 0; i < used_size; i++)
        {
            cout<<"Enter "<<i+1<<" the value in array"<<endl;
            cin>>n;
            ptr[i] = n;
        }
    }
    void show(){
        cout<<"your array is: "<<endl;
        for (int i = 0; i < used_size; i++)
        {
            cout<<ptr[i]<<endl;
        }
    }
    void insert(int num, int pos){
        ptr[used_size]= ptr[pos-1];
        ptr[pos-1] = num;
        used_size+=1;
    }

    void get(int pos){
        cout<<"The value you want to get is: ";
        cout<<ptr[pos-1];
    }
};
int main(){
    int t,u;
    cout<<"Enter the total size of Array"<<endl;
    cin>>t;
    cout<<"Enter the use size of Arrray"<<endl;
    cin>>u;
    myArray chandan(t,u);
    chandan.set();
    chandan.show();
    int insert;
    cout<<"Are you want to insert any value in exiting array if yes press 1 otherwise 0"<<endl;
    cin>>insert;
    if(insert){
        int num,pos;
        cout<<"please enter the number and position "<<endl;
        cin>>num>>pos;
        chandan.insert(num,pos);
    }
    chandan.show();
    // chandan.get(4);
return 0;
}