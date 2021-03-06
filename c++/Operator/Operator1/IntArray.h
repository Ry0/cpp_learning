#ifndef INTARRAY_H
#define INTARRAY_H

class IntArray{
public:
  IntArray(int size);
  ~IntArray();

public:
  IntArray(const IntArray& other);

public:
  void operator = (const IntArray& other);

public:
  int Get(int i);
  void Set(int i, int value);

public:
  int Size() const;

private:
  void CheckIndex(int i);

private:
  int* m_array;
  int m_size;
};

#endif