@ECHO OFF
IF EXIST "repro.ico" (
  DEL "repro.ico"
)
CALL PYTHON "pGenerateICO.py" "repro.ico"
CALL "\dev\py\headsup\headsup.cmd" "repro.ico"