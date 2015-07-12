#pragma once

#include "ofMain.h"

namespace ofx 
{ 
    namespace BinaryMesh 
    {
        void save(const string& path, const ofMesh& mesh);
        bool load(const string& path, ofMesh& mesh);
    }
}

namespace ofxBinaryMesh = ofx::BinaryMesh;
