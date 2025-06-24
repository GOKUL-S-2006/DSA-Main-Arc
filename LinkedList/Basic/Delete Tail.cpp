node* deletetail(node* head){

    //If either head is null or there is only one node is there in linkedlist return head itself    
    if(head==nullptr || head->next==nullptr)return head;
    
    node* temp=head;
    
    //to land at last second element to delete the last element
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    
    //Mani thing don't forgot to assign null to the last element next pointer
    temp->next=nullptr;
    
    return head;
    
}

Tc->O(n)
