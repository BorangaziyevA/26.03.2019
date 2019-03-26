//люйпняш//////////////////люйпняш/////////////////////люйпняш//////////////////////////люйпняш//////////////////люйпняш/////////////////////////////люйпняш

//#include<iostream>
//#include<Windows.h>
//#include<iomanip>
//#include<locale.h>
//
//#define begin {
//#define end }
//#define program int main()
//#define screen_save system("pause");
//#define exit return 0;
//#define print cout <<
//#define enter <<endl;
//#define read cin >>
//#define std using namespace std;
//#define integer int
//#define maximum(a,b) (a>b?a:b)
//#define chetnechet(x) (a%2==0? 1:0)
//
//std;//using namespace std;
//
//program begin
//
//const integer N = 100;
//
//integer a, b;
//
//read a;
//
//read b;
//
//print maximum(a, b) enter
//
//print chetnechet(a) enter
//
//screen_save
//
//end



//ахрнбше онкъ/////////////////////////ахрнбше онкъ////////////////////////ахрнбше онкъ/////////////////////////////////////////ахрнбше онкъ





//#include<iostream>
//#include<Windows.h>
//#include<iomanip>
//#include<locale.h>
//#include<fstream>
//
//using namespace std;
//
//int buf_size = 0;
//int cur_size = 0;
//
//struct flat
//{
//	int flat_on: 9, rooms: 4, area: 9;
//
//	void print()
//	{
//		cout << flat_on << " " << rooms << " " << area << endl;
//	}
//
//};
//
//struct House
//{
//
//	int house_n;
//
//	int HMflats;
//
//	int flats[];
//
//};
//
//void add(flat*&fs, flat el)
//{
//	if (buf_size == 0)
//	{
//		buf_size = 4;
//		fs = new flat[buf_size];
//	}
//	else
//	{
//		if (cur_size == buf_size)
//		{
//			buf_size *= 2;
//			flat *tmp = new flat[buf_size];
//			for (size_t i = 0; i < cur_size; i++)
//			{
//				tmp[i] = fs[i];
//			}
//			delete []fs;
//			fs = tmp;
//		}
//
//	}
//	fs[cur_size++] = el;
//
//}
//
//int main()
//{
//	ifstream in_file("Flats.txt");
//	flat el;
//	int tmp;
//
//	flat* fs = 0;
//
//	while (!in_file.eof())
//	{
//		in_file >> tmp;
//		el.flat_on = tmp;
//		in_file >> tmp;
//		el.rooms = tmp;
//		in_file >> tmp;
//		el.area = tmp;
//		add(fs, el);
//	}
//
//	for (size_t i = 0; i < cur_size; i++)
//	{
//		fs[i].print();
//	}
//
//
//	system("pause");






#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<locale.h>
#include<fstream>

using namespace std;

int buf_size = 0;
int cur_size = 0;

struct flat
{
	int flat_on: 9, rooms: 4, area: 9;

	void print()
	{
		cout << flat_on << " " << rooms << " " << area << endl;
	}

};

struct house
{

	char house_n[30];
	int flat_amount:9;
	flat *fs = NULL;

	void print()
	{
		cout << house_n << endl;
		if (fs!=NULL)
		{
			for (size_t i = 0; i < flat_amount; i++)
			{
				fs[i].print();

			}

		}
	}

};

template <typename T>
void add(T*&fs, T el)
{
	if (buf_size == 0)
	{
		buf_size = 4;
		fs = new T[buf_size];
	}
	else
	{
		if (cur_size == buf_size)
		{
			buf_size *= 2;
			T *tmp = new T[buf_size];
			for (size_t i = 0; i < cur_size; i++)
			{
				tmp[i] = fs[i];
			}
			delete []fs;
			fs = tmp;
		}

	}
	fs[cur_size++] = el;

}

int main()
{
	ifstream in_file("Flats.txt");
	house home_el;
	int tmp;

	house* hs = 0;

	while (!in_file.eof())
	{
		in_file >> home_el.house_n >> tmp;
		home_el.flat_amount = tmp;
		home_el.fs = new flat[tmp];

		for (size_t i = 0; i < home_el.flat_amount; i++)
		{
			in_file >> tmp;
			home_el.fs[i].flat_on = tmp;

			in_file >> tmp;
			home_el.fs[i].rooms = tmp;

			in_file >> tmp;
			home_el.fs[i].area = tmp;
		}
		add(hs, home_el);
	}

	for (size_t i = 0; i < cur_size; i++)
	{
		hs[i].print();
	}

	for (size_t i = 0; i < cur_size; i++)
	{
		delete[] hs[i].fs;

	}
	delete[] hs;

	system("pause");
}