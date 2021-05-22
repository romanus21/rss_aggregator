#pragma once

#include <string>
#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include "datetime.hpp"

using namespace std;

class Item {
private:
    static string* str_fields;
    map <string, string> fields;
    list <string> categories;
    datetime dt;
    bool seen = false;
public:
    bool ifSeen() const;

    void Seen();
	
    static const int numFields = 4;

    Item();

    static string *getStrFields();

    void setField(string name, string value);

    void addCategory(string category);

    datetime getDT() const;

    list <string> getCategories() const;

    map <string, string> getFields() const;
};

void parse(string xml, list <Item> &items);