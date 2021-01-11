#include "ofxBinaryMesh.h"

namespace ofx 
{ 
    namespace BinaryMesh 
    {
        //--------------------------------------------------------------
        void save(const std::filesystem::path & path, const ofMesh & mesh)
        {
            ofFile file(path, ofFile::WriteOnly, true);

            int numVerts = mesh.getNumVertices();
            file.write((char *)(&numVerts), sizeof(int));
            if (numVerts > 0) {
                file.write((char *)(&(mesh.getVertices())[0]), sizeof(ofPoint) * numVerts);
            }

            int numNormals = mesh.getNumNormals();
            file.write((char *)(&numNormals), sizeof(int));
            if (numNormals > 0) {
                file.write((char *)(&(mesh.getNormals())[0]), sizeof(ofPoint) * numNormals);
            }

            int numTexCoords = mesh.getNumTexCoords();
            file.write((char *)(&numTexCoords), sizeof(int));
            if (numTexCoords > 0) {
                file.write((char *)(&(mesh.getTexCoords())[0]), sizeof(ofVec2f) * numTexCoords);
            }

            int numColors = mesh.getNumColors();
            file.write((char *)(&numColors), sizeof(int));
            if (numColors > 0) {
                file.write((char *)(&(mesh.getColors())[0]), sizeof(ofFloatColor) * numColors);
            }

            int numIndices = mesh.getNumIndices();
            file.write((char *)(&numIndices), sizeof(int));
            if (numIndices > 0) {
                file.write((char *)(&(mesh.getIndices())[0]), sizeof(ofIndexType) * numIndices);
            }

            file.close();
        }

        //--------------------------------------------------------------
        bool load(const std::filesystem::path & path, ofMesh & mesh)
        {
            ofFile file(path, ofFile::ReadOnly, true);
            if (!file.exists()) {
                ofLogError("ofxBinaryMesh::load") << "Cannot open file at " << path;
                return false;
            }

            mesh.clear();

            int numVerts = 0;
            file.read((char *)(&numVerts), sizeof(int));
            if (numVerts > 0) {
                mesh.getVertices().resize(numVerts);
                file.read((char *)(&(mesh.getVertices())[0]), sizeof(ofPoint) * numVerts);
            }

            int numNormals = 0;
            file.read((char *)(&numNormals), sizeof(int));
            if (numNormals > 0) {
                mesh.getNormals().resize(numNormals);
                file.read((char *)(&(mesh.getNormals())[0]), sizeof(ofPoint) * numNormals);
            }

            int numTexCoords = 0;
            file.read((char *)(&numTexCoords), sizeof(int));
            if (numTexCoords > 0) {
                mesh.getTexCoords().resize(numTexCoords);
                file.read((char *)(&(mesh.getTexCoords())[0]), sizeof(ofVec2f) * numTexCoords);
            }

            int numColors = 0;
            file.read((char *)(&numColors), sizeof(int));
            if (numColors > 0) {
                mesh.getColors().resize(numColors);
                file.read((char *)(&(mesh.getColors())[0]), sizeof(ofFloatColor) * numColors);
            }

            int numIndices = 0;
            file.read((char *)(&numIndices), sizeof(int));
            if (numIndices > 0) {
                mesh.getIndices().resize(numIndices);
                file.read((char *)(&(mesh.getIndices())[0]), sizeof(ofIndexType) * numIndices);
            }

            file.close();

			return true;
        }
    }
}
