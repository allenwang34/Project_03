//
//  main.cpp
//  Project_03
//
//  Created by Yiyang Wang on 7/20/17.
//  Copyright © 2017 Yiyang Wang. All rights reserved.
//

#include <iostream>
#include "PeopleList.h"


PeopleList::PeopleList()
    :listSize(0) {
    head -> next = head;
    head -> previous = head;
}


PeopleList::Node* PeopleList::PosOfFirstName(const std::string &firstname) {
    Node *p = head;
    for ( ; p!=head; p=p->next) {
        if (p->m_value < firstname && p->next->m_value > firstname) {
            return p;
        }
    }
    return p;
}


PeopleList::Node* PeopleList::PosOfLastName(const std::string &lastname) {
    Node *p = head;
    for ( ; p!=head; p=p->next) {
        if (p->m_value < lastname && p->next->m_value > lastname) {
            return p;
        }
    }
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
        return true;
    }
    else {
        p = PosOfLastName(lastName);
        newNode->next = p->next;
        newNode->previous = p;
        p->next->previous = newNode;
        p->next = newNode;
        return true;
    }
}



int main() {
    return 0;
}









