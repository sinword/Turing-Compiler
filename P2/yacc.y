 /* It is a parser fo Turing language */
%{
#include "symboltable.hpp"
#define Trace(t)        { /*printf("Reducing %s\n", t);*/ }
#define table_msg(msg)    { printf("\n\033[34m\033[47m%s\033[0m\n", msg); }
extern int yylex(void);
extern void warning(char *msg);
extern void yyerror(char *msg);

TableList table_stack;
SymbolTable current_table;
vector<Data> para_list;
Func_return func_return;
%}

/* tokens */

%token DOT COMMA COLON LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE SEMICOLON

%token ASSIGN PUT _BEGIN DECREASING DEFAULT DO WHEN IF ELSE END EXIT FOR FUNCTION GET LOOP OF PROCEDURE REAL RESULT RETURN SKIP THEN 
%token VAR CONST INT STRING ARRAY BOOL

%left NOT AND OR
%left LT LE EQ GE GT NE
%left ADD SUB
%left MUL DIV MOD
%nonassoc UMINUS

%token<value> I_CONST
%token<value> F_CONST
%token<value> STR_CONST ID
%token<value> TRUE FALSE

%type<type> datatype
%type<data> const_variable_declaration var_variable_declaration 
%type<data> const_val const_expr function_call_stmt

%start program
%%
program
        : variable_declaration program {
                Trace("program -> variable_declaration program");
        }
        | function_declaration program {
                Trace("program -> function_declaration program");
        }
        | procedure_declaration program {
                Trace("program -> procedure_declaration program");
        }
        | stmt program {
                Trace("program -> stmt program");
        }
        |
        ;

variable_declaration
        : CONST ID const_variable_declaration {
                Trace("variable_declaration -> CONST ID const_variable_declaration");
                Data new_data;
                new_data.id = $2.s_val;
                new_data.kind = Kind::const_kind;
                new_data.type = $3.type;
                if(!current_table.insert(new_data)) {
                        warning("Redeclaration of const in current scope");
                }
                
                // current_table.dump();
        }
        | VAR ID var_variable_declaration {
                Trace("variable_declaration -> VAR ID var_variable_declaration");
                Data new_data;
                new_data.id = $2.s_val;
                new_data.kind = Kind::var_kind;
                new_data.type = $3.type;
                if ($3.array.empty()) {
                        new_data.value = $3.value;
                }
                else {
                        new_data.arr_start = $3.arr_start;
                        new_data.arr_end = $3.arr_end;
                        new_data.array = $3.array;
                }

                if(!current_table.insert(new_data)) {
                        warning("Redeclaration of var in current scope");
                }
        
                // current_table.dump();
        }
        ;

const_variable_declaration
        : ASSIGN const_expr {
                Trace("const_variable_declaration -> ASSIGN const_expr");
                Data return_data;
                return_data.type = $2.type;
                return_data.kind = Kind::const_kind;
                $$ = return_data;
        }
        | COLON datatype ASSIGN const_expr {
                Trace("cosnt_variable_declaration -> COLON datatype ASSIGN const_expr");
                Data return_data;
                return_data.type = $2;
                return_data.kind = Kind::const_kind;
                if($2 != $4.type) {
                        warning("Constant declaration datatype mismatch");
                }
                $$ = return_data;
        }
        ;

var_variable_declaration
        : ASSIGN const_expr {
                Trace("var_variable_declaration -> ASSIGN const_expr");
                Data return_data;
                return_data.type = $2.type;
                return_data.kind = Kind::var_kind;
                $$ = return_data;
        }
        | COLON datatype {
                Trace("var_variable_declaration -> COLON datatype");
                Data return_data;
                return_data.type = $2;
                return_data.kind = Kind::var_kind;
                $$ = return_data;
        }
        | COLON datatype ASSIGN const_expr {
                Trace("var_variable_declaration -> COLON datatype ASSIGN const_expr");
                Data return_data;
                return_data.type = $2;
                return_data.kind = Kind::var_kind;
                if($2 != $4.type) {
                        warning("Varaible declaration datatype mismatch");
                }
                $$ = return_data;
        }
        | COLON ARRAY I_CONST DOT DOT I_CONST OF datatype {
                Trace("var_variable_declaration -> COLON ARRAY I_CONST DOT DOT I_CONST OF datatype");
                Data return_data;
                return_data.type = $8;
                return_data.arr_start = $3.i_val;
                return_data.arr_end = $6.i_val;
                return_data.kind = Kind::var_kind;
                
                if(return_data.arr_start > return_data.arr_end) {
                        warning("Array startFound index is larger than end index");
                }
                else {
                        Value new_value;
                        for(int i = 0; i <= $6.i_val - $3.i_val; i++) {
                                return_data.array.push_back(new_value);
                        }
                }
                $$ = return_data;
        }
        ;

