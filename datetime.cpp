#include "datetime.hpp"

#include <map>

std::map<std::string, int> datetime::monthToDays = {
	{"Jan", 0},
	{"Feb", 31},
	{"Mar", 59},
	{"Apr", 90},
	{"May", 120},
	{"Jun", 151},
	{"Jul", 181},
	{"Aug", 212},
	{"Sep", 243},
	{"Oct", 273},
	{"Nov", 304},
	{"Dec", 334},
};

datetime::datetime()
{
}

datetime::datetime(std::string date)
{
	this->days = atoi(date.substr(5, 2).c_str());
	
	std::string month = date.substr(8, 3);
	this->days += datetime::monthToDays[month];
	
	std::string year = date.substr(12, 4);
	this->days += atoi(year.c_str()) * 365;

	this->seconds = atoi(date.substr(23, 2).c_str());
	
	std::string minutes = date.substr(20, 2);
	this->seconds += atoi(minutes.c_str()) * 60;
	
	std::string hour = date.substr(17, 2);
	this->seconds += atoi(hour.c_str()) * 3600;

	std::string UTChour = date.substr(27, 2);
	this->seconds += atoi(UTChour.c_str()) * 3600;

	std::string UTCmins = date.substr(29, 2);
	this->seconds += atoi(UTCmins.c_str()) * 60;

	if (this->seconds> 86400)
	{
		this->days++;
		this->seconds -= 86400;
	}
}

bool operator>(const datetime dt1, const datetime dt2)
{
	if (dt1.days > dt2.days)
		return true;
	if (dt1.days == dt2.days && dt1.seconds > dt2.seconds)
		return true;
	return false;
}

bool operator<(const datetime dt1, const datetime dt2)
{
	if (dt1.days < dt2.days)
		return true;
	if (dt1.days == dt2.days && dt1.seconds < dt2.seconds)
		return true;
	return false;
}

bool operator==(const datetime dt1, const datetime dt2)
{
	return dt1.days == dt2.days && dt1.seconds == dt2.seconds;
}

bool operator!=(const datetime dt1, const datetime dt2)
{
	return dt1.days != dt2.days || dt1.seconds != dt2.seconds;
}
