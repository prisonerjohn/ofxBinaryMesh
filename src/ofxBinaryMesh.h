#pragma once

#include "ofMain.h"

namespace ofx 
{ 
    namespace BinaryMesh 
    {
        void save(const std::filesystem::path & path, const ofMesh & mesh);
        bool load(const std::filesystem::path & path, ofMesh & mesh);
    }
}

namespace ofxBinaryMesh = ofx::BinaryMesh;
