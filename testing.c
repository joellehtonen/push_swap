#include "push_swap.h"

char	*ft_strdup(const char *s1)
{
	int		index;
	int		len;
	char	*pointer;

	if (!s1)
		return (NULL);
	index = 0;
	len = ft_strlen((char *)s1);
	pointer = malloc(sizeof(char) * (len + 1));
	if (pointer == NULL)
		return (NULL);
	while (s1[index] != '\0')
	{
		pointer[index] = s1[index];
		index++;
	}
	pointer[index] = '\0';
	return (pointer);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pointer;
	size_t	index;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if ((start + len) > s_len)
		len = s_len - start;
	pointer = malloc(sizeof(char) * (len + 1));
	if (pointer == NULL)
		return (NULL);
	index = 0;
	while (s[start] != '\0' && len > 0)
	{
		pointer[index++] = s[start++];
		len--;
	}
	pointer[index] = '\0';
	return (pointer);
}

static size_t	token_counter(const char *s, char c)
{
	size_t	count;
	size_t	index;

	index = 0;
	if (s[index] == c || s[index] == '\0')
		count = 0;
	else
		count = 1;
	while (s[index] != '\0')
	{
		if (s[index] == c)
		{
			if (s[index + 1] != c && s[index + 1] != '\0')
				count++;
		}
		index++;
	}
	return (count);
}

static size_t	token_len(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != c)
	{
		len++;
	}
	return (len);
}

static void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	**splitter(const char *str, char delim, char **array, size_t count)
{
	size_t	index;
	size_t	start;

	index = 0;
	start = 0;
	while (index < count)
	{
		while (str[start] == delim && str[start] != '\0')
			start++;
		array[index] = ft_substr(str, start, token_len(str + start, delim));
		if (!array[index])
		{
			array[index] = NULL;
			free_array(array);
			return (NULL);
		}
		while (str[start] != '\0' && str[start] != delim)
			start++;
		index++;
	}
	array[index] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	token_count;

	token_count = token_counter(s, c);
	result = (char **)malloc(sizeof(char *) * (token_count + 1));
	if (result == NULL)
		return (NULL);
	result = splitter(s, c, result, token_count);
	return (result);
}


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

static void	ft_lstswap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	ft_sa(t_stack **stack_a)
{
	ft_lstswap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack **stack_b)
{
	ft_lstswap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_lstswap(stack_a);
	ft_lstswap(stack_b);
	ft_putstr_fd("ss\n", 1);
}

