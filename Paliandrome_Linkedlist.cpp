/* ZERO_ADVANCE DSA BOSSCODER 
234. Palindrome Linked List
link : https://leetcode.com/problems/palindrome-linked-list/description/
solution : https://www.youtube.com/watch?v=-DtNInqFUXs&ab_channel=takeUforward
Given the head of a singly linked list, return true if it is a 
palindrome or false otherwise.
Example 1:
Input: head = [1,2,2,1]
Output: true
Example 2:
Input: head = [1,2]
Output: false
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
bool isPalindrome(node* head) {
    node* slow=head;
    node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow=slow->next;
    node* dummy=head;
    node* prev=NULL;
    node* curr=slow;
    while(curr!=NULL){
        node* ptrnext=curr->next;
        curr->next=prev;
        prev=curr;
        curr=ptrnext;
    }
    slow=prev;
    while(slow!=NULL){
        if(slow->val!=dummy->val){
            return false;
        }
        slow=slow->next;
        dummy=dummy->next;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    node* head=nullptr;
    for(int i=0;i<n;i++){
        cin>>a[i];
        insertintoLL(head,a[i]);
    }
    display(head);
    cout<<isPalindrome(head)<<endl;
}