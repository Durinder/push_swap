#include "push_swap.h"


void    print_shit(int *s, int elems)
{
    int i = 0;

    while (i < elems)
    {
        ft_printf("%d\n", s[i]);
        i++;
    }
}

static int find_rule_breaker(t_stacks *s, int *p, int elems)
{
    int i;
    int max;
    int sorted;

    i = -1;
    max = INT_MIN;
    while (++i < elems)
    {
        if (p[i] > max)
            max = p[i];
    }
    i = 0;
    while (i + 1 < elems)
    {
        sorted = check_sorted_offset(s, p, elems);
//        ft_printf("sorted:%d\n", sorted);
        if (sorted == 0)
            return (-2);
        else if (sorted > 0)
            return (sorted);
        if ((i == 0) && ((p == s->a && p[0] + 1 == p[elems - 1]) || \
        (p == s->b && p[0] == p[elems - 1] + 1)))
            return (-1);
        if ((p == s->a && p[i] > p[i + 1]) || (p == s->b && p[i] < p[i + 1]))
            return (i);
        i++;
    }
    return (-2);
}

static void solver_looper(t_stacks *s, int *p, int elems)
{
    int dist;

    dist = find_rule_breaker(s, p, elems);
    while (dist != -2)
    {
/*         ft_printf("this to below:%d\n", dist);
        print_shit(p, elems);
        ft_printf("\n"); */
        if (dist == -1)
        {
            redirect_buf(s, p, "rrotate"); //NEED TO MAKE CHANGES TO SLIM AS WELL!!!
            redirect_buf(s, p, "switch"); //JUST FUCKING CALCULATE MIN AND MAX FROM S!
        }
        else if (dist == 0)
            redirect_buf(s, p, "switch");
        else if ((float)dist < (float)elems / 2)
            redirect_buf(s, p, "rotate");
        else
            redirect_buf(s, p, "rrotate");
        dist = find_rule_breaker(s, p, elems);
    }
}

int find_smallest(int *s, int elems, int *cur_min)
{
    int i;
    int candidate;
    int ret;

    i = 0;
    candidate = *cur_min;
    ret = 0;
    while (i < elems)
    {
        if (candidate == *cur_min && s[i] > *cur_min)
        {
            candidate = s[i];
            ret = i;
        }
        else if (s[i] < candidate && s[i] > *cur_min)
        {
            candidate = s[i];
            ret = i;
        }
        i++;
    }
    *cur_min = candidate;
    return (ret);
}

int *transform_stack(int *s, int elems)
{
    int	*slim;
	int	i;
    int cur_min;
    int min_i;

	slim = ft_memalloc(sizeof(int *) * elems);
	if (slim == NULL)
		ft_error_exit("Error: Failed to malloc");
    i = 0;
    cur_min = INT_MIN;
    while (i < elems)
    {
        min_i = find_smallest(s, elems, &cur_min);
        slim[min_i] = i - INT_MIN;
        i++;
    }
    return (slim);
}

void    solver_loop(t_stacks *s)
{
    s->a = transform_stack(s->a, s->a_size);
    solver_looper(s, s->a, s->a_size);
//    ft_printf("a done\n");
    s->b = transform_stack(s->b, s->b_size);
    solver_looper(s, s->b, s->b_size);
}
