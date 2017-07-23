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














