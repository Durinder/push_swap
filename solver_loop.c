#include "push_swap.h"

// static int find_displaced(int *slim, t_stacks *s, int *p, int elems)
// {
//     int i;

//     if ((p == s->a && slim[0] == slim[elems - 1] + 1) || \
//         (p == s->b && slim[0] == slim[elems - 1] - 1))
//         return (-1);
//     i = 0;
//     while ((p == s->a && slim[i] < slim[i + 1]) || \
//         (p == s->b && slim[i] > slim[i + i]))
//     {
//         i++;
//         if (i == elems)
//             return (-2);
//     }
//     return (i);
// }

// static void solver_looper(int *slim, t_stacks *s, int *p, int elems)
// {
//     int dist;

//     dist = find_displaced(slim, s, p, elems);
//     while (dist != -2)
//     {
//         ft_printf("%d\n", dist);
//         if (dist == 0)
//             redirect_buf(s, p, "switch");
//         else if ((float)dist < (float)elems / 2)
//             redirect_buf(s, p, "rotate");
//         else
//             redirect_buf(s, p, "rrotate");
//         dist = find_displaced(slim, s, p, elems);
//     }
// }

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
    ft_putnbr(ret);
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
    ft_printf("halojaa\n");
    slim = NULL;
    slim = transform_stack(s->a, s->a_size);
    print_shit(slim, s->a_size);
    //solver_looper(slim, s, s->a, s->a_size);
    ft_printf("halojaa\n");
    free(slim);
    slim = transform_stack(s->b, s->b_size);
    print_shit(slim, s->b_size);
    //solver_looper(slim, s, s->b, s->b_size);
    free(slim);
}