#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: double linked llist
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev_prev, *prevv, *curr1, *currnext;

	if (list == NULL)
		return;

	curr = *list;

	while (curr)
	{
		if (curr->prev && curr->prev->n > curr->n)
		{
			prev_prev = curr->prev->prev;
			prevv = curr->prev;
			curr1 = curr;
			currnext = curr->next;

			prevv->next = currnext;

			if (currnext)
				currnext->prev = prevv;

			curr1->prev = prev_prev;
			curr1->next = prevv;

			if (prev_prev)
				prev_prev->next = curr1;
			else
				*list = curr1;

			prevv->prev = curr1;
			curr = *list;
			print_list(*list);
			continue;
		}
		else
			curr = curr->next;
	}
}
