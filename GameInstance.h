#ifndef GAME_INSTANCE_H
#define GAME_INSTANCE_H

#include <status_codes.h>

typedef void (*GameEntry)(void);
typedef int (*GamePeriodic)(double DeltaTime);
typedef StatusCode (*StatusCode)(int code);

typedef struct GameInstance {
    GameEntry Game_Init;
    GamePeriodic Game_Periodic;
    StatusCode status;
} GameInstance;

GameInstance InstanceInit(void (*GameEntry)) {

}

#endif