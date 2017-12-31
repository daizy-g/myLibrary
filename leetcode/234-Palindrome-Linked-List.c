/*

Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reverse(struct ListNode **head) {
	struct ListNode *curr = *head, *prev = NULL, *next = NULL;

	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

bool compare(struct ListNode *h1, struct ListNode *h2) {
	while (h1 && h2) {
		printf("%d %d\t", h1->val, h2->val);
		if (h1->val != h2->val)
			return false;
		h1 = h1->next;
		h2 = h2->next;
	}
	if (!h1 && !h2)
		return true;
	return false;
}

bool isPalindrome(struct ListNode* head) {
	struct ListNode *fast = NULL, *slow = NULL, *prev = NULL;
	fast = slow = head;

	if (fast && fast->next) {
		while (fast && fast->next) {
			fast = fast->next->next;
			prev = slow;
			slow = slow->next;
		}

		if (fast)
			slow = slow->next;
		reverse(&slow);
		prev->next = NULL;

		return compare(head, slow);
	}
	return true;
}
