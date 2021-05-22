#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "curl/curl.h"
using namespace std;

static char errorBuffer[CURL_ERROR_SIZE];

static string buffer;

string load_xml(string url);