const_expr
        : const_val {
                Trace("const_expr -> const_val");
                $$ = $1;
        }
        | const_expr MOD const_expr {
                Trace("const_expr -> const_expr MOD const_expr");
                if($1.type == Type::void_type || $3.type == Type::void_type) {
                        warning("MOD operation on void");
                        $$.type = Type::void_type;
                }
                else if($1.type == Type::i_type && $3.type == Type::i_type) {
                        $$.type = Type::i_type;
                }
                else if(($1.type == Type::i_type || $1.type == Type::b_type) 
                        && ($3.type == Type::i_type || $3.type == Type::b_type)) {
                        warning("Type conversion from boolean to int");
                        $$.type = Type::i_type;
                }
                else {
                        warning("MOD operation on non-integer");
                        $$.type = Type::void_type;
                }
                $$.kind = Kind::const_kind;
        }
        | const_expr MUL const_expr {
                Trace("const_expr -> const_expr MUL const_expr");
                if($1.type == Type::void_type || $3.type == Type::void_type) {
                        warning("MUL operation on void");
                        $$.type = Type::void_type;
                }
                else if($1.type == Type::s_type || $3.type == Type::s_type) {
                        warning("MUL operation on string");
                        $$.type = Type::void_type;
                }
                else {
                        if($1.type == Type::i_type && $3.type == Type::i_type) {
                                $$.type = Type::i_type;
                        }
                        else if($1.type == Type::f_type && $3.type == Type::f_type) {
                                $$.type = Type::f_type;
                        }
                        else if(($1.type == Type::i_type && $3.type == Type::f_type)
                                || ($1.type == Type::f_type && $3.type == Type::i_type)) {
                                warning("Type conversion from int to real");
                                $$.type = Type::f_type;
                        }
                        else if($1.type == Type::b_type && $3.type != Type::b_type) {
                                warning("Type conversion from boolean to $3's type");
                                $$.type = $3.type;
                        }
                        else if($1.type != Type::b_type && $3.type == Type::b_type) {
                                warning("Type conversion from boolean to $1's type");
                                $$.type = $1.type;
                        }
                        else {
                                warning("Type conversion from boolean to integer");
                                $$.type = Type::i_type;
                        }
                }
                $$.kind = Kind::const_kind;
        }
        | const_expr DIV const_expr {
                Trace("const_expr -> const_expr DIV const_expr");
                if($1.type == Type::void_type || $3.type == Type::void_type) {
                        warning("DIV operation on void");
                        $$.type = Type::void_type;
                }
                else if($1.type == Type::s_type || $3.type == Type::s_type) {
                        warning("DIV operation on string");
                        $$.type = Type::void_type;
                }
                else {
                        if($1.type == Type::i_type && $3.type == Type::i_type) {
                                $$.type = Type::i_type;
                        }
                        else if($1.type == Type::f_type && $3.type == Type::f_type) {
                                $$.type = Type::f_type;
                        }
                        else if(($1.type == Type::i_type && $3.type == Type::f_type)
                                || ($1.type == Type::f_type && $3.type == Type::i_type)) {
                                warning("Type conversion from int to real");
                                $$.type = Type::f_type;
                        }
                        else if($1.type == Type::b_type && $3.type != Type::b_type) {
                                warning("Type conversion from boolean to $3's type");
                                $$.type = $3.type;
                        }
                        else if($1.type != Type::b_type && $3.type == Type::b_type) {
                                warning("Type conversion from boolean to $1's type");
                                $$.type = $1.type;
                        }
                        else {
                                warning("Type conversion from boolean to integer");
                                $$.type = Type::i_type;
                        }
                }
                $$.kind = Kind::const_kind;
        }
        | const_expr ADD const_expr {
                Trace("const_expr -> const_expr ADD const_expr");
                if($1.type == Type::void_type || $3.type == Type::void_type) {
                        warning("ADD operation on void");
                        $$.type = Type::void_type;
                }
                else if($1.type == Type::s_type || $3.type == Type::s_type) {
                        warning("ADD operation on string");
                        $$.type = Type::void_type;
                }
                else {
                        if($1.type == Type::i_type && $3.type == Type::i_type) {
                                $$.type = Type::i_type;
                        }
                        else if($1.type == Type::f_type && $3.type == Type::f_type) {
                                $$.type = Type::f_type;
                        }
                        else if(($1.type == Type::i_type && $3.type == Type::f_type)
                                || ($1.type == Type::f_type && $3.type == Type::i_type)) {
                                warning("Type conversion from int to real");
                                $$.type = Type::f_type;
                        }
                        else if($1.type == Type::b_type && $3.type != Type::b_type) {
                                warning("Type conversion from boolean to $3's type");
                                $$.type = $3.type;
                        }
                        else if($1.type != Type::b_type && $3.type == Type::b_type) {
                                warning("Type conversion from boolean to $1's type");
                                $$.type = $1.type;
                        }
                        else {
                                warning("Type conversion from boolean to integer");
                                $$.type = Type::i_type;
                        }
                }
                $$.kind = Kind::const_kind;
        }
        | const_expr SUB const_expr {
                Trace("const_expr -> const_expr SUB const_expr");
                if($1.type == Type::void_type || $3.type == Type::void_type) {
                        warning("SUB operation on void");
                        $$.type = Type::void_type;
                }
                else if($1.type == Type::s_type || $3.type == Type::s_type) {
                        warning("SUB operation on string");
                        $$.type = Type::void_type;
                }
                else {
                        if($1.type == Type::i_type && $3.type == Type::i_type) {
                                $$.type = Type::i_type;
                        }
                        else if($1.type == Type::f_type && $3.type == Type::f_type) {
                                $$.type = Type::f_type;
                        }
                        else if(($1.type == Type::i_type && $3.type == Type::f_type)
                                || ($1.type == Type::f_type && $3.type == Type::i_type)) {
                                warning("Type conversion from int to real");
                                $$.type = Type::f_type;
                        }
                        else if($1.type == Type::b_type && $3.type != Type::b_type) {
                                warning("Type conversion from boolean to $3's type");
                                $$.type = $3.type;
                        }
                        else if($1.type != Type::b_type && $3.type == Type::b_type) {
                                warning("Type conversion from boolean to $1's type");
                                $$.type = $1.type;
                        }
                        else {
                                warning("Type conversion from boolean to integer");
                                $$.type = Type::i_type;
                        }
                }
                $$.kind = Kind::const_kind;
        }
        | const_expr AND const_expr {
                Trace("const_expr -> const_expr AND const_expr");
                if($1.type == Type::void_type || $3.type == Type::void_type) {
                        warning("AND operation on void");
                        $$.type = Type::void_type;
                }
                else if($1.type == Type::b_type && $3.type == Type::b_type) {
                        $$.type = Type::b_type;
                }
                else {
                        warning("AND operation on non-boolean");
                        $$.type = Type::void_type;
                }
                $$.kind = Kind::const_kind;
        }
        | const_expr OR const_expr {
                Trace("const_expr -> const_expr OR const_expr");
                if($1.type == Type::void_type || $3.type == Type::void_type) {
                        warning("OR operation on void");
                        $$.type = Type::void_type;
                }
                else if($1.type == Type::b_type && $3.type == Type::b_type) {
                        $$.type = Type::b_type;
                }
                else {
                        warning("OR operation on non-boolean");
                        $$.type = Type::void_type;
                }
                $$.kind = Kind::const_kind;
        }
        | const_expr LT const_expr { // Less Than
                Trace("const_expr -> const_expr LT const_expr");
                if($1.type == Type::void_type || $3.type == Type::void_type) {
                        warning("LT operation on void");
                        $$.type = Type::void_type;
                }
                else if($1.type == Type::s_type || $3.type == Type::s_type) {
                        warning("LT operation on string");
                        $$.type = Type::void_type;
                }
                else {
                        // only int, real, bool
                        if($1.type != $3.type) {
                                warning("Auto type conversion");
                        }
                        $$.type = Type::b_type;
                }
                $$.kind = Kind::const_kind;
        }
        | const_expr LE const_expr { // Less Equal
                Trace("const_expr -> const_expr LE const_expr");
                if($1.type == Type::void_type || $3.type == Type::void_type) {
                        warning("LE operation on void");
                        $$.type = Type::void_type;
                }
                else if($1.type == Type::s_type || $3.type == Type::s_type) {
                        warning("LE operation on string");
                        $$.type = Type::void_type;
                }
                else {
                        if($1.type != $3.type) {
                                warning("Auto type conversion");
                        }
                        $$.type = Type::b_type;
                }
                $$.kind = Kind::const_kind;
        }
        | const_expr EQ const_expr { // Equal
                Trace("const_expr -> const_expr EQ const_expr");
                if($1.type == Type::void_type || $3.type == Type::void_type) {
                        warning("EQ operation on void");
                        $$.type = Type::void_type;
                }
                else {
                        if($1.type != $3.type) {
                                warning("Auto type conversion");
                        }
                        $$.type = Type::b_type;
                }
                $$.kind = Kind::const_kind;
        }
        | const_expr GE const_expr { // Greater Equal
                Trace("const_expr -> const_expr GE const_expr");
                if($1.type == Type::void_type || $3.type == Type::void_type) {
                        warning("GE operation on void");
                        $$.type = Type::void_type;
                }
                else if($1.type == Type::s_type || $3.type == Type::s_type) {
                        warning("GE operation on string");
                        $$.type = Type::void_type;
                }
                else {
                        if($1.type != $3.type) {
                                warning("Auto type conversion");
                        }
                        $$.type = Type::b_type;
                }
                $$.kind = Kind::const_kind;
        }
        | const_expr GT const_expr { // Greater Than
                Trace("const_expr -> const_expr GE const_expr");
                if($1.type == Type::void_type || $3.type == Type::void_type) {
                        warning("GT operation on void");
                        $$.type = Type::void_type;
                }
                else if($1.type == Type::s_type || $3.type == Type::s_type) {
                        warning("GT operation on string");
                        $$.type= Type::void_type;
                }
                else {
                        if($1.type != $3.type) {
                                warning("Auto type conversion");
                        }
                        $$.type = Type::b_type;
                }
                $$.kind = Kind::const_kind;
        }
        | const_expr NE const_expr { // Not Equal
                Trace("const_expr -> const_expr NE const_expr");
                if($1.type == Type::void_type || $3.type == Type::void_type) {
                        warning("NE operation on void");
                        $$.type = Type::void_type;
                }
                else {
                        if($1.type != $3.type) {
                                warning("Auto type conversion");
                        }
                        $$.type = Type::b_type;
                }
                $$.kind = Kind::const_kind;
        }
        | NOT const_expr {
                Trace("const_expr -> NOT const_expr");
                if($2.type == Type::void_type) {
                        warning("NOT operation on void");
                        $$.type = Type::void_type;
                }
                else if($2.type == Type::b_type) {
                        $$.type = Type::b_type;
                }
                else {
                        warning("NOT operation on non-boolean");
                        $$.type = Type::void_type;
                }
                $$.kind = Kind::const_kind;
        }
        | SUB const_expr %prec UMINUS {
                Trace("const_expr -> SUB const_expr");
                if($2.type == Type::void_type) {
                        warning("UMINUS operation on void");
                        $$.type = Type::void_type;
                }
                else if($2.type == Type::s_type) {
                        warning("UMINUS operation on string");
                        $$.type = Type::void_type;
                }
                else {
                        $$.type = $2.type;
                }
                $$.kind = Kind::const_kind;
        }
        | LPAREN const_expr RPAREN {
                Trace("const_expr -> LPAREN const_expr RPAREN");
                $$.type = $2.type;
                $$.kind = $2.kind;
        }
        ;

