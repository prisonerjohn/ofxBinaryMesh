#include "ofxBinaryMesh.h"

namespace ofx 
{ 
    namespace BinaryMesh 
    {
        //--------------------------------------------------------------
        void save(const string& path, const ofMesh& mesh)
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
        bool load(const string& path, ofMesh& mesh)
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
                ofPoint * verts = new ofPoint[numVerts];
                file.read((char *)(&verts[0]), sizeof(ofPoint) * numVerts);
                mesh.addVertices(verts, numVerts);
                delete [] verts;
            }

            int numNormals = 0;
            file.read((char *)(&numNormals), sizeof(int));
            if (numNormals > 0) {
                ofPoint * normals = new ofPoint[numNormals];
                file.read((char *)(&normals[0]), sizeof(ofPoint) * numNormals);
                mesh.addNormals(normals, numNormals);
                delete [] normals;
            }

            int numTexCoords = 0;
            file.read((char *)(&numTexCoords), sizeof(int));
            if (numTexCoords > 0) {
                ofVec2f * texCoords = new ofVec2f[numTexCoords];
                file.read((char *)(&texCoords[0]), sizeof(ofVec2f) * numTexCoords);
                mesh.addTexCoords(texCoords, numTexCoords);
                delete [] texCoords;
            }

            int numColors = 0;
            file.read((char *)(&numColors), sizeof(int));
            if (numColors > 0) {
                ofFloatColor * colors = new ofFloatColor[numColors];
                file.read((char *)(&colors[0]), sizeof(ofFloatColor) * numColors);
                mesh.addColors(colors, numColors);
                delete [] colors;
            }

            int numIndices = 0;
            file.read((char *)(&numIndices), sizeof(int));
            if (numIndices > 0) {
                ofIndexType * indices = new ofIndexType[numIndices];
                file.read((char *)(&indices[0]), sizeof(ofIndexType) * numIndices);
                mesh.addIndices(indices, numIndices);
                delete [] indices;
            }

            file.close();
        }
    }
}
