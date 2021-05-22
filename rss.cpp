#include "rss.hpp"



list <string> RSS::RSSes;

void RSS::load() {
    fstream file;

    file.open("list_rss.ini", ios::in);
	
    string s;

	if (file.is_open())
	{
		while (!file.eof()) {
			file >> s;
			if (!s.empty())
				this->addRSS(s);
		}
	}

    file.close();
}

void RSS::save() {
    fstream file;

    file.open("list_rss.ini", ios::out);

    file.clear();

    for_each(RSS::RSSes.begin(), RSS::RSSes.end(), [&](string s) {
        file << s << endl;
        });

    file.close();
}

RSS::RSS() {
    this->load();
}

list <string> RSS::getRSS() const {
    return RSS::RSSes;
}

void RSS::addRSS(string rss) {
    if (find(RSS::RSSes.begin(), RSS::RSSes.end(), rss) == RSS::RSSes.end()) {
        RSS::RSSes.push_back(rss);
        this->save();
    }
}

void RSS::deleteRSS(string rss) {
    RSS::RSSes.remove(rss);
    this->save();
}
