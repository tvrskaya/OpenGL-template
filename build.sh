#!/bin/sh
set -xe

FILES="SandboxApplication.cpp SandboxLayer.cpp Events/Event.cpp Events/KeyEvents.h Events/MouseEvents.h Camera.cpp CameraController.cpp Application.cpp Layer.cpp LayerStack.cpp Window/Window.cpp"
CC="g++"
$CC $FILES -std=c++11 -lglad -lglfw3 -ldl -lpthread  -lGL  -lX11  -lXrandr -lXi -o main