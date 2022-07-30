//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//	Person(const string& name="zhangsan", int age=19)
//		:_name(name)
//		, _age(age)
//	{}
//	void Print()
//	{
//		cout << "name: " << _name << endl;
//		cout << "age: " << _age << endl;
//	}
//protected:
//	string _name;
//	int _age;
//};
//class Student : public Person
//{
//private:
//	int _stuid;
//};
//class Teacher : Person //classĬ��Ϊprivate�̳У�structĬ��Ϊpublic�̳�
//{
//public:
//	void Print()
//	{
//		cout << "name: " << _name << endl;
//		cout << "age: " << _age << endl;
//	}
//private:
//	int _jobid;
//};
//int main()
//{
//	Person p;
//	p.Print();
//	Teacher t;
//	t.Print();
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//	void Modify()
//	{
//		_id += 10;
//	}
//	void Print()
//	{
//		cout << _id << endl;
//	}
//protected:
//	int _id = 11;
//};
//class Student : public Person
//{
//public:
//	//void Modify()
//	//{
//	//	_id += 100;
//	//}
//	void Print()
//	{
//		cout << Person::_id << endl;
//	}
//private:
//	int _id = 111;
//};
//
//int main()
//{
//	Student st;
//	st.Modify();
//	st.Print();
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//	void func(double data)
//	{
//		cout << data << endl;
//	}
//};
//class Student : public Person
//{
//public:
//	void func(int data)
//	{
//		cout << data << endl;
//	}
//};
//
//int main()
//{
//	Student st;
//	st.func(2.1);
//	st.Person::func(2.1);
//	return 0;
//}

//Ĭ�ϳ�Ա����
//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//	Person(const string& name = "Lee")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "Person& operator=(const Person& p)" << endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//private:
//	string _name;
//};
//class Student : public Person
//{
//public:
//	Student(const string& name, int id)
//		:Person(name)
//		, _id(id)
//	{
//		cout << "Student()" << endl;
//	}
//	Student(const Student& p)
//		:Person(p)
//		, _id(p._id)
//	{
//		cout << "Student(const Student& p)" << endl;
//	}
//	Student& operator=(const Student& p)
//	{
//		if (this != &p)
//		{
//			Person::operator=(p);
//			_id = p._id;
//		}
//		cout << "Student& operator=(const Student& p)" << endl;
//		return *this;
//	}
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//private:
//	int _id;
//};
//int main()
//{
//	Student st("Lee", 20);
//	Student st1(st);
//	st1 = st;
//	return 0;
//}


//��Ԫ��ϵ���ܼ̳�
//#include <iostream>
//#include <string>
//using namespace std;
//class Student; //ע������
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name = "Lee";
//};
//class Student : public Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _id = 10;
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._id << endl;
//}
//int main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//	return 0;
//}


//����ľ�̬��Ա�����������̳���ϵ��ֻ��һ��ʵ��
//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//	Person()
//	{
//		_count++;
//	}
//public:
//	static int _count;
//};
//class Student : public Person
//{
//};
//int Person::_count = 0;
//int main()
//{
//	Person p;
//	Student s;
//	cout << &Person::_count << endl;
//	cout << &Student::_count << endl;
//	return 0;
//}

//���μ̳�->�����ԡ���������
//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//	string _name;
//};
//class Student : public Person
//{
//protected:
//	int _stuid;
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid;
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	int _id;
//};
//int main()
//{
//	Assistant a;
//	a.Student::_name = "Lee";
//	a.Teacher::_name = "Lee";
//	//a.Person::_name = "Lee"; //����ȷ��û�����ĵ���Student�̳е�Person���е�_name
//	return 0;
//}

//��������̳�
//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//	string _name;
//};
//class Student : virtual public Person
//{
//protected:
//	int _stuid;
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _jobid;
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	int _id;
//};
//int main()
//{
//	Assistant a;
//	a._name = "1";
//	a.Student::_name = "2";
//	a.Teacher::_name = "3";
//	cout << &a._name << endl;
//	cout << &a.Student::_name << endl;
//	cout << &a.Teacher::_name << endl;
//	return 0;
//}

