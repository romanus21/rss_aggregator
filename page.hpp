#pragma once
#include "item.hpp"

class Page
{
public:
	Page();
	Page(list<Item> ITEMS);
	int currentPage = 1;
	list<Item> NEWS;
	int pages = 0;
};
