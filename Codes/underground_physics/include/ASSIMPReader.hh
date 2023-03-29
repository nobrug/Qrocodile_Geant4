#pragma once

#ifdef USE_CADMESH_ASSIMP_READER

// CADMesh //
#include "Reader.hh"

// Open Asset Importer Library //
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"


namespace CADMesh
{

namespace File
{

class ASSIMPReader : public File::Reader
{
  public:
    ASSIMPReader();
    ~ASSIMPReader();

  public:
    G4bool Read(G4String filepath);
    G4bool CanRead(Type file_type);

  private:
    Assimp::Importer* importer_;
};

std::shared_ptr<ASSIMPReader> ASSIMP();

} // File namespace

} // CADMesh namespace

#endif
