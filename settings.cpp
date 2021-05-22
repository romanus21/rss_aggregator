#include "settings.hpp"
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int settings::numNewsOnPage = 4;
int settings::sizeOfFont = 14;

settings::settings() {
    this->load();
}

void settings::setNumNewsOnPage(int num) {
    settings::numNewsOnPage = num;
    settings::save();
}

int settings::getNumNewsOnPage() {
    return settings::numNewsOnPage;
}

void settings::setSizeOfFont(int num) {
    settings::sizeOfFont = num;
    settings::save();
}

int settings::getSizeOfFont() {
    return settings::sizeOfFont;
}

void settings::load() {
    fstream file;

    file.open("config.ini", ios::in);

    string s1;
    getline(file, s1);

    string s2;
    getline(file, s2);
	
    if (s1.find("num") == 0) {
        settings::numNewsOnPage = atoi(s1.substr(5).c_str());
    }
    else if (s1.find("size") == 0) {
        settings::sizeOfFont = atoi(s1.substr(6).c_str());
    }
    if (s2.find("size") == 0) {
        settings::sizeOfFont = atoi(s2.substr(6).c_str());
    }
    else if (s2.find("num") == 0) {
        settings::numNewsOnPage = atoi(s2.substr(5).c_str());
    }
    file.close();
}

void settings::save() {
    fstream file;

    file.open("config.ini", ios::out);

    file.clear();
	
    file << "num: " << settings::numNewsOnPage << endl;

    file << "size: " << settings::sizeOfFont << endl;
	
    file.close();
}
