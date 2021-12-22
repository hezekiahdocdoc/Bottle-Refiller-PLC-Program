/*
 * DEBUGGER code
 * 
 * On "publish", when buffer is free, debugger stores arbitrary variables 
 * content into, and mark this buffer as filled
 * 
 * 
 * Buffer content is read asynchronously, (from non real time part), 
 * and then buffer marked free again.
 *  
 * 
 * */
#ifdef TARGET_DEBUG_AND_RETAIN_DISABLE

void __init_debug    (void){}
void __cleanup_debug (void){}
void __retrieve_debug(void){}
void __publish_debug (void){}

#else

#include "iec_types_all.h"
#include "POUS.h"
/*for memcpy*/
#include <string.h>
#include <stdio.h>

#ifndef TARGET_ONLINE_DEBUG_DISABLE
#define BUFFER_SIZE 281

/* Atomically accessed variable for buffer state */
#define BUFFER_FREE 0
#define BUFFER_BUSY 1
static long buffer_state = BUFFER_FREE;

/* The buffer itself */
char debug_buffer[BUFFER_SIZE];

/* Buffer's cursor*/
static char* buffer_cursor = debug_buffer;
#endif

static unsigned int retain_offset = 0;
/***
 * Declare programs 
 **/
extern BOTTLEREFILL RES0__INSTANCE0;

/***
 * Declare global variables from resources and conf 
 **/
extern       BOTTLEREFILL   RES0__INSTANCE0;

typedef const struct {
    void *ptr;
    __IEC_types_enum type;
} dbgvardsc_t;

