#define GAME_JAM
#include "common.h"

static uint getPressedButton(void);
static void mainTask(void);

struct Position {
    undefined4 x;
    undefined4 y;
    undefined4 z;
};

struct Position position;
uint counter;
undefined4 speed;

void _entry start(void){
    counter = 0;
    position = (struct Position){0.0f, 0.0f, 0.0f};
    speed = 1.0f;
    
    load_scene(mainTask, 1);
    
    EV_SetPlayerControlFlags(0);
    SetClockVisibility(0); // 0 = disable clock, 1 = enable
    SetPauseDisabled(1); // 0 = enable pausing, 1 = disable pausing
    
    return;
}

static uint getPressedButton(void){
    uint button = 0;
    
    uint controller_input = get_controller_input(1);
    if (controller_input & UP) {
        button = UP;
    } else if (controller_input & DOWN) {
        button = DOWN;
    } else if (controller_input & LEFT) {
        button = LEFT;
    } else if (controller_input & RIGHT) {
        button = RIGHT;
    } else if (controller_input & LB) {
        button = LB;
    } else if (controller_input & RB) {
        button = RB;
    } else if (controller_input & A_BTN) {
        button = A_BTN;
    } else if (controller_input & B_BTN) {
        button = B_BTN;
    }
    
    return button;
}

static void mainTask(void){
    uint button = getPressedButton();
    
    set_debug_screen_text_position(0, 0);
    debug_log_to_screen("version: 64\n");
    debug_log_to_screen("button: 0x%x\n", button);
    debug_log_to_screen("button presses: %d\n", counter);
    debug_log_to_screen("position.x: %f\n", position.x);
    debug_log_to_screen("position.y: %f\n", position.y);
    debug_log_to_screen("position.z: %f\n", position.z);
    
    if (button == UP) {
        position.x += speed;
        
    } else if (button == DOWN) {
        position.x -= speed;
        
    } else if (button == LEFT) {
        position.y -= speed;
        
    } else if (button == RIGHT) {
        position.y += speed;
        
    } else if (button == LB) {
        position.z -= speed;
        
    } else if (button == RB) {
        position.z += speed;
    }
    
    if (button != 0) {
        callFn((void*)0x0c090ea0, position.x, position.y, position.z); // REVIEW The position of the character doesn't change.
        // callFn((void*)0x0c328e20, RYO_, 0xFFFFFFFF, position.x, position.y, position.z, 1); // NOTE Crashes the game.
        counter++;
        sleep(1);
    }
    
    return;
}
