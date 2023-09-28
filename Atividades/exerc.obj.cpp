#include <iostream>
#include <vector>

using namespace std;

class Ham
{
private:
    string name;
    string deadDate;

    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return name;
    }

    void setDate(string date)
    {
        this->deadDate = date;
    }

    string getDate()
    {
        return deadDate;
    }
};

class Mausoleum
{
private:
    string location;
    vector<Ham> hams;

    void setLocation(string location)
    {
        this->location = location;
    }

    string getLocation()
    {
        return location;
    }

    void setHamInMausoleum(Ham ham){
        this->hams.push_back(ham);
    }


};

int main(void)
{
    vector<Ham> hams;
    
    return 0;
}