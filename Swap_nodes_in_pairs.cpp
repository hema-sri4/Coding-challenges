/* ZERO_ADVANCE DSA BOSSCODER 
24. Swap Nodes in Pairs
link : https://leetcode.com/problems/swap-nodes-in-pairs/description/
similar to reverse k groups solution : https://www.youtube.com/watch?v=Of0HPkk3JgI&t=324s&ab_channel=takeUforward
actual solution : https://www.youtube.com/watch?v=WYlMkut4XDw&ab_channel=NareshGupta
Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:
Input: head = []
Output: []
Example 3:
Input: head = [1]
Output: [1]
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
ListNode* swapPairs(ListNode* head) {
    ListNode* dummy=new ListNode(0);
    dummy->next=head;
    ListNode* curr=dummy,*nex=dummy,*pre=dummy;
    int length=0;
    while(curr->next!=nullptr){
        curr=curr->next;
        length++;
    }
    while(length>=2){
        curr=pre->next;
        nex=curr->next;
        for(int i=1;i<2;i++){
            curr->next=nex->next;
            nex->next=pre->next;
            pre->next=nex;
            nex=curr->next;
        }
        pre=curr;
        length-=2;
    }
    return dummy->next;
}
int main(){
    ListNode* head1=nullptr;
    int m;
    cin>>m;
    int a[m];
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        insertAtTail(head1,a[i]);
    }
    display(head1);
    ListNode* newhead=swapPairs(head1);
    display(newhead);
}