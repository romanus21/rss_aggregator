#pragma once
#include <map>
#include <string>

struct datetime
{
public:
	static std::map<std::string, int> monthToDays;
	int days = 0;
	int seconds = 0;
	datetime();
	datetime(std::string date);
	friend bool operator>(const datetime dt1, const datetime dt2);
	friend bool operator<(const datetime dt1, const datetime dt2);
	friend bool operator==(const datetime dt1, const datetime dt2);
	friend bool operator!=(const datetime dt1, const datetime dt2);
};