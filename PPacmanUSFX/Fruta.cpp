#include "Fruta.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

Fruta::Fruta(int _posicionX, int _posicionY, int _tipo, vector<Texture*> _frutaTexture, bool _isClip, int _frameX, int _frameY, int _anchoClip, int _altoClip) :
	GameObject(_posicionX, _posicionY, ancho, alto, anchoPantalla, altoPantalla, _frutaTexture, _tipo, _isClip, _frameX, _frameY, _anchoClip, _altoClip)
{
	ancho = 25;
	alto = 25;
	visible = true;
	tiempoVisible = 98;
	tiempoNoVisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
	tipo = _tipo;
	frutaTexture = _frutaTexture;
}

void Fruta::show()
{

	if (contadorTiempoVisible >= tiempoVisible) {
		visible = false;
		if (contadorTiempoNoVisible >= tiempoNoVisible) {
			//posicionX = 1 + rand() % (anchoPantalla - 1);
			//posicionY = 1 + rand() % (altoPantalla - 1);
			tipo = rand() % frutaTexture.size();
			contadorTiempoVisible = 0;
			contadorTiempoNoVisible = 0;
			visible = true;
			frameX = 0;
			contadorFrames = 0;
		}
		else {
			contadorTiempoNoVisible++;
		}
	}
	else {
		contadorTiempoVisible++;
	}
}


void Fruta::update() {
	if (visible)
	{
		contadorFrames++;
		if (contadorFrames == 25)
		{
			frameX++;
			if (frameX == framesMovimiento)
			{
				frameX -= framesMovimiento;
			}
			contadorFrames = 0;
		}
	}
}
//void Fruta::render()
//{
//	if (visible) {
//		SDL_Rect clip = { 0, 0, ancho, alto };
//		frutaTexture[tipo]->render(posicionX, posicionY, &clip);
//
//	}
