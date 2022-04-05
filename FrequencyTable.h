#include <map>
#include <string>
#include <iostream>
#include "priorityQueue.h"
using namespace std;

using FrequencyTable = map<char, int>;
FrequencyTable build_frequency_table(const string& text) {
    FrequencyTable table;

    for (int i = 0; i < text.length(); i++) {
        if (table.find(text[i]) != table.end()) {
            table.at(text[i]) += 1;
        } else {
            table.insert(pair<char,int>(text[i],1));
        }
    }
    return table;
}
