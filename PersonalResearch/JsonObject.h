#include <string>
#include <unordered_map>
#include <stdexcept>


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
        JsonValue GetValue(std::string key);
        JsonObject GetObjectValue(std::string key);
        void SetValue(std::string key, JSON_DATA_TYPE type, std::string value);
        void SetValue(JsonValue value);
        void SetValue(std::string key,JsonObject object);
    private:
        std::unordered_map<std::string, JsonValue> values;
        std::unordered_map<std::string, JsonObject> objects;
};