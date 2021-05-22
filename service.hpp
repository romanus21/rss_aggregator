#pragma once
#include "item.hpp"
#include "rss.hpp"
#include "settings.hpp"
#include "load.hpp"
#include "page.hpp"
#include <set>

using namespace System::Drawing;


class Service
{
private:
	static settings setts;
	static RSS RSSes;
	static Page IndexPage;
	static Page cache;
	static set<string> cacheItems;
	static void getItems(list<Item>& ITEMS);
	static void load_cache();
	static void save_cache();
	static int currentDays;
	static int cacheDays;
public:
	Service();

	static void close();
	static void load();
	static void update();

	static void updateSettings();
	static void backToIndex();
	static void filterByCategory(String^ category);

	static void printIndexPage(System::Windows::Forms::RichTextBox^ textbox);
	static void printPaginator(System::Windows::Forms::RichTextBox^ textbox);
	static void printSettings(System::Windows::Forms::MaskedTextBox^ num, System::Windows::Forms::MaskedTextBox^ size);
	static void printRSSes(System::Windows::Forms::CheckedListBox^ box);

	static void pageNext();
	static void pagePrevious();

	static void setNumNewsOnPage(int num);
	static void setSizeFont(int num);

	static void deleteRSSes(System::Windows::Forms::CheckedListBox^ box);
	static void addRSS(String^ RSS);
};

