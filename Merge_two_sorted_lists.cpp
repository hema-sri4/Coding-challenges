/*ZERO_ADVANCE DSA BOSSCODER 
21. Merge Two Sorted Lists
link : https://leetcode.com/problems/merge-two-sorted-lists/description/
solution : https://www.youtube.com/watch?v=Xb4slcp1U38&ab_channel=takeUforward
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list.
The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:
Input: list1 = [], list2 = []
Output: []
Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
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
void display(ListNode *head){
    ListNode* temp=head;
    while(temp!=nullptr){
        cout<<temp->val<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* ptr1=list1;
    ListNode* ptr2=list2;
    ListNode* dummy=new ListNode(-1);
    ListNode* ptr3=dummy;
    while(ptr1!=nullptr && ptr2!=nullptr){
        if(ptr1->val <ptr2->val){
            ptr3->next=ptr1;
            ptr1=ptr1->next ;               
        }else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    while(ptr1!=nullptr){
        ptr3->next=ptr1;
        ptr1=ptr1->next;
        ptr3=ptr3->next;
    }
    while(ptr2!=nullptr){
        ptr3->next=ptr2;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
    }        
    return dummy->next;
}
ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
    ListNode* ptr1=list1;
    ListNode* ptr2=list2;
    ListNode* ptr;
    if(ptr1->val < ptr2->val){
        ptr=ptr1;
        ptr->next=mergeTwoLists(ptr1->next,ptr2);
    }else{
        ptr=ptr2;
        ptr->next=mergeTwoLists(ptr1,ptr2->next);
    }
    return ptr;
}
int main(){
    ListNode* head1=nullptr;
    ListNode* head2=nullptr;
    int  m,n;
    cin>>m>>n;
    int a[m],b[n];
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    } 
    for(int i=0;i<m;i++){
        insertAtTail(head1,a[i]);
    }
    for(int i=0;i<n;i++){
        insertAtTail(head2,b[i]);
    }
    display(head1);
    display(head2);
    ListNode* newhead=mergeTwoLists(head1,head2);
    ListNode* newhead2=mergeTwoLists2(head1,head2);    
    display(newhead);
    display(newhead2);    
}