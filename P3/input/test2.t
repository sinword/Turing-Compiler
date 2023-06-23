var i := 1

loop
    var j := 1
    exit when (i = 4)
    i := i + 1

    loop
        j := j + 2
        exit when (j = 5)
    end loop
    put j

end loop
put i