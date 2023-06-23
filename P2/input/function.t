function func1(x: int, y: int, z: string) :int
    return
end func1

function func2(a: bool) :bool
    const b := false
    var c: bool := (not a) and (b or a)
    result not (not (c))
end func2

function func3(num: int) :int
    const b := false
    result func1(1, ((b + 1) * 2 / 3) mod 4, "hello")   
end func3

procedure proc1 (x: int, y: int, z: string)
    return
end proc1

procedure proc2 (a: bool)
    result not a
end proc2

procedure proc3 (num: int)
    const b := false
    result proc1(proc2(-b), ((b + 1) * 2 / 3) mod 4, "hello")   
end proc3

function func4(arr1: array 1..10 of int, arr2: array 1..2 of bool, b: bool, i: int) :int
    result arr1[i] + arr2[1] + b + i
end func4

var arr1: array 1..10 of int
var arr2: array 1..2 of bool
var arr3: array 1..100 of string
const c: int := 1
var a: int := 1

a := func1((-func4(arr1, arr2, func2(arr2[1]), func3(c)) + 4), 2, arr3[50])
