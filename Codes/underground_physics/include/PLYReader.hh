#pragma once

// CADMesh//
#include "Reader.hh"
#include "Lexer.hh"
#include "LexerMacros.hh"

// GEANT4 //
#include "globals.hh"


namespace CADMesh
{

namespace File
{

CADMeshLexerToken(Header);
CADMeshLexerToken(Element);
CADMeshLexerToken(Property);

class PLYReader : public Reader
{
  public:
    PLYReader() : Reader("PLYReader") { };
  
    G4bool Read(G4String filepath);
    G4bool CanRead(Type file_type);

  protected:
    //Lexer.
    CADMeshLexerStateDefinition(StartHeader);
    CADMeshLexerStateDefinition(EndHeader);

    CADMeshLexerStateDefinition(Element);
    CADMeshLexerStateDefinition(Property);
    CADMeshLexerStateDefinition(Ignore);
 
    CADMeshLexerStateDefinition(Vertex);
    CADMeshLexerStateDefinition(Facet);

    // Parser. 
    void ParseHeader(Items items);

    std::shared_ptr<Mesh> ParseMesh(Items vertex_items, Items face_items);
    G4ThreeVector ParseVertex(Items items);
    G4TriangularFacet* ParseFacet(Items items, Points vertices);

    size_t vertex_count_ = 0;
    size_t facet_count_ = 0;

    size_t x_index_ = 0;
    size_t y_index_ = 0;
    size_t z_index_ = 0;

    size_t facet_index_ = 0;    
};

} // File namespace

} // CADMesh namespace

