#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct MemoryBlock {
    int size;
    int start_addr; // 改为整数地址
    struct MemoryBlock *prev;
    struct MemoryBlock *next;
} MemoryBlock;

MemoryBlock *freeList = NULL;
int TotalMemory = 0;
MemoryBlock *block_array[5] = {};
int block_idx = 0;

// Function to insert a block into the free list
void insertIntoFreeList (MemoryBlock *head, MemoryBlock *block) {
    MemoryBlock *current = head;
    MemoryBlock *precurrent = NULL;
    while (current && current->start_addr < block->start_addr) {
        precurrent = current;
        current = current->next;
    }

    block->next = current;
    if (current != NULL) {
        block->prev = current->prev;
        current->prev = block;
    } else {
        block->prev = precurrent;
    }
    
    if (block->prev != NULL) {
        block->prev->next = block;
    } else {
        head = block;
    }
}

// Function to remove a block from the free list
void removeFromFreeList (MemoryBlock *block) {
    if (block->prev != NULL) {
        block->prev->next = block->next;
    }
    if (block->next != NULL) {
        block->next->prev = block->prev;
    }
    if (block == freeList) {
        freeList = block->next;
    }
    block->next = NULL;
    block->prev = NULL;
}

// Function to merge adjacent free blocks 
void mergeFreeBlocks (MemoryBlock *current) { 
    if (current->prev && current->next 
                      && current->prev->start_addr + current->prev->size == current->start_addr 
                      && current->start_addr + current->size == current->next->start_addr) { 
        // Case 1: Merge with both previous and next blocks 
        current->prev->size += current->size + current->next->size; 
        MemoryBlock *toBeRemovedNext = current->next; 
        current->prev->next = current->next->next; 
        if (current->next->next) { 
            current->next->next->prev = current->prev; 
        } 
        MemoryBlock *toBeRemoved = current; 
        current = current->prev; 
        free(toBeRemovedNext); 
        free(toBeRemoved); 
    } else if (current->prev && current->prev->start_addr + current->prev->size == current->start_addr) { 
        // Case 2: Merge with the previous block 
        current->prev->size += current->size; 
        current->prev->next = current->next; 
        if (current->next) { 
            current->next->prev = current->prev; 
        } 
        MemoryBlock *toBeRemoved = current; 
        current = current->prev; 
        free(toBeRemoved);
    } else if (current->next && current->start_addr + current->size == current->next->start_addr) { 
        // Case 3: Merge with the next block 
        current->size += current->next->size; 
        MemoryBlock *toBeRemoved = current->next; 
        current->next = current->next->next; 
        if (current->next) { 
            current->next->prev = current; 
        } 
        free(toBeRemoved); 
    } else { 
        current = current->next; 
    } 
}

MemoryBlock* allocateMemory_ff (int size) {
    MemoryBlock *current = freeList->next;
    while (current) {
        if (current->size >= size) { 
            int new_start_addr = current->start_addr;
            removeFromFreeList(current); 
            if (current->size > size) { 
                MemoryBlock *newBlock = (MemoryBlock *)malloc(sizeof(MemoryBlock)); 
                newBlock->size = current->size - size;
                newBlock->start_addr = current->start_addr + size;
                insertIntoFreeList(freeList->next, newBlock); 
                current->size = size; 
            } 
            current->start_addr = new_start_addr;
            return current; 
        } 
        current = current->next;
    }
    return NULL; // No suitable block found
}


MemoryBlock* allocateMemory_nf (int size) {
    static MemoryBlock *last_alloc = NULL;  // Hold the location of the last allocation
    static int preaddress = -1;
    if (last_alloc == NULL) {
        last_alloc = freeList->next;
    }

    MemoryBlock *current = last_alloc;
    do {
        if (current->size >= size && current->start_addr > preaddress) {
            int new_start_addr = current->start_addr;
            removeFromFreeList(current);
            if (current->size > size) {
                MemoryBlock *newBlock = (MemoryBlock *)malloc(sizeof(MemoryBlock));
                newBlock->size = current->size - size;
                newBlock->start_addr = current->start_addr + size;
                insertIntoFreeList(freeList->next, newBlock);
                current->size = size;
            }
            current->start_addr = new_start_addr;
            last_alloc = current->next ? current->next : freeList->next;
            preaddress = current->start_addr;
            return current;
        }
        current = current->next ? current->next : freeList->next;
    } while (current != last_alloc);

    return NULL;  // No suitable block found
}

MemoryBlock* allocateMemory_bf (int size) {
    MemoryBlock *current = freeList->next;
    MemoryBlock *best = NULL;
    while (current) {
        if (current->size >= size && (!best || current->size < best->size)) {
            best = current;
        }
        current = current->next;
    }
    if (best) {
        int new_start_addr = best->start_addr;
        removeFromFreeList(best);
        if (best->size > size) {
            MemoryBlock *newBlock = (MemoryBlock *)malloc(sizeof(MemoryBlock));
            newBlock->size = best->size - size;
            newBlock->start_addr = best->start_addr + size;
            insertIntoFreeList(freeList->next, newBlock);
            best->size = size;
        }
        best->start_addr = new_start_addr;
        return best;
    }
    return NULL;  // No suitable block found
}

