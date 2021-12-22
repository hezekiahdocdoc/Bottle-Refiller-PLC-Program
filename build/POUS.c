void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->ADD10_OUT,0,retain)
  __INIT_VAR(data__->EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEL15_OUT,0,retain)
  __INIT_VAR(data__->AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->ADD10_OUT,)));
  __SET_VAR(data__->,SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (UINT)__GET_VAR(data__->ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->SEL15_OUT,));
  __SET_VAR(data__->,AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





void BOT_SIZE_RAND_GENERATOR_init__(BOT_SIZE_RAND_GENERATOR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BSZGENR,0,retain)
  __INIT_VAR(data__->M,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT,0,retain)
}

// Code part
void BOT_SIZE_RAND_GENERATOR_body__(BOT_SIZE_RAND_GENERATOR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->INIT,) == 0)) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
time_t t;
    srand((unsigned) time(&t))
    #undef GetFbVar
    #undef SetFbVar
;
    __SET_VAR(data__->,INIT,,1);
  };
  if (((__GET_VAR(data__->M,) == 0) && (__GET_VAR(data__->IN,) == 1))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
SetFbVar(BSZGENR,rand())
    #undef GetFbVar
    #undef SetFbVar
;
    if ((__GET_VAR(data__->BSZGENR,) > 9000)) {
      #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
      #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
SetFbVar(OUT,1)
      #undef GetFbVar
      #undef SetFbVar
;
    };
    if ((__GET_VAR(data__->BSZGENR,) <= 9000)) {
      #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
      #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
SetFbVar(OUT,0)
      #undef GetFbVar
      #undef SetFbVar
;
    };
  };
  __SET_VAR(data__->,M,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // BOT_SIZE_RAND_GENERATOR_body__() 





void BOT_STATE_RAND_GENERATOR_init__(BOT_STATE_RAND_GENERATOR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BSGENR,0,retain)
  __INIT_VAR(data__->M,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT,0,retain)
}

// Code part
void BOT_STATE_RAND_GENERATOR_body__(BOT_STATE_RAND_GENERATOR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->INIT,) == 0)) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
time_t t;
    srand((unsigned) time(&t))
    #undef GetFbVar
    #undef SetFbVar
;
    __SET_VAR(data__->,INIT,,1);
  };
  if (((__GET_VAR(data__->M,) == 0) && (__GET_VAR(data__->IN,) == 1))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
SetFbVar(BSGENR,rand())
    #undef GetFbVar
    #undef SetFbVar
;
    if ((__GET_VAR(data__->BSGENR,) > 4000)) {
      #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
      #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
SetFbVar(OUT,1)
      #undef GetFbVar
      #undef SetFbVar
;
    };
    if ((__GET_VAR(data__->BSGENR,) <= 4000)) {
      #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
      #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
SetFbVar(OUT,0)
      #undef GetFbVar
      #undef SetFbVar
;
    };
  };
  __SET_VAR(data__->,M,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // BOT_STATE_RAND_GENERATOR_body__() 





void BOT_DETECT_init__(BOT_DETECT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BDGENR,0,retain)
  __INIT_VAR(data__->M,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->INIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUT,0,retain)
}

// Code part
void BOT_DETECT_body__(BOT_DETECT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->INIT,) == 0)) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
time_t t;
    srand((unsigned) time(&t))
    #undef GetFbVar
    #undef SetFbVar
;
    __SET_VAR(data__->,INIT,,1);
  };
  if (((__GET_VAR(data__->M,) == 0) && (__GET_VAR(data__->IN,) == 1))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
SetFbVar(BDGENR,rand())
    #undef GetFbVar
    #undef SetFbVar
;
    if ((__GET_VAR(data__->BDGENR,) > 4000)) {
      #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
      #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
SetFbVar(OUT,1)
      #undef GetFbVar
      #undef SetFbVar
;
    };
    if ((__GET_VAR(data__->BDGENR,) <= 4000)) {
      #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
      #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
SetFbVar(OUT,0)
      #undef GetFbVar
      #undef SetFbVar
;
    };
  };
  __SET_VAR(data__->,M,,__GET_VAR(data__->IN,));

  goto __end;

