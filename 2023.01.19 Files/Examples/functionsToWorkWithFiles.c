#include <stdio.h>
#include <stdlib.h>


//Функції для роботи з файлами

FILE *fopen(const char *filename, const char *mode); // Створює новий файл, або відкриває вже існуюючий
int fclose(FILE *stream);                            // Закриває файл
int getc(FILE *stream);                              // Зчитує символ (character) з файлу
int putc(int char, FILE *stream);                    // Записує символ (character) у файл
int fscanf(FILE *stream, const char *format, ...);   // Зчитує данні з файлу   
int fprintf(FILE *stream, const char *format, ...);  // Записує данні до файлу
int getw(FILE *stream);                              // Зчитує int з файлу 
int putw(int c, FILE *stream);                       // Записує int у файл
int fseek(FILE *stream, long int offset, int whence);// Переміщує позицію до бажаної точки 
long int ftell(FILE *stream);                        // Повертає поточну позицію у файлі 
void rewind(FILE *stream);                           // Переміщує позицію на початок файлу
