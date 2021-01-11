#include "../printf/include/printf.h"

int	ft_printf(const char *s, ...);
int	is_valid(char c);
t_param param_default(void);
void print_struct(t_param);
void ft_putnbr(int nb);
int	clean_int(int nb);




int	n = 42;
char c = 'A';
char str[100] = "eric";
unsigned int u_n = -1;


int main()
{	

	//printf("%08d\n",1234567);
	//printf("%-8d\n",1234567);
	//printf("%-0-0-000-i\n",1234567);

	// == TEST: precision default
	
	//√ printf("%.4d\n",1234);
	//√ printf("%.5d\n",1234);
	//printf("%1.5d\n",1234);

	ft_printf("%d\n",4);
	
	//printf("%6.5d\n",1234);
	//printf("%-6.5d\n",1234);
	
	//ft_printf("%.10d\n",1234);
	



	// == TEST: if precision is neg or only '.' ==
	//printf("%-10.3d\n",42);

	// == TEST: if precision with '-'
	//printf("%-4.3d",1);
	//printf("%4.3d",1);



	return (0);
}
