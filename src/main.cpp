//
// main.cpp for  in /home/frasse_l/Projets/202unsold
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Wed Mar  2 12:25:40 2016 loic frasse-mathon
// Last update Wed Apr  6 20:29:08 2016 loic frasse-mathon
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include "ducks.hh"

static bool	is_number(char *str)
{
  int		i;
  int		v;

  i = 0;
  v = 0;
  while (str[i])
    {
      if (i == 0 && (str[i] == '-' || str[i] == '+'))
	i++;
      else if (str[i] == '.' && v == 0)
	{
	  v++;
	  i++;
	}
      else if ((str[i] < '0' || str[i] > '9'))
	return (false);
      else
	i++;
    }
  return (true);
}

static void	usage(char **av)
{
  std::cout << "USAGE" << std::endl;
  std::cout << "\t\t" << av[0] << " a" << std::endl;
  std::cout << "DESCRIPTION" << std::endl;
  std::cout << "\t\ta\tconstant" << std::endl;
  exit(0);
}

static void	error_args()
{
  std::cerr << "Error: Bad arguments, please run with -h for help" << std::endl;
  exit(84);
}

static void	unsold(double args)
{
  if (args <= 0 || args > 2.5)
    error_args();

  dck::Ducks	ducks = args;
  ducks.Calc();
}

int		main(int ac, char **av)
{
  int		i;
  double	args;
  
  i = 1;
  while (i < ac)
    {
      if (std::string("-h") == av[1])
	usage(av);
      if (i > 1 || !is_number(av[i]))
	error_args();
      errno = 0;
      args = atof(av[i]);
      if (errno == ERANGE)
        error_args();
      i++;
    }
  if (i != 2)
    error_args();
  unsold(args);
  return (0);
}
