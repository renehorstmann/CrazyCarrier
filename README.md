# CrazyCarries

A game in which you have to manually control a conveyor.

An SDL2 OpenGL game written in C, also working on Web and Android. Based on [some](https://github.com/renehorstmann/some) framework.

## Compiling for Web

Using Emscripten:

```sh
mkdir web && cd web

emcc -I../include/ -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s USE_SDL_NET=2 -s FULL_ES3=1 -s SDL2_IMAGE_FORMATS='["png"]' --preload-file ../res -s ALLOW_MEMORY_GROWTH=1 -DOPTION_GLES -DOPTION_SDL -DOPTION_SOCKET ../src/e/*.c ../src/p/*.c ../src/r/*.c ../src/u/*.c ../src/*.c -o index.html
```

May / will not work on Apple, because of their poor WebGL2 support.

## Without Cmake

Instead of cmake, the following call to gcc should work, too.

```sh
mkdir build && cd build

cp -r ../res .

gcc ../src/e/*.c ../src/p/*.c ../src/r/*.c ../src/u/*.c ../src/*.c -I../include/ $(sdl2-config --cflags --libs) -lSDL2_image -lSDL2_net -lglew32 -lopengl32 -lglu32 -DOPTION_GLEW -DOPTION_SDL -DOPTION_SOCKET  -o crazycarrier
```

## Author

René Horstmann

## Licence

- The game and its assets are licenced under GPLv3, see LICENCE.
- The [some](https://github.com/renehorstmann/some) framework is licensed under the MIT License - see the someLICENSE file for details
