var i := 1

loop
    exit when (i = 10)
    i := i + 1
    var b := 2
    b := 3
end loop
put i

loop
    i := i + 1
    exit when (i = 10)
    var b := 2
    b := 3
end loop
put i


loop
    i := i + 1
    var b := 2
    exit when (i = 10)
    b := 3
end loop
put i

loop
    i := i + 1
    var b := 2
    b := 3
    exit when (i = 10)
end loop
put i