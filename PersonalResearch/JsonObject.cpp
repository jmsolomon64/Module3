#include "./JsonObject.h"

JsonObject::JsonObject(std::string key) {
    this->key = key;
}

std::vector<JsonValue> JsonObject::GetValues() {
    std::vector<JsonValue> values;
    auto i = this->values.begin();
    while(i != this->values.end()) {
        values.push_back(i->second);
        i++;
    }
    return values;
}

JsonValue JsonObject::GetValue(std::string key) {
    auto result = values.find(key);
    if(result == values.end()) {
        throw std::runtime_error("Json Key Missing");
    }
    return result->second;
}

std::vector<JsonObject> JsonObject::GetObjectValues() {
    std::vector<JsonObject> objects;
    auto i = this->objects.begin();
    while(i != this->objects.end()) {
        objects.push_back((i->second, i->first));
    }
    return objects;
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

void JsonObject::Print() {
    JsonObject::Print(*this);
}

void JsonObject::PrintKey(std::string key) {
    std::cout << '"' << key << "\" : ";
}

void JsonObject::Print(JsonValue val) {
    JsonObject::PrintKey(val.name);
    switch(val.type) {
        case STRING:
        case DATE:
            std::cout << '"' << val.value << "\",\n";
            break;
        case NUMERIC:
            std::cout << val.value << ",\n";
            break;
        default:
            break;
    }
}

void JsonObject::Print(JsonObject obj) {
    if(obj.key != "") PrintKey(obj.key);
    
    std::cout << "{\n";

    std::vector<JsonValue> values = obj.GetValues();
    for(auto const &value : values)
        JsonObject::Print(value);

    std::vector<JsonObject> objects = obj.GetObjectValues();
    for(auto const object : objects) 
        JsonObject::Print(object);
}