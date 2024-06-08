#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	write(fd, s, len);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 != '\0') && (*s1 == *s2) && (n > 0))
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0') * sign;
		if (result < 0 && sign > 0)
			return (-1);
		else if (result > 0 && sign < 0)
			return (0);
		str++;
	}
	return (result);
}

void	ft_lstadd_back_int(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!new || !lst)
		return ;
	if ((*lst) == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

void	ft_lstclear_int(t_stack **lst)
{
	if (!lst || !(*lst))
		return ;
	ft_lstclear_int(&(*lst)->next);
	free(*lst);
	*lst = NULL;
}

t_stack	*ft_lstlast_int(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_lstnew_int(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	ft_lstsize_int(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

static void	ft_lstpush(t_stack **stack_src, t_stack **stack_dst)
{
	t_stack	*temp;

	if (*stack_src == NULL)
		return ;
	temp = *stack_src;
	*stack_src = (*stack_src)->next;
	temp->next = *stack_dst;
	*stack_dst = temp;
}

void	ft_pb(t_stack **stack_b, t_stack **stack_a)
{
	ft_lstpush(stack_b, stack_a);
	ft_putstr_fd("pb\n", 1);
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_lstpush(stack_a, stack_b);
	ft_putstr_fd("pa\n", 1);
}

static void	ft_lstreverse_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*new_tail;

	if (*stack == NULL || (*stack)->next == NULL)
        return ;
	head = ft_lstlast_int(*stack);
	new_tail = *stack;
	while (new_tail->next->next != NULL)
		new_tail = new_tail->next;
	new_tail->next = NULL;
	head->next = *stack;
	*stack = head;
}

void	ft_rra(t_stack **stack_a)
{
	ft_lstreverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_stack **stack_b)
{
	ft_lstreverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_lstreverse_rotate(stack_a);
	ft_lstreverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}

static void	ft_lstrotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;

	if (*stack == NULL || (*stack)->next == NULL)
        return ;
	temp = *stack;
	*stack = (*stack)->next;
	tail = ft_lstlast_int(*stack);
	temp->next = NULL;
	tail->next = temp;
}

void	ft_ra(t_stack **stack_a)
{
	ft_lstrotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack **stack_b)
{
	ft_lstrotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_lstrotate(stack_a);
	ft_lstrotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}

static void	ft_lstswap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
}

void	ft_sa(t_stack **stack_a)
{
	ft_lstswap(*stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack **stack_b)
{
	ft_lstswap(*stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_lstswap(*stack_a);
	ft_lstswap(*stack_b);
	ft_putstr_fd("ss\n", 1);
}

static int	find_median_of_three(t_stack *stack_a)
{
	int 	first;
	int		last;
	t_stack *last_stack;
	int		middle;
	t_stack *mid_stack;
	int		mid_index;

	first = stack_a->content;
	printf("first: %d\n", first);
	last_stack = ft_lstlast_int(stack_a);
	last = last_stack->content;
	printf("last: %d\n", last);
	mid_index = ft_lstsize_int(stack_a) / 2;
	mid_stack = stack_a;
	while (mid_index--)
		mid_stack = mid_stack->next;
	middle = mid_stack->content;
	printf("middle: %d\n", middle);
	if ((first > middle && first < last) || (first < middle && first > last))
		return (first);
	else if ((middle > first && middle < last) || (middle < first && middle > last))
		return (middle);
	else
		return (last);
}

void	quick_sort(t_stack **stack_a, t_stack **stack_b)
{
	int			pivot;
	t_stack		*check;

	if ((*stack_a == NULL) || (*stack_a)->next == NULL)
		return ;
	if (check_order(*stack_a))
		return ;
	//stack_b = NULL;
	pivot = find_median_of_three(*stack_a);
	printf("pivot: %d\n", pivot);
	check = *stack_a;
	while (check != NULL)
	{
 		if (stack_b)
		{
			printf("stack_b before: ");
       		print_stack(*stack_b);
		}
		printf("stack_a before: ");
		print_stack(*stack_a);
		printf("check->content: %d\n", check->content);
		printf("stack_a->content: %d\n", (*stack_a)->content);
		printf("pivot: %d\n", pivot);
		if ((check->content > pivot) && (check->content == (*stack_a)->content))
		{
			check = check->next;
			ft_pb(stack_a, stack_b);
		}
		else if (check->content > pivot)
		{
			ft_ra(stack_a);
		}
		else 
			check = check->next;
	}
	quick_sort(stack_a, stack_b);
	quick_sort(stack_b, stack_a);
	while (*stack_b)
	{
		ft_pa(stack_b, stack_a);
		ft_ra(stack_a);
		printf("stack_b now: ");
        print_stack(*stack_b);
		printf("stack_a now: ");
		print_stack(*stack_a);
	}
}

void	sort_3(t_stack **stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack_a)->content;
	middle = (*stack_a)->next->content;
	bottom = (*stack_a)->next->next->content;
	if ((top < middle) && (middle > bottom) && (bottom > top))
	{
		ft_rra(stack_a);
		ft_sa(stack_a);
	}
	else if ((top > middle) && (middle < bottom) && (bottom > top))
		ft_sa(stack_a);
	else if ((top < middle) && (middle > bottom) && (bottom < top))
		ft_rra(stack_a);
	else if ((top > middle) && (middle < bottom) && (bottom < top))
		ft_ra(stack_a);
	else if ((top > middle) && (middle > bottom) && (bottom < top))
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
	}
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	b_value;

	ft_pb(stack_a, stack_b);
	sort_3(stack_a);
	b_value = (*stack_b)->content;
	if (b_value < (*stack_a)->content)
		ft_pa(stack_b, stack_a);
	else if (b_value < (*stack_a)->next->content)
	{
		ft_pa(stack_b, stack_a);
		ft_sa(stack_a);
	}
	else if (b_value < (*stack_a)->next->next->content)
	{
		ft_rra(stack_a);
		ft_pa(stack_b, stack_a);
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else
	{
		ft_pa(stack_b, stack_a);
		ft_ra(stack_a);
	}
}

int	check_order(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	check_integer(char *argv)
{
	int			i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '+' || argv[i] == '-')
			i++;
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_min_max(char *argv)
{
	int	result;

	result = 1;
	while (*argv++)
	{
		if (ft_strlen(argv) >= 10)
		{
			result = ft_atoi(argv);
			if (result == 0 || result == -1)
				return (0);
		}
	}
	return (1);
}

int	check_duplicates(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!ft_strncmp(argv[i], argv[j], 11))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_input(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!check_integer(argv[i]))
			return (0);
		if (!check_min_max(argv[i]))
			return (0);
		i++;
	}
	if (!check_duplicates(argv))
		return (0);
	return (1);
}

t_stack	*fill_stack(char **argv)
{
	int		i;
	int		number;
	t_stack	*new;
	t_stack	*stack_a;

	i = 0;
	number = 0;
	stack_a = NULL;
	while (argv[i])
	{
		number = ft_atoi(argv[i]);
		new = ft_lstnew_int(number);
		if (!new)
		{
			ft_lstclear_int(&stack_a);
			return (NULL);
		}
		ft_lstadd_back_int(&stack_a, new);
		i++;
	}
	return (stack_a);
}


void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = ft_lstsize_int(*stack_a);
	if (len == 2)
		ft_sa(stack_a);
	else if (len == 3)
		sort_3(stack_a);
	else if (len == 4)
		sort_4(stack_a, stack_b);
	else
		quick_sort(stack_a, stack_b);
}

#include "push_swap.h"

void	free_and_exit(t_stack **stack_a, t_stack **stack_b, int error)
{
	if (stack_a && *stack_a)
		ft_lstclear_int(stack_a);
	if (stack_b && *stack_b)
		ft_lstclear_int(stack_b);
	if (error == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else
		exit(0);
}

void	print_stack(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp)
	{
		printf("%d ", temp->content);
		temp = temp->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*argv[] = {"5", "3", "4", "1", "2", NULL};

	if (!check_input(argv))
		free_and_exit(NULL, NULL, 1);
	stack_b = NULL;
	stack_a = fill_stack(argv);
	if (!stack_a)
		free_and_exit(&stack_a, NULL, 1);
	if (check_order(stack_a))
		free_and_exit(&stack_a, NULL, 0);
	sort_stack(&stack_a, &stack_b);
	print_stack(stack_a);
	free_and_exit(&stack_a, &stack_b, 0);
	return (1);
}
