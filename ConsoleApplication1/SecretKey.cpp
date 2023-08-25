#include "SecretKey.h"
#include <string>
#include <iostream>

using namespace std;

string secret_key::decode_message(const string& key, const string& message)
{
    string new_key;
    string result;
    for (const char i : key)
    {
        if(std::isblank(i)) continue;
        if(new_key.find(i) == std::string::npos) continue;
        new_key += i;
    }

    for (const char i : message)
    {
        if(std::isblank(i)) continue;
        result += new_key.find(i) + 'a';
    }
    return result;
}

