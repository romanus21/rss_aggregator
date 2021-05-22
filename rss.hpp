#pragma once

#include <string>
#include <list>
#include <algorithm>
#include <fstream>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace IO;
using namespace msclr::interop;;
using namespace std;

class RSS {
private:
    static list <string> RSSes;

    void load();

    void save();

public:
    RSS();

    list <string> getRSS() const;

    void addRSS(string rss);

    void deleteRSS(string rss);
};

