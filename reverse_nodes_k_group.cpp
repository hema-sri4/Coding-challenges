/* ZERO_ADVANCE DSA BOSSCODER 
25. Reverse Nodes in k-Group
link : https://leetcode.com/problems/reverse-nodes-in-k-group/
solution : https://www.youtube.com/watch?v=Of0HPkk3JgI&t=7s&ab_channel=takeUforward
Given the head of a linked list, reverse the nodes of the list k at a time, and return 
the modified list.k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.
Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
*/
#include <bits/stdc++.h>
using namespace std;
struct node {
    int val;
    node *next;
    node() : val(0), next(nullptr) {}
    node(int x) : val(x), next(nullptr) {}
    node(int x, node *next) : val(x), next(next) {}
};
void insertintoLL(node* &head,int val){
    node *n=new node(val);
    if(head==nullptr){
        head=n;
        return ;
    }
    node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node *head){
    while(head!=nullptr){
        cout<<head->val<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
node* reverseKGroup(node* head, int k) {
    node* dummy=new node(0);
    dummy->next=head;
    node*curr=dummy,*nex=dummy,*pre=dummy;
    int length=0;
    while(curr->next!=nullptr){
        curr=curr->next;
        length++;
    }
    while(length>=k){
        curr=pre->next;
        nex=curr->next;
        for(int i=1;i<k;i++){
            curr->next=nex->next;
            nex->next=pre->next;
            pre->next=nex;
            nex=curr->next;
        }
        pre=curr;
        length-=k;
    }
    return dummy->next;
}
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    node* head=nullptr;
    for(int i=0;i<n;i++){
        cin>>a[i];
        insertintoLL(head,a[i]);
    }
    display(head);
    node* res=reverseKGroup(head,k);
    display(res);
    return 0;
}