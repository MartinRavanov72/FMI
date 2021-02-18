// Complete the deleteNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    if (position == 0) {
        if (head->next == nullptr){
            delete head;
            return nullptr;
        }
        
        SinglyLinkedListNode *temp;
        temp = head;
        head = head->next;
        
        delete temp;
        return head;
    }
    
    SinglyLinkedListNode* current = head;
    SinglyLinkedListNode* previous = nullptr;
    for (int i = 0; i < position; i++) {
        if (current->next != nullptr) {
            previous = current;
            current = current->next;
        }
    }
    previous->next = current->next;
 
    delete current;
    return head;

}