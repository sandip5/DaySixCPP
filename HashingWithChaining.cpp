#include <iostream>
#include <list>

using namespace std;

struct Hash
{
	private:
	int SIZE_TABLE;
	list<int> *table;
	public:
	Hash(int size)
	{
		this->SIZE_TABLE = size;
		table = new list<int>[SIZE_TABLE];
	}

	void insertItem(int element)
	{
		int index = hashFunction(element);
		table[index].push_back(element);
	}

	void searchItem(int element)
	{
		int index = hashFunction(element);
		int j = 0;
		list <int> :: iterator k;
  		for (k = table[index].begin(); k != table[index].end(); k++)
		{	j++;
    			if (*k == element)
			{
				cout << "Position Of element: " << index << ":" << j << endl;
      				break;
			}
  		}
  		if (k != table[index].end())
		{
    			table[index].erase(k);
			cout << element << ": Deleted... After Searching" << endl;
		}
		else
		{
			cout << "Element Not Found.." << endl;
		}
	}

	int hashFunction(int element)
	{
        	return (element % SIZE_TABLE);
	}

	void displayHash()
	{
		for (int i = 0; i < SIZE_TABLE; i++)
		{
			cout << i;
    			for (auto x : table[i])
      				cout << " --> " << x;
    			cout << endl;
		}
	}
};

int main()
{
	Hash h(11);
	int select;

	do
	{
		cout << "Select Option: \n1. Insert Elements\n2. Search Element\n3. Display\n4. Exit " << endl;
        	cin >> select;

		switch(select)
		{
		case 1:
		{
			cout << "Enter Size Of Array: " << endl;
			int n;
			cin >> n;

			int a[n];
			cout << "Enter Array Elements: " << endl;
			for (int j = 0; j < n; ++j) {
        			cin >> a[j];
			}

  			for (int i = 0; i < n; i++)
			{
				h.insertItem(a[i]);
			}
			break;
		}
		case 2:
		{
			cout << "Enter Element Which You Want To Know Position: " << endl;
			int searchElement;
			cin >> searchElement;

			h.searchItem(searchElement);
			break;
		}
		case 3:
			h.displayHash();
			break;
		case 4:
			break;
		}
	}while(select != 4);
	return 0;
}
