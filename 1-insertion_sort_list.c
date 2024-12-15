#include "sort.h"

/**
 * insertion_sort_list - applies the insertion sort algorithm to double linked list
 * @list: Head of double linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *comp, *print = (*list);

	comp = (*list)->next;
	while (comp != NULL)
	{
		if ((*list)->n > comp->n)
		{
			if ((*list)->prev == NULL)
			{
				(*list)->next = comp->next;
				comp->next = (*list);
				comp->prev = NULL;
				(*list)->prev = comp;
				(*list)->next->prev = (*list);

				comp = comp->next;
				(*list) = (*list)->prev;
				print = (*list);
			}
			else if (comp->next == NULL)
			{
				(*list)->next = NULL;
				comp->next = (*list);
				(*list)->prev->next = comp;
				comp->prev = (*list)->prev;
				(*list)->prev = comp;

				(*list) = comp->prev;
			}
			else
			{
				(*list)->next = comp->next;
				comp->next = (*list);
				(*list)->prev->next = comp;
				comp->prev = (*list)->prev;
				(*list)->prev = comp;
				(*list)->next->prev = (*list);

				(*list) = comp->prev;
			}
			print_list(print);
		}
		else
		{
			comp = comp->next;
			(*list) = (*list)->next;
		}
	}
	while((*list)->prev != NULL)
		(*list) = (*list)->prev;
	print_list((*list));
}
