#include "item.hpp"

string* Item::str_fields = new string[Item::numFields]{
        "title",
        "description",
        "link",
        "pubDate",
};

const int size_to_delete = 6;

static string to_delete[size_to_delete] = {
        "<p>",
        "</p>",
        "<![CDATA[",
        "]]>",
		"<em>",
		"</em>"
};

void removeSubstring(string &s, string p) {
    string::size_type n = p.length();
    for (string::size_type i = s.find(p);
         i != string::npos;
         i = s.find(p))
        s.erase(i, n);
}

string *Item::getStrFields() {
    return Item::str_fields;
}

bool Item::ifSeen() const
{
    return this->seen;
}

void Item::Seen()
{
    this->seen = true;
}

Item::Item() { }

map <string, string> Item::getFields() const {
    return this->fields;
}

void Item::addCategory(string category) {
    this->categories.push_back(category);
}

datetime Item::getDT() const
{
    return this->dt;
}

void Item::setField(string name, string value) {
    if (name == "title" || name == "description") {
        for (int i = 0; i < size_to_delete; i++) {
            removeSubstring(value, to_delete[i]);
        }
    }
	else if (name == "pubDate")
	{
        this->dt = datetime(value);
	}
    if (this->fields.count(name) == 0)
        this->fields[name] = value;
}

list <string> Item::getCategories() const {
    return this->categories;
}




void parse(string xml, list <Item>& items) {
    int begin = 0;
    int end = 0;
    do {
        Item item = Item();
        begin = xml.find("<item>");
        end = xml.find("</item>");
        string str_item;
        try {
            str_item = xml.substr(begin, end - begin);
        }
        catch (std::out_of_range) {
            break;
        }
        string category;
        string str_category = str_item;
        string str_one_category;
        do {
            int begin_cat = str_category.find("<category");
            int end_cat = str_category.find("</category>");
            str_one_category = str_category.substr(begin_cat + 1, end_cat - begin_cat + 1);
            if (begin_cat > -1) {
                begin_cat = str_one_category.find(">");
                end_cat = str_one_category.find("<");
                category = str_one_category.substr(begin_cat + 1, end_cat - begin_cat - 1);
                transform(category.begin(), category.end(), category.begin(), tolower);
                item.addCategory(category);
            }
            else
                break;
            end_cat = str_category.find("</category>");
            str_category = str_category.substr(end_cat + string("</category>").length() + 1);
        } while (true);
        string res;
        for (int i = 0; i < Item::numFields; i++) {
            int field_begin = str_item.find("<" + Item::getStrFields()[i] + ">");
            int field_end = str_item.find("</" + Item::getStrFields()[i] + ">");
            res = str_item.substr(field_begin + Item::getStrFields()[i].length() + 2,
                field_end - field_begin - Item::getStrFields()[i].length() - 2);
            item.setField(Item::getStrFields()[i], res);
        }
        items.push_back(item);
        xml = xml.substr(end + 7);
    } while (begin != -1);
}