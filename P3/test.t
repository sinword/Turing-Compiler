var i : int
var j : int
var v1: int := 5
var v2: int := 8
const c1: int := 1
const c2: int := 3

var tmp: int := 0
for i : c1 .. v1
    
    for decreasing j : v2 .. c2
        % put i * j
        % put " "
        tmp := tmp + 1
    end for
    put tmp
    skip
    
end for
skip

for decreasing i : v1 .. c1
    for j : c2 .. v2
        % put i * j
        % put " "
    end for
end for
skip
