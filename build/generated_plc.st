TYPE
  datatype0 : ARRAY [1..10] OF BYTE;
END_TYPE

FUNCTION_BLOCK bot_size_rand_generator
  VAR_INPUT
    IN : BOOL;
  END_VAR
  VAR
    BSZGENR : UINT;
    M : BOOL;
    INIT : BOOL;
  END_VAR
  VAR_OUTPUT
    OUT : UDINT;
  END_VAR

  (* Initialize our random generator *)
  (* This IF is called only the first time this *)
  (* block executes *)
  IF INIT = 0 THEN
    {time_t t;
    srand((unsigned) time(&t))}
    INIT := 1;
  END_IF;

  IF M = 0 and IN = 1 THEN
    (* Using pragma to write code directly in C. *)
    (* You can access your PLC program variables using *)
    (* GetFbVar(var,...) and SetFbVar(var,val,...) calls *)
    {SetFbVar(BSZGENR,rand())}
    IF BSZGENR > 9000 THEN
      {SetFbVar(OUT,1)}
    END_IF;
    IF BSZGENR <= 9000 THEN
      {SetFbVar(OUT,0)}
    END_IF;
  END_IF;
  M := IN;
END_FUNCTION_BLOCK

FUNCTION_BLOCK bot_state_rand_generator
  VAR_INPUT
    IN : BOOL;
  END_VAR
  VAR
    BSGENR : UINT;
    M : BOOL;
    INIT : BOOL;
  END_VAR
  VAR_OUTPUT
    OUT : UDINT;
  END_VAR

  (* Initialize our random generator *)
  (* This IF is called only the first time this *)
  (* block executes *)
  IF INIT = 0 THEN
    {time_t t;
    srand((unsigned) time(&t))}
    INIT := 1;
  END_IF;

  IF M = 0 and IN = 1 THEN
    (* Using pragma to write code directly in C. *)
    (* You can access your PLC program variables using *)
    (* GetFbVar(var,...) and SetFbVar(var,val,...) calls *)
    {SetFbVar(BSGENR,rand())}
    IF BSGENR > 4000 THEN
      {SetFbVar(OUT,1)}
    END_IF;
    IF BSGENR <= 4000 THEN
      {SetFbVar(OUT,0)}
    END_IF;
  END_IF;
  M := IN;
END_FUNCTION_BLOCK

FUNCTION_BLOCK bot_detect
  VAR_INPUT
    IN : BOOL;
  END_VAR
  VAR
    BDGENR : UINT;
    M : BOOL;
    INIT : BOOL;
  END_VAR
  VAR_OUTPUT
    OUT : UDINT;
  END_VAR

  (* Initialize our random generator *)
  (* This IF is called only the first time this *)
  (* block executes *)
  IF INIT = 0 THEN
    {time_t t;
    srand((unsigned) time(&t))}
    INIT := 1;
  END_IF;

  IF M = 0 and IN = 1 THEN
    (* Using pragma to write code directly in C. *)
    (* You can access your PLC program variables using *)
    (* GetFbVar(var,...) and SetFbVar(var,val,...) calls *)
    {SetFbVar(BDGENR,rand())}
    IF BDGENR > 4000 THEN
      {SetFbVar(OUT,1)}
    END_IF;
    IF BDGENR <= 4000 THEN
      {SetFbVar(OUT,0)}
    END_IF;
  END_IF;
  M := IN;
END_FUNCTION_BLOCK

