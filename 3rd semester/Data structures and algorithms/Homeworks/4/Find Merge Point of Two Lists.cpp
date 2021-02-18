// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* iter1 = head1;
    SinglyLinkedListNode* iter2 = head2;
    
    while(iter1 != nullptr){
        while(iter2 != nullptr){
            if(iter2 == iter1){
                return iter1->data;    
            }
            iter2 = iter2->next;
        }
        iter2 = head2;
        
        iter1 = iter1->next;
    }
    return -1;


}