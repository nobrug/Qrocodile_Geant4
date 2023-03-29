#pragma once

// GEANT4 //
#include "G4String.hh"

// STL //
#include <map>
#include <algorithm>


namespace CADMesh
{

namespace File
{

enum Type
{
    Unknown,
    PLY,
    STL,
    DAE,
    OBJ,
    TET,
    OFF,
}; 


static std::map<Type, G4String> Extension = {
    { Unknown, "unknown" },
    { PLY, "ply" },
    { STL, "stl" },
    { DAE, "dae" },
    { OBJ, "obj" },
    { TET, "tet" },
    { OFF, "off" }
};


static std::map<Type, G4String> TypeString = {
    { Unknown, "UNKNOWN" },
    { PLY, "PLY" },
    { STL, "STL" },
    { DAE, "DAE" },
    { OBJ, "OBJ" },
    { TET, "TET" },
    { OFF, "OFF" }
};


static std::map<Type, G4String> TypeName = {
    { Unknown, "Unknown File Format" },
    { PLY, "Stanford Triangle Format (PLY)" },
    { STL, "Stereolithography (STL)" },
    { DAE, "COLLADA (DAE)" },
    { OBJ, "Wavefront (OBJ)" },
    { TET, "TetGet (TET)" },
    { OFF, "Object File Format (OFF)" }
};


Type TypeFromExtension(G4String extension);
Type TypeFromName(G4String name);

}

} // CADMesh namespace
