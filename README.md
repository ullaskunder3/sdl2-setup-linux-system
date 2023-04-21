# Sdl2-setup-linux-system

## Installation

To install SDL2 in Fedora, you can use the following command in your terminal:

```bash
sudo dnf install SDL2-devel

```

## Automate the step of running the output file

![runtask](https://user-images.githubusercontent.com/66258652/233619662-18faddd7-dc3e-4142-bf01-5534c2f2ec05.png)
![command](https://user-images.githubusercontent.com/66258652/233619933-dc1c7788-ca11-4aa1-bb2b-ae5b7c2ca364.png)
![Screenshot from 2023-04-21 16-25-34](https://user-images.githubusercontent.com/66258652/233619968-9344274d-90c8-4293-8baf-5c5ca9e8def7.png)

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
