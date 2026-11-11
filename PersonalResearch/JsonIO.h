#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "./JsonParser.h"


class JsonIO {
    public:
        JsonIO();
        JsonIO(std::string path);
        JsonObject ReadFile();
        int WriteFile(std::string contents);
    private:
        std::string filePath;
};
