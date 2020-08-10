#define _KEYPAD_C_

#include <mbed.h>
#include "keypad.h"

BusOut keySens(D11,D12,D13);

DigitalIn keyOfs0(PB_13);
DigitalIn keyOfs1(PB_14);
DigitalIn keyOfs2(PB_15);
DigitalIn keyOfs3(PB_1);

/**
 * getKey
 * 入力された文字を確認
 * return : 押されているキー or 0
 */
char getKey(){

    keyOfs0.mode(PullDown);
    keyOfs1.mode(PullDown);
    keyOfs2.mode(PullDown);
    keyOfs3.mode(PullDown);

    int i;
    char retChr = 0;
    keySens = 0;
    for(i=0;i<=2;i++){
        keySens = 1 << i;
        if(keyOfs0){
            retChr = '0'+(4*i);
        } else if(keyOfs1){
            retChr = '1'+(4*i);
        } else if(keyOfs2){
            if(i!=2)
                retChr = '2'+(4*i);
            else
                retChr = '*';
        } else if(keyOfs3){
            if(i!=2)
                retChr = '3'+(4*i);
            else
                retChr = '#';
        }
    }    
    return retChr;
}