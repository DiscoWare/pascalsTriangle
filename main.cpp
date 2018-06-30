#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string format(int i)
{
    ostringstream result;
    cout.width(7); result << left << to_string(i);
	return result.str();
}

void pascal(int rows)
{
    vector<int> current = {0, 1, 0};
    vector<int> temp;
    int spaces = rows;
    for (int e = 0; e < rows; ++e)
    {
        for (int i = 0; i < spaces - 1; ++i)
        {
            cout << "    ";
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
        for (auto a : temp)
        {
            current.push_back(a);
        }
        temp.clear();
    }
}
 
int main()
{
	int rows;
	cin >> rows;
	while (!cin)
	{
		cout << "Not a valid entry\n";
		cin.clear();
		cin.ignore();
	}
    pascal(rows);
    return 0;
}
