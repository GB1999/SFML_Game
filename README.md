# Overview
This game makes use of SFML (Simple and Fast Multimedia Library) to draw objects to the screen each frame. It also uses vectors, casting, recursion, and graphs to incorporate each game object.
#Goals
As the player, your goal is to reach the dungeon exit without dying.
You will encounter random enemies in each room of the dungeon with varying properties such as health and damage inflicted. 
Points are awarded by killing enemies.
#Controls
The keyboard is used to navigate the player around the dungeon. The keybindings are:
### W- Move Up
### A- Move Left
### S- Move Down
### D- Move Right
### Space- Shoot Projectile

# HUD
There is a simple heads up display implemented to help you explore the dungeon.
Score is displayed at the upper righthand corner. The top 5 highest scores are displayed at the end of each round.
The green bar indicates health. The game will end if it is depleted
Direction tells you the best exit to take with respect to the finish.

# Contents
### Animation
### Collider
### Projectile
### Player
### Enemies
### Rooms
### Map




# Animation
The animation class takes in a Texture * texture, an unsigned int vector imageCount, and a float switchTime. The parameter texture points to an image loaded in the main.cpp from a specified file path. It contains every frame for each alternate animation. imageCount holds the number frames (imageCount.x) per number of alternative animations (imageCount.y). switchTime dictates the time difference in seconds (deltaTime) between each frame.
In the player animation for example, the texture object is divided into 9 animations with 12 frames each.
![Texture Example](https://i.imgur.com/EPj14YS.png)

*Disclaimer: This class is based heavily on the one described by Hilze Vonck in his tutorial series SFML 2.4 For Beginners*

