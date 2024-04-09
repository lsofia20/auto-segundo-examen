PROGRAM program0
  VAR
    boton_inicio AT %IX0.0 : BOOL;
    boton_parada AT %IX0.1 : BOOL;
    sensor_caja AT %IW0 : WORD;
    motor_cinta AT %QX0.0 : BOOL;
    motor_rodillo AT %QX0.1 : BOOL;
  END_VAR
  VAR
    auxiliar_inicio : BOOL;
    auxiliar_sensor : BOOL;
    auxiliar_reloj : BOOL;
    sensor_esta_conectado : BOOL;
    sensor_tapado : BOOL;
  END_VAR
  VAR CONSTANT
    min_luz : WORD := 3500;
    max_tiempo_rodillo : TIME := T#500ms;
  END_VAR
  VAR
    reloj : TOF;
    _TMP_GT47_ENO : BOOL;
    _TMP_GT47_OUT : BOOL;
    _TMP_LT25_ENO : BOOL;
    _TMP_LT25_OUT : BOOL;
  END_VAR

  auxiliar_inicio := NOT(boton_parada) AND (auxiliar_inicio OR boton_inicio);
  reloj(IN := auxiliar_sensor AND auxiliar_inicio, PT := max_tiempo_rodillo);
  auxiliar_reloj := reloj.Q;
  _TMP_GT47_OUT := GT(EN := auxiliar_inicio, IN1 := sensor_caja, IN2 := 0, ENO => _TMP_GT47_ENO);
  IF _TMP_GT47_ENO THEN
      sensor_esta_conectado := _TMP_GT47_OUT;
  END_IF;
  _TMP_LT25_OUT := LT(EN := auxiliar_inicio, IN1 := sensor_caja, IN2 := min_luz, ENO => _TMP_LT25_ENO);
  IF _TMP_LT25_ENO THEN
      sensor_tapado := _TMP_LT25_OUT;
  END_IF;
  auxiliar_sensor := sensor_tapado AND sensor_esta_conectado;
  motor_cinta := auxiliar_inicio;
  motor_rodillo := auxiliar_reloj AND auxiliar_inicio;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
