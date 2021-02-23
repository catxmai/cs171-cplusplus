#include "Vector.h"
#include <string>

/////////////////////////////////////////////////
// Class declaration for test class            //
/////////////////////////////////////////////////

class Person
{
	friend std::ostream& operator<<(std::ostream& os, const Person& p);

public:
	Person() : m_name(""), m_age(0) {}
	Person(std::string name, int age) : m_name(name), m_age(age) {}

private:
	std::string m_name;
	int m_age;
};

std::ostream& operator<< (std::ostream& os, const Person& p)
{
	os << "(" << p.m_name << ", " << p.m_age << ")";
	return os;
}


/////////////////////////////////////////////////
// main (driver code)                          //
/////////////////////////////////////////////////

int main()
{
	{
		std::cout << "*** TESTING INTEGERS ***" << std::endl;
		Vector<int> v;

		std::cout << "Block 1" << std::endl;

		v.push(1);
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
		v.push(2);
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
		v.push(3);
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
		v.push(4);
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
		v.push(5);
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
		v.push(6);
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		std::cout << "Block 2" << std::endl;

		int a[] = { 7, 8, 9, 10 };
		v.push(a, 4);
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		std::cout << "Block 3" << std::endl;

		std::cout << v << std::endl;
		std::cout << "Sum=" << v.sum() << std::endl;

		std::cout << v[0] << std::endl;
		std::cout << v[3] << std::endl;
		std::cout << v[5] << std::endl;
		std::cout << v[9] << std::endl;
		std::cout << v[11] << std::endl;

		std::cout << "Block 4" << std::endl;

		v.setAt(2, 1234);
		std::cout << v << std::endl;
		v.setAt(1234, 2);
		v.setAtGrow(1234, 2);
		std::cout << v[1233] << std::endl;
		std::cout << v[1234] << std::endl;
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		std::cout << "Block 5" << std::endl;

		v.minimize();
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		v.clear();
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		v.minimize();
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		v.push(1);
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
	}

	{
		std::cout << "*** TESTING DOUBLES ***" << std::endl;
		Vector<double> v;

		std::cout << "Block 1" << std::endl;

		v.push(1.1);
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
		v.push(2.2);
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
		v.push(3.3);
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
		v.push(4.4);
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
		v.push(5.5);
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
		v.push(6.6);
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		std::cout << "Block 2" << std::endl;

		double a[] = { 7.7, 8.8, 9.9, 10.10 };
		v.push(a, 4);
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		std::cout << "Block 3" << std::endl;

		std::cout << v << std::endl;
		std::cout << "Sum=" << v.sum() << std::endl;

		std::cout << v[0] << std::endl;
		std::cout << v[3] << std::endl;
		std::cout << v[5] << std::endl;
		std::cout << v[9] << std::endl;
		std::cout << v[11] << std::endl;

		std::cout << "Block 4" << std::endl;

		v.setAt(2, 1234.0);
		std::cout << v << std::endl;
		v.setAt(1234, 2.0);
		v.setAtGrow(1234, 2.0);
		std::cout << v[1233] << std::endl;
		std::cout << v[1234] << std::endl;
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		std::cout << "Block 5" << std::endl;

		v.minimize();
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		v.clear();
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		v.minimize();
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		v.push(1);
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
	}


	{
		std::cout << "*** TESTING STRINGS ***" << std::endl;
		Vector<std::string> v;

		std::cout << "Block 1" << std::endl;

		v.push("a");
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
		v.push("b");
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
		v.push("c");
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
		v.push("d");
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
		v.push("e");
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
		v.push("f");
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		std::cout << "Block 2" << std::endl;

		std::string a[] = { "g", "h", "i", "j" };
		v.push(a, 4);
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		std::cout << "Block 3" << std::endl;

		std::cout << v << std::endl;
		std::cout << "Sum=" << v.sum() << std::endl;

		std::cout << v[0] << std::endl;
		std::cout << v[3] << std::endl;
		std::cout << v[5] << std::endl;
		std::cout << v[9] << std::endl;
		std::cout << v[11] << std::endl;

		std::cout << "Block 4" << std::endl;

		v.setAt(2, "index 2");
		std::cout << v << std::endl;
		v.setAt(1234, "index 1234");
		v.setAtGrow(1234, "index 1234");
		std::cout << v[1233] << std::endl;
		std::cout << v[1234] << std::endl;
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		std::cout << "Block 5" << std::endl;

		v.minimize();
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		v.clear();
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		v.minimize();
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		v.push("a");
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
	}

	{
		std::cout << "*** TESTING PERSONS ***" << std::endl;
		Vector<Person> v;

		std::cout << "Block 1" << std::endl;

		v.push(Person("Homer", 38));
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
		v.push(Person("Marge", 34));
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
		v.push(Person("Bart", 10));
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
		v.push(Person("Lisa", 8));
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
		v.push(Person("Maggie", 1));
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		std::cout << "Block 2" << std::endl;

		Person a[] = {
			Person("Burns", 103),
				Person("Smithers", 31),
				Person("Otto", 22),
				Person("Milhouse", 10),
				Person("Apu", 29)
		};
		v.push(a, 5);
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		std::cout << "Block 3" << std::endl;

		std::cout << v << std::endl;
		// std::cout << "Sum=" << v.sum() << std::endl;

		std::cout << v[0] << std::endl;
		std::cout << v[3] << std::endl;
		std::cout << v[5] << std::endl;
		std::cout << v[9] << std::endl;
		std::cout << v[11] << std::endl;

		std::cout << "Block 4" << std::endl;

		v.setAt(2, Person("Barney", 45));
		std::cout << v << std::endl;
		v.setAt(1234, Person("Moe", 45));
		v.setAtGrow(1234, Person("Moe", 45));
		std::cout << v[1233] << std::endl;
		std::cout << v[1234] << std::endl;
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		std::cout << "Block 5" << std::endl;

		v.minimize();
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		v.clear();
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		v.minimize();
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;

		v.push(Person("Krusty", 58));
		std::cout << v.size() << std::endl;
		std::cout << v.memUsage() << std::endl;
	}

	return 0;
}