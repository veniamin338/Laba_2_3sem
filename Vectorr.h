#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>

using namespace std;

template <class M>
class Vectorr
{
protected:
  int len;
  M* x;// указатель на первый элемент
public:
  //Vectorr<T>* vec;
  Vectorr(int str = 1);
  Vectorr(int str, M _v); // создание вектора  из str лементов каждый это _v 
  Vectorr(int rowsCount, M* _v);// копирование rowsC  элементов
 
  Vectorr(Vectorr<M>& _v); //конструктор копирования
  ~Vectorr();

  Vectorr<M> operator +(Vectorr<M>& _v);
  Vectorr<M> operator -(Vectorr<M>& _v);
  Vectorr<M> operator *(Vectorr<M>& _v);
  Vectorr<M> operator /(Vectorr<M>& _v);
  Vectorr<M>& operator =(Vectorr<M>& _v);
  M& operator[] (const int index);

  Vectorr<M>& operator ++();
  Vectorr<M>& operator --();
  Vectorr<M>& operator +=(Vectorr<M>& _v);
  Vectorr<M>& operator -=(Vectorr<M>& _v);

  template <class T1>
  friend ostream& operator<< (ostream& ostr, const Vectorr<T1>& A);
  template <class T1>
  friend istream& operator >> (istream& istr, Vectorr<T1>& A);

  int Length(); 
};

template <class T1>
ostream& operator<< (ostream& ostr, const Vectorr<T1>& A) {
  for (int i = 0; i < A.len; i++) {
    ostr << A.x[i] << endl;
  }
  return ostr;
}

template <class T1>
istream& operator >> (istream& istr, Vectorr<T1>& A) {
  for (int i = 0; i < A.len; i++) {
    istr >> A.x[i];
  }
  return istr;
}

#define MIN(a,b)(a>b?b:a)
#define MAX(a,b)(a>b?a:b)

template <class M>
Vectorr<M>::Vectorr(int str)
{
  len = str;
  x = new M[str];
  /*for (int i = 0; i < len; i++) {
    x[i] = 0;
  }*/
}
template <class M>
Vectorr<M>::Vectorr(int str, M _v)
{
  len = str;
  x = new M[len];
  for (int i = 0; i < str; i++) {
    x[i] = _v;
  }

}
template <class M>
Vectorr<M>::Vectorr(int rowsCount, M* _v)
{
  len = rowsCount;
  x = new M[len];
  for (int i = 0; i < len; i++)
    x[i] = _v[i];
}

template <class M>
Vectorr<M>::Vectorr(Vectorr<M>& _v)
{
  len = _v.len;
  x = new M[len];
  for (int i = 0; i < len; i = i + 1)
    x[i] = _v.x[i];
}
template <class M>
Vectorr<M>::~Vectorr()
{
  len = 0;
  if (x != 0)
    delete[] x;
  x = 0;
}
template <class M>
Vectorr<M> Vectorr<M>::operator +(Vectorr<M>& _v)
{
  Vectorr<M> res;
  res.len = MIN(len, _v.len);
  res.x = new M[res.len];
  for (int i = 0; i < res.len; i++)
  {
    res.x[i] = x[i] + _v.x[i];
  }
  return res;
}
template <class M>
Vectorr<M> Vectorr<M>::operator -(Vectorr<M>& _v)
{
  Vectorr<M> res;
  res.len = MIN(len, _v.len);
  res.x = new M[res.len];
  for (int i = 0; i < res.len; i++)
  {
    res.x[i] = x[i] - _v.x[i];
  }
  return res;
}
template <class M>
Vectorr<M> Vectorr<M>::operator *(Vectorr<M>& _v)
{
  Vectorr<M> res;
  res.len = MIN(len, _v.len);
  res.x = new M[res.len];
  for (int i = 0; i < res.len; i++)
  {
    res.x[i] = x[i] * _v.x[i];
  }
  return res;
}
template <class M>
Vectorr<M> Vectorr<M>::operator /(Vectorr<M>& _v)

{
  Vectorr<M> res;
  res.len = MIN(len, _v.len);
  res.x = new M[res.len];
  for (int i = 0; i < res.len; i++)
  {
    res.x[i] = x[i] / _v.x[i];
  }
  return res;
}
template <class M>
Vectorr<M>& Vectorr<M>::operator =(Vectorr<M>& _v)
{
  if (this == &_v)
    return *this;

  len = _v.len;
  x = new M[len];
  for (int i = 0; i < len; i++)
    x[i] = _v.x[i];
  return *this;
}
template <class M>
M& Vectorr<M>::operator[] (const int index)
{
  if ((index >= 0) && (index < len))
    return x[index];
  return x[0];
}

template <class M>
Vectorr<M>& Vectorr<M>::operator ++()
{
  for (int i = 0; i < len; i++)
    x[i]++;
  return *this;
}
template <class M>
Vectorr<M>& Vectorr<M>::operator --()
{
  for (int i = 0; i < len; i++)
    x[i]--;
  return *this;
}
template <class M>
Vectorr<M>& Vectorr<M>::operator +=(Vectorr<M>& _v)
{
  len = MIN(len, _v.len);
  for (int i = 0; i < len; i++)
  {
    x[i] += _v.x[i];
  }
  return *this;
}
template <class M>
Vectorr<M>& Vectorr<M>::operator -=(Vectorr<M>& _v)
{
  len = MIN(len, _v.len);
  for (int i = 0; i < len; i++)
  {
    x[i] -= _v.x[i];
  }
  return *this;
}
template <class M>
int Vectorr<M>::Length()
{
  return len;
}


#endif