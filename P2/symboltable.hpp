#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

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
    int scope; // level of current symbol table

public:
    SymbolTable() {
        cnt = 0;
        scope = 0;
    }

    SymbolTable(int index, int scope) {
        cnt = 0;
        this->scope = scope;
    }

    bool insert(Data new_data) {
        if(lookup(new_data.id) != -1) { // already exist
            return false;
        }
        cnt++;
        new_data.index = cnt;
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
        
        map<int, Data>::iterator iter;
        // cout <<" Index\t\t";
        cout << "ID\t\tKind\t\tType\t\tArray\n";
        cout << "--------------------------------------------------------------------------------------------\n";
        for(iter = output_map.begin(); iter!= output_map.end(); iter++) {
            // cout << iter->second.index << "\t\t";
            cout << left << setw(16) << iter->second.id;
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
            switch(iter->second.type) {
                case i_type: 
                    cout << "INT\t\t";
                    break;
                case f_type:
                    cout << "REAL\t\t";
                    break;
                case s_type:
                    cout << "STRING\t\t";
                    break;
                case b_type:
                    cout << "BOOL\t\t";
                    break;
                case void_type:
                    cout << "VOID\t\t";
                    break;
            }
            if(!iter->second.array.empty()) {
                cout << iter->second.arr_start << ".." << iter->second.arr_end;
            }
            else {
                cout << "*";
            }

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
};

class TableList {
public:
    vector<SymbolTable> list; // stack of symbol table
    int level; // current level of tablelist

public:
    TableList() {
        level = 0;
    }

    void insert(SymbolTable new_table) {
        list.push_back(new_table);
        level++;
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
        list.pop_back();
        level--;
    }

    SymbolTable get_top() {
        return list.back();
    }
};