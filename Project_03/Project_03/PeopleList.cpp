//
//  main.cpp
//  Project_03
//
//  Created by Yiyang Wang on 7/20/17.
//  Copyright © 2017 Yiyang Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include "PeopleList.h"


PeopleList::PeopleList()
    :listSize(0) {
    Node *newNode = new Node;
    head = newNode;
    head -> next = head;
    head -> previous = head;
    head -> m_firstName = "";
    head -> m_lastName = "";
}

PeopleList::PeopleList(const PeopleList &other) {
	Node *newNode = new Node;
	head = newNode;
	head->next = head;
	head->previous = head;
	head->m_firstName = "";
	head->m_lastName = "";

	Node *p = other.head->next;
	Node *n = head;
	while (p!=other.head) {
		Node *newNode = new Node;
		newNode->next = head;
		newNode->previous = n;
		n->next = newNode;
		head->previous = newNode;
		newNode->m_value = p->m_value;
		newNode->m_firstName = p->m_firstName;
		newNode->m_lastName = p->m_lastName;
		n = newNode;
		p = p->next;
	}

	listSize = other.listSize;

}

PeopleList& PeopleList::operator=(const PeopleList& other) {
	PeopleList copy(other);
	swap(copy);
	return *this;
}




PeopleList::~PeopleList() {
    Node *p = head->next;
    while (p!=head) {
        head->next = p->next;
        head->next->previous = head;
        Node *n = p;
        p = p->next;
        delete n;
    }
    delete head;
    
}


PeopleList::Node* PeopleList::PosOfFirstName(const std::string &firstname) { //return the place ready to insert. Need to insert the next node.
    Node *p = head;
    for (p=p->next; p!=head; p=p->next) {
        if (p->m_firstName < firstname && p->next->m_firstName > firstname) {
            return p;
        }
    }
    if (firstname > p->next->m_firstName)
        return p->previous;
    else
        return p;
}


PeopleList::Node* PeopleList::PosOfLastName(const std::string &lastname) {
    Node *p = head;
    for (p=p->next; p!=head; p=p->next) {
        if (p->m_lastName < lastname && p->next->m_lastName > lastname) {
            return p;
        }
    }
    if (lastname > p->next->m_lastName)
        return p -> previous;
    else
        return p;
}



int PeopleList::size() const {
    return listSize;
}



bool PeopleList::add(const std::string& firstName, const std::string& lastName, const InfoType& value) {
    bool lastNameSame = false;
    Node *p = head->next;
    for (; p!=head; p = p->next) {
        if (p->m_firstName == firstName && p->m_lastName == lastName){
            return false;
        }
        else if (p->m_lastName == lastName) {
            lastNameSame = true;
            break;
        }
        else
            ;
    }
    Node *newNode = new Node;
    newNode->m_firstName = firstName;
    newNode->m_lastName = lastName;
    newNode->m_value = value;
    if (lastNameSame == true) {
        p = PosOfFirstName(firstName);
        newNode->next = p->next;
        newNode->previous = p;
        p->next->previous = newNode;
        p->next = newNode;
        listSize++;
        return true;
    }
    else {
        p = PosOfLastName(lastName);
        newNode->next = p->next;
        newNode->previous = p;
        p->next->previous = newNode;
        p->next = newNode;
        listSize++;
        return true;
    }
}


bool PeopleList::get(int i, std::string& firstName, std::string& lastName, InfoType& value) const {
    int counter = 0;
    for (Node *p = head->next; p != head; p=p->next) {
        if (counter == i) {
            firstName = p->m_firstName;
            lastName = p-> m_lastName;
            value = p->m_value;
            return true;
        }
        else
            counter++;
    }
    return false;
    
}

bool PeopleList::change(const std::string& firstName, const std::string& lastName, const InfoType& value) {
	Node *p = head->next;
	for (; p != head; p = p->next) {
		if (p->m_firstName == firstName && p->m_lastName == lastName) {
			p->m_value = value;
			return true;
		}
	}
	return false;
}


bool PeopleList::addOrChange(const std::string& firstName, const std::string& lastName, const InfoType& value) {
	bool lastNameSame = false;
	Node *p = head->next;
	for (; p != head; p = p->next) {
		if (p->m_firstName == firstName && p->m_lastName == lastName) {
			p->m_value = value;
			return true;
		}
		else if (p->m_lastName == lastName) {
			lastNameSame = true;
			break;
		}
		else
			;
	}
	Node *newNode = new Node;
	newNode->m_firstName = firstName;
	newNode->m_lastName = lastName;
	newNode->m_value = value;
	if (lastNameSame == true) {
		p = PosOfFirstName(firstName);
		newNode->next = p->next;
		newNode->previous = p;
		p->next->previous = newNode;
		p->next = newNode;
		listSize++;
		return true;
	}
	else {
		p = PosOfLastName(lastName);
		newNode->next = p->next;
		newNode->previous = p;
		p->next->previous = newNode;
		p->next = newNode;
		listSize++;
		return true;
	}

}