const_val
        : I_CONST {
                Trace("const_val -> I_CONST");
                $$.type = Type::i_type;
                $$.kind = Kind::const_kind;
        }
        | F_CONST {
                Trace("const_val -> F_CONST");
                $$.type = Type::f_type;
                $$.kind = Kind::const_kind;
        }
        | STR_CONST {
                Trace("const_val -> STR_CONST");
                $$.type = Type::s_type;
                $$.kind = Kind::const_kind;
        }
        | ID {
                Trace("const_val -> ID");
                auto iter = current_table.table.find($1.s_val);
                if(iter != current_table.table.end()) {
                        if(iter->second.kind == Kind::func_kind || iter->second.kind == Kind::proc_kind) {
                                        warning("Function or procedure cannot be called without parenthesis");
                                }
                        $$ = iter->second;
                }
                else {
                        int table_index = table_stack.lookup($1.s_val);
                        if(table_index != -1) {
                                Value new_value;
                                iter = table_stack.list[table_index].table.find($1.s_val);
                                if(iter->second.kind == Kind::func_kind || iter->second.kind == Kind::proc_kind) {
                                        warning("Function or procedure cannot be called without parenthesis");
                                }
                                $$ = iter->second;
                        }
                        else {
                                warning("Undeclared variable");
                                $$.type = Type::void_type;
                                $$.kind = Kind::const_kind;
                        }
                }
        }
        | ID LBRACKET const_expr RBRACKET { // array
                Trace("const_val -> ID LBRACKET const_expr RBRACKET");
                auto iter = current_table.table.find($1.s_val);
                if(iter != current_table.table.end()) {
                        $$.type = iter->second.type;
                        $$.kind = Kind::var_kind;
                }
                else {
                        int table_index = table_stack.lookup($1.s_val);
                        if(table_index != -1) {
                                Value new_value;
                                iter = table_stack.list[table_index].table.find($1.s_val);
                                $$.type = iter->second.type;
                                $$.kind = Kind::var_kind;
                        }
                        else {
                                warning("Undeclared variable");
                                $$.type = Type::void_type;
                                $$.kind = Kind::var_kind;
                        }
                }
        }
        | TRUE {
                Trace("const_val -> TRUE");
                $$.type = Type::b_type;
                $$.kind = Kind::const_kind;
        }
        | FALSE {
                Trace("const_val -> FALSE");
                $$.type = Type::b_type;
                $$.kind = Kind::const_kind;
        }
        | function_call_stmt {
                Trace("const_val -> function_call_stmt");
                $$.type = $1.type;
                $$.kind = Kind::const_kind;
        }
        ;
        
