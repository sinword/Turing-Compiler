%{
// #include "symboltable.hpp"
#include "javaclass.hpp"
#define YACC_DEBUG 0
#define Trace(t)  if (YACC_DEBUG)  { printf("Reducing %s\n", t);}
#define table_msg(msg)    { printf("\n\033[34m\033[47m%s\033[0m\n", msg); }
extern int yylex(void);
extern void warning(char *msg);
extern void yyerror(char *msg);

JavaClass java_class;
TableList table_stack;
SymbolTable current_table;
vector<Data> para_list;
Func_return func_return;
bool inMain = false;
%}

/* tokens */

%token DOT COMMA COLON LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE SEMICOLON

%token BOOL ASSIGN PUT _BEGIN DECREASING DEFAULT DO WHEN IF ELSE END EXIT FOR FUNCTION GET LOOP OF PROCEDURE REAL RESULT RETURN SKIP THEN 
%token VAR CONST INT STRING ARRAY

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
%type<data> const_variable_declaration local_var_variable_declaration 
%type<data> const_val const_expr function_call_stmt for_para

%start program_body
%%

program_body
    : global_variable_declaration program_body {
        Trace("program_body -> variable_declaration program_body");
    }
    | function_declaration program_body {
        Trace("program_body -> function_declaration program_body");
    }
    | procedure_declaration program_body {
        Trace("program_body -> procedure_declaration program_body");
    }
    | {
        Trace("program_body -> stmt_list");
        java_class.mainFunction(current_table.level);
        inMain = true;
    } 
    stmt_list {
        java_class.returnFunction(Type::void_type, current_table.level, inMain);
        java_class.closeFunction(current_table.level);
    } 
    ;

stmt_list
    : stmt_list stmt {
        Trace("stmt_list -> stmt_list stmt");
    }
    |
    ;
global_variable_declaration
    : CONST ID const_variable_declaration {
        Trace("global_variable_declaration -> CONST ID const_variable_declaration");
        Data new_data;
        new_data.id = $2.s_val;
        new_data.kind = Kind::const_kind;
        new_data.type = $3.type;
        new_data.value = $3.value;
        new_data.is_global = true;
        if(!current_table.insert(new_data)) {
            warning("Redeclaration of const in current scope");
        }
    }
    | VAR ID COLON datatype {
        Trace("global_variable_declaration -> VAR ID COLON");
        Data new_data;
        new_data.id = $2.s_val;
        new_data.kind = Kind::var_kind;
        new_data.type = $4;
        new_data.has_value = false;
        new_data.is_global = true;
        if(current_table.insert(new_data)) {
            java_class.globalVarDeclaration(new_data);
        }
        else {
            warning("Redeclaration of var in current scope");
        }
    }
    | VAR ID ASSIGN I_CONST { // only int type
        Trace("global_variable_declaration -> VAR ID ASSIGN I_CONST");
        Data new_data;
        new_data.id = $2.s_val;
        new_data.kind = Kind::var_kind;
        new_data.type = Type::i_type;
        new_data.value.i_val = $4.i_val;
        new_data.is_global = true;
        if(current_table.insert(new_data)) {
            java_class.globalVarDeclaration(new_data);
        }
        else {
            warning("Redeclaration of var in current scope");
        }
    }
    | VAR ID COLON INT ASSIGN I_CONST {
        Trace("global_variable_declaration -> VAR ID COLON INT ASSIGN I_CONST");
        Data new_data;
        new_data.id = $2.s_val;
        new_data.kind = Kind::var_kind;
        new_data.type = Type::i_type;
        new_data.value.i_val = $6.i_val;
        new_data.is_global = true;
        if(current_table.insert(new_data)) {
            java_class.globalVarDeclaration(new_data);
        }
        else {
            warning("Redeclaration of var in current scope");
        }
    }
    ;

