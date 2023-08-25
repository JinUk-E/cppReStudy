#pragma once
#include <string>
#include <iostream>

using namespace std;

class secret_key
{
public:
    string decode_message(const string& key, const string& message);
    
};
