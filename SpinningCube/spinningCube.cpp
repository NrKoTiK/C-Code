#ifndef SPIN_SPINNINGCUBE
#define SPIN_SPINNINGCUBE

#include <iostream>
#include <math.h>
#include <thread>
#include <chrono>

namespace Spin 
{
	
	float A = 0, B = 0, C = 0;
	const int width = 80;
	const int height = 44;
	float zBuffer[width * height];
	char buffer[width * height];
	const float cubeWidth = 20;
	// Cubes distance from the screen
	const float cubeDistance = 100;
	// My distance from the screen
	const float userDistance = 40;
	// Filler to char to fill screen
	const char background = ' ';


	float calcX(const float& i, const float& j, const float& k) 
	{
		/// Rotation Matrix to calc X 
		return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
			j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
	}

	float calcY(const float& i, const float& j, const float& k) 
	{
		/// Rotation Matrix to calc Y axis
		return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
			j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) -
			i * cos(B) * sin(C);
	}
	float calcZ(const float& i, const float& j, const float& k)
	{
		/// Rotation matrix to calc z axis
		return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
	}
	void calcFace(const float& i, const float& j, const float& k, const char ch)
	{
		/// Gives the Point after Rotation
		float xpos = calcX(i, j, k);
		float ypos = calcY(i, j, k);
		float zpos = calcZ(i, j, k) + cubeDistance;
		float zInverse = 1 / zpos;
		
		/// Projection Point
		float yPrime = (int)((height / 2) - ypos * zInverse * userDistance);

		float xPrime = (int)((width / 2) + xpos * zInverse * userDistance*2);

		int p = xPrime + yPrime * width;
		
		if (p >= 0 && p < width * height) {
			if (zBuffer[p] < zInverse)
			{
				zBuffer[p] = zInverse;
				buffer[p] = ch;
			}
		}
	}
}
int main()
{
	std::cout << "\x1b[2J";

	while (true)
	{
		std::memset(Spin::zBuffer, 0, Spin::width * Spin::height * 4);
		std::memset(Spin::buffer, Spin::background, Spin::width * Spin::height);
		
		for (int i = -Spin::cubeWidth; i < Spin::cubeWidth; ++i)
		{
			for (int j = -Spin::cubeWidth; j < Spin::cubeWidth; ++j)
			{
				Spin::calcFace(i, j, -Spin::cubeWidth, '@');
				Spin::calcFace(i, j, Spin::cubeWidth, '/');
				Spin::calcFace(i, -Spin::cubeWidth, j, '#');
				Spin::calcFace(i, Spin::cubeWidth, j, '$');
				Spin::calcFace(-Spin::cubeWidth, j, i, '+');
				Spin::calcFace(Spin::cubeWidth, j, i, '=');
			}
		}

		std::cout << "\x1b[H";

		for (int i = 0; i < Spin::width * Spin::height; ++i)
		{
			putchar(i % Spin::width ? Spin::buffer[i] : '\n');	
		}

		Spin::A += 0.03;
		Spin::B += 0.4;
		Spin::C += 0.05;
	
		std::this_thread::sleep_for(std::chrono::microseconds(30));
	}
	
	return 0;
}

#endif // !SPIN_SPINNINGCUBE
