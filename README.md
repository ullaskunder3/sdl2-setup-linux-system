# sdl2-setup-linux-system

## Automate the step of running the output file

### This tasks.json file defines two tasks: Build C++ program with SDL2 and Run C++ program with SDL2

`Build C++ program with SDL2` is a `cppbuild` task which uses the `g++ compiler` to build the C++ program. It takes the following arguments:

- `-g` specifies to include debugging information in the binary
- `-o` specifies the output file path, which is build/${fileBasenameNoExtension}.out. ${fileBasenameNoExtension} is the name of the current file being built (without its extension).
- `${file}` specifies the path of the current file being built.
- `sdl2-config --cflags --libs` includes the compiler flags and linker flags needed for the SDL2 library.
- `"cwd": "${fileDirname}"` sets the current working directory to the directory of the current file being built.

The group option specifies that this task is a build task and is the default task for this project.

The `Run C++ program with SDL2` task is a `shell` task which runs the binary built by the `Build C++ program with SDL2` task. It takes the following arguments:

- `${workspaceFolder}/build/${fileBasenameNoExtension}.out` specifies the path of the binary file to run.
- The `group` option specifies that this task is a test task and is the default task for this group.
- The `dependsOn` option specifies that this task depends on the `Build C++` program with SDL2 task, meaning that the build task will always be executed before the run task.

So when you run the `Run C++ program with SDL2` task, it will first build the C++ program using the `Build C++ program with SDL2` task, and then run the built binary using the `shell` task.
