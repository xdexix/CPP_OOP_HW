#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

class Student
{
	string name;
	string surname;
	int age;
public:
	Student();
    	~Student() {};
	Student(string _name, string _surname, int _age);
    	int GetAge() { return age; };
	friend ostream& operator << (ostream& os, const Student& student);
};
Student::Student()
{
	name = " ";
	surname = " ";
}
Student::Student(string _name, string _surname, int _age)
{
	name = _name;
	surname = _surname;
	age = _age;
}
ostream& operator << (ostream& os, const Student& student)
{
	os << setw(15) << student.name << setw(15) << student.surname << setw(3) << student.age << endl;
	return os;
}

bool find_a(int &n)
{
    if (n % 3 == 0)
    {
        n *= 2;
        return true;
    }
    else return false;
}

bool find_b(Student s)
{
    return (s.GetAge() <= 18);
}

int main()
{
    setlocale(LC_ALL, "russian");
    srand(time(NULL));
    system("mode con cols=70 lines=50");

    vector<Student> studs =
    {
        Student("Алена", "Евдокимова", 14),
        Student("Дарья", "Герасимова", 54),
        Student("Василий", "Васильев", 19),
        Student("Михаил", "Кузнецов", 19),
        Student("Татьяна", "Некрасова", 23),
        Student("Юлия", "Чернова", 13),
        Student("Василиса", "Беляева", 31),
        Student("Елисей", "Воронов", 23),
        Student("Егор", "Филатов", 4),
        Student("Михаил", "Латышев", 43),
        Student("Александр", "Лукич", 1),
        Student("Бессонова", "Ольга", 27),
        Student("Ева", "Орлова", 31),
        Student("Вероника", "Иванова", 18),
        Student("Анастасия", "Никитина", 19),
        Student("Олег", "Фетисов", 20),
        Student("Варвара", "Степанова", 13),
        Student("Павел", "Казаков", 17),
        Student("Матвей", "Голиков", 9),
        Student("Василиса", "Романова", 18)
    };
    for (Student n : studs) cout << n;
    cout << "--------------------------------------" << endl;
    auto new_end{ remove_if(studs.begin(), studs.end(), find_b) };
    studs.erase(new_end, studs.end());
    for (Student n : studs) cout << n;
    cout << endl << "--------------------------------------" << endl << endl;

    vector<int> num;
    for (int i = 0; i < 15; i++)
    {
        num.push_back(rand() % 50);
    }
    for (int n : num) cout << setw(4) << n;
    cout << endl << "--------------------------------------" << endl;
    auto c_n{ count_if(num.begin(), num.end(), find_a) };
    for (int n : num) cout << setw(4) << n;
    cout << endl << "\tВсего чисел изменено: " << c_n;
    cout << endl << "--------------------------------------" << endl;
}
