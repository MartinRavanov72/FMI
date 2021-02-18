// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    if(position == 0 || head == nullptr){
        SinglyLinkedListNode* newHead = new SinglyLinkedListNode(data);
        newHead->next = head;
        head = newHead;
        
        return head;
    }
    
    SinglyLinkedListNode* current = head;
    SinglyLinkedListNode* previous = nullptr;
    for (int i = 0; i < position; i++) {
        if (current != nullptr) {
            previous = current;
            current = current->next;
        }
    }
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    newNode->next = current;
    previous->next = newNode;
    
    return head;
}