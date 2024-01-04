/* ZERO_ADVANCE DSA BOSSCODER
206. Reverse Linked List
LINK :https://leetcode.com/problems/reverse-linked-list/description/
Given the head of a singly linked list, reverse the list, and return the reversed list.
Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:
Input: head = [1,2]
Output: [2,1]
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
ListNode* reverseList(ListNode* head) {
    ListNode* prev=nullptr;
    ListNode* curr=head;
    while(curr!=nullptr){
        ListNode* ptrnext=curr->next;
        curr->next=prev;
        prev=curr;
        curr=ptrnext;
    }
    head=prev;
    return head;
}
int main(){
    ListNode* head1=nullptr;
    int m;
    cin>>m;
    int a[m];
    for(int i=0;i<m;i++){
        cin>>a[i];
        insertAtTail(head1,a[i]);
    }
    display(head1);
    ListNode* res=reverseList(head1);
    display(res);
    return 0;
}