#include "sort.h"

/**
 * swap_end_node - function that swap last node of the linked list
 *
 *@p: reference to the previous node of the node to swap
 *
 *@x: reference to the node to swap
 *
 *@n: reference to the next node of the node to swap
 *
 *@l: reference to the head of the list
 *
 * Return: void
 */
void swap_end_node(listint_t **p, listint_t **x, listint_t **n, listint_t **l)
{

	(*p)->next = (*x)->next;
	(*x)->prev = (*p)->prev;
	(*x)->next = *p;
	(*p)->prev = *x;
	*p = (*x)->prev;
	(*p)->next = *x;
	*n = (*x)->next;
	print_list(*l);
}

/**
 * swap_nodes - function that swap nodes
 *
 *@p: reference to the previous node of the node to swap
 *
 *@x: reference to the node to swap
 *
 *@n: reference to the next node of the node to swap
 *
 *@list: reference to the head of the list
 *
 * Return: void
 */
void swap_nodes(listint_t **p, listint_t **x, listint_t **n, listint_t **list)
{

	(*p)->next = *n;
	(*n)->prev = *p;
	(*x)->prev = (*p)->prev;
	(*x)->next = *p;
	(*p)->prev = *x;
	if ((*p)->prev->prev == NULL)
	{
		*list = (*p)->prev;
		(*x) = *n;
		*n = (*x)->next;
	}
	else
	{
		*p = (*x)->prev;
		(*p)->next = *x;
		*n = (*x)->next;
	}
	print_list(*list);
}

/**
 * insertion_sort_list - sorts a doubly linked list of ints in ascending order
 *
 *@list: reference to the head of the linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *auxp = NULL, *auxn = NULL, *x = NULL, *last = NULL;
	int sw = 1;

	if ((*list)->next == NULL)
		return;

	auxp = *list;
	x = (*list)->next;
	last = *list;
	auxn = x->next;
	while (x && sw == 1)
	{
		if (x->n < auxp->n && x->next)
			swap_nodes(&auxp, &x, &auxn, list);

		else if (x->n < auxp->n && !(x->next))
		{
			swap_end_node(&auxp, &x, &auxn, list);
			last = auxn;
		}
		else
		{
			if (last->next != NULL && x->next != NULL)
			{
				x = auxn;
				auxn = auxn->next;
				auxp = auxp->next;
			}
			else
				sw = 0;
		}
	}
}
