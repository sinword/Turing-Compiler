% constant and variable declarations
% const n :real := "HELLO"
% var sum :int := 19.5
% var index :int := "HELLO"
% const tmp :bool := 10

const n :int := 10
var sum :int
var index :int
const tmp :int := 10

sum := 0

function add (a :int, b :int) :int
    result 123
end add

put add(1, 2)

for decreasing index: sum .. 1
    var sum :int
end for

procedure sub (a :int, b :int)
    return
end sub

function test(): bool
    result true
end test

put test