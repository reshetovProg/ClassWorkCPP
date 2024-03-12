#include "PathControl.h"

void VersionController::recursive_copy(std::string from, std::string to) {
	for (const auto& entry : fs::directory_iterator(from)) {
		if (entry.path().string() != from + "\\.misha") {
			if (entry.is_directory()) {
				fs::create_directory(to + "\\" + entry.path().filename().string());
				recursive_copy(from + "\\" + entry.path().filename().string(), to + "\\" + entry.path().filename().string());
			}
			else {
				fs::copy(entry.path(), to, fs::copy_options::update_existing);
			}
		}
		fs::remove(root_path + "\\~version.json");
	}
}

void VersionController::recursive_delete(std::string path)
{
	for (const auto& entry : fs::directory_iterator(path)) {
		if (entry.path().string() != path + "\\.misha") {
			if (entry.is_directory()) {
				recursive_delete(path + "\\" + entry.path().filename().string());
			}
			else {
				fs::remove(entry.path().string());
			}
		}
	}
}

VersionController::VersionController(const VersionController& v)
{
	count = v.count;
	root_path = v.root_path;
	for (auto i : v.vers) {
		vers.emplace(i.first, i.second);
	}
}

VersionController::VersionController(std::string root_path)
{
	if (!fs::exists(root_path)) { throw "path isn't exists"; }
	bool flag = 0;
	for (const auto& entry : fs::directory_iterator(root_path)) {
		if (entry.path().filename().string() == ".misha") {
			flag = 1;
			break;
		}
	}

	if (flag) {
		Version* buf = new Version[0];
		for (const auto& entry : fs::directory_iterator(root_path + "\\.misha")) {
			count++;
			std::ifstream in{ entry.path().string() + "\\~version.json" };
			json j;
			in >> j;
			std::cout << j["name"] << " " << j["desc"] << " " << j["id"] << std::endl;
			in.close();
			buf = new Version(entry.path().string(), j["name"], j["desc"], j["id"]);
			vers.emplace(buf->id, buf);
		}
	}
	else {
		fs::create_directory(root_path + "\\.misha");
	}
	this->root_path = root_path;
}

std::string VersionController::getRootPath() { return root_path; }

void VersionController::createVersion(std::string name, std::string description) {
	Version* buf = new Version(root_path + "\\.misha\\" + std::to_string(count), name, description, count);
	fs::create_directory(buf->path);
	vers.emplace(count, buf);
	recursive_copy(root_path, buf->path);
	buf->createVersion();
	count++;
}

std::map<int, Version*> VersionController::getVersions() { return vers; }

void VersionController::returnToVersion(int id)
{
	recursive_delete(root_path);
	recursive_copy(vers[id]->path, root_path);
}

bool VersionController::versionExists(int id)
{
	return vers[id] != nullptr;
}

Version::Version() { }

Version::Version(std::string path, std::string name, std::string description, int id) { this->path = path; this->name = name; this->description = description; this->id = id; }

void Version::createVersion()
{
	std::ofstream out{ path + "\\~version.json" };
	json j;
	j["name"] = name;
	j["desc"] = description;
	j["id"] = id;
	out << j;
	out.close();
}

std::string Version::getName() { return name; }

std::string Version::getDescription() { return description; }

int Version::getID()
{
	return id;
}
