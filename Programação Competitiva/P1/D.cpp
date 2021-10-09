#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int n, m;

    cin >> n >> m;

    string name, ip, comando;
    map<string, string> servers;

    for(int i = 0; i < n; i++) {
        cin >> name >> ip;
        servers[ip] = name;
    }

    string sub;
    for(int i = 0; i < m; i++) {
        cin >> comando >> ip;
        sub = ip.substr(0, ip.length()-1);
        cout << comando <<" " << ip << " #" << servers[sub] << endl;
    }
    return 0;
}