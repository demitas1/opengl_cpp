# A project to learn OpenGL/C++ programming

## set up environment

- Ubuntu 22.04

- install necessary packages

```
bash install.sh
```

- generate zip from [https://glad.dav1d.de/](https://glad.dav1d.de/)
  - C++ version >= 3.3
  - Profile == Core

- intall glad

```
cd glad
unzip glad.zip
sudo cp -R include/* /usr/include/
cp src/* ./
```

## build

```
make
```

or 

```
g++ src/hello.cpp glad/src/glad.c -ldl -lglfw -lGLEW -lGL -o build/hello
g++ src/ex1.cpp glad/src/glad.c -ldl -lglfw -lGLEW -lGL -o build/ex1
```

## run

```
cd bulid
./hello
```

## Copyright

- The program code is licensed under the MIT License.
