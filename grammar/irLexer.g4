lexer grammar irLexer;


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

ID : '_'?([a-zA-Z]|[0-9]|'_')+;
INTLIT : '0'|[1-9][0-9]*;
FLOATLIT : ('0'|[1-9][0-9]*)'.'[0-9]*;
WS : [ \t\b]+ -> skip ;