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

int main() {
	PeopleList m;

	m.add("Skyler", "White", 45);
	m.add("James", "McGill", 49);
	m.add("Charles", "McGill", 58);
	m.add("Walter", "White", 52);
	m.add("Jesse", "Pinkman", 27);

	for (int n = 0; n < m.size(); n++)
	{
		string f;
		string l;
		int v;
		m.get(n, f, l, v);
		cout << f << " " << l << " " << v << endl;
	}
	cout << endl;
	cout << endl;

	PeopleList h;
	h = m;

	for (int n = 0; n < h.size(); n++)
	{
		string x;
		string y;
		int z;
		h.get(n, x, y, z);
		cout << x << " " << y << " " << z << endl;
	}
	
	
}






