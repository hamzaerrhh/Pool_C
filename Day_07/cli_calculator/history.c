#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

typedef struct HistoryEntry {
    char operation[MAX_OPERATION_LENGTH];
    struct HistoryEntry* next;
} HistoryEntry;

static HistoryEntry* history_head = NULL;
static HistoryEntry* history_tail = NULL;
static int history_count = 0;

void init_history() {
    history_head = NULL;
    history_tail = NULL;
    history_count = 0;
}

void add_to_history(const char* operation) {
    HistoryEntry* new_entry = (HistoryEntry*)malloc(sizeof(HistoryEntry));
    if (!new_entry) {
        printf("Memory allocation error!\n");
        return;
    }
    
    strncpy(new_entry->operation, operation, MAX_OPERATION_LENGTH - 1);
    new_entry->operation[MAX_OPERATION_LENGTH - 1] = '\0';
    new_entry->next = NULL;
    
    if (history_count == HISTORY_SIZE) {
        // Remove oldest entry
        HistoryEntry* temp = history_head;
        history_head = history_head->next;
        free(temp);
        history_count--;
    }
    
    if (history_head == NULL) {
        history_head = new_entry;
        history_tail = new_entry;
    } else {
        history_tail->next = new_entry;
        history_tail = new_entry;
    }
    
    history_count++;
}

void show_history() {
    if (history_count == 0) {
        printf("No calculations in history.\n");
        return;
    }
    
    printf("\n=== Calculation History (Last %d) ===\n", HISTORY_SIZE);
    
    HistoryEntry* current = history_head;
    int i = 1;
    
    // Count total entries for display
    int total_entries = history_count;
    
    while (current != NULL) {
        printf("%d. %s\n", i, current->operation);
        current = current->next;
        i++;
    }
    printf("====================================\n");
}

void free_history() {
    HistoryEntry* current = history_head;
    while (current != NULL) {
        HistoryEntry* next = current->next;
        free(current);
        current = next;
    }
    history_head = NULL;
    history_tail = NULL;
    history_count = 0;
}