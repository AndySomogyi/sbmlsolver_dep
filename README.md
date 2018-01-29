SBMLSolver Dependencies
=======================

This project holds most of the dependencies, including llvm needed to build the
SBMLSolver

Due to an incompatiblity between llvm and libSBML, we do not support building both
as subprojects. Therefore, you need to build the llvm project separatly


Instructions
------------

1. Clone this git repository, reccomended to clone it to ```$HOME/src/sbmlsolver_dep```

2. Decide on a location where these should be installed, it is reccomended that you
   create a ```$HOME/local``` directory hierarchy, with $HOME/local/bin, $HOME/local/include and
   $HOME/local/lib. You will then use ```$HOME/local``` as the install prefix. Remember this
   $HOME/local, you will use this as the ```SBMLSOLVER_DEP_DIR``` CCMake option when
   you build the sbmlsolver library. 

3. Create build directories for both llvm and the other projects, go to ```$HOME/src```, and
   create ```llvm_build``` and ```sbmlsolver_dep_build``` directories.

4. First build llvm, go to ```$HOME/src/llvm-build```, and run

   ```
   ccmake -DCMAKE_INSTALL_PREFIX=$HOME/local ../sbmlsolver_dep/llvm-3.5.0.src
   ```

   This will run the ccmake text mode gui where you can choose the options. This
   shuld be fine, so leave it alone. Hit 'c' to congigure, then 'g' to generate

   Make and install the llvm project

   ```
   make -j8
   make install
   ```

5. Now build the other dependencies, go to $HOME/src/sbmlsolver_dep_build, and run

   ```
   ccmake -DCMAKE_INSTALL_PREFIX=$HOME/local ../sbmlsolver_dep
   ```

   The options I think should be fine, hit 'c' to configure, and 'g' to generate.
   Then make and install the project.

   ```
   make -j8
   make install
   ```
       





