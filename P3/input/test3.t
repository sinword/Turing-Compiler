var i : int
var j : int

for i : 1 .. 3
    for j : 1 .. 3
        put i * j
        put " "
    end for
end for
skip

for decreasing i : 3 .. 1
    for decreasing j : 3 .. 1
        put i * j
        put " "
    end for
end for
skip

for i : 1 .. 3
    for decreasing j : 3 .. 1
        put i * j
        put " "
    end for
end for

skip

for decreasing j : 3 .. 1
    for i : 1 .. 3
        put i * j
        put " "
    end for
end for