#ifndef GAME_INSTANCE_H
#define GAME_INSTANCE_H

typedef struct StatusCode {
    int Code_Requested;
    int Code_Result;
    
} StatusCode;

typedef void (*GameEntry)(void);
typedef int (*GamePeriodic)(double DeltaTime);
typedef StatusCode (*StatusCode)(int code);

typedef struct GameInstance {
    GameEntry Game_Init;
    GamePeriodic Game_Periodic;
    int StatusCode;
} GameInstance;



GameInstance InstanceInit(void (*GameEntry)) {

}

StatusCode StatusInit()

#endif