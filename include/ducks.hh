//
// ducks.hh for  in /home/frasse_l/Projets/203ducks
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Mon Mar 14 11:45:31 2016 loic frasse-mathon
// Last update Wed Apr  6 20:29:34 2016 loic frasse-mathon
//

#ifndef DUCKS_HH_
# define DUCKS_HH_

namespace	dck
{
  class		Ducks
  {
  public:
    Ducks(double);
    ~Ducks();
    void	Calc();
  private:
    double	a;
  };
}

#endif /* !DUCKS_HH_ */