local_variable_declaration
    : CONST ID const_variable_declaration {
        Trace("variable_declaration -> CONST ID const_variable_declaration");
        Data new_data;
        new_data.id = $2.s_val;
        new_data.kind = Kind::const_kind;
        new_data.type = $3.type;
        new_data.value = $3.value;
        if(!current_table.insert(new_data)) {
            warning("Redeclaration of const in current scope");
        }
        // current_table.dump();
    }
    | VAR ID local_var_variable_declaration {
        Trace("variable_declaration -> VAR ID var_variable_declaration");
        Data new_data;
        new_data.id = $2.s_val;
        new_data.kind = Kind::var_kind;
        new_data.type = $3.type;
        
        // array
        if ($3.array.empty()) {
            new_data.value = $3.value;
        }
        else {
            new_data.arr_start = $3.arr_start;
            new_data.arr_end = $3.arr_end;
            new_data.array = $3.array;
        }

        if(current_table.insert(new_data)) {
            new_data.value = $3.value;
            new_data.has_value = $3.has_value;
            java_class.localVarDeclaration(new_data, current_table, current_table.level, inMain);
        }
        else {
            warning("Redeclaration of var in current scope");
        }
    }
    ;


const_variable_declaration // return Data
    : ASSIGN I_CONST {
        Trace("const_variable_declaration -> ASSIGN I_CONST");
        Data return_data;
        return_data.type = Type::i_type;
        return_data.kind = Kind::const_kind;
        return_data.value.i_val = $2.i_val;
        $$ = return_data;
    }
    | COLON INT ASSIGN I_CONST {
        Trace("const_variable_declaration -> COLON INT ASSIGN I_CONST");    
        Data return_data;
        return_data.type = Type::i_type;
        return_data.kind = Kind::const_kind;
        return_data.value.i_val = $4.i_val;
        $$ = return_data;
    }
    | ASSIGN STR_CONST {
        Trace("const_variable_declaration -> ASSIGN STR_CONST");
        Data return_data;
        return_data.type = Type::s_type;
        return_data.kind = Kind::const_kind;
        return_data.value.s_val = $2.s_val;
        $$ = return_data;
    }
    | COLON STRING ASSIGN STR_CONST {
        Trace("const_variable_declaration -> COLON STRING ASSIGN STR_CONST");
        Data return_data;
        return_data.type = Type::s_type;
        return_data.kind = Kind::const_kind;
        return_data.value.s_val = $4.s_val;
        $$ = return_data;
    }
    ;

local_var_variable_declaration
    : ASSIGN const_expr {
        Trace("var_variable_declaration -> ASSIGN I_CONST");
        Data return_data;
        return_data.type = Type::i_type;
        return_data.kind = Kind::var_kind;
        return_data.value = $2.value;
        $$ = return_data;
    }
    | COLON INT {
        Trace("var_variable_declaration -> COLON INT");
        Data return_data;
        return_data.type = Type::i_type;
        return_data.kind = Kind::var_kind;
        return_data.has_value = false;
        $$ = return_data;
    }
    | COLON INT ASSIGN const_expr {
        Trace("var_variable_declaration -> COLON INT ASSIGN I_CONST");
        Data return_data;
        return_data.type = Type::i_type;
        return_data.kind = Kind::var_kind;
        return_data.value = $4.value;
        $$ = return_data;
    }
    | COLON BOOL {
        Trace("var_variable_declaration -> COLON REAL");
        Data return_data;
        return_data.type = Type::i_type;
        return_data.kind = Kind::var_kind;
        return_data.has_value = false;
        $$ = return_data;
    }
    | COLON BOOL ASSIGN const_expr {
        Trace("var_variable_declaration -> COLON REAL ASSIGN F_CONST");
        Data return_data;
        return_data.type = Type::i_type;
        return_data.kind = Kind::var_kind;
        return_data.value = $4.value;
        $$ = return_data;
    }
    ;

