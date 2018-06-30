#include <iostream>
#include <vector>
#include <string>
using namespace std;

string format(int i)
{
    if (i >= 1000)
    {
        return " " + to_string(i) + " ";
    }
    else if (i >= 100)
    {
        return "  " + to_string(i) + " ";
    }
    else if (i >= 10)
    {
        return "  " + to_string(i) + "  ";
    }
    else 
        return "   " + to_string(i) + "  ";
}

void pascal(int rows)
{
    vector<int> current = {0, 1, 0};
    vector<int> temp;
    int spaces = rows - 1;
    for (int e = 0; e < rows; ++e)
    {
        for (int i = 0; i < spaces; ++i)
        {
            cout << "   ";
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
    pascal(16);
    return 0;
}
