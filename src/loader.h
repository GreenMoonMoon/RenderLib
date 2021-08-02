//
// Created by jboisvert on 2021-07-21.
//

#ifndef RENDERLIB_LOADER_H
#define RENDERLIB_LOADER_H

#include <iostream>
#include <fstream>
#include <string>

#include "dependencies/cgltf.h"

class Mesh;

class Loader {
public:
    ~Loader();

    void Load(Mesh &mesh, const std::string filePath);
};
#endif //RENDERLIB_LOADER_H
