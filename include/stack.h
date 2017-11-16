// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удаления)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыделяться память

using namespace std;
template <typename T>
class Stack{
private:
	T *StackPtr;
	int size;
	int Top;
public:
	Stack(int s = 10);
	~Stack();
	T ShowTop();
	void Push( const T & );
	T Pop();
	bool IsEmpty();
	bool IsFull();
	int GetSize() const;
	int GetCurrentSize();
	void ClearStack();
};

template <typename T>
Stack<T>::Stack(int maxSize) :
    size(maxSize) 
{
    StackPtr = new T[size]; 
    Top = 0; 
}

template <typename T>
Stack<T>::~Stack()
{
    delete [] StackPtr; 
}

template <typename T>
void Stack<T>::Push(const T &val)
{ 
    if (Top < size){
		StackPtr[Top++] = val; 
	}
	else { throw "Error: Stack is Full"; }
}

template <typename T>
T Stack<T>::Pop()
{
    if(Top > 0){
		StackPtr[--Top];
	} 
	else { throw "Error: Stack is Empty"; } 
}
 
template <typename T>
bool Stack<T>::IsEmpty()
{
	if (Top = 0) { return 1; };
	else { return 0; } 
}

template <typename T>
bool Stack<T>::IsFull()
{
	if (Top = size) { return 1; };
	else { return 0; }
}

template <typename T>
T Stack<T>::ShowTop()
{
	return StackPtr[Top];
}

template <typename T>
int Stack<T>::GetSize() const
{
	return size;
}

template <typename T>
int Stack<T>::GetCurrentSize() 
{
	return Top;
}

template <typename T>
void Stack<T>::ClearStack()
{
	if (!IsEmpty){
	for (int i = Top; i > 0; i--){
		Pop();
	}
	}
}