Geant4 Code for Qrocodile collaboration

///////////////////////////////////////////////////

Updated version of underground_physics code to compile CAD drawings and use them as geometries. If downloaded to your own machine, make sure the
source file is updated accordingly, or runned in the correct folder. Folder "underground_physics* contains all needed files to run it successfully. 
Find the original code at
/app/cern/geant_4.10.06.02/share/Geant4-10.6.2/examples/advanced/underground_physics

///////////////////////////////////////////////////

Needed version of Geant4: 4.10.06.02
In DMX.cc change FILE.STL to desired file, possible are: .STL, .OBJ, .STEP
Make sure you sourced geant4make.sh
To compile, cd into underground_physics, use cmake -B build && cmake --build build
cd into build, press ./DMX
