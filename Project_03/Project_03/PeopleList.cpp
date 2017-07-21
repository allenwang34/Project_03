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

int PeopleList::size() const {
    return listSize;
}

bool PeopleList::add(const std::string& firstName, const std::string& lastName, const InfoType& value) {
    for (Node *p = head->next; p!=head; p = p->next) {
        if (p->m_firstName == firstName && p->m_lastName == lastName){
            return false;
        }
    }
    
}



int main() {
    return 0;
}









