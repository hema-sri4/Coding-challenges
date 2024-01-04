/* ZERO_ADVANCE DSA BOSSCODER
203. Remove Linked List Elements
LINK :https://leetcode.com/problems/remove-linked-list-elements/description/
Given the head of a linked list and an integer val, 
remove all the nodes of the linked list that has Node.val == val, and return the new head.
Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:
Input: head = [], val = 1
Output: []
Example 3:
Input: head = [7,7,7,7], val = 7
Output: []
*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void display(ListNode *head){
    while(head!=nullptr){
        cout<<head->val<<" -> ";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
void insertAtTail(ListNode* &head,int val){
    ListNode* n = new ListNode(val);    
    if (head == nullptr) {
        head = n;
        return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = n;
}
ListNode* removeElements(ListNode* head, int val) {
    if(head==NULL){ return NULL;}
    head->next=removeElements(head->next,val);
    return head->val==val?head->next:head;
}
int main(){
    ListNode* head1=nullptr;
    int  m,val;
    cin>>m>>val;
    int a[m];
    for(int i=0;i<m;i++){
        cin>>a[i];
        insertAtTail(head1,a[i]);
    }
    display(head1);
    ListNode* res=removeElements(head1,val);
    display(res);
    return 0;
}