PROGRAM BottleRefill
  VAR
    Start AT %IX0.0 : BOOL;
    Stop AT %IX0.1 : BOOL;
    System_On AT %QX0.0 : BOOL;
  END_VAR
  VAR
    TON0 : TON;
    Time_On1 : TIME;
    Time_On2 : TIME;
    Bot_Detect_State : BOOL;
    bot_size_rand_generator0 : bot_size_rand_generator;
    bot_state_rand_generator0 : bot_state_rand_generator;
    Bot_Size1 : BOOL;
    Bot_Size2 : BOOL;
    Bot_Size3 : BOOL;
    Bot_Size4 : BOOL;
    Bot_Size5 : BOOL;
    first_bot_state_bit : BYTE;
    second_bot_state_bit : BYTE;
    third_bot_state_bit : BYTE;
    fourth_bot_state_bit : BYTE;
    fifth_bot_state_bit : BYTE;
    first_bot_size_bit : BYTE;
    second_bot_size_bit : BYTE;
    third_bot_size_bit : BYTE;
    fourth_bot_size_bit : BYTE;
    fifth_bot_size_bit : BYTE;
    Bit_Timer_State1 : BOOL;
    Bit_Timer_State2 : BOOL;
    Bit_Timer_State3 : BOOL;
    Bit_Timer_State4 : BOOL;
    Bot_State1 : BOOL;
    Bot_State2 : BOOL;
    Bot_State3 : BOOL;
    Bot_State4 : BOOL;
    Bot_State5 : BOOL;
    SR0 : SR;
    SR1 : SR;
    bot_detect0 : bot_detect;
    SR2 : SR;
    SR3 : SR;
    SR4 : SR;
    SR5 : SR;
    SR6 : SR;
    SR7 : SR;
  END_VAR
  VAR
    Fill_Large AT %QX0.1 : BOOL;
    Fill_Small AT %QX0.2 : BOOL;
    Pass AT %QX0.3 : BOOL;
    Discard AT %QX0.4 : BOOL;
    Up AT %QX0.5 : BOOL;
    Down AT %QX0.6 : BOOL;
    Feed_Motor AT %QX0.7 : BOOL;
  END_VAR
  VAR
    TON1 : TON;
    TON2 : TON;
    LT153_OUT : BOOL;
    GT4_OUT : BOOL;
    LT161_ENO : BOOL;
    LT161_OUT : BOOL;
    GT61_OUT : BOOL;
    LT64_ENO : BOOL;
    LT64_OUT : BOOL;
    UDINT_TO_BOOL22_OUT : BOOL;
    LT17_OUT : BOOL;
    UDINT_TO_BOOL8_OUT : BOOL;
    UDINT_TO_BOOL41_OUT : BOOL;
    BOOL_TO_BYTE109_OUT : BYTE;
    BOOL_TO_BYTE9_OUT : BYTE;
    BYTE_TO_BOOL29_OUT : BOOL;
    GT37_OUT : BOOL;
    LT105_ENO : BOOL;
    LT105_OUT : BOOL;
    BOOL_TO_BYTE12_OUT : BYTE;
    BYTE_TO_BOOL80_OUT : BOOL;
    BOOL_TO_BYTE77_OUT : BYTE;
    BYTE_TO_BOOL31_OUT : BOOL;
    GT21_OUT : BOOL;
    LT108_ENO : BOOL;
    LT108_OUT : BOOL;
    BOOL_TO_BYTE27_OUT : BYTE;
    BYTE_TO_BOOL82_OUT : BOOL;
    BOOL_TO_BYTE79_OUT : BYTE;
    BYTE_TO_BOOL54_OUT : BOOL;
    GT43_OUT : BOOL;
    LT112_ENO : BOOL;
    LT112_OUT : BOOL;
    BOOL_TO_BYTE49_OUT : BYTE;
    BYTE_TO_BOOL93_OUT : BOOL;
    BOOL_TO_BYTE91_OUT : BYTE;
    BYTE_TO_BOOL69_OUT : BOOL;
    GT65_OUT : BOOL;
    LT114_ENO : BOOL;
    LT114_OUT : BOOL;
    BOOL_TO_BYTE67_OUT : BYTE;
    BYTE_TO_BOOL100_OUT : BOOL;
    BOOL_TO_BYTE98_OUT : BYTE;
    GT145_ENO : BOOL;
    GT145_OUT : BOOL;
  END_VAR

  LT153_OUT := LT(Time_On2, T#1200ms);
  TON2(EN := Start, IN := LT153_OUT, PT := T#1200ms);
  IF TON2.ENO THEN
      Time_On2 := TON2.ET;
  END_IF;
  GT4_OUT := GT(Time_On2, T#0ms);
  LT161_OUT := LT(EN := GT4_OUT, IN1 := Time_On2, IN2 := T#200ms, ENO => LT161_ENO);
  Feed_Motor := LT161_OUT;
  TON1(IN := Start, PT := T#1200ms);
  System_On := NOT(Stop) AND (System_On OR TON1.Q);
  GT61_OUT := GT(Time_On1, T#1000ms);
  LT64_OUT := LT(EN := GT61_OUT, IN1 := Time_On1, IN2 := T#1200ms, ENO => LT64_ENO);
  bot_state_rand_generator0(IN := LT64_OUT);
  UDINT_TO_BOOL22_OUT := UDINT_TO_BOOL(bot_state_rand_generator0.OUT);
  Bot_State1 := Bot_Detect_State AND UDINT_TO_BOOL22_OUT;
  LT17_OUT := LT(Time_On1, T#1200ms);
  TON0(EN := System_On, IN := LT17_OUT, PT := T#1200ms);
  IF TON0.ENO THEN
      Time_On1 := TON0.ET;
  END_IF;
  bot_size_rand_generator0(IN := LT64_OUT);
  UDINT_TO_BOOL8_OUT := UDINT_TO_BOOL(bot_size_rand_generator0.OUT);
  Bot_Size1 := Bot_Detect_State AND UDINT_TO_BOOL8_OUT;
  bot_detect0(IN := LT64_OUT);
  UDINT_TO_BOOL41_OUT := UDINT_TO_BOOL(bot_detect0.OUT);
  Bot_Detect_State := UDINT_TO_BOOL41_OUT;
  BOOL_TO_BYTE109_OUT := BOOL_TO_BYTE(Bot_Detect_State AND UDINT_TO_BOOL22_OUT);
  first_bot_state_bit := BOOL_TO_BYTE109_OUT;
  BOOL_TO_BYTE9_OUT := BOOL_TO_BYTE(Bot_Detect_State AND UDINT_TO_BOOL8_OUT);
  first_bot_size_bit := BOOL_TO_BYTE9_OUT;
  BYTE_TO_BOOL29_OUT := BYTE_TO_BOOL(first_bot_state_bit);
  GT37_OUT := GT(Time_On1, T#800ms);
  LT105_OUT := LT(EN := GT37_OUT, IN1 := Time_On1, IN2 := T#1000ms, ENO => LT105_ENO);
  SR0(S1 := Bit_Timer_State1 AND BYTE_TO_BOOL29_OUT, R := LT105_OUT);
  BOOL_TO_BYTE12_OUT := BOOL_TO_BYTE(SR0.Q1);
  second_bot_state_bit := BOOL_TO_BYTE12_OUT;
  BYTE_TO_BOOL80_OUT := BYTE_TO_BOOL(first_bot_size_bit);
  SR5(S1 := Bit_Timer_State1 AND BYTE_TO_BOOL80_OUT, R := LT105_OUT);
  BOOL_TO_BYTE77_OUT := BOOL_TO_BYTE(SR5.Q1);
  second_bot_size_bit := BOOL_TO_BYTE77_OUT;
  Bot_State2 := SR0.Q1;
  Bit_Timer_State1 := LT105_OUT;
  BYTE_TO_BOOL31_OUT := BYTE_TO_BOOL(second_bot_state_bit);
  GT21_OUT := GT(Time_On1, T#600ms);
  LT108_OUT := LT(EN := GT21_OUT, IN1 := Time_On1, IN2 := T#800ms, ENO => LT108_ENO);
  SR1(S1 := Bit_Timer_State2 AND BYTE_TO_BOOL31_OUT, R := LT108_OUT);
  BOOL_TO_BYTE27_OUT := BOOL_TO_BYTE(SR1.Q1);
  third_bot_state_bit := BOOL_TO_BYTE27_OUT;
  BYTE_TO_BOOL82_OUT := BYTE_TO_BOOL(second_bot_size_bit);
  SR4(S1 := Bit_Timer_State2 AND BYTE_TO_BOOL82_OUT, R := LT108_OUT);
  BOOL_TO_BYTE79_OUT := BOOL_TO_BYTE(SR4.Q1);
  third_bot_size_bit := BOOL_TO_BYTE79_OUT;
  Bot_State3 := SR1.Q1;
  Bit_Timer_State2 := LT108_OUT;
  BYTE_TO_BOOL54_OUT := BYTE_TO_BOOL(third_bot_state_bit);
  GT43_OUT := GT(Time_On1, T#400ms);
  LT112_OUT := LT(EN := GT43_OUT, IN1 := Time_On1, IN2 := T#600ms, ENO => LT112_ENO);
  SR2(S1 := Bit_Timer_State3 AND BYTE_TO_BOOL54_OUT, R := LT112_OUT);
  BOOL_TO_BYTE49_OUT := BOOL_TO_BYTE(SR2.Q1);
  fourth_bot_state_bit := BOOL_TO_BYTE49_OUT;
  BYTE_TO_BOOL93_OUT := BYTE_TO_BOOL(third_bot_size_bit);
  SR6(S1 := Bit_Timer_State3 AND BYTE_TO_BOOL93_OUT, R := LT112_OUT);
  BOOL_TO_BYTE91_OUT := BOOL_TO_BYTE(SR6.Q1);
  fourth_bot_size_bit := BOOL_TO_BYTE91_OUT;
  Bot_State4 := SR2.Q1;
  Bit_Timer_State3 := LT112_OUT;
  BYTE_TO_BOOL69_OUT := BYTE_TO_BOOL(fourth_bot_state_bit);
  GT65_OUT := GT(Time_On1, T#200ms);
  LT114_OUT := LT(EN := GT65_OUT, IN1 := Time_On1, IN2 := T#400ms, ENO => LT114_ENO);
  SR3(S1 := Bit_Timer_State4 AND BYTE_TO_BOOL69_OUT, R := LT114_OUT);
  BOOL_TO_BYTE67_OUT := BOOL_TO_BYTE(SR3.Q1);
  fifth_bot_state_bit := BOOL_TO_BYTE67_OUT;
  BYTE_TO_BOOL100_OUT := BYTE_TO_BOOL(fourth_bot_size_bit);
  SR7(S1 := Bit_Timer_State4 AND BYTE_TO_BOOL100_OUT, R := LT114_OUT);
  BOOL_TO_BYTE98_OUT := BOOL_TO_BYTE(SR7.Q1);
  fifth_bot_size_bit := BOOL_TO_BYTE98_OUT;
  Bot_State5 := SR3.Q1;
  Bit_Timer_State4 := LT114_OUT;
  Bot_Size2 := SR5.Q1;
  Bot_Size3 := SR4.Q1;
  Bot_Size4 := SR6.Q1;
  Bot_Size5 := SR7.Q1;
  GT145_OUT := GT(EN := Bot_State3 AND System_On, IN1 := Time_On1, IN2 := T#500ms, ENO => GT145_ENO);
  Fill_Large := Bot_Size3 AND GT145_OUT;
  Fill_Small := NOT(Bot_Size3) AND GT145_OUT;
  Pass := Bot_State4 AND System_On;
  Discard := NOT(Bot_State4) AND System_On;
  Up := NOT(Bot_Size5) AND Bot_State5 AND System_On;
  Down := Bot_Size5 AND Bot_State5 AND System_On;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : BottleRefill;
  END_RESOURCE
END_CONFIGURATION
