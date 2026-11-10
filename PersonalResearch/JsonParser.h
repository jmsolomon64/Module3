#include <string>
#include <unordered_map>
#include <vector>
#include "./JsonObject.h"


class JsonParser {
    public:
        JsonParser();
        JsonParser(std::string contents);
        JsonParser(std::vector<std::string> lines);
        JsonObject Parse(int &index);
    private:
        std::string contents;
        void CombineLines(std::vector<std::string> &lines);
        void RemoveWhiteSpace();
        std::string ParseString(int &index);
};