//
// Created by jboisvert on 2021-07-21.
//
#include "loader.h"

void Loader::Load(Mesh &mesh, const std::string filePath) {
    std::ifstream inf{filePath};

    if (!inf) {
        std::cerr << "Cannot load file: " << filePath << std::endl;
        return;
    }

    //debug
    while (inf) {
        std::string input;
        std::getline(inf, input);
        std::cout << input << '\n';
    }
}

Loader::~Loader() {

}