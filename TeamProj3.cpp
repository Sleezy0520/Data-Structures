#include <iostream>

using namespace std;

class personType{
    public:
    
    void print() const;
    void setName(string first, string last);
    string getFirstName() const;
    string getLastName() const;
    personType(string first = "", string last = "");

    private: 
    string firstName;
    string lastName;
};

class doctorType : public personType{
    public:
    void setSpecialty(string s);
    string getSpecialty() const;
    doctorType(string first = "", string last = "", string s = "");

    private:
    string specialty;
};

int main(){
//main function

}

void personType::print() const{
    cout << firstName << " " << lastName;
}

void personType::setName(string first, string last){
    firstName = first;
    lastName = last;
}

string personType ::getFirstName() const{
    return firstName;
}

string personType::getLastName() const{
    return lastName;
}

personType::personType(string first, string last){
    firstName = first;
    lastName = last;
}

void doctorType::setSpecialty(string s){
    specialty = s;
}

string doctorType::getSpecialty() const{
    return specialty;
}

doctorType::doctorType(string first, string last, string s) : personType(first, last) {
    specialty = s;
}