__end:
  return;
} // BOT_DETECT_body__() 





static inline BOOL __BOTTLEREFILL_LT__BOOL__TIME1(BOOL EN,
  UINT __PARAM_COUNT,
  TIME IN1,
  TIME IN2,
  BOTTLEREFILL *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->LT161_ENO,);
  __res = LT__BOOL__TIME(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->LT161_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __BOTTLEREFILL_LT__BOOL__TIME2(BOOL EN,
  UINT __PARAM_COUNT,
  TIME IN1,
  TIME IN2,
  BOTTLEREFILL *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->LT64_ENO,);
  __res = LT__BOOL__TIME(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->LT64_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __BOTTLEREFILL_LT__BOOL__TIME3(BOOL EN,
  UINT __PARAM_COUNT,
  TIME IN1,
  TIME IN2,
  BOTTLEREFILL *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->LT105_ENO,);
  __res = LT__BOOL__TIME(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->LT105_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __BOTTLEREFILL_LT__BOOL__TIME4(BOOL EN,
  UINT __PARAM_COUNT,
  TIME IN1,
  TIME IN2,
  BOTTLEREFILL *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->LT108_ENO,);
  __res = LT__BOOL__TIME(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->LT108_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __BOTTLEREFILL_LT__BOOL__TIME5(BOOL EN,
  UINT __PARAM_COUNT,
  TIME IN1,
  TIME IN2,
  BOTTLEREFILL *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->LT112_ENO,);
  __res = LT__BOOL__TIME(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->LT112_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __BOTTLEREFILL_LT__BOOL__TIME6(BOOL EN,
  UINT __PARAM_COUNT,
  TIME IN1,
  TIME IN2,
  BOTTLEREFILL *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->LT114_ENO,);
  __res = LT__BOOL__TIME(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->LT114_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __BOTTLEREFILL_GT__BOOL__TIME7(BOOL EN,
  UINT __PARAM_COUNT,
  TIME IN1,
  TIME IN2,
  BOTTLEREFILL *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->GT145_ENO,);
  __res = GT__BOOL__TIME(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->GT145_ENO,,__TMP_ENO);
  return __res;
}

void BOTTLEREFILL_init__(BOTTLEREFILL *data__, BOOL retain) {
  __INIT_VAR(data__->START,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SYSTEM_ON,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON0,retain);
  __INIT_VAR(data__->TIME_ON1,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TIME_ON2,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->BOT_DETECT_STATE,__BOOL_LITERAL(FALSE),retain)
  BOT_SIZE_RAND_GENERATOR_init__(&data__->BOT_SIZE_RAND_GENERATOR0,retain);
  BOT_STATE_RAND_GENERATOR_init__(&data__->BOT_STATE_RAND_GENERATOR0,retain);
  __INIT_VAR(data__->BOT_SIZE1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOT_SIZE2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOT_SIZE3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOT_SIZE4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOT_SIZE5,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FIRST_BOT_STATE_BIT,0,retain)
  __INIT_VAR(data__->SECOND_BOT_STATE_BIT,0,retain)
  __INIT_VAR(data__->THIRD_BOT_STATE_BIT,0,retain)
  __INIT_VAR(data__->FOURTH_BOT_STATE_BIT,0,retain)
  __INIT_VAR(data__->FIFTH_BOT_STATE_BIT,0,retain)
  __INIT_VAR(data__->FIRST_BOT_SIZE_BIT,0,retain)
  __INIT_VAR(data__->SECOND_BOT_SIZE_BIT,0,retain)
  __INIT_VAR(data__->THIRD_BOT_SIZE_BIT,0,retain)
  __INIT_VAR(data__->FOURTH_BOT_SIZE_BIT,0,retain)
  __INIT_VAR(data__->FIFTH_BOT_SIZE_BIT,0,retain)
  __INIT_VAR(data__->BIT_TIMER_STATE1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BIT_TIMER_STATE2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BIT_TIMER_STATE3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BIT_TIMER_STATE4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOT_STATE1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOT_STATE2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOT_STATE3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOT_STATE4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOT_STATE5,__BOOL_LITERAL(FALSE),retain)
  SR_init__(&data__->SR0,retain);
  SR_init__(&data__->SR1,retain);
  BOT_DETECT_init__(&data__->BOT_DETECT0,retain);
  SR_init__(&data__->SR2,retain);
  SR_init__(&data__->SR3,retain);
  SR_init__(&data__->SR4,retain);
  SR_init__(&data__->SR5,retain);
  SR_init__(&data__->SR6,retain);
  SR_init__(&data__->SR7,retain);
  __INIT_VAR(data__->FILL_LARGE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FILL_SMALL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PASS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DISCARD,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DOWN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FEED_MOTOR,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON1,retain);
  TON_init__(&data__->TON2,retain);
  __INIT_VAR(data__->LT153_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GT4_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LT161_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LT161_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GT61_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LT64_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LT64_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UDINT_TO_BOOL22_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LT17_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UDINT_TO_BOOL8_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UDINT_TO_BOOL41_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_BYTE109_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_BYTE9_OUT,0,retain)
  __INIT_VAR(data__->BYTE_TO_BOOL29_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GT37_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LT105_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LT105_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_BYTE12_OUT,0,retain)
  __INIT_VAR(data__->BYTE_TO_BOOL80_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_BYTE77_OUT,0,retain)
  __INIT_VAR(data__->BYTE_TO_BOOL31_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GT21_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LT108_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LT108_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_BYTE27_OUT,0,retain)
  __INIT_VAR(data__->BYTE_TO_BOOL82_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_BYTE79_OUT,0,retain)
  __INIT_VAR(data__->BYTE_TO_BOOL54_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GT43_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LT112_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LT112_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_BYTE49_OUT,0,retain)
  __INIT_VAR(data__->BYTE_TO_BOOL93_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_BYTE91_OUT,0,retain)
  __INIT_VAR(data__->BYTE_TO_BOOL69_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GT65_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LT114_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LT114_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_BYTE67_OUT,0,retain)
  __INIT_VAR(data__->BYTE_TO_BOOL100_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_BYTE98_OUT,0,retain)
  __INIT_VAR(data__->GT145_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GT145_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void BOTTLEREFILL_body__(BOTTLEREFILL *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,LT153_OUT,,LT__BOOL__TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (TIME)__GET_VAR(data__->TIME_ON2,),
    (TIME)__time_to_timespec(1, 1200, 0, 0, 0, 0)));
  __SET_VAR(data__->TON2.,EN,,__GET_VAR(data__->START,));
  __SET_VAR(data__->TON2.,IN,,__GET_VAR(data__->LT153_OUT,));
  __SET_VAR(data__->TON2.,PT,,__time_to_timespec(1, 1200, 0, 0, 0, 0));
  TON_body__(&data__->TON2);
  if (__GET_VAR(data__->TON2.ENO,)) {
    __SET_VAR(data__->,TIME_ON2,,__GET_VAR(data__->TON2.ET,));
  };
  __SET_VAR(data__->,GT4_OUT,,GT__BOOL__TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (TIME)__GET_VAR(data__->TIME_ON2,),
    (TIME)__time_to_timespec(1, 0, 0, 0, 0, 0)));
  __SET_VAR(data__->,LT161_OUT,,__BOTTLEREFILL_LT__BOOL__TIME1(
    (BOOL)__GET_VAR(data__->GT4_OUT,),
    (UINT)2,
    (TIME)__GET_VAR(data__->TIME_ON2,),
    (TIME)__time_to_timespec(1, 200, 0, 0, 0, 0),
    data__));
  __SET_VAR(data__->,FEED_MOTOR,,__GET_VAR(data__->LT161_OUT,));
  __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->START,));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 1200, 0, 0, 0, 0));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->,SYSTEM_ON,,(!(__GET_VAR(data__->STOP,)) && (__GET_VAR(data__->SYSTEM_ON,) || __GET_VAR(data__->TON1.Q,))));
  __SET_VAR(data__->,GT61_OUT,,GT__BOOL__TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (TIME)__GET_VAR(data__->TIME_ON1,),
    (TIME)__time_to_timespec(1, 1000, 0, 0, 0, 0)));
  __SET_VAR(data__->,LT64_OUT,,__BOTTLEREFILL_LT__BOOL__TIME2(
    (BOOL)__GET_VAR(data__->GT61_OUT,),
    (UINT)2,
    (TIME)__GET_VAR(data__->TIME_ON1,),
    (TIME)__time_to_timespec(1, 1200, 0, 0, 0, 0),
    data__));
  __SET_VAR(data__->BOT_STATE_RAND_GENERATOR0.,IN,,__GET_VAR(data__->LT64_OUT,));
  BOT_STATE_RAND_GENERATOR_body__(&data__->BOT_STATE_RAND_GENERATOR0);
  __SET_VAR(data__->,UDINT_TO_BOOL22_OUT,,UDINT_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->BOT_STATE_RAND_GENERATOR0.OUT,)));
  __SET_VAR(data__->,BOT_STATE1,,(__GET_VAR(data__->BOT_DETECT_STATE,) && __GET_VAR(data__->UDINT_TO_BOOL22_OUT,)));
  __SET_VAR(data__->,LT17_OUT,,LT__BOOL__TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (TIME)__GET_VAR(data__->TIME_ON1,),
    (TIME)__time_to_timespec(1, 1200, 0, 0, 0, 0)));
  __SET_VAR(data__->TON0.,EN,,__GET_VAR(data__->SYSTEM_ON,));
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->LT17_OUT,));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 1200, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  if (__GET_VAR(data__->TON0.ENO,)) {
    __SET_VAR(data__->,TIME_ON1,,__GET_VAR(data__->TON0.ET,));
  };
  __SET_VAR(data__->BOT_SIZE_RAND_GENERATOR0.,IN,,__GET_VAR(data__->LT64_OUT,));
  BOT_SIZE_RAND_GENERATOR_body__(&data__->BOT_SIZE_RAND_GENERATOR0);
  __SET_VAR(data__->,UDINT_TO_BOOL8_OUT,,UDINT_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->BOT_SIZE_RAND_GENERATOR0.OUT,)));
  __SET_VAR(data__->,BOT_SIZE1,,(__GET_VAR(data__->BOT_DETECT_STATE,) && __GET_VAR(data__->UDINT_TO_BOOL8_OUT,)));
  __SET_VAR(data__->BOT_DETECT0.,IN,,__GET_VAR(data__->LT64_OUT,));
  BOT_DETECT_body__(&data__->BOT_DETECT0);
  __SET_VAR(data__->,UDINT_TO_BOOL41_OUT,,UDINT_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->BOT_DETECT0.OUT,)));
  __SET_VAR(data__->,BOT_DETECT_STATE,,__GET_VAR(data__->UDINT_TO_BOOL41_OUT,));
  __SET_VAR(data__->,BOOL_TO_BYTE109_OUT,,BOOL_TO_BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)(__GET_VAR(data__->BOT_DETECT_STATE,) && __GET_VAR(data__->UDINT_TO_BOOL22_OUT,))));
  __SET_VAR(data__->,FIRST_BOT_STATE_BIT,,__GET_VAR(data__->BOOL_TO_BYTE109_OUT,));
  __SET_VAR(data__->,BOOL_TO_BYTE9_OUT,,BOOL_TO_BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)(__GET_VAR(data__->BOT_DETECT_STATE,) && __GET_VAR(data__->UDINT_TO_BOOL8_OUT,))));
  __SET_VAR(data__->,FIRST_BOT_SIZE_BIT,,__GET_VAR(data__->BOOL_TO_BYTE9_OUT,));
  __SET_VAR(data__->,BYTE_TO_BOOL29_OUT,,BYTE_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->FIRST_BOT_STATE_BIT,)));
  __SET_VAR(data__->,GT37_OUT,,GT__BOOL__TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (TIME)__GET_VAR(data__->TIME_ON1,),
    (TIME)__time_to_timespec(1, 800, 0, 0, 0, 0)));
  __SET_VAR(data__->,LT105_OUT,,__BOTTLEREFILL_LT__BOOL__TIME3(
    (BOOL)__GET_VAR(data__->GT37_OUT,),
    (UINT)2,
    (TIME)__GET_VAR(data__->TIME_ON1,),
    (TIME)__time_to_timespec(1, 1000, 0, 0, 0, 0),
    data__));
  __SET_VAR(data__->SR0.,S1,,(__GET_VAR(data__->BIT_TIMER_STATE1,) && __GET_VAR(data__->BYTE_TO_BOOL29_OUT,)));
  __SET_VAR(data__->SR0.,R,,__GET_VAR(data__->LT105_OUT,));
  SR_body__(&data__->SR0);
  __SET_VAR(data__->,BOOL_TO_BYTE12_OUT,,BOOL_TO_BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->SR0.Q1,)));
  __SET_VAR(data__->,SECOND_BOT_STATE_BIT,,__GET_VAR(data__->BOOL_TO_BYTE12_OUT,));
  __SET_VAR(data__->,BYTE_TO_BOOL80_OUT,,BYTE_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->FIRST_BOT_SIZE_BIT,)));
  __SET_VAR(data__->SR5.,S1,,(__GET_VAR(data__->BIT_TIMER_STATE1,) && __GET_VAR(data__->BYTE_TO_BOOL80_OUT,)));
  __SET_VAR(data__->SR5.,R,,__GET_VAR(data__->LT105_OUT,));
  SR_body__(&data__->SR5);
  __SET_VAR(data__->,BOOL_TO_BYTE77_OUT,,BOOL_TO_BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->SR5.Q1,)));
  __SET_VAR(data__->,SECOND_BOT_SIZE_BIT,,__GET_VAR(data__->BOOL_TO_BYTE77_OUT,));
  __SET_VAR(data__->,BOT_STATE2,,__GET_VAR(data__->SR0.Q1,));
  __SET_VAR(data__->,BIT_TIMER_STATE1,,__GET_VAR(data__->LT105_OUT,));
  __SET_VAR(data__->,BYTE_TO_BOOL31_OUT,,BYTE_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->SECOND_BOT_STATE_BIT,)));
  __SET_VAR(data__->,GT21_OUT,,GT__BOOL__TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (TIME)__GET_VAR(data__->TIME_ON1,),
    (TIME)__time_to_timespec(1, 600, 0, 0, 0, 0)));
  __SET_VAR(data__->,LT108_OUT,,__BOTTLEREFILL_LT__BOOL__TIME4(
    (BOOL)__GET_VAR(data__->GT21_OUT,),
    (UINT)2,
    (TIME)__GET_VAR(data__->TIME_ON1,),
    (TIME)__time_to_timespec(1, 800, 0, 0, 0, 0),
    data__));
  __SET_VAR(data__->SR1.,S1,,(__GET_VAR(data__->BIT_TIMER_STATE2,) && __GET_VAR(data__->BYTE_TO_BOOL31_OUT,)));
  __SET_VAR(data__->SR1.,R,,__GET_VAR(data__->LT108_OUT,));
  SR_body__(&data__->SR1);
  __SET_VAR(data__->,BOOL_TO_BYTE27_OUT,,BOOL_TO_BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->SR1.Q1,)));
  __SET_VAR(data__->,THIRD_BOT_STATE_BIT,,__GET_VAR(data__->BOOL_TO_BYTE27_OUT,));
  __SET_VAR(data__->,BYTE_TO_BOOL82_OUT,,BYTE_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->SECOND_BOT_SIZE_BIT,)));
  __SET_VAR(data__->SR4.,S1,,(__GET_VAR(data__->BIT_TIMER_STATE2,) && __GET_VAR(data__->BYTE_TO_BOOL82_OUT,)));
  __SET_VAR(data__->SR4.,R,,__GET_VAR(data__->LT108_OUT,));
  SR_body__(&data__->SR4);
  __SET_VAR(data__->,BOOL_TO_BYTE79_OUT,,BOOL_TO_BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->SR4.Q1,)));
  __SET_VAR(data__->,THIRD_BOT_SIZE_BIT,,__GET_VAR(data__->BOOL_TO_BYTE79_OUT,));
  __SET_VAR(data__->,BOT_STATE3,,__GET_VAR(data__->SR1.Q1,));
  __SET_VAR(data__->,BIT_TIMER_STATE2,,__GET_VAR(data__->LT108_OUT,));
  __SET_VAR(data__->,BYTE_TO_BOOL54_OUT,,BYTE_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->THIRD_BOT_STATE_BIT,)));
  __SET_VAR(data__->,GT43_OUT,,GT__BOOL__TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (TIME)__GET_VAR(data__->TIME_ON1,),
    (TIME)__time_to_timespec(1, 400, 0, 0, 0, 0)));
  __SET_VAR(data__->,LT112_OUT,,__BOTTLEREFILL_LT__BOOL__TIME5(
    (BOOL)__GET_VAR(data__->GT43_OUT,),
    (UINT)2,
    (TIME)__GET_VAR(data__->TIME_ON1,),
    (TIME)__time_to_timespec(1, 600, 0, 0, 0, 0),
    data__));
  __SET_VAR(data__->SR2.,S1,,(__GET_VAR(data__->BIT_TIMER_STATE3,) && __GET_VAR(data__->BYTE_TO_BOOL54_OUT,)));
  __SET_VAR(data__->SR2.,R,,__GET_VAR(data__->LT112_OUT,));
  SR_body__(&data__->SR2);
  __SET_VAR(data__->,BOOL_TO_BYTE49_OUT,,BOOL_TO_BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->SR2.Q1,)));
  __SET_VAR(data__->,FOURTH_BOT_STATE_BIT,,__GET_VAR(data__->BOOL_TO_BYTE49_OUT,));
  __SET_VAR(data__->,BYTE_TO_BOOL93_OUT,,BYTE_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->THIRD_BOT_SIZE_BIT,)));
  __SET_VAR(data__->SR6.,S1,,(__GET_VAR(data__->BIT_TIMER_STATE3,) && __GET_VAR(data__->BYTE_TO_BOOL93_OUT,)));
  __SET_VAR(data__->SR6.,R,,__GET_VAR(data__->LT112_OUT,));
  SR_body__(&data__->SR6);
  __SET_VAR(data__->,BOOL_TO_BYTE91_OUT,,BOOL_TO_BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->SR6.Q1,)));
  __SET_VAR(data__->,FOURTH_BOT_SIZE_BIT,,__GET_VAR(data__->BOOL_TO_BYTE91_OUT,));
  __SET_VAR(data__->,BOT_STATE4,,__GET_VAR(data__->SR2.Q1,));
  __SET_VAR(data__->,BIT_TIMER_STATE3,,__GET_VAR(data__->LT112_OUT,));
  __SET_VAR(data__->,BYTE_TO_BOOL69_OUT,,BYTE_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->FOURTH_BOT_STATE_BIT,)));
  __SET_VAR(data__->,GT65_OUT,,GT__BOOL__TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (TIME)__GET_VAR(data__->TIME_ON1,),
    (TIME)__time_to_timespec(1, 200, 0, 0, 0, 0)));
  __SET_VAR(data__->,LT114_OUT,,__BOTTLEREFILL_LT__BOOL__TIME6(
    (BOOL)__GET_VAR(data__->GT65_OUT,),
    (UINT)2,
    (TIME)__GET_VAR(data__->TIME_ON1,),
    (TIME)__time_to_timespec(1, 400, 0, 0, 0, 0),
    data__));
  __SET_VAR(data__->SR3.,S1,,(__GET_VAR(data__->BIT_TIMER_STATE4,) && __GET_VAR(data__->BYTE_TO_BOOL69_OUT,)));
  __SET_VAR(data__->SR3.,R,,__GET_VAR(data__->LT114_OUT,));
  SR_body__(&data__->SR3);
  __SET_VAR(data__->,BOOL_TO_BYTE67_OUT,,BOOL_TO_BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->SR3.Q1,)));
  __SET_VAR(data__->,FIFTH_BOT_STATE_BIT,,__GET_VAR(data__->BOOL_TO_BYTE67_OUT,));
  __SET_VAR(data__->,BYTE_TO_BOOL100_OUT,,BYTE_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BYTE)__GET_VAR(data__->FOURTH_BOT_SIZE_BIT,)));
  __SET_VAR(data__->SR7.,S1,,(__GET_VAR(data__->BIT_TIMER_STATE4,) && __GET_VAR(data__->BYTE_TO_BOOL100_OUT,)));
  __SET_VAR(data__->SR7.,R,,__GET_VAR(data__->LT114_OUT,));
  SR_body__(&data__->SR7);
  __SET_VAR(data__->,BOOL_TO_BYTE98_OUT,,BOOL_TO_BYTE(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->SR7.Q1,)));
  __SET_VAR(data__->,FIFTH_BOT_SIZE_BIT,,__GET_VAR(data__->BOOL_TO_BYTE98_OUT,));
  __SET_VAR(data__->,BOT_STATE5,,__GET_VAR(data__->SR3.Q1,));
  __SET_VAR(data__->,BIT_TIMER_STATE4,,__GET_VAR(data__->LT114_OUT,));
  __SET_VAR(data__->,BOT_SIZE2,,__GET_VAR(data__->SR5.Q1,));
  __SET_VAR(data__->,BOT_SIZE3,,__GET_VAR(data__->SR4.Q1,));
  __SET_VAR(data__->,BOT_SIZE4,,__GET_VAR(data__->SR6.Q1,));
  __SET_VAR(data__->,BOT_SIZE5,,__GET_VAR(data__->SR7.Q1,));
  __SET_VAR(data__->,GT145_OUT,,__BOTTLEREFILL_GT__BOOL__TIME7(
    (BOOL)(__GET_VAR(data__->BOT_STATE3,) && __GET_VAR(data__->SYSTEM_ON,)),
    (UINT)2,
    (TIME)__GET_VAR(data__->TIME_ON1,),
    (TIME)__time_to_timespec(1, 500, 0, 0, 0, 0),
    data__));
  __SET_VAR(data__->,FILL_LARGE,,(__GET_VAR(data__->BOT_SIZE3,) && __GET_VAR(data__->GT145_OUT,)));
  __SET_VAR(data__->,FILL_SMALL,,(!(__GET_VAR(data__->BOT_SIZE3,)) && __GET_VAR(data__->GT145_OUT,)));
  __SET_VAR(data__->,PASS,,(__GET_VAR(data__->BOT_STATE4,) && __GET_VAR(data__->SYSTEM_ON,)));
  __SET_VAR(data__->,DISCARD,,(!(__GET_VAR(data__->BOT_STATE4,)) && __GET_VAR(data__->SYSTEM_ON,)));
  __SET_VAR(data__->,UP,,((!(__GET_VAR(data__->BOT_SIZE5,)) && __GET_VAR(data__->BOT_STATE5,)) && __GET_VAR(data__->SYSTEM_ON,)));
  __SET_VAR(data__->,DOWN,,((__GET_VAR(data__->BOT_SIZE5,) && __GET_VAR(data__->BOT_STATE5,)) && __GET_VAR(data__->SYSTEM_ON,)));

  goto __end;

__end:
  return;
} // BOTTLEREFILL_body__() 





