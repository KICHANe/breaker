#ifndef STATUS_CODES_H
#define STATUS_CODES_H

typedef struct StatusCode {
    int Code_Requested;
    int Code_Result;
} StatusCode;

StatusCode SendStatus(StatusCode Sender)



#endif