const_expr // return Data
    : const_val { // return Data
        Trace("const_expr -> const_val");
        $$ = $1;
    }
    | const_expr MOD const_expr {
        Trace("const_expr -> const_expr MOD const_expr");
        $$.kind = Kind::const_kind;
        $$.type = Type::i_type;
        java_class.modOperator(current_table.level, inMain);
    }
    | const_expr MUL const_expr {
        Trace("const_expr -> const_expr MUL const_expr");
        
        $$.kind = Kind::const_kind;
        $$.type = Type::i_type;
        java_class.mulOperator(current_table.level, inMain);
    }
    | const_expr DIV const_expr {
        Trace("const_expr -> const_expr DIV const_expr");
        $$.kind = Kind::const_kind;
        $$.type = Type::i_type;
        java_class.divOperator(current_table.level, inMain);
    }
    | const_expr ADD const_expr {
        Trace("const_expr -> const_expr ADD const_expr");
        $$.kind = Kind::const_kind;
        $$.type = Type::i_type;
        java_class.addOperator(current_table.level, inMain);
    }
    | const_expr SUB const_expr {
        Trace("const_expr -> const_expr SUB const_expr");
        $$.kind = Kind::const_kind;
        $$.type = Type::i_type;
        java_class.subOperator(current_table.level, inMain);
    }
    | const_expr AND const_expr {
        Trace("const_expr -> const_expr AND const_expr");
        $$.kind = Kind::const_kind;
        $$.type = Type::i_type;
        java_class.andOperator(current_table.level, inMain);
    }
    | const_expr OR const_expr {
        Trace("const_expr -> const_expr OR const_expr");
        $$.kind = Kind::const_kind;
        $$.type = Type::i_type;
        java_class.orOperator(current_table.level, inMain);
    }
    | const_expr LT const_expr { // Less Than
        Trace("const_expr -> const_expr LT const_expr");
        $$.kind = Kind::const_kind;
        $$.type = Type::i_type;
        java_class.ltOperator(current_table.level, inMain);
    }
    | const_expr LE const_expr { // Less Equal
        Trace("const_expr -> const_expr LE const_expr");
        $$.kind = Kind::const_kind;
        $$.type = Type::i_type;
        java_class.leOperator(current_table.level, inMain);
    }
    | const_expr EQ const_expr { // Equal
        Trace("const_expr -> const_expr EQ const_expr");
        $$.kind = Kind::const_kind;
        $$.type = Type::i_type;
        java_class.eqOperator(current_table.level, inMain);
    }
    | const_expr GE const_expr { // Greater Equal
        Trace("const_expr -> const_expr GE const_expr");
        $$.type = Type::i_type;
        $$.kind = Kind::const_kind;
        java_class.geOperator(current_table.level, inMain);
    }
    | const_expr GT const_expr { // Greater Than
        Trace("const_expr -> const_expr GE const_expr");
        $$.type = Type::i_type;
        $$.kind = Kind::const_kind;
        java_class.gtOperator(current_table.level, inMain);
    }
    | const_expr NE const_expr { // Not Equal
        Trace("const_expr -> const_expr NE const_expr");
        $$.type = Type::i_type;
        $$.kind = Kind::const_kind;
        java_class.neOperator(current_table.level, inMain);
    }
    | NOT const_expr {
        Trace("const_expr -> NOT const_expr");
        $$.kind = Kind::const_kind;
        $$.type = Type::i_type;
        java_class.notOperator(current_table.level, inMain);
    }
    | SUB const_expr %prec UMINUS {
        Trace("const_expr -> SUB const_expr");
        $$.kind = Kind::const_kind;
        $$.type = Type::i_type;
        java_class.negOperator(current_table.level, inMain);
    }
    | LPAREN const_expr RPAREN {
        $$.type = $2.type;
        $$.kind = $2.kind;
        Trace("const_expr -> LPAREN const_expr RPAREN");
    }
    ;

