node* deleteKthelement(node* head,int k){
    if(head==nullptr)return head;
    
    //Which means they are asking us to delete the head of the linkedlist
    if(k==1){
        
        node *temp=head;
        head=head->next;
        delete temp;
        
        return head;
    }
    
    int cnt=0;
    
    node* temp=head,*prev=nullptr;
    
    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
            prev->next=temp->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
    
}

TC->O(K)
