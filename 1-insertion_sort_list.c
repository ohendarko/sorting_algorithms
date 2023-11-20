#include "sort.h"
/**
* insertion_sort_list - sorts a doubly linked list of integers
* in ascending order
* using the Insertion sort algorithm
* @list: list
* size: size of array
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		prev = current->prev;

		while (prev != NULL && prev->n > temp->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = temp;
			else
				*list = temp;
			if (temp->next != NULL)
				temp->next->prev = prev;
			prev->next = temp->next;
			temp->prev = prev->prev;
			temp->next = prev;
			prev->prev = temp;
			print_list(*list);
			prev = temp->prev;
		}
		current = current->next;
	}
}