datatype
        : INT {
                Trace("datatype -> INT");
                $$ = Type::i_type;
        }
        | REAL {
                Trace("datatype -> REAL");
                $$ = Type::f_type;
        }
        | STRING {
                Trace("datatype -> STRING");
                $$ = Type::s_type;
        }
        | BOOL {
                Trace("datatype -> BOOL");
                $$ = Type::b_type;
        }
        ;

function_declaration
        : FUNCTION ID LPAREN RPAREN COLON datatype {
                Trace("function_declaration -> FUNCTION ID LPAREN RPAREN COLON datatype");
                Func_return new_func_return;
                func_return = new_func_return;
                func_return.return_type = Return_type::null;

                Data func_data;
                func_data.id = $2.s_val;
                func_data.kind = Kind::func_kind;
                func_data.type = $6;
                
                if(!current_table.insert(func_data)) {
                        warning("Redeclaration of function in current scope");
                }
                
                // Trace("Function Level Table:")
                // current_table.dump();
                table_stack.insert(current_table);

                SymbolTable body_table;
                current_table = body_table;
        }
        block_program END ID {
                Trace("function_body -> block_program END ID");
                if($2.s_val != $10.s_val) {
                        warning("Function name mismatch");
                }

                if(func_return.return_type != Return_type::result_type) {
                        warning("Function has no result statement");
                }
                else {
                        if(func_return.type != $6) {
                                warning("Function return type mismatch");
                        }
                }

                table_msg("function Table");
                current_table.dump();
                current_table = table_stack.get_top(); // switch back to function level table
                table_stack.pop();
        }
        | FUNCTION ID LPAREN para_declaration RPAREN COLON datatype {
                Trace("function_declaration -> FUNCTION ID LPAREN para_declaration RPAREN COLON datatype");
                Func_return new_func_return;
                func_return = new_func_return;
                func_return.return_type = Return_type::null;

                SymbolTable body_table;
                body_table = current_table;
                current_table = table_stack.get_top();
                table_stack.pop();

                Data func_data;
                func_data.id = $2.s_val;
                func_data.kind = Kind::func_kind;
                func_data.type = $7;
                func_data.para_list = para_list;

                reverse(func_data.para_list.begin(), func_data.para_list.end());

                if(!current_table.insert(func_data)) {
                        warning("Redeclaration of function in current scope");
                }
                table_stack.insert(current_table);
                current_table = body_table;
        } 
        block_program END ID {
                Trace("function_body -> block_program END ID");
                if($2.s_val != $11.s_val) {
                        warning("Function name mismatch");
                }

                if(func_return.return_type != Return_type::result_type) {
                        warning("Function has no result statement");
                }
                else {
                        if(func_return.type != $7) {
                                warning("Function return type mismatch");
                        }
                }

                table_msg("function Table");
                current_table.dump();
                current_table = table_stack.get_top(); // switch back to function level table
                table_stack.pop();
        }
        ;

procedure_declaration
        : PROCEDURE ID LPAREN RPAREN {
                Trace("procedure_declaration -> PROCEDURE ID LPAREN RPAREN COLON datatype procedure_body");
                Func_return new_func_return;
                func_return = new_func_return;
                func_return.return_type = Return_type::null;

                Data proc_data;
                proc_data.id = $2.s_val;
                proc_data.kind = Kind::proc_kind;
                proc_data.type = Type::void_type;

                if(!current_table.insert(proc_data)) {
                        warning("Redeclaration of function in current scope");
                }
                
                table_stack.insert(current_table);

                SymbolTable body_table;
                current_table = body_table;
        }
        block_program END ID {
                Trace("procedure_body -> block_program END ID");
                if($2.s_val != $8.s_val) {
                        warning("Function name mismatch");
                }

                if(func_return.return_type == Return_type::result_type) {
                        warning("Procedure cannot return a value");
                }
                else if(func_return.return_type == Return_type::null) {
                        warning("Procedure has no return statement");
                }

                table_msg("procedure Table");
                current_table.dump();
                current_table = table_stack.get_top(); // switch back to function level table
                table_stack.pop();
        }
        | PROCEDURE ID LPAREN para_declaration RPAREN {
                Trace("procedure_declaration -> PROCEDURE ID LPAREN para_declaration RPAREN COLON datatype procedure_body");
                Func_return new_func_return;
                func_return = new_func_return;
                func_return.return_type = Return_type::null;

                SymbolTable body_table;
                body_table = current_table;
                current_table = table_stack.get_top();
                table_stack.pop();

                Data proc_data;
                proc_data.id = $2.s_val;
                proc_data.kind = Kind::proc_kind;
                proc_data.type = Type::void_type;
                proc_data.para_list = para_list;
                reverse(proc_data.para_list.begin(), proc_data.para_list.end());
                // reverse the order of para_list

                if(table_stack.lookup(proc_data.id) == -1) {
                        if(!current_table.insert(proc_data)) {
                                warning("Redeclaration of function in current scope");
                        }
                }
                else {
                        warning("Reclaration of function in upper table");
                }

                table_stack.insert(current_table);
                current_table = body_table;
        }
        block_program END ID {
                Trace("procedure_body -> block_program END ID");
                if($2.s_val != $9.s_val) {
                        warning("Function name mismatch");
                }

                if(func_return.return_type == Return_type::result_type) {
                        warning("Procedure cannot have result statement");
                }
                else if(func_return.return_type == Return_type::null) {
                        warning("Procedure has no return statement");
                }

                table_msg("procedure Table");
                current_table.dump();
                current_table = table_stack.get_top(); // switch back to function level table
                table_stack.pop();
        }
        ;


