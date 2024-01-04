/* ZERO_ADVANCE DSA BOSSCODER 
2. Add Two Numbers
link : https://leetcode.com/problems/add-two-numbers/
solution : https://www.youtube.com/watch?v=LBVsXSMOIk4&ab_channel=takeUforward
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result= new ListNode(0);
    ListNode* ptr=result;
    int carry =0;
    while(l1!=NULL || l2!=NULL){
        int sum=0+carry;
        if(l1!=NULL){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
        }
        carry=sum/10;
        sum=sum%10;
        ptr->next=new ListNode(sum);
        ptr=ptr->next;
    }
    if(carry==1){
        ptr->next=new ListNode(1);
    }
    return result->next;
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
    ListNode* newhead=addTwoNumbers(head1,head2);
    display(newhead);
}