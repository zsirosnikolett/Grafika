all:
	gcc -w -Iinclude/ src/callbacks.c src/draw.c src/main.c src/ball.c src/game.c src/init.c src/pad.c -lopengl32 -lglu32 -lglut32 -lm -o pong.exe -Wall -Wextra -Wpedantic

linux:
	gcc -Iinclude/ src/callbacks.c src/draw.c src/main.c src/ball.c src/game.c src/init.c src/pad.c -lGL -lGLU -lglut -lm -o pong.exe -Wall -Wextra -Wpedantic
