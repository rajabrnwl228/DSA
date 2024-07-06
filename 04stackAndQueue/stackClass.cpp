template <typename T>
class stackUsingArray
{
  T arr[];
  int nextIndex;
  int capacity;

public:
  stackUsingArray()
  {
    arr = new T[5];
    nextIndex = 0;
    capacity = 5;
  }
  int size()
  {
    return nextIndex;
  }
  bool isEmpty()
  {
    if (!nextIndex)
      return true;
    else
      return false;
  }
  void push(T data)
  {

    if (nextIndex < capacity)
      arr[nextIndex] = data;
    nextIndex++;
    else
    {
      T newarr = new T[2 * capacity];
      for (int i = 0; i < nextIndex; i++)
      {
        newarr[i] = arr[i];
      }
      capacity = 2 * capacity;
      delete[] arr;
      arr = newarr;
      arr[nextIndex] = data;
      nextIndex++;
    }
  }

  T pop()
  {
    int t = arr[nextIndex];
    nextIndex--;
    return t;
  }

  T top()
  {
    return arr[nextIndex];
  }

  ~stackUsingArray()
  {
    delete[] arr;
  }
};