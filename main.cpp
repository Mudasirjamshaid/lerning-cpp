#include <fstream>
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Base
{
private:
    T salary;
    T password;

public:
    T name;
    T age;
    T gender;
    T address;
    T phone;
    T email;
    T birthday;
    T occupation;
    T education;
    T skills;
    T languages;
    T hobbies;
    T interests;
    T goals;
    T ambitions;
    T dreams;
    T subject;
    T marks;
    T grades;

    virtual void input() = 0;
    virtual void display() const = 0;                  // Display function added
    virtual void saveToFile(ofstream &file) const = 0; // Save function added
};

template <typename T>
class Employes : public Base<T>
{
public:
    void input() override
    {
        cout << "Enter Information for Employees" << endl;
        cout << "Enter name: ";
        getline(cin, this->name);
        cout << "Enter age: ";
        getline(cin, this->age);
        cout << "Enter gender: ";
        getline(cin, this->gender);
        cout << "Enter address: ";
        getline(cin, this->address);
        cout << "Enter phone: ";
        getline(cin, this->phone);
        cout << "Enter email: ";
        getline(cin, this->email);
        cout << "Enter birthday: ";
        getline(cin, this->birthday);
        cout << "Enter occupation: ";
        getline(cin, this->occupation);
        cout << "Enter education: ";
        getline(cin, this->education);
        cout << "Enter skills: ";
        getline(cin, this->skills);
        cout << "Enter languages: ";
        getline(cin, this->languages);
        cout << "Enter hobbies: ";
        getline(cin, this->hobbies);
    }

    void display() const override
    {
        cout << "\nEmployee Information:" << endl;
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Gender: " << this->gender << endl;
        cout << "Address: " << this->address << endl;
        cout << "Phone: " << this->phone << endl;
        cout << "Email: " << this->email << endl;
        cout << "Birthday: " << this->birthday << endl;
        cout << "Occupation: " << this->occupation << endl;
        cout << "Education: " << this->education << endl;
        cout << "Skills: " << this->skills << endl;
        cout << "Languages: " << this->languages << endl;
        cout << "Hobbies: " << this->hobbies << endl;
    }

    void saveToFile(ofstream &file) const override
    {
        if (file.is_open())
        {
            file << "Information about Employees" << endl;
            file << "Name: " << this->name << endl;
            file << "Age: " << this->age << endl;
            file << "Gender: " << this->gender << endl;
            file << "Address: " << this->address << endl;
            file << "Phone: " << this->phone << endl;
            file << "Email: " << this->email << endl;
            file << "Birthday: " << this->birthday << endl;
            file << "Occupation: " << this->occupation << endl;
            file << "Education: " << this->education << endl;
            file << "Skills: " << this->skills << endl;
            file << "Languages: " << this->languages << endl;
            file << "Hobbies: " << this->hobbies << endl;
        }
        else
        {
            cout << "Unable to open file to save employee information." << endl;
        }
    }
};

template <typename T>
class Student : public Base<T>
{
public:
    void input() override
    {
        cout << "\nEnter Information for Students" << endl;
        cout << "Enter student name: ";
        getline(cin, this->name);
        cout << "Enter student age: ";
        getline(cin, this->age);
        cout << "Enter student gender: ";
        getline(cin, this->gender);
        cout << "Enter student address: ";
        getline(cin, this->address);
        cout << "Enter education: ";
        getline(cin, this->education);
        cout << "Enter interests: ";
        getline(cin, this->interests);
        cout << "Enter goals: ";
        getline(cin, this->goals);
        cout << "Enter ambitions: ";
        getline(cin, this->ambitions);
        cout << "Enter subject: ";
        getline(cin, this->subject);
        cout << "Enter marks: ";
        getline(cin, this->marks);
        cout << "Enter grades: ";
        getline(cin, this->grades);
    }

    void display() const override
    {
        cout << "\nStudent Information:" << endl;
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Gender: " << this->gender << endl;
        cout << "Address: " << this->address << endl;
        cout << "Education: " << this->education << endl;
        cout << "Interests: " << this->interests << endl;
        cout << "Goals: " << this->goals << endl;
        cout << "Ambitions: " << this->ambitions << endl;
        cout << "Subject: " << this->subject << endl;
        cout << "Marks: " << this->marks << endl;
        cout << "Grades: " << this->grades << endl;
    }

    void saveToFile(ofstream &file) const override
    {
        if (file.is_open())
        {
            file << "\nInformation about Students" << endl;
            file << "Name: " << this->name << endl;
            file << "Age: " << this->age << endl;
            file << "Gender: " << this->gender << endl;
            file << "Address: " << this->address << endl;
            file << "Education: " << this->education << endl;
            file << "Interests: " << this->interests << endl;
            file << "Goals: " << this->goals << endl;
            file << "Ambitions: " << this->ambitions << endl;
            file << "Subject: " << this->subject << endl;
            file << "Marks: " << this->marks << endl;
            file << "Grades: " << this->grades << endl;
        }
        else
        {
            cout << "Unable to open file to save student information." << endl;
        }
    }
};

int main()
{
    Employes<string> employee;
    employee.input();
    employee.display();

    ofstream file("Text.txt");
    if (file.is_open())
    {
        employee.saveToFile(file);
        file.close();
    }
    else
    {
        cout << "Unable to open file to save employee information." << endl;
    }

    Student<string> student;
    student.input();
    student.display();

    file.open("Text.txt", ios::app); // Open file in append mode
    if (file.is_open())
    {
        student.saveToFile(file);
        file.close();
    }
    else
    {
        cout << "Unable to open file to save student information." << endl;
    }

    return 0;
}
