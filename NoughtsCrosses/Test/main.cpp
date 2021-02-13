#include <iostream>
#include <vector>

using namespace std;

int main()
{
        cout << "\nHere is the board: " << endl; 
        cout << endl;
        for ( int i {1}; i <= 9; ++i)
        {
            if (i  % 3 == 0 && i != 9)
                {
                    cout << i << endl;
                    cout << "----------" << endl;
                }
            else if (i ==9)
                cout << i << endl;
            else
            {
                cout << i << " | ";
            }
        }
        
        cout << endl;
    return 0;
}