if (3 = 3) then
    var v1: int
    const c1 := 3
    if (3 = 3) then
        var v2: real := 1.5
        const c2: real := 1.5
    else
        var v3: array 1..10 of int
        var v4: array 0..5 of bool
        var v5: array 1..100 of real
    end if
else
    var v6: string:= "123"
    const c3: string := "true"
    if (3 = 3) then
        var v7: bool := true
        if (3 = 3) then
            const c4: bool := true
            const c5: bool := false
        end if
    else
        put "456"
    end if
    const c6: int := true
    const c7: real := 6.9
end if

const c8: int := 3