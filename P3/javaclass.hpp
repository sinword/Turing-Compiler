#include "symboltable.hpp"
#define JAVA_DEBUG 0
#define java_msg(msg)    { if (JAVA_DEBUG) { /*red notify */ cout << "\033[1;31m" << msg << "\033[0m" << endl; } }

class JavaClass {
public:
    fstream file;
    string class_name;
    string lex_result;
    int goto_index_base;
    int loop_index_base;
    vector<int> if_goto_index;
    vector<int> loop_goto_index;
public:
    JavaClass() {
        class_name = "";
        lex_result = "";
        goto_index_base = 0;
        loop_index_base = 0;
    }

    string getFileName(const string& filePath)
    {
        char* filePtr = basename(const_cast<char*>(filePath.c_str()));
        return string(filePtr);
    }

    bool openFile(string input_file_name) {
        string path = input_file_name;
        string filename = getFileName(path);
        size_t pos = filename.find_last_of(".");
        class_name = filename.substr(0, pos);
        file.open((class_name + ".jasm"), ios::out);
        if(file.is_open()) {
            file << "class " << class_name << endl;
            file <<"{" << endl;
            return true;
        }
        else {
            return false;
        }
    }

    string printTab(int level) {
        string tab = "\t";
        for(int i = 1; i < level; i++) {
            tab += "\t";
        }
        return tab;
    }

    void globalVarDeclaration(Data data) {
        file << printTab(1) << "field static int" << " " << data.id;
        if(data.has_value) {
            file << " = " << data.value.i_val;
        }
        file << endl;
        return;
    }

    void localVarDeclaration(Data& data, SymbolTable& table, int level, bool inMain) {
       level++;
        if(inMain) {
            level++;
        }
        data.stack_index = table.start_index + table.cnt - 1;
        java_msg("localVarDeclaration: " + data.id + " " + to_string(data.stack_index));
        table.updataData(data);
        if(data.has_value) {
            file << printTab(level) << "istore " << data.stack_index << endl;
        }
    }
 
    void mainFunction(int level) {
        file << printTab(level) << "method public static void main(java.lang.String[])" << endl;
        file << printTab(level) << "max_stack 15" << endl;
        file << printTab(level) << "max_locals 15" << endl;
        file << printTab(level) << "{" << endl;
    }

    void newFunction(SymbolTable func_table, string func_name, Type return_type, int level) {
        file << printTab(level) << "method public static ";
        if(return_type == Type::void_type) {
            file << "void ";
        }
        else {
            file << "int ";
        }
        file << func_name << "(";
        java_msg("newFunction: " + func_name + ", parameters: ");
        for(auto iter = func_table.table.begin(); iter != func_table.table.end(); iter++) {
            if(iter->second.kind == Kind::para_kind) {
                switch(iter->second.type) {
                    case Type::i_type:
                        file << "int";
                        break;
                    case Type::s_type:
                        file << "java.lang.String";
                        break;
                    case Type::b_type:
                        file << "int";
                        break;
                    case Type::void_type:
                        file << "void";
                        break;
                    default:
                        break;
                }
                auto iter2 = func_table.table.end();
                if(iter != --iter2) {
                    file << ", ";
                }
            }
        }
        file << ")" << endl;
        file << printTab(level) << "max_stack 15" << endl;
        file << printTab(level) << "max_locals 15" << endl;
        file << printTab(level) << "{" << endl;
    }

    void closeFunction(int level) {
        file << printTab(level);
        file << "}" << endl;
    }
    
    void endFile() {
        file << "}";
    }

    void putStartStmt(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "getstatic java.io.PrintStream java.lang.System.out" << endl;     
    }

    void putEndStmt(Data data, int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        
        file << printTab(level) << "invokevirtual void java.io.PrintStream.print(";
        if(data.type == Type::i_type) {
            file << "int";
        }
        else if(data.type == Type::s_type) {
            file << "java.lang.String";
        }
        else if(data.type == Type::b_type) {
            file << "int";
        }
        file << ")" << endl;
    }