MemoryBlock* allocateMemory_wf (int size) {
    MemoryBlock *current = freeList->next;
    MemoryBlock *worst = NULL;
    while (current) {
        if (current->size >= size && (!worst || current->size > worst->size)) {
            worst = current;
        }
        current = current->next;
    }
    if (worst) {
        int new_start_addr = worst->start_addr;
        removeFromFreeList(worst);
        if (worst->size > size) {
            MemoryBlock *newBlock = (MemoryBlock *)malloc(sizeof(MemoryBlock));
            newBlock->size = worst->size - size;
            newBlock->start_addr = worst->start_addr + size;
            insertIntoFreeList(freeList->next, newBlock);
            worst->size = size;
        }
        worst->start_addr = new_start_addr;
        return worst;
    }
    return NULL;  // No suitable block found
}

// Function to free memory and merge with adjacent free blocks
void freeMemory (MemoryBlock *block) {
    insertIntoFreeList(freeList->next, block);
    mergeFreeBlocks(block);
}

// Function to display the memory blocks
void displayMemory () {
    MemoryBlock *current = freeList->next;
    int sum = 0, count = 0;
    printf("Free List:\n");
    while (current) {
        printf("Size: %d, Start Address: %d\n", current->size, current->start_addr);
        sum += current->size;
        count ++;        
        current = current->next;
    }
    printf("Free num: %d, Total: %d, Rate: %.2f\n\n", count, sum, (float)sum / TotalMemory);

    sum = 0, count = 0;
    printf("Busy List:\n");
    for (int i = 0; i < block_idx; i++) {
        printf("Size: %d, Start Address: %d\n", block_array[i]->size, block_array[i]->start_addr);
        sum += block_array[i]->size;
        count ++;
    }
    printf("Busy num: %d, Total: %d\n\n", count, sum);
}

int main () {
    // Initialize memory list with random sizes
    srand((unsigned)time(NULL));
    int totalMemory = 1024;
    freeList = (MemoryBlock *)malloc(sizeof(MemoryBlock));
    freeList->size = totalMemory;
    freeList->start_addr = 0; // 初始化内存块的起始地址为0
    freeList->prev = NULL;
    freeList->next = NULL;

    // Randomly divide the memory into blocks
    int current_start_addr = freeList->start_addr;
    for (int i = 0; i < 5; i++) {
        int blockSize = rand() % 100 + 50; // Random block size between 50 and 150
        TotalMemory += blockSize;
        MemoryBlock *newBlock = (MemoryBlock *)malloc(sizeof(MemoryBlock));
        newBlock->size = blockSize;
        newBlock->start_addr = current_start_addr;
        current_start_addr += blockSize;
        newBlock->prev = NULL;
        newBlock->next = NULL;

        if (freeList == NULL) { 
            freeList = newBlock; 
        } else { 
            MemoryBlock *current = freeList; 
            while (current->next != NULL) { 
                current = current->next; 
            } 
            current->next = newBlock; 
            newBlock->prev = current; 
        }
    }
    displayMemory();

    MemoryBlock* (*func_array[4])(int) = {allocateMemory_ff, allocateMemory_nf, allocateMemory_bf, allocateMemory_wf};

    int algorithm_choice = 0;
    printf("Which algorithm to allocate block? (1: ff, 2: nf, 3: bf, 4: wf): ");
    scanf("%d", &algorithm_choice);

    bool flag = true;
    int oper_choice = 0;
    while (flag) {
        printf("Which operation? (1: allocate, 2: free, 3: show, 4: exit): ");
        scanf("%d", &oper_choice);

        if (oper_choice == 1) {
            // Allocate memory
            MemoryBlock *block_tem = func_array[algorithm_choice](100);
            printf("Start allocate block with nf algorithm...\n");
            if (block_tem) {
                printf("Allocated block of size 100\n\n");
                block_array[block_idx++] = block_tem;
                displayMemory();
            } else {
                printf("Failed to allocate block of size 100\n\n");
            }
        } else if (oper_choice == 2) {
            // Free memory
            if (block_idx) {
                int free_idx = 0;
                printf("Which block to free?\n");
                for (int i = 0; i < block_idx; i++) {
                    printf("Idx: %d, Size: %d, Start_addr: %d\n", i + 1, block_array[i]->size, block_array[i]->start_addr);
                }
                scanf("%d", &free_idx);
                freeMemory(block_array[free_idx - 1]);
                block_idx --;
                printf("Freed block of size 100\n\n");
                displayMemory();
            }
        } else if (oper_choice == 3) {
            displayMemory();
        } else {
            flag = false;
        }
    }

    return 0;
}