static dbgvardsc_t dbgvardsc[] = {
{&(RES0__INSTANCE0.START), BOOL_ENUM},
{&(RES0__INSTANCE0.STOP), BOOL_ENUM},
{&(RES0__INSTANCE0.SYSTEM_ON), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON0.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON0.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON0.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON0.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TIME_ON1), TIME_ENUM},
{&(RES0__INSTANCE0.TIME_ON2), TIME_ENUM},
{&(RES0__INSTANCE0.BOT_DETECT_STATE), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_SIZE_RAND_GENERATOR0.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_SIZE_RAND_GENERATOR0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_SIZE_RAND_GENERATOR0.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_SIZE_RAND_GENERATOR0.BSZGENR), UINT_ENUM},
{&(RES0__INSTANCE0.BOT_SIZE_RAND_GENERATOR0.M), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_SIZE_RAND_GENERATOR0.INIT), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_SIZE_RAND_GENERATOR0.OUT), UDINT_ENUM},
{&(RES0__INSTANCE0.BOT_STATE_RAND_GENERATOR0.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_STATE_RAND_GENERATOR0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_STATE_RAND_GENERATOR0.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_STATE_RAND_GENERATOR0.BSGENR), UINT_ENUM},
{&(RES0__INSTANCE0.BOT_STATE_RAND_GENERATOR0.M), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_STATE_RAND_GENERATOR0.INIT), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_STATE_RAND_GENERATOR0.OUT), UDINT_ENUM},
{&(RES0__INSTANCE0.BOT_SIZE1), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_SIZE2), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_SIZE3), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_SIZE4), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_SIZE5), BOOL_ENUM},
{&(RES0__INSTANCE0.FIRST_BOT_STATE_BIT), BYTE_ENUM},
{&(RES0__INSTANCE0.SECOND_BOT_STATE_BIT), BYTE_ENUM},
{&(RES0__INSTANCE0.THIRD_BOT_STATE_BIT), BYTE_ENUM},
{&(RES0__INSTANCE0.FOURTH_BOT_STATE_BIT), BYTE_ENUM},
{&(RES0__INSTANCE0.FIFTH_BOT_STATE_BIT), BYTE_ENUM},
{&(RES0__INSTANCE0.FIRST_BOT_SIZE_BIT), BYTE_ENUM},
{&(RES0__INSTANCE0.SECOND_BOT_SIZE_BIT), BYTE_ENUM},
{&(RES0__INSTANCE0.THIRD_BOT_SIZE_BIT), BYTE_ENUM},
{&(RES0__INSTANCE0.FOURTH_BOT_SIZE_BIT), BYTE_ENUM},
{&(RES0__INSTANCE0.FIFTH_BOT_SIZE_BIT), BYTE_ENUM},
{&(RES0__INSTANCE0.BIT_TIMER_STATE1), BOOL_ENUM},
{&(RES0__INSTANCE0.BIT_TIMER_STATE2), BOOL_ENUM},
{&(RES0__INSTANCE0.BIT_TIMER_STATE3), BOOL_ENUM},
{&(RES0__INSTANCE0.BIT_TIMER_STATE4), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_STATE1), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_STATE2), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_STATE3), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_STATE4), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_STATE5), BOOL_ENUM},
{&(RES0__INSTANCE0.SR0.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.SR0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.SR0.S1), BOOL_ENUM},
{&(RES0__INSTANCE0.SR0.R), BOOL_ENUM},
{&(RES0__INSTANCE0.SR0.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.SR1.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.SR1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.SR1.S1), BOOL_ENUM},
{&(RES0__INSTANCE0.SR1.R), BOOL_ENUM},
{&(RES0__INSTANCE0.SR1.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_DETECT0.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_DETECT0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_DETECT0.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_DETECT0.BDGENR), UINT_ENUM},
{&(RES0__INSTANCE0.BOT_DETECT0.M), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_DETECT0.INIT), BOOL_ENUM},
{&(RES0__INSTANCE0.BOT_DETECT0.OUT), UDINT_ENUM},
{&(RES0__INSTANCE0.SR2.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.SR2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.SR2.S1), BOOL_ENUM},
{&(RES0__INSTANCE0.SR2.R), BOOL_ENUM},
{&(RES0__INSTANCE0.SR2.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.SR3.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.SR3.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.SR3.S1), BOOL_ENUM},
{&(RES0__INSTANCE0.SR3.R), BOOL_ENUM},
{&(RES0__INSTANCE0.SR3.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.SR4.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.SR4.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.SR4.S1), BOOL_ENUM},
{&(RES0__INSTANCE0.SR4.R), BOOL_ENUM},
{&(RES0__INSTANCE0.SR4.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.SR5.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.SR5.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.SR5.S1), BOOL_ENUM},
{&(RES0__INSTANCE0.SR5.R), BOOL_ENUM},
{&(RES0__INSTANCE0.SR5.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.SR6.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.SR6.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.SR6.S1), BOOL_ENUM},
{&(RES0__INSTANCE0.SR6.R), BOOL_ENUM},
{&(RES0__INSTANCE0.SR6.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.SR7.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.SR7.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.SR7.S1), BOOL_ENUM},
{&(RES0__INSTANCE0.SR7.R), BOOL_ENUM},
{&(RES0__INSTANCE0.SR7.Q1), BOOL_ENUM},
{&(RES0__INSTANCE0.FILL_LARGE), BOOL_ENUM},
{&(RES0__INSTANCE0.FILL_SMALL), BOOL_ENUM},
{&(RES0__INSTANCE0.PASS), BOOL_ENUM},
{&(RES0__INSTANCE0.DISCARD), BOOL_ENUM},
{&(RES0__INSTANCE0.UP), BOOL_ENUM},
{&(RES0__INSTANCE0.DOWN), BOOL_ENUM},
{&(RES0__INSTANCE0.FEED_MOTOR), BOOL_ENUM},
{&(RES0__INSTANCE0.TON1.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON1.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON1.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON1.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON1.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON1.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON1.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON1.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON1.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON2.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON2.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON2.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON2.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON2.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON2.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON2.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON2.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON2.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.LT153_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.GT4_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.LT161_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.LT161_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.GT61_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.LT64_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.LT64_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.UDINT_TO_BOOL22_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.LT17_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.UDINT_TO_BOOL8_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.UDINT_TO_BOOL41_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.BOOL_TO_BYTE109_OUT), BYTE_ENUM},
{&(RES0__INSTANCE0.BOOL_TO_BYTE9_OUT), BYTE_ENUM},
{&(RES0__INSTANCE0.BYTE_TO_BOOL29_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.GT37_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.LT105_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.LT105_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.BOOL_TO_BYTE12_OUT), BYTE_ENUM},
{&(RES0__INSTANCE0.BYTE_TO_BOOL80_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.BOOL_TO_BYTE77_OUT), BYTE_ENUM},
{&(RES0__INSTANCE0.BYTE_TO_BOOL31_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.GT21_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.LT108_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.LT108_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.BOOL_TO_BYTE27_OUT), BYTE_ENUM},
{&(RES0__INSTANCE0.BYTE_TO_BOOL82_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.BOOL_TO_BYTE79_OUT), BYTE_ENUM},
{&(RES0__INSTANCE0.BYTE_TO_BOOL54_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.GT43_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.LT112_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.LT112_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.BOOL_TO_BYTE49_OUT), BYTE_ENUM},
{&(RES0__INSTANCE0.BYTE_TO_BOOL93_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.BOOL_TO_BYTE91_OUT), BYTE_ENUM},
{&(RES0__INSTANCE0.BYTE_TO_BOOL69_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.GT65_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.LT114_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.LT114_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.BOOL_TO_BYTE67_OUT), BYTE_ENUM},
{&(RES0__INSTANCE0.BYTE_TO_BOOL100_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0.BOOL_TO_BYTE98_OUT), BYTE_ENUM},
{&(RES0__INSTANCE0.GT145_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.GT145_OUT), BOOL_ENUM}
};

