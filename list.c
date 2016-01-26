#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);

	//find the location to insert new_element
	list_t* ptr = head;
	while (ptr->next != NULL && ptr->next->index <= new_element->index) {
		ptr = ptr->next;
	}
	//insert new_element
	if (ptr == head) {
		new_element->next = head;
		head = new_element;
	}
	else {
		new_element->next = ptr->next;
		ptr->next = new_element;
	}
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	//if (head->next == NULL) return head;
	
	list_t* new_head = NULL;
	while (head != NULL) {
		list_t* temp_ptr = head->next; //save where head's next ptr is for iteration
		head->next = new_head;
		new_head = head;
		head = temp_ptr;
	}
	
	return new_head;
}