const_val // return Data
    : I_CONST { // return Value
        Trace("const_val -> I_CONST");
        Data return_data;
        return_data.type = Type::i_type;
        return_data.kind = Kind::const_kind;
        return_data.value.i_val = $1.i_val;
        $$ = return_data;
        java_class.loadIntConst(return_data, current_table.level, inMain);
    }
    | F_CONST {
        Trace("const_val -> F_CONST");
        $$.type = Type::f_type;
        $$.kind = Kind::const_kind;
    }
    | STR_CONST {
        Trace("const_val -> STR_CONST");
        Data return_data;
        return_data.type = Type::s_type;
        return_data.kind = Kind::const_kind;
        return_data.value.s_val = $1.s_val;
        $$ = return_data;
        java_class.loadStringConst(return_data, current_table.level, inMain);
    }
    | ID {
        Trace("const_val -> ID");
        auto iter = current_table.table.find($1.s_val);
        Data return_data;
        if(iter != current_table.table.end()) { // found in current table
            if(iter->second.kind == Kind::func_kind || iter->second.kind == Kind::proc_kind) {
                warning("Function or procedure cannot be called without parenthesis");
            }
            else {
                return_data = iter->second;
                if(iter->second.kind == Kind::const_kind) {
                    if(iter->second.type == Type::i_type) {
                        java_class.loadIntConst(iter->second, current_table.level, inMain);
                    }
                    else if(iter->second.type == Type::s_type) {
                        java_class.loadStringConst(iter->second, current_table.level, inMain);
                    }
                    else if(iter->second.type == Type::b_type) {
                        java_class.loadBoolConst(iter->second, current_table.level, inMain);
                    }
                }
                else {
                    if(current_table.level == 0) {
                        java_class.loadGlobalVar(return_data, current_table.level, inMain);
                    }
                    else {
                        java_class.loadLocalVar(current_table, return_data, current_table.level, inMain);
                    }
                }          
            } 
        }
        else {
            int table_index = table_stack.lookup($1.s_val);
            if(table_index != -1) {
                Value new_value;
                iter = table_stack.list[table_index].table.find($1.s_val);
                if(iter->second.kind == Kind::func_kind || iter->second.kind == Kind::proc_kind) {
                    warning("Function or procedure cannot be called without parenthesis");
                }
                else {
                    return_data = iter->second;
                    if(iter->second.kind == Kind::const_kind) {
                        if(iter->second.type == Type::i_type) {
                            java_class.loadIntConst(iter->second, current_table.level, inMain);
                        }
                        else if(iter->second.type == Type::s_type) {
                            java_class.loadStringConst(iter->second, current_table.level, inMain);
                        }
                        else if(iter->second.type == Type::b_type) {
                            java_class.loadBoolConst(iter->second, current_table.level, inMain);
                        }
                    }
                    else {
                        if(table_index == 0) {
                            java_class.loadGlobalVar(return_data, current_table.level, inMain);
                        }
                        else {
                            java_class.loadLocalVar(current_table, return_data, current_table.level, inMain);
                        }
                    }          
                } 
            }
            else {
                warning("Undeclared variable");
                return_data.type = Type::void_type;
                return_data.kind = Kind::const_kind;
            }
        }
        $$ = return_data;
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
        Data return_data;
        // $$.type = Type::b_type;
        return_data.type = Type::i_type;
        return_data.kind = Kind::const_kind;
        return_data.value.i_val = 1;
        $$ = return_data;
        java_class.loadBoolConst(return_data, current_table.level, inMain);
    }
    | FALSE {
        Trace("const_val -> FALSE");
        Data return_data;
        // $$.type = Type::b_type;
        return_data.type = Type::i_type;
        return_data.kind = Kind::const_kind;
        return_data.value.i_val = 0;
        $$ = return_data;
        java_class.loadBoolConst(return_data, current_table.level, inMain);
    }
    | function_call_stmt {
        Trace("const_val -> function_call_stmt");
        $$.type = $1.type;
        $$.kind = Kind::const_kind;
        $$.value = $1.value;
    }
    ;
        
