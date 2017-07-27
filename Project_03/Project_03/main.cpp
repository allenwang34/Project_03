//
//  main.cpp
//  Project_03
//
//  Created by Yiyang Wang on 7/23/17.
//  Copyright © 2017 Yiyang Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <assert.h>
#include "PeopleList.h"
using namespace std;

/*int main() {
	PeopleList result;
	PeopleList m1;
	PeopleList m2;

	result.add("Allen", "Amy", 1000);
	m1.add("Ethel", "Mertz", 456);
	m1.add("Fred", "Mertz", 123);
	m1.add("Lucy", "Ricardo", 789);
	m2.add("Lucy", "Ricardo", 654);
	m2.add("Ricky", "Ricardo", 321);

	cout << combine(m1, m2, result) << endl;
	for (int n = 0; n < result.size(); n++)
	{
		string f;
		string l;
		int v;
		result.get(n, f, l, v);
		cout << f << " " << l << " " << v << endl;
	}

	
}*/


int main() {
	PeopleList p1;
	PeopleList result;

	p1.add("Gustavo", "Fring", 57);
	p1.add("Skyler", "White", 45);
	p1.add("Walter", "White", 45);
	p1.add("Jane", "Doe", 35);
	p1.add("Marie", "Schrader", 37);
	p1.add("Jane", "Margolis", 27);

	psearch("*", "*", p1, result);

	for (int n = 0; n < result.size(); n++)
	{
		string f;
		string l;
		int v;
		result.get(n, f, l, v);
		cout << f << " " << l << " " << v << endl;
	}


}


/*#include "PeopleList.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    PeopleList m;
    assert(m.add("Fred", "Mertz", 52));
    assert(m.add("Ethel", "Mertz", 49));
    assert(m.size() == 2);
    string first, last;
    int a;
    assert(m.get(0, first, last, a)  &&  a == 49);
    string s1;
    assert(m.get(1, first, last, a)  &&
           (first == "Fred"  &&  a == 52));
}

int main()
{
    test();
    cout << "Passed all tests" << endl;
}*/




