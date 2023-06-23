% var test
const a :string := "Hey There"
const b := -25
const c := 3.14
const d :bool := true

var e :string
var f := 10
var g :real
var h :bool := false

% can't assign to const
a := "123"

% type conversion
h := 123

% can't assign to undeclared var
i := 1

function add (a :int, b :int) :int
    result a+b
end add

% valid assignment
f := add(1, 2)

% type conversion
e := add(1, 2)

procedure print (a :int, b: array 10..1 of string)
    put a
    return
end print

% can't assign to procedure
e := print(1)