# CrazyCarries

A game in which you have to manually control a conveyor.

An SDL2 OpenGL game written in C, also working on Web and Android. Based on [some](https://github.com/renehorstmann/some) framework.

## Compiling for Web

Using Emscripten:

```sh
mkdir web && cd web
```

```sh
emcc -I../include/ -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s USE_SDL_NET=2 -s FULL_ES3=1 -s SDL2_IMAGE_FORMATS='["png"]' --preload-file ../res -s ALLOW_MEMORY_GROWTH=1 -s ASYNCIFY=1 -s EXIT_RUNTIME=1 -DOPTION_GLES -DOPTION_SDL -DOPTION_SOCKET ../src/e/*.c ../src/p/*.c ../src/r/*.c ../src/u/*.c ../src/*.c -o index.html
```

Add the following changes to the generated index.html:
```html
<style>
  #canvas {
    position: absolute;
    top: 0px;
    left: 0px;
    margin: 0px;
    width: 100%;
    height: 100%;
    overflow: hidden;
    display: block;
  }
</style>
<script>
    function set_exit_failure_error_msg() {
        var newContent = '<!DOCTYPE html><html><body style="background-color:black;"><h1 style="color:white;">Potato Browsers are not supported!</h1><p style="color:silver;">Full WebGL2.0 is needed!</p></body></html>';
        document.open();
        document.write(newContent);
        document.close();
    }
</script>
```
This will let Emscripten run in fullscreen and display an error text, if the app / game is not able to run (WebGL2.0 support missing)

## Without Cmake

Instead of cmake, the following call to gcc may work, too.

```sh
mkdir build && cd build

cp -r ../res .

gcc ../src/e/*.c ../src/p/*.c ../src/r/*.c ../src/u/*.c ../src/*.c -I../include/ $(sdl2-config --cflags --libs) -lSDL2_image -lSDL2_ttf -lSDL2_net -lglew32 -lopengl32 -lglu32 -DOPTION_GLEW -DOPTION_SDL -DOPTION_TTF -DOPTION_SOCKET -o crazycarrier
```

## Author

René Horstmann

## Licence

- The game and its assets are licenced under GPLv3, see LICENCE.
- The [some](https://github.com/renehorstmann/some) framework is licensed under the MIT License - see the someLICENSE file for details
