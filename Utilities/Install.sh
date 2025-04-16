#! /bin/bash

echo "YAY or PARU?"
read editor
if [ $editor == "yay" ]; then
    yay -Sy git sdl3-mixer sdl3-image sdl3 sdl3-ttf code base-devel
else
    paru -Sy git sdl3-mixer sdl3-image sdl3 sdl3-ttf code base-devel
fi

git clone https://github.com/KICHANe/breaker.git
cd breaker
g++ -lSDL3 -lSDL3_mixer -lSDL3_image -lSDL3-ttf -o Breaker main.c       # Compile Main Engine

mkdir $HOME/BreakerEngine
mv Breaker $HOME/BreakerEngine
cd ..
mv breaker $HOME/BreakerEngine
echo "Instalation Complete."
echo "BE_EDITOR=code" >> .env
