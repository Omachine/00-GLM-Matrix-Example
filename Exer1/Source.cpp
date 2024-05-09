#include <iostream>
#include <algorithm>
#include <execution>
#include <chrono>
#include <cmath>
void vc_timer(void) {
	static bool running = false;
	static std::chrono::steady_clock::time_point previousTime = std::chrono::steady_clock::now(); if (!running) {
		running = true;
	}
	else {
		std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now(); std::chrono::steady_clock::duration elapsedTime = currentTime - previousTime;// Tempo em segundos.
		std::chrono::duration<double> time_span;
		time_span = std::chrono::duration_cast<std::chrono::duration<double>>(elapsedTime); double nseconds = time_span.count();
		std::cout << "Tempo decorrido: " << nseconds << "segundos" << std::endl; std::cout << "Pressione qualquer tecla para continuar...\n";
		std::cin.get();
	}
}

constexpr int kSize = 1000;
int main() {
	double d[kSize]{};
	vc_timer(); // Inicia a contagem de tempo
	for (int i = 0; i < kSize; i++) {
		for (int x = 0; x < kSize; x++)
			for (int y = 0; y < kSize; y++)
				d[i] += tan(atan(tan(atan(tan(atan(tan(atan(tan(atan(123456789.123456789))))))))));
	}
	vc_timer(); // Finaliza a contagem de tempo e imprime o tempo decorrido (em segundos).return 0;
}