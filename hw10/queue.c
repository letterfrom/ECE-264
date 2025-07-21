#include "queue.h"
#include "tile_game.h"
#include <stdint.h>
#include <stdlib.h>

// Helper function: check if the game is solved
static int is_solved(const struct game_state *state) {
    uint8_t expected = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 3 && j == 3) {
                if (state->tiles[i][j] != 0) return 0;
            } else {
                if (state->tiles[i][j] != expected) return 0;
                expected++;
            }
        }
    }
    return 1;
}

// Simple hash set for visited states
#define VISITED_SIZE 100003
struct visited_node {
    uint64_t key;
    struct visited_node *next;
};

static void visited_insert(struct visited_node **visited, uint64_t key) {
    size_t idx = key % VISITED_SIZE;
    struct visited_node *cur = visited[idx];
    while (cur) {
        if (cur->key == key) return;
        cur = cur->next;
    }
    struct visited_node *node = malloc(sizeof(struct visited_node));
    node->key = key;
    node->next = visited[idx];
    visited[idx] = node;
}

static int visited_exists(struct visited_node **visited, uint64_t key) {
    size_t idx = key % VISITED_SIZE;
    struct visited_node *cur = visited[idx];
    while (cur) {
        if (cur->key == key) return 1;
        cur = cur->next;
    }
    return 0;
}

static void visited_free(struct visited_node **visited) {
    for (size_t i = 0; i < VISITED_SIZE; i++) {
        struct visited_node *cur = visited[i];
        while (cur) {
            struct visited_node *next = cur->next;
            free(cur);
            cur = next;
        }
    }
}

// Enqueue: push state to queue at tail
void enqueue(struct queue *q, struct game_state state) {
    uint64_t value = serialize(state);
    insert_at_tail(&q->data, value);
}

// Dequeue: remove state from queue at head
struct game_state dequeue(struct queue *q) {
    uint64_t value = remove_from_head(&q->data);
    return deserialize(value);
}

// Main BFS logic
int number_of_moves(struct game_state start) {
    struct queue q;
    q.data.head = NULL;

    if (is_solved(&start))  // check here first for early exit
    {
      free_list(q.data);
      return start.num_steps;
    } 

    struct visited_node **visited = calloc(VISITED_SIZE, sizeof(struct visited_node*));
    if (!visited) return -1;

    enqueue(&q, start);
    visited_insert(visited, serialize(start));

    while (q.data.head != NULL) {
        struct game_state cur = dequeue(&q);
        if (is_solved(&cur)) {
            free_list(q.data);
            visited_free(visited);
            free(visited);
            return cur.num_steps;
        }

        // Try move up
        if (cur.empty_row > 0) {
            struct game_state next = cur;
            move_up(&next);
            next.empty_row--;
            next.num_steps = cur.num_steps + 1;
            uint64_t ser = serialize(next);
            if (!visited_exists(visited, ser)) {
                visited_insert(visited, ser);
                enqueue(&q, next);
            }
        }
        // Try move down
        if (cur.empty_row < 3) {
            struct game_state next = cur;
            move_down(&next);
            next.empty_row++;
            next.num_steps = cur.num_steps + 1;
            uint64_t ser = serialize(next);
            if (!visited_exists(visited, ser)) {
                visited_insert(visited, ser);
                enqueue(&q, next);
            }
        }
        // Try move left
        if (cur.empty_col > 0) {
            struct game_state next = cur;
            move_left(&next);
            next.empty_col--;
            next.num_steps = cur.num_steps + 1;
            uint64_t ser = serialize(next);
            if (!visited_exists(visited, ser)) {
                visited_insert(visited, ser);
                enqueue(&q, next);
            }
        }
        // Try move right
        if (cur.empty_col < 3) {
            struct game_state next = cur;
            move_right(&next);
            next.empty_col++;
            next.num_steps = cur.num_steps + 1;
            uint64_t ser = serialize(next);
            if (!visited_exists(visited, ser)) {
                visited_insert(visited, ser);
                enqueue(&q, next);
            }
        }
    }

    free_list(q.data);
    visited_free(visited);
    free(visited);
    return -1;
}
