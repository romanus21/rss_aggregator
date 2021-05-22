#pragma once

class settings {
private:
    static int numNewsOnPage;
    static int sizeOfFont;

    static void load();
    static void save();
public:
    settings();

    static void setNumNewsOnPage(int num);

    static int getNumNewsOnPage();

    static void setSizeOfFont(int num);

    static int getSizeOfFont();
};