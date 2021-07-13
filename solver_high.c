
#include "push_swap.h"

static float get_median(int *s, int elems)
{
	int	    *sorted;
	int	    i;
	float	median;

	sorted = ft_memalloc(sizeof(int *) * elems - 1);
	if (sorted == NULL)
		ft_error_exit("Error: failed to malloc.");
	i = 0;
	while (i < elems)
	{
		sorted[i] = s[i];
		i++;
	}
	sort_array(&sorted, elems);
    if (i % 2 == 0)
    {
        i /= 2;
        median = ((float)sorted[i] + (float)sorted[i - 1]) / 2;
    }
    else
        {
            i /= 2;
            median = sorted[i];
        }
	free(sorted);
	return (median);
}

void    solver_high(t_stacks *s)
{
    float median;

    median = get_median(s->a, s->a_size);
    ft_printf("%f\n", median);
}