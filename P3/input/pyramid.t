procedure pyramid (n: int)
    var i : int
    var j : int
    
    i := 1
    loop
        exit when i > n
        j := 1
        loop
            exit when j > n - i
            put " "
            j := j + 1
        end loop
        j := 1
        loop
            exit when j > 2 * i - 1
            put "*"
            j := j + 1
        end loop
        skip
        i := i + 1
    end loop
    return
end pyramid

pyramid(3)
pyramid(5)