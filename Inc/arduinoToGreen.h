#define ARDUINOTOGREEN_H_

void digitalWrite (int pino, int valor); // Implementar em C sem usar a HAL
void pinMode     (int pino, int modo); // Implementar em C usando a HAL
int    digitalRead (int pino); // Implementar em ASM
