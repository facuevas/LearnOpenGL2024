# Learn OpenGL Again in 2024
I think I've done this every year and I always say I'll complete it but I never do.
Regardless, here it goes again.

To clone the project, do the following:
```
git clone git@github.com:facuevas/LearnOpenGL2024.git
git submodule update --init --recursive # We build glfw from source
```

To build with project, run the following commands on terminal in the root folder:
```
cmake -S . -B build
cmake --build build
```
To run the application, run this command in the root folder:
```
build/LearnOpenGL2024
```