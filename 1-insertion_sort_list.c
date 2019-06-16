#include "sort.h"
/**
 * insertion_sort_list -
 *
 * Return: 
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *auxp = NULL, *auxn = NULL, *x = NULL;

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
				x->next = auxp;
				auxp->prev = x;
				/*printf("auxp->n %d -  x->n %d - auxn->n %d\n", auxp->n, x->n, auxn->n);*/
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
					auxp->next = x;
					auxn = x->next;
					/*printf("else adentro\n");*/
				}
				/*printf("auxp->n %d -  x->n %d - auxn->n %d\n", auxp->n, x->n, auxn->n);*/
				print_list(*list);
			}
			else
			{
				x = auxn;
				auxn = auxn->next;
				auxp = auxp->next;
				/*printf("else afuera\n");*/
			}
		}
}
