var sum :int
const mark := 1

% no declaration, warning

put "Enter 20 integers, please"

sum := 0

for i: 1 .. 20
    var a : int

    for k : 1 .. 20
        var b : int
        put "Enter 20 integers, please"
        sum := sum + mark
    end for

    get mark

    for j: 1 .. 20
        var c : int
        put "Enter 20 integers, please"
        sum := sum + mark

        for l : 1 .. 20
            var d : int
            put "Enter 20 integers, please"
            sum := sum + mark
        end for

    end for
    
    var e : int

end for

put sum