#include "./JsonIO.h"

JsonIO::JsonIO() : filePath("HelloWorld.txt") {}

JsonIO::JsonIO(std::string path) {
    this->filePath = path;
}

JsonObject JsonIO::ReadFile() {
    std::ifstream file(this->filePath);
    std::vector<std::string> lines;
    std::string line;
    int index;
    JsonObject object;
    
    if(!file.is_open()) {
        std::cerr << "Error: Cannot openfile to read \n";
        return object;
    }

    while(std::getline(file, line))
        lines.push_back(line);  
    
    JsonParser parser(lines);

    object = parser.Parse(index);
    file.close();
    return object;
}

int JsonIO::WriteFile(std::string contents) {
    std::ofstream file(this->filePath); //attempts to open file for writing
    if(!file.is_open()) {
        std::cerr << "Error: Cannot open file to write \n";
        return 0;
    }

    file << contents;

    file.close(); // Good practice to make sure to close file
    return 1;
}

int main(int argc, char** argv) {
    std::cout << "arg count: " << argc;

    JsonIO test;
    test.WriteFile("{\n\"test\": \"Hello World\" \n}");

    JsonIO test1("test.json");
    JsonObject contents = test1.ReadFile();
    contents.Print();
    return 0;
}