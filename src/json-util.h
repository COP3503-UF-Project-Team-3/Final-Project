#ifndef JSON_UTIL_H
#define JSON_UTIL_H
/*
 *	JSON utility methods
 *	Made by: Adam
 */
#include "json.hpp"
#include <string>

using JSON = nlohmann::json;

/*
 *	Returns json from a pure text file if formatted properly
 *	Throws	
 */
JSON jsonFromFile(std::string path);

/*
 *	Returns true on success
 */
bool writeJSON(JSON obj, std::string path);

#endif