#pragma once

#include <stdio.h>
#include <stdlib.h>

#define CORE_MAX_NAME_LENGTH 32

#define CORE_MQ_PATH_SERVICE 	"/mq_service"

#define CORE_MQ_PERMS 			((int)(0666))
#define CORE_MQ_MAX_MSG 		10
#define CORE_MQ_MSG_SIZE 		128

#define PASSERT_ERRNO(EXP) 			\
    do 								\
    { 								\
        if (!(EXP)) 				\
        { 							\
            perror(#EXP); 			\
            exit(EXIT_FAILURE); 	\
        } 							\
    } while(0)
