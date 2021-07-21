#include "push_swap.h"
#include "limits.h"

static int find_rule_breaker(int *slim, t_stacks *s, int *p, int elems)
{
    int i;

    i = 0;
    while (i < elems)
    {
        if (i == 0)
        {
            if ((p == s->a && slim[i] < slim[elems - 1] && slim[i] != 0) || \
        (p == s->b && slim[i] > slim[elems - 1] && slim[i] != elems - 1)) 
            return (-1);
        }
        else if ((p == s->a && slim[i] < slim[i - 1] && slim[i] != 0) || \
        (p == s->b && slim[i] > slim[i - i] && slim[i != elems - 1]))
            return (i - 1);
        i++;
    }
    return (-2);
}

static void solver_looper(int *slim, t_stacks *s, int *p, int elems)
{
    int dist;

    dist = find_rule_breaker(slim, s, p, elems);
    while (dist != -2)
    {
        ft_printf("%d\n", dist);
        if (dist == -1)
        {
            redirect_buf(s, p, "rrotate"); //NEED TO MAKE CHANGES TO SLIM AS WELL!!!
            redirect_buf(s, p, "switch");
        }
        else if (dist == 0)
            redirect_buf(s, p, "switch");
        else if ((float)dist < (float)elems / 2)
            redirect_buf(s, p, "rotate");
        else
            redirect_buf(s, p, "rrotate");
        dist = find_rule_breaker(slim, s, p, elems);
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
        slim[min_i] = i;
        i++;
    }
    return (slim);
}

void    print_shit(int *s, int elems)
{
    int i = 0;

    while (i < elems)
    {
        ft_printf("%d\n", s[i]);
        i++;
    }
}

void    solver_loop(t_stacks *s)
{
    int *slim;
    slim = NULL;
    slim = transform_stack(s->a, s->a_size);
    print_shit(slim, s->a_size);
    solver_looper(slim, s, s->a, s->a_size);
    free(slim);
    slim = transform_stack(s->b, s->b_size);
/*     print_shit(slim, s->b_size);
 */    solver_looper(slim, s, s->b, s->b_size);
    free(slim);
}