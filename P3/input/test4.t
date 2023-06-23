procedure printSequence (n: int)
    var i := 0
    loop
        exit when (i = n) 
        put i 
        put " "
        i := i + 1
    end loop
    return
end printSequence

printSequence(5)