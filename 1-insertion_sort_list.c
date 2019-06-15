#include "sort.h"
/**
 * insertion_sort_list -
 *
 * Return: 
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *auxp, *auxn, *x;

	auxp = *list;
	x = (*list)->next;
	auxn = x->next;
		while(x->next)
		{
			if(x->n < auxp->n)
			{
				auxp->next = auxn;
				auxn->prev = auxp;
				x->prev = auxp->prev;
				auxp->prev = x;
				x->next = auxp;
				printf("auxp->n %d -  x->n %d - auxn->n %d\n", auxp->n, x->n, auxn->n);
				if (auxp->prev->prev == NULL)
				{
					*list = auxp->prev;
					x = auxn;
					auxn = x->next;
					printf("if adentro\n");
				}
				else
				{
					auxp = x->prev;
					auxn = x->next;
					printf("else adentro\n");
				}
				printf("auxp->n %d -  x->n %d - auxn->n %d\n", auxp->n, x->n, auxn->n);
			}
			else
			{
				x = auxn;
				auxn = auxn->next;
				auxp = auxp->next;
				printf("else afuera\n");
			}
			print_list(*list);
		}
}
