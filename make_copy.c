#include "push_swap.h"

static int	*copy_stack(int *src, int elems, int total_elems)
{
	int	*cpy;
	int	i;

	cpy = ft_memalloc(sizeof(int *) * total_elems);
	if (cpy == NULL)
		ft_error_exit("Failed to malloc.");
	i = 0;
	while (elems > 0)
	{
		cpy[i] = src[i];
		i++;
		elems--;
	}
	return (cpy);
}

t_stacks	*copy_stacks(t_stacks *src)
{
	t_stacks	*cpy;

	cpy = ft_memalloc(sizeof(t_stacks));
	if (cpy == NULL)
		ft_error_exit("Error: failed to malloc.");
	cpy->a = copy_stack(src->a, src->a_size, src->elems);
	cpy->b = copy_stack(src->b, src->b_size, src->elems);
	cpy->elems = src->elems;
	cpy->a_size = src->a_size;
	cpy->b_size = src->b_size;
	cpy->buffer = NULL;
//	cpy->buffer = ft_memalloc(sizeof(t_buffer));
//	if (cpy->buffer == NULL)
//		ft_error_exit("Error: Failed to malloc.");
//	cpy->buffer->cmd = NULL;
//	cpy->buffer->next = NULL;
	return (cpy);
}