para_declaration
        : ID COLON datatype {
                Trace("para_declaration -> ID COLON datatype");
                SymbolTable new_table;
                table_stack.insert(current_table);
                current_table = new_table;
                Data new_data;
                new_data.id = $1.s_val;
                new_data.kind = Kind::para_kind;
                new_data.type = $3;
                if(!current_table.insert(new_data)) {
                        warning("Redeclaration of parameter in current scope");
                }
                para_list.clear();
                para_list.push_back(new_data);
        }
        | ID COLON datatype COMMA para_declaration {
                Trace("para_declaration -> ID COLON datatype COMMA para_declaration");
                Data new_data;
                new_data.id = $1.s_val;
                new_data.kind = Kind::para_kind;
                new_data.type = $3;
                if(!current_table.insert(new_data)) {
                        warning("Redeclaration of parameter in current scope");
                }
                para_list.push_back(new_data);
        }      
        | ID COLON ARRAY I_CONST DOT DOT I_CONST OF datatype { 
                Trace("para_declaration -> ID COLON ARRAY I_CONST DOT DOT I_CONST OF datatype");
                SymbolTable new_table;
                table_stack.insert(current_table);
                current_table = new_table;
                Data new_data;
                new_data.id = $1.s_val;
                new_data.kind = Kind::para_kind;
                new_data.type = $9;
                new_data.arr_start = $4.i_val;
                new_data.arr_end = $7.i_val;
                if(new_data.arr_start > new_data.arr_end) {
                        warning("Array start index is larger than end index");
                }
                Value new_value;
                for(int i = 0; i <= $7.i_val - $4.i_val; i++) {
                        new_data.array.push_back(new_value);
                }
                if(!current_table.insert(new_data)) {
                        warning("Redeclaration of parameter in current scope");
                }
                para_list.clear();
                para_list.push_back(new_data);
        }
        | ID COLON ARRAY I_CONST DOT DOT I_CONST OF datatype COMMA para_declaration {     
                Data new_data;
                new_data.id = $1.s_val;
                new_data.kind = Kind::para_kind;
                new_data.type = $9;
                new_data.arr_start = $4.i_val;
                new_data.arr_end = $7.i_val;
                if(new_data.arr_start > new_data.arr_end) {
                        warning("Array start index is larger than end index");
                }
                Value new_value;
                for(int i = 0; i <= $7.i_val - $4.i_val; i++) {
                        new_data.array.push_back(new_value);
                }
                if(!current_table.insert(new_data)) {
                        warning("Redeclaration of parameter in current cscope");
                }
                para_list.push_back(new_data);
        }
        ;


block_program
        : variable_declaration block_program {
                Trace("block_program -> variable_declaration block_program");
        }
        | stmt block_program {
                Trace("block_program -> stmt block_program");
        }
        |
        ;

stmt
        : block_stmt {
                Trace("stmt -> block_stmt");
        }
        | assign_stmt {
                Trace("stmt -> assign_stmt");
        }
        | put_stmt {
                Trace("stmt -> put_stmt");
        }
        | get_stmt {
                Trace("stmt -> get_stmt");
        }
        | result_stmt {
                Trace("stmt -> result_stmt");
        }
        | exit_stmt {
                Trace("stmt -> exit_stmt");
        }
        | skip_stmt {
                Trace("stmt -> skip_stmt");
        }
        | if_stmt {
                Trace("stmt -> if_stmt");
        }
        | loop_stmt {
                Trace("stmt -> loop_stmt");
        }
        | for_stmt {
                Trace("stmt -> for_stmt");
        }
        ;

block_stmt
        : _BEGIN {
                SymbolTable body_table;
                table_stack.insert(current_table);
                current_table = body_table;
        }
        block_program END {
                Trace("block_stmt -> BEGIN block_stmt_body");
                table_msg("block Table");
                current_table.dump();
                current_table = table_stack.get_top(); 
                table_stack.pop();
        }
        ;

