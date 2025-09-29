#include <iostream>

using namespace std;

class personType
{
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

class doctorType : public personType
{
public:
    void setSpecialty(string s);
    string getSpecialty() const;
    doctorType(string first = "", string last = "", string s = "");

private:
    string specialty;
};

class billType
{
private:
    int patientID;
    double pharmacyCharges;
    double doctorFee;
    double roomCharges;

public:
    billType() : patientID(0), pharmacyCharges(0.0), doctorFee(0.0), roomCharges(0.0) {}

    billType(int id, double pharmacy, double doctor, double room)
        : patientID(id), pharmacyCharges(pharmacy), doctorFee(doctor), roomCharges(room) {}

    void setPatientID(int id)
    {
        patientID = id;
    }

    void setPharmacyCharges(double pharmacy)
    {
        pharmacyCharges = pharmacy;
    }

    void setDoctorFee(double doctor)
    {
        doctorFee = doctor;
    }

    void setRoomCharges(double room)
    {
        roomCharges = room;
    }

    int getPatientID() const
    {
        return patientID;
    }

    double getPharmacyCharges() const
    {
        return pharmacyCharges;
    }

    double getDoctorFee() const
    {
        return doctorFee;
    }

    double getRoomCharges() const
    {
        return roomCharges;
    }

    double calculateTotalCharges() const
    {
        return pharmacyCharges + doctorFee + roomCharges;
    }

    void displayBill() const
    {
        cout << "Patient ID: " << patientID << std::endl;
        cout << "Pharmacy Charges: $" << pharmacyCharges << std::endl;
        cout << "Doctor's Fee: $" << doctorFee << std::endl;
        cout << "Room Charges: $" << roomCharges << std::endl;
        cout << "Total Charges: $" << calculateTotalCharges() << std::endl;
    }
};

int main()
{
    // test personType
cout << "----- personType Test -----" << endl;
personType p1("Sahara", "Calloway");
cout << "Person: ";
p1.print();

p1.setName("Jane", "Doe");
cout << "\nUpdated person: ";
p1.print();
cout << endl;

// test doctorType
cout << "\n---- doctorType Test ----" << endl;
doctorType d1("Gregory", "House", "Pathologist");
cout << "Doctor: ";
d1.print();
cout << "\nSpecialty: " << d1.getSpecialty() << endl;

d1.setSpecialty("Neurologist");
cout << "Updated Specialty: " << d1.getSpecialty() << endl;

// test billType
cout << "---- \nbillType test ----" << endl;
billType b1(101, 150.75, 500.00, 1200.25);

cout << "Bill:" << endl;
b1.displayBill();
cout << endl;

// update charges
b1.setPharmacyCharges(200.50);
b1.setDoctorFee(600.00);
b1.setRoomCharges(1300.00);

cout << "Updated Bill:" << endl;
b1.displayBill();

return 0;
}

void personType::print() const
{
    cout << firstName << " " << lastName;
}

void personType::setName(string first, string last)
{
    firstName = first;
    lastName = last;
}

string personType ::getFirstName() const
{
    return firstName;
}

string personType::getLastName() const
{
    return lastName;
}

personType::personType(string first, string last)
{
    firstName = first;
    lastName = last;
}

void doctorType::setSpecialty(string s)
{
    specialty = s;
}

string doctorType::getSpecialty() const
{
    return specialty;
}

doctorType::doctorType(string first, string last, string s) : personType(first, last)
{
    specialty = s;
}
