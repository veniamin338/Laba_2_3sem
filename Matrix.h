#include "Vectorr.h"

template <class M>
class Matrixx : public Vectorr<Vectorr<M> >
{
public:
  Matrixx(int stl = 1);
  Matrixx(int stl, int str);
  //Matrixx(const Matrixx& mt); // копирование
  //Matrixx(const Vectorr<Vectorr<T>>& mt); // преобразование типа
  //Matrixx& operator==(const Matrixx& mt); // сравнение
  Matrixx& operator= (const Matrixx& mt); // присваивание
  //Matrixx operator+ (const Matrixx& mt); // сложение
  //Matrixx operator- (const Matrixx& mt); // вычитание
  //Matrixx operator* (const Matrixx& mt); // умножение
  M& operator[] (const int index);
  template <class T1>
  friend ostream& operator << (ostream& ostr, const Matrixx& mt);
  template <class T1>
  friend istream& operator >> (istream& istr, Vectorr<T1>& mt);
};


template <class T1>
ostream& operator << (ostream& ostr, const Matrixx <class M> & mt) {
for (int i = 0; i < mt.len; i++) {
  ostr << mt.x[i];
  }
 return ostr;
}

template<class M>
Matrixx<M>::Matrixx(int stl) : Vectorr<Vectorr<M>>(stl)
{
}

template<class M>
Matrixx<M>::Matrixx(int stl, int str) : Vectorr<Vectorr<M>*>(stl)
{
 
  for (int i = 0; i < stl; i++) {
    this->x[i] = new Vectorr<M> [str];
  }
}

template<class M>
Matrixx<M>& Matrixx<M>::operator=(const Matrixx& mt)
{
  for (int i = 0; i < mt.len; i++) {
    this->x[i] = mt.x[i];
  }
  this->len = mt.len;
}

template<class M>
M& Matrixx<M>::operator[](const int index)
{
  if (index > 0 && index <this->len) {
    return this->x[index];
  }
  return this->x[0];
}

