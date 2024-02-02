#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
template<class T>
class Array
{
public:
	Array(int capacity)
	{
		cout << "gouzao" << endl;
		this->capacity = capacity;
		p = new T[this->capacity];
		this->size = 0;
	}
	Array(const Array& arr)
	{
		cout << "kaobeigz" << endl;
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->p = new T[arr.capacity];
		for (int i = 0; i < arr.size; i++)
		{
			this->p[i] = arr.p[i];
		}
	}
	Array& operator=(const Array& arr)
	{
		//比拷贝构造函数多一个步骤,判断堆区是否有数据,有的话需要先释放
		if (p != NULL)
		{
			delete[]p;
			p = NULL;
			this->capacity = 0;
			this->size = 0;
		}
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->p = new T[arr.capacity];
		for (int i = 0; i < arr.size; i++)
		{
			this->p[i] = arr.p[i];
		}
		return *this;
	}
	void deleteEnd()
	{
		if (this->size == 0)
			return;
		this->size--;

	}
	void enhanceEnd(const T& val)
	{
		if (this->size == this->capacity)
			return;
		this->p[this->size++] = val;

	}
	int getCapacity()
	{
		return this->capacity;
	}
	T& operator[](int index)
	{
		return this->p[index];
	}//如果返回值很有可能以左值的情况出现的话,要用T&作为返回值类型
	//
	int getSize()
	{
		return  this->size;
	}
	~Array()
	{
		cout << "xigou" << endl;
		if (p != NULL)
		{
			delete[] p;
			p = NULL;
			this->capacity = 0;
			this->size = 0;
		}
	}
private:
	int capacity;
	int size;
	T* p;
};
void test01()
{

}
int main()
{
	Array<int> arr1(100) ;
	Array<int> arr2(arr1);
	Array<int> arr3(5);
	arr3 = arr1;
	arr1.enhanceEnd(10);
	arr1.enhanceEnd(20);
	cout<<arr1[1]<<endl;
	arr1.deleteEnd();
	cout<<arr1[0]<<endl;
	return 0;
}