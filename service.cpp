#include "service.hpp"


settings Service::setts;

RSS Service::RSSes;

Page Service::IndexPage;

Page Service::cache;

set<string> Service::cacheItems;

int Service::currentDays = 0;

int Service::cacheDays = 0;

Service::Service()
{
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    this->currentDays = timeinfo->tm_yday + (timeinfo->tm_year+1900)*365;
}

void Service::close()
{
    Service::save_cache();
}


void Service::load()
{
    list<Item> NEWS;
	
    Service::load_cache();
	
    Service::getItems(NEWS);

    NEWS.remove_if([&](Item item)
        {
            for (string url : Service::cacheItems)
            {
                if (item.getFields()["link"] == url)
                {
                    return true;
                }
            }
            return false;
        });

    NEWS.sort([](Item item1, Item item2)
        {
            return item1.getDT() > item2.getDT();
        });
	
    IndexPage = Page(NEWS);
	
    IndexPage.pages = NEWS.size() / Service::setts.getNumNewsOnPage();
    if (NEWS.size() - IndexPage.pages * Service::setts.getNumNewsOnPage() != 0)
        IndexPage.pages++;
	
    Service::cache = Service::IndexPage;
}

void Service::updateSettings()
{
    IndexPage.pages = IndexPage.NEWS.size() / Service::setts.getNumNewsOnPage();
    if (IndexPage.NEWS.size() - IndexPage.pages * Service::setts.getNumNewsOnPage() != 0)
        IndexPage.pages++;
    if (IndexPage.currentPage >= IndexPage.pages)
        IndexPage.currentPage = 1;
}

void Service::update()
{
    Service::save_cache();
	
    list<Item> NEWS;

    Service::getItems(NEWS);

    NEWS.remove_if([&](Item item)
        {
            for (string url : Service::cacheItems)
            {
                if (item.getFields()["link"] == url)
                {
                    return true;
                }
            }
        });

    NEWS.sort([](Item item1, Item item2)
        {
            return item1.getDT() > item2.getDT();
        });

    IndexPage = Page(NEWS);
	
    IndexPage.pages = NEWS.size() / Service::setts.getNumNewsOnPage();
    if (NEWS.size() - IndexPage.pages * Service::setts.getNumNewsOnPage() != 0)
        IndexPage.pages++;
	
    Service::cache = Service::IndexPage;
}


void Service::getItems(list<Item>& ITEMS)
{
    list<string> thisRSS = Service::RSSes.getRSS();
	for_each(thisRSS.begin(), thisRSS.end(),
		[&](string RSS) {
			parse(load_xml(RSS), ITEMS);
		}
	);
}

void Service::load_cache()
{
    fstream file;

    file.open("cache.ini", ios::in);
    string s;

    file >> s;

	if (file.is_open())
	{
		if (Service::currentDays - atoi(s.c_str()) < 7)
        {
            Service::cacheDays = atoi(s.c_str());
			while (!file.eof()) {
				file >> s;
				if (!s.empty())
					Service::cacheItems.insert(s);
			}
		}
		else
		{
            Service::cacheDays = Service::currentDays;
            file.clear();
		}
	}
	
    file.close();
}

void Service::save_cache()
{
    fstream file;

    file.open("cache.ini", ios::out);

    file.clear();

    file << to_string(Service::cacheDays) + "\n";

    for (string s: Service::cacheItems)
    {
        file << s + "\n";
    }
	
    file.close();
}

void Service::printPaginator(System::Windows::Forms::RichTextBox^ textbox)
{
    if (Service::IndexPage.pages == 0)
        textbox->Text = 0 + " of " + Service::IndexPage.pages;

    else textbox->Text = Service::IndexPage.currentPage.ToString() + " of " + Service::IndexPage.pages;
}

void Service::printSettings(System::Windows::Forms::MaskedTextBox^ num, System::Windows::Forms::MaskedTextBox^ size)
{
    num->Text = Service::setts.getNumNewsOnPage().ToString();
    size->Text = Service::setts.getSizeOfFont().ToString();
}

void Service::printRSSes(System::Windows::Forms::CheckedListBox^ box)
{
    box->Items->Clear();
	
    list<string> RSSes = Service::RSSes.getRSS();
	
    auto begin = RSSes.begin();
	for(int i=0; i< RSSes.size(); i++)
	{
        String^ str = gcnew String(begin->c_str());
        box->Items->Add(str);
        delete str;
        ++begin;
	}
}