int	check_content_order(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	check_target_order(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->target > stack_a->next->target)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	sort_3(t_stack **stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	if (check_content_order(*stack_a))
		return ;
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

void	assign_target_value(t_stack *stack_a)
{
	t_stack	*check;
	t_stack	*lowest;
	int		len;
	int		target;

	len = ft_lstsize_int(stack_a);
	target = 1;
	while (target <= len)
	{
		check = stack_a;
		lowest = NULL;
		while (check)
		{
			if ((lowest == NULL || check->content < lowest->content)
				&& (check->target == 0))
				lowest = check;
			check = check->next;
		}
		lowest->target = target;
		printf("assigned target value of %d to the content of %d\n", lowest->target, lowest->content);
		target++;
	}
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

long long	ft_atoll(const char *str)
{
	long long	result;
	int			sign;

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
		i++;
	}
	if (!check_duplicates(argv))
		return (0);
	return (1);
}

char **check_argument(int argc, char **argv)
{
	char		**result;
	int			i;

	i = 1;
	if (argc == 2)
		result = ft_split(argv[i], ' ');
	else
		result = argv;
	return (result);
}

t_stack	*fill_stack(int argc, char **argv, t_stack **stack_a)
{
	int			i;
	long long	number;
	char		**result;
	t_stack		*new;

	i = 0;
	number = 0;
	result = check_argument(argc, argv);
	if (!check_input(result))
		free_and_exit(NULL, NULL, 1);
	while (result[i])
	{
		number = ft_atoll(result[i]);
		if (number > INT_MAX || number < INT_MIN)
			free_and_exit(stack_a, NULL, 1);
		new = ft_lstnew_int(number);
		if (!new)
		{
			ft_lstclear_int(stack_a);
			return (NULL);
		}
		ft_lstadd_back_int(stack_a, new);
		i++;
	}
	return (*stack_a);
}


















int	find_lowest_cost(t_stack *stack_a)
{
	int		lowest_cost;
	int		index;
	t_stack	*check;

	lowest_cost = (stack_a->cost_a + stack_a->cost_b);
	index = stack_a->index;
	check = stack_a;
	while (check)
	{
		if ((check->cost_a + check->cost_b) < lowest_cost)
		{
			lowest_cost = (check->cost_a + check->cost_b);
			index = check->index;
		}
		check = check->next;
	}
	return (index);
}

int	find_next_smaller(t_stack *stack_b, int ref)
{
	t_stack	*check;
	t_stack	*smaller;
	t_stack *biggest;

	check = stack_b;
	smaller = NULL;
	biggest = NULL;
	//printf("ref value is %d\n", ref);
	while (check)
	{
		if (check->content < ref && (smaller == NULL || check->content > smaller->content))
			smaller = check;
		if (biggest == NULL || check->content > biggest->content)
            biggest = check;
		check = check->next;
	}
	if (smaller == NULL)
	{
		printf("ref is smallest value, biggest is %d with index of %d\n", biggest->content, biggest->index);
		return (biggest->index);
	}
	printf("smaller value is %d with index of %d\n", smaller->content, smaller->index);
	return (smaller->index);
}

int	find_next_bigger(t_stack *stack_b, int ref)
{
	t_stack	*check;
	t_stack	*bigger;
	t_stack *smallest;

	check = stack_b;
	bigger = NULL;
	smallest = NULL;
	//printf("ref value is %d\n", ref);
	while (check)
	{
		if (check->content > ref && (bigger == NULL || check->content < bigger->content))
			bigger = check;
		if (smallest == NULL || check->content > smallest->content)
            smallest = check;
		check = check->next;
	}
	if (bigger == NULL)
	{
		printf("ref is biggest value, smallest is %d with index of %d\n", smallest->content, smallest->index);
		return (smallest->index);
	}
	printf("bigger value is %d with index of %d\n", bigger->content, bigger->index);
	return (bigger->index);
}

int	find_cost_b(t_stack *stack_b, int ref)
{
	t_stack	*compare;
	int		cost;
	int		smaller_index;

	cost = 0;
	compare = stack_b;
	assign_index(stack_b);
	smaller_index = find_next_smaller(stack_b, ref);
	cost = smaller_index - 1;
	return (cost);
}

void	assign_cost(t_stack *stack_a, t_stack *stack_b)
{
	int		cost;
	int		len_a;
	int		len_b;
	int		ref;
	t_stack	*check;

	cost = 0;
	check = stack_a;
	len_b = ft_lstsize_int(stack_b);
	len_a = ft_lstsize_int(stack_a);
	while (check)
	{
		ref = check->content;
		cost = find_cost_b(stack_b, ref);
		if (cost <= len_b / 2)
			check->cost_b = cost;
		else
			check->cost_b = len_b - cost;
		if (check->index <= len_a / 2)
			check->cost_a = check->index - 1;
		else
			check->cost_a = len_a - check->index + 1;
		//if (check->target == 1 || check->target == 2 || check->target == 3)
		//	check->cost_a = 999;
		printf("assigned cost_a of %d and cost_b of %d to the content of %d\n", check->cost_a, check->cost_b, check->content);
		check = check->next;
	}
}

void	assign_index(t_stack *stack)
{
	t_stack	*check;
	int		index;

	check = stack;
	index = 1;
	while (check)
	{
		check->index = index;
		check = check->next;
		index++;
	}
}

void	rotate_a_b(t_stack **sa, t_stack **sb, int index, int len_a)
{
	t_stack	*check;
	int		count;
	int		len_b;
	int		next_index;

	count = 0;
	check = *sa;
	while (index-- > 1)
		check = check->next;
	//printf("stack a len is %d\n", len);
	//printf("len divided by two is %d\n", len / 2);
	len_b = ft_lstsize_int(*sb);
	next_index = find_next_smaller(*sb, check->content);
	printf("chosen value is %d\n", check->content);
	printf("its index is %d\n", check->index);
	printf("its move cost is %d\n", check->cost_a + check->cost_b);
	while (check->cost_a > 0 && check->cost_b > 0)
	{
		if (check->index > len_a / 2 && next_index > len_b / 2)
		{
			ft_rrr(sa, sb);
			check->cost_a--;
			check->cost_b--;
			count++;
		}
		else if (check->index < len_a / 2 && next_index < len_b / 2)
		{
			ft_rr(sa, sb);
			check->cost_a--;
			check->cost_b--;
			count++;
		}
		else
			break;
	}
	while (check->cost_a > 0)
	{
		if (check->index > len_a / 2)
			ft_rra(sa);
		else
			ft_ra(sa);
		check->cost_a--;
		count++;
	}
	printf("a_moves made: %d\n", count);
}

void	node_to_right_place(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*check;
	int		next;
	int		ref;
	int		len;
	int		count;

	count = 0;
	check = (*stack_a);
	ref = check->content;
	len = ft_lstsize_int(*stack_b);
	next = find_next_smaller(*stack_b, ref);
	//printf("index of the next value is %d\n", next);
	while (check->cost_b > 0)
	{
		if (next > len / 2 + (len % 2))
			ft_rrb(stack_b);
		else
			ft_rb(stack_b);
		check->cost_b--;
		count++;
	}
	printf("b_moves made: %d\n", count);
}

// int	find_closest_value(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_stack	*check;
// 	int		recent;
// 	int		return_index;

// 	check = stack_a;
// 	return_index = 1;
// 	recent = 0;
// 	while (check)
// 	{
// 		if (check->target > stack_b->target && recent < stack_b->target)
// 			return_index = check->index;
// 		check = check->next;
// 	}
// 	printf("return index is %d\n", return_index);
// 	return (return_index);
// }

void	rotate_max_up(t_stack **stack_b)
{
	t_stack	*check;
	int		len;

	if (check_content_order(*stack_b))
		return ;
	check = *stack_b;
	len = ft_lstsize_int(*stack_b);
	assign_index(*stack_b);
	while (check->next != NULL && check->target > check->next->target)
		check = check->next;
	if (check->next == NULL)
		return ;
	else
	{
		printf("target index: %d\n", check->index);
		while (check->index != 0 && check->index != len)
		{
			if (check->index > len / 2)
			{
				ft_rrb(stack_b);
				check->index++;
			}
			else
			{
				ft_rb(stack_b);
				check->index--;
			}
		}
	}
}

void	final_rotate(t_stack **stack_a)
{
	t_stack	*check;
	int		len;

	print_stack(*stack_a);
	check = *stack_a;
	len = ft_lstsize_int(*stack_a);
	assign_index(*stack_a);
	while (check->target != 1)
		check = check->next;
	while ((*stack_a)->target != 1)
	{
		if (check->index > len / 2)
			ft_rra(stack_a);
		else
			ft_ra(stack_a);
		print_stack(*stack_a);
	}
}

void	final_push(t_stack **stack_a, t_stack **stack_b)
{
	int	target_index;
	int	len_a;
	int	len_b;
	int	max;

	len_a = ft_lstsize_int(*stack_a);
	len_b = ft_lstsize_int(*stack_b);
	max = len_a + len_b;
	print_stack(*stack_b);
	print_stack(*stack_a);
	while (*stack_b)
	{
		target_index = 0;
		if (((*stack_a)->target == (*stack_b)->target + 1) || (*stack_b)->target == max)
		{
			ft_pa(stack_b, stack_a);
			len_a++;
			print_stack(*stack_b);
			print_stack(*stack_a);
		}
		else
		{
			assign_index(*stack_a);
			target_index = find_next_bigger(*stack_a, (*stack_b)->content);
			printf("the target index is %d\n", target_index);
			printf("len of stack a is %d\n", len_a);
			printf("len of stack a divided by 2 is %d\n", len_a / 2);
			print_stack(*stack_a);
			while (target_index != 1 && target_index != len_a + 1)
			{
				if (target_index <= len_a / 2 + (len_a % 2))
				{
					ft_ra(stack_a);
					target_index--;
					print_stack(*stack_b);
					print_stack(*stack_a);
				}
				else
				{
					ft_rra(stack_a);
					target_index++;
					print_stack(*stack_b);
					print_stack(*stack_a);
				}
				printf("the current index is %d\n", target_index);
			}
			ft_pa(stack_b, stack_a);
			len_a++;
			print_stack(*stack_b);
			print_stack(*stack_a);
		}
	}
}

void	sort_larger_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		len;
	int		index;

	assign_target_value(*stack_a);
	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	//if (check_content_order(*stack_b))
	//	ft_sb(stack_b);
	print_stack(*stack_b);
	print_stack(*stack_a);
	len = ft_lstsize_int(*stack_a);
	while (len > 3)
	{
		assign_index(*stack_a);
		assign_cost(*stack_a, *stack_b);
		index = find_lowest_cost(*stack_a);
		rotate_a_b(stack_a, stack_b, index, len);
		node_to_right_place(stack_a, stack_b);
		ft_pb(stack_a, stack_b);
		print_stack(*stack_b);	
		print_stack(*stack_a);
		len--;
		if (check_content_order(*stack_a))
			break ;
	}
	sort_3(stack_a);
	//rotate_max_up(stack_b);
	final_push(stack_a, stack_b);
	if (!check_content_order(*stack_a))
		final_rotate(stack_a);
}

void	sort_chooser(t_stack **stack_a, t_stack **stack_b)
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
		sort_larger_stack(stack_a, stack_b);
}

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

void	print_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
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
	int 	argc = 2;
	char	*argv[] = {"1 3 2 5 4"};

	stack_a = NULL;
	stack_b = NULL;
	stack_a = fill_stack(argc, argv, &stack_a);
	if (!stack_a)
		free_and_exit(&stack_a, NULL, 1);
	if (check_content_order(stack_a))
		free_and_exit(&stack_a, NULL, 0);
	print_stack(stack_a);
	sort_chooser(&stack_a, &stack_b);
	print_stack(stack_a);
	free_and_exit(&stack_a, &stack_b, 0);
	return (1);
}
