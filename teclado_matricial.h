#ifndef KEYPAD_H 
#define KEYPAD_H
#include "pico/stdlib.h"


// Configuração do teclado matricial
#define ROWS 4 
#define COLS 4

// Pinos referente as linhas e colunas do teclado
const uint linhas[ROWS] = {18,19,20,4};
const uint colunas[COLS] = {16,17,9,8};

const char key_map [ROWS] [COLS] = {
    {'1', '2' ,'3', 'A'},
    {'4', '5' ,'6', 'B'},
    {'7', '8' ,'9', 'C'},
    {'*', '0' ,'#', 'D'}
};

void keypad_init (){
    //configura linhas como saída e as colunas como entrada
    for (int i = 0; i < ROWS ; i++){
        gpio_init(linhas[i]);
        gpio_set_dir(linhas[i], GPIO_OUT);
        gpio_put(linhas[i],0); // estado padrão das linhas
    }
    for (int i=0; i<COLS ; i++){
        gpio_init(colunas[i]);
        gpio_set_dir(colunas[i], GPIO_IN);
        gpio_pull_down(colunas[i]); // Ativa o pull-up quando pressionado
    }
}
char read_keypad(){
    for(int row = 0; row < ROWS ; row++){
        gpio_put(linhas[row],false); //Ativa a linha

        for(int col =0 ; col < COLS; col++);{
            if(!gpio_get(colunas[COLS])){
                gpio_put(linhas[row], true);
                return key_map[row] [COLS];
            }
        }
        gpio_put(linhas[row], true);
    }
    return '\0'; //Nenhuma tecla pressionada
}

#endif