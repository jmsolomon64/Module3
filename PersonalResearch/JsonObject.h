#include <string>
#include <unordered_map>
#include <stdexcept>
#include <vector>
#include <iostream>

enum JSON_DATA_TYPE {
    STRING,
    NUMERIC,
    DATE,
    OBJECT
};

struct JsonValue {
    std::string name;
    JSON_DATA_TYPE type;
    std::string value;  
};

class JsonObject {
    public:
        JsonObject(std::string key = "");
        std::string key;
        std::vector<JsonValue> GetValues();
        JsonValue GetValue(std::string key);
        std::vector<JsonObject> GetObjectValues();
        JsonObject GetObjectValue(std::string key);
        void SetValue(std::string key, JSON_DATA_TYPE type, std::string value);
        void SetValue(JsonValue value);
        void SetValue(std::string key,JsonObject object);
        void Print();
    private:
        std::unordered_map<std::string, JsonValue> values;
        std::unordered_map<std::string, JsonObject> objects;
        void static PrintKey(std::string key);
        void static Print(JsonValue val);
        void static Print(JsonObject obj);
};