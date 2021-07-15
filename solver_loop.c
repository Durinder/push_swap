#include "push_swap.h"

//for min value which == 0
//for max value which == 1
/*
static int	get_min_or_max(int *s, int size, int which)
{
	int	ret;
	int	i;

	ret = s[0];
	i = 0;
	while (i < size)
	{
    	if (which == 0 && ret > s[i])
			ret = s[i];
        if (which == 1 && ret < s[i])
            ret = s[i];
		i++;
	}
	return (ret);
}

static int check_if_done(t_stacks *s, int *p, int elems)
{
    int i;

    i = 0;
//    ft_printf("s->a:%p, s->b:%p, p:%p, elems:%d, p[0]:%d, p[1]:%d\n", s->a, s->b, p, elems, p[0], p[1]);
    while (i + 1 < elems)
    {
        if (p == s->a && p[i] > p[i + 1])
            return (i);
        if (p == s->b && p[i] < p[i + 1])
            return (i);
        i++;
    }
    return (-1);
}
*/

static void solver_looper(int *slim, t_stacks *s, int *p, int elems)
{
//    int min;
//    int max;
//    int dist;

    //min = get_min_or_max(p, elems, 0);
    //max = get_min_or_max(p, elems, 1);
//    dist = check_if_done(s, p, elems);
//   while (dist != -1)
    {
//       ft_printf("min:%d, max:%d, dist:%d\n", min, max, dist);
//        if ((p == s->a && p[0] != max && p[0] > p[1]) || 
//        (p== s->b && p[0] != min && p[0] < p[1]))
        if ((dist == 0 && p == s->a && p[0] != max) || (dist == 0 && p == s->b && p[0] != min))
        {
//            if ((p == s->a && p[0] == max && p[1] == min) || 
//            (p == s->b && p[0] == min && p[1] == max))
//                break ;
            redirect_buf(s, p, "switch");
        }
        else if ((float)dist < (float)elems / 2)
            redirect_buf(s, p, "rotate");
        else
            redirect_buf(s, p, "rrotate");
        dist = check_if_done(s, p, elems);
    }
}

int find_smallest(int *s, int elems, int *cur_min)
{
    int i;
    int candidate;
    int ret;

    i = 0;
    candidate = *cur_min;
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
    if (i == elems)
        return (-1);
    return (ret);
}

int *transform_stack(int *s, int elems)
{
    int	*slim;
	int	i;
    int cur_min;
    int min_i;

	slim = ft_memalloc(sizeof(int *) * elems - 1);
	if (slim == NULL)
		ft_error_exit("Error: Failed to malloc");
	i = 0;
    cur_min = s[0];
	while (i < elems)
	{
        if (s[i] < cur_min)
            cur_min = s[i];
		i++;
	}
    i = 0;
    while (i < elems)
    {
        min_i = find_smallest(s, elems, &cur_min);
        slim[min_i] = i;
        i++;
    }
    return (slim);
}

void    solver_loop(t_stacks *s)
{
    int *slim;
//   ft_printf("halojaa\n");
    slim = NULL;
    slim = transform_stack(s->a, s->a_size);
    solver_looper(slim, s, s->a, s->a_size);
//    ft_printf("halojaa\n");
    free(slim);
    slim = transform_stack(s->b, s->b_size);
    solver_looper(slim, s, s->b, s->b_size);
    free(slim);
}