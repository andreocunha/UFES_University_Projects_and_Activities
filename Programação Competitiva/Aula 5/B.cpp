#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    while (1)
    {
        string code = "";
        getline(cin, code);

        if(code == "#"){ break; }

        bool status = next_permutation(code.begin(), code.end());

        if (status == false){
            cout << "No Successor" << endl;
        }
        else{
            cout << code << endl;
        }
    }
	return 0;
}
