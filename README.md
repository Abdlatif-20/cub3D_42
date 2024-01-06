# cub3d

This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use of basic algorithms, information research etc. As a graphic design project, cub3D will enable you to improve your skills in these areas: windows, colors, events, fill shapes, etc. To conclude cub3D is a remarkable playground to explore the playful practical applications of mathematics without having to understand the specifics. With the help of the numerous documents available on the internet, you will use mathematics as a tool to create elegant and efficient algorithms.

In summary The goal of ``cub3d`` is to make *something* using raycasting (like [Wolfenstein 3D](https://fr.wikipedia.org/wiki/Wolfenstein_3D)).

<img align="center" src="Screen 1.png" alt="Screenshot of the game" />


<img align="center" src="Screen 2.png" alt="Screenshot of the game" />

* WASD to move, QE or Left/Right directional keys to rotate camera
* use mouse to rotate angle of player and see down and up. 
* ESC to quit
* Textures or colors for each sides (North, South, West, East) and Sky/Floor
* Shadows based on the distance
* knif
* weapon
* Minimap

## Usage
The program can be build with a simple make to make a mandatory part inside Mandatory folder

And make bonus to make a bonus part inside Bonus folder

You can run the program with use `./cub3D<map>` Or `./cub3D_bonus <map>`

## DDA algorithm
The DDA-line algorithm rasterizes the line segment between two specified points using calculations in floating-point numbers or integers.  
Let the segment be defined by the real coordinates of the ends (x1, y1), (x2, y2). The raster (integer) coordinates of the endpoints are rounded values of the source coordinates: x_start =round (X1), y_start = round(Y1), x_end = round(x2), and y_end = round(Y2).  

A larger absolute number, (x_end - x_start) or (y_end - y_start), increased by 1 L of the rasterization cycle.  

At the beginning of the cycle the auxiliary real variables x and g are assigned the initial coordinates of the beginning of the segment: x = x1, y = y1. at each step of the loop, these real variables get increments (x_end - x_start) / L, (y_end - y_start) / L. The raster coordinates produced at each step are the result of rounding the corresponding real values x and y.  

The use of calculations with real numbers and only a single use of rounding to finally obtain the value of the raster coordinate results in high accuracy and low performance of the algorithm.  


## Ressources

* [Playable Wolfenstein 3D](http://users.atw.hu/wolf3d/)
* [Raycasting in JS](http://www.playfuljs.com/a-first-person-engine-in-265-lines/)
* [Some X11 event numbers](https://github.com/qst0/ft_libgfx)
* [Full tutorial in English](https://lodev.org/cgtutor/raycasting.html)
* [Full tutorial in French (translation of the English tutorial)](http://forums.mediabox.fr/wiki/tutoriaux/flashplatform/affichage/3d/raycasting)
* [Images in minilibx](https://github.com/keuhdall/images_example)
* [BMP format on StackOverflow](https://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries)
* [BMP format explanation](https://web.archive.org/web/20080912171714/http://www.fortunecity.com/skyscraper/windows/364/bmpffrmt.html)