    void returnFunction(Type return_type, int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level);
        if(return_type == Type::void_type) {
            java_msg("returnFunction: void");
            file << "return";
        }
        else {
            java_msg("returnFunction: int");
            file << "ireturn";
        }
        file << endl;
    }

    void loadGlobalVar(Data data, int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "getstatic int " << class_name << "." << data.id << endl;
    }   

    void loadLocalVar(SymbolTable current_table, Data data, int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        string msg = "loadLocalVar: " + data.id + " " + to_string(data.stack_index);
        java_msg(msg);
        file << printTab(level) << "iload " << data.stack_index << endl;
        current_table.updataData(data);
    }
    
    void assignToGlobal(SymbolTable current_table, Data data, int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "putstatic ";
        if(data.type == Type::i_type) {
            file << "int ";
        }
        else if(data.type == Type::s_type) {
            file << "java.lang.String ";
        }
        else if(data.type == Type::b_type) {
            file << "int ";
        }
        file << class_name << "." << data.id << endl;
    }

    void assignToLocal(SymbolTable current_table, Data data, int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "istore " << data.stack_index << endl;
    }

    void skipStmt(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "getstatic java.io.PrintStream java.lang.System.out" << endl;
        file << printTab(level) << "invokevirtual void java.io.PrintStream.println()" << endl;
    }

    void loadIntConst(Data data, int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "sipush " << data.value.i_val << endl;
    }

    void loadBoolConst(Data data, int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "iconst_";
        if(data.value.i_val) {
            file << "1" << endl;
        }
        else {
            file << "0" << endl;
        }
    }

    void loadStringConst(Data data, int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "ldc \"" << data.value.s_val << "\"" << endl; 
    }

    void ifStmt(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        if_goto_index.push_back(goto_index_base);
        goto_index_base += 1;
        file << printTab(level) << "ifeq " << "Lelse" << if_goto_index.back() << endl;
        if_goto_index.push_back(goto_index_base);
        goto_index_base += 1;

        string msg = "";
        for(auto iter = if_goto_index.begin(); iter != if_goto_index.end(); iter++) {
            msg += to_string(*iter) + " ";
        }
        java_msg("ifStmt, goto_index_base: " + msg);
    }

    void elseStmt(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "goto " << "Lexit" << if_goto_index.back() << endl;
        int tmpIndex = if_goto_index.back();
        if_goto_index.pop_back();
        file << printTab(level) << "Lelse" << if_goto_index.back() << ": " << endl;
        file << printTab(level) << "nop" << endl;
        if_goto_index.pop_back();
        if_goto_index.push_back(tmpIndex);

        string msg = "";
        for(auto iter = if_goto_index.begin(); iter != if_goto_index.end(); iter++) {
            msg += to_string(*iter) + " ";
        }
        java_msg("elseStmt: goto_index_base: " + msg);
    }

    void endIfStmt(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "goto " << "Lexit" << if_goto_index.back() << endl;
        int tmpIndex = if_goto_index.back();
        if_goto_index.pop_back();
        file << printTab(level) << "Lelse" << if_goto_index.back() << ": " << endl;
        file << printTab(level) << "nop" << endl;
        if_goto_index.pop_back();
        file << printTab(level) << "Lexit" << tmpIndex << ": " << endl;
        file << printTab(level) << "nop" << endl;

        string msg = "";
        for(auto iter = if_goto_index.begin(); iter != if_goto_index.end(); iter++) {
            msg += to_string(*iter) + " ";
        }
        java_msg("endIfStmt, goto_index_base: " + msg);
    }

    void blockEndIfStmt(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "Lexit" << if_goto_index.back() << ": " << endl;
        file << printTab(level) << "nop" << endl;
        if_goto_index.pop_back();

        string msg = "";
        for(auto iter = if_goto_index.begin(); iter != if_goto_index.end(); iter++) {
            msg += to_string(*iter) + " ";
        }
        java_msg("blockEndIfStmt, goto_index_base: " + msg);
    }

    void callFunction(Data func, int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        string return_type = "";
        if(func.type == Type::i_type) {
            return_type = "int ";
        }
        else if(func.type == Type::s_type) {
            return_type = "java.lang.String ";
        }
        else if(func.type == Type::b_type) {
            return_type = "int ";
        }
        else if(func.type == Type::void_type) {
            return_type = "void ";
        }

        file << printTab(level) << "invokestatic " << return_type << class_name << "." << func.id << "(";
        for(auto iter = func.para_list.begin(); iter != func.para_list.end(); iter++) {
            if(iter->type == Type::i_type) {
                file << "int";
            }
            else if(iter->type == Type::s_type) {
                file << "java.lang.String";
            }
            else if(iter->type == Type::b_type) {
                file << "int";
            }
            if(iter != --func.para_list.end()) {
                file << ", ";
            }
        }
        file << ")" << endl;
    }

    void loopStartStmt(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        loop_goto_index.push_back(goto_index_base);
        goto_index_base += 1;
        file << printTab(level) << "Lbegin" << loop_goto_index.back() << ": " << endl;
        file << printTab(level) << "nop" << endl;
    }

    void loopExitStmt(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "goto Lexit" << loop_goto_index.back() << endl;
    }

    void loopExitWhenStmt(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "ifne Lexit" << loop_goto_index.back() << endl;
    }

    void loopEndStmt(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level + 1) << "goto Lbegin" << loop_goto_index.back() << endl;
        file << printTab(level + 1) << "Lexit" << loop_goto_index.back() << ": " << endl;
        file << printTab(level) << "nop" << endl;
        loop_goto_index.pop_back();
    }

    void forStartStmt(Data data, Data para1, Data para2, int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        
        loop_goto_index.push_back(goto_index_base);
        goto_index_base += 1;
        if(para1.is_global && para1.kind != Kind::const_kind) {
            file << printTab(level) << "getstatic int " << class_name << "." << para1.id << endl;
        }
        else {
            file << printTab(level) << "sipush " << para1.value.i_val << endl;
        }
        file << printTab(level) << "istore " << data.stack_index << endl;
        file << printTab(level) << "Lbegin" << loop_goto_index.back() << ": " << endl;
        file << printTab(level) << "nop" << endl;

        file << printTab(level) << "iload " << data.stack_index << endl;

        if(para2.is_global && para2.kind != Kind::const_kind) {
            file << printTab(level) << "getstatic int " << class_name << "." << para2.id << endl;
        }
        else {
            file << printTab(level) << "sipush " << para2.value.i_val << endl;
        }
    }

    void forExitStmt(int level, bool inMain) {
        gtOperator(level, inMain);
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "ifne Lexit" << loop_goto_index.back() << endl; 
    }

    void forDecreasingExitStmt(int level, bool inMain) {
        ltOperator(level, inMain);
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "ifne Lexit" << loop_goto_index.back() << endl;
    }

    void forEndStmt(Data data, int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }

        file << printTab(level) << "iload " << data.stack_index << endl;
        file << printTab(level) << "sipush 1" << endl;
        file << printTab(level) << "iadd" << endl;
        file << printTab(level) << "istore " << data.stack_index << endl;
        file << printTab(level) << "goto Lbegin" << loop_goto_index.back() << endl;
        file << printTab(level) << "Lexit" << loop_goto_index.back() << ": " << endl;
        file << printTab(level) << "nop" << endl;
        loop_goto_index.pop_back();
    }

    void forDecreasingEndStmt(Data data, int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "iload " << data.stack_index << endl;
        file << printTab(level) << "sipush 1" << endl;
        file << printTab(level) << "isub" << endl;
        file << printTab(level) << "istore " << data.stack_index << endl;
        file << printTab(level) << "goto Lbegin" << loop_goto_index.back() << endl;
        file << printTab(level) << "Lexit" << loop_goto_index.back() << ": " << endl;
        file << printTab(level) << "nop" << endl;
        loop_goto_index.pop_back();
    }

    void addOperator(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "iadd" << endl;
    }

    void subOperator(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "isub" << endl;
    }

    void mulOperator(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "imul" << endl;
    }

    void divOperator(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "idiv" << endl;
    }

    void modOperator(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "irem" << endl;
    }

    void negOperator(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "ineg" << endl;
    }

    void andOperator(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "iand" << endl;
    }

    void orOperator(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "ior" << endl;
    }

    void notOperator(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        file << printTab(level) << "iconst_1" << endl;
        file << printTab(level) << "ixor" << endl;
    }

    void ltOperator(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        int goto_index1 = goto_index_base;
        int goto_index2 = goto_index_base + 1;
        goto_index_base += 2;
        file << printTab(level) << "isub" << endl;
        file << printTab(level) << "iflt L" << goto_index1 << endl;
        file << printTab(level) << "iconst_0" << endl;
        file << printTab(level) << "goto L" << goto_index2 << endl;
        file << printTab(level) << "L" << goto_index1 << ": " << endl;
        file << printTab(level) << "nop" << endl;
        file << printTab(level) << "iconst_1" << endl;
        file << printTab(level) << "L" << goto_index2 << ": " << endl;
        file << printTab(level) << "nop" << endl;
    }

    void gtOperator(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        int goto_index1 = goto_index_base;
        int goto_index2 = goto_index_base + 1;
        goto_index_base += 2;
        file << printTab(level) << "isub" << endl;
        file << printTab(level) << "ifgt L" << goto_index1 << endl;
        file << printTab(level) << "iconst_0" << endl;
        file << printTab(level) << "goto L" << goto_index2 << endl;
        file << printTab(level) << "L" << goto_index1 << ": " << endl;
        file << printTab(level) << "nop" << endl;
        file << printTab(level) << "iconst_1" << endl;
        file << printTab(level) << "L" << goto_index2 << ": " << endl;
        file << printTab(level) << "nop" << endl;
    }

    void eqOperator(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        int goto_index1 = goto_index_base;
        int goto_index2 = goto_index_base + 1;
        goto_index_base += 2;
        file << printTab(level) << "isub" << endl;
        file << printTab(level) << "ifeq L" << goto_index1 << endl;
        file << printTab(level) << "iconst_0" << endl;
        file << printTab(level) << "goto L" << goto_index2 << endl;
        file << printTab(level) << "L" << goto_index1 << ": " << endl;
        file << printTab(level) << "nop" << endl;
        file << printTab(level) << "iconst_1" << endl;
        file << printTab(level) << "L" << goto_index2 << ": " << endl;
        file << printTab(level) << "nop" << endl;
    }

    void leOperator(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        int goto_index1 = goto_index_base;
        int goto_index2 = goto_index_base + 1;
        goto_index_base += 2;
        file << printTab(level) << "isub" << endl;
        file << printTab(level) << "ifle L" << goto_index1 << endl;
        file << printTab(level) << "iconst_0" << endl;
        file << printTab(level) << "goto L" << goto_index2 << endl;
        file << printTab(level) << "L" << goto_index1 << ": " << endl;
        file << printTab(level) << "nop" << endl;
        file << printTab(level) << "iconst_1" << endl;
        file << printTab(level) << "L" << goto_index2 << ": " << endl;
        file << printTab(level) << "nop" << endl;
    }

    void geOperator(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        int goto_index1 = goto_index_base;
        int goto_index2 = goto_index_base + 1;
        goto_index_base += 2;
        file << printTab(level) << "isub" << endl;
        file << printTab(level) << "ifge L" << goto_index1 << endl;
        file << printTab(level) << "iconst_0" << endl;
        file << printTab(level) << "goto L" << goto_index2 << endl;
        file << printTab(level) << "L" << goto_index1 << ": " << endl;
        file << printTab(level) << "nop" << endl;
        file << printTab(level) << "iconst_1" << endl;
        file << printTab(level) << "L" << goto_index2 << ": " << endl;
        file << printTab(level) << "nop" << endl;
    }

    void neOperator(int level, bool inMain) {
        level++;
        if(inMain) {
            level++;
        }
        int goto_index1 = goto_index_base;
        int goto_index2 = goto_index_base + 1;
        goto_index_base += 2;
        file << printTab(level) << "isub" << endl;
        file << printTab(level) << "ifne L" << goto_index1 << endl;
        file << printTab(level) << "iconst_0" << endl;
        file << printTab(level) << "goto L" << goto_index2 << endl;
        file << printTab(level) << "L" << goto_index1 << ": " << endl;
        file << printTab(level) << "nop" << endl;
        file << printTab(level) << "iconst_1" << endl;
        file << printTab(level) << "L" << goto_index2 << ": " << endl;
        file << printTab(level) << "nop" << endl;
    }
};