typedef void(*__for_each_variable_do_fp)(dbgvardsc_t*);
void __for_each_variable_do(__for_each_variable_do_fp fp)
{
    unsigned int i;
    for(i = 0; i < sizeof(dbgvardsc)/sizeof(dbgvardsc_t); i++){
        dbgvardsc_t *dsc = &dbgvardsc[i];
        if(dsc->type != UNKNOWN_ENUM) 
            (*fp)(dsc);
    }
}

#define __Unpack_case_t(TYPENAME) \
        case TYPENAME##_ENUM :\
            *flags = ((__IEC_##TYPENAME##_t *)varp)->flags;\
            forced_value_p = *real_value_p = &((__IEC_##TYPENAME##_t *)varp)->value;\
            break;

#define __Unpack_case_p(TYPENAME)\
        case TYPENAME##_O_ENUM :\
            *flags = __IEC_OUTPUT_FLAG;\
        case TYPENAME##_P_ENUM :\
            *flags |= ((__IEC_##TYPENAME##_p *)varp)->flags;\
            *real_value_p = ((__IEC_##TYPENAME##_p *)varp)->value;\
            forced_value_p = &((__IEC_##TYPENAME##_p *)varp)->fvalue;\
            break;

void* UnpackVar(dbgvardsc_t *dsc, void **real_value_p, char *flags)
{
    void *varp = dsc->ptr;
    void *forced_value_p = NULL;
    *flags = 0;
    /* find data to copy*/
    switch(dsc->type){
        __ANY(__Unpack_case_t)
        __ANY(__Unpack_case_p)
    default:
        break;
    }
    if (*flags & __IEC_FORCE_FLAG)
        return forced_value_p;
    return *real_value_p;
}

void Remind(unsigned int offset, unsigned int count, void * p);

void RemindIterator(dbgvardsc_t *dsc)
{
    void *real_value_p = NULL;
    char flags = 0;
    UnpackVar(dsc, &real_value_p, &flags);

    if(flags & __IEC_RETAIN_FLAG){
        USINT size = __get_type_enum_size(dsc->type);
        /* compute next cursor positon*/
        unsigned int next_retain_offset = retain_offset + size;
        /* if buffer not full */
        Remind(retain_offset, size, real_value_p);
        /* increment cursor according size*/
        retain_offset = next_retain_offset;
    }
}

extern int CheckRetainBuffer(void);
extern void InitRetain(void);

void __init_debug(void)
{
    /* init local static vars */
#ifndef TARGET_ONLINE_DEBUG_DISABLE	
    buffer_cursor = debug_buffer;
    buffer_state = BUFFER_FREE;
#endif

    retain_offset = 0;
    InitRetain();
    /* Iterate over all variables to fill debug buffer */
    if(CheckRetainBuffer()){
    	__for_each_variable_do(RemindIterator);
    }else{
    	char mstr[] = "RETAIN memory invalid - defaults used";
        LogMessage(LOG_WARNING, mstr, sizeof(mstr));
    }
    retain_offset = 0;
}

extern void InitiateDebugTransfer(void);
extern void CleanupRetain(void);

extern unsigned long __tick;

void __cleanup_debug(void)
{
#ifndef TARGET_ONLINE_DEBUG_DISABLE	
    buffer_cursor = debug_buffer;
    InitiateDebugTransfer();
#endif    

    CleanupRetain();
}

void __retrieve_debug(void)
{
}


void Retain(unsigned int offset, unsigned int count, void * p);

static inline void BufferIterator(dbgvardsc_t *dsc, int do_debug)
{
    void *real_value_p = NULL;
    void *visible_value_p = NULL;
    char flags = 0;

    visible_value_p = UnpackVar(dsc, &real_value_p, &flags);

    if(flags & ( __IEC_DEBUG_FLAG | __IEC_RETAIN_FLAG)){
        USINT size = __get_type_enum_size(dsc->type);

#ifndef TARGET_ONLINE_DEBUG_DISABLE	
        if(flags & __IEC_DEBUG_FLAG){
            /* copy visible variable to buffer */;
            if(do_debug){
                /* compute next cursor positon.
                   No need to check overflow, as BUFFER_SIZE
                   is computed large enough */
		if((dsc->type == STRING_ENUM)   ||
		   (dsc->type == STRING_P_ENUM) ||
		   (dsc->type == STRING_O_ENUM)){
                    /* optimization for strings */
                    size = ((STRING*)visible_value_p)->len + 1;
                }
                char* next_cursor = buffer_cursor + size;
                /* copy data to the buffer */
                memcpy(buffer_cursor, visible_value_p, size);
                /* increment cursor according size*/
                buffer_cursor = next_cursor;
            }
            /* re-force real value of outputs (M and Q)*/
            if((flags & __IEC_FORCE_FLAG) && (flags & __IEC_OUTPUT_FLAG)){
                memcpy(real_value_p, visible_value_p, size);
            }
        }
#endif	

        if(flags & __IEC_RETAIN_FLAG){
            /* compute next cursor positon*/
            unsigned int next_retain_offset = retain_offset + size;
            /* if buffer not full */
            Retain(retain_offset, size, real_value_p);
            /* increment cursor according size*/
            retain_offset = next_retain_offset;
        }
    }
}

void DebugIterator(dbgvardsc_t *dsc){
    BufferIterator(dsc, 1);
}

void RetainIterator(dbgvardsc_t *dsc){
    BufferIterator(dsc, 0);
}


unsigned int retain_size = 0;

/* GetRetainSizeIterator */
void GetRetainSizeIterator(dbgvardsc_t *dsc)
{
    void *real_value_p = NULL;
    char flags = 0;
    UnpackVar(dsc, &real_value_p, &flags);

    if(flags & __IEC_RETAIN_FLAG){
        USINT size = __get_type_enum_size(dsc->type);
        /* Calc retain buffer size */
        retain_size += size;
    }
}

/* Return size of all retain variables */
unsigned int GetRetainSize(void)
{
    __for_each_variable_do(GetRetainSizeIterator);
    return retain_size;
}


extern void PLC_GetTime(IEC_TIME*);
extern int TryEnterDebugSection(void);
extern long AtomicCompareExchange(long*, long, long);
extern long long AtomicCompareExchange64(long long* , long long , long long);
extern void LeaveDebugSection(void);
extern void ValidateRetainBuffer(void);
extern void InValidateRetainBuffer(void);

void __publish_debug(void)
{
    retain_offset = 0;
    InValidateRetainBuffer();
    
#ifndef TARGET_ONLINE_DEBUG_DISABLE 
    /* Check there is no running debugger re-configuration */
    if(TryEnterDebugSection()){
        /* Lock buffer */
        long latest_state = AtomicCompareExchange(
            &buffer_state,
            BUFFER_FREE,
            BUFFER_BUSY);
            
        /* If buffer was free */
        if(latest_state == BUFFER_FREE)
        {
            /* Reset buffer cursor */
            buffer_cursor = debug_buffer;
            /* Iterate over all variables to fill debug buffer */
            __for_each_variable_do(DebugIterator);
            
            /* Leave debug section,
             * Trigger asynchronous transmission 
             * (returns immediately) */
            InitiateDebugTransfer(); /* size */
        }else{
            /* when not debugging, do only retain */
            __for_each_variable_do(RetainIterator);
        }
        LeaveDebugSection();
    }else
#endif
    {
        /* when not debugging, do only retain */
        __for_each_variable_do(RetainIterator);
    }
    ValidateRetainBuffer();
}

#ifndef TARGET_ONLINE_DEBUG_DISABLE
#define __RegisterDebugVariable_case_t(TYPENAME) \
        case TYPENAME##_ENUM :\
            ((__IEC_##TYPENAME##_t *)varp)->flags |= flags;\
            if(force)\
             ((__IEC_##TYPENAME##_t *)varp)->value = *((TYPENAME *)force);\
            break;
#define __RegisterDebugVariable_case_p(TYPENAME)\
        case TYPENAME##_P_ENUM :\
            ((__IEC_##TYPENAME##_p *)varp)->flags |= flags;\
            if(force)\
             ((__IEC_##TYPENAME##_p *)varp)->fvalue = *((TYPENAME *)force);\
            break;\
        case TYPENAME##_O_ENUM :\
            ((__IEC_##TYPENAME##_p *)varp)->flags |= flags;\
            if(force){\
             ((__IEC_##TYPENAME##_p *)varp)->fvalue = *((TYPENAME *)force);\
             *(((__IEC_##TYPENAME##_p *)varp)->value) = *((TYPENAME *)force);\
            }\
            break;
void RegisterDebugVariable(unsigned int idx, void* force)
{
    if(idx  < sizeof(dbgvardsc)/sizeof(dbgvardsc_t)){
        unsigned char flags = force ?
            __IEC_DEBUG_FLAG | __IEC_FORCE_FLAG :
            __IEC_DEBUG_FLAG;
        dbgvardsc_t *dsc = &dbgvardsc[idx];
        void *varp = dsc->ptr;
        switch(dsc->type){
            __ANY(__RegisterDebugVariable_case_t)
            __ANY(__RegisterDebugVariable_case_p)
        default:
            break;
        }
    }
}

#define __ResetDebugVariablesIterator_case_t(TYPENAME) \
        case TYPENAME##_ENUM :\
            ((__IEC_##TYPENAME##_t *)varp)->flags &= ~(__IEC_DEBUG_FLAG|__IEC_FORCE_FLAG);\
            break;

#define __ResetDebugVariablesIterator_case_p(TYPENAME)\
        case TYPENAME##_P_ENUM :\
        case TYPENAME##_O_ENUM :\
            ((__IEC_##TYPENAME##_p *)varp)->flags &= ~(__IEC_DEBUG_FLAG|__IEC_FORCE_FLAG);\
            break;

void ResetDebugVariablesIterator(dbgvardsc_t *dsc)
{
    /* force debug flag to 0*/
    void *varp = dsc->ptr;
    switch(dsc->type){
        __ANY(__ResetDebugVariablesIterator_case_t)
        __ANY(__ResetDebugVariablesIterator_case_p)
    default:
        break;
    }
}

void ResetDebugVariables(void)
{
    __for_each_variable_do(ResetDebugVariablesIterator);
}

void FreeDebugData(void)
{
    /* atomically mark buffer as free */
    AtomicCompareExchange(
        &buffer_state,
        BUFFER_BUSY,
        BUFFER_FREE);
}
int WaitDebugData(unsigned long *tick);
/* Wait until debug data ready and return pointer to it */
int GetDebugData(unsigned long *tick, unsigned long *size, void **buffer){
    int wait_error = WaitDebugData(tick);
    if(!wait_error){
        *size = buffer_cursor - debug_buffer;
        *buffer = debug_buffer;
    }
    return wait_error;
}
#endif
#endif

