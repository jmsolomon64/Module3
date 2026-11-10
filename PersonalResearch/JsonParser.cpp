#include "./JsonParser.h"
#include <stdexcept>

JsonParser::JsonParser() {}

JsonParser::JsonParser(std::string contents) {
    this->contents = contents;
    RemoveWhiteSpace();
}

JsonParser::JsonParser(std::vector<std::string> lines) {
    this->CombineLines(lines);
    RemoveWhiteSpace();
}

JsonObject JsonParser::Parse(int &index) {
    if(index == 0 && this->contents[0] != '{') {
        throw std::runtime_error("File not formatted correctly");
    }

    JsonObject object;
    bool isKeyString = true;
    std::string key;
    JSON_DATA_TYPE type;
    while(index < this->contents.size()) {
        char current = this->contents.at(index);
        switch (current) {
            case '{':
                object.SetValue(key, Parse(index));
                break;
            case '"':
                if(isKeyString) key = this->ParseString(index);
                else object.SetValue(key, STRING, this->ParseString(index));
                break;
            case ':':
                isKeyString = false;
                break;
            case ',':
                isKeyString = true;
                break;
            case '}':
                return object;
            default:
                break;
        }
    }
    return object;
}

void JsonParser::CombineLines(std::vector<std::string> &lines) {
    for(std::string const line : lines) {
        this->contents += line;
    }
}

void JsonParser::RemoveWhiteSpace() {
    int index = 0;
    bool inString = false;
    while(index < this->contents.size()) {
        char current = this->contents.at(index);
        if(current == '"') 
            inString = !inString;
        else if (current == ' ' && !inString) 
            contents.erase(index, 1);
        index++;
    }
}

std::string JsonParser::ParseString(int &index) {
    if(this->contents.at(index) != '"') {
        throw std::runtime_error("String is not formatted properly");
    } 
    index++;

    std::string result;
    while(this->contents.at(index) != '"') {
        result += contents.at(index);
        index++;
    }
    return result;
}