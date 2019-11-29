# fdf

Ce projet consiste à créer graphiquement la representation schématique (en “fils de fer” ou “wireframe” en anglais) d’un terrain en relief en reliant différents points (x, y, z) par des segments.
Dans le cadre de votre partie obligatoire, vous avez le droit d’utiliser les fonctions suivantes :
- open, read, write, close
- malloc, free
- perror, strerror
- exit
- Toutes les fonctions de la libmath(-lm et man 3 math)
Les coordonnées du terrain seront stockées dans un fichier passé enparamètre, dont voici un exemple :
```
$>cat 42.fdf
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```


# Bonus Features :
* Real 3d navigation with rotations matrices and mesh projection into free movement camera (WASD shift ctrl space and mouse)
* Z-buffer (https://fr.wikipedia.org/wiki/Z-buffer)
* Clipping (https://fr.wikipedia.org/wiki/Clipping_(infographie))
* Really fluid
* Fps counter

# Screenshot
![Alt text](/screenshoots/1.png?raw=true "Optional Title")
![Alt text](/screenshoots/2.png?raw=true "Optional Title")
![Alt text](/screenshoots/3.png?raw=true "Optional Title")
![Alt text](/screenshoots/4.png?raw=true "Optional Title")
![Alt text](/screenshoots/5.png?raw=true "Optional Title")
![Alt text](/screenshoots/6.png?raw=true "Optional Title")
![Alt text](/screenshoots/7.png?raw=true "Optional Title")
