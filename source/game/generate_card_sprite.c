#include "game.h" 
#include <stdbool.h>
#include <string.h>

card empty_card = {5, 0, true};
card back_card = {5, 1, true};
char card_sprite[5][14][5][60];

void generate_card_sprite() {
    char card_back[5][60] = {
        "┌─────┐",
        "│▒▒▒▒▒│",
        "│▒▒▒▒▒│",
        "│▒▒▒▒▒│",
        "└─────┘"
    };
    char card_template[5][60] = {
        "┌─────┐",
        "│N   S│",
        "│  S  │",
        "│S   N│",
        "└─────┘"
    };
    char card_empty[5][60] = {
        "┌─────┐",
        "│     │",
        "│  x  │",
        "│     │",
        "└─────┘"
    };
    char suit_map[][10] = {"◆", "♣", "♥", "♠"};
    char value_map[][2] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "1", "J", "Q", "K"};
    char temp[2] = " ";

    for(int s = DIAMONDS; s <= SPADES; s++)
        for(int v = ACE; v <= KING; v++)
            for(int y = 0; y < 5; y++){
                char (*dest) = card_sprite[s][v][y];
                char (*sour) = card_template[y];
                for(int i = 0; i < 60; i++){
                    if(sour[i] == '\0')
                        break;
                    else if(sour[i] == 'N')
                        strcat(dest, value_map[v]);
                    else if(sour[i] == 'S')
                        strcat(dest, suit_map[s]);
                    else {
                        temp[0] = sour[i];
                        strcat(dest, temp);
                    }

                }
            }

    mempcpy(card_sprite[4][0], card_empty, sizeof(card_empty));
    for(int i = 1; i < 14; i++)
        mempcpy(card_sprite[4][i], card_back, sizeof(card_back));
}
