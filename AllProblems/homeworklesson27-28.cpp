

#include <iostream>
using namespace std;
struct Identity_card {
    string Name , country ,city ;
    int Age ;
    float Mounthly_salary, Yearly_salary;

};

enum status { Married , Single };
enum Gender { Male , Female };


int main()
{
    Identity_card User;
    status stat;
    Gender Gen;
    stat = status::Married;
    Gen = Gender::Male;
    User.Name = "Mohhamed Abu-hadhoud";
    User.Age = 44;
    User.city = "Amman";
    User.country = "Jordan";
    User.Mounthly_salary = 5000;
    User.Yearly_salary = 60000;
    cout << "*******************************************\n";

         cout << "Name:"<<User.Name<< endl;
         cout << "Age:" << User.Age<< endl ;
         cout << "city:"<<User.city<< endl;
         cout << "country:"<<User.country<< endl;        
         cout << "Mounthly salary:"<<User.Mounthly_salary<< endl;
         cout << "Yearly salary:"<<User.Yearly_salary<< endl;
         cout << "Status:"<< stat<< endl;
         cout << "Gender:"<<Gen<<endl;

    cout << "*******************************************\n";

    return 0;
}
