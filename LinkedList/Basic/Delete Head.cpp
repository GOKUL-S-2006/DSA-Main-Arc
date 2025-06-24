node* deletehead(node* head){
    
    if(head==nullptr)return head;
    
    node *temp=head;
    
    head=head->next;
    
    delete temp;
    
    return head;
    
}

note: In main function store this pointer which was returned by this function

Tc->O(1)
