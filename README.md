# Qrocodile-MC

Geant4 simulation code for Qrocodile.

This is an adaptation of the underground_physics example distributed by Geant4. 

## Supported GEANT4 versions

The code has been tested in the farm system of the institute. It was compiled with cmake 3.20.04 against
the libraries of the Geant4-10.06-02 version.

## Build instructions

1. Download the code from the repo:
```
git clone git@github.com:Physik-Institut-UZH/Qrocodile-MC.git
```

2. After that, the Geant4 variables and paths have to be set. To do so, there is a couple of scripts in the install directory
of Geant4 that must be executed. It is recommended to set an alias in your .bashrc file and therefore you don't have
to type the same command again and again. For example, you can set the alias:
```
alias setG4="source /app/cern/geant_4.10.06.02/bin/geant4.sh && source /app/cern/geant_4.10.06.02/share/Geant4-10.6.2/geant4make/geant4make.sh"
```

Now go to the folder of the code and set the G4WORKDIR variable:

    export G4WORKDIR=$PWD

With this, Geant4 will use this location as base for the compilation (otherwise you would find the executables somewhere else in your home directory).

For the analysis, ROOT must be also set:

    source /app/cern/root_v6.14.00/bin/thisroot.sh

where in this case we have used the v6.14.00. If you want to use other version explore the /app/cern folder and give the correct path to the script.

3. Compile the code using cmake. In the folder of the code, run:
```
cmake -B build && cmake --build build
```
(you can add -j at the end if it is too slow)

This will create a build folder where cmake will put the executables and other compilation objects. After the compilation is finished, the executable
QROCODILE is created in build. The CMakeList.txt can be modified if you don't like the name.  

4. Run:
```
./build/QROCODILE
```

In this case, the geometry should pop-up. If not, probably you have to set and configure the x-server. The code can be also run over a macro.

## Overview and TODOS

1. The names of the classes were modified to include the name of the experiment. It is very common to start the name of the definitions with this name.
In this case, it was used just "Qroco" because otherwise names would be too long.

2. The original geometry of the underground_physics example was removed; but the implementation of the room components is kept (windows, tables, etc) just
to see it as an example. 

3. CADMesh was placed in the DetectorConstruction class https://github.com/Physik-Institut-UZH/Qrocodile-MC/blob/22714e4dd5384ece9b97c6b98a7428f53173c122/src/QrocoDetectorConstruction.cc#L129 and it should be in that class. It is not necessary to compile CADMesh since it is distributed as a header.
The only thing to do is to include it in the class. After that, the logical and physical volumes have to be defined as usual.

4. Commands in the messenger classes have to be modified (it was done only in the DetectorMessenger, just to show an example of how to do it).

5. Check the STL file; if it is in ASCII or in other format and then be consistent with that. CADMesh works with other files too. 

6. The implementation of CRY generator has to be done in the ParticleSource class. 

7. The classes that define the photosensors and the sensitive volumes are kept just as an example of how to do this in the future (if needed).

8. For reference, also the README files from the underground_physics are kept.
