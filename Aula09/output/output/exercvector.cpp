#include <iostream>
#include <vector>
#include <string>

using namespace std;

    int main(void)
{
    vector<string> students;
    string word;

    getline(cin, word);
    students.push_back(word);

    for (auto it = students.begin(); it != students.end(); it++)
        cout << *it << endl;

    return 0;
}
