#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <filesystem>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
namespace fs = std::filesystem;

class Version
{
	friend class VersionController;
	std::string path;
	std::string name;
	std::string description;
	int id;
public:
	Version();
	Version(std::string path, std::string name, std::string description, int id);
	void createVersion();
	std::string getName();
	std::string getDescription();
	int getID();
};

class VersionController {
	int count = 0;
	std::map<int, Version*> vers;
	std::string root_path;
	void recursive_copy(std::string from, std::string to);
	void recursive_delete(std::string path);
public:
	VersionController();
	VersionController(const VersionController& v);
	VersionController(std::string root_path);
	std::string getRootPath();
	void createVersion(std::string name, std::string description);
	std::map<int, Version*> getVersions();
	void returnToVersion(int id);
	bool versionExists(int id);
};

