
#include "push_swap.h"

static int steps_to_co(t_stacks *s, int dir, float co)
{
    int i;
    int counter;

    if (dir == 1)
        i = 0;
    else
        i = s->a_size - 1;
    counter = 0;
    while (i < s->a_size && i > -1)
    {
        if ((float)s->a[i] < co)
            return (counter);
        i += dir;
        counter++;
    }
    return (s->a_size);
}

static void	push_to_b(t_stacks *s, float co)
{
    int r;
    int rr;

	while (1)
    {
        r = steps_to_co(s, 1, co);
        rr = steps_to_co(s, -1, co);
        if (r == s->a_size)
            break ;
        if (r == 0)
            redirect_buf(s, s->b, "push");
        else if (r <= rr)
            redirect_buf(s, s->a, "rotate");
        else
            redirect_buf(s, s->a, "rrotate");
    }
}

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
    push_to_b(s, median);
    solver_loop(s);
    while (s->b_size > 0)
		add_to_last(s, "pa");
}
