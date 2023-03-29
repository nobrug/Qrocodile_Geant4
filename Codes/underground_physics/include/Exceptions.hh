#pragma once

// CADMesh //
#include "FileTypes.hh"

// GEANT4 //
#include "globals.hh"


namespace CADMesh
{

namespace Exceptions
{


void FileNotFound(G4String origin, G4String filepath);

void LexerError(G4String origin, G4String message);

void ParserError(G4String origin, G4String message);

void ReaderCantReadError(G4String origin, File::Type file_type, G4String filepath);

void MeshNotFound(G4String origin, size_t index);
void MeshNotFound(G4String origin, G4String name);

} // Exceptions namespace

} // CADMesh namespace
