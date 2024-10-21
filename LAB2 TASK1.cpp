#include <iostream>
using namespace std;
class shape{ //abstract class
public:
	virtual void area() = 0; //pure virtual function
};

class circle :public shape{ // derived class circle
private:
	long radius;
public:
	circle(){}
	circle(int r){ //constructor
		radius = r;
	}
	void area(){
		cout << "Area pf circle is: " << (3.142)*(radius)*(radius) << endl;
	}
	
};

class rectangle :public shape{ //derived class rectangle
private:
	int length;
	int width;
public :
	rectangle(){}
	rectangle(int l, int w){ //constructor
		length = l;
		width = w;
	}
	void area(){
		cout << "Area of rectangle is: " << length*width << endl;
	}
};
int main(){
	shape*s;
	circle c(2);
	s = &c;
	s->area();
	rectangle r(2, 3);
	s = &r;
	s->area();
	return 0;

}