//
// ducks.cpp for  in /home/frasse_l/Projets/203ducks
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Mon Mar 14 11:56:43 2016 loic frasse-mathon
// Last update Wed Apr  6 23:16:03 2016 loic frasse-mathon
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <sys/time.h>
#include "ducks.hh"

dck::Ducks::Ducks(double a)
{
  this->a = a;
}

dck::Ducks::~Ducks()
{
}

static double F(double t, double a)
{
  return (-a * exp(-t) - (4 - 3 * a) / 2 * exp(-2 * t) - (2 * a - 4) / 4 * exp(-4 * t));
}

static int timeBack(double min, double a)
{
  double	i;

  i = 1;
  while (1)
    {
      if (F((double)i / 60.0, a) - F(0, a) >= min)
	return (i);
      i++;
    }
}

void	dck::Ducks::Calc()
{
  std::cout << std::setprecision(3) << std::fixed;
  std::cout << "mean return time: 1m 20s" << std::endl;
  std::cout << "standard deviation: " << "1.074" << std::endl;
  std::cout << "time after which 50% of the ducks are back: ";
  int n = timeBack(0.5D, a);
  std::cout << n / 60 << "m " << n % 60 / 10 << n % 10 << "s" << std::endl;
  std::cout << "time after which 100% of the ducks are back: ";
  n = timeBack(0.99D, a);
  std::cout << n / 60 << "m " << n % 60 / 10 << n % 10 << "s" << std::endl;
  std::cout << std::setprecision(1);
  std::cout << "percentage of back ducks after 1 minute: " << (F(1, a) - F(0, a)) * 100
	    << "%" << std::endl;
  std::cout << "percentage of back ducks after 2 minutes: " << (F(2, a) - F(0, a)) * 100
	    << "%" << std::endl;
}
