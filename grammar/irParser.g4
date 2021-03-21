parser grammar irParser;

options { tokenVocab=irLexer; }


irProgram : function functionSeq;
functionSeq : function functionSeq
            |;
function : START_FUNCTION ID NEWLINE typeId ID OPENPAREN paramList CLOSEPAREN NEWLINE INT_LIST varList NEWLINE FLOAT_LIST varList NEWLINE funcBody END_FUNCTION ID NEWLINE;
paramList : param paramListTail
        |
        ;
paramListTail : COMMA param paramListTail
        |
        ;
param : typeId ID;

typeId : INT | FLOAT | VOID;

varList : ID COMMA varList
        | ID
        |;


funcBody : ID COLON NEWLINE statSeq;
statSeq : stat statSeq
        |;

stat :  assign
      |  add
      |  sub
      |  mult
      |  div
      |  and_op
      |  or_op
      |  goto_op
      |  breq
      |  brneq
      |  brlt
      |  brgt
      |  brleq
      |  brgeq
      |  return_void
      |  return_nonvoid
      |  call
      |  callr
      |  array_store
      |  array_load
      |  array_assign
      | label;
        


label : ID optionalColon NEWLINE;
optionalColon : COLON |;
assign : ASSIGN COMMA val COMMA val COMMA NEWLINE;
add : ADD COMMA val COMMA val COMMA val NEWLINE;
sub : SUB COMMA val COMMA val COMMA val NEWLINE;
mult : MULT COMMA val COMMA val COMMA val NEWLINE;
div : DIV COMMA val COMMA val COMMA val NEWLINE;
and_op : AND COMMA val COMMA val COMMA val NEWLINE;
or_op : OR COMMA val COMMA val COMMA val NEWLINE;

goto_op : GOTO COMMA ID COMMA COMMA NEWLINE; 

breq : BREQ COMMA val COMMA val COMMA ID NEWLINE;
brneq : BRNEQ COMMA val COMMA val COMMA ID NEWLINE;
brlt : BRLT COMMA val COMMA val COMMA ID NEWLINE;
brgt : BRGT COMMA val COMMA val COMMA ID NEWLINE;
brleq : BRLEQ COMMA val COMMA val COMMA ID NEWLINE;
brgeq : BRGEQ COMMA val COMMA val COMMA ID NEWLINE;
return_void : RETURN COMMA COMMA COMMA NEWLINE;
return_nonvoid : RETURN COMMA val COMMA COMMA NEWLINE;


call : CALL COMMA exprList NEWLINE;
callr : CALLR COMMA exprList NEWLINE;


array_store : ARRAY_STORE COMMA val COMMA val COMMA val NEWLINE;
array_load : ARRAY_LOAD COMMA val COMMA val COMMA val NEWLINE;
array_assign : ASSIGN COMMA val COMMA val COMMA val NEWLINE;

exprList : val COMMA exprList optionalComma
        | val
        |;

optionalComma : COMMA |;

val : ID | INTLIT | FLOATLIT;