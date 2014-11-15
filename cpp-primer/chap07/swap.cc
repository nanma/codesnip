#include  <iostream>
using std::cout;
using std::endl;
void swap(int &, int &);
int main()
{
	
	int i =10;
	int j = 20;
	cout << "Before swap():\ti: "
		 << i << "\tj: " << j << endl;
	//int &v1 = i, &v2 = j;
	//swap(v1, v2);
	swap(i, j);
	cout << "After swap():\ti: "
		 << i << "\tj: " << j << endl;
	return 0;
}

void swap(int &v1, int &v2)
{
	int tmp = v2;
	v2 = v1;
	v1 = tmp;
}
