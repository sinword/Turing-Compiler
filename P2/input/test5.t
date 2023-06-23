% constant and variable declarations
const n :int := 10
var sum :int
var tmp :int
var index :int
const tmp :int := 10

% for loop
sum := 0
for index: 1 .. n
    sum := sum + index
end for

for index: n .. n
    sum := sum + index
end for

% invalid expr in for range
for index: "123" .. 10
    sum := sum + index
end for

% Const cannot be used as for range
for index: 1 .. tmp
    sum := sum + index
end for