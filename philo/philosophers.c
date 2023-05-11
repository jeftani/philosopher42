
#include "includes/philosophers.h"

int is_digit(char argv)
{
	if(argv >= '0' && argv <= '9')
		return(1);
	return(0);
}
int check_negativity( int argc , char **argv)
{
	int i = 1;
	while(i <= (argc - 1))
	{
		if(ft_atoi(argv[i]) > 0)
			i++;
		else
		{
			printf("error negative\n");
			return(0);
		}
	}
	return(1);
}

int ft_parsing(int argc,char *argv[])
{

	int i;
	int j;

	i = 1;
	j = 0;

	while(i <= (argc - 1))
	{
		j = 0;
		while(argv[i][j])
		{
			if ((j == 0 && (argv[i][j] == '+' || is_digit(argv[i][j]))) || (j > 0 && (is_digit(argv[i][j]) || argv[i][j] == ' ')))
			{
				j++;
			}
			else
			{
				printf("error is not digit\n");
				return(0);
			}
		}
			i++;
	}
	if(!(check_negativity(argc , argv)))
		return(0);
	return(1);
}

int		main(int argc, char *argv[])
{
	t_data *data;

	data = malloc (sizeof(t_data));
	data->eat_count_max = 0;
	data->max_ate = 0;
	if (argc < 5 || argc > 6)
	{
		printf("error\n");
		return(1);
	}
	if((!ft_parsing(argc, argv)))
		return(0);
	if(!ft_init(data,argv,argc))
		return(0);
	if(ft_create_thread(data))
		return(0);
}