# 42'S LIBASM SUBJECT

<h2>COMMON INSTRUCTIONS</h2>
<br>

- Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and you will receive a 0 during the evaluation.
- Your <samp>Makefile</samp> must at least contain the rules <code>$(NAME)</code>, <code>all</code>, <code>clean</code>, <code>fclean</code> and <code>re</code>. And must recompile/relink only necessary files.
- To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file <samp>_bonus.{c/h}</samp>. Mandatory and bonus part evaluation is done separately.
- We encourage you to create test programs for your project even though this work won’t have to be submitted and won’t be graded. It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git reposi- tory will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop.
- You must write 64 bits ASM. Beware of the "calling convention".
- You can’t do inline ASM, you must do <samp>’.s’</samp> files.
- You must compile your assembly code with nasm.
- You must use the Intel syntax, not the AT&T.

<br>
<h2>MANDATORY PART</h2>
<br>

- The library must be called <samp>libasm.a</samp>.
- You must submit a main that will test your functions and that will compile with your library to show that it’s functional.
- You must rewrite the following functions in asm:
  - <samp>ft_strlen</samp> (man 3 strlen)
  - <samp>ft_strcpy</samp> (man 3 strcpy)
  - <samp>ft_strcmp</samp> (man 3 strcmp)
  - <samp>ft_write</samp> (man 2 write)
  - <samp>ft_read</samp> (man 2 read)
  - <samp>ft_strdup</samp> (man 3 strdup, you can call to malloc)
- You must check for errors during syscalls and properly set them when needed
- Your code must set the variable errno properly.
- For that, you are allowed to call the <samp>extern ___error</samp>.

<br>
<h2>BONUS PART</h2>
<br>

You can rewrite these functions in asm. The linked list function will use the following structure:
<br>
<pre>
<code>
typedef struct    s_list
{
  void            *data;
  struct s_list   *next;

}                 t_list;
</code>
</pre>

- <samp>ft_atoi_base</samp> (like the one in the piscine)
- <samp>ft_list_push_front</samp> (like the one in the piscine)
- <samp>ft_list_size</samp> (like the one in the piscine)
- <samp>ft_list_sort</samp> (like the one in the piscine)
- <samp>ft_list_remove_if</samp> (like the one in the piscine)
