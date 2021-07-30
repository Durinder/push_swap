#include "push_swap.h"

static void sort(t_stacks *s)
{
    size_t  i;
    int     digit;

    i = 0;
    digit = 0;
    while (1)
    {
        if (((s->a[0] >> digit)&1) == 0)
            redirect_buf(s, s->b, "push");
        else
            redirect_buf(s, s->a, "rotate");
        if (i == s->elems)
        {
            while (s->b_size != 0)
                redirect_buf(s, s->a, "push");
            i = 0;
            digit++;
            if (check_solution(s))
                break ;
        }
        i++;    
    }
}

static int find_smallest(int *s, int elems, int *cur_min)
{
    int i;
    int candidate;
    int ret;

    i = 0;
    candidate = *cur_min;
    ret = s[0];
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

static void transform_stack(t_stacks *s)
{
    int     *slim;
	size_t i;
    int     cur_min;
    int     min_i;

	slim = ft_memalloc(sizeof(int *) * s->elems);
	if (slim == NULL)
		ft_error_exit("Error");
    i = 0;
    cur_min = INT_MIN;
    while (i < s->elems)
    {
        min_i = find_smallest(s->a, s->elems, &cur_min);
        slim[min_i] = i; //THINK NOT ENOUGH SPACE FOR MORE THAN INT/2 INPUTS!
        i++;
    }
    free(s->a);
    s->a = slim;
}

void    radix_sort(t_stacks *s)
{
    transform_stack(s);
    sort(s);
}