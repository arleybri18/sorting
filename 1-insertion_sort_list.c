#include "sort.h"
/**
 * insertion_sort_list -
 *
 * Return: 
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *auxp, *auxn, *x, *aux2;

	aux2 = *list;


	while(aux2->next)
	{

		auxp = *list;
		x = (*list)->next;
		while(x->next)
		{
			auxn = x->next;
			if(x->n < auxp->n)
			{
				auxp->next = auxn;
				auxn->prev = auxp;
				x->prev = auxp->prev;
				auxp->prev = x;
				x->next = auxp;
				if (auxp->prev->prev == NULL)
				{
					*list = auxp->prev;
				}
				/*printf("auxp->n %d -  x->n %d - auxn->n %d\n", auxp->n, x->n, auxn->n);*/
				print_list(*list);
				printf("\n");
			}
			x = x->next;
			auxp = x->prev;
		}
		aux2 = aux2->next;

	}
}
