//
// Created by jboisvert on 2021-07-21.
//
#include "loader.h"

void Loader::Load(Mesh &mesh, const std::string filePath) {
    cgltf_options cgltfOptions;
    cgltf_data* cgltfData = nullptr;
    cgltf_result cgltfResult = cgltf_parse_file(&cgltfOptions, filePath.c_str(), &cgltfData);
    if(cgltfResult == cgltf_result_success) {


        cgltf_free(cgltfData);
    }
}