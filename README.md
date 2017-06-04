# RT (Raytracer Engine & Renderer)

This raytracer is a program developed for my learning course at 42 school (Paris).<br />
The objective is to recreate from scratch a raytracer engine & renderer with a strong interface.<br />
<img align="center" src="http://i.imgur.com/nJ0HpUM.png" width="100%" />
<br />
Project created on pure C with SDL (SDL2, SDL2_ttf & SDL2_image) & OpenCL.<br />
List of options available :
* Add / Delete elements (Cameras, Lights & Shapes)
* Outliner (Navigate between elements)
* Edit elements settings (Cameras, Lights & Shapes)
* Save current scene file (.rt)
* Export image of the renderer (.png)
* Set preset on shapes (Earth, Sun, Moon & Jupiter) 
* Add special effect on rendered image (Cartoon, Reverse, Sobel Effect, Grey, Sepia, Saturate & Pixel Art)
* Add Skybox (Day & Night)
* Anti-Aliasing with clustering (render the image on multiple computers)
* Add Shaders on shapes (Perlin Noise, Wood, Marble (x7))
* Edit colors of shaders

## Install & launch

### Install it

```bash
git clone https://github.com/BenjaminSouchet/RT.git ~/RT
cd ~/RT
make
```

### Start a scene

```
./rt scenes/{SCENE}.rt
```
{SCENE} : The scene you want to open (located in folder 'scenes')<br />
Example ⇣
```bash
./rt scenes/Solar_system.rt
```

## Contact & Copyright

Project done with [Lionel GATIBELZA](https://github.com/lgatibel) & [Erwan RODRIGUES](https://github.com/nawrou)
If you want to contact me, just send me a mail at **bsouchet@student.42.fr**