datatype
    : INT {
        Trace("datatype -> INT");
        $$ = Type::i_type;
    }
    | BOOL {
        Trace("datatype -> REAL");
        $$ = Type::i_type;
    }
    | STRING {
        Trace("datatype -> STRING");
        $$ = Type::s_type;
    }
    | REAL {
        Trace("datatype -> REAL");
        $$ = Type::i_type;
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
        body_table.level = table_stack.list.size();
        body_table.start_index = table_stack.programCounter;
        current_table = body_table;
        
        java_class.newFunction(current_table, $2.s_val, $6, current_table.level); // origin table level
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
        java_class.closeFunction(current_table.level);
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

        // reverse(func_data.para_list.begin(), func_data.para_list.end());

        if(!current_table.insert(func_data)) {
            warning("Redeclaration of function in current scope");
        }
        table_stack.insert(current_table);
        current_table = body_table;

        map<int, Data> sorted_map;
        // sort by index with map
        for(auto iter = current_table.table.begin(); iter != current_table.table.end(); iter++) {
            if(iter->second.kind == Kind::para_kind) {
                sorted_map.insert(pair<int, Data>(iter->second.index, iter->second));
            }
        }

        int cnt = 0;
        for(auto iter = sorted_map.begin(); iter != sorted_map.end(); iter++) {
            if(iter->second.kind == Kind::para_kind) {
                iter->second.stack_index = current_table.start_index + cnt;
                cnt++;
            }
        }

        for(auto iter = current_table.table.begin(); iter != current_table.table.end(); iter++) {
            if(iter->second.kind == Kind::para_kind) {
                auto sorted_iter = sorted_map.find(iter->second.index);
                iter->second.stack_index = sorted_iter->first;
            }
        }

        java_class.newFunction(current_table, $2.s_val, $7, current_table.level);

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
        java_class.closeFunction(current_table.level);
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
        body_table.level = table_stack.list.size();
        body_table.start_index = table_stack.programCounter;
        current_table = body_table;
        
        java_class.newFunction(current_table, $2.s_val, Type::void_type, current_table.level - 1);
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
        java_class.closeFunction(current_table.level);
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
        // reverse(proc_data.para_list.begin(), proc_data.para_list.end());
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
        map<int, Data> sorted_map;
        // sort by index with map
        for(auto iter = current_table.table.begin(); iter != current_table.table.end(); iter++) {
            if(iter->second.kind == Kind::para_kind) {
                sorted_map.insert(pair<int, Data>(iter->second.index, iter->second));
            }
        }

        int cnt = 0;
        for(auto iter = sorted_map.begin(); iter != sorted_map.end(); iter++) {
            if(iter->second.kind == Kind::para_kind) {
                iter->second.stack_index = current_table.start_index + cnt;
                cnt++;
            }
        }

        for(auto iter = current_table.table.begin(); iter != current_table.table.end(); iter++) {
            if(iter->second.kind == Kind::para_kind) {
                auto sorted_iter = sorted_map.find(iter->second.index);
                iter->second.stack_index = sorted_iter->first;
            }
        }

        java_class.newFunction(current_table, $2.s_val, Type::void_type, current_table.level - 1);
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
        java_class.closeFunction(current_table.level);
    }
    ;

