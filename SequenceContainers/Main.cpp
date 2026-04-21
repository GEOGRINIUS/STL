#include<iostream>
#include<array>
#include<vector>
#include<deque>
using std::cin;
using std::cout;
using std::endl;

#define tab			"\t"
#define delimiter	"\n-----------------------------------\n"

template<typename T> void vector_properties(const std::vector<T>& vec)
{
	cout << "Size:	  " << vec.size() << endl;			//фактитеческий размер
	cout << "Capacity:" << vec.capacity() << endl;	
	cout << "MaxSize: " << vec.max_size() << endl;		//максимальный-возможный размер.
}

//#define STL_ARRAY
//#define STL_VECTOR
#define STL_DEQUE

void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_ARRAY
	std::array<int, 5> arr = { 3, 5, 8, 13, 21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	std::vector<int> i_vec = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
	vector_properties(i_vec);
	i_vec.push_back(55);
	i_vec.push_back(89);
	vector_properties(i_vec);
	//i_vec.reserve(25);	//резервирует дополнительную память.
	i_vec.shrink_to_fit();	//Приравнивает вместительность вектора до его фактического размера
	//i_vec.resize(15);
	vector_properties(i_vec);

	for (int i = 0; i < i_vec.size(); i++)
	{
		//cout << i_vec[i] << tab;
		cout << i_vec.at(i) << tab;
	}
	cout << endl;
	cout << "Front:\t" << i_vec.front() << endl;
	cout << "Back:\t" << i_vec.back() << endl;
	i_vec.data();

	//std::vector<double> d_vec;
	//vector_properties(d_vec);

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	if(index <= i_vec.size())
		i_vec.insert(i_vec.begin() + index, value);

	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	cout << "Введите значение удаляемого элемента: "; cin >> value;
	if(index < i_vec.size())
		i_vec.erase(i_vec.end() - index);

	for (std::vector<int>::iterator it = i_vec.begin(); it != i_vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

#endif // STL_VECTOR

#ifdef STL_DEQUE

	std::deque<int> i_deque = { 3, 5, 8, 13, 21 };
	for (int i = 0; i < i_deque.size(); i++)
	{
		cout << i_deque[i] << tab;
	}
	cout << endl;
	i_deque.push_front(1);
	i_deque.push_front(1);
	i_deque.push_front(0);
	i_deque.push_back(34);
	i_deque.push_back(55);
	i_deque.push_back(89);
	for (std::deque<int>::iterator it = i_deque.begin(); it != i_deque.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;

#endif // STL_DEQUE


}