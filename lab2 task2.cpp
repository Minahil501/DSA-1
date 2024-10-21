#include <iostream>
using namespace std;
class employee{ //abstract class
public:
	virtual void calculatesalary() = 0; //pure virtual function
};

class fulltimeemployee :public employee{ // derived class full time employee
private:
	int salary;
public:
	fulltimeemployee() :salary(90000){}
	void calculatesalary(){
		cout << "salary of full time employee is: " << salary << endl;
	}

};


class partTimeEmployee :public employee{ // part time employee
public:
	int hours;
	int rate;
	partTimeEmployee(){}
	partTimeEmployee(int r,int h){
		hours = h;
		rate = r;
	}
	void calculatesalary(){
		cout << "salary of part time employee is: " <<(rate*hours)*26 << endl;
	}
	
};
int main(){
	int a, b;
	employee*e;
	fulltimeemployee f;
	e = &f;
	e->calculatesalary();
	cout << "enter daily working hours of full time empoyee" << endl;
	cin >> a;
	cout << "enter hourly rate " << endl;
	cin >> b;
	partTimeEmployee p(a,b);
	e = &p;
	e->calculatesalary();
	return 0;

}