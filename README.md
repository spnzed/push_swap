<h1 align=center>
	<b>push_swap</b>
	 
  <i>42cursus' project #7</i>

<i>UNDER CONSTRUCTION ⚠️</i>

</h2>
Algorithm project where we must sort a given list of random numbers with a limited set of instructions, using the lowest possible number of actions.
  <h1 align=center>

![push_swape](https://github.com/spnzed/push_swap/assets/95354392/3d82b7ca-544c-457f-b7ff-07e7da51f7d9)

<h3 align=center>
The Approach
</h3>

![IMG_2846](https://github.com/spnzed/push_swap/assets/95354392/00d93342-7988-48f0-acef-651ed72cf489)

![IMG_2847](https://github.com/spnzed/push_swap/assets/95354392/d04a84e0-cdd6-4e7b-bb12-e3a32522d558)

---
<h3 align=center>
To-Do
</h3>

✅ 1 Parsear input como argumento que entra como diferentes ints
 2 Programar acciones de push_swap... SwapA SwapB
 3 Sort de 3 numeros (Super recomendable que cojas papel  y boli y te apuntes todos los casos diferentes del sort de 3 y lo resuelvas tu para luego aplicarlo. Intenta siempre priorizar que el numero maximo quede abajo.)
 4 Aplicar algoritmo
	- 4.1 Pasar las cosas a stack_B
	- 4.2 Pasar las cosas a stack_A
	- 4.3 "Merge actions" o sea, cuando haya [ra rb] convertirlo en [rr] (Super recomendable utilizar un push_swap visualizer para ver que esta haciendo tu codigo exactamente y encontrar errores)

---

<h3 align=center>
Mandatory
</h3>

<b>XXXXX</b>
> <i>XXXXXXXXXXXXXXXXXXXX</i>

<h3 align=center>


<h2>
The Project
</h2>

𝟏. 𝐏𝐀𝐑𝐒𝐈𝐍𝐆 :
Join inputs (Check zeros, digits) -> Convert to t_list (atol) -> Check_duplicates

- 𝑺𝒕𝒂𝒓𝒕
    - t_list          *parsing_i(char **str);

- 𝑱𝒐𝒊𝒏 𝒊𝒏𝒑𝒖𝒕𝒔(Check zeros, digits)

  - static  char    *join_input(char **input);
  - char            *check_zeros(char *input);
  - int             check_digits(char *str);
- 𝑪𝒐𝒏𝒗𝒆𝒓𝒕 𝒕𝒐 𝒕_𝒍𝒊𝒔𝒕 (atol)

  - static  t_list  *convert_to_tlist(char **input);
  - int             ft_atol(const char *str);
  - static int		check_limits(long j);
- 𝑪𝒉𝒆𝒄𝒌_𝒅𝒖𝒑𝒍𝒊𝒄𝒂𝒕𝒆𝒔

  - int             check_duplicates(t_list *stack);

stack_a == parsing_i / stack_b == NULL
size == lst_size(stack_a)

if 1<size<=3 -> sort_3 // else -> init_sort

𝟐. a. 𝐒𝐎𝐑𝐓_𝟑 :

- 𝑺𝒕𝒂𝒓𝒕
void    		sort_3(t_stack *stk);
int 			finish_check(t_stack *stk);

- 𝑰𝑭 𝒍𝒔𝒕_𝒔𝒊𝒛𝒆(𝒔𝒕𝒂𝒄𝒌_𝒂) < 𝟯
    - 𝗦𝗪𝗔𝗣
    - static t_list   *swap(t_list *stack);
- 𝗲𝗹𝘀𝗲 𝙍𝙍𝘼, 𝙍𝘼, 𝙎𝘼
    - CASE 5 -> void    		reverse_rotate_a(t_stack *stk, int print);
    - CASE 3 -> void    		rotate_a(t_stack *stk, int print);
    - CASE 1 -> void    		swap_a(t_stack *stk, int print);

![image](https://github.com/spnzed/push_swap/assets/95354392/a94c040c-42d0-400d-8a13-61732b9cf181)

𝟐. 𝐛. 𝐀𝐋𝐆𝐎𝐑𝐈𝐓𝐇𝐌 :

- 𝑺𝒕𝒂𝒓𝒕
void    		init_sort(t_stack *stk);
void            push_b(t_stack *stk, int print)
static void 	move(t_stack *stk);

- 𝑲𝒏𝒐𝒘 𝒕𝒉𝒆 𝒍𝒊𝒎𝒊𝒕𝒔
  - 𝑳𝒊𝒎𝒊𝒕𝒔
    - int 			*stk_limits(t_list *lst);
- 𝘾𝙖𝙡𝙘𝙪𝙡𝙖𝙩𝙚 𝙢𝙤𝙫𝙚𝙨
    - t_list  		*calculate_moves(t_stack *stk, int *limits, int id);
        - static t_list   *get_temp(t_stack *stk, int *aux, int *limits, int id);
            - void    		*calc_rot(t_list *lst, int *value, int stack, t_list **action);
                - static void		fill_list(t_list **lst, int amount, int *value);
                - static int 		*find_p(int n, t_list *lst, int phase);
        - static t_list 	*get_cheapest(t_list *tmp_act, t_list *cheapest_act, int stack);
                  - void    		check_merge(t_list **lst);
                  - static t_list   *merge_actions(t_actions **acts);
                  - static void 	add_actions(t_list **lst, int action, int times);
                  - void    		add_push(t_list **action, int stack);
- 𝘿𝙤 𝙩𝙝𝙚 𝙖𝙘𝙩𝙞𝙤𝙣
    - void    		parse_move(t_stack *stk, t_list *actions);
- 𝙁𝙞𝙣𝙖𝙡 𝙧𝙤𝙩𝙖𝙩𝙞𝙤𝙣
    - static void 	rotate_finish(t_stack *stk);

void    		push_swap(char **str);
static void 	fill_list(t_list **lst, int amount, int *value);
