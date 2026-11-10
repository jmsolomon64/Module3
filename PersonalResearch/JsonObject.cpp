#include "./JsonObject.h"
#include <string>

JsonValue JsonObject::GetValue(std::string key) {
    auto result = values.find(key);
    if(result == values.end()) {
        throw std::runtime_error("Json Key Missing");
    }
    return result->second;
}

JsonObject JsonObject::GetObjectValue(std::string key) {
    auto result = objects.find(key);
    if(result == objects.end()) {
        throw std::runtime_error("Json Key Missing");
    }
    return result->second;
}

void JsonObject::SetValue(std::string key, JSON_DATA_TYPE type, std::string value) {
    JsonValue json;
    json.name = key;
    json.type = type;
    json.value = value;
    values[key] = json;
} 

void JsonObject::SetValue(JsonValue value) {
    values[value.name] = value;
}

void JsonObject::SetValue(std::string key, JsonObject object) {
    objects[key] = object;
}