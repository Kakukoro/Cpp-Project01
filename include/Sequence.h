#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <string>
#include <vector>

class Sequence {
public:
    Sequence() = default;
    Sequence(std::string id, std::string description, std::string residues);

    // Getters
    const std::string& id() const { return id_; }
    const std::string& description() const { return description_; }
    const std::string& residues() const { return residues_; }
    std::size_t length() const { return residues_.size(); }

    bool readFasta(const std::string& path);

    // Reads all.
    static std::vector<Sequence> readAllFasta(const std::string& path);

    void print() const;

private:
    std::string id_;
    std::string description_;
    std::string residues_;
};

#endif
