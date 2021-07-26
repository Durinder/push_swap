#include "push_swap.h"
#define INT_MIN 0


void    print_shit(int *s, int elems)
{
    int i = 0;

    while (i < elems)
    {
        ft_printf("%d\n", s[i]);
        i++;
    }
}

static int worth_or_not(int a, int b, int elems, t_stacks *s, int *p)
{
    int inside;

    inside = 0;
    while (a + inside != b)
    {
        if (a < b)
            inside++;
        else
            inside--;
    }
    if (inside < 0)
        inside = inside * -1 - 1;
    
    ft_printf("worth_or_not - a:%d b:%d, %d", a, b, elems - 2 - inside);
    if ((elems - 2 - inside > inside && p == s->a && ??? || \
        (elems - 2 - inside < inside && p == s->b && ???)))
    {
        ft_putendl("yes");
        return (1);
    }
    else
    {
        ft_putendl("no");
        return (0);
    }
}

/* static void compare_values(t_stacks *s, int *p, int elems)
{
    int a;
    int b;
    int c;

    a = p[elems - 1];
    b = p[0];
    c = p[1];
    if (p == s->a && a > b)
    {
        if (worth_or_not(p[0], p[1], elems))
            return ()

    }
        return (-1);
     max = INT_MIN; // 0 = INT_MIN // # DEFINE MAX = INT_MIN + elems - 1;
    while (++i < elems)
    {
        if (p[i] > max)
            max = p[i];
    }
    i = 0;
    if ((p == s->a && p[elems - 1] > p[0] && p[elems - 1] != max) || \
        (p == s->b && p[elems - 1] < p[0] && )
        return (-1);
    if ()
} */

static void solver_looper(t_stacks *s, int *p, int elems)
{
    int sorted;

    sorted = check_sorted_offset(s, p, elems);
    while (sorted != 0)
    {
        ft_printf("sorted:%d\n", sorted);
        print_shit(p, elems);
        if (worth_or_not(p[0], p[1], elems, s, p))
        {
            redirect_buf(s, p, "switch");
            continue ;
        }
        if (worth_or_not(p[elems - 1], p[0], elems, s, p))
            {
                redirect_buf(s, p, "rrotate");
                redirect_buf(s, p, "switch");
                continue ;
            }
        if ((float)sorted < (float)elems / 2)
            redirect_buf(s, p, "rotate");
        else
            redirect_buf(s, p, "rrotate");
        sorted = check_sorted_offset(s, p, elems);
    }
}
/*         if ((p == s->a && p[0] > p[1]) || (p == s->b && p[0] < p[1]))
        {
            if (worth_or_not(p[0], p[1], elems, s, p) == 1)
            {
                redirect_buf(s, p, "switch");
                ft_putendl("sa");
                continue ;
            }
        }
        if ((p == s->a && p[elems - 1] > p[0]) || (p == s->b && p[elems - 1] < p[0]))
        {
            if (worth_or_not(p[elems - 1], p[0], elems, s, p) == 1)
            {
                redirect_buf(s, p, "rrotate");
                redirect_buf(s, p, "switch");
                ft_putendl("rr & sa");
                continue ;
            }
        }
        if ((float)sorted < (float)elems / 2)
            redirect_buf(s, p, "rotate");
        else
            redirect_buf(s, p, "rrotate");
        sorted = check_sorted_offset(s, p, elems);
    }
} */



/*         compare = compare_values(s, p, elems);
        ft_printf("this to below:%d\n", compare);
        print_shit(p, elems);
        ft_printf("\n");
        if (compare == -1)
        {
            redirect_buf(s, p, "rrotate"); //NEED TO MAKE CHANGES TO SLIM AS WELL!!!
            redirect_buf(s, p, "switch"); //JUST FUCKING CALCULATE MIN AND MAX FROM S!
        }
        else if (compare == 0)
            redirect_buf(s, p, "switch");
        else if ((float)compare < (float)elems / 2)
            redirect_buf(s, p, "rotate");
        else
            redirect_buf(s, p, "rrotate");
        sorted = check_sorted_offset(s, p, elems); */

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
    ft_printf("a done\n");
    s->b = transform_stack(s->b, s->b_size);
    solver_looper(s, s->b, s->b_size);
}
