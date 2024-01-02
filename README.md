# Learn OpenGL Again in 2024
I think I've done this every year and I always say I'll complete it but I never do.
Regardless, here it goes again.

To clone the project, do the following:
```
git clone git@github.com:facuevas/LearnOpenGL2024.git
git submodule update --init --recursive # We build glfw from source
```

To build the project terminal, run the following:
```
mkdir build
cd build
cmake ..
cmake --build . --target LearnOpenGL2024
```

To run, you can do the following (assuming you are still in the build directory):
```
.\Debug\LearnOpenGL2024.exe # (or without .exe if not on Windows)
```