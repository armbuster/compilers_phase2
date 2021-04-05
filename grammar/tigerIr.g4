grammar tigerIr;


irProgram : function functionSeq;
functionSeq : function functionSeq # functionSeqNonempty
            |                      # functionSeqEmpty
            ;
function : START_FUNCTION ID NEWLINE typeId ID OPENPAREN paramList CLOSEPAREN NEWLINE INT_LIST varList NEWLINE FLOAT_LIST varList NEWLINE funcBody END_FUNCTION ID multipleNewline;
paramList : param paramListTail # paramListNonEmpty
        | # paramListEmpty
        ;
paramListTail : COMMA param paramListTail # paramListTailNonEmpty
        | # paramListTailEmpty
        ;
param : typeId ID;

typeId : INT # typeIdInt
        | FLOAT # typeIdFloat
        | VOID # typeIdVoid
        ;

varList : ID arrayDeref COMMA varList # varListExpand
        | ID arrayDeref # varListSingle
        | # varListEmpty
        ;

arrayDeref : OPENBRACK INTLIT CLOSEBRACK # arrayDerefNonempty
        | # arrayDerefEmpty
        ;

multipleNewline : NEWLINE multipleNewline
                |
                ;


funcBody : ID COLON NEWLINE statSeq;
statSeq : stat statSeq # statSeqNonempty
        | # statSeqEmpty
        ;

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
      | label
      ;
        


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


call : CALL COMMA ID COMMA exprList NEWLINE;
callr : CALLR COMMA val COMMA ID COMMA exprList NEWLINE;


array_store : ARRAY_STORE COMMA val COMMA val COMMA val NEWLINE;
array_load : ARRAY_LOAD COMMA val COMMA val COMMA val NEWLINE;
array_assign : ASSIGN COMMA val COMMA val COMMA val NEWLINE;

exprList : val COMMA exprList optionalComma # exprListContinue
        | val # exprListSingle
        | # exprListEmpty
        ;

optionalComma : COMMA |;

val : ID # valId
    | INTLIT # valIntLit
    | FLOATLIT # valFloatLit
    ;


ARRAY_STORE : 'array_store' ;
ARRAY_LOAD : 'array_load' ;
ASSIGN : 'assign' ;
CALL : 'call' ;
CALLR : 'callr' ;
ADD : 'add' ;
SUB : 'sub' ;
MULT : 'mult' ;
DIV : 'div' ;
AND : 'and';
OR : 'or';
BREQ : 'breq';
BRNEQ : 'brneq';
BRLT : 'brlt';
BRGT : 'brgt';
BRLEQ : 'brleq';
BRGEQ : 'brgeq';
GOTO : 'goto';
RETURN : 'return';

FLOAT : 'float' ;
INT : 'int' ;
VOID : 'void' ;


INT_LIST : 'int-list:' ;
FLOAT_LIST : 'float-list:' ;


COMMA : ',' ;
COLON : ':' ;
SEMICOLON : ';';
OPENPAREN : '(';
CLOSEPAREN : ')';
OPENBRACK : '[';
CLOSEBRACK : ']';
OPENCURLY : '{';
CLOSECURLY : '}';
NEWLINE : '\n';

START_FUNCTION : '#start_function' ;
END_FUNCTION : '#end_function' ;

ID : '_'?[a-zA-Z]([a-zA-Z]|[0-9]|'_')*;
INTLIT : '0'|[1-9][0-9]*;
FLOATLIT : ('0'|[1-9][0-9]*)'.'[0-9]*;
WS : [ \t\b]+ -> skip ;