assign_stmt
        : ID ASSIGN const_expr {
                Trace("assign_stmt -> ID ASSIGN const_expr");
                auto iter = current_table.table.find($1.s_val);
                if(iter == current_table.table.end()) {
                        int table_index = table_stack.lookup($1.s_val);
                        if(table_index == -1) {
                                warning("Undeclared variable");
                        }
                        else {
                                iter = table_stack.list[table_index].table.find($1.s_val);
                                switch(iter->second.kind) {
                                        case Kind::func_kind:
                                                warning("Assign value to function");
                                                break;
                                        case Kind::proc_kind:
                                                warning("Assign value to procedure");
                                                break;
                                        case Kind::const_kind:
                                                warning("Assign value to constant");
                                                break;
                                        case Kind::para_kind:
                                        case Kind::var_kind:
                                                if(iter->second.type == Type::void_type) {
                                                        warning("Assign value to void type");
                                                }
                                                else if((iter->second.array.size() != 0 && $3.array.size() == 0)
                                                        || (iter->second.array.size() == 0 && $3.array.size() != 0)) {
                                                        warning("One is array, the other is not");
                                                }
                                                else if($3.kind == Kind::func_kind) {
                                                        if($3.type == Type::void_type) {
                                                                warning("Assign varaible to a function with no return value");
                                                        }
                                                }
                                                else if($3.kind == Kind::proc_kind) {
                                                        warning("Assgin varaible to a procedure");
                                                }
                                                else if(iter->second.type != $3.type) {
                                                        warning("Auto type conversion");
                                                }
                                                break;
                                }
                        }
                }
                else {
                        switch(iter->second.kind) {
                                case Kind::func_kind:
                                        warning("Assign value to function");
                                        break;
                                case Kind::proc_kind:
                                        warning("Assign value to function");
                                        break;
                                case Kind::const_kind:
                                        warning("Assign value to constant");
                                        break;
                                case Kind::para_kind:
                                case Kind::var_kind:
                                        if(iter->second.type == Type::void_type) {
                                                warning("Assign value to void type");
                                        }
                                        else if((iter->second.array.size() != 0 && $3.array.size() == 0)
                                        || (iter->second.array.size() == 0 && $3.array.size() != 0)) {
                                                warning("One is array, the other is not");
                                        }
                                        else if($3.kind == Kind::func_kind) {
                                                if($3.type == Type::void_type) {
                                                        warning("Assign varaible to a function with no return value");
                                                }
                                        }
                                        else if($3.kind == Kind::proc_kind) {
                                                warning("Assgin varaible to a procedure");
                                        }
                                        else if(iter->second.type != $3.type) {
                                                warning("Auto type conversion");
                                        }
                                        break;
                        }
                }
        }
        | ID LBRACKET const_expr RBRACKET ASSIGN const_expr { // arary assignment
                Trace("assign_stmt -> ID LBRACKET const_expr RBRACKET ASSIGN const_expr");
                if($3.type != Type::i_type) {
                        warning("Array index is not integer");
                }
                else {
                        auto iter = current_table.table.find($1.s_val);
                        if(iter == current_table.table.end()) {
                                int table_index = table_stack.lookup($1.s_val);
                                if(table_index == -1) {
                                        warning("Undeclared variable");
                                }
                                else {
                                        iter = table_stack.list[table_index].table.find($1.s_val);
                                        switch(iter->second.kind) {
                                                case Kind::func_kind:
                                                        warning("Assign value to function");
                                                        break;
                                                case Kind::proc_kind:
                                                        warning("Assign value to procedure");
                                                        break;
                                                case Kind::const_kind:
                                                        warning("Assign value to constant");
                                                        break;
                                                case Kind::para_kind:
                                                case Kind::var_kind:
                                                        if(iter->second.type == Type::void_type) {
                                                                warning("Assign value to void type");
                                                        }
                                                        else if(iter->second.array.size() == 0) {
                                                                warning("It is not array");
                                                        }
                                                        else if(iter->second.type != $6.type) {
                                                                warning("Auto type conversion");
                                                        }
                                                        break;
                                        }
                                }
                        }
                        else {
                                switch(iter->second.kind) {
                                        case Kind::func_kind:
                                                warning("Assign value to function");
                                                break;
                                        case Kind::proc_kind:
                                                warning("Assign value to procedure");
                                                break;
                                        case Kind::const_kind:
                                                warning("Assign value to constant");
                                                break;
                                        case Kind::para_kind:
                                        case Kind::var_kind:
                                                if(iter->second.type == Type::void_type) {
                                                        warning("Assign value to void type");
                                                }
                                                else if(iter->second.array.size() == 0) {
                                                        warning("It is not array");
                                                }
                                                else if(iter->second.type != $6.type) {
                                                        warning("Auto type conversion");
                                                }
                                                break;
                                }
                        }
                }
        }

        ;

put_stmt
        : PUT const_expr {
                Trace("put_stmt -> PUT const_expr");
                if($2.array.size() != 0) {
                        warning("PUT operation on array");
                }
                else if($2.kind == Kind::proc_kind) {
                        warning("PUT operation on procedure");
                }
                else if($2.kind == Kind::func_kind) {
                        if($2.type == Type::void_type) {
                                warning("PUT operation on function with no return value");
                        }
                }
        }
        ;

get_stmt
        : GET ID {
                Trace("get_stmt -> GET ID");
                auto iter = current_table.table.find($2.s_val);
                if(iter == current_table.table.end()) {
                        int table_index = table_stack.lookup($2.s_val);
                        if(table_index == -1) {
                                warning("Undeclared variable");
                        }
                        else {
                                iter = table_stack.list[table_index].table.find($2.s_val);
                                if((iter->second.kind == Kind::func_kind) 
                                || (iter->second.kind == Kind::proc_kind)) {
                                        warning("GET operation on function or procedure");
                                }
                                else {
                                        if(iter->second.type == Type::void_type) {
                                                warning("GET operation on void");
                                        }
                                }
                        }
                }
                else {
                        if((iter->second.kind == Kind::func_kind) 
                        || (iter->second.kind == Kind::proc_kind)) {
                                warning("GET operation on function or procedure");
                        }
                        else {
                                if(iter->second.type == Type::void_type) {
                                        warning("GET operation on void");
                                }
                        }
                }
        } 
        | GET ID LBRACKET const_expr RBRACKET {
                if ($4.type != Type::i_type) {
                        warning("Array index is not integer");
                }
                else {
                        auto iter = current_table.table.find($2.s_val);
                        if(iter == current_table.table.end()) {
                                int table_index = table_stack.lookup($2.s_val);
                                if(table_index == -1) {
                                        warning("Undeclared variable");
                                }
                                else {
                                        iter = table_stack.list[table_index].table.find($2.s_val);
                                        if(iter->second.array.empty()) {
                                                warning("GET operation on non-array");
                                        }
                                }
                        }
                        else {
                                if(iter->second.array.empty()) {
                                        warning("GET operation on non-array");
                                }
                        } 
                }
        }
        ;

result_stmt
        : RESULT const_expr {
                Trace("result_stmt -> RESULT const_expr");

                func_return.return_type = Return_type::result_type;
                func_return.type = $2.type;
        }
        | RETURN {
                Trace("result_stmt -> RETURN");
                func_return.return_type = Return_type::return_type;
                func_return.type = Type::void_type;
        }
        ;

exit_stmt
        : EXIT {
                Trace("exit_stmt -> EXIT");
        }
        | EXIT WHEN const_expr { // bool_expr
                Trace("exit_stmt -> EXIT WHEN bool_expr");
                if($3.type == Type::void_type) {
                        warning("EXIT operation on void");
                }
                else if($3.type != Type::b_type) {
                        warning("EXIT operation on non-boolean");
                }
        }
        ;

skip_stmt
        : SKIP {
                Trace("skip_stmt -> SKIP");
        }
        ;

