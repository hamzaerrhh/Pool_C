#ifndef HISTORY_H
#define HISTORY_H

#define HISTORY_SIZE 5
#define MAX_OPERATION_LENGTH 100

void init_history();
void add_to_history(const char* operation);
void show_history();
void free_history();

#endif