bool PeopleList::remove(const std::string& firstName, const std::string& lastName) {
	Node *p = head->next;
	for (; p != head; p = p->next) {
		if (p->m_firstName == firstName && p->m_lastName == lastName) {
			p->previous->next = p->next;
			p->next->previous = p->previous;
			delete p;
			listSize--;
			return true;
		}
	}
	return false;
}


bool PeopleList::contains(const std::string& firstName, const std::string& lastName) const {
	Node *p = head->next;
	for (; p != head; p = p->next) {
		if (p->m_firstName == firstName && p->m_lastName == lastName)
			return true;
	}
	return false;
}


bool PeopleList::lookup(const std::string& firstName, const std::string& lastName, InfoType& value) const {
	Node *p = head->next;
	for (; p != head; p = p->next) {
		if (p->m_firstName == firstName && p->m_lastName == lastName) {
			value = p->m_value;
			return true;
		}
	}
	return false;
}

bool PeopleList::empty() const {
	if (head->next == head && head->previous == head)
		return true;
	else
		return false;
}



void PeopleList::swap(PeopleList& other) {
	Node *temp = new Node;
	temp->m_firstName = "";
	temp->m_lastName = "";
	
	temp->next = head->next;
	head->next->previous = temp;
	temp->previous = head->previous;
	head->previous->next = temp;

	head->next = other.head->next;
	other.head->next->previous = head;
	head->previous = other.head->previous;
	other.head->previous->next = head;

	other.head->next = temp->next;
	temp->next->previous = other.head;
	other.head->previous = temp->previous;
	temp->previous->next = other.head;


	std::swap(listSize, other.listSize);
}



bool combine(const PeopleList& m1, const PeopleList& m2, PeopleList& result) {
	bool isEqualValue = true;
	
	for (int j = 0; j < m1.size(); j++) {
		std::string firstName;
		std::string lastName;
		InfoType m1Value;
		InfoType resultValue;
		m1.get(j, firstName, lastName, m1Value);
		if (result.lookup(firstName, lastName, resultValue) && resultValue == m1Value) {
			;
		}
		else if (result.lookup(firstName, lastName, resultValue) && resultValue != m1Value) {
			result.remove(firstName, lastName);
			isEqualValue = false;
		}
		else {
			result.add(firstName, lastName, m1Value);
		}
	}

	for (int i = 0; i < m2.size();i++){
		std::string firstName;
		std::string lastName;
		InfoType m2Value;
		InfoType resultValue;
		m2.get(i, firstName, lastName, m2Value);
		if (result.lookup(firstName,lastName,resultValue) && resultValue == m2Value ) {
			;
		}
		else if (result.lookup(firstName, lastName, resultValue) && resultValue != m2Value) {
			result.remove(firstName, lastName);
			isEqualValue = false;
		}
		else {
			result.add(firstName, lastName, m2Value);
		}
	}
	return isEqualValue;
}

void psearch(const std::string& fsearch, const std::string& lsearch, const PeopleList& p1, PeopleList& result) {
	if (fsearch == "*" && lsearch == "*") {
		for (int i = 0; i < p1.size(); i++) {
			std::string firstName;
			std::string lastName;
			InfoType p1Value;
			p1.get(i, firstName, lastName, p1Value);
			result.add(firstName, lastName, p1Value);
		}
	}
	else if (fsearch == "*" && lsearch != "*") {
		for (int j = 0; j < p1.size(); j++) {
			std::string firstName;
			std::string lastName;
			InfoType p1Value;
			p1.get(j, firstName, lastName, p1Value);
			if (lastName==lsearch) {
				result.add(firstName, lastName, p1Value);
			}
		}
	}
	else if (fsearch != "*" && lsearch == "*") {
		for (int j = 0; j < p1.size(); j++) {
			std::string firstName;
			std::string lastName;
			InfoType p1Value;
			p1.get(j, firstName, lastName, p1Value);
			if (firstName == fsearch) {
				result.add(firstName, lastName, p1Value);
			}
		}
	}
	else {
		if (p1.contains(fsearch,lsearch)) {
			InfoType p1Value;
			p1.lookup(fsearch, lsearch, p1Value);
			result.add(fsearch, lsearch, p1Value);
		}
		else{
			return;
		}
	}
}