//��������̳г�Ա�ֲ�
//#include <iostream>
//#include <string>
//using namespace std;
//class A
//{
//public:
//	int _a;
//};
//class B : virtual public A
//{
//public:
//	int _b;
//};
//class C : virtual public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	B b = d;
//	return 0;
//}



//��̬
//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��ͨ��->ȫ��" << endl;
//	}
//};
//class Student : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "ѧ��->���" << endl;
//	}
//};
//class Soldier : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "����->������Ʊ" << endl;
//	}
//};
//int main()
//{
//	Person p;
//	Student st;
//	Soldier so;
//	Person& ptr1 = p;
//	Person& ptr2 = st;
//	Person& ptr3 = so;
//	ptr1.BuyTicket();
//	ptr2.BuyTicket();
//	ptr3.BuyTicket();
//	return 0;
//}

//Э��
//#include <iostream>
//#include <string>
//using namespace std;
//class A
//{};
//class B : public A
//{};
//class Person
//{
//public:
//	virtual Person* BuyTicket()
//	{
//		cout << "��ͨ��->ȫ��" << endl;
//		return nullptr;
//	}
//};
//class Student : public Person
//{
//public:
//	virtual Student* BuyTicket()
//	{
//		cout << "ѧ��->���" << endl;
//		return nullptr;
//	}
//};
//class Soldier : public Person
//{
//public:
//	virtual Student* BuyTicket()
//	{
//		cout << "����->������Ʊ" << endl;
//		return nullptr;
//	}
//};
//int main()
//{
//	Person p;
//	Student st;
//	Soldier so;
//	Person& ptr1 = p;
//	Person& ptr2 = st;
//	Person& ptr3 = so;
//	ptr1.BuyTicket();
//	ptr2.BuyTicket();
//	ptr3.BuyTicket();
//	return 0;
//}

//������������д
//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//	//Person()
//	//{
//	//	cout << "Person()" << endl;
//	//}
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//class Student : public Person
//{
//public:
//	//Student()
//	//{
//	//	cout << "Student()" << endl;
//	//}
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};
//int main()
//{
//	Person* ptr1 = new Person;
//	Person* ptr2 = new Student;
//	delete ptr1;
//	delete ptr2;
//	return 0;
//}

//final��override
//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//	virtual void func() //final
//	{
//		cout << "Person" << endl;
//	}
//};
//class Student : public Person
//{
//public:
//	virtual void func() override
//	{
//		cout << "Student" << endl;
//	}
//};
//int main()
//{
//
//	return 0;
//}

//������
//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//	virtual void func() = 0
//	{
//		cout << "Person" << endl;
//	}
//};
//class Student : public Person
//{
//public:
//	virtual void func()
//	{
//		cout << "Student" << endl;
//	}
//};
//int main()
//{
//	//Person p; //error
//	Student s;
//	return 0;
//}

//��Ĵ�С
//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//	virtual void func()
//	{
//		cout << "Person" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	Person p;
//	return 0;
//}


#include <iostream>
using namespace std;
class A
{
public:
	virtual void funcA()
	{
		cout << "A::funcA()" << endl;
	}
private:
	int _a;
};
class B : virtual public A
{
public:
	virtual void funcA()
	{
		cout << "B::funcA()" << endl;
	}
	virtual void funcB()
	{
		cout << "B::funcB()" << endl;
	}
private:
	int _b;
};
class C : virtual public A
{
public:
	virtual void funcA()
	{
		cout << "C::funcA()" << endl;
	}
	virtual void funcC()
	{
		cout << "C::funcC()" << endl;
	}
private:
	int _c;
};
class D : public B, public C
{
public:
	virtual void funcA()
	{
		cout << "D::funcA()" << endl;
	}
	virtual void funcD()
	{
		cout << "D::funcD()" << endl;
	}
private:
	int _d;
};
typedef void(*VFPTR)();
int main()
{
	B b;
	VFPTR* p = (VFPTR*)*(int*)((char*)&b + 12);
	(*p)();
	return 0;
}
