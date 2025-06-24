int lengthoflinkedlist(node *root){
    
    if(root==nullptr)return 0;
    
    int len=0;
    
    while(root!=nullptr){
        len++;
        root=root->next;
    }
    
    return len;
    
}