if_stmt
        : IF const_expr THEN { //bool_expr
                Trace("if_stmt -> IF bool_expr THEN")
                if($2.type != Type::b_type) {
                        warning("IF condition is not bool");
                }
                table_stack.insert(current_table);
                SymbolTable body_table;
                current_table = body_table;
        }
        block_program { 
                Trace("if_stmt -> IF bool_expr THEN block_program");
        }
        end_if_stmt {
                Trace("if_stmt -> IF bool_expr THEN block_program end_if_stmt");
        }
        ;

end_if_stmt
        : END IF {
                Trace("end_if_stmt -> END IF");
                table_msg("if Table");
                current_table.dump();
                current_table = table_stack.get_top();
                table_stack.pop();
        }
        | ELSE {
                table_msg("if Table");
                current_table.dump();
                SymbolTable body_table;
                current_table = body_table;
        }
        block_program END IF {
                Trace("end_if_stmt -> ELSE block_program END IF");
                table_msg("else Table");
                current_table.dump();
                current_table = table_stack.get_top();
                table_stack.pop();
        }
        ;

loop_stmt
        : LOOP {
                SymbolTable body_table;
                table_stack.insert(current_table);
                current_table = body_table;
        }
        block_program END LOOP {
                table_msg("loop Table");
                current_table.dump();
                current_table = table_stack.get_top();
                table_stack.pop();
        }
        ;

for_stmt
        : FOR ID {
                auto iter = current_table.table.find($2.s_val);
                if(iter == current_table.table.end()) {
                        int table_index = table_stack.lookup($2.s_val);
                        if(table_index == -1) {
                                warning("Undeclared variable");
                        }
                        else {
                                iter = table_stack.list[table_index].table.find($2.s_val);
                                if(iter->second.kind != Kind::var_kind) {
                                        warning("FOR operation on non-variable");
                                }
                                else if(iter->second.array.size() != 0) {
                                        warning("FOR operation on array");
                                }
                                else {
                                        if(iter->second.type != Type::i_type) {
                                                warning("FOR operation on non-integer");
                                        }
                                }
                        }
                }
                else {
                        if((iter->second.kind != Kind::var_kind) && (iter->second.kind != Kind::para_kind) ) {
                                warning("FOR operation on non-variable");
                        }
                        else if(iter->second.array.size() != 0) {
                                        warning("FOR operation on array");
                        }
                        else {
                                if(iter->second.type != Type::i_type) {
                                        warning("FOR operation on non-integer");
                                }
                        }
                }

                SymbolTable body_table;
                table_stack.insert(current_table);
                current_table = body_table;

                Data for_data;
                for_data.id = $2.s_val;
                for_data.kind = Kind::para_kind;
                for_data.type = Type::i_type;
                current_table.insert(for_data);
        }
        COLON const_expr DOT DOT const_expr block_program END FOR {
                Trace("for_stmt -> FOR ID COLON const_expr DOT DOT const_expr for_stmt_body END FOR");
                if($5.kind != Kind::const_kind || $8.kind != Kind::const_kind) {
                        warning("FOR operation on non-constant");
                }
                if($5.type != Type::i_type || $8.type != Type::i_type) {
                        warning("FOR operation on non-integer");
                }
                table_msg("for Table");
                current_table.dump();
                current_table = table_stack.get_top();
                table_stack.pop();
        }
        | FOR DECREASING ID { 
                auto iter = current_table.table.find($3.s_val);
                if(iter == current_table.table.end()) {
                        int table_index = table_stack.lookup($3.s_val);
                        if(table_index == -1) {
                                warning("Undeclared variable");
                        }
                        else {
                                iter = table_stack.list[table_index].table.find($3.s_val);
                                if(iter->second.kind != Kind::var_kind) {
                                        warning("FOR operation on non-variable");
                                }
                                else if(iter->second.array.size() != 0) {
                                        warning("FOR operation on array");
                                }
                                else {
                                        if(iter->second.type != Type::i_type) {
                                                warning("FOR operation on non-integer");
                                        }
                                }
                        }
                }
                else {
                        if((iter->second.kind != Kind::var_kind) && (iter->second.kind != Kind::para_kind) ) {
                                warning("FOR operation on non-variable");
                        }
                        else if(iter->second.array.size() != 0) {
                                warning("FOR operation on array");
                        }
                        else {
                                if(iter->second.type != Type::i_type) {
                                        warning("FOR operation on non-integer");
                                }
                        }
                }

                SymbolTable body_table;
                table_stack.insert(current_table);
                current_table = body_table;

                Data for_data;
                for_data.id = $3.s_val;
                for_data.kind = Kind::para_kind;
                for_data.type = Type::i_type;
                current_table.insert(for_data);
        }
        COLON const_expr DOT DOT const_expr block_program END FOR {
                Trace("for_stmt -> FOR DECREASING ID COLON const_expr DOT DOT const_expr for_stmt_body END FOR");
                if($6.type != Type::i_type || $9.type != Type::i_type) {
                        warning("FOR operation on non-integer");
                }
                else {
                        if($6.value.i_val < $9.value.i_val) {
                                warning("FOR operation with wrong direction");
                        }
                }
                if($6.kind != Kind::const_kind || $9.kind != Kind::const_kind) {
                        warning("FOR operation on non-constant");
                }
                
                table_msg("for Table");
                current_table.dump();
                current_table = table_stack.get_top();
                table_stack.pop();
        }
        ;