para_declaration
    : ID COLON datatype {
        Trace("para_declaration -> ID COLON datatype");
        SymbolTable new_table;
        table_stack.insert(current_table);
        new_table.level = table_stack.list.size();
        new_table.start_index = table_stack.programCounter;

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
    | para_declaration COMMA ID COLON datatype   {
        Trace("para_declaration -> ID COLON datatype COMMA para_declaration");
        Data new_data;
        new_data.id = $3.s_val;
        new_data.kind = Kind::para_kind;
        new_data.type = $5;
        if(!current_table.insert(new_data)) {
            warning("Redeclaration of parameter in current scope");
        }
        para_list.push_back(new_data);
    }      
    | ID COLON ARRAY I_CONST DOT DOT I_CONST OF datatype { // array
        Trace("para_declaration -> ID COLON ARRAY I_CONST DOT DOT I_CONST OF datatype");
        SymbolTable new_table;
        table_stack.insert(current_table);
        new_table.level = table_stack.list.size();
        new_table.start_index = table_stack.programCounter;

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
    | ID COLON ARRAY I_CONST DOT DOT I_CONST OF datatype COMMA para_declaration { // array
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
    : local_variable_declaration block_program {
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
    | function_call_stmt {
        Trace("stmt -> function_call_stmt");
    }
    ;

block_stmt
    : _BEGIN {
        SymbolTable body_table;
        table_stack.insert(current_table);
        body_table.level = table_stack.list.size();
        current_table = body_table;
        current_table.level = table_stack.list.size();
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
                if(table_index == 0) {
                    java_class.assignToGlobal(current_table, iter->second, current_table.level, inMain);
                }
                else {
                    java_class.assignToLocal(current_table, iter->second, current_table.level, inMain);
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
            if(current_table.level == 0) {
                java_class.assignToGlobal(current_table, iter->second, current_table.level, inMain);
            }
            else {
                java_class.assignToLocal(current_table, iter->second, current_table.level, inMain);
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
    : PUT {
        java_class.putStartStmt(current_table.level, inMain);
    }
    const_expr {
        Trace("put_stmt -> PUT const_expr");
        if($3.array.size() != 0) {
            warning("PUT operation on array");
        }
        else if($3.kind == Kind::proc_kind) {
            warning("PUT operation on procedure");
        }
        else if($3.kind == Kind::func_kind) {
            if($3.type == Type::void_type) {
                warning("PUT operation on function with no return value");
            }
        }
        java_class.putEndStmt($3, current_table.level, inMain);
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
        java_class.returnFunction(func_return.type, current_table.level, inMain);
    }
    | RETURN {
        Trace("result_stmt -> RETURN");
        func_return.return_type = Return_type::return_type;
        func_return.type = Type::void_type;
        java_class.returnFunction(func_return.type, current_table.level, inMain);
    }
    ;

exit_stmt
    : EXIT {
        Trace("exit_stmt -> EXIT");
        java_class.loopExitStmt(current_table.level, inMain);
    }
    | EXIT WHEN const_expr { // bool_expr
        Trace("exit_stmt -> EXIT WHEN bool_expr");
        if($3.type == Type::void_type) {
            warning("EXIT operation on void");
        }
        else if($3.type != Type::b_type) {
            warning("EXIT operation on non-boolean");
        }
        java_class.loopExitWhenStmt(current_table.level, inMain);
    }
    ;

skip_stmt
    : SKIP {
        Trace("skip_stmt -> SKIP");
        java_class.skipStmt(current_table.level, inMain);
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
        body_table.level = table_stack.list.size();
        body_table.start_index = table_stack.programCounter;
        current_table = body_table;
        
        java_class.ifStmt(current_table.level, inMain);
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

        java_class.endIfStmt(current_table.level, inMain);
    }
    | ELSE {
        table_msg("if Table");
        current_table.dump();
        SymbolTable body_table;
        body_table.level = table_stack.list.size();
        body_table.start_index = table_stack.programCounter;
        current_table = body_table;

        java_class.elseStmt(current_table.level, inMain);
    }
    block_program {
        
    } END IF {
        Trace("end_if_stmt -> ELSE block_program END IF");
        table_msg("else Table");
        current_table.dump();
        current_table = table_stack.get_top();
        table_stack.pop();

        java_class.blockEndIfStmt(current_table.level, inMain);
    }
    ;

loop_stmt
    : LOOP {
        Trace("loop_stmt -> LOOP");
        SymbolTable body_table;
        table_stack.insert(current_table);
        body_table.level = table_stack.list.size();
        body_table.start_index = table_stack.programCounter;
        current_table = body_table;
        body_table.start_index = table_stack.programCounter;

        java_class.loopStartStmt(current_table.level, inMain);
    }
    block_program END LOOP {
        Trace("loop_stmt -> LOOP block_program END LOOP");

        table_msg("loop Table");
        current_table.dump();
        current_table = table_stack.get_top();
        table_stack.pop();
        java_class.loopEndStmt(current_table.level, inMain);
    }
    ;

for_stmt
    : FOR ID {
        auto iter = current_table.table.find($2.s_val);
        if(iter == current_table.table.end()) {
            int table_index = table_stack.lookup($2.s_val);
            iter = table_stack.list[table_index].table.find($2.s_val);
        }

        SymbolTable body_table;
        table_stack.insert(current_table);
        body_table.level = table_stack.list.size();
        body_table.start_index = table_stack.programCounter;
        current_table = body_table;

        Data for_data;
        for_data.id = $2.s_val;
        for_data.kind = Kind::para_kind;
        for_data.type = Type::i_type;
        current_table.insert(for_data);
    }
    COLON for_para DOT DOT for_para {
        Trace("for_stmt -> FOR ID COLON for_para DOT DOT for_para block_program END FOR");

        auto iter = current_table.table.find($2.s_val);
        if(iter == current_table.table.end()) {
            int table_index = table_stack.lookup($2.s_val);
            if(table_index != -1) {
               iter = table_stack.list[table_index].table.find($2.s_val);
            }
        }
        int cnt = 0;
        for(auto iter = current_table.table.begin(); iter != current_table.table.end(); iter++) {
            if(iter->second.kind == Kind::para_kind) {
                iter->second.stack_index = current_table.start_index + cnt;
                cnt++;
            }
        }
        java_class.forStartStmt(iter->second, $5, $8, current_table.level, inMain);
        java_class.forExitStmt(current_table.level, inMain);
    }
    block_program END FOR {
        auto iter = current_table.table.find($2.s_val);
        if(iter == current_table.table.end()) {
            int table_index = table_stack.lookup($2.s_val);
            if(table_index != -1) {
               iter = table_stack.list[table_index].table.find($2.s_val);
            }
        }

        java_class.forEndStmt(iter->second, current_table.level, inMain);

        table_msg("for Table");
        current_table.dump();
        current_table = table_stack.get_top();
        table_stack.pop();
    }
    | FOR DECREASING ID { // DECREASING
        auto iter = current_table.table.find($3.s_val);
        if(iter == current_table.table.end()) {
            int table_index = table_stack.lookup($3.s_val);
            iter = table_stack.list[table_index].table.find($3.s_val);          
        }

        SymbolTable body_table;
        table_stack.insert(current_table);
        body_table.level = table_stack.list.size();
        body_table.start_index = table_stack.programCounter;
        current_table = body_table;
        
        Data for_data;
        for_data.id = $3.s_val;
        for_data.kind = Kind::para_kind;
        for_data.type = Type::i_type;
        current_table.insert(for_data);
    }
    COLON for_para DOT DOT for_para  {
        Trace("for_stmt -> FOR DECREASING ID COLON for_para DOT DOT for_para block_program END FOR");

        auto iter = current_table.table.find($3.s_val);
        if(iter == current_table.table.end()) {
            int table_index = table_stack.lookup($3.s_val);
            if(table_index != -1) {
               iter = table_stack.list[table_index].table.find($3.s_val);
            }
        }
        int cnt = 0;
        for(auto iter = current_table.table.begin(); iter != current_table.table.end(); iter++) {
            if(iter->second.kind == Kind::para_kind) {
                iter->second.stack_index = current_table.start_index + cnt;
                cnt++;
            }
        }
        java_class.forStartStmt(iter->second, $6, $9, current_table.level, inMain);
        java_class.forDecreasingExitStmt(current_table.level, inMain);
    } 
    block_program END FOR {
        auto iter = current_table.table.find($3.s_val);
        if(iter == current_table.table.end()) {
            int table_index = table_stack.lookup($3.s_val);
            if(table_index != -1) {
               iter = table_stack.list[table_index].table.find($3.s_val);
            }
        }

        java_class.forDecreasingEndStmt(iter->second, current_table.level, inMain);

        table_msg("for Table");
        current_table.dump();
        current_table = table_stack.get_top();
        table_stack.pop();
    }
    ;

for_para
    : I_CONST {
        Trace("for_para -> I_CONST");
        Data return_data;
        return_data.type = Type::i_type;
        return_data.kind = Kind::const_kind;
        return_data.value.i_val = $1.i_val;
        $$ = return_data;
    }
    | ID {
        Trace("for_para -> ID");
        auto iter = current_table.table.find($1.s_val);
        Data return_data;
        if(iter != current_table.table.end()) { // found in current table
            return_data = iter->second;
        }
        else {
            int table_index = table_stack.lookup($1.s_val);
            if(table_index != -1) {
                iter = table_stack.list[table_index].table.find($1.s_val);
                return_data = iter->second;
            }           
        }
        $$ = return_data;
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
                java_class.callFunction(iter->second, current_table.level, inMain);
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
                java_class.callFunction(iter->second, current_table.level, inMain);
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
                        // reverse(para_list.begin(), para_list.end());
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
                        java_class.callFunction(iter->second, current_table.level, inMain);
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
                    // reverse(para_list.begin(), para_list.end());
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
                    java_class.callFunction(iter->second, current_table.level, inMain);
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
    // fprintf(stderr, "\033[47m\033[31m\033[1mWANRING: %s\033[0m\n", msg);
}

void yyerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    table_msg("Current Table");
    current_table.dump();
    exit(1);
}

int main(int argc, char* argv[]) {
    string input_file_name;
    if(argc == 1) {
        yyin = stdin;
    }
    else if(argc == 2) {
        yyin = fopen(argv[1], "r");
        input_file_name = argv[1];
    }
    else {
        yyerror("Too many arguments");
        exit(1);
    }

    if (java_class.openFile(input_file_name)) {
        cout << "Open file " << input_file_name << " successfully" << endl;
    }
    else {
        cout << "Open file " << input_file_name << " failed" << endl;
        exit(1);
    }

    printf("---------------------Parsing begin\n");
    /* perform parsing */
    if(yyparse()) {
        yyerror("Parsing failed");
    }
    else {
        java_class.endFile();
        table_msg("\nMAIN Table");
        current_table.dump();
    
        printf("\n---------------------Parsing end\n");
    }
    
    fclose(yyin);
}