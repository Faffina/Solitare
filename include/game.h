#ifndef GAME_H  
#define GAME_H
#include <stdbool.h>

#define N_CARD_IN_DECK 52

typedef enum {DIAMONDS, CLUBS, HEARTS, SPADES} suit;
typedef enum {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEEN, JACK, QUEEN, KING} value;

extern char card_sprite[5][14][5][60];

typedef struct {
    suit s;
    value v;
    bool face_up;
} card;

typedef struct {
    card cards[N_CARD_IN_DECK];
    int n_cards;
} card_stack;

extern card empty_card;
extern card back_card;

//generate the card from the card_template
void generate_card_sprite();
//gets the top most face up cad
card get_top(card_stack* stack);
//get the index of the top most face up card
int get_top_index(card_stack* stack);
//get the card at index n
card get_n_card(card_stack* stack, int n);
//move n card from stack a to stack b
int move_cards(card_stack* stack_a, card_stack stack_b, int n);
// print empty card slot
void print_card(int y, int x, card c);
//init the ncurses
//return terminal to defult setings

#endif
