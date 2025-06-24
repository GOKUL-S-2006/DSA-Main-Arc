#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
    
    node(int val){
        
        data=val;
        next=nullptr;
    }
};

int main() {
    
    vector<int> arr={10,20,30,40,50};
    
    int n=arr.size();
    
    node* head=new node(arr[0]);
    node* temp=head;

    for(int i=1;i<n;i++){
        temp->next=new node(arr[i]);
        temp=temp->next;
    }  
    
   

    return 0;
}