void Service::printIndexPage(System::Windows::Forms::RichTextBox^ textbox)
{
    textbox->Font =
        (gcnew System::Drawing::Font(L"Microsoft Sans Serif",
            System::Convert::ToInt32(Service::setts.getSizeOfFont()),
            System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(204)));
    textbox->Clear();
	
    if (IndexPage.NEWS.empty())
    {
        textbox->AppendText("No news!");
        return;
    }
	
    auto begin = IndexPage.NEWS.begin();
    advance(begin, (IndexPage.currentPage-1) * setts.getNumNewsOnPage());
	
    auto end = IndexPage.NEWS.begin();
	
    if (IndexPage.currentPage == IndexPage.pages)
        end = IndexPage.NEWS.end();
    else
        advance(end, (IndexPage.currentPage) * settings::getNumNewsOnPage());
	
    textbox->SelectionStart = 0;
	
    while (begin!=end) {

        if (!begin->ifSeen())
        {
            begin->Seen();
            Service::cacheItems.insert(begin->getFields()["link"]);
        }
    	
        auto item = *begin;

        for (int i = 0; i < Item::numFields; i++) {
            string tag = Item::getStrFields()[i] + ": ";
            string value = item.getFields()[Item::getStrFields()[i]] + "\n";

            textbox->SelectionColor = Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(112)),
                static_cast<System::Int32>(static_cast<System::Byte>(155)));
            textbox->SelectionFont = gcnew Font(L"Microsoft Sans Serif",
                System::Convert::ToInt32(Service::setts.getSizeOfFont()),
                System::Drawing::FontStyle::Bold);
        	
            String^ strResult = gcnew String(tag.c_str());
            textbox->AppendText(strResult);

            textbox->SelectionColor = SystemColors::WindowText;
            textbox->SelectionFont = gcnew Font(L"Microsoft Sans Serif",
                System::Convert::ToInt32(Service::setts.getSizeOfFont()),
                System::Drawing::FontStyle::Regular);
        	
            strResult = gcnew String(value.c_str());
            textbox->AppendText(strResult);
        	
            delete strResult;
        }

        textbox->SelectionColor = Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(112)),
            static_cast<System::Int32>(static_cast<System::Byte>(155)));
        textbox->SelectionFont = gcnew Font(L"Microsoft Sans Serif",
            System::Convert::ToInt32(Service::setts.getSizeOfFont()),
            System::Drawing::FontStyle::Bold);
    	
        textbox->AppendText("Categories: ");
    	
        textbox->SelectionColor = Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(226)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
            static_cast<System::Int32>(static_cast<System::Byte>(83)));
        textbox->SelectionFont = gcnew Font(L"Microsoft Sans Serif",
            System::Convert::ToInt32(Service::setts.getSizeOfFont()),
            System::Drawing::FontStyle::Regular);
    	
        list<string> categories = item.getCategories();

        string addingCategories = "";
    	
        for_each(categories.begin(),
            categories.end(),
            [&](string category) {
                addingCategories += "#" + category + " ";
            }
        );
    	
        String^ strCategories = gcnew String(addingCategories.c_str());
    	
        textbox->AppendText(strCategories);
    	
        delete strCategories;
    	
        textbox->AppendText("\n\n");
    	
        ++begin;
        }
}

void Service::filterByCategory(String^ category)
{
    category = category->ToLower();
    string needCategory = msclr::interop::marshal_as<std::string>(category);
	
    list<Item> NEWS = Service::cache.NEWS;

    list<Item> NEWSByCategory;
	
    for_each(NEWS.begin(), NEWS.end(),
        [&](const Item item) {
            list <string> categories = item.getCategories();

            auto iter_find = find_if(categories.begin(), categories.end(),
                [&](const string categoryFrom)
                { return categoryFrom.find(needCategory) != -1; });

            if (iter_find != categories.end())
                NEWSByCategory.push_back(item);
        });

    Service::IndexPage = Page(NEWSByCategory);
    
    Service::updateSettings();
}

void Service::backToIndex()
{
    Service::IndexPage = Service::cache;
    Service::updateSettings();
}

void Service::pagePrevious()
{
    if (IndexPage.currentPage == 1)
        return;
    IndexPage.currentPage--;
}

void Service::pageNext()
{
    if (IndexPage.currentPage >= IndexPage.pages)
        return;
    IndexPage.currentPage++;
}

void Service::setNumNewsOnPage(int num)
{
    Service::setts.setNumNewsOnPage(num);
}

void Service::setSizeFont(int num)
{
    Service::setts.setSizeOfFont(num);
}

void Service::deleteRSSes(System::Windows::Forms::CheckedListBox^ box)
{
    auto collect = box->CheckedItems;
	
    for (int i=0; i<collect->Count; i++)
    {
        Service::RSSes.deleteRSS(msclr::interop::marshal_as<std::string>(collect[i]->ToString()));
    }
	
    delete collect;
}

void Service::addRSS(String^ RSS)
{
    Service::RSSes.addRSS(msclr::interop::marshal_as<std::string>(RSS));
}
