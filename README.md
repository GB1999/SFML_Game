![Gameplay example](https://i.imgur.com/Xk8yNSd.png)
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

# Collider 
The collider class is a component of each object in the scene and allows the game to detect whether two objects are colliding. The collider class takes in a RectangleShape body by reference. RectangleShape is a SFML class that represents an area designated to a particular object in the scene. The checkCollider method of the Collider class takes in a collider of an opposing game object, other, and returns whether the two are overlapping. checkCollider also takes in int push, which dictates whether an object can push the other.
The checkCollider function effectively repels the other object, calculating the degree to which the parent collider is overlapping and moves the other object to that degree in the opposite direction.
![Collider Example](https://i.imgur.com/iNXIOav.png)

# Player
The player class takes in a float vector spawnPos, projectile projectile, and float speed. As the name suggests, spawnPos initializes the starting x (spawnPos.x) and y (spawnPos.y) position of the player. projectile passes a projectile class object that the player will use to shoot enemies.
The player class also has a series of if statements in its Update function to dictate the movement of the player and the respective animation for that movement.
![Player Example](https://i.imgur.com/wNAfuJ9.png)

# Enemies
Enemies are very similar to the Player class. However, they take in an extra int parameter called type. This can be thought of as an identifier that dictates how the enemies behave. Each enemy has a unique (albeit simple) AI.
![Enemies Example](https://i.imgur.com/JcMXcaA.png)

# Rooms
Rooms are 2D vectors of wall game objects. Like the player and or enemies, wall has a texture to dictate its appearance and a collider object to interact with other objects. However, they also have a bool hasCollider, that determines whether this collider affects the player. 
![Room Example](https://imgur.com/43f646f5-deb9-42ed-9731-ffd35aabc66f)

Rooms also have a int variable type that defines their opening(s). This number is based off a preconstructed array index. 
![Preset Example](https://i.imgur.com/cMH97Tp.png)

# Map
The map is a 2D vector of rooms (or alternatively a “4D” vector of walls).The map class has 4 main functions: Clear, Generate, Populate, and Display. 
Clear allocates space for the map based on a predefined map size, filling the 2D vector of rooms (layout) with empty/null rooms. 
Generate works by assigning a random room to a given coordinate and recursively generating appropriate “exit” rooms for each exit the room has. For example if I generate a room opening right at coordinate [x,y], the generate will call itself for the area to the right([x +1, y]) and generate an appropriate room opening left.

![Map Example](https://i.imgur.com/EMOXkW2.png)


As rooms can have multiple openings, the algorithm will continue to recursively branch out until it reaches a spot that has already been taken or exceeds the bounds of the map.
Populate fills each room with a random set of enemies.
This algorithm ensures that each room is accessible by at least one entry. Which is important considering the start and finish could be in any room.

![Path example](https://i.imgur.com/dtM3BMU.png)

Map also makes use of a graph data structure named GPS. GPS utilizes breadth first search to calculate the shortest route from the room the player is currently in to the finishing room. The main function of the game then takes the first step of this route and relays it to the player’s HUD in the form of a direction.
![Direction Example](https://i.imgur.com/QH321rm.png)
