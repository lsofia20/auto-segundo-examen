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





static inline BOOL __PROGRAM0_GT__BOOL__WORD1(BOOL EN,
  UINT __PARAM_COUNT,
  WORD IN1,
  WORD IN2,
  PROGRAM0 *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_GT47_ENO,);
  __res = GT__BOOL__WORD(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_GT47_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __PROGRAM0_LT__BOOL__WORD2(BOOL EN,
  UINT __PARAM_COUNT,
  WORD IN1,
  WORD IN2,
  PROGRAM0 *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_LT25_ENO,);
  __res = LT__BOOL__WORD(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_LT25_ENO,,__TMP_ENO);
  return __res;
}

void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_LOCATED(BOOL,__IX0_0,data__->BOTON_INICIO,retain)
  __INIT_LOCATED_VALUE(data__->BOTON_INICIO,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1,data__->BOTON_PARADA,retain)
  __INIT_LOCATED_VALUE(data__->BOTON_PARADA,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(WORD,__IW0,data__->SENSOR_CAJA,retain)
  __INIT_LOCATED_VALUE(data__->SENSOR_CAJA,0)
  __INIT_LOCATED(BOOL,__QX0_0,data__->MOTOR_CINTA,retain)
  __INIT_LOCATED_VALUE(data__->MOTOR_CINTA,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_1,data__->MOTOR_RODILLO,retain)
  __INIT_LOCATED_VALUE(data__->MOTOR_RODILLO,__BOOL_LITERAL(FALSE))
  __INIT_VAR(data__->AUXILIAR_INICIO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AUXILIAR_SENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AUXILIAR_RELOJ,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSOR_ESTA_CONECTADO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSOR_TAPADO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MIN_LUZ,3500,retain)
  __INIT_VAR(data__->MAX_TIEMPO_RODILLO,__time_to_timespec(1, 500, 0, 0, 0, 0),retain)
  TOF_init__(&data__->RELOJ,retain);
  __INIT_VAR(data__->_TMP_GT47_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT47_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT25_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT25_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,AUXILIAR_INICIO,,(!(__GET_LOCATED(data__->BOTON_PARADA,)) && (__GET_VAR(data__->AUXILIAR_INICIO,) || __GET_LOCATED(data__->BOTON_INICIO,))));
  __SET_VAR(data__->RELOJ.,IN,,(__GET_VAR(data__->AUXILIAR_SENSOR,) && __GET_VAR(data__->AUXILIAR_INICIO,)));
  __SET_VAR(data__->RELOJ.,PT,,__GET_VAR(data__->MAX_TIEMPO_RODILLO,));
  TOF_body__(&data__->RELOJ);
  __SET_VAR(data__->,AUXILIAR_RELOJ,,__GET_VAR(data__->RELOJ.Q,));
  __SET_VAR(data__->,_TMP_GT47_OUT,,__PROGRAM0_GT__BOOL__WORD1(
    (BOOL)__GET_VAR(data__->AUXILIAR_INICIO,),
    (UINT)2,
    (WORD)__GET_LOCATED(data__->SENSOR_CAJA,),
    (WORD)0,
    data__));
  if (__GET_VAR(data__->_TMP_GT47_ENO,)) {
    __SET_VAR(data__->,SENSOR_ESTA_CONECTADO,,__GET_VAR(data__->_TMP_GT47_OUT,));
  };
  __SET_VAR(data__->,_TMP_LT25_OUT,,__PROGRAM0_LT__BOOL__WORD2(
    (BOOL)__GET_VAR(data__->AUXILIAR_INICIO,),
    (UINT)2,
    (WORD)__GET_LOCATED(data__->SENSOR_CAJA,),
    (WORD)__GET_VAR(data__->MIN_LUZ,),
    data__));
  if (__GET_VAR(data__->_TMP_LT25_ENO,)) {
    __SET_VAR(data__->,SENSOR_TAPADO,,__GET_VAR(data__->_TMP_LT25_OUT,));
  };
  __SET_VAR(data__->,AUXILIAR_SENSOR,,(__GET_VAR(data__->SENSOR_TAPADO,) && __GET_VAR(data__->SENSOR_ESTA_CONECTADO,)));
  __SET_LOCATED(data__->,MOTOR_CINTA,,__GET_VAR(data__->AUXILIAR_INICIO,));
  __SET_LOCATED(data__->,MOTOR_RODILLO,,(__GET_VAR(data__->AUXILIAR_RELOJ,) && __GET_VAR(data__->AUXILIAR_INICIO,)));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





