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
        cout << "Patient ID: " << patientID << endl;
        cout << "Pharmacy Charges: $" << pharmacyCharges << endl;
        cout << "Doctor's Fee: $" << doctorFee << endl;
        cout << "Room Charges: $" << roomCharges << endl;
        cout << "Total Charges: $" << calculateTotalCharges() << endl;
    }
};

class dateType {
private:
    int month, day, year;

public:
    dateType(int m = 1, int d = 1, int y = 2000)
        : month(m), day(d), year(y) {}

    void setDate(int m, int d, int y) {
        month = m;
        day = d;
        year = y;
    }

    void printDate() const {
        cout << month << "/" << day << "/" << year;
    }
};

class patientType : public personType {
private:
    int patientID;
    int age;
    dateType dateofBirth;
    dateType admittedDate;
    dateType dischargeDate;
    doctorType attendingPhysician;

public:
    patientType(
        string fName = "", string lName = "", int id = 0, int a = 0,
        dateType dob = dateType(),
        dateType admit = dateType(),
        dateType discharge = dateType(),
        doctorType doctor = doctorType()
    )
    : personType(fName, lName),
      patientID(id),
      age(a),
      dateofBirth(dob),
      admittedDate(admit),
      dischargeDate(discharge),
      attendingPhysician(doctor) {}

    void printPatientInfo() const {
        cout << "Patient Name: " << firstName << " " << lastName << endl;
        cout << "ID: " << patientID << " Age: " << age << endl;
        cout << "Date of Birth: "; dateofBirth.printDate(); cout << endl;
        cout << "Admitted Date: "; admittedDate.printDate(); cout << endl;
        cout << "Discharge Date: "; dischargeDate.printDate(); cout << endl;
        cout << "Attending Physician: "; attendingPhysician.print(); cout << endl;
    }
};

int main()
{
    // main function
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
