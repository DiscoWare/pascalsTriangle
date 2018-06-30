#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string format(unsigned int i)
{
    ostringstream result;
    cout.width(10); result << right << to_string(i);
	return result.str();
}

void pascal(unsigned int rows)
{
    vector<unsigned int> current = {0, 1, 0};
    vector<unsigned int> temp;
    unsigned int spaces = rows;
    for (int e = 0; e < rows; ++e)
    {
        for (int i = 0; i < spaces - 1; ++i)
        {
            cout << "     ";
        }
        --spaces;
        
        for (int i = 1; i < current.size() - 1; ++i)
        {
            cout << format(current[i]);
        }
        cout << endl;
        
        temp.push_back(0);
        for (int i = 1; i < current.size(); ++i)
        {
            temp.push_back(current[i - 1] + current [i]);
        }
        temp.push_back(0);
        current.clear();
        current = temp;
        temp.clear();
    }
}
 
int main()
{
	int rows;
	cout << "How many rows of Pascal's triangle would you like?\n";
	cin >> rows;
	while (!cin)
	{
		cout << "Not a valid entry, please enter a number\n";
		cin.clear();
		cin.ignore();
	}
    pascal(rows);
    return 0;
}