function_call_stmt
        : ID LPAREN RPAREN {
                Trace("function_call_stmt -> ID LPAREN RPAREN");
                auto iter = current_table.table.find($1.s_val);
                if(iter == current_table.table.end()) {
                        int table_index = table_stack.lookup($1.s_val);
                        if(table_index == -1) {
                                warning("Undeclared function");
                                $$.type = Type::void_type;
                        }
                        else {
                                iter = table_stack.list[table_index].table.find($1.s_val);
                                if((iter->second.kind != Kind::func_kind) && (iter->second.kind != Kind::proc_kind)) {
                                        warning("Call non-function");
                                        $$.type = Type::void_type;
                                }
                                else {
                                        if(iter->second.para_list.size() != 0) {
                                                warning("Call function with wrong number of parameters");
                                                $$.type = Type::void_type;
                                        }
                                        else if(iter->second.array.size() != 0) {
                                                warning("Call function with array");
                                                $$.type = Type::void_type;
                                        }
                                        else {
                                                $$.type = iter->second.type;
                                        }
                                }
                        }
                }
                else {
                        if((iter->second.kind != Kind::func_kind) && (iter->second.kind != Kind::proc_kind)) {
                                warning("Call non-function");
                                $$.type = Type::void_type;
                        }
                        else {
                                if(iter->second.para_list.size() != 0) {
                                        warning("Call function with wrong number of parameters");
                                        $$.type = Type::void_type;
                                }
                                else if(iter->second.array.size() != 0) {
                                        warning("Call function with array");
                                        $$.type = Type::void_type;
                                }
                                else {
                                        $$.type= iter->second.type;
                                }
                        }
                }

                if(iter->second.kind == Kind::proc_kind) {
                        $$.kind = Kind::proc_kind;
                }
                else {
                        $$.kind = Kind::const_kind;
                }
        }
        | ID LPAREN function_call_para RPAREN {
                Trace("function_call_stmt -> ID LPAREN function_call_para RPAREN");
                auto iter = current_table.table.find($1.s_val);
                if(iter == current_table.table.end()) {
                        int table_index = table_stack.lookup($1.s_val);
                        if(table_index == -1) {
                                warning("Undeclared function");
                                $$.type = Type::void_type;
                        }
                        else {
                                iter = table_stack.list[table_index].table.find($1.s_val);
                                if((iter->second.kind != Kind::func_kind) && (iter->second.kind != Kind::proc_kind)) {
                                        warning("Call non-function");
                                        $$.type = Type::void_type;
                                }
                                else {
                                        if(iter->second.para_list.size() != para_list.size()) {
                                                warning("Call function with wrong number of parameters");
                                                $$.type = Type::void_type;
                                        }
                                        else {
                                                reverse(para_list.begin(), para_list.end());
                                                int i;
                                                for(i = 0; i < para_list.size(); i++) {
                                                        if((para_list[i].array.size() != 0) && (iter->second.para_list[i].array.size() == 0)) {
                                                                warning("function call with an array parameter, but the function is not");
                                                                break;
                                                        }
                                                        else if ((para_list[i].array.size() == 0) && (iter->second.para_list[i].array.size() != 0)) {
                                                                warning("function call with a non-array parameter, but the function is");
                                                                break;
                                                        }
                                                        else if(para_list[i].type != iter->second.para_list[i].type) {
                                                                if((para_list[i].type == Type::s_type && iter->second.para_list[i].type != Type::s_type)
                                                                || (para_list[i].type != Type::s_type && iter->second.para_list[i].type == Type::s_type)
                                                                || (para_list[i].type == Type::void_type) 
                                                                || (iter->second.para_list[i].type == Type::void_type)) {
                                                                        warning("Call function with wrong type of parameters");
                                                                        $$.type = Type::void_type;
                                                                        break;
                                                                } 
                                                                else {
                                                                        warning("Auto type conversion");
                                                                }
                                                        }
                                                }
                                                if(i == para_list.size()) {
                                                        // all parameters are correct
                                                        $$.type = iter->second.type;
                                                }
                                        }
                                }
                        }
                }
                else {
                        if((iter->second.kind != Kind::func_kind) && (iter->second.kind != Kind::proc_kind)) {
                                warning("Call non-function");
                                $$.type = Type::void_type;
                        }
                        else {
                                if(iter->second.para_list.size() != para_list.size()) {
                                        warning("Call function with wrong number of parameters");
                                        $$.type = Type::void_type;
                                }
                                else {
                                        reverse(para_list.begin(), para_list.end());
                                        int i;
                                        for(i = 0; i < para_list.size(); i++) {
                                                if((para_list[i].array.size() != 0) && (iter->second.para_list[i].array.size() == 0)) {
                                                        warning("function call with an array parameter, but the function is not");
                                                        break;
                                                }
                                                else if ((para_list[i].array.size() == 0) && (iter->second.para_list[i].array.size() != 0)) {
                                                        warning("function call with a non-array parameter, but the function is");
                                                        break;
                                                }
                                                else if(para_list[i].type != iter->second.para_list[i].type) {
                                                        if((para_list[i].type == Type::s_type && iter->second.para_list[i].type != Type::s_type)
                                                        || (para_list[i].type != Type::s_type && iter->second.para_list[i].type == Type::s_type)
                                                        || (para_list[i].type == Type::void_type) 
                                                        || (iter->second.para_list[i].type == Type::void_type)) {
                                                                warning("Call function with wrong type of parameters");
                                                                $$.type = Type::void_type;
                                                                break;
                                                        } 
                                                        else {
                                                                warning("Auto type conversion");
                                                        }
                                                }
                                        }
                                        if(i == para_list.size()) {
                                                // all parameters are correct
                                                $$.type = iter->second.type;
                                        }

                                }
                        }
                }

                if(iter->second.kind == Kind::proc_kind) {
                        $$.kind = Kind::proc_kind;
                }
                else {
                        $$.kind = Kind::const_kind;
                }
        }
        ;

function_call_para
        : const_expr {
                Trace("function_call_para -> const_expr");
                para_list.clear();
                para_list.push_back($1);
        }
        | const_expr COMMA function_call_para {
                Trace("function_call_para -> const_expr COMMA function_call_para");
                para_list.push_back($1);
        }
        ;

%% 

#include "lex.yy.cpp"

void warning(char *msg) {
    fprintf(stderr, "\033[47m\033[31m\033[1mWANRING: %s\033[0m\n", msg);
}

void yyerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    table_msg("Current Table");
    current_table.dump();
    exit(1);
}

int main()
{
    printf("---------------------Parsing begin\n");
    
    /* perform parsing */
    yyparse();
    table_msg("\nMAIN Table");
    current_table.dump();
    
    printf("\n---------------------Parsing end\n");
    
    fclose(yyin);
}