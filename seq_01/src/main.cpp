#include <iostream>
#include "Sequence.h"

int main() {
    for (int i = 0; i < 3; ++i) {
        std::cout << "testing " << i << std::endl;
    }

    Sequence seq;
    if (seq.readFasta("data/example.fasta")) {
        seq.print();
    } else {
        std::cerr << "Could not read FASTA file\n";
        return 1;
    }
    return 0;
}
