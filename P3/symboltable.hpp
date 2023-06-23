#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <libgen.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include <fstream>

using namespace std;

enum Kind {
    func_kind, proc_kind, para_kind, var_kind, const_kind
};

enum Type {
    void_type, i_type, f_type, s_type, b_type
};

enum Return_type {
    null, return_type, result_type
};

// void_type is used for debugging
typedef struct Value {
    int i_val;
    float f_val;
    string s_val;
    bool b_val;
    Type type;
} Value;

typedef struct Data {
    int index;
    int arr_start;
    int arr_end;
    vector<Value> array;
    vector<Data> para_list;
    string id;
    Kind kind; // FUNC, PROC, PARA, VAR, CONST
    Type type; // VOID, INT, FLOAT, STRING, BOOL
    Value value;
    bool has_value = true;
    bool is_global = false;
    int stack_index = -1;
} Data;

typedef struct Func_return {
    Return_type return_type;
    Type type;
} Func_return;

struct YYSType {
    Kind kind;
    Type type;
    Value value;
    Data data;
};

#define YYSTYPE YYSType

class SymbolTable {
public:
    map<string, Data> table;
    int cnt; // number of data in current symbol table
    int level; // level of current symbol table
    int start_index;

public:
    SymbolTable() {
        cnt = 0;
        level = 0;
        start_index = 0;
    }

    SymbolTable(int level) {
        cnt = 0;
        this->level = level;
        start_index = 0;
    }

    bool insert(Data new_data) {
        if(lookup(new_data.id) != -1) { // already exist
            return false;
        }
        new_data.index = cnt;
        cnt++;
        table.insert(pair<string, Data>(new_data.id, new_data));
        return true;
    }

    int lookup(string id) {
        map<string, Data>::iterator iter;
        for(iter = table.begin(); iter != table.end(); iter++) {
            if(iter->first == id) {
                return iter->second.index;
            }
        }
        return -1;
    }

    void dump() {
        map<string, Data>::iterator sort_iter;
        map<int, Data> output_map;
        // sort by index with map
        for(sort_iter = table.begin(); sort_iter!= table.end(); sort_iter++) {
            output_map.insert(pair<int, Data>(sort_iter->second.index, sort_iter->second));
        }
        
        cout << "level: " << level << endl;
        map<int, Data>::iterator iter;
        // cout <<" Index\t\t";
        cout << "ID\t\tIndex\t\tKind\t\tType\t\tValue\t\tArray\t\tS_index\n";
        cout << "--------------------------------------------------------------------------------------------\n";
        for(iter = output_map.begin(); iter!= output_map.end(); iter++) {
            // cout << iter->second.index << "\t\t";
            cout << left << setw(16) << iter->second.id;
            cout << iter->second.index << "\t\t";
            // print data kind
            switch(iter->second.kind) {
                case func_kind:
                    cout << "FUNC";
                    break;
                case proc_kind:
                    cout << "PROC";
                    break;
                case para_kind:
                    cout << "PARA";
                    break;
                case var_kind:
                    cout << "VAR";
                    break;
                case const_kind:
                    cout << "CONST";
                    break;
            }

            cout << "\t\t";
            // print data type
            switch(iter->second.type) {
                case i_type: 
                    cout << "INT";
                    break;
                case f_type:
                    cout << "REAL";
                    break;
                case s_type:
                    cout << "STRING";
                    break;
                case b_type:
                    cout << "BOOL";
                    break;
                case void_type:
                    cout << "VOID";
                    break;
            }
            
            cout << "\t\t";
            // print data value (only constant)
            switch(iter->second.kind) {
                case func_kind:
                case proc_kind:
                case para_kind:
                case var_kind:
                    cout << "*";
                    break;
                case const_kind:
                    switch(iter->second.type) {
                        case i_type: 
                            cout << iter->second.value.i_val;
                            break;
                        case f_type:
                            cout << iter->second.value.f_val;
                            break;
                        case s_type:
                            cout << iter->second.value.s_val;
                            break;
                        case b_type:
                            cout << iter->second.value.b_val;
                            break;
                        case void_type:
                            cout << "*";
                            break;
                    }
            }

            cout << "\t\t";
            // print array size
            if(!iter->second.array.empty()) {
                cout << iter->second.arr_start << ".." << iter->second.arr_end;
            }
            else {
                cout << "*";
            }

            // print stack index
            cout << "\t\t";
            if(iter->second.stack_index != -1) {
                cout << iter->second.stack_index;
            }
            else {
                cout << "*";
            }

            // print parameter list
            if(iter->second.kind == Kind::func_kind || iter->second.kind == Kind::proc_kind) {
                cout << "\t\tParameter List (";
                if(!iter->second.para_list.empty()) {
                    for(int i = 0; i < iter->second.para_list.size(); i++) {
                        switch(iter->second.para_list[i].type) {
                            case i_type: 
                                cout << "INT";
                                break;
                            case f_type:
                                cout << "FLOAT";
                                break;
                            case s_type:
                                cout << "STRING";
                                break;
                            case b_type:
                                cout << "BOOL";
                                break;
                            case void_type:
                                cout << "VOID";
                                break;
                        }
                        if(i != iter->second.para_list.size() - 1) {
                            cout << ", ";
                        }
                    }
                }
                cout << ")";
            }
            cout << endl;
        }
        cout << "--------------------------------------------------------------------------------------------\n\n";
    }

    void updataData(Data data) {
        table[data.id] = data;
    }
};

class TableList {
public:
    vector<SymbolTable> list; // stack of symbol table
    int level; // current level of tablelist
    int programCounter;

public:
    TableList() {
        level = 0;
        programCounter = 0;
    }

    void insert(SymbolTable new_table) {
        list.push_back(new_table);
        level++;
        if(new_table.level > 0) {
            for(auto iter = new_table.table.begin(); iter != new_table.table.end(); iter++) {
            if(iter->second.stack_index != -1){
                programCounter++;
            }
        }
        }
        
    }

    int lookup(string id) {
        if (level == 0) {
            return -1;
        }
        else {
            for(int i = level - 1; i >= 0; i--) {
                if(list[i].lookup(id) != -1) {
                    return i;
                }   
            }
            return -1;
        }
    }

    void dump() {
        for(size_t i = 0; i < list.size(); i++) {
            list[i].dump();
            cout << "----------------------------\n";
        }
    }

    void pop() {
        SymbolTable tmp = list.back();
        list.pop_back();
        level--;
        cout << "PG before popping table: " << programCounter << endl;
        for(auto iter = tmp.table.begin(); iter != tmp.table.end(); iter++) {
            if(iter->second.stack_index != -1) {
                programCounter--;
            }
        }
    }

    SymbolTable get_top() {
        return list.back();
    }
};
