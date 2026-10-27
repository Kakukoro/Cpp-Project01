#include "Sequence.h"

#include <fstream>
#include <iostream>

Sequence::Sequence(std::string id, std::string description, std::string residues)
    : id_(std::move(id)),
      description_(std::move(description)),
      residues_(std::move(residues)) {}

std::vector<Sequence> Sequence::readAllFasta(const std::string& path) {
    std::vector<Sequence> result;
    std::ifstream in(path);
    if (!in) {
        std::cerr << "Cannot open file: " << path << "\n";
        return result;
    }

    std::string line, id, desc, residues;
    bool haveRecord = false;

    auto flush = [&]() {
        if (haveRecord) result.emplace_back(id, desc, residues);
        id.clear(); desc.clear(); residues.clear();
    };

    while (std::getline(in, line)) {
        if (!line.empty() && line.back() == 0x0D) line.pop_back();  // Windows line endings
        if (line.empty()) continue;

        if (line[0] == 0x3E) { // ">"
            flush();
            haveRecord = true;
            std::string header = line.substr(1);
            auto space = header.find(" ");
            id = header.substr(0, space);
            desc = (space == std::string::npos) ? "" : header.substr(space + 1);
        } else {
            residues += line;
        }
    }
    flush();
    return result;
}

bool Sequence::readFasta(const std::string& path) {
    auto all = readAllFasta(path);
    if (all.empty()) return false;
    *this = all.front();
    return true;
}

void Sequence::print() const {
    std::cout << ">" << id_ << " " << description_ << "\n"
              << residues_ << "\n(length: " << length() << ")\n";
}
